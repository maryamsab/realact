/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_AU_VA_sfun.h"
#include "c5_Demo_AU_VA.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_AU_VA_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[13] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "V", "A", "e" };

/* Function Declarations */
static void initialize_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance);
static void initialize_params_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance);
static void enable_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *chartInstance);
static void disable_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *
  chartInstance);
static void set_sim_state_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *chartInstance);
static void sf_gateway_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance);
static void c5_chartstep_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance);
static void initSimStructsc5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct *chartInstance,
  const mxArray *c5_e, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static boolean_T c5_c_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Demo_AU_VA, const char_T
  *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_Demo_AU_VAInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_Demo_AU_VA = 0U;
}

static void initialize_params_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *
  chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T *c5_e;
  c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(2, 1), false);
  c5_hoistedGlobal = *c5_e;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_Demo_AU_VA;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_e;
  c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *c5_e = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "e");
  chartInstance->c5_is_active_c5_Demo_AU_VA = c5_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_Demo_AU_VA");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Demo_AU_VA(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance)
{
  real_T *c5_V;
  real_T *c5_e;
  real_T *c5_A;
  c5_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_V, 0U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_Demo_AU_VA(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_AU_VAMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c5_e, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_A, 2U);
}

static void c5_chartstep_c5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_V;
  real_T c5_A;
  uint32_T c5_debug_family_var_map[13];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  boolean_T c5_aVarTruthTableCondition_4;
  boolean_T c5_aVarTruthTableCondition_5;
  boolean_T c5_aVarTruthTableCondition_6;
  boolean_T c5_aVarTruthTableCondition_7;
  boolean_T c5_aVarTruthTableCondition_8;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  real_T c5_e;
  boolean_T c5_b0;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  real_T *c5_b_e;
  real_T *c5_b_V;
  real_T *c5_b_A;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  c5_b_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_V;
  c5_b_hoistedGlobal = *c5_b_A;
  c5_V = c5_hoistedGlobal;
  c5_A = c5_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_4, 3U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_5, 4U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_6, 5U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_7, 6U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_8, 7U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_V, 10U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_A, 11U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  guard11 = false;
  guard12 = false;
  if (c5_V > 10.0) {
    if (c5_A < 40.0) {
      if (c5_A > 10.0) {
        c5_b0 = true;
      } else {
        guard11 = true;
      }
    } else {
      guard12 = true;
    }
  } else {
    guard12 = true;
  }

  if (guard12 == true) {
    guard11 = true;
  }

  if (guard11 == true) {
    c5_b0 = false;
  }

  c5_aVarTruthTableCondition_1 = c5_b0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  guard10 = false;
  if (c5_V > 0.0) {
    if (c5_A > 40.0) {
      c5_b1 = true;
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 == true) {
    c5_b1 = false;
  }

  c5_aVarTruthTableCondition_2 = c5_b1;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  guard9 = false;
  if (c5_V < 0.0) {
    if (c5_A > 40.0) {
      c5_b2 = true;
    } else {
      guard9 = true;
    }
  } else {
    guard9 = true;
  }

  if (guard9 == true) {
    c5_b2 = false;
  }

  c5_aVarTruthTableCondition_3 = c5_b2;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
  guard7 = false;
  guard8 = false;
  if (c5_V < -10.0) {
    if (c5_A < 40.0) {
      if (c5_A > 10.0) {
        c5_b3 = true;
      } else {
        guard7 = true;
      }
    } else {
      guard8 = true;
    }
  } else {
    guard8 = true;
  }

  if (guard8 == true) {
    guard7 = true;
  }

  if (guard7 == true) {
    c5_b3 = false;
  }

  c5_aVarTruthTableCondition_4 = c5_b3;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
  guard5 = false;
  guard6 = false;
  if (c5_V > 10.0) {
    if (c5_A < -10.0) {
      if (c5_A > -40.0) {
        c5_b4 = true;
      } else {
        guard5 = true;
      }
    } else {
      guard6 = true;
    }
  } else {
    guard6 = true;
  }

  if (guard6 == true) {
    guard5 = true;
  }

  if (guard5 == true) {
    c5_b4 = false;
  }

  c5_aVarTruthTableCondition_5 = c5_b4;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 35);
  guard4 = false;
  if (c5_V > 0.0) {
    if (c5_A < -40.0) {
      c5_b5 = true;
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }

  if (guard4 == true) {
    c5_b5 = false;
  }

  c5_aVarTruthTableCondition_6 = c5_b5;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 39);
  guard3 = false;
  if (c5_V < 0.0) {
    if (c5_A < -40.0) {
      c5_b6 = true;
    } else {
      guard3 = true;
    }
  } else {
    guard3 = true;
  }

  if (guard3 == true) {
    c5_b6 = false;
  }

  c5_aVarTruthTableCondition_7 = c5_b6;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 43);
  guard1 = false;
  guard2 = false;
  if (c5_V < -10.0) {
    if (c5_A < -10.0) {
      if (c5_A > -40.0) {
        c5_b7 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c5_b7 = false;
  }

  c5_aVarTruthTableCondition_8 = c5_b7;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 45);
  if (CV_EML_IF(0, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 46);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 69);
    c5_e = 7.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -69);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 47);
    if (CV_EML_IF(0, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 48);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 75);
      c5_e = 8.0;
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -75);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 49);
      if (CV_EML_IF(0, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 50);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 81);
        c5_e = 4.0;
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -81);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 51);
        if (CV_EML_IF(0, 1, 3, c5_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 52);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 87);
          c5_e = 3.0;
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -87);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 53);
          if (CV_EML_IF(0, 1, 4, c5_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 54);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 93);
            c5_e = 6.0;
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -93);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 55);
            if (CV_EML_IF(0, 1, 5, c5_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 56);
              CV_EML_FCN(0, 6);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 99);
              c5_e = 5.0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -99);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 57);
              if (CV_EML_IF(0, 1, 6, c5_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 58);
                CV_EML_FCN(0, 7);
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 105);
                c5_e = 1.0;
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -105);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 59);
                if (CV_EML_IF(0, 1, 7, c5_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 60);
                  CV_EML_FCN(0, 8);
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 111);
                  c5_e = 2.0;
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 62);
                  CV_EML_FCN(0, 5);
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 93);
                  c5_e = 6.0;
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -93);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
  *c5_b_e = c5_e;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_Demo_AU_VA(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Demo_AU_VAInstanceStruct *chartInstance;
  chartInstance = (SFc5_Demo_AU_VAInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct *chartInstance,
  const mxArray *c5_e, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_e), &c5_thisId);
  sf_mex_destroy(&c5_e);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_e;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_Demo_AU_VAInstanceStruct *chartInstance;
  chartInstance = (SFc5_Demo_AU_VAInstanceStruct *)chartInstanceVoid;
  c5_e = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_e), &c5_thisId);
  sf_mex_destroy(&c5_e);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  boolean_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Demo_AU_VAInstanceStruct *chartInstance;
  chartInstance = (SFc5_Demo_AU_VAInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(boolean_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static boolean_T c5_c_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  boolean_T c5_y;
  boolean_T c5_b8;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b8, 1, 11, 0U, 0, 0U, 0);
  c5_y = c5_b8;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_aVarTruthTableCondition_8;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_y;
  SFc5_Demo_AU_VAInstanceStruct *chartInstance;
  chartInstance = (SFc5_Demo_AU_VAInstanceStruct *)chartInstanceVoid;
  c5_aVarTruthTableCondition_8 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_aVarTruthTableCondition_8), &c5_thisId);
  sf_mex_destroy(&c5_aVarTruthTableCondition_8);
  *(boolean_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Demo_AU_VA_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Demo_AU_VAInstanceStruct *chartInstance;
  chartInstance = (SFc5_Demo_AU_VAInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i0, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_Demo_AU_VAInstanceStruct *chartInstance;
  chartInstance = (SFc5_Demo_AU_VAInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Demo_AU_VA, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Demo_AU_VA), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Demo_AU_VA);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_Demo_AU_VAInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_Demo_AU_VAInstanceStruct *chartInstance)
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

void sf_c5_Demo_AU_VA_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2924027576U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3917474555U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(904934237U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2117593214U);
}

mxArray *sf_c5_Demo_AU_VA_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("DsGiFVf3BSSsPxOzqVwzkE");
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

mxArray *sf_c5_Demo_AU_VA_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_Demo_AU_VA_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_Demo_AU_VA(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"e\",},{M[8],M[0],T\"is_active_c5_Demo_AU_VA\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Demo_AU_VA_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Demo_AU_VAInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_Demo_AU_VAInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_AU_VAMachineNumber_,
           5,
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
        init_script_number_translation(_Demo_AU_VAMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_AU_VAMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_AU_VAMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,1491);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1491,-1,1541);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1541,-1,1593);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1593,-1,1642);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1642,-1,1698);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1698,-1,1750);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",1750,-1,1803);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",1803,-1,1853);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",1853,-1,1900);
        _SFD_CV_INIT_EML_IF(0,1,0,925,955,986,1489);
        _SFD_CV_INIT_EML_IF(0,1,1,986,1020,1051,1489);
        _SFD_CV_INIT_EML_IF(0,1,2,1051,1085,1116,1489);
        _SFD_CV_INIT_EML_IF(0,1,3,1116,1150,1181,1489);
        _SFD_CV_INIT_EML_IF(0,1,4,1181,1215,1246,1489);
        _SFD_CV_INIT_EML_IF(0,1,5,1246,1280,1311,1489);
        _SFD_CV_INIT_EML_IF(0,1,6,1311,1345,1376,1489);
        _SFD_CV_INIT_EML_IF(0,1,7,1376,1410,1441,1489);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c5_V;
          real_T *c5_e;
          real_T *c5_A;
          c5_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_V);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_e);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_A);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_AU_VAMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "94EHSMjC42UJTIOKUCRIaE";
}

static void sf_opaque_initialize_c5_Demo_AU_VA(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*)
    chartInstanceVar);
  initialize_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_Demo_AU_VA(void *chartInstanceVar)
{
  enable_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_Demo_AU_VA(void *chartInstanceVar)
{
  disable_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_Demo_AU_VA(void *chartInstanceVar)
{
  sf_gateway_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_Demo_AU_VA(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_Demo_AU_VA
    ((SFc5_Demo_AU_VAInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Demo_AU_VA();/* state var info */
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

extern void sf_internal_set_sim_state_c5_Demo_AU_VA(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_Demo_AU_VA();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_Demo_AU_VA(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_Demo_AU_VA(S);
}

static void sf_opaque_set_sim_state_c5_Demo_AU_VA(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_Demo_AU_VA(S, st);
}

static void sf_opaque_terminate_c5_Demo_AU_VA(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_AU_VA_optimization_info();
    }

    finalize_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Demo_AU_VA(SimStruct *S)
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
    initialize_params_c5_Demo_AU_VA((SFc5_Demo_AU_VAInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Demo_AU_VA(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_AU_VA_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2156838119U));
  ssSetChecksum1(S,(1414360541U));
  ssSetChecksum2(S,(1191667092U));
  ssSetChecksum3(S,(2065238556U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_Demo_AU_VA(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c5_Demo_AU_VA(SimStruct *S)
{
  SFc5_Demo_AU_VAInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_Demo_AU_VAInstanceStruct *)utMalloc(sizeof
    (SFc5_Demo_AU_VAInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_Demo_AU_VAInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_Demo_AU_VA;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_Demo_AU_VA;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_Demo_AU_VA;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_Demo_AU_VA;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_Demo_AU_VA;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_Demo_AU_VA;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_Demo_AU_VA;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_Demo_AU_VA;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Demo_AU_VA;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Demo_AU_VA;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_Demo_AU_VA;
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

void c5_Demo_AU_VA_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Demo_AU_VA(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Demo_AU_VA(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Demo_AU_VA(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Demo_AU_VA_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
