/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DemoGazeFollowWaveIdleRand_sfun.h"
#include "c6_DemoGazeFollowWaveIdleRand.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DemoGazeFollowWaveIdleRand_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "z", "y" };

/* Function Declarations */
static void initialize_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void initialize_params_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void enable_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void disable_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void set_sim_state_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_st);
static void finalize_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void sf_gateway_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void initSimStructsc6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *
  chartInstance, const mxArray *c6_y, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static boolean_T c6_c_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_b_is_active_c6_DemoGazeFollowWaveIdleRand, const char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_DemoGazeFollowWaveIdleRand = 0U;
}

static void initialize_params_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T *c6_d_y;
  c6_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  c6_hoistedGlobal = *c6_d_y;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = chartInstance->c6_is_active_c6_DemoGazeFollowWaveIdleRand;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_y;
  c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  *c6_y = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
    "y");
  chartInstance->c6_is_active_c6_DemoGazeFollowWaveIdleRand =
    c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
    "is_active_c6_DemoGazeFollowWaveIdleRand");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_DemoGazeFollowWaveIdleRand(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_z;
  uint32_T c6_debug_family_var_map[8];
  boolean_T c6_aVarTruthTableCondition_1;
  boolean_T c6_aVarTruthTableCondition_2;
  boolean_T c6_aVarTruthTableCondition_3;
  boolean_T c6_aVarTruthTableCondition_4;
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_y;
  boolean_T c6_b0;
  boolean_T c6_b1;
  real_T *c6_b_z;
  real_T *c6_b_y;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c6_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_b_z, 0U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_z;
  c6_z = c6_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_1, 0U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_2, 1U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_3, 2U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_4, 3U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 4U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 5U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_z, 6U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_y, 7U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
  c6_aVarTruthTableCondition_1 = (c6_z >= 220.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
  guard2 = false;
  if (c6_z < 150.0) {
    if (c6_z != 0.0) {
      c6_b0 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    c6_b0 = false;
  }

  c6_aVarTruthTableCondition_2 = c6_b0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 19);
  guard1 = false;
  if (c6_z >= 150.0) {
    if (c6_z < 220.0) {
      c6_b1 = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    c6_b1 = false;
  }

  c6_aVarTruthTableCondition_3 = c6_b1;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 23);
  c6_aVarTruthTableCondition_4 = (c6_z == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 25);
  if (CV_EML_IF(0, 1, 0, c6_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 26);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 41);
    c6_y = 2.0;
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -41);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 27);
    if (CV_EML_IF(0, 1, 1, c6_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 28);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 47);
      c6_y = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -47);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 29);
      if (CV_EML_IF(0, 1, 2, c6_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 30);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 53);
        c6_y = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -53);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 31);
        if (CV_EML_IF(0, 1, 3, c6_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 32);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 59);
          c6_y = 3.0;
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -59);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 34);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 59);
          c6_y = 3.0;
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -59);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  *c6_b_y = c6_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DemoGazeFollowWaveIdleRandMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c6_b_y, 1U);
}

static void initSimStructsc6_DemoGazeFollowWaveIdleRand
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *
  chartInstance, const mxArray *c6_y, const char_T *c6_identifier)
{
  real_T c6_b_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_y), &c6_thisId);
  sf_mex_destroy(&c6_y);
  return c6_b_y;
}

static real_T c6_b_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_y;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_b_y;
  SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c6_y = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_y), &c6_thisId);
  sf_mex_destroy(&c6_y);
  *(real_T *)c6_outData = c6_b_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  boolean_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(boolean_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static boolean_T c6_c_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  boolean_T c6_y;
  boolean_T c6_b2;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_b2, 1, 11, 0U, 0, 0U, 0);
  c6_y = c6_b2;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_aVarTruthTableCondition_4;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  boolean_T c6_y;
  SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c6_aVarTruthTableCondition_4 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_aVarTruthTableCondition_4), &c6_thisId);
  sf_mex_destroy(&c6_aVarTruthTableCondition_4);
  *(boolean_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i0, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_b_is_active_c6_DemoGazeFollowWaveIdleRand, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_DemoGazeFollowWaveIdleRand), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_DemoGazeFollowWaveIdleRand);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn
  (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *
  chartInstance)
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

void sf_c6_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(426753847U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1581916049U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2744553432U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3937934175U);
}

mxArray *sf_c6_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void)
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

mxArray *sf_c6_DemoGazeFollowWaveIdleRand_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_DemoGazeFollowWaveIdleRand(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c6_DemoGazeFollowWaveIdleRand\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_DemoGazeFollowWaveIdleRand_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DemoGazeFollowWaveIdleRandMachineNumber_,
           6,
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
        init_script_number_translation(_DemoGazeFollowWaveIdleRandMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _DemoGazeFollowWaveIdleRandMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DemoGazeFollowWaveIdleRandMachineNumber_,
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
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_z;
          real_T *c6_y;
          c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_z);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DemoGazeFollowWaveIdleRandMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "BJJ23zA4DpRgbGLiJ1zNAB";
}

static void sf_opaque_initialize_c6_DemoGazeFollowWaveIdleRand(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*) chartInstanceVar);
  initialize_c6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_DemoGazeFollowWaveIdleRand(void
  *chartInstanceVar)
{
  enable_c6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_DemoGazeFollowWaveIdleRand(void
  *chartInstanceVar)
{
  disable_c6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_DemoGazeFollowWaveIdleRand(void
  *chartInstanceVar)
{
  sf_gateway_c6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_DemoGazeFollowWaveIdleRand
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_DemoGazeFollowWaveIdleRand();/* state var info */
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

extern void sf_internal_set_sim_state_c6_DemoGazeFollowWaveIdleRand(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c6_DemoGazeFollowWaveIdleRand();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_DemoGazeFollowWaveIdleRand
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c6_DemoGazeFollowWaveIdleRand(S);
}

static void sf_opaque_set_sim_state_c6_DemoGazeFollowWaveIdleRand(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c6_DemoGazeFollowWaveIdleRand(S, st);
}

static void sf_opaque_terminate_c6_DemoGazeFollowWaveIdleRand(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DemoGazeFollowWaveIdleRand_optimization_info();
    }

    finalize_c6_DemoGazeFollowWaveIdleRand
      ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_DemoGazeFollowWaveIdleRand
    ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_DemoGazeFollowWaveIdleRand(SimStruct *S)
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
    initialize_params_c6_DemoGazeFollowWaveIdleRand
      ((SFc6_DemoGazeFollowWaveIdleRandInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_DemoGazeFollowWaveIdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DemoGazeFollowWaveIdleRand_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
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

static void mdlRTW_c6_DemoGazeFollowWaveIdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c6_DemoGazeFollowWaveIdleRand(SimStruct *S)
{
  SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_DemoGazeFollowWaveIdleRandInstanceStruct *)utMalloc
    (sizeof(SFc6_DemoGazeFollowWaveIdleRandInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_DemoGazeFollowWaveIdleRandInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_DemoGazeFollowWaveIdleRand;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_DemoGazeFollowWaveIdleRand;
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

void c6_DemoGazeFollowWaveIdleRand_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_DemoGazeFollowWaveIdleRand(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_DemoGazeFollowWaveIdleRand(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_DemoGazeFollowWaveIdleRand(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_DemoGazeFollowWaveIdleRand_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
