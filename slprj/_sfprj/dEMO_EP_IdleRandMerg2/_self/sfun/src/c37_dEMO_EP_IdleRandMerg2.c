/* Include files */

#include <stddef.h>
#include "blas.h"
#include "dEMO_EP_IdleRandMerg2_sfun.h"
#include "c37_dEMO_EP_IdleRandMerg2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dEMO_EP_IdleRandMerg2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c37_debug_family_names[5] = { "nargin", "nargout",
  "extrovert", "neurotic", "personality" };

/* Function Declarations */
static void initialize_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void initialize_params_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void enable_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void disable_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void c37_update_debugger_state_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void set_sim_state_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance, const mxArray
   *c37_st);
static void finalize_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void sf_gateway_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void initSimStructsc37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c37_machineNumber, uint32_T
  c37_chartNumber, uint32_T c37_instanceNumber);
static const mxArray *c37_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static real_T c37_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct
  *chartInstance, const mxArray *c37_personality, const char_T *c37_identifier);
static real_T c37_b_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId);
static void c37_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData);
static const mxArray *c37_b_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static const mxArray *c37_c_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static int32_T c37_c_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *
  chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId);
static void c37_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData);
static uint8_T c37_d_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *
  chartInstance, const mxArray *c37_b_is_active_c37_dEMO_EP_IdleRandMerg2, const
  char_T *c37_identifier);
static uint8_T c37_e_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *
  chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId);
static void init_dsm_address_info(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  chartInstance->c37_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c37_is_active_c37_dEMO_EP_IdleRandMerg2 = 0U;
}

static void initialize_params_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c37_update_debugger_state_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  const mxArray *c37_st;
  const mxArray *c37_y = NULL;
  real_T c37_hoistedGlobal;
  real_T c37_u;
  const mxArray *c37_b_y = NULL;
  uint8_T c37_b_hoistedGlobal;
  uint8_T c37_b_u;
  const mxArray *c37_c_y = NULL;
  real_T *c37_personality;
  c37_personality = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c37_st = NULL;
  c37_st = NULL;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_createcellmatrix(2, 1), false);
  c37_hoistedGlobal = *c37_personality;
  c37_u = c37_hoistedGlobal;
  c37_b_y = NULL;
  sf_mex_assign(&c37_b_y, sf_mex_create("y", &c37_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c37_y, 0, c37_b_y);
  c37_b_hoistedGlobal = chartInstance->c37_is_active_c37_dEMO_EP_IdleRandMerg2;
  c37_b_u = c37_b_hoistedGlobal;
  c37_c_y = NULL;
  sf_mex_assign(&c37_c_y, sf_mex_create("y", &c37_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c37_y, 1, c37_c_y);
  sf_mex_assign(&c37_st, c37_y, false);
  return c37_st;
}

static void set_sim_state_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance, const mxArray
   *c37_st)
{
  const mxArray *c37_u;
  real_T *c37_personality;
  c37_personality = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c37_doneDoubleBufferReInit = true;
  c37_u = sf_mex_dup(c37_st);
  *c37_personality = c37_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c37_u, 0)), "personality");
  chartInstance->c37_is_active_c37_dEMO_EP_IdleRandMerg2 =
    c37_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c37_u, 1)),
    "is_active_c37_dEMO_EP_IdleRandMerg2");
  sf_mex_destroy(&c37_u);
  c37_update_debugger_state_c37_dEMO_EP_IdleRandMerg2(chartInstance);
  sf_mex_destroy(&c37_st);
}

static void finalize_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  boolean_T c37_hoistedGlobal;
  boolean_T c37_b_hoistedGlobal;
  boolean_T c37_extrovert;
  boolean_T c37_neurotic;
  uint32_T c37_debug_family_var_map[5];
  real_T c37_nargin = 2.0;
  real_T c37_nargout = 1.0;
  real_T c37_personality;
  boolean_T *c37_b_extrovert;
  real_T *c37_b_personality;
  boolean_T *c37_b_neurotic;
  c37_b_neurotic = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c37_b_personality = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c37_b_extrovert = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c37_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c37_b_extrovert, 0U);
  chartInstance->c37_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c37_sfEvent);
  c37_hoistedGlobal = *c37_b_extrovert;
  c37_b_hoistedGlobal = *c37_b_neurotic;
  c37_extrovert = c37_hoistedGlobal;
  c37_neurotic = c37_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c37_debug_family_names,
    c37_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_nargin, 0U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_nargout, 1U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_extrovert, 2U, c37_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_neurotic, 3U, c37_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_personality, 4U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, (real_T)c37_extrovert == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 5);
    if (CV_EML_IF(0, 1, 1, (real_T)c37_neurotic == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 6);
      c37_personality = 1.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 8);
      c37_personality = 3.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 11);
    if (CV_EML_IF(0, 1, 2, (real_T)c37_neurotic == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 12);
      c37_personality = 2.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 14);
      c37_personality = 4.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  *c37_b_personality = c37_personality;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c37_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_dEMO_EP_IdleRandMerg2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c37_b_personality, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c37_b_neurotic, 2U);
}

static void initSimStructsc37_dEMO_EP_IdleRandMerg2
  (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c37_machineNumber, uint32_T
  c37_chartNumber, uint32_T c37_instanceNumber)
{
  (void)c37_machineNumber;
  (void)c37_chartNumber;
  (void)c37_instanceNumber;
}

static const mxArray *c37_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  real_T c37_u;
  const mxArray *c37_y = NULL;
  SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance;
  chartInstance = (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  c37_u = *(real_T *)c37_inData;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

static real_T c37_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct
  *chartInstance, const mxArray *c37_personality, const char_T *c37_identifier)
{
  real_T c37_y;
  emlrtMsgIdentifier c37_thisId;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_y = c37_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_personality),
    &c37_thisId);
  sf_mex_destroy(&c37_personality);
  return c37_y;
}

static real_T c37_b_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId)
{
  real_T c37_y;
  real_T c37_d0;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_u), &c37_d0, 1, 0, 0U, 0, 0U, 0);
  c37_y = c37_d0;
  sf_mex_destroy(&c37_u);
  return c37_y;
}

static void c37_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData)
{
  const mxArray *c37_personality;
  const char_T *c37_identifier;
  emlrtMsgIdentifier c37_thisId;
  real_T c37_y;
  SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance;
  chartInstance = (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *)chartInstanceVoid;
  c37_personality = sf_mex_dup(c37_mxArrayInData);
  c37_identifier = c37_varName;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_y = c37_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_personality),
    &c37_thisId);
  sf_mex_destroy(&c37_personality);
  *(real_T *)c37_outData = c37_y;
  sf_mex_destroy(&c37_mxArrayInData);
}

static const mxArray *c37_b_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  boolean_T c37_u;
  const mxArray *c37_y = NULL;
  SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance;
  chartInstance = (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  c37_u = *(boolean_T *)c37_inData;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

const mxArray *sf_c37_dEMO_EP_IdleRandMerg2_get_eml_resolved_functions_info(void)
{
  const mxArray *c37_nameCaptureInfo = NULL;
  c37_nameCaptureInfo = NULL;
  sf_mex_assign(&c37_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c37_nameCaptureInfo;
}

static const mxArray *c37_c_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  int32_T c37_u;
  const mxArray *c37_y = NULL;
  SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance;
  chartInstance = (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  c37_u = *(int32_T *)c37_inData;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

static int32_T c37_c_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *
  chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId)
{
  int32_T c37_y;
  int32_T c37_i0;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_u), &c37_i0, 1, 6, 0U, 0, 0U, 0);
  c37_y = c37_i0;
  sf_mex_destroy(&c37_u);
  return c37_y;
}

static void c37_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData)
{
  const mxArray *c37_b_sfEvent;
  const char_T *c37_identifier;
  emlrtMsgIdentifier c37_thisId;
  int32_T c37_y;
  SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance;
  chartInstance = (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *)chartInstanceVoid;
  c37_b_sfEvent = sf_mex_dup(c37_mxArrayInData);
  c37_identifier = c37_varName;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_y = c37_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_b_sfEvent),
    &c37_thisId);
  sf_mex_destroy(&c37_b_sfEvent);
  *(int32_T *)c37_outData = c37_y;
  sf_mex_destroy(&c37_mxArrayInData);
}

static uint8_T c37_d_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *
  chartInstance, const mxArray *c37_b_is_active_c37_dEMO_EP_IdleRandMerg2, const
  char_T *c37_identifier)
{
  uint8_T c37_y;
  emlrtMsgIdentifier c37_thisId;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_y = c37_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c37_b_is_active_c37_dEMO_EP_IdleRandMerg2), &c37_thisId);
  sf_mex_destroy(&c37_b_is_active_c37_dEMO_EP_IdleRandMerg2);
  return c37_y;
}

static uint8_T c37_e_emlrt_marshallIn(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *
  chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId)
{
  uint8_T c37_y;
  uint8_T c37_u0;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_u), &c37_u0, 1, 3, 0U, 0, 0U, 0);
  c37_y = c37_u0;
  sf_mex_destroy(&c37_u);
  return c37_y;
}

static void init_dsm_address_info(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct
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

void sf_c37_dEMO_EP_IdleRandMerg2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1149343897U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2342717550U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(698283266U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2025843310U);
}

mxArray *sf_c37_dEMO_EP_IdleRandMerg2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mvMGcuHSeH872pn0xeK8q");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

mxArray *sf_c37_dEMO_EP_IdleRandMerg2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c37_dEMO_EP_IdleRandMerg2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c37_dEMO_EP_IdleRandMerg2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"personality\",},{M[8],M[0],T\"is_active_c37_dEMO_EP_IdleRandMerg2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c37_dEMO_EP_IdleRandMerg2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _dEMO_EP_IdleRandMerg2MachineNumber_,
           37,
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
        init_script_number_translation(_dEMO_EP_IdleRandMerg2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_dEMO_EP_IdleRandMerg2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _dEMO_EP_IdleRandMerg2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"extrovert");
          _SFD_SET_DATA_PROPS(1,2,0,1,"personality");
          _SFD_SET_DATA_PROPS(2,1,1,0,"neurotic");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,310);
        _SFD_CV_INIT_EML_IF(0,1,0,87,103,205,310);
        _SFD_CV_INIT_EML_IF(0,1,1,108,123,161,204);
        _SFD_CV_INIT_EML_IF(0,1,2,214,229,264,306);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)c37_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          boolean_T *c37_extrovert;
          real_T *c37_personality;
          boolean_T *c37_neurotic;
          c37_neurotic = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c37_personality = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c37_extrovert = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c37_extrovert);
          _SFD_SET_DATA_VALUE_PTR(1U, c37_personality);
          _SFD_SET_DATA_VALUE_PTR(2U, c37_neurotic);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _dEMO_EP_IdleRandMerg2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "mgNqmw8cvZcbuXmBbTrp9";
}

static void sf_opaque_initialize_c37_dEMO_EP_IdleRandMerg2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c37_dEMO_EP_IdleRandMerg2
    ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*) chartInstanceVar);
  initialize_c37_dEMO_EP_IdleRandMerg2
    ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c37_dEMO_EP_IdleRandMerg2(void *chartInstanceVar)
{
  enable_c37_dEMO_EP_IdleRandMerg2((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c37_dEMO_EP_IdleRandMerg2(void *chartInstanceVar)
{
  disable_c37_dEMO_EP_IdleRandMerg2((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c37_dEMO_EP_IdleRandMerg2(void *chartInstanceVar)
{
  sf_gateway_c37_dEMO_EP_IdleRandMerg2
    ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c37_dEMO_EP_IdleRandMerg2
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c37_dEMO_EP_IdleRandMerg2
    ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c37_dEMO_EP_IdleRandMerg2();/* state var info */
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

extern void sf_internal_set_sim_state_c37_dEMO_EP_IdleRandMerg2(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c37_dEMO_EP_IdleRandMerg2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c37_dEMO_EP_IdleRandMerg2
    ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c37_dEMO_EP_IdleRandMerg2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c37_dEMO_EP_IdleRandMerg2(S);
}

static void sf_opaque_set_sim_state_c37_dEMO_EP_IdleRandMerg2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c37_dEMO_EP_IdleRandMerg2(S, st);
}

static void sf_opaque_terminate_c37_dEMO_EP_IdleRandMerg2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_dEMO_EP_IdleRandMerg2_optimization_info();
    }

    finalize_c37_dEMO_EP_IdleRandMerg2
      ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc37_dEMO_EP_IdleRandMerg2
    ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c37_dEMO_EP_IdleRandMerg2(SimStruct *S)
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
    initialize_params_c37_dEMO_EP_IdleRandMerg2
      ((SFc37_dEMO_EP_IdleRandMerg2InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c37_dEMO_EP_IdleRandMerg2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dEMO_EP_IdleRandMerg2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      37);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,37,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,37,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,37);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,37,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,37,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,37);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2027171681U));
  ssSetChecksum1(S,(1765840809U));
  ssSetChecksum2(S,(3809161513U));
  ssSetChecksum3(S,(186417858U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c37_dEMO_EP_IdleRandMerg2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c37_dEMO_EP_IdleRandMerg2(SimStruct *S)
{
  SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct *)utMalloc(sizeof
    (SFc37_dEMO_EP_IdleRandMerg2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc37_dEMO_EP_IdleRandMerg2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.mdlStart = mdlStart_c37_dEMO_EP_IdleRandMerg2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c37_dEMO_EP_IdleRandMerg2;
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

void c37_dEMO_EP_IdleRandMerg2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c37_dEMO_EP_IdleRandMerg2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c37_dEMO_EP_IdleRandMerg2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c37_dEMO_EP_IdleRandMerg2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c37_dEMO_EP_IdleRandMerg2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
