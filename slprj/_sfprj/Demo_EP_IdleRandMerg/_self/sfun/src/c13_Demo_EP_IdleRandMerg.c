/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_EP_IdleRandMerg_sfun.h"
#include "c13_Demo_EP_IdleRandMerg.h"
#include "mwmathutil.h"
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
static const char * c13_debug_family_names[11] = { "randTrigger", "nargin",
  "nargout", "smile", "wave", "win", "invade", "vaFlag", "randv", "v_trigW",
  "v_trig" };

/* Function Declarations */
static void initialize_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initialize_params_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void enable_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void disable_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void set_sim_state_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c13_st);
static void finalize_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void sf_gateway_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initSimStructsc13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_v_trigW, const char_T *c13_identifier);
static real_T c13_b_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_info_helper(const mxArray **c13_info);
static const mxArray *c13_emlrt_marshallOut(const char * c13_u);
static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_u);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_c_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_d_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_Demo_EP_IdleRandMerg, const
  char_T *c13_identifier);
static uint8_T c13_e_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_is_active_c13_Demo_EP_IdleRandMerg = 0U;
}

static void initialize_params_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c13_update_debugger_state_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_b_hoistedGlobal;
  real_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  uint8_T c13_c_hoistedGlobal;
  uint8_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  real_T *c13_v_trig;
  real_T *c13_v_trigW;
  c13_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c13_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(3, 1), false);
  c13_hoistedGlobal = *c13_v_trig;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = *c13_v_trigW;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_c_hoistedGlobal = chartInstance->c13_is_active_c13_Demo_EP_IdleRandMerg;
  c13_c_u = c13_c_hoistedGlobal;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c13_st)
{
  const mxArray *c13_u;
  real_T *c13_v_trig;
  real_T *c13_v_trigW;
  c13_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c13_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  *c13_v_trig = c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 0)), "v_trig");
  *c13_v_trigW = c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 1)), "v_trigW");
  chartInstance->c13_is_active_c13_Demo_EP_IdleRandMerg = c13_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 2)),
     "is_active_c13_Demo_EP_IdleRandMerg");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_Demo_EP_IdleRandMerg(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  real_T c13_hoistedGlobal;
  real_T c13_b_hoistedGlobal;
  real_T c13_c_hoistedGlobal;
  real_T c13_d_hoistedGlobal;
  boolean_T c13_e_hoistedGlobal;
  real_T c13_f_hoistedGlobal;
  real_T c13_smile;
  real_T c13_wave;
  real_T c13_win;
  real_T c13_invade;
  boolean_T c13_vaFlag;
  real_T c13_randv;
  uint32_T c13_debug_family_var_map[11];
  real_T c13_randTrigger;
  real_T c13_nargin = 6.0;
  real_T c13_nargout = 2.0;
  real_T c13_v_trigW;
  real_T c13_v_trig;
  real_T c13_x;
  real_T c13_b_x;
  real_T *c13_b_smile;
  real_T *c13_b_wave;
  real_T *c13_b_win;
  real_T *c13_b_invade;
  real_T *c13_b_v_trigW;
  boolean_T *c13_b_vaFlag;
  real_T *c13_b_randv;
  real_T *c13_b_v_trig;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c13_b_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c13_b_randv = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c13_b_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c13_b_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_invade = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c13_b_win = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c13_b_wave = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_smile = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c13_b_smile, 0U);
  _SFD_DATA_RANGE_CHECK(*c13_b_wave, 1U);
  _SFD_DATA_RANGE_CHECK(*c13_b_win, 2U);
  _SFD_DATA_RANGE_CHECK(*c13_b_invade, 3U);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c13_sfEvent);
  c13_hoistedGlobal = *c13_b_smile;
  c13_b_hoistedGlobal = *c13_b_wave;
  c13_c_hoistedGlobal = *c13_b_win;
  c13_d_hoistedGlobal = *c13_b_invade;
  c13_e_hoistedGlobal = *c13_b_vaFlag;
  c13_f_hoistedGlobal = *c13_b_randv;
  c13_smile = c13_hoistedGlobal;
  c13_wave = c13_b_hoistedGlobal;
  c13_win = c13_c_hoistedGlobal;
  c13_invade = c13_d_hoistedGlobal;
  c13_vaFlag = c13_e_hoistedGlobal;
  c13_randv = c13_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_randTrigger, 0U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 1U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 2U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_smile, 3U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_wave, 4U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_win, 5U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_invade, 6U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_vaFlag, 7U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_randv, 8U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_v_trigW, 9U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_v_trig, 10U, c13_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
  c13_v_trigW = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 10);
  if (CV_EML_IF(0, 1, 0, (real_T)c13_vaFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 12);
    c13_x = c13_randv;
    c13_randTrigger = c13_x;
    c13_b_x = c13_randTrigger;
    c13_randTrigger = c13_b_x;
    c13_randTrigger = muDoubleScalarFloor(c13_randTrigger);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 13);
    guard2 = false;
    if (CV_EML_COND(0, 1, 0, 0.0 < c13_randTrigger)) {
      if (CV_EML_COND(0, 1, 1, c13_randTrigger < 30.0)) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 1, true);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 14);
        c13_v_trigW += 0.05;
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

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 16);
    guard1 = false;
    if (CV_EML_COND(0, 1, 2, 30.0 < c13_randTrigger)) {
      if (CV_EML_COND(0, 1, 3, c13_randTrigger < 60.0)) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 2, true);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 17);
        c13_v_trigW -= 0.05;
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

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 20);
    if (CV_EML_IF(0, 1, 3, c13_win == 2.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 21);
      c13_v_trigW += 0.5;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 22);
      if (CV_EML_IF(0, 1, 4, c13_win == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 23);
        c13_v_trigW -= 0.5;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 26);
    if (CV_EML_IF(0, 1, 5, c13_smile == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 27);
      c13_v_trigW += 0.25;
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 30);
    if (CV_EML_IF(0, 1, 6, c13_wave == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 31);
      c13_v_trigW += 0.25;
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 34);
    if (CV_EML_IF(0, 1, 7, c13_invade == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 35);
      c13_v_trigW -= 0.25;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 38);
    c13_v_trigW = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 40);
  if (CV_EML_IF(0, 1, 8, c13_v_trigW > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 41);
    c13_v_trig = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 42);
    if (CV_EML_IF(0, 1, 9, c13_v_trigW < 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 43);
      c13_v_trig = -1.0;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 44);
      c13_v_trigW = 1.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 46);
      c13_v_trig = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -46);
  _SFD_SYMBOL_SCOPE_POP();
  *c13_b_v_trigW = c13_v_trigW;
  *c13_b_v_trig = c13_v_trig;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c13_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_EP_IdleRandMergMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c13_b_v_trigW, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_b_vaFlag, 5U);
  _SFD_DATA_RANGE_CHECK(*c13_b_randv, 6U);
  _SFD_DATA_RANGE_CHECK(*c13_b_v_trig, 7U);
}

static void initSimStructsc13_Demo_EP_IdleRandMerg
  (SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  (void)c13_chartNumber;
  (void)c13_instanceNumber;
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc13_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_v_trigW, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_v_trigW),
    &c13_thisId);
  sf_mex_destroy(&c13_v_trigW);
  return c13_y;
}

static real_T c13_b_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_v_trigW;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc13_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c13_v_trigW = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_v_trigW),
    &c13_thisId);
  sf_mex_destroy(&c13_v_trigW);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  boolean_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc13_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(boolean_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

const mxArray *sf_c13_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
                false);
  c13_info_helper(&c13_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(const mxArray **c13_info)
{
  const mxArray *c13_rhs0 = NULL;
  const mxArray *c13_lhs0 = NULL;
  const mxArray *c13_rhs1 = NULL;
  const mxArray *c13_lhs1 = NULL;
  const mxArray *c13_rhs2 = NULL;
  const mxArray *c13_lhs2 = NULL;
  const mxArray *c13_rhs3 = NULL;
  const mxArray *c13_lhs3 = NULL;
  const mxArray *c13_rhs4 = NULL;
  const mxArray *c13_lhs4 = NULL;
  const mxArray *c13_rhs5 = NULL;
  const mxArray *c13_lhs5 = NULL;
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("floor"), "name", "name", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c13_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c13_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c13_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("abs"), "name", "name", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c13_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c13_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c13_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs5), "lhs", "lhs",
                  5);
  sf_mex_destroy(&c13_rhs0);
  sf_mex_destroy(&c13_lhs0);
  sf_mex_destroy(&c13_rhs1);
  sf_mex_destroy(&c13_lhs1);
  sf_mex_destroy(&c13_rhs2);
  sf_mex_destroy(&c13_lhs2);
  sf_mex_destroy(&c13_rhs3);
  sf_mex_destroy(&c13_lhs3);
  sf_mex_destroy(&c13_rhs4);
  sf_mex_destroy(&c13_lhs4);
  sf_mex_destroy(&c13_rhs5);
  sf_mex_destroy(&c13_lhs5);
}

static const mxArray *c13_emlrt_marshallOut(const char * c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c13_u)), false);
  return c13_y;
}

static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 7, 0U, 0U, 0U, 0), false);
  return c13_y;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc13_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_c_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i0, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc13_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_d_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_Demo_EP_IdleRandMerg, const
  char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_Demo_EP_IdleRandMerg), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_Demo_EP_IdleRandMerg);
  return c13_y;
}

static uint8_T c13_e_emlrt_marshallIn(SFc13_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_Demo_EP_IdleRandMergInstanceStruct
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

void sf_c13_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1889225076U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1889842447U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(290050852U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1675018771U);
}

mxArray *sf_c13_Demo_EP_IdleRandMerg_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zWrtVS2BxvkXpDYdA5w9oE");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

mxArray *sf_c13_Demo_EP_IdleRandMerg_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_Demo_EP_IdleRandMerg_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_Demo_EP_IdleRandMerg(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[14],T\"v_trig\",},{M[1],M[11],T\"v_trigW\",},{M[8],M[0],T\"is_active_c13_Demo_EP_IdleRandMerg\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_Demo_EP_IdleRandMerg_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc13_Demo_EP_IdleRandMergInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_EP_IdleRandMergMachineNumber_,
           13,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"smile");
          _SFD_SET_DATA_PROPS(1,1,1,0,"wave");
          _SFD_SET_DATA_PROPS(2,1,1,0,"win");
          _SFD_SET_DATA_PROPS(3,1,1,0,"invade");
          _SFD_SET_DATA_PROPS(4,2,0,1,"v_trigW");
          _SFD_SET_DATA_PROPS(5,1,1,0,"vaFlag");
          _SFD_SET_DATA_PROPS(6,1,1,0,"randv");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1311);
        _SFD_CV_INIT_EML_IF(0,1,0,442,455,1137,1169);
        _SFD_CV_INIT_EML_IF(0,1,1,566,601,-1,647);
        _SFD_CV_INIT_EML_IF(0,1,2,656,692,-1,738);
        _SFD_CV_INIT_EML_IF(0,1,3,748,758,832,846);
        _SFD_CV_INIT_EML_IF(0,1,4,832,846,-1,846);
        _SFD_CV_INIT_EML_IF(0,1,5,938,950,-1,996);
        _SFD_CV_INIT_EML_IF(0,1,6,1006,1017,-1,1063);
        _SFD_CV_INIT_EML_IF(0,1,7,1073,1086,-1,1132);
        _SFD_CV_INIT_EML_IF(0,1,8,1174,1187,1210,1310);
        _SFD_CV_INIT_EML_IF(0,1,9,1210,1227,1280,1310);

        {
          static int condStart[] = { 569, 586 };

          static int condEnd[] = { 582, 600 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,568,601,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 659, 677 };

          static int condEnd[] = { 673, 691 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,658,692,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);

        {
          real_T *c13_smile;
          real_T *c13_wave;
          real_T *c13_win;
          real_T *c13_invade;
          real_T *c13_v_trigW;
          boolean_T *c13_vaFlag;
          real_T *c13_randv;
          real_T *c13_v_trig;
          c13_v_trig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c13_randv = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c13_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c13_v_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c13_invade = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c13_win = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c13_wave = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c13_smile = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_smile);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_wave);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_win);
          _SFD_SET_DATA_VALUE_PTR(3U, c13_invade);
          _SFD_SET_DATA_VALUE_PTR(4U, c13_v_trigW);
          _SFD_SET_DATA_VALUE_PTR(5U, c13_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(6U, c13_randv);
          _SFD_SET_DATA_VALUE_PTR(7U, c13_v_trig);
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
  return "BCWB2dcpeExeMoPXkiwlND";
}

static void sf_opaque_initialize_c13_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_Demo_EP_IdleRandMerg
    ((SFc13_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
  initialize_c13_Demo_EP_IdleRandMerg((SFc13_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  enable_c13_Demo_EP_IdleRandMerg((SFc13_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  disable_c13_Demo_EP_IdleRandMerg((SFc13_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  sf_gateway_c13_Demo_EP_IdleRandMerg((SFc13_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_Demo_EP_IdleRandMerg
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_Demo_EP_IdleRandMerg
    ((SFc13_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_Demo_EP_IdleRandMerg();/* state var info */
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

extern void sf_internal_set_sim_state_c13_Demo_EP_IdleRandMerg(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c13_Demo_EP_IdleRandMerg();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_Demo_EP_IdleRandMerg
    ((SFc13_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_Demo_EP_IdleRandMerg(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c13_Demo_EP_IdleRandMerg(S);
}

static void sf_opaque_set_sim_state_c13_Demo_EP_IdleRandMerg(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_Demo_EP_IdleRandMerg(S, st);
}

static void sf_opaque_terminate_c13_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_EP_IdleRandMerg_optimization_info();
    }

    finalize_c13_Demo_EP_IdleRandMerg((SFc13_Demo_EP_IdleRandMergInstanceStruct*)
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
  initSimStructsc13_Demo_EP_IdleRandMerg
    ((SFc13_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_Demo_EP_IdleRandMerg(SimStruct *S)
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
    initialize_params_c13_Demo_EP_IdleRandMerg
      ((SFc13_Demo_EP_IdleRandMergInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_EP_IdleRandMerg_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(249175226U));
  ssSetChecksum1(S,(2834939183U));
  ssSetChecksum2(S,(2277021994U));
  ssSetChecksum3(S,(3315644269U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_Demo_EP_IdleRandMerg(SimStruct *S)
{
  SFc13_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc13_Demo_EP_IdleRandMergInstanceStruct *)utMalloc(sizeof
    (SFc13_Demo_EP_IdleRandMergInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_Demo_EP_IdleRandMergInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_Demo_EP_IdleRandMerg;
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

void c13_Demo_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_Demo_EP_IdleRandMerg(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_Demo_EP_IdleRandMerg_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
