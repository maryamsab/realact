/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Pose_sfun.h"
#include "c55_Expriment_Pose.h"
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
static const char * c55_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "v1", "v2" };

/* Function Declarations */
static void initialize_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance);
static void initialize_params_c55_Expriment_Pose
  (SFc55_Expriment_PoseInstanceStruct *chartInstance);
static void enable_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance);
static void disable_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance);
static void c55_update_debugger_state_c55_Expriment_Pose
  (SFc55_Expriment_PoseInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c55_Expriment_Pose
  (SFc55_Expriment_PoseInstanceStruct *chartInstance);
static void set_sim_state_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c55_st);
static void finalize_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance);
static void sf_gateway_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance);
static void initSimStructsc55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber);
static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static real_T c55_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_v2, const char_T *c55_identifier);
static real_T c55_b_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static boolean_T c55_c_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static int32_T c55_d_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static uint8_T c55_e_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_b_is_active_c55_Expriment_Pose, const
  char_T *c55_identifier);
static uint8_T c55_f_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void init_dsm_address_info(SFc55_Expriment_PoseInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance)
{
  chartInstance->c55_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c55_is_active_c55_Expriment_Pose = 0U;
}

static void initialize_params_c55_Expriment_Pose
  (SFc55_Expriment_PoseInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c55_update_debugger_state_c55_Expriment_Pose
  (SFc55_Expriment_PoseInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c55_Expriment_Pose
  (SFc55_Expriment_PoseInstanceStruct *chartInstance)
{
  const mxArray *c55_st;
  const mxArray *c55_y = NULL;
  real_T c55_hoistedGlobal;
  real_T c55_u;
  const mxArray *c55_b_y = NULL;
  uint8_T c55_b_hoistedGlobal;
  uint8_T c55_b_u;
  const mxArray *c55_c_y = NULL;
  real_T *c55_v2;
  c55_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c55_st = NULL;
  c55_st = NULL;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_createcellmatrix(2, 1), false);
  c55_hoistedGlobal = *c55_v2;
  c55_u = c55_hoistedGlobal;
  c55_b_y = NULL;
  sf_mex_assign(&c55_b_y, sf_mex_create("y", &c55_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c55_y, 0, c55_b_y);
  c55_b_hoistedGlobal = chartInstance->c55_is_active_c55_Expriment_Pose;
  c55_b_u = c55_b_hoistedGlobal;
  c55_c_y = NULL;
  sf_mex_assign(&c55_c_y, sf_mex_create("y", &c55_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c55_y, 1, c55_c_y);
  sf_mex_assign(&c55_st, c55_y, false);
  return c55_st;
}

static void set_sim_state_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c55_st)
{
  const mxArray *c55_u;
  real_T *c55_v2;
  c55_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c55_doneDoubleBufferReInit = true;
  c55_u = sf_mex_dup(c55_st);
  *c55_v2 = c55_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c55_u,
    0)), "v2");
  chartInstance->c55_is_active_c55_Expriment_Pose = c55_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c55_u, 1)),
     "is_active_c55_Expriment_Pose");
  sf_mex_destroy(&c55_u);
  c55_update_debugger_state_c55_Expriment_Pose(chartInstance);
  sf_mex_destroy(&c55_st);
}

static void finalize_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct
  *chartInstance)
{
  real_T c55_hoistedGlobal;
  real_T c55_v1;
  uint32_T c55_debug_family_var_map[6];
  boolean_T c55_aVarTruthTableCondition_1;
  boolean_T c55_aVarTruthTableCondition_2;
  real_T c55_nargin = 1.0;
  real_T c55_nargout = 1.0;
  real_T c55_v2;
  real_T *c55_b_v2;
  real_T *c55_b_v1;
  c55_b_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c55_b_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
  chartInstance->c55_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
  c55_hoistedGlobal = *c55_b_v1;
  c55_v1 = c55_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c55_debug_family_names,
    c55_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_aVarTruthTableCondition_1, 0U,
    c55_b_sf_marshallOut, c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_aVarTruthTableCondition_2, 1U,
    c55_b_sf_marshallOut, c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargin, 2U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargout, 3U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c55_v1, 4U, c55_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_v2, 5U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 3);
  c55_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 4);
  c55_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 8);
  c55_aVarTruthTableCondition_1 = (c55_v1 > 25.0);
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 11);
  c55_aVarTruthTableCondition_2 = (c55_v1 < -25.0);
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, c55_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 14);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 24);
    c55_v2 = c55_v1;
    _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, -24);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 15);
    if (CV_EML_IF(0, 1, 1, c55_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 16);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 29);
      c55_v2 = c55_v1;
      _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, -29);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 18);
      CV_EML_FCN(0, 3);
      _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 34);
      c55_v2 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, -34);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *c55_b_v2 = c55_v2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_PoseMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c55_b_v2, 0U);
  _SFD_DATA_RANGE_CHECK(*c55_b_v1, 1U);
}

static void initSimStructsc55_Expriment_Pose(SFc55_Expriment_PoseInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber)
{
  (void)c55_machineNumber;
  (void)c55_chartNumber;
  (void)c55_instanceNumber;
}

static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  real_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(real_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static real_T c55_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_v2, const char_T *c55_identifier)
{
  real_T c55_y;
  emlrtMsgIdentifier c55_thisId;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_v2), &c55_thisId);
  sf_mex_destroy(&c55_v2);
  return c55_y;
}

static real_T c55_b_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  real_T c55_y;
  real_T c55_d0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_d0, 1, 0, 0U, 0, 0U, 0);
  c55_y = c55_d0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_v2;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  real_T c55_y;
  SFc55_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c55_v2 = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_v2), &c55_thisId);
  sf_mex_destroy(&c55_v2);
  *(real_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  boolean_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(boolean_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static boolean_T c55_c_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  boolean_T c55_y;
  boolean_T c55_b0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_b0, 1, 11, 0U, 0, 0U, 0);
  c55_y = c55_b0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_aVarTruthTableCondition_2;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  boolean_T c55_y;
  SFc55_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c55_aVarTruthTableCondition_2 = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c55_aVarTruthTableCondition_2), &c55_thisId);
  sf_mex_destroy(&c55_aVarTruthTableCondition_2);
  *(boolean_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

const mxArray *sf_c55_Expriment_Pose_get_eml_resolved_functions_info(void)
{
  const mxArray *c55_nameCaptureInfo = NULL;
  c55_nameCaptureInfo = NULL;
  sf_mex_assign(&c55_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c55_nameCaptureInfo;
}

static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(int32_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static int32_T c55_d_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  int32_T c55_y;
  int32_T c55_i0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_i0, 1, 6, 0U, 0, 0U, 0);
  c55_y = c55_i0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_b_sfEvent;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  int32_T c55_y;
  SFc55_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c55_b_sfEvent = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_sfEvent),
    &c55_thisId);
  sf_mex_destroy(&c55_b_sfEvent);
  *(int32_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

static uint8_T c55_e_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_b_is_active_c55_Expriment_Pose, const
  char_T *c55_identifier)
{
  uint8_T c55_y;
  emlrtMsgIdentifier c55_thisId;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c55_b_is_active_c55_Expriment_Pose), &c55_thisId);
  sf_mex_destroy(&c55_b_is_active_c55_Expriment_Pose);
  return c55_y;
}

static uint8_T c55_f_emlrt_marshallIn(SFc55_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  uint8_T c55_y;
  uint8_T c55_u0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_u0, 1, 3, 0U, 0, 0U, 0);
  c55_y = c55_u0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void init_dsm_address_info(SFc55_Expriment_PoseInstanceStruct
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

void sf_c55_Expriment_Pose_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4026600077U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(629412063U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(709736593U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1843946743U);
}

mxArray *sf_c55_Expriment_Pose_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("EuZRnyhPFvbAKeV9Xs3xlD");
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

mxArray *sf_c55_Expriment_Pose_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c55_Expriment_Pose_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c55_Expriment_Pose(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"v2\",},{M[8],M[0],T\"is_active_c55_Expriment_Pose\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c55_Expriment_Pose_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc55_Expriment_PoseInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc55_Expriment_PoseInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_PoseMachineNumber_,
           55,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"v2");
          _SFD_SET_DATA_PROPS(1,1,1,0,"v1");
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
        _SFD_CV_INIT_EML(0,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,364);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",364,-1,408);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",408,-1,452);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",452,-1,494);
        _SFD_CV_INIT_EML_IF(0,1,0,188,218,249,362);
        _SFD_CV_INIT_EML_IF(0,1,1,249,283,314,362);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c55_v2;
          real_T *c55_v1;
          c55_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c55_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c55_v2);
          _SFD_SET_DATA_VALUE_PTR(1U, c55_v1);
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
  return "G8dVEy14Q9jhJKpvmXcxPD";
}

static void sf_opaque_initialize_c55_Expriment_Pose(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc55_Expriment_PoseInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
  initialize_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c55_Expriment_Pose(void *chartInstanceVar)
{
  enable_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c55_Expriment_Pose(void *chartInstanceVar)
{
  disable_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c55_Expriment_Pose(void *chartInstanceVar)
{
  sf_gateway_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c55_Expriment_Pose(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c55_Expriment_Pose
    ((SFc55_Expriment_PoseInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c55_Expriment_Pose();/* state var info */
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

extern void sf_internal_set_sim_state_c55_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c55_Expriment_Pose();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c55_Expriment_Pose(SimStruct* S)
{
  return sf_internal_get_sim_state_c55_Expriment_Pose(S);
}

static void sf_opaque_set_sim_state_c55_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c55_Expriment_Pose(S, st);
}

static void sf_opaque_terminate_c55_Expriment_Pose(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc55_Expriment_PoseInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Pose_optimization_info();
    }

    finalize_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
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
  initSimStructsc55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c55_Expriment_Pose(SimStruct *S)
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
    initialize_params_c55_Expriment_Pose((SFc55_Expriment_PoseInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c55_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Pose_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      55);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,55,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,55,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,55);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,55,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,55,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,55);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2104411969U));
  ssSetChecksum1(S,(4031701563U));
  ssSetChecksum2(S,(3206155808U));
  ssSetChecksum3(S,(2273650533U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c55_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c55_Expriment_Pose(SimStruct *S)
{
  SFc55_Expriment_PoseInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc55_Expriment_PoseInstanceStruct *)utMalloc(sizeof
    (SFc55_Expriment_PoseInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc55_Expriment_PoseInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c55_Expriment_Pose;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c55_Expriment_Pose;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c55_Expriment_Pose;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c55_Expriment_Pose;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c55_Expriment_Pose;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c55_Expriment_Pose;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c55_Expriment_Pose;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c55_Expriment_Pose;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c55_Expriment_Pose;
  chartInstance->chartInfo.mdlStart = mdlStart_c55_Expriment_Pose;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c55_Expriment_Pose;
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

void c55_Expriment_Pose_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c55_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c55_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c55_Expriment_Pose(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c55_Expriment_Pose_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
