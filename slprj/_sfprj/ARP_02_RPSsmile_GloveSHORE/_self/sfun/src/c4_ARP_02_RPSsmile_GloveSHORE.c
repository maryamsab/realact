/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_GloveSHORE_sfun.h"
#include "c4_ARP_02_RPSsmile_GloveSHORE.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_GloveSHORE_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[5] = { "smile", "nargin", "nargout",
  "u", "y" };

/* Function Declarations */
static void initialize_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void initialize_params_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void enable_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void disable_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void set_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_st);
static void finalize_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void sf_gateway_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void initSimStructsc4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *
  chartInstance, const mxArray *c4_y, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_b_is_active_c4_ARP_02_RPSsmile_GloveSHORE, const char_T *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveSHORE = 0U;
}

static void initialize_params_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T *c4_d_y;
  c4_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_hoistedGlobal = *c4_d_y;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveSHORE;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_y;
  c4_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "y");
  chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveSHORE =
    c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "is_active_c4_ARP_02_RPSsmile_GloveSHORE");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_ARP_02_RPSsmile_GloveSHORE(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_u;
  uint32_T c4_debug_family_var_map[5];
  real_T c4_smile;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_y;
  real_T *c4_b_u;
  real_T *c4_b_y;
  c4_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_b_u, 0U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_u;
  c4_u = c4_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_smile, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_u, 3U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, c4_u > 10.0)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
    c4_smile = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
    c4_smile = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_y = c4_smile;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  *c4_b_y = c4_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSsmile_GloveSHOREMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c4_b_y, 1U);
}

static void initSimStructsc4_ARP_02_RPSsmile_GloveSHORE
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *
  chartInstance, const mxArray *c4_y, const char_T *c4_identifier)
{
  real_T c4_b_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId);
  sf_mex_destroy(&c4_y);
  return c4_b_y;
}

static real_T c4_b_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_y;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y;
  SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *)
    chartInstanceVoid;
  c4_y = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId);
  sf_mex_destroy(&c4_y);
  *(real_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_ARP_02_RPSsmile_GloveSHORE_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i0, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_b_is_active_c4_ARP_02_RPSsmile_GloveSHORE, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_ARP_02_RPSsmile_GloveSHORE), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_ARP_02_RPSsmile_GloveSHORE);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *
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

void sf_c4_ARP_02_RPSsmile_GloveSHORE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4034184236U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4027303412U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(812296790U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1617385634U);
}

mxArray *sf_c4_ARP_02_RPSsmile_GloveSHORE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("DtjMk7SqhwV5BFq0nnUQoE");
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

mxArray *sf_c4_ARP_02_RPSsmile_GloveSHORE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_ARP_02_RPSsmile_GloveSHORE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveSHORE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c4_ARP_02_RPSsmile_GloveSHORE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_ARP_02_RPSsmile_GloveSHORE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_GloveSHOREMachineNumber_,
           4,
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
        init_script_number_translation(_ARP_02_RPSsmile_GloveSHOREMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_GloveSHOREMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_GloveSHOREMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,83);
        _SFD_CV_INIT_EML_IF(0,1,0,30,37,51,72);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_u;
          real_T *c4_y;
          c4_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_GloveSHOREMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "PBF1XeoWbqG4ePndV3MmgF";
}

static void sf_opaque_initialize_c4_ARP_02_RPSsmile_GloveSHORE(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*) chartInstanceVar);
  initialize_c4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_ARP_02_RPSsmile_GloveSHORE(void
  *chartInstanceVar)
{
  enable_c4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_ARP_02_RPSsmile_GloveSHORE(void
  *chartInstanceVar)
{
  disable_c4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_ARP_02_RPSsmile_GloveSHORE(void
  *chartInstanceVar)
{
  sf_gateway_c4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveSHORE();/* state var info */
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

extern void sf_internal_set_sim_state_c4_ARP_02_RPSsmile_GloveSHORE(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveSHORE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_ARP_02_RPSsmile_GloveSHORE
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c4_ARP_02_RPSsmile_GloveSHORE(S);
}

static void sf_opaque_set_sim_state_c4_ARP_02_RPSsmile_GloveSHORE(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c4_ARP_02_RPSsmile_GloveSHORE(S, st);
}

static void sf_opaque_terminate_c4_ARP_02_RPSsmile_GloveSHORE(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_GloveSHORE_optimization_info();
    }

    finalize_c4_ARP_02_RPSsmile_GloveSHORE
      ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_ARP_02_RPSsmile_GloveSHORE
    ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_ARP_02_RPSsmile_GloveSHORE(SimStruct *S)
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
    initialize_params_c4_ARP_02_RPSsmile_GloveSHORE
      ((SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_ARP_02_RPSsmile_GloveSHORE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSsmile_GloveSHORE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4054421980U));
  ssSetChecksum1(S,(2415363838U));
  ssSetChecksum2(S,(3107529154U));
  ssSetChecksum3(S,(1696461864U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_ARP_02_RPSsmile_GloveSHORE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_ARP_02_RPSsmile_GloveSHORE(SimStruct *S)
{
  SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct *)utMalloc
    (sizeof(SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_ARP_02_RPSsmile_GloveSHOREInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_ARP_02_RPSsmile_GloveSHORE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_ARP_02_RPSsmile_GloveSHORE;
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

void c4_ARP_02_RPSsmile_GloveSHORE_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_ARP_02_RPSsmile_GloveSHORE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_ARP_02_RPSsmile_GloveSHORE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_ARP_02_RPSsmile_GloveSHORE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_ARP_02_RPSsmile_GloveSHORE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
