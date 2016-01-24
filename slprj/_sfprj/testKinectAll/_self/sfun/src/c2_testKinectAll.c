/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testKinectAll_sfun.h"
#include "c2_testKinectAll.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testKinectAll_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[12] = { "joint", "temp", "n", "mystr",
  "nargin", "nargout", "tagID", "w", "x", "y", "z", "arrSBM" };

static const char * c2_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c2_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance);
static void initialize_params_c2_testKinectAll(SFc2_testKinectAllInstanceStruct *
  chartInstance);
static void enable_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance);
static void disable_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_testKinectAll
  (SFc2_testKinectAllInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_testKinectAll
  (SFc2_testKinectAllInstanceStruct *chartInstance);
static void set_sim_state_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance);
static void sf_gateway_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance);
static void initSimStructsc2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance);
static void c2_encStr2Arr(SFc2_testKinectAllInstanceStruct *chartInstance,
  char_T c2_mystr_data[], int32_T c2_mystr_sizes[2], real_T c2_myarr256[256]);
static void c2_b_encStr2Arr(SFc2_testKinectAllInstanceStruct *chartInstance,
  real_T c2_myarr256[256]);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static void c2_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct *chartInstance,
  const mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y_data[],
  int32_T c2_y_sizes[2]);
static void c2_b_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y_data[], int32_T c2_y_sizes[2]);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_arrSBM, const char_T *c2_identifier, real_T
  c2_y[256]);
static void c2_d_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c2_inData_data[], int32_T c2_inData_sizes[2]);
static void c2_f_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y_data[], int32_T c2_y_sizes[2]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, char_T c2_outData_data[], int32_T
  c2_outData_sizes[2]);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, char_T
  c2_inData_data[], int32_T c2_inData_sizes[2]);
static void c2_g_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y_data[], int32_T c2_y_sizes[2]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, char_T c2_outData_data[], int32_T
  c2_outData_sizes[2]);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c2_inData_data[], int32_T *c2_inData_sizes);
static void c2_h_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y_data[], int32_T *c2_y_sizes);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real_T c2_outData_data[], int32_T
  *c2_outData_sizes);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_testKinectAll, const char_T
  *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_testKinectAllInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_testKinectAll = 0U;
}

static void initialize_params_c2_testKinectAll(SFc2_testKinectAllInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_testKinectAll
  (SFc2_testKinectAllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_testKinectAll
  (SFc2_testKinectAllInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[256];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_arrSBM)[256];
  c2_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  for (c2_i0 = 0; c2_i0 < 256; c2_i0++) {
    c2_u[c2_i0] = (*c2_arrSBM)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_testKinectAll;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[256];
  int32_T c2_i1;
  real_T (*c2_arrSBM)[256];
  c2_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "arrSBM", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 256; c2_i1++) {
    (*c2_arrSBM)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_testKinectAll = c2_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_testKinectAll");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_testKinectAll(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_tagID;
  real_T c2_w;
  real_T c2_x;
  real_T c2_y;
  real_T c2_z;
  uint32_T c2_debug_family_var_map[12];
  int32_T c2_joint_sizes[2];
  char_T c2_joint_data[10];
  const mxArray *c2_temp = NULL;
  real_T c2_n;
  char_T c2_mystr[256];
  int32_T c2_mystr_sizes[2];
  char_T c2_mystr_data[118];
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 1.0;
  real_T c2_arrSBM[256];
  int32_T c2_i2;
  static char_T c2_cv0[27] = { '+', '+', '+', '+', '+', 'i', 'n', ' ', 's', 'e',
    'n', 'd', 'S', 'm', 'a', 'r', 't', 'b', 'o', 'd', 'y', '+', '+', '+', '+',
    '+', '+' };

  char_T c2_u[27];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i3;
  static char_T c2_cv1[13] = { 's', 'h', 'o', 'u', 'l', 'd', 'e', 'r', 'r', 'i',
    'g', 'h', 't' };

  char_T c2_b_u[13];
  const mxArray *c2_c_y = NULL;
  int32_T c2_joint;
  int32_T c2_b_joint;
  int32_T c2_i4;
  static char_T c2_cv2[10] = { 'r', '_', 's', 'h', 'o', 'u', 'l', 'd', 'e', 'r'
  };

  int32_T c2_i5;
  static char_T c2_cv3[10] = { 'w', 'r', 'i', 's', 't', 'r', 'i', 'g', 'h', 't'
  };

  char_T c2_c_u[10];
  const mxArray *c2_d_y = NULL;
  int32_T c2_c_joint;
  int32_T c2_d_joint;
  int32_T c2_i6;
  static char_T c2_cv4[7] = { 'r', '_', 'w', 'r', 'i', 's', 't' };

  int32_T c2_i7;
  static char_T c2_cv5[36] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\\', '\"' };

  char_T c2_d_u[36];
  const mxArray *c2_e_y = NULL;
  int32_T c2_u_sizes[2];
  int32_T c2_e_u;
  int32_T c2_f_u;
  int32_T c2_loop_ub;
  int32_T c2_i8;
  char_T c2_u_data[10];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i9;
  static char_T c2_cv6[52] = { '\\', '\"', ')', '.', 's', 'e', 't', 'P', 'o',
    's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u',
    'a', 't', '(', '%', '0', '.', '2', 'f', ',', '%', '0', '.', '2', 'f', ',',
    '%', '0', '.', '2', 'f', ',', '%', '0', '.', '2', 'f', ')', ')' };

  char_T c2_g_u[52];
  const mxArray *c2_g_y = NULL;
  int32_T c2_x_sizes[2];
  int32_T c2_b_x;
  int32_T c2_c_x;
  int32_T c2_b_loop_ub;
  int32_T c2_i10;
  char_T c2_x_data[10];
  real_T c2_b_n;
  real_T c2_dv1[2];
  int32_T c2_iv0[2];
  int32_T c2_b_mystr;
  int32_T c2_c_mystr;
  int32_T c2_c_loop_ub;
  int32_T c2_i11;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  int32_T c2_tmp_sizes[2];
  char_T c2_tmp_data[118];
  int32_T c2_d_mystr;
  int32_T c2_e_mystr;
  int32_T c2_d_loop_ub;
  int32_T c2_i12;
  int32_T c2_b_mystr_sizes[2];
  int32_T c2_f_mystr;
  int32_T c2_g_mystr;
  int32_T c2_e_loop_ub;
  int32_T c2_i13;
  char_T c2_b_mystr_data[118];
  real_T c2_dv2[256];
  int32_T c2_i14;
  int32_T c2_i15;
  real_T c2_dv3[256];
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_e_joint;
  int32_T c2_f_joint;
  real_T *c2_b_tagID;
  real_T *c2_b_w;
  real_T *c2_d_x;
  real_T *c2_l_y;
  real_T *c2_b_z;
  real_T (*c2_b_arrSBM)[256];
  c2_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_l_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_d_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_tagID = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_tagID, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_w, 1U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_tagID;
  c2_b_hoistedGlobal = *c2_b_w;
  c2_c_hoistedGlobal = *c2_d_x;
  c2_d_hoistedGlobal = *c2_l_y;
  c2_e_hoistedGlobal = *c2_b_z;
  c2_tagID = c2_hoistedGlobal;
  c2_w = c2_b_hoistedGlobal;
  c2_x = c2_c_hoistedGlobal;
  c2_y = c2_d_hoistedGlobal;
  c2_z = c2_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 13U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c2_joint_data, (const int32_T *)
    &c2_joint_sizes, NULL, 0, 0, (void *)c2_f_sf_marshallOut, (void *)
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_temp, 1U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_n, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, MAX_uint32_T, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c2_mystr_data, (const int32_T *)
    &c2_mystr_sizes, NULL, 0, -1, (void *)c2_c_sf_marshallOut, (void *)
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_tagID, 6U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_w, 7U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_x, 8U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_y, 9U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_z, 10U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_arrSBM, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i2 = 0; c2_i2 < 27; c2_i2++) {
    c2_u[c2_i2] = c2_cv0[c2_i2];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c2_b_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  switch ((int32_T)_SFD_INTEGER_CHECK("tagID", c2_tagID)) {
   case 6:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
    for (c2_i3 = 0; c2_i3 < 13; c2_i3++) {
      c2_b_u[c2_i3] = c2_cv1[c2_i3];
    }

    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 13),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c2_c_y);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
    c2_joint_sizes[0] = 1;
    c2_joint_sizes[1] = 10;
    c2_joint = c2_joint_sizes[0];
    c2_b_joint = c2_joint_sizes[1];
    for (c2_i4 = 0; c2_i4 < 10; c2_i4++) {
      c2_joint_data[c2_i4] = c2_cv2[c2_i4];
    }
    break;

   case 11:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
    for (c2_i5 = 0; c2_i5 < 10; c2_i5++) {
      c2_c_u[c2_i5] = c2_cv3[c2_i5];
    }

    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 10),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c2_d_y);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
    c2_joint_sizes[0] = 1;
    c2_joint_sizes[1] = 7;
    c2_c_joint = c2_joint_sizes[0];
    c2_d_joint = c2_joint_sizes[1];
    for (c2_i6 = 0; c2_i6 < 7; c2_i6++) {
      c2_joint_data[c2_i6] = c2_cv4[c2_i6];
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
    c2_joint_sizes[0] = 1;
    c2_joint_sizes[1] = 0;
    c2_e_joint = c2_joint_sizes[0];
    c2_f_joint = c2_joint_sizes[1];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
    c2_w = 1.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
  if (CV_EML_IF(0, 1, 0, (real_T)c2_joint_sizes[1] > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
    for (c2_i7 = 0; c2_i7 < 36; c2_i7++) {
      c2_d_u[c2_i7] = c2_cv5[c2_i7];
    }

    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_u_sizes[0] = 1;
    c2_u_sizes[1] = c2_joint_sizes[1];
    c2_e_u = c2_u_sizes[0];
    c2_f_u = c2_u_sizes[1];
    c2_loop_ub = c2_joint_sizes[0] * c2_joint_sizes[1] - 1;
    for (c2_i8 = 0; c2_i8 <= c2_loop_ub; c2_i8++) {
      c2_u_data[c2_i8] = c2_joint_data[c2_i8];
    }

    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_u_data, 10, 0U, 1U, 0U, 2,
      c2_u_sizes[0], c2_u_sizes[1]), false);
    for (c2_i9 = 0; c2_i9 < 52; c2_i9++) {
      c2_g_u[c2_i9] = c2_cv6[c2_i9];
    }

    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_g_u, 10, 0U, 1U, 0U, 2, 1, 52),
                  false);
    sf_mex_assign(&c2_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "strcat", 1U, 3U, 14, c2_e_y, 14, c2_f_y, 14, c2_g_y), false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
    c2_x_sizes[0] = 1;
    c2_x_sizes[1] = c2_joint_sizes[1];
    c2_b_x = c2_x_sizes[0];
    c2_c_x = c2_x_sizes[1];
    c2_b_loop_ub = c2_joint_sizes[0] * c2_joint_sizes[1] - 1;
    for (c2_i10 = 0; c2_i10 <= c2_b_loop_ub; c2_i10++) {
      c2_x_data[c2_i10] = c2_joint_data[c2_i10];
    }

    c2_n = (real_T)c2_x_sizes[1];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 96);
    c2_b_n = c2_n + 108.0;
    c2_dv1[0] = 1.0;
    c2_dv1[1] = c2_b_n;
    c2_mystr_sizes[0] = 1;
    c2_iv0[0] = 1;
    c2_iv0[1] = (int32_T)c2_dv1[1];
    c2_mystr_sizes[1] = c2_iv0[1];
    c2_b_mystr = c2_mystr_sizes[0];
    c2_c_mystr = c2_mystr_sizes[1];
    c2_c_loop_ub = (int32_T)c2_dv1[1] - 1;
    for (c2_i11 = 0; c2_i11 <= c2_c_loop_ub; c2_i11++) {
      c2_mystr_data[c2_i11] = ' ';
    }

    _SFD_SYMBOL_SWITCH(3U, 4U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 97);
    c2_h_u = c2_w;
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
    c2_i_u = c2_x;
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), false);
    c2_j_u = c2_y;
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), false);
    c2_k_u = c2_z;
    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), false);
    c2_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 5U, 14,
                         sf_mex_dup(c2_temp), 14, c2_h_y, 14, c2_i_y, 14, c2_j_y,
                         14, c2_k_y), "sprintf", c2_tmp_data, c2_tmp_sizes);
    c2_mystr_sizes[0] = 1;
    c2_mystr_sizes[1] = c2_tmp_sizes[1];
    c2_d_mystr = c2_mystr_sizes[0];
    c2_e_mystr = c2_mystr_sizes[1];
    c2_d_loop_ub = c2_tmp_sizes[0] * c2_tmp_sizes[1] - 1;
    for (c2_i12 = 0; c2_i12 <= c2_d_loop_ub; c2_i12++) {
      c2_mystr_data[c2_i12] = c2_tmp_data[c2_i12];
    }

    _SFD_SYMBOL_SWITCH(3U, 4U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 98);
    c2_b_mystr_sizes[0] = 1;
    c2_b_mystr_sizes[1] = c2_mystr_sizes[1];
    c2_f_mystr = c2_b_mystr_sizes[0];
    c2_g_mystr = c2_b_mystr_sizes[1];
    c2_e_loop_ub = c2_mystr_sizes[0] * c2_mystr_sizes[1] - 1;
    for (c2_i13 = 0; c2_i13 <= c2_e_loop_ub; c2_i13++) {
      c2_b_mystr_data[c2_i13] = c2_mystr_data[c2_i13];
    }

    c2_encStr2Arr(chartInstance, c2_b_mystr_data, c2_b_mystr_sizes, c2_dv2);
    for (c2_i14 = 0; c2_i14 < 256; c2_i14++) {
      c2_arrSBM[c2_i14] = c2_dv2[c2_i14];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 100);
    for (c2_i15 = 0; c2_i15 < 256; c2_i15++) {
      c2_mystr[c2_i15] = ' ';
    }

    _SFD_SYMBOL_SWITCH(3U, 3U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
    c2_b_encStr2Arr(chartInstance, c2_dv3);
    for (c2_i16 = 0; c2_i16 < 256; c2_i16++) {
      c2_arrSBM[c2_i16] = c2_dv3[c2_i16];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -101);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c2_temp);
  for (c2_i17 = 0; c2_i17 < 256; c2_i17++) {
    (*c2_b_arrSBM)[c2_i17] = c2_arrSBM[c2_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testKinectAllMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i18 = 0; c2_i18 < 256; c2_i18++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_arrSBM)[c2_i18], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_d_x, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_l_y, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_z, 5U);
}

static void initSimStructsc2_testKinectAll(SFc2_testKinectAllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_encStr2Arr(SFc2_testKinectAllInstanceStruct *chartInstance,
  char_T c2_mystr_data[], int32_T c2_mystr_sizes[2], real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  int32_T c2_arr_sizes;
  real_T c2_arr_data[118];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_loop_ub;
  int32_T c2_i19;
  int32_T c2_i20;
  boolean_T c2_b0;
  boolean_T c2_b1;
  boolean_T c2_b2;
  int32_T c2_i21;
  int32_T c2_tmp_sizes;
  int32_T c2_b_loop_ub;
  int32_T c2_i22;
  int32_T c2_tmp_data[118];
  int32_T c2_iv1[1];
  int32_T c2_c_loop_ub;
  int32_T c2_i23;
  int32_T c2_i24;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c2_arr_data, (const int32_T *)
    &c2_arr_sizes, NULL, 0, 1, (void *)c2_g_sf_marshallOut, (void *)
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ss, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c2_mystr_data, (const int32_T *)
    c2_mystr_sizes, NULL, 1, 7, (void *)c2_c_sf_marshallOut, (void *)
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_arr_sizes = c2_mystr_sizes[1];
  c2_loop_ub = c2_mystr_sizes[1] - 1;
  for (c2_i19 = 0; c2_i19 <= c2_loop_ub; c2_i19++) {
    c2_arr_data[c2_i19] = (real_T)c2_mystr_data[c2_mystr_sizes[0] * c2_i19];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = (real_T)c2_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = 256.0 - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i20 = 0; c2_i20 < 256; c2_i20++) {
    c2_tt[c2_i20] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_b0 = (1.0 > c2_ss);
  c2_b1 = c2_b0;
  c2_b2 = c2_b1;
  if (c2_b2) {
    c2_i21 = 0;
  } else {
    c2_i21 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c2_ss, 1, 256, 0, 0);
  }

  c2_tmp_sizes = c2_i21;
  c2_b_loop_ub = c2_i21 - 1;
  for (c2_i22 = 0; c2_i22 <= c2_b_loop_ub; c2_i22++) {
    c2_tmp_data[c2_i22] = c2_i22;
  }

  c2_iv1[0] = c2_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv1, 1, *(int32_T (*)[1])&c2_arr_sizes, 1);
  c2_c_loop_ub = c2_arr_sizes - 1;
  for (c2_i23 = 0; c2_i23 <= c2_c_loop_ub; c2_i23++) {
    c2_tt[c2_tmp_data[c2_i23]] = c2_arr_data[c2_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i24 = 0; c2_i24 < 256; c2_i24++) {
    c2_myarr256[c2_i24] = c2_tt[c2_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_b_encStr2Arr(SFc2_testKinectAllInstanceStruct *chartInstance,
  real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[256];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[256];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  for (c2_i25 = 0; c2_i25 < 256; c2_i25++) {
    c2_mystr[c2_i25] = ' ';
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i26 = 0; c2_i26 < 256; c2_i26++) {
    c2_arr[c2_i26] = 32.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i27 = 0; c2_i27 < 256; c2_i27++) {
    c2_tt[c2_i27] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i28 = 0; c2_i28 < 256; c2_i28++) {
    c2_tt[c2_i28] = c2_arr[c2_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i29 = 0; c2_i29 < 256; c2_i29++) {
    c2_myarr256[c2_i29] = c2_tt[c2_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static void c2_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct *chartInstance,
  const mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y_data[],
  int32_T c2_y_sizes[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId,
                        c2_y_data, c2_y_sizes);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_b_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y_data[], int32_T c2_y_sizes[2])
{
  int32_T c2_i30;
  uint32_T c2_uv0[2];
  int32_T c2_i31;
  static boolean_T c2_bv0[2] = { false, true };

  boolean_T c2_bv1[2];
  int32_T c2_tmp_sizes[2];
  char_T c2_tmp_data[118];
  int32_T c2_y;
  int32_T c2_b_y;
  int32_T c2_loop_ub;
  int32_T c2_i32;
  (void)chartInstance;
  for (c2_i30 = 0; c2_i30 < 2; c2_i30++) {
    c2_uv0[c2_i30] = 1U + 117U * (uint32_T)c2_i30;
  }

  for (c2_i31 = 0; c2_i31 < 2; c2_i31++) {
    c2_bv1[c2_i31] = c2_bv0[c2_i31];
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_u), c2_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c2_bv1, c2_uv0, c2_tmp_sizes);
  c2_y_sizes[0] = 1;
  c2_y_sizes[1] = c2_tmp_sizes[1];
  c2_y = c2_y_sizes[0];
  c2_b_y = c2_y_sizes[1];
  c2_loop_ub = c2_tmp_sizes[0] * c2_tmp_sizes[1] - 1;
  for (c2_i32 = 0; c2_i32 <= c2_loop_ub; c2_i32++) {
    c2_y_data[c2_i32] = c2_tmp_data[c2_i32];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i33;
  real_T c2_b_inData[256];
  int32_T c2_i34;
  real_T c2_u[256];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i33 = 0; c2_i33 < 256; c2_i33++) {
    c2_b_inData[c2_i33] = (*(real_T (*)[256])c2_inData)[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 256; c2_i34++) {
    c2_u[c2_i34] = c2_b_inData[c2_i34];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_arrSBM, const char_T *c2_identifier, real_T
  c2_y[256])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_arrSBM), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_arrSBM);
}

static void c2_d_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256])
{
  real_T c2_dv4[256];
  int32_T c2_i35;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 1, 256);
  for (c2_i35 = 0; c2_i35 < 256; c2_i35++) {
    c2_y[c2_i35] = c2_dv4[c2_i35];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_arrSBM;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[256];
  int32_T c2_i36;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_arrSBM = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_arrSBM), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_arrSBM);
  for (c2_i36 = 0; c2_i36 < 256; c2_i36++) {
    (*(real_T (*)[256])c2_outData)[c2_i36] = c2_y[c2_i36];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c2_inData_data[], int32_T c2_inData_sizes[2])
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_inData_sizes[2];
  int32_T c2_loop_ub;
  int32_T c2_i37;
  char_T c2_b_inData_data[118];
  int32_T c2_u_sizes[2];
  int32_T c2_b_loop_ub;
  int32_T c2_i38;
  char_T c2_u_data[118];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_inData_sizes[0] = 1;
  c2_b_inData_sizes[1] = c2_inData_sizes[1];
  c2_loop_ub = c2_inData_sizes[1] - 1;
  for (c2_i37 = 0; c2_i37 <= c2_loop_ub; c2_i37++) {
    c2_b_inData_data[c2_b_inData_sizes[0] * c2_i37] =
      c2_inData_data[c2_inData_sizes[0] * c2_i37];
  }

  c2_u_sizes[0] = 1;
  c2_u_sizes[1] = c2_b_inData_sizes[1];
  c2_b_loop_ub = c2_b_inData_sizes[1] - 1;
  for (c2_i38 = 0; c2_i38 <= c2_b_loop_ub; c2_i38++) {
    c2_u_data[c2_u_sizes[0] * c2_i38] = c2_b_inData_data[c2_b_inData_sizes[0] *
      c2_i38];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u_data, 10, 0U, 1U, 0U, 2,
    c2_u_sizes[0], c2_u_sizes[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y_data[], int32_T c2_y_sizes[2])
{
  int32_T c2_i39;
  uint32_T c2_uv1[2];
  int32_T c2_i40;
  static boolean_T c2_bv2[2] = { false, true };

  boolean_T c2_bv3[2];
  int32_T c2_tmp_sizes[2];
  char_T c2_tmp_data[118];
  int32_T c2_y;
  int32_T c2_b_y;
  int32_T c2_loop_ub;
  int32_T c2_i41;
  (void)chartInstance;
  for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
    c2_uv1[c2_i39] = 1U + 117U * (uint32_T)c2_i39;
  }

  for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
    c2_bv3[c2_i40] = c2_bv2[c2_i40];
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_u), c2_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c2_bv3, c2_uv1, c2_tmp_sizes);
  c2_y_sizes[0] = 1;
  c2_y_sizes[1] = c2_tmp_sizes[1];
  c2_y = c2_y_sizes[0];
  c2_b_y = c2_y_sizes[1];
  c2_loop_ub = c2_tmp_sizes[0] * c2_tmp_sizes[1] - 1;
  for (c2_i41 = 0; c2_i41 <= c2_loop_ub; c2_i41++) {
    c2_y_data[c2_i41] = c2_tmp_data[c2_i41];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, char_T c2_outData_data[], int32_T
  c2_outData_sizes[2])
{
  const mxArray *c2_mystr;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y_sizes[2];
  char_T c2_y_data[118];
  int32_T c2_loop_ub;
  int32_T c2_i42;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mystr = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_mystr), &c2_thisId,
                        c2_y_data, c2_y_sizes);
  sf_mex_destroy(&c2_mystr);
  c2_outData_sizes[0] = 1;
  c2_outData_sizes[1] = c2_y_sizes[1];
  c2_loop_ub = c2_y_sizes[1] - 1;
  for (c2_i42 = 0; c2_i42 <= c2_loop_ub; c2_i42++) {
    c2_outData_data[c2_outData_sizes[0] * c2_i42] = c2_y_data[c2_y_sizes[0] *
      c2_i42];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i43;
  char_T c2_b_inData[256];
  int32_T c2_i44;
  char_T c2_u[256];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i43 = 0; c2_i43 < 256; c2_i43++) {
    c2_b_inData[c2_i43] = (*(char_T (*)[256])c2_inData)[c2_i43];
  }

  for (c2_i44 = 0; c2_i44 < 256; c2_i44++) {
    c2_u[c2_i44] = c2_b_inData[c2_i44];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 256),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  const mxArray *c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = sf_mex_dup(*(const mxArray **)c2_inData);
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, char_T
  c2_inData_data[], int32_T c2_inData_sizes[2])
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_inData_sizes[2];
  int32_T c2_loop_ub;
  int32_T c2_i45;
  char_T c2_b_inData_data[10];
  int32_T c2_u_sizes[2];
  int32_T c2_b_loop_ub;
  int32_T c2_i46;
  char_T c2_u_data[10];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_inData_sizes[0] = 1;
  c2_b_inData_sizes[1] = c2_inData_sizes[1];
  c2_loop_ub = c2_inData_sizes[1] - 1;
  for (c2_i45 = 0; c2_i45 <= c2_loop_ub; c2_i45++) {
    c2_b_inData_data[c2_b_inData_sizes[0] * c2_i45] =
      c2_inData_data[c2_inData_sizes[0] * c2_i45];
  }

  c2_u_sizes[0] = 1;
  c2_u_sizes[1] = c2_b_inData_sizes[1];
  c2_b_loop_ub = c2_b_inData_sizes[1] - 1;
  for (c2_i46 = 0; c2_i46 <= c2_b_loop_ub; c2_i46++) {
    c2_u_data[c2_u_sizes[0] * c2_i46] = c2_b_inData_data[c2_b_inData_sizes[0] *
      c2_i46];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u_data, 10, 0U, 1U, 0U, 2,
    c2_u_sizes[0], c2_u_sizes[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y_data[], int32_T c2_y_sizes[2])
{
  int32_T c2_i47;
  uint32_T c2_uv2[2];
  int32_T c2_i48;
  static boolean_T c2_bv4[2] = { false, true };

  boolean_T c2_bv5[2];
  int32_T c2_tmp_sizes[2];
  char_T c2_tmp_data[10];
  int32_T c2_y;
  int32_T c2_b_y;
  int32_T c2_loop_ub;
  int32_T c2_i49;
  (void)chartInstance;
  for (c2_i47 = 0; c2_i47 < 2; c2_i47++) {
    c2_uv2[c2_i47] = 1U + 9U * (uint32_T)c2_i47;
  }

  for (c2_i48 = 0; c2_i48 < 2; c2_i48++) {
    c2_bv5[c2_i48] = c2_bv4[c2_i48];
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_u), c2_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c2_bv5, c2_uv2, c2_tmp_sizes);
  c2_y_sizes[0] = 1;
  c2_y_sizes[1] = c2_tmp_sizes[1];
  c2_y = c2_y_sizes[0];
  c2_b_y = c2_y_sizes[1];
  c2_loop_ub = c2_tmp_sizes[0] * c2_tmp_sizes[1] - 1;
  for (c2_i49 = 0; c2_i49 <= c2_loop_ub; c2_i49++) {
    c2_y_data[c2_i49] = c2_tmp_data[c2_i49];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, char_T c2_outData_data[], int32_T
  c2_outData_sizes[2])
{
  const mxArray *c2_joint;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y_sizes[2];
  char_T c2_y_data[10];
  int32_T c2_loop_ub;
  int32_T c2_i50;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_joint = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_joint), &c2_thisId,
                        c2_y_data, c2_y_sizes);
  sf_mex_destroy(&c2_joint);
  c2_outData_sizes[0] = 1;
  c2_outData_sizes[1] = c2_y_sizes[1];
  c2_loop_ub = c2_y_sizes[1] - 1;
  for (c2_i50 = 0; c2_i50 <= c2_loop_ub; c2_i50++) {
    c2_outData_data[c2_outData_sizes[0] * c2_i50] = c2_y_data[c2_y_sizes[0] *
      c2_i50];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c2_inData_data[], int32_T *c2_inData_sizes)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_inData_sizes;
  int32_T c2_loop_ub;
  int32_T c2_i51;
  real_T c2_b_inData_data[118];
  int32_T c2_u_sizes;
  int32_T c2_b_loop_ub;
  int32_T c2_i52;
  real_T c2_u_data[118];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_inData_sizes = *c2_inData_sizes;
  c2_loop_ub = *c2_inData_sizes - 1;
  for (c2_i51 = 0; c2_i51 <= c2_loop_ub; c2_i51++) {
    c2_b_inData_data[c2_i51] = c2_inData_data[c2_i51];
  }

  c2_u_sizes = c2_b_inData_sizes;
  c2_b_loop_ub = c2_b_inData_sizes - 1;
  for (c2_i52 = 0; c2_i52 <= c2_b_loop_ub; c2_i52++) {
    c2_u_data[c2_i52] = c2_b_inData_data[c2_i52];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u_data, 0, 0U, 1U, 0U, 1,
    c2_u_sizes), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y_data[], int32_T *c2_y_sizes)
{
  static uint32_T c2_uv3[1] = { 118U };

  uint32_T c2_uv4[1];
  static boolean_T c2_bv6[1] = { true };

  boolean_T c2_bv7[1];
  int32_T c2_tmp_sizes;
  real_T c2_tmp_data[118];
  int32_T c2_loop_ub;
  int32_T c2_i53;
  (void)chartInstance;
  c2_uv4[0] = c2_uv3[0];
  c2_bv7[0] = c2_bv6[0];
  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_u), c2_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c2_bv7, c2_uv4, &c2_tmp_sizes);
  *c2_y_sizes = c2_tmp_sizes;
  c2_loop_ub = c2_tmp_sizes - 1;
  for (c2_i53 = 0; c2_i53 <= c2_loop_ub; c2_i53++) {
    c2_y_data[c2_i53] = c2_tmp_data[c2_i53];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real_T c2_outData_data[], int32_T
  *c2_outData_sizes)
{
  const mxArray *c2_arr;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y_sizes;
  real_T c2_y_data[118];
  int32_T c2_loop_ub;
  int32_T c2_i54;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_arr = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_arr), &c2_thisId, c2_y_data,
                        &c2_y_sizes);
  sf_mex_destroy(&c2_arr);
  *c2_outData_sizes = c2_y_sizes;
  c2_loop_ub = c2_y_sizes - 1;
  for (c2_i54 = 0; c2_i54 <= c2_loop_ub; c2_i54++) {
    c2_outData_data[c2_i54] = c2_y_data[c2_i54];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_testKinectAll_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 5, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("disp"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("length"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1303178606U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("blanks"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i55;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i55, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i55;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_testKinectAllInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_testKinectAll, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_testKinectAll), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_testKinectAll);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_testKinectAllInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_testKinectAllInstanceStruct
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

void sf_c2_testKinectAll_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2833781300U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1191717244U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3823668296U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(439049740U);
}

mxArray *sf_c2_testKinectAll_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WlBWGcdYwsQhJO23s8pzaE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

mxArray *sf_c2_testKinectAll_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_testKinectAll_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_testKinectAll(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"arrSBM\",},{M[8],M[0],T\"is_active_c2_testKinectAll\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_testKinectAll_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_testKinectAllInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_testKinectAllInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testKinectAllMachineNumber_,
           2,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testKinectAllMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testKinectAllMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testKinectAllMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"tagID");
          _SFD_SET_DATA_PROPS(1,1,1,0,"w");
          _SFD_SET_DATA_PROPS(2,2,0,1,"arrSBM");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x");
          _SFD_SET_DATA_PROPS(4,1,1,0,"y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"z");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2457);
        _SFD_CV_INIT_EML_IF(0,1,0,2070,2090,2350,2430);

        {
          static int caseStart[] = { 1969, 584, 938 };

          static int caseExprEnd[] = { 1978, 590, 945 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,219,232,2054,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_tagID;
          real_T *c2_w;
          real_T *c2_x;
          real_T *c2_y;
          real_T *c2_z;
          real_T (*c2_arrSBM)[256];
          c2_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_arrSBM = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_tagID = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_tagID);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_w);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_arrSBM);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_x);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_z);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testKinectAllMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "GksZeWnW3O9sQCMYfIY6sD";
}

static void sf_opaque_initialize_c2_testKinectAll(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_testKinectAllInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*)
    chartInstanceVar);
  initialize_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_testKinectAll(void *chartInstanceVar)
{
  enable_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_testKinectAll(void *chartInstanceVar)
{
  disable_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_testKinectAll(void *chartInstanceVar)
{
  sf_gateway_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_testKinectAll(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_testKinectAll
    ((SFc2_testKinectAllInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_testKinectAll();/* state var info */
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

extern void sf_internal_set_sim_state_c2_testKinectAll(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_testKinectAll();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_testKinectAll(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_testKinectAll(S);
}

static void sf_opaque_set_sim_state_c2_testKinectAll(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_testKinectAll(S, st);
}

static void sf_opaque_terminate_c2_testKinectAll(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_testKinectAllInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testKinectAll_optimization_info();
    }

    finalize_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*)
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
  initSimStructsc2_testKinectAll((SFc2_testKinectAllInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_testKinectAll(SimStruct *S)
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
    initialize_params_c2_testKinectAll((SFc2_testKinectAllInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_testKinectAll(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testKinectAll_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4259498240U));
  ssSetChecksum1(S,(1193201417U));
  ssSetChecksum2(S,(1260815380U));
  ssSetChecksum3(S,(3948054813U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_testKinectAll(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_testKinectAll(SimStruct *S)
{
  SFc2_testKinectAllInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_testKinectAllInstanceStruct *)utMalloc(sizeof
    (SFc2_testKinectAllInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_testKinectAllInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_testKinectAll;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_testKinectAll;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_testKinectAll;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_testKinectAll;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_testKinectAll;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_testKinectAll;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_testKinectAll;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_testKinectAll;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_testKinectAll;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_testKinectAll;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_testKinectAll;
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

void c2_testKinectAll_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_testKinectAll(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_testKinectAll(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_testKinectAll(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_testKinectAll_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
