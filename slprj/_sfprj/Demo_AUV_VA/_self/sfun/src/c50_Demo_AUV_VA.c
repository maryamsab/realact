/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_AUV_VA_sfun.h"
#include "c50_Demo_AUV_VA.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_AUV_VA_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c50_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c50_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c50_IN_init                    ((uint8_T)1U)
#define c50_IN_randFace                ((uint8_T)2U)
#define c50_IN_initial                 ((uint8_T)1U)
#define c50_IN_stateFacialExpression   ((uint8_T)2U)
#define c50_IN_wait                    ((uint8_T)3U)
#define c50_IN_wait3                   ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c50_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c50_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c50_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c50_d_debug_family_names[9] = { "p", "a", "all_AUs", "c",
  "nargin", "nargout", "arousal", "valence", "eAmountFactor" };

static const char * c50_e_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c50_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c50_g_debug_family_names[5] = { "nargin", "nargout", "E",
  "AU", "L" };

static const char * c50_h_debug_family_names[12] = { "pFactor", "p", "a_factor",
  "v_factor", "c", "nargin", "nargout", "E", "AU", "arousal", "valence",
  "eAmountFactor2" };

static const char * c50_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c50_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c50_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c50_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c50_m_debug_family_names[14] = { "L", "str1", "all_AUs", "c",
  "AU", "eA", "temp", "temp2", "str2", "mystr", "nargin", "nargout", "eAmount",
  "arrBML" };

static const char * c50_n_debug_family_names[4] = { "nargin", "nargout",
  "myarr256", "mystr" };

static const char * c50_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c50_p_debug_family_names[4] = { "nargin", "nargout", "x",
  "num" };

static const char * c50_q_debug_family_names[17] = { "csum", "str1", "j", "AU",
  "eA", "c1", "c2", "temp", "temp2", "str2", "mystr", "nargin", "nargout",
  "arrAU", "eAmount", "L", "arrBML" };

static const char * c50_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c50_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c50_dataWrittenToVector[16];

/* Function Declarations */
static void initialize_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void initialize_params_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void enable_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void disable_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_update_debugger_state_c50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void set_sim_state_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_st);
static void c50_set_sim_state_side_effects_c50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void finalize_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void sf_gateway_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_enter_atomic_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_enter_internal_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_exit_internal_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_initc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void initSimStructsc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_enter_atomic_init(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_enter_atomic_randFace(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_enter_atomic_stateFacialExpression
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_b_enter_atomic_stateFacialExpression
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_encStr2Arr(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_myarr256[2000]);
static void c50_b_encStr2Arr(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_myarr256[2000]);
static real_T c50_rand(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_eml_rand_mt19937ar(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_d_state[625]);
static void c50_twister_state_vector(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_mt[625], real_T c50_seed, uint32_T c50_b_mt[625]);
static void c50_b_eml_rand_mt19937ar(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_d_state[625], uint32_T c50_e_state[625], real_T
  *c50_r);
static void c50_eml_error(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static real_T c50_randi(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_cmdBML_AU_VA(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_eAmount[15], real_T c50_arrBML[2000]);
static real_T c50_log10(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  c50_x);
static real_T c50_ceil(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  c50_x);
static void c50_eml_scalar_eg(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_b_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_c_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_d_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_e_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_f_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_g_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_h_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_i_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_j_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_k_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_l_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_m_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_n_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_o_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_fprintf(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  c50_formatSpec);
static void c50_isequal(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static real_T c50_b_fprintf(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_varargin_1);
static void c50_c_encStr2Arr(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  char_T c50_mystr_data[], int32_T c50_mystr_sizes[2], real_T c50_myarr256[2000]);
static void c50_eml_li_find(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  boolean_T c50_x[2000], int32_T c50_y_data[], int32_T *c50_y_sizes);
static int32_T c50_compute_nones(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  boolean_T c50_x[2000]);
static void c50_char(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
                     c50_varargin_1_data[], int32_T c50_varargin_1_sizes[2],
                     char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_cmdBML_AUmerg(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_arrAU[6], real_T c50_eAmount[6], real_T c50_L, real_T c50_arrBML
  [2000]);
static real_T c50_countDigits(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_x);
static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber);
static real_T c50_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_feval, const char_T *c50_identifier);
static real_T c50_b_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_c_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_strcat, const char_T *c50_identifier,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_d_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_e_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_strcat, const char_T *c50_identifier,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_f_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_g_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_poseBML, const char_T *c50_identifier,
  real_T c50_y[2000]);
static void c50_h_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[2000]);
static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static boolean_T c50_i_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_j_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[2000]);
static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_e_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_f_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_g_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_h_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_i_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_k_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_eAmountFactor, const char_T *c50_identifier,
  real_T c50_y[15]);
static void c50_l_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[15]);
static void c50_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_j_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_m_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_newBmls, const char_T *c50_identifier,
  real_T c50_y[10000]);
static void c50_n_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[10000]);
static void c50_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_k_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_l_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_o_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_AU, const char_T *c50_identifier, real_T
  c50_y[6]);
static void c50_p_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[6]);
static void c50_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_m_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2]);
static void c50_q_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2]);
static const mxArray *c50_n_sf_marshallOut(void *chartInstanceVoid, real_T
  c50_inData_data[], int32_T *c50_inData_sizes);
static void c50_r_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y_data[], int32_T *c50_y_sizes);
static void c50_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, real_T c50_outData_data[],
  int32_T *c50_outData_sizes);
static const mxArray *c50_o_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_s_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[103]);
static void c50_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_p_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_t_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[206]);
static void c50_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_q_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_u_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[306]);
static void c50_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_r_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_v_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[412]);
static void c50_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_s_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_w_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[515]);
static void c50_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_t_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_x_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[656]);
static void c50_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_u_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_y_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[759]);
static void c50_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_v_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_ab_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[862]);
static void c50_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_w_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_bb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[965]);
static void c50_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_x_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_cb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1068]);
static void c50_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_y_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_db_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1171]);
static void c50_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_eb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1474]);
static void c50_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_fb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1577]);
static void c50_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_gb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1610]);
static void c50_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_db_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_hb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1713]);
static void c50_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_fb_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2]);
static void c50_ib_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2]);
static const mxArray *c50_gb_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2]);
static void c50_jb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2]);
static void c50_info_helper(const mxArray **c50_info);
static const mxArray *c50_emlrt_marshallOut(const char * c50_u);
static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u);
static void c50_b_info_helper(const mxArray **c50_info);
static void c50_c_info_helper(const mxArray **c50_info);
static void c50_activate_secsc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_deactivate_secsc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance);
static void c50_increment_counters_secsc50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_reset_counters_secsc50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance);
static void c50_faceTwitchc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_bmlID, real_T *c50_p, real_T c50_poseBML[2000]);
static void c50_set_AU_Amountc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_arousal, real_T c50_valence, real_T
  c50_eAmountFactor[15]);
static void c50_insertQueueLowc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_bmls[10000], real_T c50_myBML[2000], real_T
  c50_newBmls[10000]);
static void c50_setAUc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_E, real_T c50_AU[6], real_T *c50_L);
static void c50_set_eAmountFactorc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_E, real_T c50_AU[6], real_T c50_arousal, real_T
  c50_valence, real_T c50_eAmountFactor2[6]);
static boolean_T c50_b_isequal(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_varargin_1[2000], real_T c50_varargin_2[2000]);
static real_T c50_abs(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
                      c50_x);
static const mxArray *c50_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int8_T c50_kb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_bb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int32_T c50_lb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_cb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static uint8_T c50_mb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_b_tp_subFaceTwitch, const char_T
  *c50_identifier);
static uint8_T c50_nb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_db_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static uint32_T c50_ob_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_b_method, const char_T *c50_identifier);
static uint32_T c50_pb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static uint32_T c50_qb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_d_state, const char_T *c50_identifier);
static uint32_T c50_rb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_sb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_d_state, const char_T *c50_identifier,
  uint32_T c50_y[625]);
static void c50_tb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  uint32_T c50_y[625]);
static void c50_ub_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_d_state, const char_T *c50_identifier,
  uint32_T c50_y[2]);
static void c50_vb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  uint32_T c50_y[2]);
static const mxArray *c50_wb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_b_setSimStateSideEffectsInfo, const char_T *
  c50_identifier);
static const mxArray *c50_xb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_updateDataWrittenToVector(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_vectorIndex);
static void c50_errorIfDataNotWrittenToFcn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_vectorIndex, uint32_T c50_dataNumber);
static void c50_b_twister_state_vector(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_mt[625], real_T c50_seed);
static real_T c50_c_eml_rand_mt19937ar(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_d_state[625]);
static void c50_b_log10(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  *c50_x);
static void c50_b_ceil(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  *c50_x);
static real_T c50_get_bmlsL(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  uint32_T c50_b);
static void c50_set_bmlsL(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  uint32_T c50_b, real_T c50_c);
static real_T *c50_access_bmlsL(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  uint32_T c50_b);
static void init_dsm_address_info(SFc50_Demo_AUV_VAInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c50_update_debugger_state_c50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  uint32_T c50_prevAniVal;
  c50_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c50_is_active_c50_Demo_AUV_VA == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 2U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_active_subFaceTwitch == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFaceTwitch == c50_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFaceTwitch == c50_IN_randFace) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_active_subFacial == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacial == c50_IN_stateFacialExpression) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacial == c50_IN_initial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacial == c50_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_active_subFacialMaryam == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacialMaryam == c50_IN_stateFacialExpression) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacialMaryam == c50_IN_initial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacialMaryam == c50_IN_wait3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c50_sfEvent);
  }

  _SFD_SET_ANIMATION(c50_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  const mxArray *c50_st;
  const mxArray *c50_y = NULL;
  int32_T c50_i0;
  real_T c50_u[15];
  const mxArray *c50_b_y = NULL;
  int32_T c50_i1;
  real_T c50_b_u[6];
  const mxArray *c50_c_y = NULL;
  int32_T c50_i2;
  real_T c50_c_u[2000];
  const mxArray *c50_d_y = NULL;
  int32_T c50_i3;
  real_T c50_d_u[6];
  const mxArray *c50_e_y = NULL;
  real_T c50_hoistedGlobal;
  real_T c50_e_u;
  const mxArray *c50_f_y = NULL;
  int32_T c50_i4;
  real_T c50_f_u[10000];
  const mxArray *c50_g_y = NULL;
  real_T c50_b_hoistedGlobal;
  real_T c50_g_u;
  const mxArray *c50_h_y = NULL;
  real_T c50_c_hoistedGlobal;
  real_T c50_h_u;
  const mxArray *c50_i_y = NULL;
  real_T c50_d_hoistedGlobal;
  real_T c50_i_u;
  const mxArray *c50_j_y = NULL;
  uint32_T c50_e_hoistedGlobal;
  uint32_T c50_j_u;
  const mxArray *c50_k_y = NULL;
  uint32_T c50_f_hoistedGlobal;
  uint32_T c50_k_u;
  const mxArray *c50_l_y = NULL;
  int32_T c50_i5;
  uint32_T c50_l_u[625];
  const mxArray *c50_m_y = NULL;
  int32_T c50_i6;
  uint32_T c50_m_u[2];
  const mxArray *c50_n_y = NULL;
  uint8_T c50_g_hoistedGlobal;
  uint8_T c50_n_u;
  const mxArray *c50_o_y = NULL;
  uint8_T c50_h_hoistedGlobal;
  uint8_T c50_o_u;
  const mxArray *c50_p_y = NULL;
  uint8_T c50_i_hoistedGlobal;
  uint8_T c50_p_u;
  const mxArray *c50_q_y = NULL;
  uint8_T c50_j_hoistedGlobal;
  uint8_T c50_q_u;
  const mxArray *c50_r_y = NULL;
  uint8_T c50_k_hoistedGlobal;
  uint8_T c50_r_u;
  const mxArray *c50_s_y = NULL;
  uint8_T c50_l_hoistedGlobal;
  uint8_T c50_s_u;
  const mxArray *c50_t_y = NULL;
  uint8_T c50_m_hoistedGlobal;
  uint8_T c50_t_u;
  const mxArray *c50_u_y = NULL;
  uint8_T c50_n_hoistedGlobal;
  uint8_T c50_u_u;
  const mxArray *c50_v_y = NULL;
  uint8_T c50_o_hoistedGlobal;
  uint8_T c50_v_u;
  const mxArray *c50_w_y = NULL;
  uint8_T c50_p_hoistedGlobal;
  uint8_T c50_w_u;
  const mxArray *c50_x_y = NULL;
  real_T (*c50_emotion_amount_factor2)[6];
  real_T (*c50_emotion_amount_factor)[15];
  c50_emotion_amount_factor2 = (real_T (*)[6])ssGetOutputPortSignal
    (chartInstance->S, 2);
  c50_emotion_amount_factor = (real_T (*)[15])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c50_st = NULL;
  c50_st = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_createcellmatrix(23, 1), false);
  for (c50_i0 = 0; c50_i0 < 15; c50_i0++) {
    c50_u[c50_i0] = (*c50_emotion_amount_factor)[c50_i0];
  }

  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 15),
                false);
  sf_mex_setcell(c50_y, 0, c50_b_y);
  for (c50_i1 = 0; c50_i1 < 6; c50_i1++) {
    c50_b_u[c50_i1] = (*c50_emotion_amount_factor2)[c50_i1];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_b_u, 0, 0U, 1U, 0U, 2, 1, 6),
                false);
  sf_mex_setcell(c50_y, 1, c50_c_y);
  for (c50_i2 = 0; c50_i2 < 2000; c50_i2++) {
    c50_c_u[c50_i2] = chartInstance->c50_BMLl[c50_i2];
  }

  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", c50_c_u, 0, 0U, 1U, 0U, 2, 2000, 1),
                false);
  sf_mex_setcell(c50_y, 2, c50_d_y);
  for (c50_i3 = 0; c50_i3 < 6; c50_i3++) {
    c50_d_u[c50_i3] = chartInstance->c50_au[c50_i3];
  }

  c50_e_y = NULL;
  sf_mex_assign(&c50_e_y, sf_mex_create("y", c50_d_u, 0, 0U, 1U, 0U, 2, 1, 6),
                false);
  sf_mex_setcell(c50_y, 3, c50_e_y);
  c50_hoistedGlobal = chartInstance->c50_au_L;
  c50_e_u = c50_hoistedGlobal;
  c50_f_y = NULL;
  sf_mex_assign(&c50_f_y, sf_mex_create("y", &c50_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 4, c50_f_y);
  for (c50_i4 = 0; c50_i4 < 10000; c50_i4++) {
    c50_f_u[c50_i4] = chartInstance->c50_newBmlsL[c50_i4];
  }

  c50_g_y = NULL;
  sf_mex_assign(&c50_g_y, sf_mex_create("y", c50_f_u, 0, 0U, 1U, 0U, 2, 2000, 5),
                false);
  sf_mex_setcell(c50_y, 5, c50_g_y);
  c50_b_hoistedGlobal = chartInstance->c50_num;
  c50_g_u = c50_b_hoistedGlobal;
  c50_h_y = NULL;
  sf_mex_assign(&c50_h_y, sf_mex_create("y", &c50_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 6, c50_h_y);
  c50_c_hoistedGlobal = chartInstance->c50_pp;
  c50_h_u = c50_c_hoistedGlobal;
  c50_i_y = NULL;
  sf_mex_assign(&c50_i_y, sf_mex_create("y", &c50_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 7, c50_i_y);
  c50_d_hoistedGlobal = chartInstance->c50_randNum;
  c50_i_u = c50_d_hoistedGlobal;
  c50_j_y = NULL;
  sf_mex_assign(&c50_j_y, sf_mex_create("y", &c50_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 8, c50_j_y);
  c50_e_hoistedGlobal = chartInstance->c50_method;
  c50_j_u = c50_e_hoistedGlobal;
  c50_k_y = NULL;
  if (!chartInstance->c50_method_not_empty) {
    sf_mex_assign(&c50_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c50_k_y, sf_mex_create("y", &c50_j_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c50_y, 9, c50_k_y);
  c50_f_hoistedGlobal = chartInstance->c50_state;
  c50_k_u = c50_f_hoistedGlobal;
  c50_l_y = NULL;
  if (!chartInstance->c50_state_not_empty) {
    sf_mex_assign(&c50_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c50_l_y, sf_mex_create("y", &c50_k_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c50_y, 10, c50_l_y);
  for (c50_i5 = 0; c50_i5 < 625; c50_i5++) {
    c50_l_u[c50_i5] = chartInstance->c50_c_state[c50_i5];
  }

  c50_m_y = NULL;
  if (!chartInstance->c50_c_state_not_empty) {
    sf_mex_assign(&c50_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c50_m_y, sf_mex_create("y", c50_l_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c50_y, 11, c50_m_y);
  for (c50_i6 = 0; c50_i6 < 2; c50_i6++) {
    c50_m_u[c50_i6] = chartInstance->c50_b_state[c50_i6];
  }

  c50_n_y = NULL;
  if (!chartInstance->c50_b_state_not_empty) {
    sf_mex_assign(&c50_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c50_n_y, sf_mex_create("y", c50_m_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c50_y, 12, c50_n_y);
  c50_g_hoistedGlobal = chartInstance->c50_is_active_c50_Demo_AUV_VA;
  c50_n_u = c50_g_hoistedGlobal;
  c50_o_y = NULL;
  sf_mex_assign(&c50_o_y, sf_mex_create("y", &c50_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 13, c50_o_y);
  c50_h_hoistedGlobal = chartInstance->c50_is_active_subFacial;
  c50_o_u = c50_h_hoistedGlobal;
  c50_p_y = NULL;
  sf_mex_assign(&c50_p_y, sf_mex_create("y", &c50_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 14, c50_p_y);
  c50_i_hoistedGlobal = chartInstance->c50_is_active_subFacialMaryam;
  c50_p_u = c50_i_hoistedGlobal;
  c50_q_y = NULL;
  sf_mex_assign(&c50_q_y, sf_mex_create("y", &c50_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 15, c50_q_y);
  c50_j_hoistedGlobal = chartInstance->c50_is_active_subFaceTwitch;
  c50_q_u = c50_j_hoistedGlobal;
  c50_r_y = NULL;
  sf_mex_assign(&c50_r_y, sf_mex_create("y", &c50_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 16, c50_r_y);
  c50_k_hoistedGlobal = chartInstance->c50_is_subFacial;
  c50_r_u = c50_k_hoistedGlobal;
  c50_s_y = NULL;
  sf_mex_assign(&c50_s_y, sf_mex_create("y", &c50_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 17, c50_s_y);
  c50_l_hoistedGlobal = chartInstance->c50_is_subFacialMaryam;
  c50_s_u = c50_l_hoistedGlobal;
  c50_t_y = NULL;
  sf_mex_assign(&c50_t_y, sf_mex_create("y", &c50_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 18, c50_t_y);
  c50_m_hoistedGlobal = chartInstance->c50_is_subFaceTwitch;
  c50_t_u = c50_m_hoistedGlobal;
  c50_u_y = NULL;
  sf_mex_assign(&c50_u_y, sf_mex_create("y", &c50_t_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 19, c50_u_y);
  c50_n_hoistedGlobal = chartInstance->c50_temporalCounter_i2;
  c50_u_u = c50_n_hoistedGlobal;
  c50_v_y = NULL;
  sf_mex_assign(&c50_v_y, sf_mex_create("y", &c50_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 20, c50_v_y);
  c50_o_hoistedGlobal = chartInstance->c50_temporalCounter_i3;
  c50_v_u = c50_o_hoistedGlobal;
  c50_w_y = NULL;
  sf_mex_assign(&c50_w_y, sf_mex_create("y", &c50_v_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 21, c50_w_y);
  c50_p_hoistedGlobal = chartInstance->c50_temporalCounter_i1;
  c50_w_u = c50_p_hoistedGlobal;
  c50_x_y = NULL;
  sf_mex_assign(&c50_x_y, sf_mex_create("y", &c50_w_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 22, c50_x_y);
  sf_mex_assign(&c50_st, c50_y, false);
  return c50_st;
}

static void set_sim_state_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_st)
{
  const mxArray *c50_u;
  real_T c50_dv0[15];
  int32_T c50_i7;
  real_T c50_dv1[6];
  int32_T c50_i8;
  real_T c50_dv2[2000];
  int32_T c50_i9;
  real_T c50_dv3[6];
  int32_T c50_i10;
  real_T c50_dv4[10000];
  int32_T c50_i11;
  uint32_T c50_uv0[625];
  int32_T c50_i12;
  uint32_T c50_uv1[2];
  int32_T c50_i13;
  real_T (*c50_emotion_amount_factor2)[6];
  real_T (*c50_emotion_amount_factor)[15];
  c50_emotion_amount_factor2 = (real_T (*)[6])ssGetOutputPortSignal
    (chartInstance->S, 2);
  c50_emotion_amount_factor = (real_T (*)[15])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c50_u = sf_mex_dup(c50_st);
  c50_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 0)),
    "emotion_amount_factor", c50_dv0);
  for (c50_i7 = 0; c50_i7 < 15; c50_i7++) {
    (*c50_emotion_amount_factor)[c50_i7] = c50_dv0[c50_i7];
  }

  c50_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 1)),
    "emotion_amount_factor2", c50_dv1);
  for (c50_i8 = 0; c50_i8 < 6; c50_i8++) {
    (*c50_emotion_amount_factor2)[c50_i8] = c50_dv1[c50_i8];
  }

  c50_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 2)),
    "BMLl", c50_dv2);
  for (c50_i9 = 0; c50_i9 < 2000; c50_i9++) {
    chartInstance->c50_BMLl[c50_i9] = c50_dv2[c50_i9];
  }

  c50_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 3)),
    "au", c50_dv3);
  for (c50_i10 = 0; c50_i10 < 6; c50_i10++) {
    chartInstance->c50_au[c50_i10] = c50_dv3[c50_i10];
  }

  chartInstance->c50_au_L = c50_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 4)), "au_L");
  c50_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 5)),
    "newBmlsL", c50_dv4);
  for (c50_i11 = 0; c50_i11 < 10000; c50_i11++) {
    chartInstance->c50_newBmlsL[c50_i11] = c50_dv4[c50_i11];
  }

  chartInstance->c50_num = c50_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 6)), "num");
  chartInstance->c50_pp = c50_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 7)), "pp");
  chartInstance->c50_randNum = c50_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 8)), "randNum");
  chartInstance->c50_method = c50_ob_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 9)), "method");
  chartInstance->c50_state = c50_qb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 10)), "state");
  c50_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 11)),
    "state", c50_uv0);
  for (c50_i12 = 0; c50_i12 < 625; c50_i12++) {
    chartInstance->c50_c_state[c50_i12] = c50_uv0[c50_i12];
  }

  c50_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 12)),
    "state", c50_uv1);
  for (c50_i13 = 0; c50_i13 < 2; c50_i13++) {
    chartInstance->c50_b_state[c50_i13] = c50_uv1[c50_i13];
  }

  chartInstance->c50_is_active_c50_Demo_AUV_VA = c50_mb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 13)),
     "is_active_c50_Demo_AUV_VA");
  chartInstance->c50_is_active_subFacial = c50_mb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 14)), "is_active_subFacial");
  chartInstance->c50_is_active_subFacialMaryam = c50_mb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 15)),
     "is_active_subFacialMaryam");
  chartInstance->c50_is_active_subFaceTwitch = c50_mb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 16)),
     "is_active_subFaceTwitch");
  chartInstance->c50_is_subFacial = c50_mb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 17)), "is_subFacial");
  chartInstance->c50_is_subFacialMaryam = c50_mb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 18)), "is_subFacialMaryam");
  chartInstance->c50_is_subFaceTwitch = c50_mb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 19)), "is_subFaceTwitch");
  chartInstance->c50_temporalCounter_i2 = c50_mb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 20)), "temporalCounter_i2");
  chartInstance->c50_temporalCounter_i3 = c50_mb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 21)), "temporalCounter_i3");
  chartInstance->c50_temporalCounter_i1 = c50_mb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 22)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c50_setSimStateSideEffectsInfo,
                c50_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
                  (c50_u, 23)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c50_u);
  chartInstance->c50_doSetSimStateSideEffects = 1U;
  c50_update_debugger_state_c50_Demo_AUV_VA(chartInstance);
  sf_mex_destroy(&c50_st);
}

static void c50_set_sim_state_side_effects_c50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  if (chartInstance->c50_doSetSimStateSideEffects != 0) {
    if (chartInstance->c50_is_active_subFacial == 1U) {
      chartInstance->c50_tp_subFacial = 1U;
    } else {
      chartInstance->c50_tp_subFacial = 0U;
    }

    if (chartInstance->c50_is_subFacial == c50_IN_initial) {
      chartInstance->c50_tp_initial = 1U;
    } else {
      chartInstance->c50_tp_initial = 0U;
    }

    if (chartInstance->c50_is_subFacial == c50_IN_stateFacialExpression) {
      chartInstance->c50_tp_stateFacialExpression = 1U;
    } else {
      chartInstance->c50_tp_stateFacialExpression = 0U;
    }

    if (chartInstance->c50_is_subFacial == c50_IN_wait) {
      chartInstance->c50_tp_wait = 1U;
      if (sf_mex_sub(chartInstance->c50_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c50_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c50_tp_wait = 0U;
    }

    if (chartInstance->c50_is_active_subFacialMaryam == 1U) {
      chartInstance->c50_tp_subFacialMaryam = 1U;
    } else {
      chartInstance->c50_tp_subFacialMaryam = 0U;
    }

    if (chartInstance->c50_is_subFacialMaryam == c50_IN_initial) {
      chartInstance->c50_b_tp_initial = 1U;
    } else {
      chartInstance->c50_b_tp_initial = 0U;
    }

    if (chartInstance->c50_is_subFacialMaryam == c50_IN_stateFacialExpression) {
      chartInstance->c50_b_tp_stateFacialExpression = 1U;
    } else {
      chartInstance->c50_b_tp_stateFacialExpression = 0U;
    }

    if (chartInstance->c50_is_subFacialMaryam == c50_IN_wait3) {
      chartInstance->c50_tp_wait3 = 1U;
      if (sf_mex_sub(chartInstance->c50_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c50_temporalCounter_i3 = 0U;
      }
    } else {
      chartInstance->c50_tp_wait3 = 0U;
    }

    if (chartInstance->c50_is_active_subFaceTwitch == 1U) {
      chartInstance->c50_tp_subFaceTwitch = 1U;
    } else {
      chartInstance->c50_tp_subFaceTwitch = 0U;
    }

    if (chartInstance->c50_is_subFaceTwitch == c50_IN_init) {
      chartInstance->c50_tp_init = 1U;
      if (sf_mex_sub(chartInstance->c50_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c50_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c50_tp_init = 0U;
    }

    if (chartInstance->c50_is_subFaceTwitch == c50_IN_randFace) {
      chartInstance->c50_tp_randFace = 1U;
      if (sf_mex_sub(chartInstance->c50_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c50_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c50_tp_randFace = 0U;
    }

    chartInstance->c50_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c50_setSimStateSideEffectsInfo);
}

static void sf_gateway_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  c50_set_sim_state_side_effects_c50_Demo_AUV_VA(chartInstance);
}

static void c50_enter_atomic_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 2U, chartInstance->c50_sfEvent);
  chartInstance->c50_is_active_c50_Demo_AUV_VA = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c50_sfEvent);
}

static void c50_enter_internal_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  uint32_T c50_debug_family_var_map[2];
  real_T c50_nargin = 0.0;
  real_T c50_nargout = 0.0;
  int32_T c50_i14;
  int32_T c50_i15;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c50_sfEvent);
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_active_subFacial = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c50_sfEvent);
  chartInstance->c50_tp_subFacial = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c50_sfEvent);
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_subFacial = c50_IN_initial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
  chartInstance->c50_tp_initial = 1U;
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_active_subFacialMaryam = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c50_sfEvent);
  chartInstance->c50_tp_subFacialMaryam = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c50_sfEvent);
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_subFacialMaryam = c50_IN_initial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c50_sfEvent);
  chartInstance->c50_b_tp_initial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c50_r_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  for (c50_i14 = 0; c50_i14 < 6; c50_i14++) {
    chartInstance->c50_au[c50_i14] = 0.0;
  }

  c50_updateDataWrittenToVector(chartInstance, 5U);
  for (c50_i15 = 0; c50_i15 < 6; c50_i15++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_au[c50_i15], 9U);
  }

  chartInstance->c50_au_L = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c50_au_L, 8U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_active_subFaceTwitch = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
  chartInstance->c50_tp_subFaceTwitch = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c50_sfEvent);
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_subFaceTwitch = c50_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
  chartInstance->c50_temporalCounter_i1 = 0U;
  chartInstance->c50_tp_init = 1U;
  c50_enter_atomic_init(chartInstance);
}

static void c50_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  uint32_T c50_debug_family_var_map[3];
  real_T c50_nargin = 0.0;
  real_T c50_nargout = 1.0;
  boolean_T c50_out;
  real_T c50_b_nargin = 0.0;
  real_T c50_b_nargout = 1.0;
  boolean_T c50_b_out;
  real_T c50_c_nargin = 0.0;
  real_T c50_c_nargout = 1.0;
  boolean_T c50_c_out;
  real_T c50_d_nargin = 0.0;
  real_T c50_d_nargout = 1.0;
  boolean_T c50_d_out;
  real_T c50_e_nargin = 0.0;
  real_T c50_e_nargout = 1.0;
  boolean_T c50_e_out;
  real_T c50_f_nargin = 0.0;
  real_T c50_f_nargout = 1.0;
  boolean_T c50_f_out;
  real_T *c50_inA;
  c50_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c50_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_isStable = true;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c50_sfEvent);
  switch (chartInstance->c50_is_subFacial) {
   case c50_IN_initial:
    CV_STATE_EVAL(8, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c50_sfEvent);
    chartInstance->c50_tp_initial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
    chartInstance->c50_isStable = false;
    chartInstance->c50_is_subFacial = c50_IN_stateFacialExpression;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c50_sfEvent);
    chartInstance->c50_tp_stateFacialExpression = 1U;
    c50_enter_atomic_stateFacialExpression(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_stateFacialExpression:
    CV_STATE_EVAL(8, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c50_sfEvent);
    chartInstance->c50_tp_stateFacialExpression = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c50_sfEvent);
    chartInstance->c50_isStable = false;
    chartInstance->c50_is_subFacial = c50_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c50_sfEvent);
    chartInstance->c50_temporalCounter_i2 = 0U;
    chartInstance->c50_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_wait:
    CV_STATE_EVAL(8, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c50_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c50_v_debug_family_names,
      c50_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_out, 2U, c50_c_sf_marshallOut,
      c50_c_sf_marshallIn);
    c50_out = CV_EML_IF(3, 0, 0, (chartInstance->c50_sfEvent == c50_event_secs) &&
                        (chartInstance->c50_temporalCounter_i2 >= 7));
    _SFD_SYMBOL_SCOPE_POP();
    if (c50_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
      chartInstance->c50_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c50_sfEvent);
      chartInstance->c50_isStable = false;
      chartInstance->c50_is_subFacial = c50_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c50_sfEvent);
      chartInstance->c50_tp_stateFacialExpression = 1U;
      c50_enter_atomic_stateFacialExpression(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c50_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(8, 0, 0);
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c50_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c50_sfEvent);
  switch (chartInstance->c50_is_subFacialMaryam) {
   case c50_IN_initial:
    CV_STATE_EVAL(12, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c50_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c50_w_debug_family_names,
      c50_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_nargin, 0U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_nargout, 1U,
      c50_b_sf_marshallOut, c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_out, 2U, c50_c_sf_marshallOut,
      c50_c_sf_marshallIn);
    c50_b_out = CV_EML_IF(5, 0, 0, *c50_inA == -1000.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c50_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
      chartInstance->c50_b_tp_initial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c50_sfEvent);
      chartInstance->c50_isStable = false;
      chartInstance->c50_is_subFacialMaryam = c50_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c50_sfEvent);
      chartInstance->c50_b_tp_stateFacialExpression = 1U;
      c50_b_enter_atomic_stateFacialExpression(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c50_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_stateFacialExpression:
    CV_STATE_EVAL(12, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c50_sfEvent);
    chartInstance->c50_b_tp_stateFacialExpression = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c50_sfEvent);
    chartInstance->c50_isStable = false;
    chartInstance->c50_is_subFacialMaryam = c50_IN_wait3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c50_sfEvent);
    chartInstance->c50_temporalCounter_i3 = 0U;
    chartInstance->c50_tp_wait3 = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_wait3:
    CV_STATE_EVAL(12, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 chartInstance->c50_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c50_x_debug_family_names,
      c50_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c_nargin, 0U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c_nargout, 1U,
      c50_b_sf_marshallOut, c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c_out, 2U, c50_c_sf_marshallOut,
      c50_c_sf_marshallIn);
    c50_c_out = CV_EML_IF(6, 0, 0, (chartInstance->c50_sfEvent == c50_event_secs)
                          && (chartInstance->c50_temporalCounter_i3 >= 7));
    _SFD_SYMBOL_SCOPE_POP();
    if (c50_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
      chartInstance->c50_tp_wait3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c50_sfEvent);
      chartInstance->c50_isStable = false;
      chartInstance->c50_is_subFacialMaryam = c50_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c50_sfEvent);
      chartInstance->c50_b_tp_stateFacialExpression = 1U;
      c50_b_enter_atomic_stateFacialExpression(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                   chartInstance->c50_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(12, 0, 0);
    chartInstance->c50_is_subFacialMaryam = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c50_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c50_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c50_sfEvent);
  switch (chartInstance->c50_is_subFaceTwitch) {
   case c50_IN_init:
    CV_STATE_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                 chartInstance->c50_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c50_s_debug_family_names,
      c50_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_d_nargin, 0U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_d_nargout, 1U,
      c50_b_sf_marshallOut, c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_d_out, 2U, c50_c_sf_marshallOut,
      c50_c_sf_marshallIn);
    c50_errorIfDataNotWrittenToFcn(chartInstance, 8U, 13U);
    c50_d_out = CV_EML_IF(9, 0, 0, chartInstance->c50_num > 100.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c50_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
      chartInstance->c50_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
      chartInstance->c50_isStable = false;
      chartInstance->c50_is_subFaceTwitch = c50_IN_randFace;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c50_sfEvent);
      chartInstance->c50_temporalCounter_i1 = 0U;
      chartInstance->c50_tp_randFace = 1U;
      c50_enter_atomic_randFace(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c50_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c50_u_debug_family_names,
        c50_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_e_nargin, 0U,
        c50_b_sf_marshallOut, c50_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_e_nargout, 1U,
        c50_b_sf_marshallOut, c50_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_e_out, 2U, c50_c_sf_marshallOut,
        c50_c_sf_marshallIn);
      c50_e_out = CV_EML_IF(11, 0, 0, (chartInstance->c50_sfEvent ==
        c50_event_secs) && (chartInstance->c50_temporalCounter_i1 >= 5));
      _SFD_SYMBOL_SCOPE_POP();
      if (c50_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c50_sfEvent);
        chartInstance->c50_tp_init = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
        chartInstance->c50_isStable = false;
        chartInstance->c50_is_subFaceTwitch = c50_IN_init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
        chartInstance->c50_temporalCounter_i1 = 0U;
        chartInstance->c50_tp_init = 1U;
        c50_enter_atomic_init(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c50_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_randFace:
    CV_STATE_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c50_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c50_t_debug_family_names,
      c50_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_f_nargin, 0U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_f_nargout, 1U,
      c50_b_sf_marshallOut, c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_f_out, 2U, c50_c_sf_marshallOut,
      c50_c_sf_marshallIn);
    c50_f_out = CV_EML_IF(10, 0, 0, (chartInstance->c50_sfEvent ==
      c50_event_secs) && (chartInstance->c50_temporalCounter_i1 >= 3));
    _SFD_SYMBOL_SCOPE_POP();
    if (c50_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c50_sfEvent);
      chartInstance->c50_tp_randFace = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c50_sfEvent);
      chartInstance->c50_isStable = false;
      chartInstance->c50_is_subFaceTwitch = c50_IN_init;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
      chartInstance->c50_temporalCounter_i1 = 0U;
      chartInstance->c50_tp_init = 1U;
      c50_enter_atomic_init(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c50_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 0, 0);
    chartInstance->c50_is_subFaceTwitch = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c50_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c50_sfEvent);
}

static void c50_exit_internal_c50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c50_is_subFaceTwitch) {
   case c50_IN_init:
    CV_STATE_EVAL(5, 1, 1);
    chartInstance->c50_tp_init = 0U;
    chartInstance->c50_is_subFaceTwitch = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_randFace:
    CV_STATE_EVAL(5, 1, 2);
    chartInstance->c50_tp_randFace = 0U;
    chartInstance->c50_is_subFaceTwitch = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 1, 0);
    chartInstance->c50_is_subFaceTwitch = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c50_sfEvent);
    break;
  }

  chartInstance->c50_tp_subFaceTwitch = 0U;
  chartInstance->c50_is_active_subFaceTwitch = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
  switch (chartInstance->c50_is_subFacialMaryam) {
   case c50_IN_initial:
    CV_STATE_EVAL(12, 1, 1);
    chartInstance->c50_b_tp_initial = 0U;
    chartInstance->c50_is_subFacialMaryam = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_stateFacialExpression:
    CV_STATE_EVAL(12, 1, 2);
    chartInstance->c50_b_tp_stateFacialExpression = 0U;
    chartInstance->c50_is_subFacialMaryam = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_wait3:
    CV_STATE_EVAL(12, 1, 3);
    chartInstance->c50_tp_wait3 = 0U;
    chartInstance->c50_is_subFacialMaryam = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(12, 1, 0);
    chartInstance->c50_is_subFacialMaryam = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c50_sfEvent);
    break;
  }

  chartInstance->c50_tp_subFacialMaryam = 0U;
  chartInstance->c50_is_active_subFacialMaryam = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c50_sfEvent);
  switch (chartInstance->c50_is_subFacial) {
   case c50_IN_initial:
    CV_STATE_EVAL(8, 1, 1);
    chartInstance->c50_tp_initial = 0U;
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_stateFacialExpression:
    CV_STATE_EVAL(8, 1, 2);
    chartInstance->c50_tp_stateFacialExpression = 0U;
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_wait:
    CV_STATE_EVAL(8, 1, 3);
    chartInstance->c50_tp_wait = 0U;
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(8, 1, 0);
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c50_sfEvent);
    break;
  }

  chartInstance->c50_tp_subFacial = 0U;
  chartInstance->c50_is_active_subFacial = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c50_sfEvent);
}

static void c50_initc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_method_not_empty = false;
  chartInstance->c50_state_not_empty = false;
  chartInstance->c50_b_state_not_empty = false;
  chartInstance->c50_c_state_not_empty = false;
  chartInstance->c50_doSetSimStateSideEffects = 0U;
  chartInstance->c50_setSimStateSideEffectsInfo = NULL;
  chartInstance->c50_is_active_subFaceTwitch = 0U;
  chartInstance->c50_is_subFaceTwitch = c50_IN_NO_ACTIVE_CHILD;
  chartInstance->c50_tp_subFaceTwitch = 0U;
  chartInstance->c50_tp_init = 0U;
  chartInstance->c50_temporalCounter_i1 = 0U;
  chartInstance->c50_tp_randFace = 0U;
  chartInstance->c50_temporalCounter_i1 = 0U;
  chartInstance->c50_is_active_subFacial = 0U;
  chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
  chartInstance->c50_tp_subFacial = 0U;
  chartInstance->c50_tp_initial = 0U;
  chartInstance->c50_tp_stateFacialExpression = 0U;
  chartInstance->c50_tp_wait = 0U;
  chartInstance->c50_temporalCounter_i2 = 0U;
  chartInstance->c50_is_active_subFacialMaryam = 0U;
  chartInstance->c50_is_subFacialMaryam = c50_IN_NO_ACTIVE_CHILD;
  chartInstance->c50_tp_subFacialMaryam = 0U;
  chartInstance->c50_b_tp_initial = 0U;
  chartInstance->c50_b_tp_stateFacialExpression = 0U;
  chartInstance->c50_tp_wait3 = 0U;
  chartInstance->c50_temporalCounter_i3 = 0U;
  chartInstance->c50_is_active_c50_Demo_AUV_VA = 0U;
}

static void initSimStructsc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c50_enter_atomic_init(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  uint32_T c50_debug_family_var_map[2];
  real_T c50_nargin = 0.0;
  real_T c50_nargout = 0.0;
  real_T c50_r;
  real_T c50_x;
  real_T c50_b_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c50_i_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  c50_r = c50_rand(chartInstance);
  c50_x = c50_r * 100.0;
  c50_b_x = c50_x;
  c50_b_x = muDoubleScalarFloor(c50_b_x);
  c50_r = 1.0 + c50_b_x;
  chartInstance->c50_num = c50_r;
  c50_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c50_num, 13U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_enter_atomic_randFace(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  uint32_T c50_debug_family_var_map[2];
  real_T c50_nargin = 0.0;
  real_T c50_nargout = 0.0;
  real_T c50_b_BMLl[2000];
  real_T c50_b_pp;
  int32_T c50_i16;
  real_T c50_c_BMLl[2000];
  int32_T c50_i17;
  int32_T c50_i18;
  int32_T c50_i19;
  static real_T c50_dv5[10000];
  int32_T c50_i20;
  real_T c50_dv6[2000];
  static real_T c50_dv7[10000];
  int32_T c50_i21;
  int32_T c50_i22;
  int32_T c50_i23;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c50_j_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  chartInstance->c50_randNum = c50_randi(chartInstance);
  c50_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c50_randNum, 11U);
  c50_errorIfDataNotWrittenToFcn(chartInstance, 6U, 11U);
  c50_faceTwitchc50_Demo_AUV_VA(chartInstance, chartInstance->c50_randNum,
    &c50_b_pp, c50_b_BMLl);
  for (c50_i16 = 0; c50_i16 < 2000; c50_i16++) {
    c50_c_BMLl[c50_i16] = c50_b_BMLl[c50_i16];
  }

  chartInstance->c50_pp = 3.0;
  c50_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c50_pp, 12U);
  for (c50_i17 = 0; c50_i17 < 2000; c50_i17++) {
    chartInstance->c50_BMLl[c50_i17] = c50_c_BMLl[c50_i17];
  }

  c50_updateDataWrittenToVector(chartInstance, 0U);
  for (c50_i18 = 0; c50_i18 < 2000; c50_i18++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_BMLl[c50_i18], 1U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
  for (c50_i19 = 0; c50_i19 < 10000; c50_i19++) {
    c50_dv5[c50_i19] = c50_get_bmlsL(chartInstance, c50_i19);
  }

  for (c50_i20 = 0; c50_i20 < 2000; c50_i20++) {
    c50_dv6[c50_i20] = chartInstance->c50_BMLl[c50_i20];
  }

  c50_insertQueueLowc50_Demo_AUV_VA(chartInstance, c50_dv5, c50_dv6, c50_dv7);
  for (c50_i21 = 0; c50_i21 < 10000; c50_i21++) {
    chartInstance->c50_newBmlsL[c50_i21] = c50_dv7[c50_i21];
  }

  c50_updateDataWrittenToVector(chartInstance, 1U);
  for (c50_i22 = 0; c50_i22 < 10000; c50_i22++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_newBmlsL[c50_i22], 2U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
  for (c50_i23 = 0; c50_i23 < 10000; c50_i23++) {
    c50_set_bmlsL(chartInstance, c50_i23, chartInstance->c50_newBmlsL[c50_i23]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_enter_atomic_stateFacialExpression
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  uint32_T c50_debug_family_var_map[2];
  real_T c50_nargin = 0.0;
  real_T c50_nargout = 0.0;
  real_T c50_dv8[15];
  int32_T c50_i24;
  int32_T c50_i25;
  int32_T c50_i26;
  real_T c50_dv9[15];
  real_T c50_dv10[2000];
  int32_T c50_i27;
  int32_T c50_i28;
  int32_T c50_i29;
  static real_T c50_dv11[10000];
  int32_T c50_i30;
  real_T c50_dv12[2000];
  static real_T c50_dv13[10000];
  int32_T c50_i31;
  int32_T c50_i32;
  int32_T c50_i33;
  int32_T c50_i34;
  real_T c50_myarr256[2000];
  uint32_T c50_b_debug_family_var_map[4];
  real_T c50_b_nargin = 1.0;
  real_T c50_b_nargout = 1.0;
  int32_T c50_mystr_sizes[2];
  char_T c50_mystr_data[2000];
  int32_T c50_i35;
  boolean_T c50_b_myarr256[2000];
  int32_T c50_tmp_sizes;
  int32_T c50_tmp_data[2000];
  int32_T c50_myarr256_sizes[2];
  int32_T c50_loop_ub;
  int32_T c50_i36;
  real_T c50_myarr256_data[2000];
  int32_T c50_b_tmp_sizes[2];
  char_T c50_b_tmp_data[2000];
  int32_T c50_mystr;
  int32_T c50_b_mystr;
  int32_T c50_b_loop_ub;
  int32_T c50_i37;
  int32_T c50_u_sizes[2];
  int32_T c50_u;
  int32_T c50_b_u;
  int32_T c50_c_loop_ub;
  int32_T c50_i38;
  char_T c50_u_data[2000];
  const mxArray *c50_y = NULL;
  real_T *c50_inA;
  real_T *c50_inV;
  real_T (*c50_emotion_amount_factor)[15];
  c50_emotion_amount_factor = (real_T (*)[15])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c50_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c50_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c50_k_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  c50_set_AU_Amountc50_Demo_AUV_VA(chartInstance, *c50_inA, *c50_inV, c50_dv8);
  for (c50_i24 = 0; c50_i24 < 15; c50_i24++) {
    (*c50_emotion_amount_factor)[c50_i24] = c50_dv8[c50_i24];
  }

  c50_updateDataWrittenToVector(chartInstance, 2U);
  for (c50_i25 = 0; c50_i25 < 15; c50_i25++) {
    _SFD_DATA_RANGE_CHECK((*c50_emotion_amount_factor)[c50_i25], 5U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U);
  for (c50_i26 = 0; c50_i26 < 15; c50_i26++) {
    c50_dv9[c50_i26] = (*c50_emotion_amount_factor)[c50_i26];
  }

  c50_cmdBML_AU_VA(chartInstance, c50_dv9, c50_dv10);
  for (c50_i27 = 0; c50_i27 < 2000; c50_i27++) {
    chartInstance->c50_BMLl[c50_i27] = c50_dv10[c50_i27];
  }

  c50_updateDataWrittenToVector(chartInstance, 0U);
  for (c50_i28 = 0; c50_i28 < 2000; c50_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_BMLl[c50_i28], 1U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
  for (c50_i29 = 0; c50_i29 < 10000; c50_i29++) {
    c50_dv11[c50_i29] = c50_get_bmlsL(chartInstance, c50_i29);
  }

  for (c50_i30 = 0; c50_i30 < 2000; c50_i30++) {
    c50_dv12[c50_i30] = chartInstance->c50_BMLl[c50_i30];
  }

  c50_insertQueueLowc50_Demo_AUV_VA(chartInstance, c50_dv11, c50_dv12, c50_dv13);
  for (c50_i31 = 0; c50_i31 < 10000; c50_i31++) {
    chartInstance->c50_newBmlsL[c50_i31] = c50_dv13[c50_i31];
  }

  c50_updateDataWrittenToVector(chartInstance, 1U);
  for (c50_i32 = 0; c50_i32 < 10000; c50_i32++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_newBmlsL[c50_i32], 2U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
  for (c50_i33 = 0; c50_i33 < 10000; c50_i33++) {
    c50_set_bmlsL(chartInstance, c50_i33, chartInstance->c50_newBmlsL[c50_i33]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
  for (c50_i34 = 0; c50_i34 < 2000; c50_i34++) {
    c50_myarr256[c50_i34] = chartInstance->c50_BMLl[c50_i34];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c50_n_debug_family_names,
    c50_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_myarr256, 2U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_mystr_data, (const int32_T *)
    &c50_mystr_sizes, NULL, 0, 3, (void *)c50_fb_sf_marshallOut, (void *)
    c50_y_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c50_sfEvent, 3);
  for (c50_i35 = 0; c50_i35 < 2000; c50_i35++) {
    c50_b_myarr256[c50_i35] = (c50_myarr256[c50_i35] != 0.0);
  }

  c50_eml_li_find(chartInstance, c50_b_myarr256, c50_tmp_data, &c50_tmp_sizes);
  c50_myarr256_sizes[0] = 1;
  c50_myarr256_sizes[1] = c50_tmp_sizes;
  c50_loop_ub = c50_tmp_sizes - 1;
  for (c50_i36 = 0; c50_i36 <= c50_loop_ub; c50_i36++) {
    c50_myarr256_data[c50_myarr256_sizes[0] * c50_i36] =
      c50_myarr256[c50_tmp_data[c50_i36] - 1];
  }

  c50_char(chartInstance, c50_myarr256_data, c50_myarr256_sizes, c50_b_tmp_data,
           c50_b_tmp_sizes);
  c50_mystr_sizes[0] = 1;
  c50_mystr_sizes[1] = c50_b_tmp_sizes[1];
  c50_mystr = c50_mystr_sizes[0];
  c50_b_mystr = c50_mystr_sizes[1];
  c50_b_loop_ub = c50_b_tmp_sizes[0] * c50_b_tmp_sizes[1] - 1;
  for (c50_i37 = 0; c50_i37 <= c50_b_loop_ub; c50_i37++) {
    c50_mystr_data[c50_i37] = c50_b_tmp_data[c50_i37];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c50_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c50_u_sizes[0] = 1;
  c50_u_sizes[1] = c50_mystr_sizes[1];
  c50_u = c50_u_sizes[0];
  c50_b_u = c50_u_sizes[1];
  c50_c_loop_ub = c50_mystr_sizes[0] * c50_mystr_sizes[1] - 1;
  for (c50_i38 = 0; c50_i38 <= c50_c_loop_ub; c50_i38++) {
    c50_u_data[c50_i38] = c50_mystr_data[c50_i38];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 10, 0U, 1U, 0U, 2,
    c50_u_sizes[0], c50_u_sizes[1]), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c50_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_b_enter_atomic_stateFacialExpression
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  uint32_T c50_debug_family_var_map[2];
  real_T c50_nargin = 0.0;
  real_T c50_nargout = 0.0;
  real_T c50_b_au_L;
  real_T c50_dv14[6];
  int32_T c50_i39;
  int32_T c50_i40;
  int32_T c50_i41;
  real_T c50_dv15[6];
  real_T c50_dv16[6];
  int32_T c50_i42;
  int32_T c50_i43;
  int32_T c50_i44;
  real_T c50_dv17[6];
  int32_T c50_i45;
  real_T c50_dv18[6];
  real_T c50_dv19[2000];
  int32_T c50_i46;
  int32_T c50_i47;
  int32_T c50_i48;
  static real_T c50_dv20[10000];
  int32_T c50_i49;
  real_T c50_dv21[2000];
  static real_T c50_dv22[10000];
  int32_T c50_i50;
  int32_T c50_i51;
  int32_T c50_i52;
  real_T *c50_internalE;
  real_T *c50_inA;
  real_T *c50_inV;
  real_T (*c50_emotion_amount_factor2)[6];
  c50_emotion_amount_factor2 = (real_T (*)[6])ssGetOutputPortSignal
    (chartInstance->S, 2);
  c50_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c50_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c50_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c50_o_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  c50_setAUc50_Demo_AUV_VA(chartInstance, *c50_internalE, c50_dv14, &c50_b_au_L);
  for (c50_i39 = 0; c50_i39 < 6; c50_i39++) {
    chartInstance->c50_au[c50_i39] = c50_dv14[c50_i39];
  }

  c50_updateDataWrittenToVector(chartInstance, 5U);
  for (c50_i40 = 0; c50_i40 < 6; c50_i40++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_au[c50_i40], 9U);
  }

  chartInstance->c50_au_L = c50_b_au_L;
  c50_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c50_au_L, 8U);
  c50_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
  for (c50_i41 = 0; c50_i41 < 6; c50_i41++) {
    c50_dv15[c50_i41] = chartInstance->c50_au[c50_i41];
  }

  c50_set_eAmountFactorc50_Demo_AUV_VA(chartInstance, *c50_internalE, c50_dv15, *
    c50_inA, *c50_inV, c50_dv16);
  for (c50_i42 = 0; c50_i42 < 6; c50_i42++) {
    (*c50_emotion_amount_factor2)[c50_i42] = c50_dv16[c50_i42];
  }

  c50_updateDataWrittenToVector(chartInstance, 3U);
  for (c50_i43 = 0; c50_i43 < 6; c50_i43++) {
    _SFD_DATA_RANGE_CHECK((*c50_emotion_amount_factor2)[c50_i43], 7U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
  c50_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
  c50_errorIfDataNotWrittenToFcn(chartInstance, 4U, 8U);
  for (c50_i44 = 0; c50_i44 < 6; c50_i44++) {
    c50_dv17[c50_i44] = chartInstance->c50_au[c50_i44];
  }

  for (c50_i45 = 0; c50_i45 < 6; c50_i45++) {
    c50_dv18[c50_i45] = (*c50_emotion_amount_factor2)[c50_i45];
  }

  c50_cmdBML_AUmerg(chartInstance, c50_dv17, c50_dv18, chartInstance->c50_au_L,
                    c50_dv19);
  for (c50_i46 = 0; c50_i46 < 2000; c50_i46++) {
    chartInstance->c50_BMLl[c50_i46] = c50_dv19[c50_i46];
  }

  c50_updateDataWrittenToVector(chartInstance, 0U);
  for (c50_i47 = 0; c50_i47 < 2000; c50_i47++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_BMLl[c50_i47], 1U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
  for (c50_i48 = 0; c50_i48 < 10000; c50_i48++) {
    c50_dv20[c50_i48] = c50_get_bmlsL(chartInstance, c50_i48);
  }

  for (c50_i49 = 0; c50_i49 < 2000; c50_i49++) {
    c50_dv21[c50_i49] = chartInstance->c50_BMLl[c50_i49];
  }

  c50_insertQueueLowc50_Demo_AUV_VA(chartInstance, c50_dv20, c50_dv21, c50_dv22);
  for (c50_i50 = 0; c50_i50 < 10000; c50_i50++) {
    chartInstance->c50_newBmlsL[c50_i50] = c50_dv22[c50_i50];
  }

  c50_updateDataWrittenToVector(chartInstance, 1U);
  for (c50_i51 = 0; c50_i51 < 10000; c50_i51++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c50_newBmlsL[c50_i51], 2U);
  }

  c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
  for (c50_i52 = 0; c50_i52 < 10000; c50_i52++) {
    c50_set_bmlsL(chartInstance, c50_i52, chartInstance->c50_newBmlsL[c50_i52]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_encStr2Arr(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_myarr256[2000])
{
  uint32_T c50_debug_family_var_map[9];
  real_T c50_maxarrsize;
  real_T c50_arr[260];
  real_T c50_ss;
  real_T c50_padsize;
  real_T c50_tt[2000];
  char_T c50_mystr[260];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i53;
  static char_T c50_cv0[260] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=',
    '\"', '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ',
    'e', 'n', 'd', '=', '\"', '0', '.', '5', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a',
    'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o', 'u',
    'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '2', '\"', ' ',
    ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=',
    '\"', '0', '.', '5', '\"', ' ', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's',
    '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o', 'u', 'n', 't',
    '=', '\"', '0', '.', '5', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"',
    '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '0', '.', '5', '\"', ' ', ' ', 'a',
    'u', '=', '\"', '5', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c50_i54;
  static real_T c50_dv23[260] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 116.0,
    121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 50.0, 34.0,
    32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    101.0, 110.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 32.0,
    116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0,
    48.0, 46.0, 53.0, 34.0, 32.0, 32.0, 97.0, 117.0, 61.0, 34.0, 53.0, 34.0,
    32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0,
    32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c50_i55;
  int32_T c50_i56;
  int32_T c50_i57;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c50_b_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_maxarrsize, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_arr, 1U, c50_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_ss, 2U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_padsize, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_tt, 4U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_mystr, 5U, c50_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 7U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_myarr256, 8U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  for (c50_i53 = 0; c50_i53 < 260; c50_i53++) {
    c50_mystr[c50_i53] = c50_cv0[c50_i53];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 6);
  for (c50_i54 = 0; c50_i54 < 260; c50_i54++) {
    c50_arr[c50_i54] = c50_dv23[c50_i54];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 7);
  c50_ss = 260.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 8);
  c50_padsize = 1740.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 9);
  for (c50_i55 = 0; c50_i55 < 2000; c50_i55++) {
    c50_tt[c50_i55] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 10);
  for (c50_i56 = 0; c50_i56 < 260; c50_i56++) {
    c50_tt[c50_i56] = c50_arr[c50_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 11);
  for (c50_i57 = 0; c50_i57 < 2000; c50_i57++) {
    c50_myarr256[c50_i57] = c50_tt[c50_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_b_encStr2Arr(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_myarr256[2000])
{
  uint32_T c50_debug_family_var_map[9];
  real_T c50_maxarrsize;
  real_T c50_arr[244];
  real_T c50_ss;
  real_T c50_padsize;
  real_T c50_tt[2000];
  char_T c50_mystr[244];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i58;
  static char_T c50_cv1[244] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=',
    '\"', '1', '\"', ' ', 'e', 'n', 'd', '=', '\"', '4', '\"', ' ', 'r', 'e',
    'a', 'd', 'y', '=', '\"', '1', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"',
    '3', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k',
    'e', '=', '\"', '2', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c',
    's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o', 'u', 'n',
    't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"', '5', '\"',
    ' ', 'e', 'n', 'd', '=', '\"', '4', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=',
    '\"', '1', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '3', '\"', ' ',
    's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's', 't', 'a',
    'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"',
    '2', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c50_i59;
  static real_T c50_dv24[244] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 52.0, 34.0, 32.0, 114.0,
    101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 49.0, 34.0, 32.0, 114.0, 101.0, 108.0,
    97.0, 120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0,
    61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0,
    34.0, 50.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0,
    99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0,
    109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0,
    97.0, 117.0, 61.0, 34.0, 53.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0,
    52.0, 34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 49.0, 34.0,
    32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0,
    116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0,
    111.0, 107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c50_i60;
  int32_T c50_i61;
  int32_T c50_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c50_c_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_maxarrsize, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_arr, 1U, c50_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_ss, 2U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_padsize, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_tt, 4U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_mystr, 5U, c50_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 7U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_myarr256, 8U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  for (c50_i58 = 0; c50_i58 < 244; c50_i58++) {
    c50_mystr[c50_i58] = c50_cv1[c50_i58];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 6);
  for (c50_i59 = 0; c50_i59 < 244; c50_i59++) {
    c50_arr[c50_i59] = c50_dv24[c50_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 7);
  c50_ss = 244.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 8);
  c50_padsize = 1756.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 9);
  for (c50_i60 = 0; c50_i60 < 2000; c50_i60++) {
    c50_tt[c50_i60] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 10);
  for (c50_i61 = 0; c50_i61 < 244; c50_i61++) {
    c50_tt[c50_i61] = c50_arr[c50_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 11);
  for (c50_i62 = 0; c50_i62 < 2000; c50_i62++) {
    c50_myarr256[c50_i62] = c50_tt[c50_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c50_rand(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  uint32_T c50_uv2[625];
  int32_T c50_i63;
  real_T c50_d0;
  if (!chartInstance->c50_method_not_empty) {
    chartInstance->c50_method = 7U;
    chartInstance->c50_method_not_empty = true;
  }

  if (!chartInstance->c50_c_state_not_empty) {
    c50_eml_rand_mt19937ar(chartInstance, c50_uv2);
    for (c50_i63 = 0; c50_i63 < 625; c50_i63++) {
      chartInstance->c50_c_state[c50_i63] = c50_uv2[c50_i63];
    }

    chartInstance->c50_c_state_not_empty = true;
  }

  c50_d0 = c50_c_eml_rand_mt19937ar(chartInstance, chartInstance->c50_c_state);
  return c50_d0;
}

static void c50_eml_rand_mt19937ar(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_d_state[625])
{
  real_T c50_d1;
  int32_T c50_i64;
  c50_d1 = 5489.0;
  for (c50_i64 = 0; c50_i64 < 625; c50_i64++) {
    c50_d_state[c50_i64] = 0U;
  }

  c50_b_twister_state_vector(chartInstance, c50_d_state, c50_d1);
}

static void c50_twister_state_vector(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_mt[625], real_T c50_seed, uint32_T c50_b_mt[625])
{
  int32_T c50_i65;
  for (c50_i65 = 0; c50_i65 < 625; c50_i65++) {
    c50_b_mt[c50_i65] = c50_mt[c50_i65];
  }

  c50_b_twister_state_vector(chartInstance, c50_b_mt, c50_seed);
}

static void c50_b_eml_rand_mt19937ar(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_d_state[625], uint32_T c50_e_state[625], real_T
  *c50_r)
{
  int32_T c50_i66;
  for (c50_i66 = 0; c50_i66 < 625; c50_i66++) {
    c50_e_state[c50_i66] = c50_d_state[c50_i66];
  }

  *c50_r = c50_c_eml_rand_mt19937ar(chartInstance, c50_e_state);
}

static void c50_eml_error(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  int32_T c50_i67;
  static char_T c50_cv2[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c50_u[37];
  const mxArray *c50_y = NULL;
  (void)chartInstance;
  for (c50_i67 = 0; c50_i67 < 37; c50_i67++) {
    c50_u[c50_i67] = c50_cv2[c50_i67];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 37),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c50_y));
}

static real_T c50_randi(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  real_T c50_r;
  real_T c50_x;
  real_T c50_b_x;
  c50_r = c50_rand(chartInstance);
  c50_x = c50_r * 2.0;
  c50_b_x = c50_x;
  c50_b_x = muDoubleScalarFloor(c50_b_x);
  return 1.0 + c50_b_x;
}

static void c50_cmdBML_AU_VA(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_eAmount[15], real_T c50_arrBML[2000])
{
  uint32_T c50_debug_family_var_map[14];
  real_T c50_L;
  const mxArray *c50_str1 = NULL;
  real_T c50_all_AUs[15];
  real_T c50_c;
  real_T c50_AU;
  real_T c50_eA;
  const mxArray *c50_temp = NULL;
  const mxArray *c50_temp2 = NULL;
  const mxArray *c50_str2 = NULL;
  char_T c50_mystr[1713];
  char_T c50_b_mystr[1610];
  char_T c50_c_mystr[1577];
  char_T c50_d_mystr[1474];
  char_T c50_e_mystr[1171];
  char_T c50_f_mystr[1068];
  char_T c50_g_mystr[965];
  char_T c50_h_mystr[862];
  char_T c50_i_mystr[759];
  char_T c50_j_mystr[656];
  char_T c50_k_mystr[515];
  char_T c50_l_mystr[412];
  char_T c50_m_mystr[306];
  char_T c50_n_mystr[206];
  char_T c50_o_mystr[103];
  int32_T c50_mystr_sizes[2];
  char_T c50_mystr_data[1713];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i68;
  static char_T c50_cv3[34] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>' };

  char_T c50_u[34];
  const mxArray *c50_y = NULL;
  int32_T c50_i69;
  static real_T c50_dv25[15] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 12.0, 26.0, 45.0,
    10.0, 25.0, 102.0, 103.0, 104.0, 105.0 };

  int32_T c50_b_c;
  real_T c50_d2;
  real_T c50_varargin_1;
  real_T c50_varargin_2;
  real_T c50_x;
  real_T c50_b_x;
  real_T c50_xk;
  real_T c50_c_x;
  real_T c50_maxval;
  int32_T c50_i70;
  static char_T c50_cv4[124] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '1', 'd', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't',
    '=', '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\',
    '\"', '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"',
    '4', '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6',
    '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '3', 'f', '\\',
    '\"', '/', '>' };

  char_T c50_b_u[124];
  const mxArray *c50_b_y = NULL;
  real_T c50_c_u;
  const mxArray *c50_c_y = NULL;
  real_T c50_d_u;
  const mxArray *c50_d_y = NULL;
  int32_T c50_i71;
  static char_T c50_cv5[123] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '2', 'd', '\\', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\', '\"',
    '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"', '4',
    '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6', '\\',
    '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '3', 'f', '\\', '\"',
    '/', '>' };

  char_T c50_e_u[123];
  const mxArray *c50_e_y = NULL;
  real_T c50_f_u;
  const mxArray *c50_f_y = NULL;
  real_T c50_g_u;
  const mxArray *c50_g_y = NULL;
  int32_T c50_i72;
  static char_T c50_cv6[12] = { '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  char_T c50_h_u[12];
  const mxArray *c50_h_y = NULL;
  int32_T c50_i73;
  int32_T c50_i74;
  int32_T c50_i75;
  int32_T c50_i76;
  int32_T c50_i77;
  int32_T c50_i78;
  int32_T c50_i79;
  int32_T c50_i80;
  int32_T c50_i81;
  int32_T c50_i82;
  int32_T c50_i83;
  int32_T c50_i84;
  int32_T c50_i85;
  int32_T c50_i86;
  int32_T c50_i87;
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[1713];
  int32_T c50_p_mystr;
  int32_T c50_q_mystr;
  int32_T c50_loop_ub;
  int32_T c50_i88;
  int32_T c50_b_mystr_sizes[2];
  int32_T c50_r_mystr;
  int32_T c50_s_mystr;
  int32_T c50_b_loop_ub;
  int32_T c50_i89;
  char_T c50_b_mystr_data[1713];
  real_T c50_dv26[2000];
  int32_T c50_i90;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 29U, c50_m_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_L, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_str1, 1U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_all_AUs, 2U, c50_i_sf_marshallOut,
    c50_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_AU, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_eA, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_temp, 6U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_temp2, 7U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_str2, 8U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_mystr, MAX_uint32_T,
    c50_db_sf_marshallOut, c50_x_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_b_mystr, MAX_uint32_T,
    c50_cb_sf_marshallOut, c50_w_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_c_mystr, MAX_uint32_T,
    c50_bb_sf_marshallOut, c50_v_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_d_mystr, MAX_uint32_T,
    c50_ab_sf_marshallOut, c50_u_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_e_mystr, MAX_uint32_T,
    c50_y_sf_marshallOut, c50_t_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_f_mystr, MAX_uint32_T,
    c50_x_sf_marshallOut, c50_s_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_g_mystr, MAX_uint32_T,
    c50_w_sf_marshallOut, c50_r_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_h_mystr, MAX_uint32_T,
    c50_v_sf_marshallOut, c50_q_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_i_mystr, MAX_uint32_T,
    c50_u_sf_marshallOut, c50_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_j_mystr, MAX_uint32_T,
    c50_t_sf_marshallOut, c50_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_k_mystr, MAX_uint32_T,
    c50_s_sf_marshallOut, c50_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_l_mystr, MAX_uint32_T,
    c50_r_sf_marshallOut, c50_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_m_mystr, MAX_uint32_T,
    c50_q_sf_marshallOut, c50_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_n_mystr, MAX_uint32_T,
    c50_p_sf_marshallOut, c50_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_o_mystr, MAX_uint32_T,
    c50_o_sf_marshallOut, c50_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_mystr_data, (const int32_T *)
    &c50_mystr_sizes, NULL, 0, -1, (void *)c50_m_sf_marshallOut, (void *)
    c50_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 10U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 11U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_eAmount, 12U, c50_i_sf_marshallOut,
    c50_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_arrBML, 13U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 4);
  c50_L = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 6);
  for (c50_i68 = 0; c50_i68 < 34; c50_i68++) {
    c50_u[c50_i68] = c50_cv3[c50_i68];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  sf_mex_assign(&c50_str1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c50_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 7);
  for (c50_i69 = 0; c50_i69 < 15; c50_i69++) {
    c50_all_AUs[c50_i69] = c50_dv25[c50_i69];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 8);
  c50_c = 1.0;
  c50_b_c = 0;
  while (c50_b_c < 15) {
    c50_c = 1.0 + (real_T)c50_b_c;
    CV_SCRIPT_FOR(1, 0, 1);
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 9);
    c50_AU = c50_all_AUs[(int32_T)c50_c - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 9);
    c50_eA = c50_eAmount[(int32_T)c50_c - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 10);
    if (CV_SCRIPT_IF(1, 0, c50_eA >= 0.1)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 11);
      c50_L++;
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 13);
      c50_d2 = c50_abs(chartInstance, c50_AU);
      c50_b_log10(chartInstance, &c50_d2);
      c50_varargin_1 = c50_d2;
      c50_b_ceil(chartInstance, &c50_varargin_1);
      c50_varargin_2 = c50_varargin_1;
      c50_x = c50_varargin_2;
      c50_b_x = c50_x;
      c50_eml_scalar_eg(chartInstance);
      c50_xk = c50_b_x;
      c50_c_x = c50_xk;
      c50_eml_scalar_eg(chartInstance);
      c50_maxval = muDoubleScalarMax(c50_c_x, 1.0);
      if (CV_SCRIPT_IF(1, 1, c50_maxval == 1.0)) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 14);
        for (c50_i70 = 0; c50_i70 < 124; c50_i70++) {
          c50_b_u[c50_i70] = c50_cv4[c50_i70];
        }

        c50_b_y = NULL;
        sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_b_u, 10, 0U, 1U, 0U, 2, 1,
          124), false);
        c50_c_u = c50_AU;
        c50_c_y = NULL;
        sf_mex_assign(&c50_c_y, sf_mex_create("y", &c50_c_u, 0, 0U, 0U, 0U, 0),
                      false);
        c50_d_u = c50_eA;
        c50_d_y = NULL;
        sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c50_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "sprintf", 1U, 3U, 14, c50_b_y, 14, c50_c_y, 14, c50_d_y), false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 15);
        sf_mex_assign(&c50_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14, sf_mex_dup(c50_temp)),
                      false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 16);
        sf_mex_assign(&c50_str1, sf_mex_dup(c50_temp2), false);
      } else {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 18);
        for (c50_i71 = 0; c50_i71 < 123; c50_i71++) {
          c50_e_u[c50_i71] = c50_cv5[c50_i71];
        }

        c50_e_y = NULL;
        sf_mex_assign(&c50_e_y, sf_mex_create("y", c50_e_u, 10, 0U, 1U, 0U, 2, 1,
          123), false);
        c50_f_u = c50_AU;
        c50_f_y = NULL;
        sf_mex_assign(&c50_f_y, sf_mex_create("y", &c50_f_u, 0, 0U, 0U, 0U, 0),
                      false);
        c50_g_u = c50_eA;
        c50_g_y = NULL;
        sf_mex_assign(&c50_g_y, sf_mex_create("y", &c50_g_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c50_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "sprintf", 1U, 3U, 14, c50_e_y, 14, c50_f_y, 14, c50_g_y), false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 19);
        sf_mex_assign(&c50_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14, sf_mex_dup(c50_temp)),
                      false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 20);
        sf_mex_assign(&c50_str1, sf_mex_dup(c50_temp2), false);
      }
    }

    c50_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(1, 0, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 24);
  for (c50_i72 = 0; c50_i72 < 12; c50_i72++) {
    c50_h_u[c50_i72] = c50_cv6[c50_i72];
  }

  c50_h_y = NULL;
  sf_mex_assign(&c50_h_y, sf_mex_create("y", c50_h_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_assign(&c50_str2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c50_h_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 26);
  if (CV_SCRIPT_IF(1, 2, c50_L == 1.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 27);
    c50_blanks(chartInstance);
    for (c50_i73 = 0; c50_i73 < 103; c50_i73++) {
      c50_o_mystr[c50_i73] = ' ';
    }

    _SFD_SYMBOL_SWITCH(9U, 23U);
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 28);
    if (CV_SCRIPT_IF(1, 3, c50_L == 2.0)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 29);
      c50_b_blanks(chartInstance);
      for (c50_i74 = 0; c50_i74 < 206; c50_i74++) {
        c50_n_mystr[c50_i74] = ' ';
      }

      _SFD_SYMBOL_SWITCH(9U, 22U);
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 30);
      if (CV_SCRIPT_IF(1, 4, c50_L == 3.0)) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 31);
        c50_c_blanks(chartInstance);
        for (c50_i75 = 0; c50_i75 < 306; c50_i75++) {
          c50_m_mystr[c50_i75] = ' ';
        }

        _SFD_SYMBOL_SWITCH(9U, 21U);
      } else {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 32);
        if (CV_SCRIPT_IF(1, 5, c50_L == 4.0)) {
          _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 33);
          c50_d_blanks(chartInstance);
          for (c50_i76 = 0; c50_i76 < 412; c50_i76++) {
            c50_l_mystr[c50_i76] = ' ';
          }

          _SFD_SYMBOL_SWITCH(9U, 20U);
        } else {
          _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 34);
          if (CV_SCRIPT_IF(1, 6, c50_L == 5.0)) {
            _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 35);
            c50_e_blanks(chartInstance);
            for (c50_i77 = 0; c50_i77 < 515; c50_i77++) {
              c50_k_mystr[c50_i77] = ' ';
            }

            _SFD_SYMBOL_SWITCH(9U, 19U);
          } else {
            _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 36);
            if (CV_SCRIPT_IF(1, 7, c50_L == 6.0)) {
              _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 37);
              c50_f_blanks(chartInstance);
              for (c50_i78 = 0; c50_i78 < 656; c50_i78++) {
                c50_j_mystr[c50_i78] = ' ';
              }

              _SFD_SYMBOL_SWITCH(9U, 18U);
            } else {
              _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 38);
              if (CV_SCRIPT_IF(1, 8, c50_L == 7.0)) {
                _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 39);
                c50_g_blanks(chartInstance);
                for (c50_i79 = 0; c50_i79 < 759; c50_i79++) {
                  c50_i_mystr[c50_i79] = ' ';
                }

                _SFD_SYMBOL_SWITCH(9U, 17U);
              } else {
                _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 40);
                if (CV_SCRIPT_IF(1, 9, c50_L == 8.0)) {
                  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 41);
                  c50_h_blanks(chartInstance);
                  for (c50_i80 = 0; c50_i80 < 862; c50_i80++) {
                    c50_h_mystr[c50_i80] = ' ';
                  }

                  _SFD_SYMBOL_SWITCH(9U, 16U);
                } else {
                  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 42);
                  if (CV_SCRIPT_IF(1, 10, c50_L == 9.0)) {
                    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 43);
                    c50_i_blanks(chartInstance);
                    for (c50_i81 = 0; c50_i81 < 965; c50_i81++) {
                      c50_g_mystr[c50_i81] = ' ';
                    }

                    _SFD_SYMBOL_SWITCH(9U, 15U);
                  } else {
                    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 44);
                    if (CV_SCRIPT_IF(1, 11, c50_L == 10.0)) {
                      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 45);
                      c50_j_blanks(chartInstance);
                      for (c50_i82 = 0; c50_i82 < 1068; c50_i82++) {
                        c50_f_mystr[c50_i82] = ' ';
                      }

                      _SFD_SYMBOL_SWITCH(9U, 14U);
                    } else {
                      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 46);
                      if (CV_SCRIPT_IF(1, 12, c50_L == 11.0)) {
                        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 47);
                        c50_k_blanks(chartInstance);
                        for (c50_i83 = 0; c50_i83 < 1171; c50_i83++) {
                          c50_e_mystr[c50_i83] = ' ';
                        }

                        _SFD_SYMBOL_SWITCH(9U, 13U);
                      } else {
                        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 48);
                        if (CV_SCRIPT_IF(1, 13, c50_L == 12.0)) {
                          _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 49);
                          c50_l_blanks(chartInstance);
                          for (c50_i84 = 0; c50_i84 < 1474; c50_i84++) {
                            c50_d_mystr[c50_i84] = ' ';
                          }

                          _SFD_SYMBOL_SWITCH(9U, 12U);
                        } else {
                          _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 50);
                          if (CV_SCRIPT_IF(1, 14, c50_L == 13.0)) {
                            _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 51);
                            c50_m_blanks(chartInstance);
                            for (c50_i85 = 0; c50_i85 < 1577; c50_i85++) {
                              c50_c_mystr[c50_i85] = ' ';
                            }

                            _SFD_SYMBOL_SWITCH(9U, 11U);
                          } else {
                            _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 52);
                            if (CV_SCRIPT_IF(1, 15, c50_L == 14.0)) {
                              _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent,
                                               53);
                              c50_n_blanks(chartInstance);
                              for (c50_i86 = 0; c50_i86 < 1610; c50_i86++) {
                                c50_b_mystr[c50_i86] = ' ';
                              }

                              _SFD_SYMBOL_SWITCH(9U, 10U);
                            } else {
                              _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent,
                                               54);
                              if (CV_SCRIPT_IF(1, 16, c50_L == 15.0)) {
                                _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent,
                                                 55);
                                c50_o_blanks(chartInstance);
                                for (c50_i87 = 0; c50_i87 < 1713; c50_i87++) {
                                  c50_mystr[c50_i87] = ' ';
                                }

                                _SFD_SYMBOL_SWITCH(9U, 9U);
                              } else {
                                _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent,
                                                 57);
                                c50_fprintf(chartInstance, c50_L);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 59);
  c50_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14,
     sf_mex_dup(c50_str2)), "strcat", c50_tmp_data, c50_tmp_sizes);
  c50_mystr_sizes[0] = 1;
  c50_mystr_sizes[1] = c50_tmp_sizes[1];
  c50_p_mystr = c50_mystr_sizes[0];
  c50_q_mystr = c50_mystr_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i88 = 0; c50_i88 <= c50_loop_ub; c50_i88++) {
    c50_mystr_data[c50_i88] = c50_tmp_data[c50_i88];
  }

  _SFD_SYMBOL_SWITCH(9U, 24U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 60);
  c50_b_mystr_sizes[0] = 1;
  c50_b_mystr_sizes[1] = c50_mystr_sizes[1];
  c50_r_mystr = c50_b_mystr_sizes[0];
  c50_s_mystr = c50_b_mystr_sizes[1];
  c50_b_loop_ub = c50_mystr_sizes[0] * c50_mystr_sizes[1] - 1;
  for (c50_i89 = 0; c50_i89 <= c50_b_loop_ub; c50_i89++) {
    c50_b_mystr_data[c50_i89] = c50_mystr_data[c50_i89];
  }

  c50_c_encStr2Arr(chartInstance, c50_b_mystr_data, c50_b_mystr_sizes, c50_dv26);
  for (c50_i90 = 0; c50_i90 < 2000; c50_i90++) {
    c50_arrBML[c50_i90] = c50_dv26[c50_i90];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, -60);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c50_str1);
  sf_mex_destroy(&c50_temp);
  sf_mex_destroy(&c50_temp2);
  sf_mex_destroy(&c50_str2);
}

static real_T c50_log10(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  c50_x)
{
  real_T c50_b_x;
  c50_b_x = c50_x;
  c50_b_log10(chartInstance, &c50_b_x);
  return c50_b_x;
}

static real_T c50_ceil(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  c50_x)
{
  real_T c50_b_x;
  c50_b_x = c50_x;
  c50_b_ceil(chartInstance, &c50_b_x);
  return c50_b_x;
}

static void c50_eml_scalar_eg(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_b_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_c_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_d_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_e_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_f_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_g_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_h_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_i_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_j_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_k_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_l_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_m_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_n_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_o_blanks(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_fprintf(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  c50_formatSpec)
{
  c50_isequal(chartInstance);
  c50_b_fprintf(chartInstance, c50_formatSpec);
}

static void c50_isequal(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c50_b_fprintf(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_varargin_1)
{
  real_T c50_nbytes;
  int32_T c50_i91;
  static char_T c50_cv7[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c50_u[7];
  const mxArray *c50_y = NULL;
  real_T c50_b_u;
  const mxArray *c50_b_y = NULL;
  int32_T c50_i92;
  static char_T c50_formatSpec[12] = { ' ', ',', 'L', ':', ' ', '%', '0', '.',
    '0', 'f', '\\', 'r' };

  char_T c50_c_u[12];
  const mxArray *c50_c_y = NULL;
  real_T c50_d_u;
  const mxArray *c50_d_y = NULL;
  const mxArray *c50_cfmt = NULL;
  const mxArray *c50_convs = NULL;
  c50_isequal(chartInstance);
  for (c50_i91 = 0; c50_i91 < 7; c50_i91++) {
    c50_u[c50_i91] = c50_cv7[c50_i91];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c50_b_u = 1.0;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c50_i92 = 0; c50_i92 < 12; c50_i92++) {
    c50_c_u[c50_i92] = c50_formatSpec[c50_i92];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_c_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  c50_d_u = c50_varargin_1;
  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0), false);
  c50_nbytes = c50_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14, c50_y, 14, c50_b_y, 14,
     c50_c_y, 14, c50_d_y), "feval");
  sf_mex_destroy(&c50_cfmt);
  sf_mex_destroy(&c50_convs);
  return c50_nbytes;
}

static void c50_c_encStr2Arr(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  char_T c50_mystr_data[], int32_T c50_mystr_sizes[2], real_T c50_myarr256[2000])
{
  uint32_T c50_debug_family_var_map[9];
  real_T c50_maxarrsize;
  int32_T c50_arr_sizes;
  real_T c50_arr_data[1713];
  real_T c50_ss;
  real_T c50_padsize;
  real_T c50_tt[2000];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  int32_T c50_loop_ub;
  int32_T c50_i93;
  int32_T c50_i94;
  boolean_T c50_b0;
  boolean_T c50_b1;
  boolean_T c50_b2;
  int32_T c50_i95;
  int32_T c50_tmp_sizes;
  int32_T c50_b_loop_ub;
  int32_T c50_i96;
  int32_T c50_tmp_data[1713];
  int32_T c50_iv0[1];
  int32_T c50_c_loop_ub;
  int32_T c50_i97;
  int32_T c50_i98;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c50_l_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_maxarrsize, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_arr_data, (const int32_T *)
    &c50_arr_sizes, NULL, 0, 1, (void *)c50_n_sf_marshallOut, (void *)
    c50_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_ss, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_padsize, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_tt, 4U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_mystr_data, (const int32_T *)
    c50_mystr_sizes, NULL, 1, 7, (void *)c50_m_sf_marshallOut, (void *)
    c50_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_myarr256, 8U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 6);
  c50_arr_sizes = c50_mystr_sizes[1];
  c50_loop_ub = c50_mystr_sizes[1] - 1;
  for (c50_i93 = 0; c50_i93 <= c50_loop_ub; c50_i93++) {
    c50_arr_data[c50_i93] = (real_T)c50_mystr_data[c50_mystr_sizes[0] * c50_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 7);
  c50_ss = (real_T)c50_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 8);
  c50_padsize = 2000.0 - c50_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 9);
  for (c50_i94 = 0; c50_i94 < 2000; c50_i94++) {
    c50_tt[c50_i94] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 10);
  c50_b0 = (1.0 > c50_ss);
  c50_b1 = c50_b0;
  c50_b2 = c50_b1;
  if (c50_b2) {
    c50_i95 = 0;
  } else {
    c50_i95 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c50_ss, 1, 2000, 0, 0);
  }

  c50_tmp_sizes = c50_i95;
  c50_b_loop_ub = c50_i95 - 1;
  for (c50_i96 = 0; c50_i96 <= c50_b_loop_ub; c50_i96++) {
    c50_tmp_data[c50_i96] = c50_i96;
  }

  c50_iv0[0] = c50_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c50_iv0, 1, *(int32_T (*)[1])&c50_arr_sizes, 1);
  c50_c_loop_ub = c50_arr_sizes - 1;
  for (c50_i97 = 0; c50_i97 <= c50_c_loop_ub; c50_i97++) {
    c50_tt[c50_tmp_data[c50_i97]] = c50_arr_data[c50_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 11);
  for (c50_i98 = 0; c50_i98 < 2000; c50_i98++) {
    c50_myarr256[c50_i98] = c50_tt[c50_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_eml_li_find(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  boolean_T c50_x[2000], int32_T c50_y_data[], int32_T *c50_y_sizes)
{
  int32_T c50_i99;
  boolean_T c50_b_x[2000];
  int32_T c50_k;
  const mxArray *c50_y = NULL;
  int32_T c50_tmp_sizes;
  int32_T c50_loop_ub;
  int32_T c50_i100;
  int32_T c50_tmp_data[2000];
  int32_T c50_j;
  int32_T c50_i;
  int32_T c50_b_i;
  int32_T c50_a;
  int32_T c50_b_a;
  for (c50_i99 = 0; c50_i99 < 2000; c50_i99++) {
    c50_b_x[c50_i99] = c50_x[c50_i99];
  }

  c50_k = c50_compute_nones(chartInstance, c50_b_x);
  if (c50_k <= 2000) {
  } else {
    c50_y = NULL;
    sf_mex_assign(&c50_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c50_y);
  }

  c50_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c50_k);
  c50_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c50_k) - 1;
  for (c50_i100 = 0; c50_i100 <= c50_loop_ub; c50_i100++) {
    c50_tmp_data[c50_i100] = 0;
  }

  *c50_y_sizes = c50_tmp_sizes;
  c50_j = 1;
  for (c50_i = 1; c50_i < 2001; c50_i++) {
    c50_b_i = c50_i;
    if (c50_x[c50_b_i - 1]) {
      c50_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c50_j, 1, *c50_y_sizes, 1, 0) -
        1] = c50_b_i;
      c50_a = c50_j;
      c50_b_a = c50_a + 1;
      c50_j = c50_b_a;
    }
  }
}

static int32_T c50_compute_nones(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  boolean_T c50_x[2000])
{
  int32_T c50_k;
  int32_T c50_i;
  int32_T c50_b_i;
  int32_T c50_a;
  int32_T c50_b_a;
  (void)chartInstance;
  c50_k = 0;
  for (c50_i = 1; c50_i < 2001; c50_i++) {
    c50_b_i = c50_i - 1;
    if (c50_x[c50_b_i]) {
      c50_a = c50_k;
      c50_b_a = c50_a + 1;
      c50_k = c50_b_a;
    }
  }

  return c50_k;
}

static void c50_char(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
                     c50_varargin_1_data[], int32_T c50_varargin_1_sizes[2],
                     char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i101;
  real_T c50_dv27[2];
  int32_T c50_tmp_sizes[2];
  int32_T c50_iv1[2];
  int32_T c50_i102;
  int32_T c50_i103;
  int32_T c50_loop_ub;
  int32_T c50_i104;
  char_T c50_tmp_data[2000];
  int32_T c50_i105;
  int32_T c50_b_tmp_sizes;
  int32_T c50_b_loop_ub;
  int32_T c50_i106;
  char_T c50_b_tmp_data[2000];
  int32_T c50_i107;
  int32_T c50_y[2];
  int32_T c50_c_loop_ub;
  int32_T c50_i108;
  (void)chartInstance;
  for (c50_i101 = 0; c50_i101 < 2; c50_i101++) {
    c50_dv27[c50_i101] = (real_T)c50_varargin_1_sizes[c50_i101];
  }

  c50_tmp_sizes[0] = 1;
  c50_iv1[0] = 1;
  c50_iv1[1] = (int32_T)c50_dv27[1];
  c50_tmp_sizes[1] = c50_iv1[1];
  c50_i102 = c50_tmp_sizes[0];
  c50_i103 = c50_tmp_sizes[1];
  c50_loop_ub = (int32_T)c50_dv27[1] - 1;
  for (c50_i104 = 0; c50_i104 <= c50_loop_ub; c50_i104++) {
    c50_tmp_data[c50_i104] = ' ';
  }

  for (c50_i105 = 0; c50_i105 < 2; c50_i105++) {
    c50_y_sizes[c50_i105] = c50_tmp_sizes[c50_i105];
  }

  c50_b_tmp_sizes = c50_varargin_1_sizes[1];
  c50_b_loop_ub = c50_varargin_1_sizes[1] - 1;
  for (c50_i106 = 0; c50_i106 <= c50_b_loop_ub; c50_i106++) {
    c50_b_tmp_data[c50_i106] = (char_T)(int8_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "char", (int32_T)_SFD_INTEGER_CHECK("", c50_varargin_1_data[c50_i106]), 0,
      255, 0, 2);
  }

  _SFD_SIZE_EQ_CHECK_1D(c50_y_sizes[1], c50_b_tmp_sizes);
  for (c50_i107 = 0; c50_i107 < 2; c50_i107++) {
    c50_y[c50_i107] = c50_y_sizes[c50_i107];
  }

  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_y[1];
  c50_c_loop_ub = c50_y[1] - 1;
  for (c50_i108 = 0; c50_i108 <= c50_c_loop_ub; c50_i108++) {
    c50_y_data[c50_y_sizes[0] * c50_i108] = c50_b_tmp_data[c50_y[0] * c50_i108];
  }
}

static void c50_cmdBML_AUmerg(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_arrAU[6], real_T c50_eAmount[6], real_T c50_L, real_T c50_arrBML
  [2000])
{
  uint32_T c50_debug_family_var_map[17];
  real_T c50_csum;
  const mxArray *c50_str1 = NULL;
  real_T c50_j;
  real_T c50_AU;
  real_T c50_eA;
  real_T c50_c1;
  real_T c50_c2;
  const mxArray *c50_temp = NULL;
  const mxArray *c50_temp2 = NULL;
  const mxArray *c50_str2 = NULL;
  char_T c50_mystr[656];
  char_T c50_b_mystr[515];
  char_T c50_c_mystr[412];
  char_T c50_d_mystr[306];
  char_T c50_e_mystr[206];
  char_T c50_f_mystr[103];
  int32_T c50_mystr_sizes[2];
  char_T c50_mystr_data[656];
  real_T c50_nargin = 3.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i109;
  static char_T c50_cv8[34] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>' };

  char_T c50_u[34];
  const mxArray *c50_y = NULL;
  real_T c50_b_L;
  int32_T c50_i110;
  int32_T c50_b_j;
  real_T c50_d3;
  real_T c50_varargin_1;
  real_T c50_varargin_2;
  real_T c50_x;
  real_T c50_b_x;
  real_T c50_xk;
  real_T c50_c_x;
  real_T c50_maxval;
  int32_T c50_i111;
  static char_T c50_cv9[124] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '1', 'd', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't',
    '=', '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\',
    '\"', '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"',
    '4', '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6',
    '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '1', 'f', '\\',
    '\"', '/', '>' };

  char_T c50_b_u[124];
  const mxArray *c50_b_y = NULL;
  real_T c50_c_u;
  const mxArray *c50_c_y = NULL;
  real_T c50_d_u;
  const mxArray *c50_d_y = NULL;
  int32_T c50_i112;
  static char_T c50_cv10[123] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '2', 'd', '\\', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\', '\"',
    '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"', '4',
    '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6', '\\',
    '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '1', 'f', '\\', '\"',
    '/', '>' };

  char_T c50_e_u[123];
  const mxArray *c50_e_y = NULL;
  real_T c50_f_u;
  const mxArray *c50_f_y = NULL;
  real_T c50_g_u;
  const mxArray *c50_g_y = NULL;
  int32_T c50_i113;
  static char_T c50_cv11[12] = { '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  char_T c50_h_u[12];
  const mxArray *c50_h_y = NULL;
  int32_T c50_i114;
  int32_T c50_i115;
  int32_T c50_i116;
  int32_T c50_i117;
  int32_T c50_i118;
  int32_T c50_i119;
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[656];
  int32_T c50_g_mystr;
  int32_T c50_h_mystr;
  int32_T c50_loop_ub;
  int32_T c50_i120;
  int32_T c50_b_mystr_sizes[2];
  int32_T c50_i_mystr;
  int32_T c50_j_mystr;
  int32_T c50_b_loop_ub;
  int32_T c50_i121;
  char_T c50_b_mystr_data[656];
  real_T c50_dv28[2000];
  int32_T c50_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 23U, c50_q_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_csum, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_str1, 1U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_j, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_AU, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_eA, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c1, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c2, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_temp, 7U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_temp2, 8U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_str2, 9U, c50_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_mystr, MAX_uint32_T,
    c50_t_sf_marshallOut, c50_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_b_mystr, MAX_uint32_T,
    c50_s_sf_marshallOut, c50_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_c_mystr, MAX_uint32_T,
    c50_r_sf_marshallOut, c50_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_d_mystr, MAX_uint32_T,
    c50_q_sf_marshallOut, c50_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_e_mystr, MAX_uint32_T,
    c50_p_sf_marshallOut, c50_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_f_mystr, MAX_uint32_T,
    c50_o_sf_marshallOut, c50_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_mystr_data, (const int32_T *)
    &c50_mystr_sizes, NULL, 0, -1, (void *)c50_gb_sf_marshallOut, (void *)
    c50_ab_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 11U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 12U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_arrAU, 13U, c50_l_sf_marshallOut,
    c50_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_eAmount, 14U, c50_l_sf_marshallOut,
    c50_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_L, 15U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_arrBML, 16U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 2);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 3);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 4);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 5);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 6);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 7);
  c50_csum = 1.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 9);
  for (c50_i109 = 0; c50_i109 < 34; c50_i109++) {
    c50_u[c50_i109] = c50_cv8[c50_i109];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  sf_mex_assign(&c50_str1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c50_y), false);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 11);
  c50_b_L = c50_L;
  c50_i110 = (int32_T)c50_b_L;
  _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c50_b_L, mxDOUBLE_CLASS, c50_i110);
  c50_j = 1.0;
  c50_b_j = 0;
  while (c50_b_j <= c50_i110 - 1) {
    c50_j = 1.0 + (real_T)c50_b_j;
    CV_SCRIPT_FOR(3, 0, 1);
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 12);
    c50_AU = c50_arrAU[_SFD_EML_ARRAY_BOUNDS_CHECK("arrAU", (int32_T)c50_j, 1, 6,
      1, 0) - 1];
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 12);
    c50_eA = c50_eAmount[(int32_T)c50_j - 1];
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 13);
    c50_c1 = c50_countDigits(chartInstance, c50_AU);
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 13);
    c50_c2 = c50_countDigits(chartInstance, c50_eA);
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 13);
    c50_csum += c50_c1 + c50_c2;
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 14);
    c50_d3 = c50_abs(chartInstance, c50_AU);
    c50_b_log10(chartInstance, &c50_d3);
    c50_varargin_1 = c50_d3;
    c50_b_ceil(chartInstance, &c50_varargin_1);
    c50_varargin_2 = c50_varargin_1;
    c50_x = c50_varargin_2;
    c50_b_x = c50_x;
    c50_eml_scalar_eg(chartInstance);
    c50_xk = c50_b_x;
    c50_c_x = c50_xk;
    c50_eml_scalar_eg(chartInstance);
    c50_maxval = muDoubleScalarMax(c50_c_x, 1.0);
    if (CV_SCRIPT_IF(3, 0, c50_maxval == 1.0)) {
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 15);
      for (c50_i111 = 0; c50_i111 < 124; c50_i111++) {
        c50_b_u[c50_i111] = c50_cv9[c50_i111];
      }

      c50_b_y = NULL;
      sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_b_u, 10, 0U, 1U, 0U, 2, 1,
        124), false);
      c50_c_u = c50_AU;
      c50_c_y = NULL;
      sf_mex_assign(&c50_c_y, sf_mex_create("y", &c50_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c50_d_u = c50_eA;
      c50_d_y = NULL;
      sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c50_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "sprintf", 1U, 3U, 14, c50_b_y, 14, c50_c_y, 14, c50_d_y), false);
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 17);
      sf_mex_assign(&c50_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14, sf_mex_dup(c50_temp)),
                    false);
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 18);
      sf_mex_assign(&c50_str1, sf_mex_dup(c50_temp2), false);
    } else {
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 20);
      for (c50_i112 = 0; c50_i112 < 123; c50_i112++) {
        c50_e_u[c50_i112] = c50_cv10[c50_i112];
      }

      c50_e_y = NULL;
      sf_mex_assign(&c50_e_y, sf_mex_create("y", c50_e_u, 10, 0U, 1U, 0U, 2, 1,
        123), false);
      c50_f_u = c50_AU;
      c50_f_y = NULL;
      sf_mex_assign(&c50_f_y, sf_mex_create("y", &c50_f_u, 0, 0U, 0U, 0U, 0),
                    false);
      c50_g_u = c50_eA;
      c50_g_y = NULL;
      sf_mex_assign(&c50_g_y, sf_mex_create("y", &c50_g_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c50_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "sprintf", 1U, 3U, 14, c50_e_y, 14, c50_f_y, 14, c50_g_y), false);
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 22);
      sf_mex_assign(&c50_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14, sf_mex_dup(c50_temp)),
                    false);
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 23);
      sf_mex_assign(&c50_str1, sf_mex_dup(c50_temp2), false);
    }

    c50_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(3, 0, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 43);
  for (c50_i113 = 0; c50_i113 < 12; c50_i113++) {
    c50_h_u[c50_i113] = c50_cv11[c50_i113];
  }

  c50_h_y = NULL;
  sf_mex_assign(&c50_h_y, sf_mex_create("y", c50_h_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_assign(&c50_str2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c50_h_y), false);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 47);
  if (CV_SCRIPT_IF(3, 1, c50_L == 1.0)) {
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 48);
    c50_blanks(chartInstance);
    for (c50_i114 = 0; c50_i114 < 103; c50_i114++) {
      c50_f_mystr[c50_i114] = ' ';
    }

    _SFD_SYMBOL_SWITCH(10U, 15U);
  } else {
    _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 49);
    if (CV_SCRIPT_IF(3, 2, c50_L == 2.0)) {
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 50);
      for (c50_i115 = 0; c50_i115 < 206; c50_i115++) {
        c50_e_mystr[c50_i115] = ' ';
      }

      _SFD_SYMBOL_SWITCH(10U, 14U);
    } else {
      _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 51);
      if (CV_SCRIPT_IF(3, 3, c50_L == 3.0)) {
        _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 52);
        c50_c_blanks(chartInstance);
        for (c50_i116 = 0; c50_i116 < 306; c50_i116++) {
          c50_d_mystr[c50_i116] = ' ';
        }

        _SFD_SYMBOL_SWITCH(10U, 13U);
      } else {
        _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 53);
        if (CV_SCRIPT_IF(3, 4, c50_L == 4.0)) {
          _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 54);
          c50_d_blanks(chartInstance);
          for (c50_i117 = 0; c50_i117 < 412; c50_i117++) {
            c50_c_mystr[c50_i117] = ' ';
          }

          _SFD_SYMBOL_SWITCH(10U, 12U);
        } else {
          _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 55);
          if (CV_SCRIPT_IF(3, 5, c50_L == 5.0)) {
            _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 56);
            c50_e_blanks(chartInstance);
            for (c50_i118 = 0; c50_i118 < 515; c50_i118++) {
              c50_b_mystr[c50_i118] = ' ';
            }

            _SFD_SYMBOL_SWITCH(10U, 11U);
          } else {
            _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 57);
            if (CV_SCRIPT_IF(3, 6, c50_L == 6.0)) {
              _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 58);
              for (c50_i119 = 0; c50_i119 < 656; c50_i119++) {
                c50_mystr[c50_i119] = ' ';
              }

              _SFD_SYMBOL_SWITCH(10U, 10U);
            }
          }
        }
      }
    }
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 64);
  c50_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14,
     sf_mex_dup(c50_str2)), "strcat", c50_tmp_data, c50_tmp_sizes);
  c50_mystr_sizes[0] = 1;
  c50_mystr_sizes[1] = c50_tmp_sizes[1];
  c50_g_mystr = c50_mystr_sizes[0];
  c50_h_mystr = c50_mystr_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i120 = 0; c50_i120 <= c50_loop_ub; c50_i120++) {
    c50_mystr_data[c50_i120] = c50_tmp_data[c50_i120];
  }

  _SFD_SYMBOL_SWITCH(10U, 16U);
  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, 65);
  c50_b_mystr_sizes[0] = 1;
  c50_b_mystr_sizes[1] = c50_mystr_sizes[1];
  c50_i_mystr = c50_b_mystr_sizes[0];
  c50_j_mystr = c50_b_mystr_sizes[1];
  c50_b_loop_ub = c50_mystr_sizes[0] * c50_mystr_sizes[1] - 1;
  for (c50_i121 = 0; c50_i121 <= c50_b_loop_ub; c50_i121++) {
    c50_b_mystr_data[c50_i121] = c50_mystr_data[c50_i121];
  }

  c50_c_encStr2Arr(chartInstance, c50_b_mystr_data, c50_b_mystr_sizes, c50_dv28);
  for (c50_i122 = 0; c50_i122 < 2000; c50_i122++) {
    c50_arrBML[c50_i122] = c50_dv28[c50_i122];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c50_sfEvent, -65);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c50_str1);
  sf_mex_destroy(&c50_temp);
  sf_mex_destroy(&c50_temp2);
  sf_mex_destroy(&c50_str2);
}

static real_T c50_countDigits(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_x)
{
  real_T c50_b_num;
  uint32_T c50_debug_family_var_map[4];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  real_T c50_b_x;
  real_T c50_c_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c50_p_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_x, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_num, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 2);
  c50_b_num = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 3);
  if (CV_SCRIPT_IF(4, 0, c50_x < 0.0)) {
    _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 4);
    c50_b_num = 1.0;
    _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 5);
    c50_b_x = c50_x;
    c50_c_x = c50_b_x;
    c50_x = muDoubleScalarAbs(c50_c_x);
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 7);
  guard1 = false;
  if (CV_SCRIPT_COND(4, 0, c50_x > 0.0)) {
    if (CV_SCRIPT_COND(4, 1, c50_x < 9.0)) {
      CV_SCRIPT_MCDC(4, 0, true);
      CV_SCRIPT_IF(4, 1, true);
      _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 8);
      c50_b_num++;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(4, 0, false);
    CV_SCRIPT_IF(4, 1, false);
    _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 9);
    guard2 = false;
    if (CV_SCRIPT_COND(4, 2, c50_x > 10.0)) {
      if (CV_SCRIPT_COND(4, 3, c50_x < 99.0)) {
        CV_SCRIPT_MCDC(4, 1, true);
        CV_SCRIPT_IF(4, 2, true);
        _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 10);
        c50_b_num += 2.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_SCRIPT_MCDC(4, 1, false);
      CV_SCRIPT_IF(4, 2, false);
      _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 11);
      guard3 = false;
      if (CV_SCRIPT_COND(4, 4, c50_x > 100.0)) {
        if (CV_SCRIPT_COND(4, 5, c50_x < 999.0)) {
          CV_SCRIPT_MCDC(4, 2, true);
          CV_SCRIPT_IF(4, 3, true);
          _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, 12);
          c50_b_num += 3.0;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_SCRIPT_MCDC(4, 2, false);
        CV_SCRIPT_IF(4, 3, false);
      }
    }
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c50_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  return c50_b_num;
}

static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber)
{
  (void)c50_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c50_chartNumber, c50_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\9-1-2016-Matlab\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c50_chartNumber, c50_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\9-1-2016-Matlab\\cmdBML_AU_VA.m"));
  _SFD_SCRIPT_TRANSLATION(c50_chartNumber, c50_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\9-1-2016-Matlab\\decArr2Str.m"));
  _SFD_SCRIPT_TRANSLATION(c50_chartNumber, c50_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\9-1-2016-Matlab\\cmdBML_AUmerg.m"));
  _SFD_SCRIPT_TRANSLATION(c50_chartNumber, c50_instanceNumber, 4U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\9-1-2016-Matlab\\countDigits.m"));
}

static real_T c50_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_feval, const char_T *c50_identifier)
{
  real_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_feval),
    &c50_thisId);
  sf_mex_destroy(&c50_feval);
  return c50_y;
}

static real_T c50_b_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  real_T c50_y;
  real_T c50_d4;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_d4, 1, 0, 0U, 0, 0U, 0);
  c50_y = c50_d4;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_c_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_strcat, const char_T *c50_identifier,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_strcat), &c50_thisId,
    c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_strcat);
}

static void c50_d_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i123;
  uint32_T c50_uv3[2];
  int32_T c50_i124;
  static boolean_T c50_bv0[2] = { false, true };

  boolean_T c50_bv1[2];
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[1713];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i125;
  (void)chartInstance;
  for (c50_i123 = 0; c50_i123 < 2; c50_i123++) {
    c50_uv3[c50_i123] = 1U + 1712U * (uint32_T)c50_i123;
  }

  for (c50_i124 = 0; c50_i124 < 2; c50_i124++) {
    c50_bv1[c50_i124] = c50_bv0[c50_i124];
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 0, 10, 0U, 1,
                   0U, 2, c50_bv1, c50_uv3, c50_tmp_sizes);
  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i125 = 0; c50_i125 <= c50_loop_ub; c50_i125++) {
    c50_y_data[c50_i125] = c50_tmp_data[c50_i125];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_e_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_strcat, const char_T *c50_identifier,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_strcat), &c50_thisId,
    c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_strcat);
}

static void c50_f_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i126;
  uint32_T c50_uv4[2];
  int32_T c50_i127;
  static boolean_T c50_bv2[2] = { false, true };

  boolean_T c50_bv3[2];
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[656];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i128;
  (void)chartInstance;
  for (c50_i126 = 0; c50_i126 < 2; c50_i126++) {
    c50_uv4[c50_i126] = 1U + 655U * (uint32_T)c50_i126;
  }

  for (c50_i127 = 0; c50_i127 < 2; c50_i127++) {
    c50_bv3[c50_i127] = c50_bv2[c50_i127];
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 0, 10, 0U, 1,
                   0U, 2, c50_bv3, c50_uv4, c50_tmp_sizes);
  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i128 = 0; c50_i128 <= c50_loop_ub; c50_i128++) {
    c50_y_data[c50_i128] = c50_tmp_data[c50_i128];
  }

  sf_mex_destroy(&c50_u);
}

static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i129;
  real_T c50_b_inData[2000];
  int32_T c50_i130;
  real_T c50_u[2000];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i129 = 0; c50_i129 < 2000; c50_i129++) {
    c50_b_inData[c50_i129] = (*(real_T (*)[2000])c50_inData)[c50_i129];
  }

  for (c50_i130 = 0; c50_i130 < 2000; c50_i130++) {
    c50_u[c50_i130] = c50_b_inData[c50_i130];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 2000, 1),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_g_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_poseBML, const char_T *c50_identifier,
  real_T c50_y[2000])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_poseBML), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_poseBML);
}

static void c50_h_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[2000])
{
  real_T c50_dv29[2000];
  int32_T c50_i131;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv29, 1, 0, 0U, 1, 0U, 2,
                2000, 1);
  for (c50_i131 = 0; c50_i131 < 2000; c50_i131++) {
    c50_y[c50_i131] = c50_dv29[c50_i131];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_poseBML;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[2000];
  int32_T c50_i132;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_poseBML = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_poseBML), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_poseBML);
  for (c50_i132 = 0; c50_i132 < 2000; c50_i132++) {
    (*(real_T (*)[2000])c50_outData)[c50_i132] = c50_y[c50_i132];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  real_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(real_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_feval;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_feval = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_feval),
    &c50_thisId);
  sf_mex_destroy(&c50_feval);
  *(real_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  boolean_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(boolean_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static boolean_T c50_i_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  boolean_T c50_y;
  boolean_T c50_b3;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_b3, 1, 11, 0U, 0, 0U, 0);
  c50_y = c50_b3;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_aVarTruthTableCondition_2;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  boolean_T c50_y;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_aVarTruthTableCondition_2 = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_aVarTruthTableCondition_2), &c50_thisId);
  sf_mex_destroy(&c50_aVarTruthTableCondition_2);
  *(boolean_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i133;
  real_T c50_b_inData[2000];
  int32_T c50_i134;
  real_T c50_u[2000];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i133 = 0; c50_i133 < 2000; c50_i133++) {
    c50_b_inData[c50_i133] = (*(real_T (*)[2000])c50_inData)[c50_i133];
  }

  for (c50_i134 = 0; c50_i134 < 2000; c50_i134++) {
    c50_u[c50_i134] = c50_b_inData[c50_i134];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 1, 2000), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_j_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[2000])
{
  real_T c50_dv30[2000];
  int32_T c50_i135;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv30, 1, 0, 0U, 1, 0U, 1,
                2000);
  for (c50_i135 = 0; c50_i135 < 2000; c50_i135++) {
    c50_y[c50_i135] = c50_dv30[c50_i135];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_myarr256;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[2000];
  int32_T c50_i136;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_myarr256 = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_myarr256), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_myarr256);
  for (c50_i136 = 0; c50_i136 < 2000; c50_i136++) {
    (*(real_T (*)[2000])c50_outData)[c50_i136] = c50_y[c50_i136];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_e_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i137;
  char_T c50_b_inData[260];
  int32_T c50_i138;
  char_T c50_u[260];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i137 = 0; c50_i137 < 260; c50_i137++) {
    c50_b_inData[c50_i137] = (*(char_T (*)[260])c50_inData)[c50_i137];
  }

  for (c50_i138 = 0; c50_i138 < 260; c50_i138++) {
    c50_u[c50_i138] = c50_b_inData[c50_i138];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 260),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_f_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i139;
  real_T c50_b_inData[260];
  int32_T c50_i140;
  real_T c50_u[260];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i139 = 0; c50_i139 < 260; c50_i139++) {
    c50_b_inData[c50_i139] = (*(real_T (*)[260])c50_inData)[c50_i139];
  }

  for (c50_i140 = 0; c50_i140 < 260; c50_i140++) {
    c50_u[c50_i140] = c50_b_inData[c50_i140];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 1, 260), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_g_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i141;
  char_T c50_b_inData[244];
  int32_T c50_i142;
  char_T c50_u[244];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i141 = 0; c50_i141 < 244; c50_i141++) {
    c50_b_inData[c50_i141] = (*(char_T (*)[244])c50_inData)[c50_i141];
  }

  for (c50_i142 = 0; c50_i142 < 244; c50_i142++) {
    c50_u[c50_i142] = c50_b_inData[c50_i142];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 244),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_h_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i143;
  real_T c50_b_inData[244];
  int32_T c50_i144;
  real_T c50_u[244];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i143 = 0; c50_i143 < 244; c50_i143++) {
    c50_b_inData[c50_i143] = (*(real_T (*)[244])c50_inData)[c50_i143];
  }

  for (c50_i144 = 0; c50_i144 < 244; c50_i144++) {
    c50_u[c50_i144] = c50_b_inData[c50_i144];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 1, 244), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_i_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i145;
  real_T c50_b_inData[15];
  int32_T c50_i146;
  real_T c50_u[15];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i145 = 0; c50_i145 < 15; c50_i145++) {
    c50_b_inData[c50_i145] = (*(real_T (*)[15])c50_inData)[c50_i145];
  }

  for (c50_i146 = 0; c50_i146 < 15; c50_i146++) {
    c50_u[c50_i146] = c50_b_inData[c50_i146];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 15),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_k_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_eAmountFactor, const char_T *c50_identifier,
  real_T c50_y[15])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_eAmountFactor),
    &c50_thisId, c50_y);
  sf_mex_destroy(&c50_eAmountFactor);
}

static void c50_l_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[15])
{
  real_T c50_dv31[15];
  int32_T c50_i147;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv31, 1, 0, 0U, 1, 0U, 2, 1,
                15);
  for (c50_i147 = 0; c50_i147 < 15; c50_i147++) {
    c50_y[c50_i147] = c50_dv31[c50_i147];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_eAmountFactor;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[15];
  int32_T c50_i148;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_eAmountFactor = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_eAmountFactor),
    &c50_thisId, c50_y);
  sf_mex_destroy(&c50_eAmountFactor);
  for (c50_i148 = 0; c50_i148 < 15; c50_i148++) {
    (*(real_T (*)[15])c50_outData)[c50_i148] = c50_y[c50_i148];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_j_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i149;
  int32_T c50_i150;
  int32_T c50_i151;
  real_T c50_b_inData[10000];
  int32_T c50_i152;
  int32_T c50_i153;
  int32_T c50_i154;
  real_T c50_u[10000];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_i149 = 0;
  for (c50_i150 = 0; c50_i150 < 5; c50_i150++) {
    for (c50_i151 = 0; c50_i151 < 2000; c50_i151++) {
      c50_b_inData[c50_i151 + c50_i149] = (*(real_T (*)[10000])c50_inData)
        [c50_i151 + c50_i149];
    }

    c50_i149 += 2000;
  }

  c50_i152 = 0;
  for (c50_i153 = 0; c50_i153 < 5; c50_i153++) {
    for (c50_i154 = 0; c50_i154 < 2000; c50_i154++) {
      c50_u[c50_i154 + c50_i152] = c50_b_inData[c50_i154 + c50_i152];
    }

    c50_i152 += 2000;
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 2000, 5),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_m_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_newBmls, const char_T *c50_identifier,
  real_T c50_y[10000])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_newBmls), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_newBmls);
}

static void c50_n_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[10000])
{
  real_T c50_dv32[10000];
  int32_T c50_i155;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv32, 1, 0, 0U, 1, 0U, 2,
                2000, 5);
  for (c50_i155 = 0; c50_i155 < 10000; c50_i155++) {
    c50_y[c50_i155] = c50_dv32[c50_i155];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_newBmls;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[10000];
  int32_T c50_i156;
  int32_T c50_i157;
  int32_T c50_i158;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_newBmls = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_newBmls), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_newBmls);
  c50_i156 = 0;
  for (c50_i157 = 0; c50_i157 < 5; c50_i157++) {
    for (c50_i158 = 0; c50_i158 < 2000; c50_i158++) {
      (*(real_T (*)[10000])c50_outData)[c50_i158 + c50_i156] = c50_y[c50_i158 +
        c50_i156];
    }

    c50_i156 += 2000;
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_k_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  char_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(char_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_l_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i159;
  real_T c50_b_inData[6];
  int32_T c50_i160;
  real_T c50_u[6];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i159 = 0; c50_i159 < 6; c50_i159++) {
    c50_b_inData[c50_i159] = (*(real_T (*)[6])c50_inData)[c50_i159];
  }

  for (c50_i160 = 0; c50_i160 < 6; c50_i160++) {
    c50_u[c50_i160] = c50_b_inData[c50_i160];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_o_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_AU, const char_T *c50_identifier, real_T
  c50_y[6])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_AU), &c50_thisId, c50_y);
  sf_mex_destroy(&c50_AU);
}

static void c50_p_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[6])
{
  real_T c50_dv33[6];
  int32_T c50_i161;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv33, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c50_i161 = 0; c50_i161 < 6; c50_i161++) {
    c50_y[c50_i161] = c50_dv33[c50_i161];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_AU;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[6];
  int32_T c50_i162;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_AU = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_AU), &c50_thisId, c50_y);
  sf_mex_destroy(&c50_AU);
  for (c50_i162 = 0; c50_i162 < 6; c50_i162++) {
    (*(real_T (*)[6])c50_outData)[c50_i162] = c50_y[c50_i162];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_m_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2])
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_b_inData_sizes[2];
  int32_T c50_loop_ub;
  int32_T c50_i163;
  char_T c50_b_inData_data[1713];
  int32_T c50_u_sizes[2];
  int32_T c50_b_loop_ub;
  int32_T c50_i164;
  char_T c50_u_data[1713];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_b_inData_sizes[0] = 1;
  c50_b_inData_sizes[1] = c50_inData_sizes[1];
  c50_loop_ub = c50_inData_sizes[1] - 1;
  for (c50_i163 = 0; c50_i163 <= c50_loop_ub; c50_i163++) {
    c50_b_inData_data[c50_b_inData_sizes[0] * c50_i163] =
      c50_inData_data[c50_inData_sizes[0] * c50_i163];
  }

  c50_u_sizes[0] = 1;
  c50_u_sizes[1] = c50_b_inData_sizes[1];
  c50_b_loop_ub = c50_b_inData_sizes[1] - 1;
  for (c50_i164 = 0; c50_i164 <= c50_b_loop_ub; c50_i164++) {
    c50_u_data[c50_u_sizes[0] * c50_i164] =
      c50_b_inData_data[c50_b_inData_sizes[0] * c50_i164];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 10, 0U, 1U, 0U, 2,
    c50_u_sizes[0], c50_u_sizes[1]), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_q_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i165;
  uint32_T c50_uv5[2];
  int32_T c50_i166;
  static boolean_T c50_bv4[2] = { false, true };

  boolean_T c50_bv5[2];
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[1713];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i167;
  (void)chartInstance;
  for (c50_i165 = 0; c50_i165 < 2; c50_i165++) {
    c50_uv5[c50_i165] = 1U + 1712U * (uint32_T)c50_i165;
  }

  for (c50_i166 = 0; c50_i166 < 2; c50_i166++) {
    c50_bv5[c50_i166] = c50_bv4[c50_i166];
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c50_bv5, c50_uv5, c50_tmp_sizes);
  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i167 = 0; c50_i167 <= c50_loop_ub; c50_i167++) {
    c50_y_data[c50_i167] = c50_tmp_data[c50_i167];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2])
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y_sizes[2];
  char_T c50_y_data[1713];
  int32_T c50_loop_ub;
  int32_T c50_i168;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_mystr);
  c50_outData_sizes[0] = 1;
  c50_outData_sizes[1] = c50_y_sizes[1];
  c50_loop_ub = c50_y_sizes[1] - 1;
  for (c50_i168 = 0; c50_i168 <= c50_loop_ub; c50_i168++) {
    c50_outData_data[c50_outData_sizes[0] * c50_i168] = c50_y_data[c50_y_sizes[0]
      * c50_i168];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_n_sf_marshallOut(void *chartInstanceVoid, real_T
  c50_inData_data[], int32_T *c50_inData_sizes)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_b_inData_sizes;
  int32_T c50_loop_ub;
  int32_T c50_i169;
  real_T c50_b_inData_data[1713];
  int32_T c50_u_sizes;
  int32_T c50_b_loop_ub;
  int32_T c50_i170;
  real_T c50_u_data[1713];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_b_inData_sizes = *c50_inData_sizes;
  c50_loop_ub = *c50_inData_sizes - 1;
  for (c50_i169 = 0; c50_i169 <= c50_loop_ub; c50_i169++) {
    c50_b_inData_data[c50_i169] = c50_inData_data[c50_i169];
  }

  c50_u_sizes = c50_b_inData_sizes;
  c50_b_loop_ub = c50_b_inData_sizes - 1;
  for (c50_i170 = 0; c50_i170 <= c50_b_loop_ub; c50_i170++) {
    c50_u_data[c50_i170] = c50_b_inData_data[c50_i170];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 0, 0U, 1U, 0U, 1,
    c50_u_sizes), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_r_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y_data[], int32_T *c50_y_sizes)
{
  static uint32_T c50_uv6[1] = { 1713U };

  uint32_T c50_uv7[1];
  static boolean_T c50_bv6[1] = { true };

  boolean_T c50_bv7[1];
  int32_T c50_tmp_sizes;
  real_T c50_tmp_data[1713];
  int32_T c50_loop_ub;
  int32_T c50_i171;
  (void)chartInstance;
  c50_uv7[0] = c50_uv6[0];
  c50_bv7[0] = c50_bv6[0];
  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 1, 0, 0U, 1,
                   0U, 1, c50_bv7, c50_uv7, &c50_tmp_sizes);
  *c50_y_sizes = c50_tmp_sizes;
  c50_loop_ub = c50_tmp_sizes - 1;
  for (c50_i171 = 0; c50_i171 <= c50_loop_ub; c50_i171++) {
    c50_y_data[c50_i171] = c50_tmp_data[c50_i171];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, real_T c50_outData_data[],
  int32_T *c50_outData_sizes)
{
  const mxArray *c50_arr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y_sizes;
  real_T c50_y_data[1713];
  int32_T c50_loop_ub;
  int32_T c50_i172;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_arr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_arr), &c50_thisId,
    c50_y_data, &c50_y_sizes);
  sf_mex_destroy(&c50_arr);
  *c50_outData_sizes = c50_y_sizes;
  c50_loop_ub = c50_y_sizes - 1;
  for (c50_i172 = 0; c50_i172 <= c50_loop_ub; c50_i172++) {
    c50_outData_data[c50_i172] = c50_y_data[c50_i172];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_o_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i173;
  char_T c50_b_inData[103];
  int32_T c50_i174;
  char_T c50_u[103];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i173 = 0; c50_i173 < 103; c50_i173++) {
    c50_b_inData[c50_i173] = (*(char_T (*)[103])c50_inData)[c50_i173];
  }

  for (c50_i174 = 0; c50_i174 < 103; c50_i174++) {
    c50_u[c50_i174] = c50_b_inData[c50_i174];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_s_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[103])
{
  char_T c50_cv12[103];
  int32_T c50_i175;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv12, 1, 10, 0U, 1, 0U, 2,
                1, 103);
  for (c50_i175 = 0; c50_i175 < 103; c50_i175++) {
    c50_y[c50_i175] = c50_cv12[c50_i175];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[103];
  int32_T c50_i176;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i176 = 0; c50_i176 < 103; c50_i176++) {
    (*(char_T (*)[103])c50_outData)[c50_i176] = c50_y[c50_i176];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_p_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i177;
  char_T c50_b_inData[206];
  int32_T c50_i178;
  char_T c50_u[206];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i177 = 0; c50_i177 < 206; c50_i177++) {
    c50_b_inData[c50_i177] = (*(char_T (*)[206])c50_inData)[c50_i177];
  }

  for (c50_i178 = 0; c50_i178 < 206; c50_i178++) {
    c50_u[c50_i178] = c50_b_inData[c50_i178];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 206),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_t_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[206])
{
  char_T c50_cv13[206];
  int32_T c50_i179;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv13, 1, 10, 0U, 1, 0U, 2,
                1, 206);
  for (c50_i179 = 0; c50_i179 < 206; c50_i179++) {
    c50_y[c50_i179] = c50_cv13[c50_i179];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[206];
  int32_T c50_i180;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i180 = 0; c50_i180 < 206; c50_i180++) {
    (*(char_T (*)[206])c50_outData)[c50_i180] = c50_y[c50_i180];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_q_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i181;
  char_T c50_b_inData[306];
  int32_T c50_i182;
  char_T c50_u[306];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i181 = 0; c50_i181 < 306; c50_i181++) {
    c50_b_inData[c50_i181] = (*(char_T (*)[306])c50_inData)[c50_i181];
  }

  for (c50_i182 = 0; c50_i182 < 306; c50_i182++) {
    c50_u[c50_i182] = c50_b_inData[c50_i182];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 306),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_u_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[306])
{
  char_T c50_cv14[306];
  int32_T c50_i183;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv14, 1, 10, 0U, 1, 0U, 2,
                1, 306);
  for (c50_i183 = 0; c50_i183 < 306; c50_i183++) {
    c50_y[c50_i183] = c50_cv14[c50_i183];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[306];
  int32_T c50_i184;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i184 = 0; c50_i184 < 306; c50_i184++) {
    (*(char_T (*)[306])c50_outData)[c50_i184] = c50_y[c50_i184];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_r_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i185;
  char_T c50_b_inData[412];
  int32_T c50_i186;
  char_T c50_u[412];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i185 = 0; c50_i185 < 412; c50_i185++) {
    c50_b_inData[c50_i185] = (*(char_T (*)[412])c50_inData)[c50_i185];
  }

  for (c50_i186 = 0; c50_i186 < 412; c50_i186++) {
    c50_u[c50_i186] = c50_b_inData[c50_i186];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 412),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_v_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[412])
{
  char_T c50_cv15[412];
  int32_T c50_i187;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv15, 1, 10, 0U, 1, 0U, 2,
                1, 412);
  for (c50_i187 = 0; c50_i187 < 412; c50_i187++) {
    c50_y[c50_i187] = c50_cv15[c50_i187];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[412];
  int32_T c50_i188;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i188 = 0; c50_i188 < 412; c50_i188++) {
    (*(char_T (*)[412])c50_outData)[c50_i188] = c50_y[c50_i188];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_s_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i189;
  char_T c50_b_inData[515];
  int32_T c50_i190;
  char_T c50_u[515];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i189 = 0; c50_i189 < 515; c50_i189++) {
    c50_b_inData[c50_i189] = (*(char_T (*)[515])c50_inData)[c50_i189];
  }

  for (c50_i190 = 0; c50_i190 < 515; c50_i190++) {
    c50_u[c50_i190] = c50_b_inData[c50_i190];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 515),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_w_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[515])
{
  char_T c50_cv16[515];
  int32_T c50_i191;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv16, 1, 10, 0U, 1, 0U, 2,
                1, 515);
  for (c50_i191 = 0; c50_i191 < 515; c50_i191++) {
    c50_y[c50_i191] = c50_cv16[c50_i191];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[515];
  int32_T c50_i192;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i192 = 0; c50_i192 < 515; c50_i192++) {
    (*(char_T (*)[515])c50_outData)[c50_i192] = c50_y[c50_i192];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_t_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i193;
  char_T c50_b_inData[656];
  int32_T c50_i194;
  char_T c50_u[656];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i193 = 0; c50_i193 < 656; c50_i193++) {
    c50_b_inData[c50_i193] = (*(char_T (*)[656])c50_inData)[c50_i193];
  }

  for (c50_i194 = 0; c50_i194 < 656; c50_i194++) {
    c50_u[c50_i194] = c50_b_inData[c50_i194];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 656),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_x_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[656])
{
  char_T c50_cv17[656];
  int32_T c50_i195;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv17, 1, 10, 0U, 1, 0U, 2,
                1, 656);
  for (c50_i195 = 0; c50_i195 < 656; c50_i195++) {
    c50_y[c50_i195] = c50_cv17[c50_i195];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[656];
  int32_T c50_i196;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i196 = 0; c50_i196 < 656; c50_i196++) {
    (*(char_T (*)[656])c50_outData)[c50_i196] = c50_y[c50_i196];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_u_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i197;
  char_T c50_b_inData[759];
  int32_T c50_i198;
  char_T c50_u[759];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i197 = 0; c50_i197 < 759; c50_i197++) {
    c50_b_inData[c50_i197] = (*(char_T (*)[759])c50_inData)[c50_i197];
  }

  for (c50_i198 = 0; c50_i198 < 759; c50_i198++) {
    c50_u[c50_i198] = c50_b_inData[c50_i198];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 759),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_y_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[759])
{
  char_T c50_cv18[759];
  int32_T c50_i199;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv18, 1, 10, 0U, 1, 0U, 2,
                1, 759);
  for (c50_i199 = 0; c50_i199 < 759; c50_i199++) {
    c50_y[c50_i199] = c50_cv18[c50_i199];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[759];
  int32_T c50_i200;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i200 = 0; c50_i200 < 759; c50_i200++) {
    (*(char_T (*)[759])c50_outData)[c50_i200] = c50_y[c50_i200];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_v_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i201;
  char_T c50_b_inData[862];
  int32_T c50_i202;
  char_T c50_u[862];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i201 = 0; c50_i201 < 862; c50_i201++) {
    c50_b_inData[c50_i201] = (*(char_T (*)[862])c50_inData)[c50_i201];
  }

  for (c50_i202 = 0; c50_i202 < 862; c50_i202++) {
    c50_u[c50_i202] = c50_b_inData[c50_i202];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 862),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_ab_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[862])
{
  char_T c50_cv19[862];
  int32_T c50_i203;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv19, 1, 10, 0U, 1, 0U, 2,
                1, 862);
  for (c50_i203 = 0; c50_i203 < 862; c50_i203++) {
    c50_y[c50_i203] = c50_cv19[c50_i203];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[862];
  int32_T c50_i204;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i204 = 0; c50_i204 < 862; c50_i204++) {
    (*(char_T (*)[862])c50_outData)[c50_i204] = c50_y[c50_i204];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_w_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i205;
  char_T c50_b_inData[965];
  int32_T c50_i206;
  char_T c50_u[965];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i205 = 0; c50_i205 < 965; c50_i205++) {
    c50_b_inData[c50_i205] = (*(char_T (*)[965])c50_inData)[c50_i205];
  }

  for (c50_i206 = 0; c50_i206 < 965; c50_i206++) {
    c50_u[c50_i206] = c50_b_inData[c50_i206];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 965),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_bb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[965])
{
  char_T c50_cv20[965];
  int32_T c50_i207;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv20, 1, 10, 0U, 1, 0U, 2,
                1, 965);
  for (c50_i207 = 0; c50_i207 < 965; c50_i207++) {
    c50_y[c50_i207] = c50_cv20[c50_i207];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[965];
  int32_T c50_i208;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i208 = 0; c50_i208 < 965; c50_i208++) {
    (*(char_T (*)[965])c50_outData)[c50_i208] = c50_y[c50_i208];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_x_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i209;
  char_T c50_b_inData[1068];
  int32_T c50_i210;
  char_T c50_u[1068];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i209 = 0; c50_i209 < 1068; c50_i209++) {
    c50_b_inData[c50_i209] = (*(char_T (*)[1068])c50_inData)[c50_i209];
  }

  for (c50_i210 = 0; c50_i210 < 1068; c50_i210++) {
    c50_u[c50_i210] = c50_b_inData[c50_i210];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 1068),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_cb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1068])
{
  char_T c50_cv21[1068];
  int32_T c50_i211;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv21, 1, 10, 0U, 1, 0U, 2,
                1, 1068);
  for (c50_i211 = 0; c50_i211 < 1068; c50_i211++) {
    c50_y[c50_i211] = c50_cv21[c50_i211];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[1068];
  int32_T c50_i212;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i212 = 0; c50_i212 < 1068; c50_i212++) {
    (*(char_T (*)[1068])c50_outData)[c50_i212] = c50_y[c50_i212];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_y_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i213;
  char_T c50_b_inData[1171];
  int32_T c50_i214;
  char_T c50_u[1171];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i213 = 0; c50_i213 < 1171; c50_i213++) {
    c50_b_inData[c50_i213] = (*(char_T (*)[1171])c50_inData)[c50_i213];
  }

  for (c50_i214 = 0; c50_i214 < 1171; c50_i214++) {
    c50_u[c50_i214] = c50_b_inData[c50_i214];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 1171),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_db_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1171])
{
  char_T c50_cv22[1171];
  int32_T c50_i215;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv22, 1, 10, 0U, 1, 0U, 2,
                1, 1171);
  for (c50_i215 = 0; c50_i215 < 1171; c50_i215++) {
    c50_y[c50_i215] = c50_cv22[c50_i215];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[1171];
  int32_T c50_i216;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i216 = 0; c50_i216 < 1171; c50_i216++) {
    (*(char_T (*)[1171])c50_outData)[c50_i216] = c50_y[c50_i216];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i217;
  char_T c50_b_inData[1474];
  int32_T c50_i218;
  char_T c50_u[1474];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i217 = 0; c50_i217 < 1474; c50_i217++) {
    c50_b_inData[c50_i217] = (*(char_T (*)[1474])c50_inData)[c50_i217];
  }

  for (c50_i218 = 0; c50_i218 < 1474; c50_i218++) {
    c50_u[c50_i218] = c50_b_inData[c50_i218];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 1474),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_eb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1474])
{
  char_T c50_cv23[1474];
  int32_T c50_i219;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv23, 1, 10, 0U, 1, 0U, 2,
                1, 1474);
  for (c50_i219 = 0; c50_i219 < 1474; c50_i219++) {
    c50_y[c50_i219] = c50_cv23[c50_i219];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[1474];
  int32_T c50_i220;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i220 = 0; c50_i220 < 1474; c50_i220++) {
    (*(char_T (*)[1474])c50_outData)[c50_i220] = c50_y[c50_i220];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i221;
  char_T c50_b_inData[1577];
  int32_T c50_i222;
  char_T c50_u[1577];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i221 = 0; c50_i221 < 1577; c50_i221++) {
    c50_b_inData[c50_i221] = (*(char_T (*)[1577])c50_inData)[c50_i221];
  }

  for (c50_i222 = 0; c50_i222 < 1577; c50_i222++) {
    c50_u[c50_i222] = c50_b_inData[c50_i222];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 1577),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_fb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1577])
{
  char_T c50_cv24[1577];
  int32_T c50_i223;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv24, 1, 10, 0U, 1, 0U, 2,
                1, 1577);
  for (c50_i223 = 0; c50_i223 < 1577; c50_i223++) {
    c50_y[c50_i223] = c50_cv24[c50_i223];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[1577];
  int32_T c50_i224;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i224 = 0; c50_i224 < 1577; c50_i224++) {
    (*(char_T (*)[1577])c50_outData)[c50_i224] = c50_y[c50_i224];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i225;
  char_T c50_b_inData[1610];
  int32_T c50_i226;
  char_T c50_u[1610];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i225 = 0; c50_i225 < 1610; c50_i225++) {
    c50_b_inData[c50_i225] = (*(char_T (*)[1610])c50_inData)[c50_i225];
  }

  for (c50_i226 = 0; c50_i226 < 1610; c50_i226++) {
    c50_u[c50_i226] = c50_b_inData[c50_i226];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 1610),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_gb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1610])
{
  char_T c50_cv25[1610];
  int32_T c50_i227;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv25, 1, 10, 0U, 1, 0U, 2,
                1, 1610);
  for (c50_i227 = 0; c50_i227 < 1610; c50_i227++) {
    c50_y[c50_i227] = c50_cv25[c50_i227];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[1610];
  int32_T c50_i228;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i228 = 0; c50_i228 < 1610; c50_i228++) {
    (*(char_T (*)[1610])c50_outData)[c50_i228] = c50_y[c50_i228];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_db_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i229;
  char_T c50_b_inData[1713];
  int32_T c50_i230;
  char_T c50_u[1713];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i229 = 0; c50_i229 < 1713; c50_i229++) {
    c50_b_inData[c50_i229] = (*(char_T (*)[1713])c50_inData)[c50_i229];
  }

  for (c50_i230 = 0; c50_i230 < 1713; c50_i230++) {
    c50_u[c50_i230] = c50_b_inData[c50_i230];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 1713),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_hb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[1713])
{
  char_T c50_cv26[1713];
  int32_T c50_i231;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv26, 1, 10, 0U, 1, 0U, 2,
                1, 1713);
  for (c50_i231 = 0; c50_i231 < 1713; c50_i231++) {
    c50_y[c50_i231] = c50_cv26[c50_i231];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[1713];
  int32_T c50_i232;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i232 = 0; c50_i232 < 1713; c50_i232++) {
    (*(char_T (*)[1713])c50_outData)[c50_i232] = c50_y[c50_i232];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  const mxArray *c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = sf_mex_dup(*(const mxArray **)c50_inData);
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_duplicatearraysafe(&c50_u), false);
  sf_mex_destroy(&c50_u);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_fb_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2])
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_b_inData_sizes[2];
  int32_T c50_loop_ub;
  int32_T c50_i233;
  char_T c50_b_inData_data[2000];
  int32_T c50_u_sizes[2];
  int32_T c50_b_loop_ub;
  int32_T c50_i234;
  char_T c50_u_data[2000];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_b_inData_sizes[0] = 1;
  c50_b_inData_sizes[1] = c50_inData_sizes[1];
  c50_loop_ub = c50_inData_sizes[1] - 1;
  for (c50_i233 = 0; c50_i233 <= c50_loop_ub; c50_i233++) {
    c50_b_inData_data[c50_b_inData_sizes[0] * c50_i233] =
      c50_inData_data[c50_inData_sizes[0] * c50_i233];
  }

  c50_u_sizes[0] = 1;
  c50_u_sizes[1] = c50_b_inData_sizes[1];
  c50_b_loop_ub = c50_b_inData_sizes[1] - 1;
  for (c50_i234 = 0; c50_i234 <= c50_b_loop_ub; c50_i234++) {
    c50_u_data[c50_u_sizes[0] * c50_i234] =
      c50_b_inData_data[c50_b_inData_sizes[0] * c50_i234];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 10, 0U, 1U, 0U, 2,
    c50_u_sizes[0], c50_u_sizes[1]), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_ib_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i235;
  uint32_T c50_uv8[2];
  int32_T c50_i236;
  static boolean_T c50_bv8[2] = { false, true };

  boolean_T c50_bv9[2];
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[2000];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i237;
  (void)chartInstance;
  for (c50_i235 = 0; c50_i235 < 2; c50_i235++) {
    c50_uv8[c50_i235] = 1U + 1999U * (uint32_T)c50_i235;
  }

  for (c50_i236 = 0; c50_i236 < 2; c50_i236++) {
    c50_bv9[c50_i236] = c50_bv8[c50_i236];
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c50_bv9, c50_uv8, c50_tmp_sizes);
  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i237 = 0; c50_i237 <= c50_loop_ub; c50_i237++) {
    c50_y_data[c50_i237] = c50_tmp_data[c50_i237];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2])
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y_sizes[2];
  char_T c50_y_data[2000];
  int32_T c50_loop_ub;
  int32_T c50_i238;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_mystr);
  c50_outData_sizes[0] = 1;
  c50_outData_sizes[1] = c50_y_sizes[1];
  c50_loop_ub = c50_y_sizes[1] - 1;
  for (c50_i238 = 0; c50_i238 <= c50_loop_ub; c50_i238++) {
    c50_outData_data[c50_outData_sizes[0] * c50_i238] = c50_y_data[c50_y_sizes[0]
      * c50_i238];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_gb_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2])
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_b_inData_sizes[2];
  int32_T c50_loop_ub;
  int32_T c50_i239;
  char_T c50_b_inData_data[656];
  int32_T c50_u_sizes[2];
  int32_T c50_b_loop_ub;
  int32_T c50_i240;
  char_T c50_u_data[656];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_b_inData_sizes[0] = 1;
  c50_b_inData_sizes[1] = c50_inData_sizes[1];
  c50_loop_ub = c50_inData_sizes[1] - 1;
  for (c50_i239 = 0; c50_i239 <= c50_loop_ub; c50_i239++) {
    c50_b_inData_data[c50_b_inData_sizes[0] * c50_i239] =
      c50_inData_data[c50_inData_sizes[0] * c50_i239];
  }

  c50_u_sizes[0] = 1;
  c50_u_sizes[1] = c50_b_inData_sizes[1];
  c50_b_loop_ub = c50_b_inData_sizes[1] - 1;
  for (c50_i240 = 0; c50_i240 <= c50_b_loop_ub; c50_i240++) {
    c50_u_data[c50_u_sizes[0] * c50_i240] =
      c50_b_inData_data[c50_b_inData_sizes[0] * c50_i240];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 10, 0U, 1U, 0U, 2,
    c50_u_sizes[0], c50_u_sizes[1]), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_jb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i241;
  uint32_T c50_uv9[2];
  int32_T c50_i242;
  static boolean_T c50_bv10[2] = { false, true };

  boolean_T c50_bv11[2];
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[656];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i243;
  (void)chartInstance;
  for (c50_i241 = 0; c50_i241 < 2; c50_i241++) {
    c50_uv9[c50_i241] = 1U + 655U * (uint32_T)c50_i241;
  }

  for (c50_i242 = 0; c50_i242 < 2; c50_i242++) {
    c50_bv11[c50_i242] = c50_bv10[c50_i242];
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c50_bv11, c50_uv9, c50_tmp_sizes);
  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i243 = 0; c50_i243 <= c50_loop_ub; c50_i243++) {
    c50_y_data[c50_i243] = c50_tmp_data[c50_i243];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2])
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y_sizes[2];
  char_T c50_y_data[656];
  int32_T c50_loop_ub;
  int32_T c50_i244;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_mystr);
  c50_outData_sizes[0] = 1;
  c50_outData_sizes[1] = c50_y_sizes[1];
  c50_loop_ub = c50_y_sizes[1] - 1;
  for (c50_i244 = 0; c50_i244 <= c50_loop_ub; c50_i244++) {
    c50_outData_data[c50_outData_sizes[0] * c50_i244] = c50_y_data[c50_y_sizes[0]
      * c50_i244];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

const mxArray *sf_c50_Demo_AUV_VA_get_eml_resolved_functions_info(void)
{
  const mxArray *c50_nameCaptureInfo = NULL;
  c50_nameCaptureInfo = NULL;
  sf_mex_assign(&c50_nameCaptureInfo, sf_mex_createstruct("structure", 2, 129, 1),
                false);
  c50_info_helper(&c50_nameCaptureInfo);
  c50_b_info_helper(&c50_nameCaptureInfo);
  c50_c_info_helper(&c50_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c50_nameCaptureInfo);
  return c50_nameCaptureInfo;
}

static void c50_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs0 = NULL;
  const mxArray *c50_lhs0 = NULL;
  const mxArray *c50_rhs1 = NULL;
  const mxArray *c50_lhs1 = NULL;
  const mxArray *c50_rhs2 = NULL;
  const mxArray *c50_lhs2 = NULL;
  const mxArray *c50_rhs3 = NULL;
  const mxArray *c50_lhs3 = NULL;
  const mxArray *c50_rhs4 = NULL;
  const mxArray *c50_lhs4 = NULL;
  const mxArray *c50_rhs5 = NULL;
  const mxArray *c50_lhs5 = NULL;
  const mxArray *c50_rhs6 = NULL;
  const mxArray *c50_lhs6 = NULL;
  const mxArray *c50_rhs7 = NULL;
  const mxArray *c50_lhs7 = NULL;
  const mxArray *c50_rhs8 = NULL;
  const mxArray *c50_lhs8 = NULL;
  const mxArray *c50_rhs9 = NULL;
  const mxArray *c50_lhs9 = NULL;
  const mxArray *c50_rhs10 = NULL;
  const mxArray *c50_lhs10 = NULL;
  const mxArray *c50_rhs11 = NULL;
  const mxArray *c50_lhs11 = NULL;
  const mxArray *c50_rhs12 = NULL;
  const mxArray *c50_lhs12 = NULL;
  const mxArray *c50_rhs13 = NULL;
  const mxArray *c50_lhs13 = NULL;
  const mxArray *c50_rhs14 = NULL;
  const mxArray *c50_lhs14 = NULL;
  const mxArray *c50_rhs15 = NULL;
  const mxArray *c50_lhs15 = NULL;
  const mxArray *c50_rhs16 = NULL;
  const mxArray *c50_lhs16 = NULL;
  const mxArray *c50_rhs17 = NULL;
  const mxArray *c50_lhs17 = NULL;
  const mxArray *c50_rhs18 = NULL;
  const mxArray *c50_lhs18 = NULL;
  const mxArray *c50_rhs19 = NULL;
  const mxArray *c50_lhs19 = NULL;
  const mxArray *c50_rhs20 = NULL;
  const mxArray *c50_lhs20 = NULL;
  const mxArray *c50_rhs21 = NULL;
  const mxArray *c50_lhs21 = NULL;
  const mxArray *c50_rhs22 = NULL;
  const mxArray *c50_lhs22 = NULL;
  const mxArray *c50_rhs23 = NULL;
  const mxArray *c50_lhs23 = NULL;
  const mxArray *c50_rhs24 = NULL;
  const mxArray *c50_lhs24 = NULL;
  const mxArray *c50_rhs25 = NULL;
  const mxArray *c50_lhs25 = NULL;
  const mxArray *c50_rhs26 = NULL;
  const mxArray *c50_lhs26 = NULL;
  const mxArray *c50_rhs27 = NULL;
  const mxArray *c50_lhs27 = NULL;
  const mxArray *c50_rhs28 = NULL;
  const mxArray *c50_lhs28 = NULL;
  const mxArray *c50_rhs29 = NULL;
  const mxArray *c50_lhs29 = NULL;
  const mxArray *c50_rhs30 = NULL;
  const mxArray *c50_lhs30 = NULL;
  const mxArray *c50_rhs31 = NULL;
  const mxArray *c50_lhs31 = NULL;
  const mxArray *c50_rhs32 = NULL;
  const mxArray *c50_lhs32 = NULL;
  const mxArray *c50_rhs33 = NULL;
  const mxArray *c50_lhs33 = NULL;
  const mxArray *c50_rhs34 = NULL;
  const mxArray *c50_lhs34 = NULL;
  const mxArray *c50_rhs35 = NULL;
  const mxArray *c50_lhs35 = NULL;
  const mxArray *c50_rhs36 = NULL;
  const mxArray *c50_lhs36 = NULL;
  const mxArray *c50_rhs37 = NULL;
  const mxArray *c50_lhs37 = NULL;
  const mxArray *c50_rhs38 = NULL;
  const mxArray *c50_lhs38 = NULL;
  const mxArray *c50_rhs39 = NULL;
  const mxArray *c50_lhs39 = NULL;
  const mxArray *c50_rhs40 = NULL;
  const mxArray *c50_lhs40 = NULL;
  const mxArray *c50_rhs41 = NULL;
  const mxArray *c50_lhs41 = NULL;
  const mxArray *c50_rhs42 = NULL;
  const mxArray *c50_lhs42 = NULL;
  const mxArray *c50_rhs43 = NULL;
  const mxArray *c50_lhs43 = NULL;
  const mxArray *c50_rhs44 = NULL;
  const mxArray *c50_lhs44 = NULL;
  const mxArray *c50_rhs45 = NULL;
  const mxArray *c50_lhs45 = NULL;
  const mxArray *c50_rhs46 = NULL;
  const mxArray *c50_lhs46 = NULL;
  const mxArray *c50_rhs47 = NULL;
  const mxArray *c50_lhs47 = NULL;
  const mxArray *c50_rhs48 = NULL;
  const mxArray *c50_lhs48 = NULL;
  const mxArray *c50_rhs49 = NULL;
  const mxArray *c50_lhs49 = NULL;
  const mxArray *c50_rhs50 = NULL;
  const mxArray *c50_lhs50 = NULL;
  const mxArray *c50_rhs51 = NULL;
  const mxArray *c50_lhs51 = NULL;
  const mxArray *c50_rhs52 = NULL;
  const mxArray *c50_lhs52 = NULL;
  const mxArray *c50_rhs53 = NULL;
  const mxArray *c50_lhs53 = NULL;
  const mxArray *c50_rhs54 = NULL;
  const mxArray *c50_lhs54 = NULL;
  const mxArray *c50_rhs55 = NULL;
  const mxArray *c50_lhs55 = NULL;
  const mxArray *c50_rhs56 = NULL;
  const mxArray *c50_lhs56 = NULL;
  const mxArray *c50_rhs57 = NULL;
  const mxArray *c50_lhs57 = NULL;
  const mxArray *c50_rhs58 = NULL;
  const mxArray *c50_lhs58 = NULL;
  const mxArray *c50_rhs59 = NULL;
  const mxArray *c50_lhs59 = NULL;
  const mxArray *c50_rhs60 = NULL;
  const mxArray *c50_lhs60 = NULL;
  const mxArray *c50_rhs61 = NULL;
  const mxArray *c50_lhs61 = NULL;
  const mxArray *c50_rhs62 = NULL;
  const mxArray *c50_lhs62 = NULL;
  const mxArray *c50_rhs63 = NULL;
  const mxArray *c50_lhs63 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1452377975U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c50_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mrdivide"), "name", "name",
                  1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c50_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c50_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c50_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c50_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c50_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c50_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c50_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isequal"), "name", "name", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c50_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c50_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isnan"), "name", "name", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c50_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c50_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("disp"), "name", "name", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 12);
  sf_mex_assign(&c50_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("abs"), "name", "name", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c50_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c50_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c50_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("randi"), "name", "name", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c50_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c50_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("rand"), "name", "name", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c50_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c50_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand"), "name", "name",
                  20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c50_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c50_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c50_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c50_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c50_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c50_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c50_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c50_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c50_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c50_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c50_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c50_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eps"), "name", "name", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c50_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_eps"), "name", "name",
                  33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c50_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c50_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isequal"), "name", "name",
                  35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c50_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c50_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c50_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c50_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_error"), "name", "name",
                  39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c50_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("floor"), "name", "name", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c50_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c50_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c50_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("cmdBML_AU_VA"), "name",
                  "name", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1452379246U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c50_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("abs"), "name", "name", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c50_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("log10"), "name", "name", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343862782U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c50_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_error"), "name", "name",
                  46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c50_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851128U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c50_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("realmax"), "name", "name",
                  48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1307683642U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c50_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c50_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c50_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mrdivide"), "name", "name",
                  51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c50_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("ceil"), "name", "name", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c50_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c50_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_ceil"), "name",
                  "name", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_ceil.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851120U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c50_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("max"), "name", "name", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1311287716U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c50_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328384U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c50_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c50_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c50_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c50_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c50_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c50_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c50_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 63);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 63);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c50_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c50_rhs0);
  sf_mex_destroy(&c50_lhs0);
  sf_mex_destroy(&c50_rhs1);
  sf_mex_destroy(&c50_lhs1);
  sf_mex_destroy(&c50_rhs2);
  sf_mex_destroy(&c50_lhs2);
  sf_mex_destroy(&c50_rhs3);
  sf_mex_destroy(&c50_lhs3);
  sf_mex_destroy(&c50_rhs4);
  sf_mex_destroy(&c50_lhs4);
  sf_mex_destroy(&c50_rhs5);
  sf_mex_destroy(&c50_lhs5);
  sf_mex_destroy(&c50_rhs6);
  sf_mex_destroy(&c50_lhs6);
  sf_mex_destroy(&c50_rhs7);
  sf_mex_destroy(&c50_lhs7);
  sf_mex_destroy(&c50_rhs8);
  sf_mex_destroy(&c50_lhs8);
  sf_mex_destroy(&c50_rhs9);
  sf_mex_destroy(&c50_lhs9);
  sf_mex_destroy(&c50_rhs10);
  sf_mex_destroy(&c50_lhs10);
  sf_mex_destroy(&c50_rhs11);
  sf_mex_destroy(&c50_lhs11);
  sf_mex_destroy(&c50_rhs12);
  sf_mex_destroy(&c50_lhs12);
  sf_mex_destroy(&c50_rhs13);
  sf_mex_destroy(&c50_lhs13);
  sf_mex_destroy(&c50_rhs14);
  sf_mex_destroy(&c50_lhs14);
  sf_mex_destroy(&c50_rhs15);
  sf_mex_destroy(&c50_lhs15);
  sf_mex_destroy(&c50_rhs16);
  sf_mex_destroy(&c50_lhs16);
  sf_mex_destroy(&c50_rhs17);
  sf_mex_destroy(&c50_lhs17);
  sf_mex_destroy(&c50_rhs18);
  sf_mex_destroy(&c50_lhs18);
  sf_mex_destroy(&c50_rhs19);
  sf_mex_destroy(&c50_lhs19);
  sf_mex_destroy(&c50_rhs20);
  sf_mex_destroy(&c50_lhs20);
  sf_mex_destroy(&c50_rhs21);
  sf_mex_destroy(&c50_lhs21);
  sf_mex_destroy(&c50_rhs22);
  sf_mex_destroy(&c50_lhs22);
  sf_mex_destroy(&c50_rhs23);
  sf_mex_destroy(&c50_lhs23);
  sf_mex_destroy(&c50_rhs24);
  sf_mex_destroy(&c50_lhs24);
  sf_mex_destroy(&c50_rhs25);
  sf_mex_destroy(&c50_lhs25);
  sf_mex_destroy(&c50_rhs26);
  sf_mex_destroy(&c50_lhs26);
  sf_mex_destroy(&c50_rhs27);
  sf_mex_destroy(&c50_lhs27);
  sf_mex_destroy(&c50_rhs28);
  sf_mex_destroy(&c50_lhs28);
  sf_mex_destroy(&c50_rhs29);
  sf_mex_destroy(&c50_lhs29);
  sf_mex_destroy(&c50_rhs30);
  sf_mex_destroy(&c50_lhs30);
  sf_mex_destroy(&c50_rhs31);
  sf_mex_destroy(&c50_lhs31);
  sf_mex_destroy(&c50_rhs32);
  sf_mex_destroy(&c50_lhs32);
  sf_mex_destroy(&c50_rhs33);
  sf_mex_destroy(&c50_lhs33);
  sf_mex_destroy(&c50_rhs34);
  sf_mex_destroy(&c50_lhs34);
  sf_mex_destroy(&c50_rhs35);
  sf_mex_destroy(&c50_lhs35);
  sf_mex_destroy(&c50_rhs36);
  sf_mex_destroy(&c50_lhs36);
  sf_mex_destroy(&c50_rhs37);
  sf_mex_destroy(&c50_lhs37);
  sf_mex_destroy(&c50_rhs38);
  sf_mex_destroy(&c50_lhs38);
  sf_mex_destroy(&c50_rhs39);
  sf_mex_destroy(&c50_lhs39);
  sf_mex_destroy(&c50_rhs40);
  sf_mex_destroy(&c50_lhs40);
  sf_mex_destroy(&c50_rhs41);
  sf_mex_destroy(&c50_lhs41);
  sf_mex_destroy(&c50_rhs42);
  sf_mex_destroy(&c50_lhs42);
  sf_mex_destroy(&c50_rhs43);
  sf_mex_destroy(&c50_lhs43);
  sf_mex_destroy(&c50_rhs44);
  sf_mex_destroy(&c50_lhs44);
  sf_mex_destroy(&c50_rhs45);
  sf_mex_destroy(&c50_lhs45);
  sf_mex_destroy(&c50_rhs46);
  sf_mex_destroy(&c50_lhs46);
  sf_mex_destroy(&c50_rhs47);
  sf_mex_destroy(&c50_lhs47);
  sf_mex_destroy(&c50_rhs48);
  sf_mex_destroy(&c50_lhs48);
  sf_mex_destroy(&c50_rhs49);
  sf_mex_destroy(&c50_lhs49);
  sf_mex_destroy(&c50_rhs50);
  sf_mex_destroy(&c50_lhs50);
  sf_mex_destroy(&c50_rhs51);
  sf_mex_destroy(&c50_lhs51);
  sf_mex_destroy(&c50_rhs52);
  sf_mex_destroy(&c50_lhs52);
  sf_mex_destroy(&c50_rhs53);
  sf_mex_destroy(&c50_lhs53);
  sf_mex_destroy(&c50_rhs54);
  sf_mex_destroy(&c50_lhs54);
  sf_mex_destroy(&c50_rhs55);
  sf_mex_destroy(&c50_lhs55);
  sf_mex_destroy(&c50_rhs56);
  sf_mex_destroy(&c50_lhs56);
  sf_mex_destroy(&c50_rhs57);
  sf_mex_destroy(&c50_lhs57);
  sf_mex_destroy(&c50_rhs58);
  sf_mex_destroy(&c50_lhs58);
  sf_mex_destroy(&c50_rhs59);
  sf_mex_destroy(&c50_lhs59);
  sf_mex_destroy(&c50_rhs60);
  sf_mex_destroy(&c50_lhs60);
  sf_mex_destroy(&c50_rhs61);
  sf_mex_destroy(&c50_lhs61);
  sf_mex_destroy(&c50_rhs62);
  sf_mex_destroy(&c50_lhs62);
  sf_mex_destroy(&c50_rhs63);
  sf_mex_destroy(&c50_lhs63);
}

static const mxArray *c50_emlrt_marshallOut(const char * c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c50_u)), false);
  return c50_y;
}

static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 7, 0U, 0U, 0U, 0), false);
  return c50_y;
}

static void c50_b_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs64 = NULL;
  const mxArray *c50_lhs64 = NULL;
  const mxArray *c50_rhs65 = NULL;
  const mxArray *c50_lhs65 = NULL;
  const mxArray *c50_rhs66 = NULL;
  const mxArray *c50_lhs66 = NULL;
  const mxArray *c50_rhs67 = NULL;
  const mxArray *c50_lhs67 = NULL;
  const mxArray *c50_rhs68 = NULL;
  const mxArray *c50_lhs68 = NULL;
  const mxArray *c50_rhs69 = NULL;
  const mxArray *c50_lhs69 = NULL;
  const mxArray *c50_rhs70 = NULL;
  const mxArray *c50_lhs70 = NULL;
  const mxArray *c50_rhs71 = NULL;
  const mxArray *c50_lhs71 = NULL;
  const mxArray *c50_rhs72 = NULL;
  const mxArray *c50_lhs72 = NULL;
  const mxArray *c50_rhs73 = NULL;
  const mxArray *c50_lhs73 = NULL;
  const mxArray *c50_rhs74 = NULL;
  const mxArray *c50_lhs74 = NULL;
  const mxArray *c50_rhs75 = NULL;
  const mxArray *c50_lhs75 = NULL;
  const mxArray *c50_rhs76 = NULL;
  const mxArray *c50_lhs76 = NULL;
  const mxArray *c50_rhs77 = NULL;
  const mxArray *c50_lhs77 = NULL;
  const mxArray *c50_rhs78 = NULL;
  const mxArray *c50_lhs78 = NULL;
  const mxArray *c50_rhs79 = NULL;
  const mxArray *c50_lhs79 = NULL;
  const mxArray *c50_rhs80 = NULL;
  const mxArray *c50_lhs80 = NULL;
  const mxArray *c50_rhs81 = NULL;
  const mxArray *c50_lhs81 = NULL;
  const mxArray *c50_rhs82 = NULL;
  const mxArray *c50_lhs82 = NULL;
  const mxArray *c50_rhs83 = NULL;
  const mxArray *c50_lhs83 = NULL;
  const mxArray *c50_rhs84 = NULL;
  const mxArray *c50_lhs84 = NULL;
  const mxArray *c50_rhs85 = NULL;
  const mxArray *c50_lhs85 = NULL;
  const mxArray *c50_rhs86 = NULL;
  const mxArray *c50_lhs86 = NULL;
  const mxArray *c50_rhs87 = NULL;
  const mxArray *c50_lhs87 = NULL;
  const mxArray *c50_rhs88 = NULL;
  const mxArray *c50_lhs88 = NULL;
  const mxArray *c50_rhs89 = NULL;
  const mxArray *c50_lhs89 = NULL;
  const mxArray *c50_rhs90 = NULL;
  const mxArray *c50_lhs90 = NULL;
  const mxArray *c50_rhs91 = NULL;
  const mxArray *c50_lhs91 = NULL;
  const mxArray *c50_rhs92 = NULL;
  const mxArray *c50_lhs92 = NULL;
  const mxArray *c50_rhs93 = NULL;
  const mxArray *c50_lhs93 = NULL;
  const mxArray *c50_rhs94 = NULL;
  const mxArray *c50_lhs94 = NULL;
  const mxArray *c50_rhs95 = NULL;
  const mxArray *c50_lhs95 = NULL;
  const mxArray *c50_rhs96 = NULL;
  const mxArray *c50_lhs96 = NULL;
  const mxArray *c50_rhs97 = NULL;
  const mxArray *c50_lhs97 = NULL;
  const mxArray *c50_rhs98 = NULL;
  const mxArray *c50_lhs98 = NULL;
  const mxArray *c50_rhs99 = NULL;
  const mxArray *c50_lhs99 = NULL;
  const mxArray *c50_rhs100 = NULL;
  const mxArray *c50_lhs100 = NULL;
  const mxArray *c50_rhs101 = NULL;
  const mxArray *c50_lhs101 = NULL;
  const mxArray *c50_rhs102 = NULL;
  const mxArray *c50_lhs102 = NULL;
  const mxArray *c50_rhs103 = NULL;
  const mxArray *c50_lhs103 = NULL;
  const mxArray *c50_rhs104 = NULL;
  const mxArray *c50_lhs104 = NULL;
  const mxArray *c50_rhs105 = NULL;
  const mxArray *c50_lhs105 = NULL;
  const mxArray *c50_rhs106 = NULL;
  const mxArray *c50_lhs106 = NULL;
  const mxArray *c50_rhs107 = NULL;
  const mxArray *c50_lhs107 = NULL;
  const mxArray *c50_rhs108 = NULL;
  const mxArray *c50_lhs108 = NULL;
  const mxArray *c50_rhs109 = NULL;
  const mxArray *c50_lhs109 = NULL;
  const mxArray *c50_rhs110 = NULL;
  const mxArray *c50_lhs110 = NULL;
  const mxArray *c50_rhs111 = NULL;
  const mxArray *c50_lhs111 = NULL;
  const mxArray *c50_rhs112 = NULL;
  const mxArray *c50_lhs112 = NULL;
  const mxArray *c50_rhs113 = NULL;
  const mxArray *c50_lhs113 = NULL;
  const mxArray *c50_rhs114 = NULL;
  const mxArray *c50_lhs114 = NULL;
  const mxArray *c50_rhs115 = NULL;
  const mxArray *c50_lhs115 = NULL;
  const mxArray *c50_rhs116 = NULL;
  const mxArray *c50_lhs116 = NULL;
  const mxArray *c50_rhs117 = NULL;
  const mxArray *c50_lhs117 = NULL;
  const mxArray *c50_rhs118 = NULL;
  const mxArray *c50_lhs118 = NULL;
  const mxArray *c50_rhs119 = NULL;
  const mxArray *c50_lhs119 = NULL;
  const mxArray *c50_rhs120 = NULL;
  const mxArray *c50_lhs120 = NULL;
  const mxArray *c50_rhs121 = NULL;
  const mxArray *c50_lhs121 = NULL;
  const mxArray *c50_rhs122 = NULL;
  const mxArray *c50_lhs122 = NULL;
  const mxArray *c50_rhs123 = NULL;
  const mxArray *c50_lhs123 = NULL;
  const mxArray *c50_rhs124 = NULL;
  const mxArray *c50_lhs124 = NULL;
  const mxArray *c50_rhs125 = NULL;
  const mxArray *c50_lhs125 = NULL;
  const mxArray *c50_rhs126 = NULL;
  const mxArray *c50_lhs126 = NULL;
  const mxArray *c50_rhs127 = NULL;
  const mxArray *c50_lhs127 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("blanks"), "name", "name", 64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c50_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c50_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fprintf"), "name", "name",
                  66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c50_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isequal"), "name", "name",
                  67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c50_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c50_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isnan"), "name", "name", 69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c50_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c50_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c50_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fprintf"), "name", "name",
                  72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c50_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("upper"), "name", "name", 73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c50_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c50_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c50_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c50_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c50_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c50_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c50_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("colon"), "name", "name", 80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c50_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("colon"), "name", "name", 81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c50_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c50_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c50_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("floor"), "name", "name", 84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c50_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 85);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmin"), "name", "name", 85);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c50_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 86);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 86);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c50_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 87);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 87);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c50_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 88);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmin"), "name", "name", 88);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c50_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 89);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 89);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 89);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c50_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 90);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 90);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c50_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 91);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c50_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 92);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 92);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c50_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 93);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 93);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c50_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 94);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 94);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c50_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 95);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 95);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c50_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 96);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 96);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 96);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c50_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 97);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 97);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 97);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c50_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 98);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 98);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c50_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 99);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 99);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c50_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 100);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name",
                  100);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 100);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c50_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 101);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "name", "name", 101);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c50_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fidCheck"), "name", "name",
                  102);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c50_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 103);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("upper"), "name", "name", 103);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 103);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c50_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 104);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 104);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c50_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 105);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 105);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c50_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 106);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 106);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c50_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 107);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 107);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c50_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 108);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 108);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c50_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 109);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 109);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c50_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 110);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  110);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1452377975U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c50_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context",
                  111);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("decArr2Str"), "name", "name",
                  111);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/decArr2Str.m"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1445391057U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c50_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/decArr2Str.m"),
                  "context", "context", 112);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_li_find"), "name",
                  "name", 112);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c50_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 113);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c50_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 114);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 114);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c50_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 115);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 115);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c50_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 116);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 116);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c50_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 117);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 117);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c50_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 118);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 118);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c50_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/decArr2Str.m"),
                  "context", "context", 119);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "name", "name", 119);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c50_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context",
                  120);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("cmdBML_AUmerg"), "name",
                  "name", 120);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1450731944U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c50_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 121);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("countDigits"), "name",
                  "name", 121);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/countDigits.m"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1408487908U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c50_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/countDigits.m"),
                  "context", "context", 122);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("abs"), "name", "name", 122);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 122);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c50_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 123);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("abs"), "name", "name", 123);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 123);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c50_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 124);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("log10"), "name", "name", 124);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 124);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343862782U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c50_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 125);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("ceil"), "name", "name", 125);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 125);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c50_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 126);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("max"), "name", "name", 126);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 126);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1311287716U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c50_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 127);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("blanks"), "name", "name",
                  127);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 127);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c50_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c50_rhs64);
  sf_mex_destroy(&c50_lhs64);
  sf_mex_destroy(&c50_rhs65);
  sf_mex_destroy(&c50_lhs65);
  sf_mex_destroy(&c50_rhs66);
  sf_mex_destroy(&c50_lhs66);
  sf_mex_destroy(&c50_rhs67);
  sf_mex_destroy(&c50_lhs67);
  sf_mex_destroy(&c50_rhs68);
  sf_mex_destroy(&c50_lhs68);
  sf_mex_destroy(&c50_rhs69);
  sf_mex_destroy(&c50_lhs69);
  sf_mex_destroy(&c50_rhs70);
  sf_mex_destroy(&c50_lhs70);
  sf_mex_destroy(&c50_rhs71);
  sf_mex_destroy(&c50_lhs71);
  sf_mex_destroy(&c50_rhs72);
  sf_mex_destroy(&c50_lhs72);
  sf_mex_destroy(&c50_rhs73);
  sf_mex_destroy(&c50_lhs73);
  sf_mex_destroy(&c50_rhs74);
  sf_mex_destroy(&c50_lhs74);
  sf_mex_destroy(&c50_rhs75);
  sf_mex_destroy(&c50_lhs75);
  sf_mex_destroy(&c50_rhs76);
  sf_mex_destroy(&c50_lhs76);
  sf_mex_destroy(&c50_rhs77);
  sf_mex_destroy(&c50_lhs77);
  sf_mex_destroy(&c50_rhs78);
  sf_mex_destroy(&c50_lhs78);
  sf_mex_destroy(&c50_rhs79);
  sf_mex_destroy(&c50_lhs79);
  sf_mex_destroy(&c50_rhs80);
  sf_mex_destroy(&c50_lhs80);
  sf_mex_destroy(&c50_rhs81);
  sf_mex_destroy(&c50_lhs81);
  sf_mex_destroy(&c50_rhs82);
  sf_mex_destroy(&c50_lhs82);
  sf_mex_destroy(&c50_rhs83);
  sf_mex_destroy(&c50_lhs83);
  sf_mex_destroy(&c50_rhs84);
  sf_mex_destroy(&c50_lhs84);
  sf_mex_destroy(&c50_rhs85);
  sf_mex_destroy(&c50_lhs85);
  sf_mex_destroy(&c50_rhs86);
  sf_mex_destroy(&c50_lhs86);
  sf_mex_destroy(&c50_rhs87);
  sf_mex_destroy(&c50_lhs87);
  sf_mex_destroy(&c50_rhs88);
  sf_mex_destroy(&c50_lhs88);
  sf_mex_destroy(&c50_rhs89);
  sf_mex_destroy(&c50_lhs89);
  sf_mex_destroy(&c50_rhs90);
  sf_mex_destroy(&c50_lhs90);
  sf_mex_destroy(&c50_rhs91);
  sf_mex_destroy(&c50_lhs91);
  sf_mex_destroy(&c50_rhs92);
  sf_mex_destroy(&c50_lhs92);
  sf_mex_destroy(&c50_rhs93);
  sf_mex_destroy(&c50_lhs93);
  sf_mex_destroy(&c50_rhs94);
  sf_mex_destroy(&c50_lhs94);
  sf_mex_destroy(&c50_rhs95);
  sf_mex_destroy(&c50_lhs95);
  sf_mex_destroy(&c50_rhs96);
  sf_mex_destroy(&c50_lhs96);
  sf_mex_destroy(&c50_rhs97);
  sf_mex_destroy(&c50_lhs97);
  sf_mex_destroy(&c50_rhs98);
  sf_mex_destroy(&c50_lhs98);
  sf_mex_destroy(&c50_rhs99);
  sf_mex_destroy(&c50_lhs99);
  sf_mex_destroy(&c50_rhs100);
  sf_mex_destroy(&c50_lhs100);
  sf_mex_destroy(&c50_rhs101);
  sf_mex_destroy(&c50_lhs101);
  sf_mex_destroy(&c50_rhs102);
  sf_mex_destroy(&c50_lhs102);
  sf_mex_destroy(&c50_rhs103);
  sf_mex_destroy(&c50_lhs103);
  sf_mex_destroy(&c50_rhs104);
  sf_mex_destroy(&c50_lhs104);
  sf_mex_destroy(&c50_rhs105);
  sf_mex_destroy(&c50_lhs105);
  sf_mex_destroy(&c50_rhs106);
  sf_mex_destroy(&c50_lhs106);
  sf_mex_destroy(&c50_rhs107);
  sf_mex_destroy(&c50_lhs107);
  sf_mex_destroy(&c50_rhs108);
  sf_mex_destroy(&c50_lhs108);
  sf_mex_destroy(&c50_rhs109);
  sf_mex_destroy(&c50_lhs109);
  sf_mex_destroy(&c50_rhs110);
  sf_mex_destroy(&c50_lhs110);
  sf_mex_destroy(&c50_rhs111);
  sf_mex_destroy(&c50_lhs111);
  sf_mex_destroy(&c50_rhs112);
  sf_mex_destroy(&c50_lhs112);
  sf_mex_destroy(&c50_rhs113);
  sf_mex_destroy(&c50_lhs113);
  sf_mex_destroy(&c50_rhs114);
  sf_mex_destroy(&c50_lhs114);
  sf_mex_destroy(&c50_rhs115);
  sf_mex_destroy(&c50_lhs115);
  sf_mex_destroy(&c50_rhs116);
  sf_mex_destroy(&c50_lhs116);
  sf_mex_destroy(&c50_rhs117);
  sf_mex_destroy(&c50_lhs117);
  sf_mex_destroy(&c50_rhs118);
  sf_mex_destroy(&c50_lhs118);
  sf_mex_destroy(&c50_rhs119);
  sf_mex_destroy(&c50_lhs119);
  sf_mex_destroy(&c50_rhs120);
  sf_mex_destroy(&c50_lhs120);
  sf_mex_destroy(&c50_rhs121);
  sf_mex_destroy(&c50_lhs121);
  sf_mex_destroy(&c50_rhs122);
  sf_mex_destroy(&c50_lhs122);
  sf_mex_destroy(&c50_rhs123);
  sf_mex_destroy(&c50_lhs123);
  sf_mex_destroy(&c50_rhs124);
  sf_mex_destroy(&c50_lhs124);
  sf_mex_destroy(&c50_rhs125);
  sf_mex_destroy(&c50_lhs125);
  sf_mex_destroy(&c50_rhs126);
  sf_mex_destroy(&c50_lhs126);
  sf_mex_destroy(&c50_rhs127);
  sf_mex_destroy(&c50_lhs127);
}

static void c50_c_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs128 = NULL;
  const mxArray *c50_lhs128 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 128);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  128);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/9-1-2016-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1452377975U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c50_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_destroy(&c50_rhs128);
  sf_mex_destroy(&c50_lhs128);
}

static void c50_activate_secsc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  chartInstance->c50_sfEvent = c50_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c50_event_secs,
               chartInstance->c50_sfEvent);
}

static void c50_deactivate_secsc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c50_event_secs,
               chartInstance->c50_sfEvent);
}

static void c50_increment_counters_secsc50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  if (chartInstance->c50_temporalCounter_i1 < 7U) {
    chartInstance->c50_temporalCounter_i1++;
  }

  if (chartInstance->c50_temporalCounter_i2 < 15U) {
    chartInstance->c50_temporalCounter_i2++;
  }

  if (chartInstance->c50_temporalCounter_i3 < 15U) {
    chartInstance->c50_temporalCounter_i3++;
  }
}

static void c50_reset_counters_secsc50_Demo_AUV_VA
  (SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c50_Demo_AUV_VA_secs(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_activate_secsc50_Demo_AUV_VA(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c50_Demo_AUV_VA_secs(SimStruct
  *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_increment_counters_secsc50_Demo_AUV_VA(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c50_Demo_AUV_VA_secs(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_reset_counters_secsc50_Demo_AUV_VA(chartInstance);
}

void sf_exported_auto_deactivate_c50_Demo_AUV_VA_secs(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_deactivate_secsc50_Demo_AUV_VA(chartInstance);
}

boolean_T sf_exported_auto_isStablec50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  return chartInstance->c50_isStable;
}

void sf_exported_auto_duringc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_c50_Demo_AUV_VA(chartInstance);
}

void sf_exported_auto_enterc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_enter_atomic_c50_Demo_AUV_VA(chartInstance);
  c50_enter_internal_c50_Demo_AUV_VA(chartInstance);
}

void sf_exported_auto_exitc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_exit_internal_c50_Demo_AUV_VA(chartInstance);
}

void sf_exported_auto_gatewayc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  chartInstance->c50_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_initc50_Demo_AUV_VA(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec50_Demo_AUV_VA(SimStruct *c50_S)
{
  const mxArray *c50_out = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_out = NULL;
  sf_mex_assign(&c50_out, sf_internal_get_sim_state_c50_Demo_AUV_VA(c50_S),
                false);
  return c50_out;
}

void sf_exported_auto_setSimstatec50_Demo_AUV_VA(SimStruct *c50_S, const mxArray
  *c50_in)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c50_Demo_AUV_VA(c50_S, sf_mex_dup(c50_in));
  sf_mex_destroy(&c50_in);
}

void sf_exported_auto_check_state_inconsistency_c50_Demo_AUV_VA(SimStruct *c50_S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_AUV_VAMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c50_faceTwitchc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_bmlID, real_T *c50_p, real_T c50_poseBML[2000])
{
  uint32_T c50_debug_family_var_map[7];
  boolean_T c50_aVarTruthTableCondition_1;
  boolean_T c50_aVarTruthTableCondition_2;
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 2.0;
  real_T c50_dv34[2000];
  int32_T c50_i245;
  int32_T c50_i246;
  int32_T c50_i247;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c50_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_aVarTruthTableCondition_1, 0U,
    c50_c_sf_marshallOut, c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_aVarTruthTableCondition_2, 1U,
    c50_c_sf_marshallOut, c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_bmlID, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_p, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseBML, 6U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 3);
  c50_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 9);
  c50_aVarTruthTableCondition_1 = (c50_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 13);
  c50_aVarTruthTableCondition_2 = (c50_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 15);
  if (CV_EML_IF(0, 1, 0, c50_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 16);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 27);
    c50_encStr2Arr(chartInstance, c50_dv34);
    for (c50_i245 = 0; c50_i245 < 2000; c50_i245++) {
      c50_poseBML[c50_i245] = c50_dv34[c50_i245];
    }

    c50_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 27);
    *c50_p = 3.0;
    c50_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -27);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 17);
    if (CV_EML_IF(0, 1, 1, c50_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 18);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 33);
      c50_b_encStr2Arr(chartInstance, c50_dv34);
      for (c50_i246 = 0; c50_i246 < 2000; c50_i246++) {
        c50_poseBML[c50_i246] = c50_dv34[c50_i246];
      }

      c50_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 33);
      *c50_p = 3.0;
      c50_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -33);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 20);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 33);
      c50_b_encStr2Arr(chartInstance, c50_dv34);
      for (c50_i247 = 0; c50_i247 < 2000; c50_i247++) {
        c50_poseBML[c50_i247] = c50_dv34[c50_i247];
      }

      c50_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 33);
      *c50_p = 3.0;
      c50_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -33);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_set_AU_Amountc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_arousal, real_T c50_valence, real_T
  c50_eAmountFactor[15])
{
  uint32_T c50_debug_family_var_map[9];
  real_T c50_p;
  real_T c50_a;
  real_T c50_all_AUs[15];
  real_T c50_c;
  real_T c50_nargin = 2.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i248;
  static real_T c50_dv35[15] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 12.0, 26.0, 45.0,
    10.0, 25.0, 102.0, 103.0, 104.0, 105.0 };

  int32_T c50_i249;
  int32_T c50_b_c;
  int32_T c50_i250;
  real_T c50_A[15];
  int32_T c50_i251;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c50_d_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_p, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_a, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_all_AUs, 2U, c50_i_sf_marshallOut,
    c50_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_arousal, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_valence, 7U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_eAmountFactor, 8U,
    c50_i_sf_marshallOut, c50_e_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 8);
  c50_p = c50_valence;
  _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 8);
  c50_a = c50_arousal;
  _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 9);
  for (c50_i248 = 0; c50_i248 < 15; c50_i248++) {
    c50_all_AUs[c50_i248] = c50_dv35[c50_i248];
  }

  _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 9);
  for (c50_i249 = 0; c50_i249 < 15; c50_i249++) {
    c50_eAmountFactor[c50_i249] = 0.0;
  }

  c50_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 10);
  c50_c = 1.0;
  c50_b_c = 0;
  while (c50_b_c < 15) {
    c50_c = 1.0 + (real_T)c50_b_c;
    CV_EML_FOR(3, 1, 0, 1);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 11);
    c50_eAmountFactor[0] = 0.0036 * c50_p - -0.01 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 12);
    c50_eAmountFactor[1] = 0.0024 * c50_p + 0.04 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 14);
    c50_eAmountFactor[7] = -0.002 * c50_p + 0.023 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 15);
    c50_eAmountFactor[4] = -0.008 * c50_p + 0.009 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 17);
    c50_eAmountFactor[12] = (0.007 * c50_p + 0.025 * c50_a) * 0.3;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 19);
    c50_eAmountFactor[14] = (0.003 * c50_p + 0.009 * c50_a) * 0.5;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 20);
    c50_eAmountFactor[13] = (0.003 * c50_p + 0.009 * c50_a) * 0.5;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 23);
    c50_eAmountFactor[9] = -0.02 * c50_p + 0.026 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 24);
    c50_eAmountFactor[3] = -0.003 * c50_p + 0.057600000000000005 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 25);
    c50_eAmountFactor[8] = -0.0021000000000000003 * c50_p - 0.00925 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 26);
    c50_eAmountFactor[2] = -0.053999999999999992 * c50_p + 0.011 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 30);
    c50_eAmountFactor[10] = -0.011 * c50_p + 0.058 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 34);
    c50_eAmountFactor[11] = (0.039 * c50_p + 0.015 * c50_a) * 0.2;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 36);
    c50_eAmountFactor[5] = -0.005 * c50_p - 0.001 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 37);
    c50_eAmountFactor[6] = (0.057 * c50_p + 0.009 * c50_a) * 1.1;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, 43);
    c50_errorIfDataNotWrittenToFcn(chartInstance, 11U, 17U);
    for (c50_i250 = 0; c50_i250 < 15; c50_i250++) {
      c50_A[c50_i250] = c50_eAmountFactor[c50_i250];
    }

    for (c50_i251 = 0; c50_i251 < 15; c50_i251++) {
      c50_eAmountFactor[c50_i251] = c50_A[c50_i251] / 4.5;
    }

    c50_updateDataWrittenToVector(chartInstance, 11U);
    c50_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(3, 1, 0, 0);
  _SFD_EML_CALL(3U, chartInstance->c50_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_insertQueueLowc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_bmls[10000], real_T c50_myBML[2000], real_T
  c50_newBmls[10000])
{
  uint32_T c50_debug_family_var_map[8];
  real_T c50_full;
  real_T c50_t[2000];
  real_T c50_i;
  real_T c50_nargin = 2.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i252;
  static real_T c50_dv36[2000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i253;
  int32_T c50_i254;
  int32_T c50_i255;
  int32_T c50_i256;
  int32_T c50_i257;
  int32_T c50_b_i;
  int32_T c50_c_i;
  int32_T c50_i258;
  real_T c50_b_bmls[2000];
  int32_T c50_i259;
  real_T c50_dv37[2000];
  int32_T c50_d_i;
  int32_T c50_i260;
  int32_T c50_i261;
  real_T c50_c_bmls[2000];
  int32_T c50_i262;
  int32_T c50_i263;
  real_T c50_d_bmls[2000];
  int32_T c50_i264;
  int32_T c50_i265;
  real_T c50_e_bmls[2000];
  int32_T c50_i266;
  int32_T c50_i267;
  int32_T c50_i268;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c50_e_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_full, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_t, 1U, c50_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_i, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_bmls, 5U, c50_j_sf_marshallOut,
    c50_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_myBML, 6U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_newBmls, 7U, c50_j_sf_marshallOut,
    c50_f_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 2);
  c50_full = 1.0;
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 3);
  for (c50_i252 = 0; c50_i252 < 2000; c50_i252++) {
    c50_t[c50_i252] = c50_dv36[c50_i252];
  }

  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 4);
  for (c50_i253 = 0; c50_i253 < 2000; c50_i253++) {
    c50_newBmls[c50_i253] = c50_t[c50_i253];
  }

  for (c50_i254 = 0; c50_i254 < 2000; c50_i254++) {
    c50_newBmls[c50_i254 + 2000] = c50_t[c50_i254];
  }

  for (c50_i255 = 0; c50_i255 < 2000; c50_i255++) {
    c50_newBmls[c50_i255 + 4000] = c50_t[c50_i255];
  }

  for (c50_i256 = 0; c50_i256 < 2000; c50_i256++) {
    c50_newBmls[c50_i256 + 6000] = c50_t[c50_i256];
  }

  for (c50_i257 = 0; c50_i257 < 2000; c50_i257++) {
    c50_newBmls[c50_i257 + 8000] = c50_t[c50_i257];
  }

  c50_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 5);
  c50_i = 1.0;
  c50_b_i = 0;
  do {
    exitg1 = 0;
    if (c50_b_i < 5) {
      c50_i = 1.0 + (real_T)c50_b_i;
      CV_EML_FOR(1, 1, 0, 1);
      _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 6);
      c50_c_i = (int32_T)c50_i - 1;
      for (c50_i258 = 0; c50_i258 < 2000; c50_i258++) {
        c50_b_bmls[c50_i258] = c50_bmls[c50_i258 + 2000 * c50_c_i];
      }

      for (c50_i259 = 0; c50_i259 < 2000; c50_i259++) {
        c50_dv37[c50_i259] = c50_dv36[c50_i259];
      }

      if (CV_EML_IF(1, 1, 0, c50_b_isequal(chartInstance, c50_b_bmls, c50_dv37)))
      {
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 8);
        c50_d_i = (int32_T)c50_i - 1;
        for (c50_i260 = 0; c50_i260 < 2000; c50_i260++) {
          c50_bmls[c50_i260 + 2000 * c50_d_i] = c50_myBML[c50_i260];
        }

        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 9);
        c50_full = 0.0;
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 10);
        exitg1 = 1;
      } else {
        c50_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(1, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 13);
  if (CV_EML_IF(1, 1, 1, c50_full != 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 15);
    for (c50_i261 = 0; c50_i261 < 2000; c50_i261++) {
      c50_c_bmls[c50_i261] = c50_bmls[c50_i261 + 2000];
    }

    for (c50_i262 = 0; c50_i262 < 2000; c50_i262++) {
      c50_bmls[c50_i262] = c50_c_bmls[c50_i262];
    }

    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 16);
    for (c50_i263 = 0; c50_i263 < 2000; c50_i263++) {
      c50_d_bmls[c50_i263] = c50_bmls[c50_i263 + 4000];
    }

    for (c50_i264 = 0; c50_i264 < 2000; c50_i264++) {
      c50_bmls[c50_i264 + 2000] = c50_d_bmls[c50_i264];
    }

    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 17);
    for (c50_i265 = 0; c50_i265 < 2000; c50_i265++) {
      c50_e_bmls[c50_i265] = c50_bmls[c50_i265 + 6000];
    }

    for (c50_i266 = 0; c50_i266 < 2000; c50_i266++) {
      c50_bmls[c50_i266 + 4000] = c50_e_bmls[c50_i266];
    }

    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 18);
    for (c50_i267 = 0; c50_i267 < 2000; c50_i267++) {
      c50_bmls[c50_i267 + 8000] = c50_myBML[c50_i267];
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 20);
  for (c50_i268 = 0; c50_i268 < 10000; c50_i268++) {
    c50_newBmls[c50_i268] = c50_bmls[c50_i268];
  }

  c50_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_setAUc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_E, real_T c50_AU[6], real_T *c50_L)
{
  uint32_T c50_debug_family_var_map[5];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 2.0;
  int32_T c50_i269;
  int32_T c50_i270;
  static real_T c50_dv38[6] = { 1.0, 2.0, 45.0, 0.0, 0.0, 0.0 };

  int32_T c50_i271;
  static real_T c50_dv39[6] = { 1.0, 4.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i272;
  static real_T c50_dv40[6] = { 1.0, 2.0, 4.0, 5.0, 6.0, 0.0 };

  int32_T c50_i273;
  static real_T c50_dv41[6] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0 };

  int32_T c50_i274;
  static real_T c50_dv42[6] = { 12.0, 45.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i275;
  static real_T c50_dv43[6] = { 6.0, 12.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i276;
  static real_T c50_dv44[6] = { 6.0, 12.0, 1.0, 2.0, 0.0, 0.0 };

  int32_T c50_i277;
  static real_T c50_dv45[6] = { 12.0, 26.0, 5.0, 1.0, 2.0, 6.0 };

  int32_T c50_i278;
  static real_T c50_dv46[6] = { 2.0, 4.0, 5.0, 7.0, 45.0, 0.0 };

  const mxArray *c50_y = NULL;
  char_T c50_u[31];
  static char_T c50_cv27[31] = { 'e', 'r', 'r', 'o', 'r', ',', ' ', 's', 'e',
    't', 'A', 'U', ',', 'e', 'm', 'o', 't', 'i', 'o', 'n', ' ', 'n', 'o', 't',
    ' ', 'l', 'i', 's', 't', 'e', 'd' };

  int32_T c50_i279;
  int32_T c50_i280;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c50_g_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_E, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_AU, 3U, c50_l_sf_marshallOut,
    c50_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_L, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 12);
  for (c50_i269 = 0; c50_i269 < 6; c50_i269++) {
    c50_AU[c50_i269] = 0.0;
  }

  c50_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 12);
  *c50_L = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 16);
  switch ((int32_T)_SFD_INTEGER_CHECK("E", c50_E)) {
   case 1:
    CV_EML_SWITCH(2, 1, 0, 1);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 18);
    for (c50_i270 = 0; c50_i270 < 6; c50_i270++) {
      c50_AU[c50_i270] = c50_dv38[c50_i270];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 18);
    *c50_L = 3.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 2:
    CV_EML_SWITCH(2, 1, 0, 2);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 21);
    for (c50_i271 = 0; c50_i271 < 6; c50_i271++) {
      c50_AU[c50_i271] = c50_dv39[c50_i271];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 21);
    *c50_L = 2.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 3:
    CV_EML_SWITCH(2, 1, 0, 3);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 24);
    for (c50_i272 = 0; c50_i272 < 6; c50_i272++) {
      c50_AU[c50_i272] = c50_dv40[c50_i272];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 24);
    *c50_L = 5.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 4:
    CV_EML_SWITCH(2, 1, 0, 4);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 27);
    for (c50_i273 = 0; c50_i273 < 6; c50_i273++) {
      c50_AU[c50_i273] = c50_dv41[c50_i273];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 27);
    *c50_L = 6.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 5:
    CV_EML_SWITCH(2, 1, 0, 5);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 30);
    for (c50_i274 = 0; c50_i274 < 6; c50_i274++) {
      c50_AU[c50_i274] = c50_dv42[c50_i274];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 30);
    *c50_L = 2.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 6:
    CV_EML_SWITCH(2, 1, 0, 6);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 33);
    for (c50_i275 = 0; c50_i275 < 6; c50_i275++) {
      c50_AU[c50_i275] = c50_dv43[c50_i275];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 33);
    *c50_L = 2.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 7:
    CV_EML_SWITCH(2, 1, 0, 7);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 36);
    for (c50_i276 = 0; c50_i276 < 6; c50_i276++) {
      c50_AU[c50_i276] = c50_dv44[c50_i276];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 36);
    *c50_L = 4.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 8:
    CV_EML_SWITCH(2, 1, 0, 8);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 39);
    for (c50_i277 = 0; c50_i277 < 6; c50_i277++) {
      c50_AU[c50_i277] = c50_dv45[c50_i277];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 39);
    *c50_L = 6.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   case 9:
    CV_EML_SWITCH(2, 1, 0, 9);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 42);
    for (c50_i278 = 0; c50_i278 < 6; c50_i278++) {
      c50_AU[c50_i278] = c50_dv46[c50_i278];
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 42);
    *c50_L = 5.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    break;

   default:
    CV_EML_SWITCH(2, 1, 0, 0);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 49);
    for (c50_i279 = 0; c50_i279 < 6; c50_i279++) {
      c50_AU[c50_i279] = 0.0;
    }

    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 49);
    *c50_L = 0.0;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, 50);
    for (c50_i280 = 0; c50_i280 < 31; c50_i280++) {
      c50_u[c50_i280] = c50_cv27[c50_i280];
    }

    c50_y = NULL;
    sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c50_y);
    break;
  }

  _SFD_EML_CALL(2U, chartInstance->c50_sfEvent, -50);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_set_eAmountFactorc50_Demo_AUV_VA(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, real_T c50_E, real_T c50_AU[6], real_T c50_arousal, real_T
  c50_valence, real_T c50_eAmountFactor2[6])
{
  uint32_T c50_debug_family_var_map[12];
  real_T c50_pFactor;
  real_T c50_p;
  real_T c50_a_factor;
  real_T c50_v_factor;
  real_T c50_c;
  real_T c50_nargin = 4.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i281;
  int32_T c50_i282;
  static real_T c50_dv47[6] = { 1.0, 1.0, 0.25, 0.0, 0.0, 0.0 };

  int32_T c50_i283;
  static real_T c50_dv48[6] = { 0.7, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i284;
  static real_T c50_dv49[6] = { 1.0, 1.0, 1.0, 0.7, 0.7, 0.0 };

  int32_T c50_i285;
  static real_T c50_dv50[6] = { 1.0, 1.0, 1.0, 0.8, 0.8, 0.2 };

  int32_T c50_i286;
  static real_T c50_dv51[6] = { 0.7, 0.25, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i287;
  static real_T c50_dv52[6] = { 0.4, 0.4, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i288;
  static real_T c50_dv53[6] = { 0.9, 1.2, 0.0, 0.0, 0.0, 0.0 };

  int32_T c50_i289;
  static real_T c50_dv54[6] = { 0.7, 0.5, 0.8, 0.8, 0.8, 0.5 };

  int32_T c50_i290;
  int32_T c50_i291;
  static char_T c50_cv28[43] = { 'e', 'r', 'r', 'o', 'r', ',', ' ', 's', 'e',
    't', '_', 'e', 'A', 'm', 'o', 'u', 'n', 't', 'F', 'a', 'c', 't', 'o', 'r',
    ',', 'e', 'm', 'o', 't', 'i', 'o', 'n', ' ', 'n', 'o', 't', ' ', 'l', 'i',
    's', 't', 'e', 'd' };

  char_T c50_u[43];
  const mxArray *c50_y = NULL;
  real_T c50_A;
  real_T c50_x;
  real_T c50_b_x;
  real_T c50_c_x;
  real_T c50_b_y;
  real_T c50_d_x;
  real_T c50_e_x;
  real_T c50_b_A;
  real_T c50_f_x;
  real_T c50_g_x;
  real_T c50_h_x;
  real_T c50_c_y;
  real_T c50_i_x;
  real_T c50_j_x;
  int32_T c50_b_c;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c50_h_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pFactor, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_p, 1U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_a_factor, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_v_factor, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_E, 7U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_AU, 8U, c50_l_sf_marshallOut,
    c50_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_arousal, 9U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_valence, 10U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_eAmountFactor2, 11U,
    c50_l_sf_marshallOut, c50_g_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 2);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 3);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 4);
  for (c50_i281 = 0; c50_i281 < 6; c50_i281++) {
    c50_eAmountFactor2[c50_i281] = 0.0;
  }

  c50_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 4);
  c50_pFactor = 0.8;
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 5);
  c50_p = 1.0;
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 6);
  CV_EML_IF(4, 1, 0, true);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 8);
  if (CV_EML_IF(4, 1, 1, c50_E == 1.0)) {
    _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 9);
    for (c50_i282 = 0; c50_i282 < 6; c50_i282++) {
      c50_eAmountFactor2[c50_i282] = c50_dv47[c50_i282];
    }

    c50_updateDataWrittenToVector(chartInstance, 15U);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 10);
    if (CV_EML_IF(4, 1, 2, c50_E == 2.0)) {
      _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 11);
      for (c50_i283 = 0; c50_i283 < 6; c50_i283++) {
        c50_eAmountFactor2[c50_i283] = c50_dv48[c50_i283];
      }

      c50_updateDataWrittenToVector(chartInstance, 15U);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 12);
      if (CV_EML_IF(4, 1, 3, c50_E == 3.0)) {
        _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 13);
        for (c50_i284 = 0; c50_i284 < 6; c50_i284++) {
          c50_eAmountFactor2[c50_i284] = c50_dv49[c50_i284];
        }

        c50_updateDataWrittenToVector(chartInstance, 15U);
      } else {
        _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 14);
        if (CV_EML_IF(4, 1, 4, c50_E == 4.0)) {
          _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 15);
          for (c50_i285 = 0; c50_i285 < 6; c50_i285++) {
            c50_eAmountFactor2[c50_i285] = c50_dv50[c50_i285];
          }

          c50_updateDataWrittenToVector(chartInstance, 15U);
        } else {
          _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 16);
          if (CV_EML_IF(4, 1, 5, c50_E == 5.0)) {
            _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 17);
            for (c50_i286 = 0; c50_i286 < 6; c50_i286++) {
              c50_eAmountFactor2[c50_i286] = c50_dv51[c50_i286];
            }

            c50_updateDataWrittenToVector(chartInstance, 15U);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 18);
            if (CV_EML_IF(4, 1, 6, c50_E == 6.0)) {
              _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 19);
              for (c50_i287 = 0; c50_i287 < 6; c50_i287++) {
                c50_eAmountFactor2[c50_i287] = c50_dv52[c50_i287];
              }

              c50_updateDataWrittenToVector(chartInstance, 15U);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 20);
              if (CV_EML_IF(4, 1, 7, c50_E == 7.0)) {
                _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 21);
                for (c50_i288 = 0; c50_i288 < 6; c50_i288++) {
                  c50_eAmountFactor2[c50_i288] = c50_dv53[c50_i288];
                }

                c50_updateDataWrittenToVector(chartInstance, 15U);
              } else {
                _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 22);
                if (CV_EML_IF(4, 1, 8, c50_E == 8.0)) {
                  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 23);
                  for (c50_i289 = 0; c50_i289 < 6; c50_i289++) {
                    c50_eAmountFactor2[c50_i289] = c50_dv54[c50_i289];
                  }

                  c50_updateDataWrittenToVector(chartInstance, 15U);
                } else {
                  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 25);
                  for (c50_i290 = 0; c50_i290 < 6; c50_i290++) {
                    c50_eAmountFactor2[c50_i290] = 0.0;
                  }

                  c50_updateDataWrittenToVector(chartInstance, 15U);
                  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 26);
                  for (c50_i291 = 0; c50_i291 < 43; c50_i291++) {
                    c50_u[c50_i291] = c50_cv28[c50_i291];
                  }

                  c50_y = NULL;
                  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U,
                    2, 1, 43), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c50_y);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 28);
  c50_errorIfDataNotWrittenToFcn(chartInstance, 15U, 27U);
  c50_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 103);
  c50_A = c50_arousal;
  c50_x = c50_A;
  c50_b_x = c50_x;
  c50_c_x = c50_b_x;
  c50_b_y = c50_c_x / 250.0;
  c50_d_x = 0.4 + c50_b_y;
  c50_e_x = c50_d_x;
  c50_a_factor = muDoubleScalarAbs(c50_e_x);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 104);
  c50_b_A = c50_valence;
  c50_f_x = c50_b_A;
  c50_g_x = c50_f_x;
  c50_h_x = c50_g_x;
  c50_c_y = c50_h_x / 250.0;
  c50_i_x = 0.4 + c50_c_y;
  c50_j_x = c50_i_x;
  c50_v_factor = muDoubleScalarAbs(c50_j_x);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 108);
  c50_c = 1.0;
  c50_b_c = 0;
  while (c50_b_c < 6) {
    c50_c = 1.0 + (real_T)c50_b_c;
    CV_EML_FOR(4, 1, 0, 1);
    _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 109);
    if (CV_EML_IF(4, 1, 36, c50_arousal > 0.0)) {
      _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 110);
      guard2 = false;
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(4, 1, 0, c50_AU[(int32_T)c50_c - 1] == 1.0)) {
        guard4 = true;
      } else if (CV_EML_COND(4, 1, 1, c50_AU[(int32_T)c50_c - 1] == 2.0)) {
        guard4 = true;
      } else if (CV_EML_COND(4, 1, 2, c50_AU[(int32_T)c50_c - 1] == 5.0)) {
        guard3 = true;
      } else if (CV_EML_COND(4, 1, 3, c50_AU[(int32_T)c50_c - 1] == 26.0)) {
        guard2 = true;
      } else {
        CV_EML_MCDC(4, 1, 0, false);
        CV_EML_IF(4, 1, 37, false);
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(4, 1, 0, true);
        CV_EML_IF(4, 1, 37, true);
        _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 111);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 15U, 27U);
        c50_eAmountFactor2[(int32_T)c50_c - 1] *= c50_a_factor;
        c50_updateDataWrittenToVector(chartInstance, 15U);
      }
    }

    _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 114);
    if (CV_EML_IF(4, 1, 38, c50_valence > 0.0)) {
      _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 115);
      guard1 = false;
      if (CV_EML_COND(4, 1, 4, c50_AU[(int32_T)c50_c - 1] == 6.0)) {
        guard1 = true;
      } else if (CV_EML_COND(4, 1, 5, c50_AU[(int32_T)c50_c - 1] == 12.0)) {
        guard1 = true;
      } else {
        CV_EML_MCDC(4, 1, 1, false);
        CV_EML_IF(4, 1, 39, false);
      }

      if (guard1 == true) {
        CV_EML_MCDC(4, 1, 1, true);
        CV_EML_IF(4, 1, 39, true);
        _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 116);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 15U, 27U);
        c50_eAmountFactor2[(int32_T)c50_c - 1] *= c50_v_factor;
        c50_updateDataWrittenToVector(chartInstance, 15U);
      }
    } else {
      _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 119);
      if (CV_EML_IF(4, 1, 40, c50_AU[(int32_T)c50_c - 1] == 4.0)) {
        _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, 120);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 15U, 27U);
        c50_eAmountFactor2[(int32_T)c50_c - 1] *= c50_v_factor;
        c50_updateDataWrittenToVector(chartInstance, 15U);
      }
    }

    c50_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(4, 1, 0, 0);
  _SFD_EML_CALL(4U, chartInstance->c50_sfEvent, -120);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c50_b_isequal(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  real_T c50_varargin_1[2000], real_T c50_varargin_2[2000])
{
  boolean_T c50_p;
  boolean_T c50_b_p;
  int32_T c50_k;
  real_T c50_b_k;
  real_T c50_x1;
  real_T c50_x2;
  boolean_T c50_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c50_p = false;
  c50_b_p = true;
  c50_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c50_k < 2000)) {
    c50_b_k = 1.0 + (real_T)c50_k;
    c50_x1 = c50_varargin_1[(int32_T)c50_b_k - 1];
    c50_x2 = c50_varargin_2[(int32_T)c50_b_k - 1];
    c50_c_p = (c50_x1 == c50_x2);
    if (!c50_c_p) {
      c50_b_p = false;
      exitg1 = true;
    } else {
      c50_k++;
    }
  }

  if (!c50_b_p) {
  } else {
    c50_p = true;
  }

  return c50_p;
}

static real_T c50_abs(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
                      c50_x)
{
  real_T c50_b_x;
  (void)chartInstance;
  c50_b_x = c50_x;
  return muDoubleScalarAbs(c50_b_x);
}

void sf_exported_user_c50_Demo_AUV_VA_faceTwitch(SimStruct *c50_S, real_T
  c50_bmlID, real_T *c50_p, real_T c50_poseBML[2000])
{
  real_T c50_b_p;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_faceTwitchc50_Demo_AUV_VA(chartInstance, c50_bmlID, &c50_b_p, c50_poseBML);
  *c50_p = c50_b_p;
}

void sf_exported_user_c50_Demo_AUV_VA_insertQueueLow(SimStruct *c50_S, real_T
  c50_bmls[10000], real_T c50_myBML[2000], real_T c50_newBmls[10000])
{
  int32_T c50_i292;
  real_T c50_b_bmls[10000];
  int32_T c50_i293;
  real_T c50_b_myBML[2000];
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  for (c50_i292 = 0; c50_i292 < 10000; c50_i292++) {
    c50_b_bmls[c50_i292] = c50_bmls[c50_i292];
  }

  for (c50_i293 = 0; c50_i293 < 2000; c50_i293++) {
    c50_b_myBML[c50_i293] = c50_myBML[c50_i293];
  }

  c50_insertQueueLowc50_Demo_AUV_VA(chartInstance, c50_b_bmls, c50_b_myBML,
    c50_newBmls);
}

void sf_exported_user_c50_Demo_AUV_VA_setAU(SimStruct *c50_S, real_T c50_E,
  real_T c50_AU[6], real_T *c50_L)
{
  real_T c50_b_L;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_setAUc50_Demo_AUV_VA(chartInstance, c50_E, c50_AU, &c50_b_L);
  *c50_L = c50_b_L;
}

void sf_exported_user_c50_Demo_AUV_VA_set_AU_Amount(SimStruct *c50_S, real_T
  c50_arousal, real_T c50_valence, real_T c50_eAmountFactor[15])
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_set_AU_Amountc50_Demo_AUV_VA(chartInstance, c50_arousal, c50_valence,
    c50_eAmountFactor);
}

void sf_exported_user_c50_Demo_AUV_VA_set_eAmountFactor(SimStruct *c50_S, real_T
  c50_E, real_T c50_AU[6], real_T c50_arousal, real_T c50_valence, real_T
  c50_eAmountFactor2[6])
{
  int32_T c50_i294;
  real_T c50_b_AU[6];
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  for (c50_i294 = 0; c50_i294 < 6; c50_i294++) {
    c50_b_AU[c50_i294] = c50_AU[c50_i294];
  }

  c50_set_eAmountFactorc50_Demo_AUV_VA(chartInstance, c50_E, c50_b_AU,
    c50_arousal, c50_valence, c50_eAmountFactor2);
}

static const mxArray *c50_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int8_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int8_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int8_T c50_kb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int8_T c50_y;
  int8_T c50_i295;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i295, 1, 2, 0U, 0, 0U, 0);
  c50_y = c50_i295;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_bb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_secs;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int8_T c50_y;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_secs = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_secs),
    &c50_thisId);
  sf_mex_destroy(&c50_secs);
  *(int8_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int32_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int32_T c50_lb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int32_T c50_y;
  int32_T c50_i296;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i296, 1, 6, 0U, 0, 0U, 0);
  c50_y = c50_i296;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_cb_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_sfEvent;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_b_sfEvent = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_lb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_sfEvent),
    &c50_thisId);
  sf_mex_destroy(&c50_b_sfEvent);
  *(int32_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  uint8_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(uint8_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static uint8_T c50_mb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_b_tp_subFaceTwitch, const char_T
  *c50_identifier)
{
  uint8_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_nb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_tp_subFaceTwitch), &c50_thisId);
  sf_mex_destroy(&c50_b_tp_subFaceTwitch);
  return c50_y;
}

static uint8_T c50_nb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint8_T c50_y;
  uint8_T c50_u0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u0, 1, 3, 0U, 0, 0U, 0);
  c50_y = c50_u0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_db_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_tp_subFaceTwitch;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  uint8_T c50_y;
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)chartInstanceVoid;
  c50_b_tp_subFaceTwitch = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_nb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_tp_subFaceTwitch), &c50_thisId);
  sf_mex_destroy(&c50_b_tp_subFaceTwitch);
  *(uint8_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static uint32_T c50_ob_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_b_method, const char_T *c50_identifier)
{
  uint32_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_pb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_method),
    &c50_thisId);
  sf_mex_destroy(&c50_b_method);
  return c50_y;
}

static uint32_T c50_pb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint32_T c50_y;
  uint32_T c50_u1;
  if (mxIsEmpty(c50_u)) {
    chartInstance->c50_method_not_empty = false;
  } else {
    chartInstance->c50_method_not_empty = true;
    sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u1, 1, 7, 0U, 0, 0U, 0);
    c50_y = c50_u1;
  }

  sf_mex_destroy(&c50_u);
  return c50_y;
}

static uint32_T c50_qb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_d_state, const char_T *c50_identifier)
{
  uint32_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_rb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_d_state),
    &c50_thisId);
  sf_mex_destroy(&c50_d_state);
  return c50_y;
}

static uint32_T c50_rb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint32_T c50_y;
  uint32_T c50_u2;
  if (mxIsEmpty(c50_u)) {
    chartInstance->c50_state_not_empty = false;
  } else {
    chartInstance->c50_state_not_empty = true;
    sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u2, 1, 7, 0U, 0, 0U, 0);
    c50_y = c50_u2;
  }

  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_sb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_d_state, const char_T *c50_identifier,
  uint32_T c50_y[625])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_tb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_d_state), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_d_state);
}

static void c50_tb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  uint32_T c50_y[625])
{
  uint32_T c50_uv10[625];
  int32_T c50_i297;
  if (mxIsEmpty(c50_u)) {
    chartInstance->c50_c_state_not_empty = false;
  } else {
    chartInstance->c50_c_state_not_empty = true;
    sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_uv10, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c50_i297 = 0; c50_i297 < 625; c50_i297++) {
      c50_y[c50_i297] = c50_uv10[c50_i297];
    }
  }

  sf_mex_destroy(&c50_u);
}

static void c50_ub_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_d_state, const char_T *c50_identifier,
  uint32_T c50_y[2])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_vb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_d_state), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_d_state);
}

static void c50_vb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  uint32_T c50_y[2])
{
  uint32_T c50_uv11[2];
  int32_T c50_i298;
  if (mxIsEmpty(c50_u)) {
    chartInstance->c50_b_state_not_empty = false;
  } else {
    chartInstance->c50_b_state_not_empty = true;
    sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_uv11, 1, 7, 0U, 1, 0U, 1,
                  2);
    for (c50_i298 = 0; c50_i298 < 2; c50_i298++) {
      c50_y[c50_i298] = c50_uv11[c50_i298];
    }
  }

  sf_mex_destroy(&c50_u);
}

static const mxArray *c50_wb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_b_setSimStateSideEffectsInfo, const char_T *
  c50_identifier)
{
  const mxArray *c50_y = NULL;
  emlrtMsgIdentifier c50_thisId;
  c50_y = NULL;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  sf_mex_assign(&c50_y, c50_xb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_setSimStateSideEffectsInfo), &c50_thisId), false);
  sf_mex_destroy(&c50_b_setSimStateSideEffectsInfo);
  return c50_y;
}

static const mxArray *c50_xb_emlrt_marshallIn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  const mxArray *c50_y = NULL;
  (void)chartInstance;
  (void)c50_parentId;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_duplicatearraysafe(&c50_u), false);
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_updateDataWrittenToVector(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_vectorIndex)
{
  (void)chartInstance;
  c50_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c50_vectorIndex, 0, 15, 1, 0)] = true;
}

static void c50_errorIfDataNotWrittenToFcn(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_vectorIndex, uint32_T c50_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c50_dataNumber, c50_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c50_vectorIndex, 0, 15, 1,
    0)]);
}

static void c50_b_twister_state_vector(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_mt[625], real_T c50_seed)
{
  uint32_T c50_r;
  int32_T c50_mti;
  real_T c50_b_mti;
  real_T c50_d5;
  uint32_T c50_u3;
  (void)chartInstance;
  (void)c50_seed;
  c50_r = 5489U;
  c50_mt[0] = 5489U;
  for (c50_mti = 0; c50_mti < 623; c50_mti++) {
    c50_b_mti = 2.0 + (real_T)c50_mti;
    c50_d5 = muDoubleScalarRound(c50_b_mti - 1.0);
    if (c50_d5 < 4.294967296E+9) {
      if (c50_d5 >= 0.0) {
        c50_u3 = (uint32_T)c50_d5;
      } else {
        c50_u3 = 0U;
      }
    } else if (c50_d5 >= 4.294967296E+9) {
      c50_u3 = MAX_uint32_T;
    } else {
      c50_u3 = 0U;
    }

    c50_r = (c50_r ^ c50_r >> 30U) * 1812433253U + c50_u3;
    c50_mt[(int32_T)c50_b_mti - 1] = c50_r;
  }

  c50_mt[624] = 624U;
}

static real_T c50_c_eml_rand_mt19937ar(SFc50_Demo_AUV_VAInstanceStruct
  *chartInstance, uint32_T c50_d_state[625])
{
  int32_T c50_i299;
  uint32_T c50_u[2];
  int32_T c50_j;
  real_T c50_b_j;
  uint32_T c50_mti;
  int32_T c50_kk;
  real_T c50_b_kk;
  uint32_T c50_y;
  uint32_T c50_b_y;
  uint32_T c50_c_y;
  int32_T c50_c_kk;
  uint32_T c50_d_y;
  uint32_T c50_e_y;
  uint32_T c50_f_y;
  uint32_T c50_g_y;
  real_T c50_b_r;
  boolean_T c50_b4;
  boolean_T c50_isvalid;
  int32_T c50_k;
  int32_T c50_a;
  int32_T c50_b_a;
  real_T c50_d6;
  boolean_T guard1 = false;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    for (c50_i299 = 0; c50_i299 < 2; c50_i299++) {
      c50_u[c50_i299] = 0U;
    }

    for (c50_j = 0; c50_j < 2; c50_j++) {
      c50_b_j = 1.0 + (real_T)c50_j;
      c50_mti = c50_d_state[624] + 1U;
      if ((real_T)c50_mti >= 625.0) {
        for (c50_kk = 0; c50_kk < 227; c50_kk++) {
          c50_b_kk = 1.0 + (real_T)c50_kk;
          c50_y = (c50_d_state[(int32_T)c50_b_kk - 1] & 2147483648U) |
            (c50_d_state[(int32_T)(c50_b_kk + 1.0) - 1] & 2147483647U);
          c50_b_y = c50_y;
          c50_c_y = c50_b_y;
          if ((real_T)(c50_c_y & 1U) == 0.0) {
            c50_c_y >>= 1U;
          } else {
            c50_c_y = c50_c_y >> 1U ^ 2567483615U;
          }

          c50_d_state[(int32_T)c50_b_kk - 1] = c50_d_state[(int32_T)(c50_b_kk +
            397.0) - 1] ^ c50_c_y;
        }

        for (c50_c_kk = 0; c50_c_kk < 396; c50_c_kk++) {
          c50_b_kk = 228.0 + (real_T)c50_c_kk;
          c50_y = (c50_d_state[(int32_T)c50_b_kk - 1] & 2147483648U) |
            (c50_d_state[(int32_T)(c50_b_kk + 1.0) - 1] & 2147483647U);
          c50_d_y = c50_y;
          c50_e_y = c50_d_y;
          if ((real_T)(c50_e_y & 1U) == 0.0) {
            c50_e_y >>= 1U;
          } else {
            c50_e_y = c50_e_y >> 1U ^ 2567483615U;
          }

          c50_d_state[(int32_T)c50_b_kk - 1] = c50_d_state[(int32_T)((c50_b_kk +
            1.0) - 228.0) - 1] ^ c50_e_y;
        }

        c50_y = (c50_d_state[623] & 2147483648U) | (c50_d_state[0] & 2147483647U);
        c50_f_y = c50_y;
        c50_g_y = c50_f_y;
        if ((real_T)(c50_g_y & 1U) == 0.0) {
          c50_g_y >>= 1U;
        } else {
          c50_g_y = c50_g_y >> 1U ^ 2567483615U;
        }

        c50_d_state[623] = c50_d_state[396] ^ c50_g_y;
        c50_mti = 1U;
      }

      c50_y = c50_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c50_mti, 1, 625, 1, 0) - 1];
      c50_d_state[624] = c50_mti;
      c50_y ^= c50_y >> 11U;
      c50_y ^= c50_y << 7U & 2636928640U;
      c50_y ^= c50_y << 15U & 4022730752U;
      c50_y ^= c50_y >> 18U;
      c50_u[(int32_T)c50_b_j - 1] = c50_y;
    }

    c50_u[0] >>= 5U;
    c50_u[1] >>= 6U;
    c50_b_r = 1.1102230246251565E-16 * ((real_T)c50_u[0] * 6.7108864E+7 +
      (real_T)c50_u[1]);
    if (c50_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c50_d_state[624] >= 1.0) {
        if ((real_T)c50_d_state[624] < 625.0) {
          c50_b4 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c50_b4 = false;
      }

      c50_isvalid = c50_b4;
      if (c50_isvalid) {
        c50_isvalid = false;
        c50_k = 0;
        exitg2 = false;
        while ((exitg2 == false) && (c50_k + 1 < 625)) {
          if ((real_T)c50_d_state[c50_k] == 0.0) {
            c50_a = c50_k + 1;
            c50_b_a = c50_a;
            c50_k = c50_b_a;
          } else {
            c50_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c50_isvalid) {
        c50_eml_error(chartInstance);
        c50_d6 = 5489.0;
        c50_b_twister_state_vector(chartInstance, c50_d_state, c50_d6);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c50_b_r;
}

static void c50_b_log10(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  *c50_x)
{
  (void)chartInstance;
  *c50_x = muDoubleScalarLog10(*c50_x);
}

static void c50_b_ceil(SFc50_Demo_AUV_VAInstanceStruct *chartInstance, real_T
  *c50_x)
{
  (void)chartInstance;
  *c50_x = muDoubleScalarCeil(*c50_x);
}

static real_T c50_get_bmlsL(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  uint32_T c50_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c50_b);
  if (chartInstance->c50_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2413) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c50_bmlsL_address)[c50_b];
}

static void c50_set_bmlsL(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  uint32_T c50_b, real_T c50_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c50_b);
  if (chartInstance->c50_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2413) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c50_bmlsL_address)[c50_b] = c50_c;
}

static real_T *c50_access_bmlsL(SFc50_Demo_AUV_VAInstanceStruct *chartInstance,
  uint32_T c50_b)
{
  real_T *c50_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c50_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2413) in the initialization routine of the chart.\n");
  }

  c50_c = *chartInstance->c50_bmlsL_address;
  if (c50_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c50_c;
}

static void init_dsm_address_info(SFc50_Demo_AUV_VAInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c50_bmlsL_address, &chartInstance->c50_bmlsL_index);
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

void sf_c50_Demo_AUV_VA_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1260294251U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(316823663U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1975895222U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(333728340U);
}

mxArray *sf_c50_Demo_AUV_VA_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SEoRvwdStvlMvt7ojSiHxE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[1] = (double)(15);
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
      pr[1] = (double)(6);
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2000);
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
      pr[0] = (double)(2000);
      pr[1] = (double)(5);
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
      pr[1] = (double)(6);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c50_Demo_AUV_VA_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c50_Demo_AUV_VA_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c50_Demo_AUV_VA(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[199],T\"emotion_amount_factor\",},{M[1],M[243],T\"emotion_amount_factor2\",},{M[3],M[175],T\"BMLl\",},{M[3],M[245],T\"au\",},{M[3],M[244],T\"au_L\",},{M[3],M[176],T\"newBmlsL\",},{M[3],M[259],T\"num\",},{M[3],M[258],T\"pp\",},{M[3],M[257],T\"randNum\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c50_Demo_AUV_VA\",},{M[8],M[116],T\"is_active_subFacial\",},{M[8],M[223],T\"is_active_subFacialMaryam\",},{M[8],M[250],T\"is_active_subFaceTwitch\",},{M[9],M[116],T\"is_subFacial\",},{M[9],M[223],T\"is_subFacialMaryam\",},{M[9],M[250],T\"is_subFaceTwitch\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[11],M[39],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M[197],M[1]}}},{M[11],M[39],T\"temporalCounter_i3\",S'et','os','ct'{{T\"ev\",M[227],M[1]}}},{M[11],M[39],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x2[252 251],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 23, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c50_Demo_AUV_VA_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_AUV_VAMachineNumber_,
           50,
           16,
           12,
           0,
           31,
           1,
           0,
           0,
           0,
           5,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_AUV_VAMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_AUV_VAMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_AUV_VAMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(1,0,0,0,"BMLl");
          _SFD_SET_DATA_PROPS(2,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(3,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(4,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(5,2,0,1,"emotion_amount_factor");
          _SFD_SET_DATA_PROPS(6,1,1,0,"internalE");
          _SFD_SET_DATA_PROPS(7,2,0,1,"emotion_amount_factor2");
          _SFD_SET_DATA_PROPS(8,0,0,0,"au_L");
          _SFD_SET_DATA_PROPS(9,0,0,0,"au");
          _SFD_SET_DATA_PROPS(10,1,1,0,"randTwitch");
          _SFD_SET_DATA_PROPS(11,0,0,0,"randNum");
          _SFD_SET_DATA_PROPS(12,0,0,0,"pp");
          _SFD_SET_DATA_PROPS(13,0,0,0,"num");
          _SFD_SET_DATA_PROPS(14,9,0,0,"");
          _SFD_SET_DATA_PROPS(15,8,0,0,"");
          _SFD_SET_DATA_PROPS(16,9,0,0,"");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,8,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,9,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
          _SFD_SET_DATA_PROPS(24,9,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,9,0,0,"");
          _SFD_SET_DATA_PROPS(28,8,0,0,"");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_SET_DATA_PROPS(30,8,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(5,0,1);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,1);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,8);
          _SFD_CH_SUBSTATE_INDEX(1,12);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_ST_SUBSTATE_COUNT(8,3);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_INDEX(8,2,11);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,3);
          _SFD_ST_SUBSTATE_INDEX(12,0,13);
          _SFD_ST_SUBSTATE_INDEX(12,1,14);
          _SFD_ST_SUBSTATE_INDEX(12,2,15);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(5,2);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(5,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"faceTwitchc50_Demo_AUV_VA",0,-1,402);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",402,-1,740);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",740,-1,1055);
        _SFD_CV_INIT_EML_IF(0,1,0,226,256,287,400);
        _SFD_CV_INIT_EML_IF(0,1,1,287,321,352,400);
        _SFD_CV_INIT_EML(3,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"set_AU_Amountc50_Demo_AUV_VA",0,-1,2467);
        _SFD_CV_INIT_EML_FOR(3,1,0,403,414,2467);
        _SFD_CV_INIT_EML(1,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"insertQueueLowc50_Demo_AUV_VA",0,-1,568);
        _SFD_CV_INIT_EML_IF(1,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(1,1,1,299,310,-1,549);
        _SFD_CV_INIT_EML_FOR(1,1,0,109,121,294);
        _SFD_CV_INIT_EML(2,1,1,0,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"setAUc50_Demo_AUV_VA",0,-1,2056);

        {
          static int caseStart[] = { 1696, 776, 867, 995, 1138, 1243, 1334, 1429,
            1516, 1604 };

          static int caseExprEnd[] = { 1705, 782, 873, 1001, 1144, 1249, 1340,
            1435, 1522, 1610 };

          _SFD_CV_INIT_EML_SWITCH(2,1,0,758,767,1966,10,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_EML(4,1,1,41,0,0,0,1,0,6,2);
        _SFD_CV_INIT_EML_FCN(4,0,"set_eAmountFactorc50_Demo_AUV_VA",0,-1,6325);
        _SFD_CV_INIT_EML_IF(4,1,0,184,192,1110,1122);
        _SFD_CV_INIT_EML_IF(4,1,1,215,223,294,1050);
        _SFD_CV_INIT_EML_IF(4,1,2,294,306,370,1050);
        _SFD_CV_INIT_EML_IF(4,1,3,370,382,456,1050);
        _SFD_CV_INIT_EML_IF(4,1,4,456,468,544,1050);
        _SFD_CV_INIT_EML_IF(4,1,5,544,556,634,1050);
        _SFD_CV_INIT_EML_IF(4,1,6,634,646,727,1050);
        _SFD_CV_INIT_EML_IF(4,1,7,727,739,814,1050);
        _SFD_CV_INIT_EML_IF(4,1,8,814,826,917,1050);
        _SFD_CV_INIT_EML_IF(4,1,9,1110,1122,2015,3873);
        _SFD_CV_INIT_EML_IF(4,1,10,1131,1139,1210,1958);
        _SFD_CV_INIT_EML_IF(4,1,11,1210,1222,1286,1958);
        _SFD_CV_INIT_EML_IF(4,1,12,1286,1298,1372,1958);
        _SFD_CV_INIT_EML_IF(4,1,13,1372,1384,1460,1958);
        _SFD_CV_INIT_EML_IF(4,1,14,1460,1472,1550,1958);
        _SFD_CV_INIT_EML_IF(4,1,15,1550,1562,1643,1958);
        _SFD_CV_INIT_EML_IF(4,1,16,1643,1655,1734,1958);
        _SFD_CV_INIT_EML_IF(4,1,17,1734,1746,1835,1958);
        _SFD_CV_INIT_EML_IF(4,1,18,2015,2027,2949,3873);
        _SFD_CV_INIT_EML_IF(4,1,19,2036,2044,2115,2883);
        _SFD_CV_INIT_EML_IF(4,1,20,2115,2127,2191,2883);
        _SFD_CV_INIT_EML_IF(4,1,21,2191,2203,2277,2883);
        _SFD_CV_INIT_EML_IF(4,1,22,2277,2289,2365,2883);
        _SFD_CV_INIT_EML_IF(4,1,23,2365,2377,2455,2883);
        _SFD_CV_INIT_EML_IF(4,1,24,2455,2467,2548,2883);
        _SFD_CV_INIT_EML_IF(4,1,25,2548,2560,2639,2883);
        _SFD_CV_INIT_EML_IF(4,1,26,2639,2651,2740,2883);
        _SFD_CV_INIT_EML_IF(4,1,27,2949,2961,-1,2961);
        _SFD_CV_INIT_EML_IF(4,1,28,2971,2979,3050,3818);
        _SFD_CV_INIT_EML_IF(4,1,29,3050,3062,3126,3818);
        _SFD_CV_INIT_EML_IF(4,1,30,3126,3138,3212,3818);
        _SFD_CV_INIT_EML_IF(4,1,31,3212,3224,3300,3818);
        _SFD_CV_INIT_EML_IF(4,1,32,3300,3312,3390,3818);
        _SFD_CV_INIT_EML_IF(4,1,33,3390,3402,3483,3818);
        _SFD_CV_INIT_EML_IF(4,1,34,3483,3495,3574,3818);
        _SFD_CV_INIT_EML_IF(4,1,35,3574,3586,3675,3818);
        _SFD_CV_INIT_EML_IF(4,1,36,4320,4333,-1,4483);
        _SFD_CV_INIT_EML_IF(4,1,37,4346,4393,-1,4471);
        _SFD_CV_INIT_EML_IF(4,1,38,4492,4505,4630,4758);
        _SFD_CV_INIT_EML_IF(4,1,39,4518,4543,-1,4621);
        _SFD_CV_INIT_EML_IF(4,1,40,4655,4667,-1,4746);
        _SFD_CV_INIT_EML_FOR(4,1,0,4300,4312,4770);

        {
          static int condStart[] = { 4350, 4361, 4372, 4383 };

          static int condEnd[] = { 4358, 4369, 4380, 4392 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2, 3, -2 };

          _SFD_CV_INIT_EML_MCDC(4,1,0,4350,4392,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4522, 4533 };

          static int condEnd[] = { 4530, 4542 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(4,1,1,4522,4542,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_SCRIPT(1,1,17,0,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"cmdBML_AU_VA",0,-1,1861);
        _SFD_CV_INIT_SCRIPT_IF(1,0,346,357,-1,1026);
        _SFD_CV_INIT_SCRIPT_IF(1,1,442,476,744,1004);
        _SFD_CV_INIT_SCRIPT_IF(1,2,1076,1084,1116,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,3,1116,1128,1160,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,4,1160,1172,1204,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,5,1204,1216,1248,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,6,1248,1260,1292,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,7,1292,1304,1336,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,8,1336,1348,1380,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,9,1380,1392,1424,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,10,1424,1436,1468,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,11,1468,1481,1515,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,12,1515,1528,1561,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,13,1561,1574,1607,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,14,1607,1620,1653,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,15,1653,1666,1699,1792);
        _SFD_CV_INIT_SCRIPT_IF(1,16,1699,1712,1745,1792);
        _SFD_CV_INIT_SCRIPT_FOR(1,0,288,299,1034);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"decArr2Str",0,-1,106);
        _SFD_CV_INIT_SCRIPT(3,1,7,0,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"cmdBML_AUmerg",0,-1,3091);
        _SFD_CV_INIT_SCRIPT_IF(3,0,487,521,1167,1803);
        _SFD_CV_INIT_SCRIPT_IF(3,1,2674,2682,2714,2726);
        _SFD_CV_INIT_SCRIPT_IF(3,2,2714,2726,2758,2937);
        _SFD_CV_INIT_SCRIPT_IF(3,3,2758,2770,2802,2937);
        _SFD_CV_INIT_SCRIPT_IF(3,4,2802,2814,2846,2937);
        _SFD_CV_INIT_SCRIPT_IF(3,5,2846,2858,2890,2937);
        _SFD_CV_INIT_SCRIPT_IF(3,6,2890,2902,-1,2902);
        _SFD_CV_INIT_SCRIPT_FOR(3,0,355,367,2542);
        _SFD_CV_INIT_SCRIPT(4,1,4,0,0,0,0,0,6,3);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"countDigits",0,-1,267);
        _SFD_CV_INIT_SCRIPT_IF(4,0,43,49,-1,94);
        _SFD_CV_INIT_SCRIPT_IF(4,1,103,120,152,175);
        _SFD_CV_INIT_SCRIPT_IF(4,2,152,175,207,263);
        _SFD_CV_INIT_SCRIPT_IF(4,3,207,232,-1,232);

        {
          static int condStart[] = { 107, 116 };

          static int condEnd[] = { 110, 119 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(4,0,106,120,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 160, 170 };

          static int condEnd[] = { 164, 174 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(4,1,159,175,2,2,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 215, 226 };

          static int condEnd[] = { 220, 231 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(4,2,214,232,2,4,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,0,13,0,13);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_j_sf_marshallOut,(MexInFcnForType)
            c50_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_j_sf_marshallOut,(MexInFcnForType)
            c50_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 15;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_i_sf_marshallOut,(MexInFcnForType)
            c50_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_l_sf_marshallOut,(MexInFcnForType)
            c50_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_l_sf_marshallOut,(MexInFcnForType)
            c50_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 15;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_i_sf_marshallOut,(MexInFcnForType)
            c50_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_j_sf_marshallOut,(MexInFcnForType)
            c50_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_j_sf_marshallOut,(MexInFcnForType)
            c50_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_l_sf_marshallOut,(MexInFcnForType)
            c50_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_l_sf_marshallOut,(MexInFcnForType)
            c50_g_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_l_sf_marshallOut,(MexInFcnForType)
            c50_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));

        {
          real_T *c50_inA;
          real_T *c50_inV;
          real_T *c50_internalE;
          real_T *c50_randTwitch;
          real_T (*c50_emotion_amount_factor)[15];
          real_T (*c50_emotion_amount_factor2)[6];
          c50_randTwitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c50_emotion_amount_factor2 = (real_T (*)[6])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c50_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c50_emotion_amount_factor = (real_T (*)[15])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c50_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c50_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c50_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c50_BMLl);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c50_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(3U, c50_inA);
          _SFD_SET_DATA_VALUE_PTR(4U, c50_inV);
          _SFD_SET_DATA_VALUE_PTR(5U, *c50_emotion_amount_factor);
          _SFD_SET_DATA_VALUE_PTR(6U, c50_internalE);
          _SFD_SET_DATA_VALUE_PTR(7U, *c50_emotion_amount_factor2);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c50_au_L);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c50_au);
          _SFD_SET_DATA_VALUE_PTR(10U, c50_randTwitch);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c50_randNum);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c50_pp);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c50_num);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_AUV_VAMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "6DtY0OqpqXQhFzePhHANIF";
}

static void sf_opaque_initialize_c50_Demo_AUV_VA(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc50_Demo_AUV_VAInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*)
    chartInstanceVar);
  initialize_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c50_Demo_AUV_VA(void *chartInstanceVar)
{
  enable_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c50_Demo_AUV_VA(void *chartInstanceVar)
{
  disable_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c50_Demo_AUV_VA(void *chartInstanceVar)
{
  sf_gateway_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c50_Demo_AUV_VA(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c50_Demo_AUV_VA
    ((SFc50_Demo_AUV_VAInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c50_Demo_AUV_VA();/* state var info */
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

extern void sf_internal_set_sim_state_c50_Demo_AUV_VA(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c50_Demo_AUV_VA();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c50_Demo_AUV_VA(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c50_Demo_AUV_VA(SimStruct* S, const mxArray *
  st)
{
}

static void sf_opaque_terminate_c50_Demo_AUV_VA(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc50_Demo_AUV_VAInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_AUV_VA_optimization_info();
    }

    finalize_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c50_Demo_AUV_VA(SimStruct *S)
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
    initialize_params_c50_Demo_AUV_VA((SFc50_Demo_AUV_VAInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c50_Demo_AUV_VA(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_AUV_VA_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      50);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,50,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,50,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,50);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,50,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,50,2);
    }

    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,50);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3247494856U));
  ssSetChecksum1(S,(950361587U));
  ssSetChecksum2(S,(3851430642U));
  ssSetChecksum3(S,(2839801951U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c50_Demo_AUV_VA(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c50_Demo_AUV_VA(SimStruct *S)
{
  SFc50_Demo_AUV_VAInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc50_Demo_AUV_VAInstanceStruct *)utMalloc(sizeof
    (SFc50_Demo_AUV_VAInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc50_Demo_AUV_VAInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c50_Demo_AUV_VA;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c50_Demo_AUV_VA;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c50_Demo_AUV_VA;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c50_Demo_AUV_VA;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c50_Demo_AUV_VA;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c50_Demo_AUV_VA;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c50_Demo_AUV_VA;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c50_Demo_AUV_VA;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c50_Demo_AUV_VA;
  chartInstance->chartInfo.mdlStart = mdlStart_c50_Demo_AUV_VA;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c50_Demo_AUV_VA;
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

void c50_Demo_AUV_VA_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c50_Demo_AUV_VA(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c50_Demo_AUV_VA(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c50_Demo_AUV_VA(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c50_Demo_AUV_VA_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
