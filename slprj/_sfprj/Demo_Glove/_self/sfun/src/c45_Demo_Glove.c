/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_Glove_sfun.h"
#include "c45_Demo_Glove.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_Glove_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c45_debug_family_names[9] = { "nargin", "nargout", "r1",
  "r2", "r3", "r4", "r5", "r6", "y" };

/* Function Declarations */
static void initialize_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance);
static void initialize_params_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance);
static void enable_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct *chartInstance);
static void disable_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct *chartInstance);
static void c45_update_debugger_state_c45_Demo_Glove
  (SFc45_Demo_GloveInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c45_Demo_Glove
  (SFc45_Demo_GloveInstanceStruct *chartInstance);
static void set_sim_state_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_st);
static void finalize_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance);
static void sf_gateway_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance);
static void initSimStructsc45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber);
static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static void c45_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct *chartInstance,
  const mxArray *c45_y, const char_T *c45_identifier, real_T c45_b_y[6]);
static void c45_b_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct *chartInstance,
  const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId, real_T c45_y[6]);
static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static real_T c45_c_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static void c45_info_helper(const mxArray **c45_info);
static const mxArray *c45_emlrt_marshallOut(const char * c45_u);
static const mxArray *c45_b_emlrt_marshallOut(const uint32_T c45_u);
static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static int32_T c45_d_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static uint8_T c45_e_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_b_is_active_c45_Demo_Glove, const char_T
  *c45_identifier);
static uint8_T c45_f_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void init_dsm_address_info(SFc45_Demo_GloveInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance)
{
  chartInstance->c45_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c45_is_active_c45_Demo_Glove = 0U;
}

static void initialize_params_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c45_update_debugger_state_c45_Demo_Glove
  (SFc45_Demo_GloveInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c45_Demo_Glove
  (SFc45_Demo_GloveInstanceStruct *chartInstance)
{
  const mxArray *c45_st;
  const mxArray *c45_y = NULL;
  int32_T c45_i0;
  real_T c45_u[6];
  const mxArray *c45_b_y = NULL;
  uint8_T c45_hoistedGlobal;
  uint8_T c45_b_u;
  const mxArray *c45_c_y = NULL;
  real_T (*c45_d_y)[6];
  c45_d_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c45_st = NULL;
  c45_st = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_createcellmatrix(2, 1), false);
  for (c45_i0 = 0; c45_i0 < 6; c45_i0++) {
    c45_u[c45_i0] = (*c45_d_y)[c45_i0];
  }

  c45_b_y = NULL;
  sf_mex_assign(&c45_b_y, sf_mex_create("y", c45_u, 0, 0U, 1U, 0U, 2, 1, 6),
                false);
  sf_mex_setcell(c45_y, 0, c45_b_y);
  c45_hoistedGlobal = chartInstance->c45_is_active_c45_Demo_Glove;
  c45_b_u = c45_hoistedGlobal;
  c45_c_y = NULL;
  sf_mex_assign(&c45_c_y, sf_mex_create("y", &c45_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 1, c45_c_y);
  sf_mex_assign(&c45_st, c45_y, false);
  return c45_st;
}

static void set_sim_state_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_st)
{
  const mxArray *c45_u;
  real_T c45_dv0[6];
  int32_T c45_i1;
  real_T (*c45_y)[6];
  c45_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c45_doneDoubleBufferReInit = true;
  c45_u = sf_mex_dup(c45_st);
  c45_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 0)), "y",
                       c45_dv0);
  for (c45_i1 = 0; c45_i1 < 6; c45_i1++) {
    (*c45_y)[c45_i1] = c45_dv0[c45_i1];
  }

  chartInstance->c45_is_active_c45_Demo_Glove = c45_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 1)),
     "is_active_c45_Demo_Glove");
  sf_mex_destroy(&c45_u);
  c45_update_debugger_state_c45_Demo_Glove(chartInstance);
  sf_mex_destroy(&c45_st);
}

static void finalize_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance)
{
  real_T c45_hoistedGlobal;
  real_T c45_b_hoistedGlobal;
  real_T c45_c_hoistedGlobal;
  real_T c45_d_hoistedGlobal;
  real_T c45_e_hoistedGlobal;
  real_T c45_f_hoistedGlobal;
  real_T c45_r1;
  real_T c45_r2;
  real_T c45_r3;
  real_T c45_r4;
  real_T c45_r5;
  real_T c45_r6;
  uint32_T c45_debug_family_var_map[9];
  real_T c45_nargin = 6.0;
  real_T c45_nargout = 1.0;
  real_T c45_y[6];
  int32_T c45_i2;
  real_T c45_x;
  real_T c45_b_x;
  real_T c45_c_x;
  real_T c45_d_x;
  real_T c45_e_x;
  real_T c45_f_x;
  real_T c45_g_x;
  real_T c45_h_x;
  real_T c45_i_x;
  real_T c45_j_x;
  real_T c45_k_x;
  real_T c45_l_x;
  int32_T c45_i3;
  int32_T c45_i4;
  real_T *c45_b_r1;
  real_T *c45_b_r2;
  real_T *c45_b_r3;
  real_T *c45_b_r4;
  real_T *c45_b_r5;
  real_T *c45_b_r6;
  real_T (*c45_b_y)[6];
  c45_b_r6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c45_b_r5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c45_b_r4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c45_b_r3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c45_b_r2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c45_b_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c45_b_r1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c45_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c45_b_r1, 0U);
  chartInstance->c45_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c45_sfEvent);
  c45_hoistedGlobal = *c45_b_r1;
  c45_b_hoistedGlobal = *c45_b_r2;
  c45_c_hoistedGlobal = *c45_b_r3;
  c45_d_hoistedGlobal = *c45_b_r4;
  c45_e_hoistedGlobal = *c45_b_r5;
  c45_f_hoistedGlobal = *c45_b_r6;
  c45_r1 = c45_hoistedGlobal;
  c45_r2 = c45_b_hoistedGlobal;
  c45_r3 = c45_c_hoistedGlobal;
  c45_r4 = c45_d_hoistedGlobal;
  c45_r5 = c45_e_hoistedGlobal;
  c45_r6 = c45_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c45_debug_family_names,
    c45_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargin, 0U, c45_b_sf_marshallOut,
    c45_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargout, 1U, c45_b_sf_marshallOut,
    c45_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c45_r1, 2U, c45_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c45_r2, 3U, c45_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c45_r3, 4U, c45_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c45_r4, 5U, c45_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c45_r5, 6U, c45_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c45_r6, 7U, c45_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_y, 8U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 3);
  for (c45_i2 = 0; c45_i2 < 6; c45_i2++) {
    c45_y[c45_i2] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 4);
  c45_x = c45_r1;
  c45_b_x = c45_x;
  c45_b_x = muDoubleScalarFloor(c45_b_x);
  c45_y[0] = c45_b_x;
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 5);
  c45_c_x = c45_r2;
  c45_d_x = c45_c_x;
  c45_d_x = muDoubleScalarFloor(c45_d_x);
  c45_y[1] = c45_d_x;
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 6);
  c45_e_x = c45_r3;
  c45_f_x = c45_e_x;
  c45_f_x = muDoubleScalarFloor(c45_f_x);
  c45_y[2] = c45_f_x;
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 7);
  c45_g_x = c45_r4;
  c45_h_x = c45_g_x;
  c45_h_x = muDoubleScalarFloor(c45_h_x);
  c45_y[3] = c45_h_x;
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 8);
  c45_i_x = c45_r5;
  c45_j_x = c45_i_x;
  c45_j_x = muDoubleScalarFloor(c45_j_x);
  c45_y[4] = c45_j_x;
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 9);
  c45_k_x = c45_r6;
  c45_l_x = c45_k_x;
  c45_l_x = muDoubleScalarFloor(c45_l_x);
  c45_y[5] = c45_l_x;
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  for (c45_i3 = 0; c45_i3 < 6; c45_i3++) {
    (*c45_b_y)[c45_i3] = c45_y[c45_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c45_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_GloveMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c45_i4 = 0; c45_i4 < 6; c45_i4++) {
    _SFD_DATA_RANGE_CHECK((*c45_b_y)[c45_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c45_b_r2, 2U);
  _SFD_DATA_RANGE_CHECK(*c45_b_r3, 3U);
  _SFD_DATA_RANGE_CHECK(*c45_b_r4, 4U);
  _SFD_DATA_RANGE_CHECK(*c45_b_r5, 5U);
  _SFD_DATA_RANGE_CHECK(*c45_b_r6, 6U);
}

static void initSimStructsc45_Demo_Glove(SFc45_Demo_GloveInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber)
{
  (void)c45_machineNumber;
  (void)c45_chartNumber;
  (void)c45_instanceNumber;
}

static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_i5;
  real_T c45_b_inData[6];
  int32_T c45_i6;
  real_T c45_u[6];
  const mxArray *c45_y = NULL;
  SFc45_Demo_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc45_Demo_GloveInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  for (c45_i5 = 0; c45_i5 < 6; c45_i5++) {
    c45_b_inData[c45_i5] = (*(real_T (*)[6])c45_inData)[c45_i5];
  }

  for (c45_i6 = 0; c45_i6 < 6; c45_i6++) {
    c45_u[c45_i6] = c45_b_inData[c45_i6];
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static void c45_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct *chartInstance,
  const mxArray *c45_y, const char_T *c45_identifier, real_T c45_b_y[6])
{
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_y), &c45_thisId, c45_b_y);
  sf_mex_destroy(&c45_y);
}

static void c45_b_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct *chartInstance,
  const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId, real_T c45_y[6])
{
  real_T c45_dv1[6];
  int32_T c45_i7;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), c45_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c45_i7 = 0; c45_i7 < 6; c45_i7++) {
    c45_y[c45_i7] = c45_dv1[c45_i7];
  }

  sf_mex_destroy(&c45_u);
}

static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_y;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  real_T c45_b_y[6];
  int32_T c45_i8;
  SFc45_Demo_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc45_Demo_GloveInstanceStruct *)chartInstanceVoid;
  c45_y = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_y), &c45_thisId, c45_b_y);
  sf_mex_destroy(&c45_y);
  for (c45_i8 = 0; c45_i8 < 6; c45_i8++) {
    (*(real_T (*)[6])c45_outData)[c45_i8] = c45_b_y[c45_i8];
  }

  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  real_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Demo_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc45_Demo_GloveInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(real_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static real_T c45_c_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  real_T c45_y;
  real_T c45_d0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_d0, 1, 0, 0U, 0, 0U, 0);
  c45_y = c45_d0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_nargout;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  real_T c45_y;
  SFc45_Demo_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc45_Demo_GloveInstanceStruct *)chartInstanceVoid;
  c45_nargout = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_nargout),
    &c45_thisId);
  sf_mex_destroy(&c45_nargout);
  *(real_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

const mxArray *sf_c45_Demo_Glove_get_eml_resolved_functions_info(void)
{
  const mxArray *c45_nameCaptureInfo = NULL;
  c45_nameCaptureInfo = NULL;
  sf_mex_assign(&c45_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c45_info_helper(&c45_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c45_nameCaptureInfo);
  return c45_nameCaptureInfo;
}

static void c45_info_helper(const mxArray **c45_info)
{
  const mxArray *c45_rhs0 = NULL;
  const mxArray *c45_lhs0 = NULL;
  const mxArray *c45_rhs1 = NULL;
  const mxArray *c45_lhs1 = NULL;
  const mxArray *c45_rhs2 = NULL;
  const mxArray *c45_lhs2 = NULL;
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("floor"), "name", "name", 0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c45_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c45_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c45_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c45_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 2);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c45_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c45_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c45_rhs0);
  sf_mex_destroy(&c45_lhs0);
  sf_mex_destroy(&c45_rhs1);
  sf_mex_destroy(&c45_lhs1);
  sf_mex_destroy(&c45_rhs2);
  sf_mex_destroy(&c45_lhs2);
}

static const mxArray *c45_emlrt_marshallOut(const char * c45_u)
{
  const mxArray *c45_y = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c45_u)), false);
  return c45_y;
}

static const mxArray *c45_b_emlrt_marshallOut(const uint32_T c45_u)
{
  const mxArray *c45_y = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 7, 0U, 0U, 0U, 0), false);
  return c45_y;
}

static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Demo_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc45_Demo_GloveInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(int32_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static int32_T c45_d_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  int32_T c45_y;
  int32_T c45_i9;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_i9, 1, 6, 0U, 0, 0U, 0);
  c45_y = c45_i9;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_sfEvent;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y;
  SFc45_Demo_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc45_Demo_GloveInstanceStruct *)chartInstanceVoid;
  c45_b_sfEvent = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_sfEvent),
    &c45_thisId);
  sf_mex_destroy(&c45_b_sfEvent);
  *(int32_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static uint8_T c45_e_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_b_is_active_c45_Demo_Glove, const char_T
  *c45_identifier)
{
  uint8_T c45_y;
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_is_active_c45_Demo_Glove), &c45_thisId);
  sf_mex_destroy(&c45_b_is_active_c45_Demo_Glove);
  return c45_y;
}

static uint8_T c45_f_emlrt_marshallIn(SFc45_Demo_GloveInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  uint8_T c45_y;
  uint8_T c45_u0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_u0, 1, 3, 0U, 0, 0U, 0);
  c45_y = c45_u0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void init_dsm_address_info(SFc45_Demo_GloveInstanceStruct *chartInstance)
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

void sf_c45_Demo_Glove_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(801054891U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3825483126U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4092966389U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1472407491U);
}

mxArray *sf_c45_Demo_Glove_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PBOOE2ONCJlr45MWsYJj7G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[1] = (double)(6);
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

mxArray *sf_c45_Demo_Glove_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c45_Demo_Glove_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c45_Demo_Glove(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c45_Demo_Glove\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c45_Demo_Glove_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc45_Demo_GloveInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc45_Demo_GloveInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_GloveMachineNumber_,
           45,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_GloveMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_GloveMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_GloveMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,184);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)
            c45_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c45_r1;
          real_T *c45_r2;
          real_T *c45_r3;
          real_T *c45_r4;
          real_T *c45_r5;
          real_T *c45_r6;
          real_T (*c45_y)[6];
          c45_r6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c45_r5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c45_r4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c45_r3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c45_r2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c45_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c45_r1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c45_r1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c45_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c45_r2);
          _SFD_SET_DATA_VALUE_PTR(3U, c45_r3);
          _SFD_SET_DATA_VALUE_PTR(4U, c45_r4);
          _SFD_SET_DATA_VALUE_PTR(5U, c45_r5);
          _SFD_SET_DATA_VALUE_PTR(6U, c45_r6);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_GloveMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "TYRfK1GKG3nJxBPOVXmiwG";
}

static void sf_opaque_initialize_c45_Demo_Glove(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc45_Demo_GloveInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*)
    chartInstanceVar);
  initialize_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c45_Demo_Glove(void *chartInstanceVar)
{
  enable_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c45_Demo_Glove(void *chartInstanceVar)
{
  disable_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c45_Demo_Glove(void *chartInstanceVar)
{
  sf_gateway_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c45_Demo_Glove(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c45_Demo_Glove
    ((SFc45_Demo_GloveInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c45_Demo_Glove();/* state var info */
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

extern void sf_internal_set_sim_state_c45_Demo_Glove(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c45_Demo_Glove();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c45_Demo_Glove(SimStruct* S)
{
  return sf_internal_get_sim_state_c45_Demo_Glove(S);
}

static void sf_opaque_set_sim_state_c45_Demo_Glove(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c45_Demo_Glove(S, st);
}

static void sf_opaque_terminate_c45_Demo_Glove(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc45_Demo_GloveInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_Glove_optimization_info();
    }

    finalize_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c45_Demo_Glove(SimStruct *S)
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
    initialize_params_c45_Demo_Glove((SFc45_Demo_GloveInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c45_Demo_Glove(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_Glove_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      45);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,45,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,45,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,45);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,45,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,45,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,45);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(564390947U));
  ssSetChecksum1(S,(4114128404U));
  ssSetChecksum2(S,(2395737836U));
  ssSetChecksum3(S,(1148318102U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c45_Demo_Glove(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c45_Demo_Glove(SimStruct *S)
{
  SFc45_Demo_GloveInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc45_Demo_GloveInstanceStruct *)utMalloc(sizeof
    (SFc45_Demo_GloveInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc45_Demo_GloveInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c45_Demo_Glove;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c45_Demo_Glove;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c45_Demo_Glove;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c45_Demo_Glove;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c45_Demo_Glove;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c45_Demo_Glove;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c45_Demo_Glove;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c45_Demo_Glove;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c45_Demo_Glove;
  chartInstance->chartInfo.mdlStart = mdlStart_c45_Demo_Glove;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c45_Demo_Glove;
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

void c45_Demo_Glove_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c45_Demo_Glove(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c45_Demo_Glove(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c45_Demo_Glove(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c45_Demo_Glove_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
