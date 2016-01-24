/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_PointUser_AnTS_sfun.h"
#include "c1_ARP_02_PointUser_AnTS.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_PointUser_AnTS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[14] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9", "nargin", "nargout",
  "V", "A", "e" };

/* Function Declarations */
static void initialize_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void initialize_params_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void enable_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void disable_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void set_sim_state_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void sf_gateway_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c1_chartstep_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void initSimStructsc1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_e, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_ARP_02_PointUser_AnTS, const
  char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_ARP_02_PointUser_AnTS = 0U;
}

static void initialize_params_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T *c1_e;
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_hoistedGlobal = *c1_e;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_ARP_02_PointUser_AnTS;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_e;
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *c1_e = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "e");
  chartInstance->c1_is_active_c1_ARP_02_PointUser_AnTS = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_ARP_02_PointUser_AnTS");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_ARP_02_PointUser_AnTS(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  real_T *c1_V;
  real_T *c1_e;
  real_T *c1_A;
  c1_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_V, 0U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_ARP_02_PointUser_AnTS(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_PointUser_AnTSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c1_e, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_A, 2U);
}

static void c1_chartstep_c1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_V;
  real_T c1_A;
  uint32_T c1_debug_family_var_map[14];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_4;
  boolean_T c1_aVarTruthTableCondition_5;
  boolean_T c1_aVarTruthTableCondition_6;
  boolean_T c1_aVarTruthTableCondition_7;
  boolean_T c1_aVarTruthTableCondition_8;
  boolean_T c1_aVarTruthTableCondition_9;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_e;
  boolean_T c1_b0;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b8;
  real_T *c1_b_e;
  real_T *c1_b_V;
  real_T *c1_b_A;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  c1_b_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_V;
  c1_b_hoistedGlobal = *c1_b_A;
  c1_V = c1_hoistedGlobal;
  c1_A = c1_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_4, 3U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_5, 4U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_6, 5U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_7, 6U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_8, 7U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_9, 8U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_V, 11U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_A, 12U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  guard9 = false;
  if (c1_V == 2.0) {
    if (c1_A == 1.0) {
      c1_b0 = true;
    } else {
      guard9 = true;
    }
  } else {
    guard9 = true;
  }

  if (guard9 == true) {
    c1_b0 = false;
  }

  c1_aVarTruthTableCondition_1 = c1_b0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  guard8 = false;
  if (c1_V == 2.0) {
    if (c1_A == 2.0) {
      c1_b1 = true;
    } else {
      guard8 = true;
    }
  } else {
    guard8 = true;
  }

  if (guard8 == true) {
    c1_b1 = false;
  }

  c1_aVarTruthTableCondition_2 = c1_b1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  guard7 = false;
  if (c1_V == -1.0) {
    if (c1_A == 2.0) {
      c1_b2 = true;
    } else {
      guard7 = true;
    }
  } else {
    guard7 = true;
  }

  if (guard7 == true) {
    c1_b2 = false;
  }

  c1_aVarTruthTableCondition_3 = c1_b2;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  guard6 = false;
  if (c1_V == -2.0) {
    if (c1_A == 1.0) {
      c1_b3 = true;
    } else {
      guard6 = true;
    }
  } else {
    guard6 = true;
  }

  if (guard6 == true) {
    c1_b3 = false;
  }

  c1_aVarTruthTableCondition_4 = c1_b3;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  guard5 = false;
  if (c1_V == 2.0) {
    if (c1_A == -1.0) {
      c1_b4 = true;
    } else {
      guard5 = true;
    }
  } else {
    guard5 = true;
  }

  if (guard5 == true) {
    c1_b4 = false;
  }

  c1_aVarTruthTableCondition_5 = c1_b4;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  guard4 = false;
  if (c1_V == 1.0) {
    if (c1_A == -2.0) {
      c1_b5 = true;
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }

  if (guard4 == true) {
    c1_b5 = false;
  }

  c1_aVarTruthTableCondition_6 = c1_b5;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  guard3 = false;
  if (c1_V == -1.0) {
    if (c1_A == -2.0) {
      c1_b6 = true;
    } else {
      guard3 = true;
    }
  } else {
    guard3 = true;
  }

  if (guard3 == true) {
    c1_b6 = false;
  }

  c1_aVarTruthTableCondition_7 = c1_b6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  guard2 = false;
  if (c1_V == -2.0) {
    if (c1_A == -1.0) {
      c1_b7 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    c1_b7 = false;
  }

  c1_aVarTruthTableCondition_8 = c1_b7;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
  guard1 = false;
  if (c1_A == 1.5) {
    if (c1_V == -1.5) {
      c1_b8 = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    c1_b8 = false;
  }

  c1_aVarTruthTableCondition_9 = c1_b8;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
  if (CV_EML_IF(0, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 68);
    c1_e = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -68);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
    if (CV_EML_IF(0, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 74);
      c1_e = 2.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -74);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
      if (CV_EML_IF(0, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 80);
        c1_e = 3.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -80);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
        if (CV_EML_IF(0, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 86);
          c1_e = 4.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -86);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
          if (CV_EML_IF(0, 1, 4, c1_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 92);
            c1_e = 5.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -92);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
            if (CV_EML_IF(0, 1, 5, c1_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
              CV_EML_FCN(0, 6);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 98);
              c1_e = 6.0;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -98);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
              if (CV_EML_IF(0, 1, 6, c1_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
                CV_EML_FCN(0, 7);
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 104);
                c1_e = 7.0;
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -104);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
                if (CV_EML_IF(0, 1, 7, c1_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
                  CV_EML_FCN(0, 8);
                  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 110);
                  c1_e = 8.0;
                  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -110);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
                  if (CV_EML_IF(0, 1, 8, c1_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
                    CV_EML_FCN(0, 9);
                    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 116);
                    c1_e = 9.0;
                    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -116);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
                    CV_EML_FCN(0, 5);
                    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 92);
                    c1_e = 5.0;
                    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -92);
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -61);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_e = c1_e;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_ARP_02_PointUser_AnTS
  (SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_e, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e), &c1_thisId);
  sf_mex_destroy(&c1_e);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
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

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_e;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c1_e = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e), &c1_thisId);
  sf_mex_destroy(&c1_e);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b9;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b9, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b9;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_aVarTruthTableCondition_9;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c1_aVarTruthTableCondition_9 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_aVarTruthTableCondition_9), &c1_thisId);
  sf_mex_destroy(&c1_aVarTruthTableCondition_9);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_ARP_02_PointUser_AnTS_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_ARP_02_PointUser_AnTS, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_ARP_02_PointUser_AnTS), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_ARP_02_PointUser_AnTS);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_ARP_02_PointUser_AnTSInstanceStruct
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

static void init_dsm_address_info(SFc1_ARP_02_PointUser_AnTSInstanceStruct
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

void sf_c1_ARP_02_PointUser_AnTS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(729223605U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(320313680U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2788417786U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4223766916U);
}

mxArray *sf_c1_ARP_02_PointUser_AnTS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ikFsKyVBqOBnETmR3ilQiG");
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

mxArray *sf_c1_ARP_02_PointUser_AnTS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_ARP_02_PointUser_AnTS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_ARP_02_PointUser_AnTS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"e\",},{M[8],M[0],T\"is_active_c1_ARP_02_PointUser_AnTS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ARP_02_PointUser_AnTS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_PointUser_AnTSMachineNumber_,
           1,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_02_PointUser_AnTSMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_PointUser_AnTSMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_PointUser_AnTSMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"V");
          _SFD_SET_DATA_PROPS(1,2,0,1,"e");
          _SFD_SET_DATA_PROPS(2,1,1,0,"A");
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
        _SFD_CV_INIT_EML(0,1,10,9,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,1484);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1484,-1,1542);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1542,-1,1592);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1592,-1,1641);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1641,-1,1697);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1697,-1,1746);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",1746,-1,1799);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",1799,-1,1849);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",1849,-1,1897);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",1897,-1,1946);
        _SFD_CV_INIT_EML_IF(0,1,0,853,883,914,1482);
        _SFD_CV_INIT_EML_IF(0,1,1,914,948,979,1482);
        _SFD_CV_INIT_EML_IF(0,1,2,979,1013,1044,1482);
        _SFD_CV_INIT_EML_IF(0,1,3,1044,1078,1109,1482);
        _SFD_CV_INIT_EML_IF(0,1,4,1109,1143,1174,1482);
        _SFD_CV_INIT_EML_IF(0,1,5,1174,1208,1239,1482);
        _SFD_CV_INIT_EML_IF(0,1,6,1239,1273,1304,1482);
        _SFD_CV_INIT_EML_IF(0,1,7,1304,1338,1369,1482);
        _SFD_CV_INIT_EML_IF(0,1,8,1369,1403,1434,1482);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_V;
          real_T *c1_e;
          real_T *c1_A;
          c1_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_V);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_e);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_A);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_PointUser_AnTSMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "wMfnvZO1UpkWq0oHI4Y2nF";
}

static void sf_opaque_initialize_c1_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_ARP_02_PointUser_AnTS
    ((SFc1_ARP_02_PointUser_AnTSInstanceStruct*) chartInstanceVar);
  initialize_c1_ARP_02_PointUser_AnTS((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  enable_c1_ARP_02_PointUser_AnTS((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  disable_c1_ARP_02_PointUser_AnTS((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  sf_gateway_c1_ARP_02_PointUser_AnTS((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_ARP_02_PointUser_AnTS
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ARP_02_PointUser_AnTS
    ((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ARP_02_PointUser_AnTS();/* state var info */
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

extern void sf_internal_set_sim_state_c1_ARP_02_PointUser_AnTS(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_ARP_02_PointUser_AnTS();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ARP_02_PointUser_AnTS
    ((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_ARP_02_PointUser_AnTS(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_ARP_02_PointUser_AnTS(S);
}

static void sf_opaque_set_sim_state_c1_ARP_02_PointUser_AnTS(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_ARP_02_PointUser_AnTS(S, st);
}

static void sf_opaque_terminate_c1_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ARP_02_PointUser_AnTSInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_PointUser_AnTS_optimization_info();
    }

    finalize_c1_ARP_02_PointUser_AnTS((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)
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
  initSimStructsc1_ARP_02_PointUser_AnTS
    ((SFc1_ARP_02_PointUser_AnTSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ARP_02_PointUser_AnTS(SimStruct *S)
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
    initialize_params_c1_ARP_02_PointUser_AnTS
      ((SFc1_ARP_02_PointUser_AnTSInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ARP_02_PointUser_AnTS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_PointUser_AnTS_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
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
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3225555521U));
  ssSetChecksum1(S,(2230686544U));
  ssSetChecksum2(S,(3638955557U));
  ssSetChecksum3(S,(568074137U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_ARP_02_PointUser_AnTS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c1_ARP_02_PointUser_AnTS(SimStruct *S)
{
  SFc1_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_ARP_02_PointUser_AnTSInstanceStruct *)utMalloc(sizeof
    (SFc1_ARP_02_PointUser_AnTSInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ARP_02_PointUser_AnTSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ARP_02_PointUser_AnTS;
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

void c1_ARP_02_PointUser_AnTS_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ARP_02_PointUser_AnTS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ARP_02_PointUser_AnTS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ARP_02_PointUser_AnTS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ARP_02_PointUser_AnTS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
