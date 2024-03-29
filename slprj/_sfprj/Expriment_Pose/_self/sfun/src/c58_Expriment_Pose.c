/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Pose_sfun.h"
#include "c58_Expriment_Pose.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_Pose_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c58_debug_family_names[11] = { "randTrigger", "nargin",
  "nargout", "randv", "smile", "wave", "win", "invade", "vaFlag", "v_trigW",
  "v_trig" };

/* Function Declarations */
static void initialize_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance);
static void initialize_params_c58_Expriment_Pose
  (SFc58_Expriment_PoseInstanceStruct *chartInstance);
static void enable_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance);
static void disable_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance);
static void c58_update_debugger_state_c58_Expriment_Pose
  (SFc58_Expriment_PoseInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c58_Expriment_Pose
  (SFc58_Expriment_PoseInstanceStruct *chartInstance);
static void set_sim_state_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c58_st);
static void finalize_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance);
static void sf_gateway_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance);
static void initSimStructsc58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c58_machineNumber, uint32_T
  c58_chartNumber, uint32_T c58_instanceNumber);
static const mxArray *c58_sf_marshallOut(void *chartInstanceVoid, void
  *c58_inData);
static real_T c58_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_v_trig, const char_T *c58_identifier);
static real_T c58_b_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_u, const emlrtMsgIdentifier *c58_parentId);
static void c58_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c58_mxArrayInData, const char_T *c58_varName, void *c58_outData);
static const mxArray *c58_b_sf_marshallOut(void *chartInstanceVoid, void
  *c58_inData);
static void c58_info_helper(const mxArray **c58_info);
static const mxArray *c58_emlrt_marshallOut(const char * c58_u);
static const mxArray *c58_b_emlrt_marshallOut(const uint32_T c58_u);
static const mxArray *c58_c_sf_marshallOut(void *chartInstanceVoid, void
  *c58_inData);
static int32_T c58_c_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_u, const emlrtMsgIdentifier *c58_parentId);
static void c58_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c58_mxArrayInData, const char_T *c58_varName, void *c58_outData);
static uint8_T c58_d_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_b_is_active_c58_Expriment_Pose, const
  char_T *c58_identifier);
static uint8_T c58_e_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_u, const emlrtMsgIdentifier *c58_parentId);
static void init_dsm_address_info(SFc58_Expriment_PoseInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance)
{
  chartInstance->c58_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c58_is_active_c58_Expriment_Pose = 0U;
}

static void initialize_params_c58_Expriment_Pose
  (SFc58_Expriment_PoseInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c58_update_debugger_state_c58_Expriment_Pose
  (SFc58_Expriment_PoseInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c58_Expriment_Pose
  (SFc58_Expriment_PoseInstanceStruct *chartInstance)
{
  const mxArray *c58_st;
  const mxArray *c58_y = NULL;
  real_T c58_hoistedGlobal;
  real_T c58_u;
  const mxArray *c58_b_y = NULL;
  real_T c58_b_hoistedGlobal;
  real_T c58_b_u;
  const mxArray *c58_c_y = NULL;
  uint8_T c58_c_hoistedGlobal;
  uint8_T c58_c_u;
  const mxArray *c58_d_y = NULL;
  real_T *c58_v_trig;
  real_T *c58_v_trigW;
  c58_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c58_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c58_st = NULL;
  c58_st = NULL;
  c58_y = NULL;
  sf_mex_assign(&c58_y, sf_mex_createcellmatrix(3, 1), false);
  c58_hoistedGlobal = *c58_v_trig;
  c58_u = c58_hoistedGlobal;
  c58_b_y = NULL;
  sf_mex_assign(&c58_b_y, sf_mex_create("y", &c58_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c58_y, 0, c58_b_y);
  c58_b_hoistedGlobal = *c58_v_trigW;
  c58_b_u = c58_b_hoistedGlobal;
  c58_c_y = NULL;
  sf_mex_assign(&c58_c_y, sf_mex_create("y", &c58_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c58_y, 1, c58_c_y);
  c58_c_hoistedGlobal = chartInstance->c58_is_active_c58_Expriment_Pose;
  c58_c_u = c58_c_hoistedGlobal;
  c58_d_y = NULL;
  sf_mex_assign(&c58_d_y, sf_mex_create("y", &c58_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c58_y, 2, c58_d_y);
  sf_mex_assign(&c58_st, c58_y, false);
  return c58_st;
}

static void set_sim_state_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c58_st)
{
  const mxArray *c58_u;
  real_T *c58_v_trig;
  real_T *c58_v_trigW;
  c58_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c58_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c58_doneDoubleBufferReInit = true;
  c58_u = sf_mex_dup(c58_st);
  *c58_v_trig = c58_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c58_u, 0)), "v_trig");
  *c58_v_trigW = c58_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c58_u, 1)), "v_trigW");
  chartInstance->c58_is_active_c58_Expriment_Pose = c58_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c58_u, 2)),
     "is_active_c58_Expriment_Pose");
  sf_mex_destroy(&c58_u);
  c58_update_debugger_state_c58_Expriment_Pose(chartInstance);
  sf_mex_destroy(&c58_st);
}

static void finalize_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct
  *chartInstance)
{
  real_T c58_hoistedGlobal;
  real_T c58_b_hoistedGlobal;
  real_T c58_c_hoistedGlobal;
  real_T c58_d_hoistedGlobal;
  real_T c58_e_hoistedGlobal;
  boolean_T c58_f_hoistedGlobal;
  real_T c58_randv;
  real_T c58_smile;
  real_T c58_wave;
  real_T c58_win;
  real_T c58_invade;
  boolean_T c58_vaFlag;
  uint32_T c58_debug_family_var_map[11];
  real_T c58_randTrigger;
  real_T c58_nargin = 6.0;
  real_T c58_nargout = 2.0;
  real_T c58_v_trigW;
  real_T c58_v_trig;
  real_T c58_x;
  real_T c58_b_x;
  real_T c58_c_x;
  real_T c58_d_x;
  real_T *c58_b_randv;
  real_T *c58_b_smile;
  real_T *c58_b_wave;
  real_T *c58_b_win;
  real_T *c58_b_invade;
  real_T *c58_b_v_trigW;
  boolean_T *c58_b_vaFlag;
  real_T *c58_b_v_trig;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c58_b_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c58_b_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c58_b_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c58_b_invade = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c58_b_win = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c58_b_wave = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c58_b_smile = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c58_b_randv = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 34U, chartInstance->c58_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c58_b_randv, 0U);
  _SFD_DATA_RANGE_CHECK(*c58_b_smile, 1U);
  _SFD_DATA_RANGE_CHECK(*c58_b_wave, 2U);
  _SFD_DATA_RANGE_CHECK(*c58_b_win, 3U);
  _SFD_DATA_RANGE_CHECK(*c58_b_invade, 4U);
  chartInstance->c58_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 34U, chartInstance->c58_sfEvent);
  c58_hoistedGlobal = *c58_b_randv;
  c58_b_hoistedGlobal = *c58_b_smile;
  c58_c_hoistedGlobal = *c58_b_wave;
  c58_d_hoistedGlobal = *c58_b_win;
  c58_e_hoistedGlobal = *c58_b_invade;
  c58_f_hoistedGlobal = *c58_b_vaFlag;
  c58_randv = c58_hoistedGlobal;
  c58_smile = c58_b_hoistedGlobal;
  c58_wave = c58_c_hoistedGlobal;
  c58_win = c58_d_hoistedGlobal;
  c58_invade = c58_e_hoistedGlobal;
  c58_vaFlag = c58_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c58_debug_family_names,
    c58_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c58_randTrigger, 0U, c58_sf_marshallOut,
    c58_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c58_nargin, 1U, c58_sf_marshallOut,
    c58_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c58_nargout, 2U, c58_sf_marshallOut,
    c58_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c58_randv, 3U, c58_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c58_smile, 4U, c58_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c58_wave, 5U, c58_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c58_win, 6U, c58_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c58_invade, 7U, c58_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c58_vaFlag, 8U, c58_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c58_v_trigW, 9U, c58_sf_marshallOut,
    c58_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c58_v_trig, 10U, c58_sf_marshallOut,
    c58_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 8);
  if (CV_EML_IF(0, 1, 0, (real_T)c58_vaFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 9);
    c58_v_trigW = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 11);
    c58_x = c58_randv;
    c58_randTrigger = c58_x;
    c58_b_x = c58_randTrigger;
    c58_randTrigger = c58_b_x;
    c58_randTrigger = muDoubleScalarFloor(c58_randTrigger);
    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 12);
    guard2 = false;
    if (CV_EML_COND(0, 1, 0, 0.0 < c58_randTrigger)) {
      if (CV_EML_COND(0, 1, 1, c58_randTrigger < 30.0)) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 1, true);
        _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 13);
        c58_v_trigW += 0.6;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 1, false);
    }

    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 15);
    guard1 = false;
    if (CV_EML_COND(0, 1, 2, 30.0 < c58_randTrigger)) {
      if (CV_EML_COND(0, 1, 3, c58_randTrigger < 60.0)) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 2, true);
        _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 16);
        c58_v_trigW -= 0.6;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 2, false);
    }

    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 19);
    if (CV_EML_IF(0, 1, 3, c58_win == 2.0)) {
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 20);
      c58_v_trigW += 0.5;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 21);
      if (CV_EML_IF(0, 1, 4, c58_win == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 22);
        c58_v_trigW -= 0.5;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 25);
    if (CV_EML_IF(0, 1, 5, c58_smile == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 26);
      c58_v_trigW += 0.25;
    }

    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 29);
    if (CV_EML_IF(0, 1, 6, c58_wave == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 30);
      c58_v_trigW += 0.25;
    }

    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 33);
    if (CV_EML_IF(0, 1, 7, c58_invade == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 34);
      c58_v_trigW -= 0.25;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 37);
    c58_v_trigW = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 39);
  if (CV_EML_IF(0, 1, 8, c58_v_trigW > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 40);
    c58_v_trig = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 41);
    if (CV_EML_IF(0, 1, 9, c58_v_trigW < 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 42);
      c58_v_trig = -1.0;
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 43);
      c58_c_x = c58_v_trigW;
      c58_d_x = c58_c_x;
      c58_v_trigW = muDoubleScalarAbs(c58_d_x);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, 45);
      c58_v_trig = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c58_sfEvent, -45);
  _SFD_SYMBOL_SCOPE_POP();
  *c58_b_v_trigW = c58_v_trigW;
  *c58_b_v_trig = c58_v_trig;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c58_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_PoseMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c58_b_v_trigW, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c58_b_vaFlag, 6U);
  _SFD_DATA_RANGE_CHECK(*c58_b_v_trig, 7U);
}

static void initSimStructsc58_Expriment_Pose(SFc58_Expriment_PoseInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c58_machineNumber, uint32_T
  c58_chartNumber, uint32_T c58_instanceNumber)
{
  (void)c58_machineNumber;
  (void)c58_chartNumber;
  (void)c58_instanceNumber;
}

static const mxArray *c58_sf_marshallOut(void *chartInstanceVoid, void
  *c58_inData)
{
  const mxArray *c58_mxArrayOutData = NULL;
  real_T c58_u;
  const mxArray *c58_y = NULL;
  SFc58_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc58_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c58_mxArrayOutData = NULL;
  c58_u = *(real_T *)c58_inData;
  c58_y = NULL;
  sf_mex_assign(&c58_y, sf_mex_create("y", &c58_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c58_mxArrayOutData, c58_y, false);
  return c58_mxArrayOutData;
}

static real_T c58_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_v_trig, const char_T *c58_identifier)
{
  real_T c58_y;
  emlrtMsgIdentifier c58_thisId;
  c58_thisId.fIdentifier = c58_identifier;
  c58_thisId.fParent = NULL;
  c58_y = c58_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c58_v_trig),
    &c58_thisId);
  sf_mex_destroy(&c58_v_trig);
  return c58_y;
}

static real_T c58_b_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_u, const emlrtMsgIdentifier *c58_parentId)
{
  real_T c58_y;
  real_T c58_d0;
  (void)chartInstance;
  sf_mex_import(c58_parentId, sf_mex_dup(c58_u), &c58_d0, 1, 0, 0U, 0, 0U, 0);
  c58_y = c58_d0;
  sf_mex_destroy(&c58_u);
  return c58_y;
}

static void c58_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c58_mxArrayInData, const char_T *c58_varName, void *c58_outData)
{
  const mxArray *c58_v_trig;
  const char_T *c58_identifier;
  emlrtMsgIdentifier c58_thisId;
  real_T c58_y;
  SFc58_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc58_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c58_v_trig = sf_mex_dup(c58_mxArrayInData);
  c58_identifier = c58_varName;
  c58_thisId.fIdentifier = c58_identifier;
  c58_thisId.fParent = NULL;
  c58_y = c58_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c58_v_trig),
    &c58_thisId);
  sf_mex_destroy(&c58_v_trig);
  *(real_T *)c58_outData = c58_y;
  sf_mex_destroy(&c58_mxArrayInData);
}

static const mxArray *c58_b_sf_marshallOut(void *chartInstanceVoid, void
  *c58_inData)
{
  const mxArray *c58_mxArrayOutData = NULL;
  boolean_T c58_u;
  const mxArray *c58_y = NULL;
  SFc58_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc58_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c58_mxArrayOutData = NULL;
  c58_u = *(boolean_T *)c58_inData;
  c58_y = NULL;
  sf_mex_assign(&c58_y, sf_mex_create("y", &c58_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c58_mxArrayOutData, c58_y, false);
  return c58_mxArrayOutData;
}

const mxArray *sf_c58_Expriment_Pose_get_eml_resolved_functions_info(void)
{
  const mxArray *c58_nameCaptureInfo = NULL;
  c58_nameCaptureInfo = NULL;
  sf_mex_assign(&c58_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
                false);
  c58_info_helper(&c58_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c58_nameCaptureInfo);
  return c58_nameCaptureInfo;
}

static void c58_info_helper(const mxArray **c58_info)
{
  const mxArray *c58_rhs0 = NULL;
  const mxArray *c58_lhs0 = NULL;
  const mxArray *c58_rhs1 = NULL;
  const mxArray *c58_lhs1 = NULL;
  const mxArray *c58_rhs2 = NULL;
  const mxArray *c58_lhs2 = NULL;
  const mxArray *c58_rhs3 = NULL;
  const mxArray *c58_lhs3 = NULL;
  const mxArray *c58_rhs4 = NULL;
  const mxArray *c58_lhs4 = NULL;
  const mxArray *c58_rhs5 = NULL;
  const mxArray *c58_lhs5 = NULL;
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("floor"), "name", "name", 0);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c58_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c58_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c58_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c58_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 2);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c58_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c58_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("abs"), "name", "name", 3);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c58_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c58_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c58_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c58_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 5);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c58_info, c58_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c58_info, c58_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c58_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c58_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c58_info, sf_mex_duplicatearraysafe(&c58_lhs5), "lhs", "lhs",
                  5);
  sf_mex_destroy(&c58_rhs0);
  sf_mex_destroy(&c58_lhs0);
  sf_mex_destroy(&c58_rhs1);
  sf_mex_destroy(&c58_lhs1);
  sf_mex_destroy(&c58_rhs2);
  sf_mex_destroy(&c58_lhs2);
  sf_mex_destroy(&c58_rhs3);
  sf_mex_destroy(&c58_lhs3);
  sf_mex_destroy(&c58_rhs4);
  sf_mex_destroy(&c58_lhs4);
  sf_mex_destroy(&c58_rhs5);
  sf_mex_destroy(&c58_lhs5);
}

static const mxArray *c58_emlrt_marshallOut(const char * c58_u)
{
  const mxArray *c58_y = NULL;
  c58_y = NULL;
  sf_mex_assign(&c58_y, sf_mex_create("y", c58_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c58_u)), false);
  return c58_y;
}

static const mxArray *c58_b_emlrt_marshallOut(const uint32_T c58_u)
{
  const mxArray *c58_y = NULL;
  c58_y = NULL;
  sf_mex_assign(&c58_y, sf_mex_create("y", &c58_u, 7, 0U, 0U, 0U, 0), false);
  return c58_y;
}

static const mxArray *c58_c_sf_marshallOut(void *chartInstanceVoid, void
  *c58_inData)
{
  const mxArray *c58_mxArrayOutData = NULL;
  int32_T c58_u;
  const mxArray *c58_y = NULL;
  SFc58_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc58_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c58_mxArrayOutData = NULL;
  c58_u = *(int32_T *)c58_inData;
  c58_y = NULL;
  sf_mex_assign(&c58_y, sf_mex_create("y", &c58_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c58_mxArrayOutData, c58_y, false);
  return c58_mxArrayOutData;
}

static int32_T c58_c_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_u, const emlrtMsgIdentifier *c58_parentId)
{
  int32_T c58_y;
  int32_T c58_i0;
  (void)chartInstance;
  sf_mex_import(c58_parentId, sf_mex_dup(c58_u), &c58_i0, 1, 6, 0U, 0, 0U, 0);
  c58_y = c58_i0;
  sf_mex_destroy(&c58_u);
  return c58_y;
}

static void c58_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c58_mxArrayInData, const char_T *c58_varName, void *c58_outData)
{
  const mxArray *c58_b_sfEvent;
  const char_T *c58_identifier;
  emlrtMsgIdentifier c58_thisId;
  int32_T c58_y;
  SFc58_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc58_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c58_b_sfEvent = sf_mex_dup(c58_mxArrayInData);
  c58_identifier = c58_varName;
  c58_thisId.fIdentifier = c58_identifier;
  c58_thisId.fParent = NULL;
  c58_y = c58_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c58_b_sfEvent),
    &c58_thisId);
  sf_mex_destroy(&c58_b_sfEvent);
  *(int32_T *)c58_outData = c58_y;
  sf_mex_destroy(&c58_mxArrayInData);
}

static uint8_T c58_d_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_b_is_active_c58_Expriment_Pose, const
  char_T *c58_identifier)
{
  uint8_T c58_y;
  emlrtMsgIdentifier c58_thisId;
  c58_thisId.fIdentifier = c58_identifier;
  c58_thisId.fParent = NULL;
  c58_y = c58_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c58_b_is_active_c58_Expriment_Pose), &c58_thisId);
  sf_mex_destroy(&c58_b_is_active_c58_Expriment_Pose);
  return c58_y;
}

static uint8_T c58_e_emlrt_marshallIn(SFc58_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c58_u, const emlrtMsgIdentifier *c58_parentId)
{
  uint8_T c58_y;
  uint8_T c58_u0;
  (void)chartInstance;
  sf_mex_import(c58_parentId, sf_mex_dup(c58_u), &c58_u0, 1, 3, 0U, 0, 0U, 0);
  c58_y = c58_u0;
  sf_mex_destroy(&c58_u);
  return c58_y;
}

static void init_dsm_address_info(SFc58_Expriment_PoseInstanceStruct
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

void sf_c58_Expriment_Pose_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2899336697U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2529092174U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3569392863U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1566489486U);
}

mxArray *sf_c58_Expriment_Pose_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("S954SW2RZeFUPsEwVaqQHC");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c58_Expriment_Pose_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c58_Expriment_Pose_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c58_Expriment_Pose(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[14],T\"v_trig\",},{M[1],M[11],T\"v_trigW\",},{M[8],M[0],T\"is_active_c58_Expriment_Pose\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c58_Expriment_Pose_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc58_Expriment_PoseInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc58_Expriment_PoseInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_PoseMachineNumber_,
           58,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_PoseMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_PoseMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_PoseMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"randv");
          _SFD_SET_DATA_PROPS(1,1,1,0,"smile");
          _SFD_SET_DATA_PROPS(2,1,1,0,"wave");
          _SFD_SET_DATA_PROPS(3,1,1,0,"win");
          _SFD_SET_DATA_PROPS(4,1,1,0,"invade");
          _SFD_SET_DATA_PROPS(5,2,0,1,"v_trigW");
          _SFD_SET_DATA_PROPS(6,1,1,0,"vaFlag");
          _SFD_SET_DATA_PROPS(7,2,0,1,"v_trig");
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
        _SFD_CV_INIT_EML(0,1,1,10,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1322);
        _SFD_CV_INIT_EML_IF(0,1,0,346,359,1147,1179);
        _SFD_CV_INIT_EML_IF(0,1,1,562,597,-1,646);
        _SFD_CV_INIT_EML_IF(0,1,2,655,691,-1,740);
        _SFD_CV_INIT_EML_IF(0,1,3,750,760,838,852);
        _SFD_CV_INIT_EML_IF(0,1,4,838,852,-1,852);
        _SFD_CV_INIT_EML_IF(0,1,5,948,960,-1,1006);
        _SFD_CV_INIT_EML_IF(0,1,6,1016,1027,-1,1073);
        _SFD_CV_INIT_EML_IF(0,1,7,1083,1096,-1,1142);
        _SFD_CV_INIT_EML_IF(0,1,8,1184,1197,1220,1321);
        _SFD_CV_INIT_EML_IF(0,1,9,1220,1237,1291,1321);

        {
          static int condStart[] = { 565, 582 };

          static int condEnd[] = { 578, 596 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,564,597,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 658, 676 };

          static int condEnd[] = { 672, 690 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,657,691,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_sf_marshallOut,(MexInFcnForType)c58_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c58_sf_marshallOut,(MexInFcnForType)c58_sf_marshallIn);

        {
          real_T *c58_randv;
          real_T *c58_smile;
          real_T *c58_wave;
          real_T *c58_win;
          real_T *c58_invade;
          real_T *c58_v_trigW;
          boolean_T *c58_vaFlag;
          real_T *c58_v_trig;
          c58_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c58_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c58_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c58_invade = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c58_win = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c58_wave = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c58_smile = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c58_randv = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c58_randv);
          _SFD_SET_DATA_VALUE_PTR(1U, c58_smile);
          _SFD_SET_DATA_VALUE_PTR(2U, c58_wave);
          _SFD_SET_DATA_VALUE_PTR(3U, c58_win);
          _SFD_SET_DATA_VALUE_PTR(4U, c58_invade);
          _SFD_SET_DATA_VALUE_PTR(5U, c58_v_trigW);
          _SFD_SET_DATA_VALUE_PTR(6U, c58_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(7U, c58_v_trig);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_PoseMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "57O7vadCeH0X7PHMa1NeqF";
}

static void sf_opaque_initialize_c58_Expriment_Pose(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc58_Expriment_PoseInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
  initialize_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c58_Expriment_Pose(void *chartInstanceVar)
{
  enable_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c58_Expriment_Pose(void *chartInstanceVar)
{
  disable_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c58_Expriment_Pose(void *chartInstanceVar)
{
  sf_gateway_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c58_Expriment_Pose(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c58_Expriment_Pose
    ((SFc58_Expriment_PoseInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c58_Expriment_Pose();/* state var info */
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

extern void sf_internal_set_sim_state_c58_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c58_Expriment_Pose();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c58_Expriment_Pose(SimStruct* S)
{
  return sf_internal_get_sim_state_c58_Expriment_Pose(S);
}

static void sf_opaque_set_sim_state_c58_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c58_Expriment_Pose(S, st);
}

static void sf_opaque_terminate_c58_Expriment_Pose(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc58_Expriment_PoseInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Pose_optimization_info();
    }

    finalize_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
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
  initSimStructsc58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c58_Expriment_Pose(SimStruct *S)
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
    initialize_params_c58_Expriment_Pose((SFc58_Expriment_PoseInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c58_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Pose_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      58);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,58,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,58,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,58);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,58,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,58,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,58);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3248540520U));
  ssSetChecksum1(S,(2477504733U));
  ssSetChecksum2(S,(1052817123U));
  ssSetChecksum3(S,(282815459U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c58_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c58_Expriment_Pose(SimStruct *S)
{
  SFc58_Expriment_PoseInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc58_Expriment_PoseInstanceStruct *)utMalloc(sizeof
    (SFc58_Expriment_PoseInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc58_Expriment_PoseInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c58_Expriment_Pose;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c58_Expriment_Pose;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c58_Expriment_Pose;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c58_Expriment_Pose;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c58_Expriment_Pose;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c58_Expriment_Pose;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c58_Expriment_Pose;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c58_Expriment_Pose;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c58_Expriment_Pose;
  chartInstance->chartInfo.mdlStart = mdlStart_c58_Expriment_Pose;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c58_Expriment_Pose;
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

void c58_Expriment_Pose_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c58_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c58_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c58_Expriment_Pose(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c58_Expriment_Pose_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
