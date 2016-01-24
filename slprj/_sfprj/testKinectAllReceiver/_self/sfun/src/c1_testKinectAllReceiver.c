/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testKinectAllReceiver_sfun.h"
#include "c1_testKinectAllReceiver.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testKinectAllReceiver_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[13] = { "x", "y", "z", "c1", "c2",
  "c3", "mystr", "nargin", "nargout", "kinectX", "kinectY", "kinectZ", "arrSBM"
};

static const char * c1_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "num" };

static const char * c1_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

/* Function Declarations */
static void initialize_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static void initialize_params_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static void enable_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static void disable_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static void set_sim_state_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static void sf_gateway_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static void initSimStructsc1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance);
static real_T c1_countDigits(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, real_T c1_x);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static void c1_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y_data[], int32_T c1_y_sizes[2]);
static void c1_b_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y_data[], int32_T c1_y_sizes[2]);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_arrSBM, const char_T *c1_identifier, real_T
  c1_y[256]);
static void c1_d_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c1_inData_data[], int32_T c1_inData_sizes[2]);
static void c1_f_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y_data[], int32_T c1_y_sizes[2]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, char_T c1_outData_data[], int32_T
  c1_outData_sizes[2]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T *c1_inData_sizes);
static void c1_g_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T *c1_y_sizes);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  *c1_outData_sizes);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_h_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_i_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_testKinectAllReceiver, const
  char_T *c1_identifier);
static uint8_T c1_j_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_testKinectAllReceiver = 0U;
}

static void initialize_params_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[256];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_arrSBM)[256];
  c1_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  for (c1_i0 = 0; c1_i0 < 256; c1_i0++) {
    c1_u[c1_i0] = (*c1_arrSBM)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_testKinectAllReceiver;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[256];
  int32_T c1_i1;
  real_T (*c1_arrSBM)[256];
  c1_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "arrSBM", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    (*c1_arrSBM)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_testKinectAllReceiver = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_testKinectAllReceiver");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_testKinectAllReceiver(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_kinectX;
  real_T c1_kinectY;
  real_T c1_kinectZ;
  uint32_T c1_debug_family_var_map[13];
  real_T c1_x;
  real_T c1_y;
  real_T c1_z;
  real_T c1_c1;
  real_T c1_c2;
  real_T c1_c3;
  int32_T c1_mystr_sizes[2];
  char_T c1_mystr_data[113];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_arrSBM[256];
  real_T c1_n;
  real_T c1_dv1[2];
  int32_T c1_iv0[2];
  int32_T c1_mystr;
  int32_T c1_b_mystr;
  int32_T c1_loop_ub;
  int32_T c1_i2;
  int32_T c1_i3;
  static char_T c1_cv0[76] = { 's', 'b', 'm', ' ', 'r', 'e', 'c', 'e', 'i', 'v',
    'e', 'r', ' ', 's', 'k', 'e', 'l', 'e', 't', 'o', 'n', ' ', 'C', 'h', 'r',
    'B', 'r', 'a', 'd', ' ', 'g', 'e', 'n', 'e', 'r', 'i', 'c', ' ', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', ' ', 'l', '_', 'w', 'r', 'i', 's', 't', ' ',
    '%', '0', '.', '1', 'f', ' ', '%', '0', '.', '1', 'f', ' ', '%', '0', '.',
    '1', 'f', ' ', '0', '.', '0' };

  char_T c1_u[76];
  const mxArray *c1_b_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_tmp_sizes[2];
  char_T c1_tmp_data[113];
  int32_T c1_c_mystr;
  int32_T c1_d_mystr;
  int32_T c1_b_loop_ub;
  int32_T c1_i4;
  int32_T c1_b_mystr_sizes[2];
  int32_T c1_e_mystr;
  int32_T c1_f_mystr;
  int32_T c1_c_loop_ub;
  int32_T c1_i5;
  char_T c1_b_mystr_data[113];
  uint32_T c1_b_debug_family_var_map[9];
  real_T c1_maxarrsize;
  int32_T c1_arr_sizes;
  real_T c1_arr_data[113];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_d_loop_ub;
  int32_T c1_i6;
  int32_T c1_i7;
  boolean_T c1_b0;
  boolean_T c1_b1;
  boolean_T c1_b2;
  int32_T c1_i8;
  int32_T c1_b_tmp_sizes;
  int32_T c1_e_loop_ub;
  int32_T c1_i9;
  int32_T c1_b_tmp_data[113];
  int32_T c1_iv1[1];
  int32_T c1_f_loop_ub;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T *c1_b_kinectX;
  real_T *c1_b_kinectY;
  real_T *c1_b_kinectZ;
  real_T (*c1_b_arrSBM)[256];
  c1_b_kinectZ = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_kinectY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_kinectX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_kinectX;
  c1_b_hoistedGlobal = *c1_b_kinectY;
  c1_c_hoistedGlobal = *c1_b_kinectZ;
  c1_kinectX = c1_hoistedGlobal;
  c1_kinectY = c1_b_hoistedGlobal;
  c1_kinectZ = c1_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_x, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_y, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_z, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c1, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c2, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c3, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_mystr_data, (const int32_T *)
    &c1_mystr_sizes, NULL, 0, 6, (void *)c1_c_sf_marshallOut, (void *)
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_kinectX, 9U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_kinectY, 10U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_kinectZ, 11U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_arrSBM, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_x = c1_kinectX;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_y = c1_kinectY;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_z = c1_kinectZ;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_c1 = c1_countDigits(chartInstance, c1_x);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_c2 = c1_countDigits(chartInstance, c1_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_c3 = c1_countDigits(chartInstance, c1_z);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_n = ((101.0 + c1_c1) + c1_c2) + c1_c3;
  c1_dv1[0] = 1.0;
  c1_dv1[1] = c1_n;
  c1_mystr_sizes[0] = 1;
  c1_iv0[0] = 1;
  c1_iv0[1] = (int32_T)c1_dv1[1];
  c1_mystr_sizes[1] = c1_iv0[1];
  c1_mystr = c1_mystr_sizes[0];
  c1_b_mystr = c1_mystr_sizes[1];
  c1_loop_ub = (int32_T)c1_dv1[1] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    c1_mystr_data[c1_i2] = ' ';
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i3 = 0; c1_i3 < 76; c1_i3++) {
    c1_u[c1_i3] = c1_cv0[c1_i3];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 76),
                false);
  c1_b_u = c1_x;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  c1_c_u = c1_y;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  c1_d_u = c1_z;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  c1_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "sprintf", 1U, 4U, 14,
                       c1_b_y, 14, c1_c_y, 14, c1_d_y, 14, c1_e_y), "sprintf",
                      c1_tmp_data, c1_tmp_sizes);
  c1_mystr_sizes[0] = 1;
  c1_mystr_sizes[1] = c1_tmp_sizes[1];
  c1_c_mystr = c1_mystr_sizes[0];
  c1_d_mystr = c1_mystr_sizes[1];
  c1_b_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i4 = 0; c1_i4 <= c1_b_loop_ub; c1_i4++) {
    c1_mystr_data[c1_i4] = c1_tmp_data[c1_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_b_mystr_sizes[0] = 1;
  c1_b_mystr_sizes[1] = c1_mystr_sizes[1];
  c1_e_mystr = c1_b_mystr_sizes[0];
  c1_f_mystr = c1_b_mystr_sizes[1];
  c1_c_loop_ub = c1_mystr_sizes[0] * c1_mystr_sizes[1] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
    c1_b_mystr_data[c1_i5] = c1_mystr_data[c1_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_c_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_arr_data, (const int32_T *)
    &c1_arr_sizes, NULL, 0, 1, (void *)c1_d_sf_marshallOut, (void *)
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ss, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_b_mystr_data, (const int32_T *)
    &c1_b_mystr_sizes, NULL, 1, 7, (void *)c1_c_sf_marshallOut, (void *)
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_arrSBM, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 6);
  c1_arr_sizes = c1_b_mystr_sizes[1];
  c1_d_loop_ub = c1_b_mystr_sizes[1] - 1;
  for (c1_i6 = 0; c1_i6 <= c1_d_loop_ub; c1_i6++) {
    c1_arr_data[c1_i6] = (real_T)c1_b_mystr_data[c1_b_mystr_sizes[0] * c1_i6];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 7);
  c1_ss = (real_T)c1_arr_sizes;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 8);
  c1_padsize = 256.0 - c1_ss;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 9);
  for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
    c1_tt[c1_i7] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 10);
  c1_b0 = (1.0 > c1_ss);
  c1_b1 = c1_b0;
  c1_b2 = c1_b1;
  if (c1_b2) {
    c1_i8 = 0;
  } else {
    c1_i8 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c1_ss, 1, 256, 0, 0);
  }

  c1_b_tmp_sizes = c1_i8;
  c1_e_loop_ub = c1_i8 - 1;
  for (c1_i9 = 0; c1_i9 <= c1_e_loop_ub; c1_i9++) {
    c1_b_tmp_data[c1_i9] = c1_i9;
  }

  c1_iv1[0] = c1_b_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c1_iv1, 1, *(int32_T (*)[1])&c1_arr_sizes, 1);
  c1_f_loop_ub = c1_arr_sizes - 1;
  for (c1_i10 = 0; c1_i10 <= c1_f_loop_ub; c1_i10++) {
    c1_tt[c1_b_tmp_data[c1_i10]] = c1_arr_data[c1_i10];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 11);
  for (c1_i11 = 0; c1_i11 < 256; c1_i11++) {
    c1_arrSBM[c1_i11] = c1_tt[c1_i11];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
    (*c1_b_arrSBM)[c1_i12] = c1_arrSBM[c1_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testKinectAllReceiverMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i13 = 0; c1_i13 < 256; c1_i13++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arrSBM)[c1_i13], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_kinectX, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_kinectY, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_kinectZ, 3U);
}

static void initSimStructsc1_testKinectAllReceiver
  (SFc1_testKinectAllReceiverInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c1_countDigits(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, real_T c1_x)
{
  real_T c1_num;
  uint32_T c1_debug_family_var_map[4];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_b_x;
  real_T c1_c_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_x, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_num, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_num = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  if (CV_SCRIPT_IF(0, 0, c1_x < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
    c1_num = 1.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 5);
    c1_b_x = c1_x;
    c1_c_x = c1_b_x;
    c1_x = muDoubleScalarAbs(c1_c_x);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  guard1 = false;
  if (CV_SCRIPT_COND(0, 0, c1_x > 0.0)) {
    if (CV_SCRIPT_COND(0, 1, c1_x < 9.0)) {
      CV_SCRIPT_MCDC(0, 0, true);
      CV_SCRIPT_IF(0, 1, true);
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
      c1_num++;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(0, 0, false);
    CV_SCRIPT_IF(0, 1, false);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
    guard2 = false;
    if (CV_SCRIPT_COND(0, 2, c1_x > 10.0)) {
      if (CV_SCRIPT_COND(0, 3, c1_x < 99.0)) {
        CV_SCRIPT_MCDC(0, 1, true);
        CV_SCRIPT_IF(0, 2, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
        c1_num += 2.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_SCRIPT_MCDC(0, 1, false);
      CV_SCRIPT_IF(0, 2, false);
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
      guard3 = false;
      if (CV_SCRIPT_COND(0, 4, c1_x > 100.0)) {
        if (CV_SCRIPT_COND(0, 5, c1_x < 999.0)) {
          CV_SCRIPT_MCDC(0, 2, true);
          CV_SCRIPT_IF(0, 3, true);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 12);
          c1_num += 3.0;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_SCRIPT_MCDC(0, 2, false);
        CV_SCRIPT_IF(0, 3, false);
      }
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  return c1_num;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\countDigits.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static void c1_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y_data[], int32_T c1_y_sizes[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sprintf), &c1_thisId,
                        c1_y_data, c1_y_sizes);
  sf_mex_destroy(&c1_sprintf);
}

static void c1_b_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y_data[], int32_T c1_y_sizes[2])
{
  int32_T c1_i14;
  uint32_T c1_uv0[2];
  int32_T c1_i15;
  static boolean_T c1_bv0[2] = { false, true };

  boolean_T c1_bv1[2];
  int32_T c1_tmp_sizes[2];
  char_T c1_tmp_data[113];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i16;
  (void)chartInstance;
  for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
    c1_uv0[c1_i14] = 1U + 112U * (uint32_T)c1_i14;
  }

  for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
    c1_bv1[c1_i15] = c1_bv0[c1_i15];
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c1_bv1, c1_uv0, c1_tmp_sizes);
  c1_y_sizes[0] = 1;
  c1_y_sizes[1] = c1_tmp_sizes[1];
  c1_y = c1_y_sizes[0];
  c1_b_y = c1_y_sizes[1];
  c1_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i16 = 0; c1_i16 <= c1_loop_ub; c1_i16++) {
    c1_y_data[c1_i16] = c1_tmp_data[c1_i16];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i17;
  real_T c1_b_inData[256];
  int32_T c1_i18;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i17 = 0; c1_i17 < 256; c1_i17++) {
    c1_b_inData[c1_i17] = (*(real_T (*)[256])c1_inData)[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 256; c1_i18++) {
    c1_u[c1_i18] = c1_b_inData[c1_i18];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_arrSBM, const char_T *c1_identifier, real_T
  c1_y[256])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_arrSBM), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_arrSBM);
}

static void c1_d_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256])
{
  real_T c1_dv2[256];
  int32_T c1_i19;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 256);
  for (c1_i19 = 0; c1_i19 < 256; c1_i19++) {
    c1_y[c1_i19] = c1_dv2[c1_i19];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_arrSBM;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[256];
  int32_T c1_i20;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_arrSBM = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_arrSBM), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_arrSBM);
  for (c1_i20 = 0; c1_i20 < 256; c1_i20++) {
    (*(real_T (*)[256])c1_outData)[c1_i20] = c1_y[c1_i20];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c1_inData_data[], int32_T c1_inData_sizes[2])
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes[2];
  int32_T c1_loop_ub;
  int32_T c1_i21;
  char_T c1_b_inData_data[113];
  int32_T c1_u_sizes[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i22;
  char_T c1_u_data[113];
  const mxArray *c1_y = NULL;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes[0] = 1;
  c1_b_inData_sizes[1] = c1_inData_sizes[1];
  c1_loop_ub = c1_inData_sizes[1] - 1;
  for (c1_i21 = 0; c1_i21 <= c1_loop_ub; c1_i21++) {
    c1_b_inData_data[c1_b_inData_sizes[0] * c1_i21] =
      c1_inData_data[c1_inData_sizes[0] * c1_i21];
  }

  c1_u_sizes[0] = 1;
  c1_u_sizes[1] = c1_b_inData_sizes[1];
  c1_b_loop_ub = c1_b_inData_sizes[1] - 1;
  for (c1_i22 = 0; c1_i22 <= c1_b_loop_ub; c1_i22++) {
    c1_u_data[c1_u_sizes[0] * c1_i22] = c1_b_inData_data[c1_b_inData_sizes[0] *
      c1_i22];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 10, 0U, 1U, 0U, 2,
    c1_u_sizes[0], c1_u_sizes[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y_data[], int32_T c1_y_sizes[2])
{
  int32_T c1_i23;
  uint32_T c1_uv1[2];
  int32_T c1_i24;
  static boolean_T c1_bv2[2] = { false, true };

  boolean_T c1_bv3[2];
  int32_T c1_tmp_sizes[2];
  char_T c1_tmp_data[113];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i25;
  (void)chartInstance;
  for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
    c1_uv1[c1_i23] = 1U + 112U * (uint32_T)c1_i23;
  }

  for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
    c1_bv3[c1_i24] = c1_bv2[c1_i24];
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c1_bv3, c1_uv1, c1_tmp_sizes);
  c1_y_sizes[0] = 1;
  c1_y_sizes[1] = c1_tmp_sizes[1];
  c1_y = c1_y_sizes[0];
  c1_b_y = c1_y_sizes[1];
  c1_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i25 = 0; c1_i25 <= c1_loop_ub; c1_i25++) {
    c1_y_data[c1_i25] = c1_tmp_data[c1_i25];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, char_T c1_outData_data[], int32_T
  c1_outData_sizes[2])
{
  const mxArray *c1_mystr;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes[2];
  char_T c1_y_data[113];
  int32_T c1_loop_ub;
  int32_T c1_i26;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_mystr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mystr), &c1_thisId,
                        c1_y_data, c1_y_sizes);
  sf_mex_destroy(&c1_mystr);
  c1_outData_sizes[0] = 1;
  c1_outData_sizes[1] = c1_y_sizes[1];
  c1_loop_ub = c1_y_sizes[1] - 1;
  for (c1_i26 = 0; c1_i26 <= c1_loop_ub; c1_i26++) {
    c1_outData_data[c1_outData_sizes[0] * c1_i26] = c1_y_data[c1_y_sizes[0] *
      c1_i26];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T *c1_inData_sizes)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i27;
  real_T c1_b_inData_data[113];
  int32_T c1_u_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i28;
  real_T c1_u_data[113];
  const mxArray *c1_y = NULL;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes = *c1_inData_sizes;
  c1_loop_ub = *c1_inData_sizes - 1;
  for (c1_i27 = 0; c1_i27 <= c1_loop_ub; c1_i27++) {
    c1_b_inData_data[c1_i27] = c1_inData_data[c1_i27];
  }

  c1_u_sizes = c1_b_inData_sizes;
  c1_b_loop_ub = c1_b_inData_sizes - 1;
  for (c1_i28 = 0; c1_i28 <= c1_b_loop_ub; c1_i28++) {
    c1_u_data[c1_i28] = c1_b_inData_data[c1_i28];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 0, 0U, 1U, 0U, 1,
    c1_u_sizes), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T *c1_y_sizes)
{
  static uint32_T c1_uv2[1] = { 113U };

  uint32_T c1_uv3[1];
  static boolean_T c1_bv4[1] = { true };

  boolean_T c1_bv5[1];
  int32_T c1_tmp_sizes;
  real_T c1_tmp_data[113];
  int32_T c1_loop_ub;
  int32_T c1_i29;
  (void)chartInstance;
  c1_uv3[0] = c1_uv2[0];
  c1_bv5[0] = c1_bv4[0];
  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c1_bv5, c1_uv3, &c1_tmp_sizes);
  *c1_y_sizes = c1_tmp_sizes;
  c1_loop_ub = c1_tmp_sizes - 1;
  for (c1_i29 = 0; c1_i29 <= c1_loop_ub; c1_i29++) {
    c1_y_data[c1_i29] = c1_tmp_data[c1_i29];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  *c1_outData_sizes)
{
  const mxArray *c1_arr;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes;
  real_T c1_y_data[113];
  int32_T c1_loop_ub;
  int32_T c1_i30;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_arr = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_arr), &c1_thisId, c1_y_data,
                        &c1_y_sizes);
  sf_mex_destroy(&c1_arr);
  *c1_outData_sizes = c1_y_sizes;
  c1_loop_ub = c1_y_sizes - 1;
  for (c1_i30 = 0; c1_i30 <= c1_loop_ub; c1_i30++) {
    c1_outData_data[c1_i30] = c1_y_data[c1_i30];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_testKinectAllReceiver_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("countDigits"), "name", "name",
                  0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/countDigits.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1408487908U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/countDigits.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("abs"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("blanks"), "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_h_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i31;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i31, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i31;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_testKinectAllReceiver, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_testKinectAllReceiver), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_testKinectAllReceiver);
  return c1_y;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_testKinectAllReceiverInstanceStruct
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

void sf_c1_testKinectAllReceiver_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1166460987U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2154657645U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3168982125U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2377008341U);
}

mxArray *sf_c1_testKinectAllReceiver_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BVyyIECUxjt46Y8on28qfE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(256);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_testKinectAllReceiver_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_testKinectAllReceiver_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_testKinectAllReceiver(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"arrSBM\",},{M[8],M[0],T\"is_active_c1_testKinectAllReceiver\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_testKinectAllReceiver_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testKinectAllReceiverMachineNumber_,
           1,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testKinectAllReceiverMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testKinectAllReceiverMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testKinectAllReceiverMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"arrSBM");
          _SFD_SET_DATA_PROPS(1,1,1,0,"kinectX");
          _SFD_SET_DATA_PROPS(2,1,1,0,"kinectY");
          _SFD_SET_DATA_PROPS(3,1,1,0,"kinectZ");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,476);
        _SFD_CV_INIT_SCRIPT(0,1,4,0,0,0,0,0,6,3);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"countDigits",0,-1,267);
        _SFD_CV_INIT_SCRIPT_IF(0,0,43,49,-1,94);
        _SFD_CV_INIT_SCRIPT_IF(0,1,103,120,152,175);
        _SFD_CV_INIT_SCRIPT_IF(0,2,152,175,207,263);
        _SFD_CV_INIT_SCRIPT_IF(0,3,207,232,-1,232);

        {
          static int condStart[] = { 107, 116 };

          static int condEnd[] = { 110, 119 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,106,120,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 160, 170 };

          static int condEnd[] = { 164, 174 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,1,159,175,2,2,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 215, 226 };

          static int condEnd[] = { 220, 231 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,2,214,232,2,4,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"encStr2Arr",0,-1,436);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_kinectX;
          real_T *c1_kinectY;
          real_T *c1_kinectZ;
          real_T (*c1_arrSBM)[256];
          c1_kinectZ = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_kinectY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_kinectX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_arrSBM);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_kinectX);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_kinectY);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_kinectZ);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testKinectAllReceiverMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "6znlHfqlttVbi1V7lDoSuE";
}

static void sf_opaque_initialize_c1_testKinectAllReceiver(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_testKinectAllReceiver
    ((SFc1_testKinectAllReceiverInstanceStruct*) chartInstanceVar);
  initialize_c1_testKinectAllReceiver((SFc1_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_testKinectAllReceiver(void *chartInstanceVar)
{
  enable_c1_testKinectAllReceiver((SFc1_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_testKinectAllReceiver(void *chartInstanceVar)
{
  disable_c1_testKinectAllReceiver((SFc1_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_testKinectAllReceiver(void *chartInstanceVar)
{
  sf_gateway_c1_testKinectAllReceiver((SFc1_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_testKinectAllReceiver
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_testKinectAllReceiver
    ((SFc1_testKinectAllReceiverInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_testKinectAllReceiver();/* state var info */
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

extern void sf_internal_set_sim_state_c1_testKinectAllReceiver(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_testKinectAllReceiver();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_testKinectAllReceiver
    ((SFc1_testKinectAllReceiverInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_testKinectAllReceiver(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_testKinectAllReceiver(S);
}

static void sf_opaque_set_sim_state_c1_testKinectAllReceiver(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_testKinectAllReceiver(S, st);
}

static void sf_opaque_terminate_c1_testKinectAllReceiver(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_testKinectAllReceiverInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testKinectAllReceiver_optimization_info();
    }

    finalize_c1_testKinectAllReceiver((SFc1_testKinectAllReceiverInstanceStruct*)
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
  initSimStructsc1_testKinectAllReceiver
    ((SFc1_testKinectAllReceiverInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_testKinectAllReceiver(SimStruct *S)
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
    initialize_params_c1_testKinectAllReceiver
      ((SFc1_testKinectAllReceiverInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_testKinectAllReceiver(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testKinectAllReceiver_optimization_info();
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2610989949U));
  ssSetChecksum1(S,(4161452299U));
  ssSetChecksum2(S,(3144460811U));
  ssSetChecksum3(S,(3787888494U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_testKinectAllReceiver(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_testKinectAllReceiver(SimStruct *S)
{
  SFc1_testKinectAllReceiverInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_testKinectAllReceiverInstanceStruct *)utMalloc(sizeof
    (SFc1_testKinectAllReceiverInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_testKinectAllReceiverInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_testKinectAllReceiver;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_testKinectAllReceiver;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_testKinectAllReceiver;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_testKinectAllReceiver;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_testKinectAllReceiver;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_testKinectAllReceiver;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_testKinectAllReceiver;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_testKinectAllReceiver;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_testKinectAllReceiver;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_testKinectAllReceiver;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_testKinectAllReceiver;
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

void c1_testKinectAllReceiver_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_testKinectAllReceiver(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_testKinectAllReceiver(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_testKinectAllReceiver(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_testKinectAllReceiver_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
