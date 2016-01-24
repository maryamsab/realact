/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testBradImitateSmile_sfun.h"
#include "c3_testBradImitateSmile.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testBradImitateSmile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_event                 (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_smile                    ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c3_subchartSimStateInfo;

/* Function Declarations */
static void initialize_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void initialize_params_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void enable_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void disable_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void set_sim_state_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void finalize_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void sf_gateway_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void initSimStructsc3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static int8_T c3_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_b_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_c_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_smile, const char_T *c3_identifier);
static uint8_T c3_d_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_e_emlrt_marshallIn
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance, const mxArray
   *c3_b_subchartSimStateInfo, const char_T *c3_identifier);
static const mxArray *c3_f_emlrt_marshallIn
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  sf_exported_auto_initc4_testBradImitateSmile
    (chartInstance->c3_subchartSimstruct);
  _sfTime_ = sf_get_time(chartInstance->S);
  c3_subchartSimStateInfo = NULL;
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_smile = 0U;
  chartInstance->c3_is_active_c3_testBradImitateSmile = 0U;
  chartInstance->c3_is_c3_testBradImitateSmile = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_is_c3_testBradImitateSmile == c3_IN_smile) {
    sf_exported_auto_enablec4_testBradImitateSmile
      (chartInstance->c3_subchartSimstruct);
  }
}

static void disable_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_is_c3_testBradImitateSmile == c3_IN_smile) {
    sf_exported_auto_disablec4_testBradImitateSmile
      (chartInstance->c3_subchartSimstruct);
  }
}

static void c3_update_debugger_state_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_testBradImitateSmile == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testBradImitateSmile == c3_IN_smile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_c_u;
  const mxArray *c3_d_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_subchartSimStateInfo,
                sf_exported_auto_getSimstatec4_testBradImitateSmile
                (chartInstance->c3_subchartSimstruct), true);
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(3, 1), false);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_testBradImitateSmile;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_c3_testBradImitateSmile;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_u = sf_mex_dup(c3_subchartSimStateInfo);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_duplicatearraysafe(&c3_c_u), false);
  sf_mex_destroy(&c3_c_u);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_is_active_c3_testBradImitateSmile = c3_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
     "is_active_c3_testBradImitateSmile");
  chartInstance->c3_is_c3_testBradImitateSmile = c3_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_c3_testBradImitateSmile");
  sf_mex_assign(&c3_subchartSimStateInfo, c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_testBradImitateSmile(chartInstance);
  sf_exported_auto_setSimstatec4_testBradImitateSmile
    (chartInstance->c3_subchartSimstruct, sf_mex_dup(c3_subchartSimStateInfo));
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_testBradImitateSmile == c3_IN_smile) {
      chartInstance->c3_tp_smile = 1U;
    } else {
      chartInstance->c3_tp_smile = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  sf_mex_destroy(&c3_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  real_T *c3_pSmile;
  c3_pSmile = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_testBradImitateSmile(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc4_testBradImitateSmile
    (chartInstance->c3_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_pSmile, 0U);
  sf_exported_auto_activate_callc4_testBradImitateSmile
    (chartInstance->c3_subchartSimstruct);
  chartInstance->c3_sfEvent = c3_event_event;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_event,
               chartInstance->c3_sfEvent);
  sf_exported_auto_stepBuffersc4_testBradImitateSmile
    (chartInstance->c3_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_testBradImitateSmile == 0U) {
    sf_exported_auto_initBuffersc4_testBradImitateSmile
      (chartInstance->c3_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_testBradImitateSmile = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_testBradImitateSmile = c3_IN_smile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_smile = 1U;
    sf_exported_auto_enterc4_testBradImitateSmile
      (chartInstance->c3_subchartSimstruct);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    sf_exported_auto_duringc4_testBradImitateSmile
      (chartInstance->c3_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_event,
               chartInstance->c3_sfEvent);
  sf_exported_auto_deactivate_callc4_testBradImitateSmile
    (chartInstance->c3_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testBradImitateSmileMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c3_is_c3_testBradImitateSmile == c3_IN_smile) {
    sf_exported_auto_check_state_inconsistency_c4_testBradImitateSmile
      (chartInstance->c3_subchartSimstruct);
  }
}

static void initSimStructsc3_testBradImitateSmile
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance)
{
  chartInstance->c3_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "smile");
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

const mxArray *sf_c3_testBradImitateSmile_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_event;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)chartInstanceVoid;
  c3_event = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_event), &c3_thisId);
  sf_mex_destroy(&c3_event);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_b_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_smile, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_smile),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_smile);
  return c3_y;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_testBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_smile;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)chartInstanceVoid;
  c3_b_tp_smile = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_smile),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_smile);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_e_emlrt_marshallIn
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance, const mxArray
   *c3_b_subchartSimStateInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_subchartSimStateInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_subchartSimStateInfo);
  return c3_y;
}

static const mxArray *c3_f_emlrt_marshallIn
  (SFc3_testBradImitateSmileInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_testBradImitateSmileInstanceStruct
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

void sf_c3_testBradImitateSmile_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2086667581U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4010848457U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2167475985U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(689987604U);
}

mxArray *sf_c3_testBradImitateSmile_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("HSyfLWQRYcS1DBMZfqakMH");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_testBradImitateSmile_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_testBradImitateSmile_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_testBradImitateSmile(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_testBradImitateSmile\",},{M[9],M[0],T\"is_c3_testBradImitateSmile\",},{M[14],M[1],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_testBradImitateSmile_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_testBradImitateSmileInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testBradImitateSmileMachineNumber_,
           3,
           1,
           0,
           0,
           1,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testBradImitateSmileMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testBradImitateSmileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testBradImitateSmileMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,1,1,0,"pSmile");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_pSmile;
          c3_pSmile = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_pSmile);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testBradImitateSmileMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "k1d5cX5HpiEbKLF4YdGN8D";
}

static void sf_opaque_initialize_c3_testBradImitateSmile(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_testBradImitateSmileInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_testBradImitateSmile
    ((SFc3_testBradImitateSmileInstanceStruct*) chartInstanceVar);
  initialize_c3_testBradImitateSmile((SFc3_testBradImitateSmileInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_testBradImitateSmile(void *chartInstanceVar)
{
  enable_c3_testBradImitateSmile((SFc3_testBradImitateSmileInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_testBradImitateSmile(void *chartInstanceVar)
{
  disable_c3_testBradImitateSmile((SFc3_testBradImitateSmileInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_testBradImitateSmile(void *chartInstanceVar)
{
  sf_gateway_c3_testBradImitateSmile((SFc3_testBradImitateSmileInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_testBradImitateSmile
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_testBradImitateSmile
    ((SFc3_testBradImitateSmileInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_testBradImitateSmile();/* state var info */
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

extern void sf_internal_set_sim_state_c3_testBradImitateSmile(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_testBradImitateSmile();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_testBradImitateSmile((SFc3_testBradImitateSmileInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_testBradImitateSmile(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c3_testBradImitateSmile(S);
}

static void sf_opaque_set_sim_state_c3_testBradImitateSmile(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_testBradImitateSmile(S, st);
}

static void sf_opaque_terminate_c3_testBradImitateSmile(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_testBradImitateSmileInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testBradImitateSmile_optimization_info();
    }

    finalize_c3_testBradImitateSmile((SFc3_testBradImitateSmileInstanceStruct*)
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
  initSimStructsc3_testBradImitateSmile((SFc3_testBradImitateSmileInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_testBradImitateSmile(SimStruct *S)
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
    initialize_params_c3_testBradImitateSmile
      ((SFc3_testBradImitateSmileInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_testBradImitateSmile(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testBradImitateSmile_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4107163890U));
  ssSetChecksum1(S,(2175991625U));
  ssSetChecksum2(S,(15950411U));
  ssSetChecksum3(S,(2181720439U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_testBradImitateSmile(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_testBradImitateSmile(SimStruct *S)
{
  SFc3_testBradImitateSmileInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_testBradImitateSmileInstanceStruct *)utMalloc(sizeof
    (SFc3_testBradImitateSmileInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_testBradImitateSmileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_testBradImitateSmile;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_testBradImitateSmile;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_testBradImitateSmile;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_testBradImitateSmile;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_testBradImitateSmile;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_testBradImitateSmile;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_testBradImitateSmile;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_testBradImitateSmile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_testBradImitateSmile;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_testBradImitateSmile;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_testBradImitateSmile;
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

void c3_testBradImitateSmile_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_testBradImitateSmile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_testBradImitateSmile(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_testBradImitateSmile(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_testBradImitateSmile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
