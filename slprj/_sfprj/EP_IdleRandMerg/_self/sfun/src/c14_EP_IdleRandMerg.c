/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EP_IdleRandMerg_sfun.h"
#include "c14_EP_IdleRandMerg.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EP_IdleRandMerg_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c14_debug_family_names[8] = { "randTrigger", "nargin",
  "nargout", "userInvade", "interactionState", "randa", "arousalTrig", "a_trigW"
};

/* Function Declarations */
static void initialize_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void initialize_params_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance);
static void enable_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void disable_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void c14_update_debugger_state_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance);
static void set_sim_state_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray *c14_st);
static void finalize_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void sf_gateway_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void initSimStructsc14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_a_trigW, const char_T *c14_identifier);
static real_T c14_b_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_info_helper(const mxArray **c14_info);
static const mxArray *c14_emlrt_marshallOut(const char * c14_u);
static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_c_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_d_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_EP_IdleRandMerg, const
  char_T *c14_identifier);
static uint8_T c14_e_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_is_active_c14_EP_IdleRandMerg = 0U;
}

static void initialize_params_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c14_update_debugger_state_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_b_hoistedGlobal;
  real_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  uint8_T c14_c_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  real_T *c14_a_trigW;
  real_T *c14_arousalTrig;
  c14_a_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_arousalTrig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(3, 1), false);
  c14_hoistedGlobal = *c14_a_trigW;
  c14_u = c14_hoistedGlobal;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_b_hoistedGlobal = *c14_arousalTrig;
  c14_b_u = c14_b_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_c_hoistedGlobal = chartInstance->c14_is_active_c14_EP_IdleRandMerg;
  c14_c_u = c14_c_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T *c14_a_trigW;
  real_T *c14_arousalTrig;
  c14_a_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_arousalTrig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = true;
  c14_u = sf_mex_dup(c14_st);
  *c14_a_trigW = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 0)), "a_trigW");
  *c14_arousalTrig = c14_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 1)), "arousalTrig");
  chartInstance->c14_is_active_c14_EP_IdleRandMerg = c14_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
     "is_active_c14_EP_IdleRandMerg");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_EP_IdleRandMerg(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c14_EP_IdleRandMerg(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  real_T c14_hoistedGlobal;
  real_T c14_b_hoistedGlobal;
  real_T c14_c_hoistedGlobal;
  real_T c14_userInvade;
  real_T c14_interactionState;
  real_T c14_randa;
  uint32_T c14_debug_family_var_map[8];
  real_T c14_randTrigger;
  real_T c14_nargin = 3.0;
  real_T c14_nargout = 2.0;
  real_T c14_arousalTrig;
  real_T c14_a_trigW;
  real_T c14_x;
  real_T c14_b_x;
  real_T *c14_b_userInvade;
  real_T *c14_b_interactionState;
  real_T *c14_b_randa;
  real_T *c14_b_arousalTrig;
  real_T *c14_b_a_trigW;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c14_b_a_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_b_arousalTrig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_b_randa = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c14_b_interactionState = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_b_userInvade = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c14_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c14_b_userInvade, 0U);
  _SFD_DATA_RANGE_CHECK(*c14_b_interactionState, 1U);
  _SFD_DATA_RANGE_CHECK(*c14_b_randa, 2U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c14_sfEvent);
  c14_hoistedGlobal = *c14_b_userInvade;
  c14_b_hoistedGlobal = *c14_b_interactionState;
  c14_c_hoistedGlobal = *c14_b_randa;
  c14_userInvade = c14_hoistedGlobal;
  c14_interactionState = c14_b_hoistedGlobal;
  c14_randa = c14_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_randTrigger, 0U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 1U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 2U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_userInvade, 3U, c14_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_interactionState, 4U, c14_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_randa, 5U, c14_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_arousalTrig, 6U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_a_trigW, 7U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 9);
  c14_arousalTrig = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 9);
  c14_a_trigW = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 10);
  c14_x = c14_randa;
  c14_randTrigger = c14_x;
  c14_b_x = c14_randTrigger;
  c14_randTrigger = c14_b_x;
  c14_randTrigger = muDoubleScalarFloor(c14_randTrigger);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 11);
  guard2 = false;
  if (CV_EML_COND(0, 1, 0, 0.0 < c14_randTrigger)) {
    if (CV_EML_COND(0, 1, 1, c14_randTrigger < 30.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 12);
      c14_arousalTrig = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 12);
      c14_a_trigW = 0.1;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 14);
  guard1 = false;
  if (CV_EML_COND(0, 1, 2, 30.0 < c14_randTrigger)) {
    if (CV_EML_COND(0, 1, 3, c14_randTrigger < 60.0)) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 15);
      c14_arousalTrig = -1.0;
      _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 15);
      c14_a_trigW = 0.1;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 1, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 18);
  if (CV_EML_IF(0, 1, 2, c14_interactionState == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 19);
    c14_arousalTrig = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 19);
    c14_a_trigW = 0.5;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 21);
  if (CV_EML_IF(0, 1, 3, c14_interactionState == 7.0)) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 22);
    c14_arousalTrig = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 22);
    c14_a_trigW = 0.5;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 24);
  if (CV_EML_IF(0, 1, 4, c14_interactionState == 2.0)) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 25);
    c14_arousalTrig = -1.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 25);
    c14_a_trigW = 0.5;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 27);
  if (CV_EML_IF(0, 1, 5, c14_interactionState == 6.0)) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 28);
    c14_arousalTrig = -1.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 28);
    c14_a_trigW = 0.5;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 33);
  if (CV_EML_IF(0, 1, 6, c14_userInvade == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 34);
    c14_arousalTrig = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 34);
    c14_a_trigW = 0.1;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  *c14_b_arousalTrig = c14_arousalTrig;
  *c14_b_a_trigW = c14_a_trigW;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c14_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EP_IdleRandMergMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c14_b_arousalTrig, 3U);
  _SFD_DATA_RANGE_CHECK(*c14_b_a_trigW, 4U);
}

static void initSimStructsc14_EP_IdleRandMerg
  (SFc14_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  (void)c14_chartNumber;
  (void)c14_instanceNumber;
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc14_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_a_trigW, const char_T *c14_identifier)
{
  real_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_a_trigW),
    &c14_thisId);
  sf_mex_destroy(&c14_a_trigW);
  return c14_y;
}

static real_T c14_b_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_a_trigW;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc14_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c14_a_trigW = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_a_trigW),
    &c14_thisId);
  sf_mex_destroy(&c14_a_trigW);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_EP_IdleRandMerg_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c14_info_helper(&c14_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(const mxArray **c14_info)
{
  const mxArray *c14_rhs0 = NULL;
  const mxArray *c14_lhs0 = NULL;
  const mxArray *c14_rhs1 = NULL;
  const mxArray *c14_lhs1 = NULL;
  const mxArray *c14_rhs2 = NULL;
  const mxArray *c14_lhs2 = NULL;
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("floor"), "name", "name", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c14_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c14_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c14_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c14_rhs0);
  sf_mex_destroy(&c14_lhs0);
  sf_mex_destroy(&c14_rhs1);
  sf_mex_destroy(&c14_lhs1);
  sf_mex_destroy(&c14_rhs2);
  sf_mex_destroy(&c14_lhs2);
}

static const mxArray *c14_emlrt_marshallOut(const char * c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c14_u)), false);
  return c14_y;
}

static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 7, 0U, 0U, 0U, 0), false);
  return c14_y;
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc14_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_c_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i0, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc14_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_d_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_EP_IdleRandMerg, const
  char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_EP_IdleRandMerg), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_EP_IdleRandMerg);
  return c14_y;
}

static uint8_T c14_e_emlrt_marshallIn(SFc14_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info(SFc14_EP_IdleRandMergInstanceStruct
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

void sf_c14_EP_IdleRandMerg_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4183494561U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1691237576U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2807253023U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1557482140U);
}

mxArray *sf_c14_EP_IdleRandMerg_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tqm83fUVasSnQPhC8yNNTG");
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

mxArray *sf_c14_EP_IdleRandMerg_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_EP_IdleRandMerg_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c14_EP_IdleRandMerg(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"a_trigW\",},{M[1],M[5],T\"arousalTrig\",},{M[8],M[0],T\"is_active_c14_EP_IdleRandMerg\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_EP_IdleRandMerg_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_EP_IdleRandMergInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_EP_IdleRandMergInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EP_IdleRandMergMachineNumber_,
           14,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_EP_IdleRandMergMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_EP_IdleRandMergMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _EP_IdleRandMergMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"userInvade");
          _SFD_SET_DATA_PROPS(1,1,1,0,"interactionState");
          _SFD_SET_DATA_PROPS(2,1,1,0,"randa");
          _SFD_SET_DATA_PROPS(3,2,0,1,"arousalTrig");
          _SFD_SET_DATA_PROPS(4,2,0,1,"a_trigW");
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
        _SFD_CV_INIT_EML(0,1,1,7,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1187);
        _SFD_CV_INIT_EML_IF(0,1,0,456,491,-1,534);
        _SFD_CV_INIT_EML_IF(0,1,1,539,575,-1,619);
        _SFD_CV_INIT_EML_IF(0,1,2,629,652,-1,722);
        _SFD_CV_INIT_EML_IF(0,1,3,727,750,-1,821);
        _SFD_CV_INIT_EML_IF(0,1,4,826,849,-1,921);
        _SFD_CV_INIT_EML_IF(0,1,5,926,949,-1,1018);
        _SFD_CV_INIT_EML_IF(0,1,6,1128,1145,-1,1187);

        {
          static int condStart[] = { 459, 476 };

          static int condEnd[] = { 472, 490 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,458,491,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 542, 560 };

          static int condEnd[] = { 556, 574 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,541,575,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);

        {
          real_T *c14_userInvade;
          real_T *c14_interactionState;
          real_T *c14_randa;
          real_T *c14_arousalTrig;
          real_T *c14_a_trigW;
          c14_a_trigW = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c14_arousalTrig = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c14_randa = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c14_interactionState = (real_T *)ssGetInputPortSignal(chartInstance->S,
            1);
          c14_userInvade = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c14_userInvade);
          _SFD_SET_DATA_VALUE_PTR(1U, c14_interactionState);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_randa);
          _SFD_SET_DATA_VALUE_PTR(3U, c14_arousalTrig);
          _SFD_SET_DATA_VALUE_PTR(4U, c14_a_trigW);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _EP_IdleRandMergMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "1l8cmGlAYERLWs9KBrY8h";
}

static void sf_opaque_initialize_c14_EP_IdleRandMerg(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
  initialize_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_EP_IdleRandMerg(void *chartInstanceVar)
{
  enable_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_EP_IdleRandMerg(void *chartInstanceVar)
{
  disable_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_EP_IdleRandMerg(void *chartInstanceVar)
{
  sf_gateway_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_EP_IdleRandMerg(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_EP_IdleRandMerg
    ((SFc14_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_EP_IdleRandMerg();/* state var info */
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

extern void sf_internal_set_sim_state_c14_EP_IdleRandMerg(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c14_EP_IdleRandMerg();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_EP_IdleRandMerg(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_EP_IdleRandMerg(S);
}

static void sf_opaque_set_sim_state_c14_EP_IdleRandMerg(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c14_EP_IdleRandMerg(S, st);
}

static void sf_opaque_terminate_c14_EP_IdleRandMerg(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_EP_IdleRandMergInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EP_IdleRandMerg_optimization_info();
    }

    finalize_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
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
  initSimStructsc14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_EP_IdleRandMerg(SimStruct *S)
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
    initialize_params_c14_EP_IdleRandMerg((SFc14_EP_IdleRandMergInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EP_IdleRandMerg_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(809350916U));
  ssSetChecksum1(S,(2609882582U));
  ssSetChecksum2(S,(4053116121U));
  ssSetChecksum3(S,(263400873U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_EP_IdleRandMerg(SimStruct *S)
{
  SFc14_EP_IdleRandMergInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_EP_IdleRandMergInstanceStruct *)utMalloc(sizeof
    (SFc14_EP_IdleRandMergInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_EP_IdleRandMergInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_EP_IdleRandMerg;
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

void c14_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_EP_IdleRandMerg(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_EP_IdleRandMerg_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
