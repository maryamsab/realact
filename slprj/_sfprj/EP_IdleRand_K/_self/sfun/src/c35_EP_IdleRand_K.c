/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EP_IdleRand_K_sfun.h"
#include "c35_EP_IdleRand_K.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EP_IdleRand_K_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c35_debug_family_names[4] = { "nargin", "nargout", "e",
  "notNeutral" };

/* Function Declarations */
static void initialize_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void initialize_params_c35_EP_IdleRand_K
  (SFc35_EP_IdleRand_KInstanceStruct *chartInstance);
static void enable_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void disable_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c35_update_debugger_state_c35_EP_IdleRand_K
  (SFc35_EP_IdleRand_KInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_EP_IdleRand_K
  (SFc35_EP_IdleRand_KInstanceStruct *chartInstance);
static void set_sim_state_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_st);
static void finalize_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void sf_gateway_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void initSimStructsc35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_notNeutral, const char_T *c35_identifier);
static real_T c35_b_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_c_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_d_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_EP_IdleRand_K, const char_T
  *c35_identifier);
static uint8_T c35_e_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void init_dsm_address_info(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c35_is_active_c35_EP_IdleRand_K = 0U;
}

static void initialize_params_c35_EP_IdleRand_K
  (SFc35_EP_IdleRand_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c35_update_debugger_state_c35_EP_IdleRand_K
  (SFc35_EP_IdleRand_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c35_EP_IdleRand_K
  (SFc35_EP_IdleRand_KInstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  real_T c35_hoistedGlobal;
  real_T c35_u;
  const mxArray *c35_b_y = NULL;
  uint8_T c35_b_hoistedGlobal;
  uint8_T c35_b_u;
  const mxArray *c35_c_y = NULL;
  real_T *c35_notNeutral;
  c35_notNeutral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellmatrix(2, 1), false);
  c35_hoistedGlobal = *c35_notNeutral;
  c35_u = c35_hoistedGlobal;
  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  c35_b_hoistedGlobal = chartInstance->c35_is_active_c35_EP_IdleRand_K;
  c35_b_u = c35_b_hoistedGlobal;
  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", &c35_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  sf_mex_assign(&c35_st, c35_y, false);
  return c35_st;
}

static void set_sim_state_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  real_T *c35_notNeutral;
  c35_notNeutral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c35_doneDoubleBufferReInit = true;
  c35_u = sf_mex_dup(c35_st);
  *c35_notNeutral = c35_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c35_u, 0)), "notNeutral");
  chartInstance->c35_is_active_c35_EP_IdleRand_K = c35_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 1)),
     "is_active_c35_EP_IdleRand_K");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_EP_IdleRand_K(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  real_T c35_hoistedGlobal;
  real_T c35_e;
  uint32_T c35_debug_family_var_map[4];
  real_T c35_nargin = 1.0;
  real_T c35_nargout = 1.0;
  real_T c35_notNeutral;
  real_T *c35_b_notNeutral;
  real_T *c35_b_e;
  c35_b_e = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c35_b_notNeutral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c35_sfEvent);
  chartInstance->c35_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c35_sfEvent);
  c35_hoistedGlobal = *c35_b_e;
  c35_e = c35_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 0U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 1U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_e, 2U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_notNeutral, 3U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c35_e != 6.0)) {
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 5);
    c35_notNeutral = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 7);
    c35_notNeutral = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  *c35_b_notNeutral = c35_notNeutral;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c35_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EP_IdleRand_KMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c35_b_notNeutral, 0U);
  _SFD_DATA_RANGE_CHECK(*c35_b_e, 1U);
}

static void initSimStructsc35_EP_IdleRand_K(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber)
{
  (void)c35_machineNumber;
  (void)c35_chartNumber;
  (void)c35_instanceNumber;
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc35_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static real_T c35_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_notNeutral, const char_T *c35_identifier)
{
  real_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_notNeutral),
    &c35_thisId);
  sf_mex_destroy(&c35_notNeutral);
  return c35_y;
}

static real_T c35_b_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d0, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_notNeutral;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc35_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c35_notNeutral = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_notNeutral),
    &c35_thisId);
  sf_mex_destroy(&c35_notNeutral);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

const mxArray *sf_c35_EP_IdleRand_K_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  sf_mex_assign(&c35_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c35_nameCaptureInfo;
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc35_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static int32_T c35_c_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i0, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc35_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_d_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_EP_IdleRand_K, const char_T
  *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_is_active_c35_EP_IdleRand_K), &c35_thisId);
  sf_mex_destroy(&c35_b_is_active_c35_EP_IdleRand_K);
  return c35_y;
}

static uint8_T c35_e_emlrt_marshallIn(SFc35_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void init_dsm_address_info(SFc35_EP_IdleRand_KInstanceStruct
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

void sf_c35_EP_IdleRand_K_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(123619878U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1783780523U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2679486502U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2915540305U);
}

mxArray *sf_c35_EP_IdleRand_K_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rm17tte3C08PdN1kaNbNDF");
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

mxArray *sf_c35_EP_IdleRand_K_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c35_EP_IdleRand_K_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c35_EP_IdleRand_K(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"notNeutral\",},{M[8],M[0],T\"is_active_c35_EP_IdleRand_K\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_EP_IdleRand_K_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_EP_IdleRand_KInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc35_EP_IdleRand_KInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EP_IdleRand_KMachineNumber_,
           35,
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
        init_script_number_translation(_EP_IdleRand_KMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_EP_IdleRand_KMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _EP_IdleRand_KMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"notNeutral");
          _SFD_SET_DATA_PROPS(1,1,1,0,"e");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,93);
        _SFD_CV_INIT_EML_IF(0,1,0,40,48,67,93);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c35_notNeutral;
          real_T *c35_e;
          c35_e = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c35_notNeutral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c35_notNeutral);
          _SFD_SET_DATA_VALUE_PTR(1U, c35_e);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _EP_IdleRand_KMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "i8BiCvJGkgztdHYzLrK4TD";
}

static void sf_opaque_initialize_c35_EP_IdleRand_K(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
  initialize_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_EP_IdleRand_K(void *chartInstanceVar)
{
  enable_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c35_EP_IdleRand_K(void *chartInstanceVar)
{
  disable_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c35_EP_IdleRand_K(void *chartInstanceVar)
{
  sf_gateway_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c35_EP_IdleRand_K(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c35_EP_IdleRand_K
    ((SFc35_EP_IdleRand_KInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_EP_IdleRand_K();/* state var info */
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

extern void sf_internal_set_sim_state_c35_EP_IdleRand_K(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c35_EP_IdleRand_K();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c35_EP_IdleRand_K(SimStruct* S)
{
  return sf_internal_get_sim_state_c35_EP_IdleRand_K(S);
}

static void sf_opaque_set_sim_state_c35_EP_IdleRand_K(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c35_EP_IdleRand_K(S, st);
}

static void sf_opaque_terminate_c35_EP_IdleRand_K(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_EP_IdleRand_KInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EP_IdleRand_K_optimization_info();
    }

    finalize_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
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
  initSimStructsc35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_EP_IdleRand_K(SimStruct *S)
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
    initialize_params_c35_EP_IdleRand_K((SFc35_EP_IdleRand_KInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_EP_IdleRand_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EP_IdleRand_K_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,35,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,35);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,35,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,35,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2657023289U));
  ssSetChecksum1(S,(2045612412U));
  ssSetChecksum2(S,(683244166U));
  ssSetChecksum3(S,(1601661073U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_EP_IdleRand_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_EP_IdleRand_K(SimStruct *S)
{
  SFc35_EP_IdleRand_KInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc35_EP_IdleRand_KInstanceStruct *)utMalloc(sizeof
    (SFc35_EP_IdleRand_KInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_EP_IdleRand_KInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c35_EP_IdleRand_K;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_EP_IdleRand_K;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c35_EP_IdleRand_K;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_EP_IdleRand_K;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c35_EP_IdleRand_K;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_EP_IdleRand_K;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_EP_IdleRand_K;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_EP_IdleRand_K;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_EP_IdleRand_K;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_EP_IdleRand_K;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c35_EP_IdleRand_K;
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

void c35_EP_IdleRand_K_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_EP_IdleRand_K(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_EP_IdleRand_K(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_EP_IdleRand_K(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_EP_IdleRand_K_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
