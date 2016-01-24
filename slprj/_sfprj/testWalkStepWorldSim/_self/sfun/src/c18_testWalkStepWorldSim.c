/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testWalkStepWorldSim_sfun.h"
#include "c18_testWalkStepWorldSim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testWalkStepWorldSim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c18_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "z", "y" };

/* Function Declarations */
static void initialize_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void initialize_params_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void enable_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void disable_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void c18_update_debugger_state_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void set_sim_state_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance, const mxArray
   *c18_st);
static void finalize_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void sf_gateway_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void initSimStructsc18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_y, const char_T *c18_identifier);
static real_T c18_b_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static boolean_T c18_c_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_d_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_e_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_testWalkStepWorldSim, const
  char_T *c18_identifier);
static uint8_T c18_f_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_is_active_c18_testWalkStepWorldSim = 0U;
}

static void initialize_params_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c18_update_debugger_state_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  real_T c18_hoistedGlobal;
  real_T c18_u;
  const mxArray *c18_b_y = NULL;
  uint8_T c18_b_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  real_T *c18_d_y;
  c18_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellmatrix(2, 1), false);
  c18_hoistedGlobal = *c18_d_y;
  c18_u = c18_hoistedGlobal;
  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_b_hoistedGlobal = chartInstance->c18_is_active_c18_testWalkStepWorldSim;
  c18_b_u = c18_b_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y, false);
  return c18_st;
}

static void set_sim_state_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance, const mxArray
   *c18_st)
{
  const mxArray *c18_u;
  real_T *c18_y;
  c18_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c18_doneDoubleBufferReInit = true;
  c18_u = sf_mex_dup(c18_st);
  *c18_y = c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u,
    0)), "y");
  chartInstance->c18_is_active_c18_testWalkStepWorldSim = c18_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 1)),
     "is_active_c18_testWalkStepWorldSim");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_testWalkStepWorldSim(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  real_T c18_hoistedGlobal;
  real_T c18_z;
  uint32_T c18_debug_family_var_map[8];
  boolean_T c18_aVarTruthTableCondition_1;
  boolean_T c18_aVarTruthTableCondition_2;
  boolean_T c18_aVarTruthTableCondition_3;
  boolean_T c18_aVarTruthTableCondition_4;
  real_T c18_nargin = 1.0;
  real_T c18_nargout = 1.0;
  real_T c18_y;
  boolean_T c18_b0;
  boolean_T c18_b1;
  real_T *c18_b_z;
  real_T *c18_b_y;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c18_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c18_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c18_b_z, 0U);
  chartInstance->c18_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c18_sfEvent);
  c18_hoistedGlobal = *c18_b_z;
  c18_z = c18_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_aVarTruthTableCondition_1, 0U,
    c18_b_sf_marshallOut, c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_aVarTruthTableCondition_2, 1U,
    c18_b_sf_marshallOut, c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_aVarTruthTableCondition_3, 2U,
    c18_b_sf_marshallOut, c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_aVarTruthTableCondition_4, 3U,
    c18_b_sf_marshallOut, c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 4U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 5U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_z, 6U, c18_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_y, 7U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 3);
  c18_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 4);
  c18_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 5);
  c18_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 6);
  c18_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 11);
  c18_aVarTruthTableCondition_1 = (c18_z >= 220.0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 15);
  guard2 = false;
  if (c18_z < 150.0) {
    if (c18_z != 0.0) {
      c18_b0 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    c18_b0 = false;
  }

  c18_aVarTruthTableCondition_2 = c18_b0;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 19);
  guard1 = false;
  if (c18_z >= 150.0) {
    if (c18_z < 220.0) {
      c18_b1 = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    c18_b1 = false;
  }

  c18_aVarTruthTableCondition_3 = c18_b1;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 23);
  c18_aVarTruthTableCondition_4 = (c18_z == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 25);
  if (CV_EML_IF(0, 1, 0, c18_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 26);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 41);
    c18_y = 2.0;
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -41);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 27);
    if (CV_EML_IF(0, 1, 1, c18_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 28);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 47);
      c18_y = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -47);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 29);
      if (CV_EML_IF(0, 1, 2, c18_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 30);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 53);
        c18_y = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -53);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 31);
        if (CV_EML_IF(0, 1, 3, c18_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 32);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 59);
          c18_y = 3.0;
          _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -59);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 34);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 59);
          c18_y = 3.0;
          _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -59);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  *c18_b_y = c18_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c18_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testWalkStepWorldSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c18_b_y, 1U);
}

static void initSimStructsc18_testWalkStepWorldSim
  (SFc18_testWalkStepWorldSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber)
{
  (void)c18_machineNumber;
  (void)c18_chartNumber;
  (void)c18_instanceNumber;
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static real_T c18_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_y, const char_T *c18_identifier)
{
  real_T c18_b_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_y), &c18_thisId);
  sf_mex_destroy(&c18_y);
  return c18_b_y;
}

static real_T c18_b_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d0, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_y;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_b_y;
  SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)chartInstanceVoid;
  c18_y = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_y), &c18_thisId);
  sf_mex_destroy(&c18_y);
  *(real_T *)c18_outData = c18_b_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  boolean_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(boolean_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static boolean_T c18_c_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  boolean_T c18_y;
  boolean_T c18_b2;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_b2, 1, 11, 0U, 0, 0U, 0);
  c18_y = c18_b2;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_aVarTruthTableCondition_4;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  boolean_T c18_y;
  SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)chartInstanceVoid;
  c18_aVarTruthTableCondition_4 = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_aVarTruthTableCondition_4), &c18_thisId);
  sf_mex_destroy(&c18_aVarTruthTableCondition_4);
  *(boolean_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_testWalkStepWorldSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c18_nameCaptureInfo;
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static int32_T c18_d_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i0, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_e_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_testWalkStepWorldSim, const
  char_T *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_testWalkStepWorldSim), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_testWalkStepWorldSim);
  return c18_y;
}

static uint8_T c18_f_emlrt_marshallIn(SFc18_testWalkStepWorldSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info(SFc18_testWalkStepWorldSimInstanceStruct
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

void sf_c18_testWalkStepWorldSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(426753847U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1581916049U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2744553432U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3937934175U);
}

mxArray *sf_c18_testWalkStepWorldSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("q7zoKb2PYssm0FsycxJhm");
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c18_testWalkStepWorldSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_testWalkStepWorldSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c18_testWalkStepWorldSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c18_testWalkStepWorldSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_testWalkStepWorldSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testWalkStepWorldSimMachineNumber_,
           18,
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
        init_script_number_translation(_testWalkStepWorldSimMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testWalkStepWorldSimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testWalkStepWorldSimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"z");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,722);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",722,-1,776);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",776,-1,832);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",832,-1,890);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",890,-1,944);
        _SFD_CV_INIT_EML_IF(0,1,0,416,446,477,720);
        _SFD_CV_INIT_EML_IF(0,1,1,477,511,542,720);
        _SFD_CV_INIT_EML_IF(0,1,2,542,576,607,720);
        _SFD_CV_INIT_EML_IF(0,1,3,607,641,672,720);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)c18_sf_marshallIn);

        {
          real_T *c18_z;
          real_T *c18_y;
          c18_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c18_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c18_z);
          _SFD_SET_DATA_VALUE_PTR(1U, c18_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testWalkStepWorldSimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "BJJ23zA4DpRgbGLiJ1zNAB";
}

static void sf_opaque_initialize_c18_testWalkStepWorldSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_testWalkStepWorldSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c18_testWalkStepWorldSim
    ((SFc18_testWalkStepWorldSimInstanceStruct*) chartInstanceVar);
  initialize_c18_testWalkStepWorldSim((SFc18_testWalkStepWorldSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c18_testWalkStepWorldSim(void *chartInstanceVar)
{
  enable_c18_testWalkStepWorldSim((SFc18_testWalkStepWorldSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c18_testWalkStepWorldSim(void *chartInstanceVar)
{
  disable_c18_testWalkStepWorldSim((SFc18_testWalkStepWorldSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c18_testWalkStepWorldSim(void *chartInstanceVar)
{
  sf_gateway_c18_testWalkStepWorldSim((SFc18_testWalkStepWorldSimInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c18_testWalkStepWorldSim
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_testWalkStepWorldSim
    ((SFc18_testWalkStepWorldSimInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_testWalkStepWorldSim();/* state var info */
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

extern void sf_internal_set_sim_state_c18_testWalkStepWorldSim(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c18_testWalkStepWorldSim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_testWalkStepWorldSim
    ((SFc18_testWalkStepWorldSimInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c18_testWalkStepWorldSim(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c18_testWalkStepWorldSim(S);
}

static void sf_opaque_set_sim_state_c18_testWalkStepWorldSim(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c18_testWalkStepWorldSim(S, st);
}

static void sf_opaque_terminate_c18_testWalkStepWorldSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_testWalkStepWorldSimInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testWalkStepWorldSim_optimization_info();
    }

    finalize_c18_testWalkStepWorldSim((SFc18_testWalkStepWorldSimInstanceStruct*)
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
  initSimStructsc18_testWalkStepWorldSim
    ((SFc18_testWalkStepWorldSimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_testWalkStepWorldSim(SimStruct *S)
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
    initialize_params_c18_testWalkStepWorldSim
      ((SFc18_testWalkStepWorldSimInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_testWalkStepWorldSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testWalkStepWorldSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,18,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
    }

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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(508935511U));
  ssSetChecksum1(S,(3210139094U));
  ssSetChecksum2(S,(4048065566U));
  ssSetChecksum3(S,(674732350U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_testWalkStepWorldSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c18_testWalkStepWorldSim(SimStruct *S)
{
  SFc18_testWalkStepWorldSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc18_testWalkStepWorldSimInstanceStruct *)utMalloc(sizeof
    (SFc18_testWalkStepWorldSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_testWalkStepWorldSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_testWalkStepWorldSim;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c18_testWalkStepWorldSim;
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

void c18_testWalkStepWorldSim_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_testWalkStepWorldSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_testWalkStepWorldSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_testWalkStepWorldSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_testWalkStepWorldSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
