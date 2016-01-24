/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_All_sfun.h"
#include "c9_Expriment_All.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_All_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c9_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_checkP                   ((uint8_T)1U)
#define c9_IN_gazeCamera               ((uint8_T)2U)
#define c9_IN_stateCheckSmile          ((uint8_T)3U)
#define c9_IN_stateInitial             ((uint8_T)4U)
#define c9_IN_wait                     ((uint8_T)5U)
#define c9_IN_ifHighNeurotic           ((uint8_T)1U)
#define c9_IN_init                     ((uint8_T)2U)
#define c9_IN_weightshiftPoseCategory2 ((uint8_T)3U)
#define c9_IN_initial                  ((uint8_T)1U)
#define c9_IN_stateFacialExpression    ((uint8_T)2U)
#define c9_IN_wait3                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c9_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_c_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c9_d_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c9_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_g_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c9_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_i_debug_family_names[10] = { "p", "a", "all_AUs", "c",
  "nargin", "nargout", "arousal", "valence", "inPersonality", "eAmountFactor" };

static const char * c9_j_debug_family_names[10] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5", "nargin", "nargout",
  "bmlID", "p", "poseBML" };

static const char * c9_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c9_w_debug_family_names[14] = { "L", "str1", "all_AUs", "c",
  "AU", "eA", "temp", "temp2", "str2", "mystr", "nargin", "nargout", "eAmount",
  "arrBML" };

static const char * c9_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c9_dataWrittenToVector[23];

/* Function Declarations */
static void initialize_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void initialize_params_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance);
static void enable_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void disable_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance);
static void set_sim_state_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_st);
static void c9_set_sim_state_side_effects_c9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance);
static void finalize_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void sf_gateway_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_enter_atomic_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_enter_internal_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance);
static void c9_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_exit_internal_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_initc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void initSimStructsc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_subSmile(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_enter_atomic_gazeCamera(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_enter_atomic_checkP(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_enter_atomic_weightshiftPoseCategory2
  (SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_b_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_c_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_d_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_e_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_f_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_g_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_h_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_i_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000]);
static void c9_cmdBML_AU_VA(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_eAmount[15], real_T c9_arrBML[2000]);
static real_T c9_abs(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
                     c9_x);
static real_T c9_log10(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
  c9_x);
static real_T c9_ceil(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
                      c9_x);
static void c9_eml_scalar_eg(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_b_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_c_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_d_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_e_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_f_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_g_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_h_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_i_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_j_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_k_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_l_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_m_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_n_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_o_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_fprintf(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
  c9_formatSpec);
static void c9_isequal(SFc9_Expriment_AllInstanceStruct *chartInstance);
static real_T c9_b_fprintf(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_varargin_1);
static void c9_j_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  char_T c9_mystr_data[], int32_T c9_mystr_sizes[2], real_T c9_myarr256[2000]);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static real_T c9_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_feval, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_strcat, const char_T *c9_identifier, char_T
  c9_y_data[], int32_T c9_y_sizes[2]);
static void c9_d_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2]);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_e_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_newBmls, const char_T *c9_identifier, real_T
  c9_y[10000]);
static void c9_f_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[10000]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_g_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_myBML, const char_T *c9_identifier, real_T
  c9_y[2000]);
static void c9_h_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2000]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_i_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_myarr256, const char_T *c9_identifier,
  real_T c9_y[2000]);
static void c9_j_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2000]);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_k_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_l_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[15]);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_o_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_p_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_q_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_r_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_s_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_t_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_u_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_v_sf_marshallOut(void *chartInstanceVoid, char_T
  c9_inData_data[], int32_T c9_inData_sizes[2]);
static void c9_m_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2]);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, char_T c9_outData_data[], int32_T
  c9_outData_sizes[2]);
static const mxArray *c9_w_sf_marshallOut(void *chartInstanceVoid, real_T
  c9_inData_data[], int32_T *c9_inData_sizes);
static void c9_n_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y_data[], int32_T *c9_y_sizes);
static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, real_T c9_outData_data[], int32_T
  *c9_outData_sizes);
static const mxArray *c9_x_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_o_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[103]);
static void c9_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_y_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_p_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[206]);
static void c9_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_q_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[306]);
static void c9_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_r_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[412]);
static void c9_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_s_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[515]);
static void c9_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_db_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_t_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[656]);
static void c9_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_u_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[759]);
static void c9_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_v_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[862]);
static void c9_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_w_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[965]);
static void c9_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_x_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1068]);
static void c9_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_y_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1171]);
static void c9_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_ab_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1474]);
static void c9_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_bb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1577]);
static void c9_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_cb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1610]);
static void c9_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_db_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1713]);
static void c9_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static void c9_b_info_helper(const mxArray **c9_info);
static void c9_activate_secsc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance);
static void c9_deactivate_secsc9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance);
static void c9_increment_counters_secsc9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_reset_counters_secsc9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance);
static void c9_insertQueuec9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmls[10000], real_T c9_myBML[2000], real_T
  c9_newBmls[10000]);
static void c9_insertQueueLowc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmls[10000], real_T c9_myBML[2000], real_T
  c9_newBmls[10000]);
static void c9_smileTablec9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000]);
static void c9_facialExprc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000]);
static void c9_set_AU_Amountc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_arousal, real_T c9_valence, real_T c9_inPersonality,
  real_T c9_eAmountFactor[15]);
static void c9_faceTwitchTablec9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance, real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000]);
static boolean_T c9_b_isequal(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_varargin_1[2000], real_T c9_varargin_2[2000]);
static const mxArray *c9_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int8_T c9_eb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_fb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_gb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_subSmile, const char_T *c9_identifier);
static uint8_T c9_hb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint32_T c9_ib_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i2, const char_T
  *c9_identifier);
static uint32_T c9_jb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static const mxArray *c9_kb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T
  *c9_identifier);
static const mxArray *c9_lb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_updateDataWrittenToVector(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex);
static void c9_errorIfDataNotWrittenToFcn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber);
static void c9_b_log10(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
  *c9_x);
static void c9_b_ceil(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
                      *c9_x);
static real_T c9_get_BML(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_BML(SFc9_Expriment_AllInstanceStruct *chartInstance, uint32_T
  c9_b, real_T c9_c);
static real_T *c9_access_BML(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_GAZE_WIN(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_GAZE_WIN(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_WIN(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_P(SFc9_Expriment_AllInstanceStruct *chartInstance, uint32_T
  c9_b);
static void c9_set_P(SFc9_Expriment_AllInstanceStruct *chartInstance, uint32_T
                     c9_b, real_T c9_c);
static real_T *c9_access_P(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_STATE_BEFORE(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_STATE_BEFORE(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_BEFORE(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_GO(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_STATE_GO(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_GO(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_READY(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_STATE_READY(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_READY(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_avert(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_avert(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_avert(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_bmlsL(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_bmlsL(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_bmlsL(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_bmlsM(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_bmlsM(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_bmlsM(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_emotion_amount_factor(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_emotion_amount_factor(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_emotion_amount_factor(SFc9_Expriment_AllInstanceStruct *
  chartInstance, uint32_T c9_b);
static real_T c9_get_gazing(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_gazing(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_gazing(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b);
static void init_dsm_address_info(SFc9_Expriment_AllInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c9_update_debugger_state_c9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c9_is_active_c9_Expriment_All == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_subSmile == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subSmile == c9_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subSmile == c9_IN_stateCheckSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subSmile == c9_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subSmile == c9_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subSmile == c9_IN_checkP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_faceTwitches == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_faceTwitches == c9_IN_ifHighNeurotic) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_faceTwitches == c9_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_faceTwitches == c9_IN_weightshiftPoseCategory2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_subFacial == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subFacial == c9_IN_stateFacialExpression) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subFacial == c9_IN_initial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_subFacial == c9_IN_wait3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  int32_T c9_i0;
  real_T c9_b_u[2000];
  const mxArray *c9_c_y = NULL;
  int32_T c9_i1;
  real_T c9_c_u[2000];
  const mxArray *c9_d_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_f_u;
  const mxArray *c9_g_y = NULL;
  real_T c9_e_hoistedGlobal;
  real_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  real_T c9_f_hoistedGlobal;
  real_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  int32_T c9_i2;
  real_T c9_i_u[2000];
  const mxArray *c9_j_y = NULL;
  int32_T c9_i3;
  static real_T c9_j_u[10000];
  const mxArray *c9_k_y = NULL;
  int32_T c9_i4;
  real_T c9_k_u[10000];
  const mxArray *c9_l_y = NULL;
  real_T c9_g_hoistedGlobal;
  real_T c9_l_u;
  const mxArray *c9_m_y = NULL;
  real_T c9_h_hoistedGlobal;
  real_T c9_m_u;
  const mxArray *c9_n_y = NULL;
  real_T c9_i_hoistedGlobal;
  real_T c9_n_u;
  const mxArray *c9_o_y = NULL;
  uint8_T c9_j_hoistedGlobal;
  uint8_T c9_o_u;
  const mxArray *c9_p_y = NULL;
  uint8_T c9_k_hoistedGlobal;
  uint8_T c9_p_u;
  const mxArray *c9_q_y = NULL;
  uint8_T c9_l_hoistedGlobal;
  uint8_T c9_q_u;
  const mxArray *c9_r_y = NULL;
  uint8_T c9_m_hoistedGlobal;
  uint8_T c9_r_u;
  const mxArray *c9_s_y = NULL;
  uint8_T c9_n_hoistedGlobal;
  uint8_T c9_s_u;
  const mxArray *c9_t_y = NULL;
  uint8_T c9_o_hoistedGlobal;
  uint8_T c9_t_u;
  const mxArray *c9_u_y = NULL;
  uint8_T c9_p_hoistedGlobal;
  uint8_T c9_u_u;
  const mxArray *c9_v_y = NULL;
  uint8_T c9_q_hoistedGlobal;
  uint8_T c9_v_u;
  const mxArray *c9_w_y = NULL;
  uint32_T c9_r_hoistedGlobal;
  uint32_T c9_w_u;
  const mxArray *c9_x_y = NULL;
  uint8_T c9_s_hoistedGlobal;
  uint8_T c9_x_u;
  const mxArray *c9_y_y = NULL;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(24, 1), false);
  c9_hoistedGlobal = *c9_gameState;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  for (c9_i0 = 0; c9_i0 < 2000; c9_i0++) {
    c9_b_u[c9_i0] = chartInstance->c9_BMLM[c9_i0];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 2, 2000, 1),
                false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  for (c9_i1 = 0; c9_i1 < 2000; c9_i1++) {
    c9_c_u[c9_i1] = chartInstance->c9_BMLl[c9_i1];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_c_u, 0, 0U, 1U, 0U, 2, 2000, 1),
                false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_b_hoistedGlobal = chartInstance->c9_au;
  c9_d_u = c9_b_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_c_hoistedGlobal = chartInstance->c9_au_L;
  c9_e_u = c9_c_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  c9_d_hoistedGlobal = chartInstance->c9_au_i;
  c9_f_u = c9_d_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  c9_e_hoistedGlobal = chartInstance->c9_emoDisp;
  c9_g_u = c9_e_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  c9_f_hoistedGlobal = chartInstance->c9_fileID;
  c9_h_u = c9_f_hoistedGlobal;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 7, c9_i_y);
  for (c9_i2 = 0; c9_i2 < 2000; c9_i2++) {
    c9_i_u[c9_i2] = chartInstance->c9_n[c9_i2];
  }

  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_i_u, 0, 0U, 1U, 0U, 1, 2000),
                false);
  sf_mex_setcell(c9_y, 8, c9_j_y);
  for (c9_i3 = 0; c9_i3 < 10000; c9_i3++) {
    c9_j_u[c9_i3] = chartInstance->c9_newBmlsL[c9_i3];
  }

  c9_k_y = NULL;
  sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_j_u, 0, 0U, 1U, 0U, 2, 2000, 5),
                false);
  sf_mex_setcell(c9_y, 9, c9_k_y);
  for (c9_i4 = 0; c9_i4 < 10000; c9_i4++) {
    c9_k_u[c9_i4] = chartInstance->c9_newBmlsM[c9_i4];
  }

  c9_l_y = NULL;
  sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_k_u, 0, 0U, 1U, 0U, 2, 2000, 5),
                false);
  sf_mex_setcell(c9_y, 10, c9_l_y);
  c9_g_hoistedGlobal = chartInstance->c9_poseNum;
  c9_l_u = c9_g_hoistedGlobal;
  c9_m_y = NULL;
  sf_mex_assign(&c9_m_y, sf_mex_create("y", &c9_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 11, c9_m_y);
  c9_h_hoistedGlobal = chartInstance->c9_poseRandFreq;
  c9_m_u = c9_h_hoistedGlobal;
  c9_n_y = NULL;
  sf_mex_assign(&c9_n_y, sf_mex_create("y", &c9_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 12, c9_n_y);
  c9_i_hoistedGlobal = chartInstance->c9_smileN;
  c9_n_u = c9_i_hoistedGlobal;
  c9_o_y = NULL;
  sf_mex_assign(&c9_o_y, sf_mex_create("y", &c9_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 13, c9_o_y);
  c9_j_hoistedGlobal = chartInstance->c9_is_active_c9_Expriment_All;
  c9_o_u = c9_j_hoistedGlobal;
  c9_p_y = NULL;
  sf_mex_assign(&c9_p_y, sf_mex_create("y", &c9_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 14, c9_p_y);
  c9_k_hoistedGlobal = chartInstance->c9_is_active_subSmile;
  c9_p_u = c9_k_hoistedGlobal;
  c9_q_y = NULL;
  sf_mex_assign(&c9_q_y, sf_mex_create("y", &c9_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 15, c9_q_y);
  c9_l_hoistedGlobal = chartInstance->c9_is_active_subFacial;
  c9_q_u = c9_l_hoistedGlobal;
  c9_r_y = NULL;
  sf_mex_assign(&c9_r_y, sf_mex_create("y", &c9_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 16, c9_r_y);
  c9_m_hoistedGlobal = chartInstance->c9_is_active_faceTwitches;
  c9_r_u = c9_m_hoistedGlobal;
  c9_s_y = NULL;
  sf_mex_assign(&c9_s_y, sf_mex_create("y", &c9_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 17, c9_s_y);
  c9_n_hoistedGlobal = chartInstance->c9_is_subSmile;
  c9_s_u = c9_n_hoistedGlobal;
  c9_t_y = NULL;
  sf_mex_assign(&c9_t_y, sf_mex_create("y", &c9_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 18, c9_t_y);
  c9_o_hoistedGlobal = chartInstance->c9_is_subFacial;
  c9_t_u = c9_o_hoistedGlobal;
  c9_u_y = NULL;
  sf_mex_assign(&c9_u_y, sf_mex_create("y", &c9_t_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 19, c9_u_y);
  c9_p_hoistedGlobal = chartInstance->c9_is_faceTwitches;
  c9_u_u = c9_p_hoistedGlobal;
  c9_v_y = NULL;
  sf_mex_assign(&c9_v_y, sf_mex_create("y", &c9_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 20, c9_v_y);
  c9_q_hoistedGlobal = chartInstance->c9_temporalCounter_i3;
  c9_v_u = c9_q_hoistedGlobal;
  c9_w_y = NULL;
  sf_mex_assign(&c9_w_y, sf_mex_create("y", &c9_v_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 21, c9_w_y);
  c9_r_hoistedGlobal = chartInstance->c9_temporalCounter_i2;
  c9_w_u = c9_r_hoistedGlobal;
  c9_x_y = NULL;
  sf_mex_assign(&c9_x_y, sf_mex_create("y", &c9_w_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 22, c9_x_y);
  c9_s_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
  c9_x_u = c9_s_hoistedGlobal;
  c9_y_y = NULL;
  sf_mex_assign(&c9_y_y, sf_mex_create("y", &c9_x_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 23, c9_y_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[2000];
  int32_T c9_i5;
  real_T c9_dv1[2000];
  int32_T c9_i6;
  real_T c9_dv2[2000];
  int32_T c9_i7;
  static real_T c9_dv3[10000];
  int32_T c9_i8;
  static real_T c9_dv4[10000];
  int32_T c9_i9;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  *c9_gameState = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 0)), "gameState");
  c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
                        "BMLM", c9_dv0);
  for (c9_i5 = 0; c9_i5 < 2000; c9_i5++) {
    chartInstance->c9_BMLM[c9_i5] = c9_dv0[c9_i5];
  }

  c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
                        "BMLl", c9_dv1);
  for (c9_i6 = 0; c9_i6 < 2000; c9_i6++) {
    chartInstance->c9_BMLl[c9_i6] = c9_dv1[c9_i6];
  }

  chartInstance->c9_au = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 3)), "au");
  chartInstance->c9_au_L = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 4)), "au_L");
  chartInstance->c9_au_i = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 5)), "au_i");
  chartInstance->c9_emoDisp = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 6)), "emoDisp");
  chartInstance->c9_fileID = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 7)), "fileID");
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 8)), "n",
                        c9_dv2);
  for (c9_i7 = 0; c9_i7 < 2000; c9_i7++) {
    chartInstance->c9_n[c9_i7] = c9_dv2[c9_i7];
  }

  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 9)),
                        "newBmlsL", c9_dv3);
  for (c9_i8 = 0; c9_i8 < 10000; c9_i8++) {
    chartInstance->c9_newBmlsL[c9_i8] = c9_dv3[c9_i8];
  }

  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 10)),
                        "newBmlsM", c9_dv4);
  for (c9_i9 = 0; c9_i9 < 10000; c9_i9++) {
    chartInstance->c9_newBmlsM[c9_i9] = c9_dv4[c9_i9];
  }

  chartInstance->c9_poseNum = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 11)), "poseNum");
  chartInstance->c9_poseRandFreq = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 12)), "poseRandFreq");
  chartInstance->c9_smileN = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 13)), "smileN");
  chartInstance->c9_is_active_c9_Expriment_All = c9_gb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 14)),
     "is_active_c9_Expriment_All");
  chartInstance->c9_is_active_subSmile = c9_gb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 15)), "is_active_subSmile");
  chartInstance->c9_is_active_subFacial = c9_gb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 16)), "is_active_subFacial");
  chartInstance->c9_is_active_faceTwitches = c9_gb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 17)),
     "is_active_faceTwitches");
  chartInstance->c9_is_subSmile = c9_gb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 18)), "is_subSmile");
  chartInstance->c9_is_subFacial = c9_gb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 19)), "is_subFacial");
  chartInstance->c9_is_faceTwitches = c9_gb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 20)), "is_faceTwitches");
  chartInstance->c9_temporalCounter_i3 = c9_gb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 21)), "temporalCounter_i3");
  chartInstance->c9_temporalCounter_i2 = c9_ib_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 22)), "temporalCounter_i2");
  chartInstance->c9_temporalCounter_i1 = c9_gb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 23)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 24)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_Expriment_All(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (chartInstance->c9_is_active_subSmile == 1U) {
      chartInstance->c9_tp_subSmile = 1U;
    } else {
      chartInstance->c9_tp_subSmile = 0U;
    }

    if (chartInstance->c9_is_subSmile == c9_IN_checkP) {
      chartInstance->c9_tp_checkP = 1U;
    } else {
      chartInstance->c9_tp_checkP = 0U;
    }

    if (chartInstance->c9_is_subSmile == c9_IN_gazeCamera) {
      chartInstance->c9_tp_gazeCamera = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_gazeCamera = 0U;
    }

    if (chartInstance->c9_is_subSmile == c9_IN_stateCheckSmile) {
      chartInstance->c9_tp_stateCheckSmile = 1U;
    } else {
      chartInstance->c9_tp_stateCheckSmile = 0U;
    }

    if (chartInstance->c9_is_subSmile == c9_IN_stateInitial) {
      chartInstance->c9_tp_stateInitial = 1U;
    } else {
      chartInstance->c9_tp_stateInitial = 0U;
    }

    if (chartInstance->c9_is_subSmile == c9_IN_wait) {
      chartInstance->c9_tp_wait = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_wait = 0U;
    }

    if (chartInstance->c9_is_active_subFacial == 1U) {
      chartInstance->c9_tp_subFacial = 1U;
    } else {
      chartInstance->c9_tp_subFacial = 0U;
    }

    if (chartInstance->c9_is_subFacial == c9_IN_initial) {
      chartInstance->c9_tp_initial = 1U;
    } else {
      chartInstance->c9_tp_initial = 0U;
    }

    if (chartInstance->c9_is_subFacial == c9_IN_stateFacialExpression) {
      chartInstance->c9_tp_stateFacialExpression = 1U;
    } else {
      chartInstance->c9_tp_stateFacialExpression = 0U;
    }

    if (chartInstance->c9_is_subFacial == c9_IN_wait3) {
      chartInstance->c9_tp_wait3 = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c9_temporalCounter_i3 = 0U;
      }
    } else {
      chartInstance->c9_tp_wait3 = 0U;
    }

    if (chartInstance->c9_is_active_faceTwitches == 1U) {
      chartInstance->c9_tp_faceTwitches = 1U;
    } else {
      chartInstance->c9_tp_faceTwitches = 0U;
    }

    if (chartInstance->c9_is_faceTwitches == c9_IN_ifHighNeurotic) {
      chartInstance->c9_tp_ifHighNeurotic = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c9_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c9_tp_ifHighNeurotic = 0U;
    }

    if (chartInstance->c9_is_faceTwitches == c9_IN_init) {
      chartInstance->c9_tp_init = 1U;
    } else {
      chartInstance->c9_tp_init = 0U;
    }

    if (chartInstance->c9_is_faceTwitches == c9_IN_weightshiftPoseCategory2) {
      chartInstance->c9_tp_weightshiftPoseCategory2 = 1U;
    } else {
      chartInstance->c9_tp_weightshiftPoseCategory2 = 0U;
    }

    chartInstance->c9_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_gateway_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  c9_set_sim_state_side_effects_c9_Expriment_All(chartInstance);
}

static void c9_enter_atomic_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  chartInstance->c9_is_active_c9_Expriment_All = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
}

static void c9_enter_internal_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_dv5[2000];
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_subSmile = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_subSmile = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_subSmile = c9_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateInitial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_p_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  *c9_gameState = 14.0;
  c9_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_gameState, 8U);
  c9_encStr2Arr(chartInstance, c9_dv5);
  for (c9_i10 = 0; c9_i10 < 2000; c9_i10++) {
    chartInstance->c9_n[c9_i10] = c9_dv5[c9_i10];
  }

  c9_updateDataWrittenToVector(chartInstance, 5U);
  for (c9_i11 = 0; c9_i11 < 2000; c9_i11++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_n[c9_i11], 15U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 5U, 15U);
  for (c9_i12 = 0; c9_i12 < 2000; c9_i12++) {
    c9_set_bmlsM(chartInstance, c9_i12, chartInstance->c9_n[c9_i12]);
  }

  for (c9_i13 = 0; c9_i13 < 2000; c9_i13++) {
    c9_set_bmlsM(chartInstance, c9_i13 + 2000, chartInstance->c9_n[c9_i13]);
  }

  for (c9_i14 = 0; c9_i14 < 2000; c9_i14++) {
    c9_set_bmlsM(chartInstance, c9_i14 + 4000, chartInstance->c9_n[c9_i14]);
  }

  for (c9_i15 = 0; c9_i15 < 2000; c9_i15++) {
    c9_set_bmlsM(chartInstance, c9_i15 + 6000, chartInstance->c9_n[c9_i15]);
  }

  for (c9_i16 = 0; c9_i16 < 2000; c9_i16++) {
    c9_set_bmlsM(chartInstance, c9_i16 + 8000, chartInstance->c9_n[c9_i16]);
  }

  c9_updateDataWrittenToVector(chartInstance, 5U);
  c9_updateDataWrittenToVector(chartInstance, 5U);
  c9_updateDataWrittenToVector(chartInstance, 5U);
  c9_updateDataWrittenToVector(chartInstance, 5U);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 5U, 15U);
  for (c9_i17 = 0; c9_i17 < 2000; c9_i17++) {
    chartInstance->c9_newBmlsM[c9_i17] = chartInstance->c9_n[c9_i17];
  }

  for (c9_i18 = 0; c9_i18 < 2000; c9_i18++) {
    chartInstance->c9_newBmlsM[c9_i18 + 2000] = chartInstance->c9_n[c9_i18];
  }

  for (c9_i19 = 0; c9_i19 < 2000; c9_i19++) {
    chartInstance->c9_newBmlsM[c9_i19 + 4000] = chartInstance->c9_n[c9_i19];
  }

  for (c9_i20 = 0; c9_i20 < 2000; c9_i20++) {
    chartInstance->c9_newBmlsM[c9_i20 + 6000] = chartInstance->c9_n[c9_i20];
  }

  for (c9_i21 = 0; c9_i21 < 2000; c9_i21++) {
    chartInstance->c9_newBmlsM[c9_i21 + 8000] = chartInstance->c9_n[c9_i21];
  }

  c9_updateDataWrittenToVector(chartInstance, 5U);
  c9_updateDataWrittenToVector(chartInstance, 5U);
  c9_updateDataWrittenToVector(chartInstance, 5U);
  c9_updateDataWrittenToVector(chartInstance, 5U);
  c9_updateDataWrittenToVector(chartInstance, 3U);
  for (c9_i22 = 0; c9_i22 < 10000; c9_i22++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsM[c9_i22], 12U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_subFacial = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_subFacial = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_subFacial = c9_IN_initial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_initial = 1U;
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_faceTwitches = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_faceTwitches = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_faceTwitches = c9_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_init = 1U;
}

static void c9_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_dv6[15];
  int32_T c9_i23;
  int32_T c9_i24;
  real_T c9_dv7[15];
  real_T c9_dv8[2000];
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  static real_T c9_dv9[10000];
  int32_T c9_i28;
  real_T c9_dv10[2000];
  static real_T c9_dv11[10000];
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  uint32_T c9_b_debug_family_var_map[3];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 0.0;
  real_T c9_dv12[15];
  int32_T c9_i32;
  int32_T c9_i33;
  real_T c9_dv13[15];
  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  static real_T c9_dv14[10000];
  int32_T c9_i37;
  real_T c9_dv15[2000];
  static real_T c9_dv16[10000];
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i40;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_b_out;
  boolean_T c9_temp;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 0.0;
  real_T *c9_inA;
  real_T *c9_inV;
  real_T *c9_personality;
  real_T (*c9_randArray)[40];
  boolean_T guard1 = false;
  c9_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 8);
  c9_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c9_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_isStable = true;
  c9_subSmile(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_subFacial) {
   case c9_IN_initial:
    CV_STATE_EVAL(10, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_initial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_subFacial = c9_IN_stateFacialExpression;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateFacialExpression = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_u_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_set_AU_Amountc9_Expriment_All(chartInstance, *c9_inA, *c9_inV,
      *c9_personality, c9_dv6);
    for (c9_i23 = 0; c9_i23 < 15; c9_i23++) {
      c9_set_emotion_amount_factor(chartInstance, c9_i23, c9_dv6[c9_i23]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 9);
    for (c9_i24 = 0; c9_i24 < 15; c9_i24++) {
      c9_dv7[c9_i24] = c9_get_emotion_amount_factor(chartInstance, c9_i24);
    }

    c9_cmdBML_AU_VA(chartInstance, c9_dv7, c9_dv8);
    for (c9_i25 = 0; c9_i25 < 2000; c9_i25++) {
      chartInstance->c9_BMLl[c9_i25] = c9_dv8[c9_i25];
    }

    c9_updateDataWrittenToVector(chartInstance, 10U);
    for (c9_i26 = 0; c9_i26 < 2000; c9_i26++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i26], 25U);
    }

    c9_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
    for (c9_i27 = 0; c9_i27 < 10000; c9_i27++) {
      c9_dv9[c9_i27] = c9_get_bmlsL(chartInstance, c9_i27);
    }

    for (c9_i28 = 0; c9_i28 < 2000; c9_i28++) {
      c9_dv10[c9_i28] = chartInstance->c9_BMLl[c9_i28];
    }

    c9_insertQueueLowc9_Expriment_All(chartInstance, c9_dv9, c9_dv10, c9_dv11);
    for (c9_i29 = 0; c9_i29 < 10000; c9_i29++) {
      chartInstance->c9_newBmlsL[c9_i29] = c9_dv11[c9_i29];
    }

    c9_updateDataWrittenToVector(chartInstance, 11U);
    for (c9_i30 = 0; c9_i30 < 10000; c9_i30++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i30], 26U);
    }

    c9_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
    for (c9_i31 = 0; c9_i31 < 10000; c9_i31++) {
      c9_set_bmlsL(chartInstance, c9_i31, chartInstance->c9_newBmlsL[c9_i31]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 7);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateFacialExpression:
    CV_STATE_EVAL(10, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateFacialExpression = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_subFacial = c9_IN_wait3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i3 = 0U;
    chartInstance->c9_tp_wait3 = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_wait3:
    CV_STATE_EVAL(10, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_fb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_f_sf_marshallOut,
      c9_e_sf_marshallIn);
    c9_out = CV_EML_IF(10, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                       (chartInstance->c9_temporalCounter_i3 >= 7));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_wait3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_subFacial = c9_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateFacialExpression = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_u_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
        c9_c_sf_marshallOut, c9_c_sf_marshallIn);
      c9_set_AU_Amountc9_Expriment_All(chartInstance, *c9_inA, *c9_inV,
        *c9_personality, c9_dv12);
      for (c9_i32 = 0; c9_i32 < 15; c9_i32++) {
        c9_set_emotion_amount_factor(chartInstance, c9_i32, c9_dv12[c9_i32]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 9);
      for (c9_i33 = 0; c9_i33 < 15; c9_i33++) {
        c9_dv13[c9_i33] = c9_get_emotion_amount_factor(chartInstance, c9_i33);
      }

      c9_cmdBML_AU_VA(chartInstance, c9_dv13, c9_dv8);
      for (c9_i34 = 0; c9_i34 < 2000; c9_i34++) {
        chartInstance->c9_BMLl[c9_i34] = c9_dv8[c9_i34];
      }

      c9_updateDataWrittenToVector(chartInstance, 10U);
      for (c9_i35 = 0; c9_i35 < 2000; c9_i35++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i35], 25U);
      }

      c9_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
      for (c9_i36 = 0; c9_i36 < 10000; c9_i36++) {
        c9_dv14[c9_i36] = c9_get_bmlsL(chartInstance, c9_i36);
      }

      for (c9_i37 = 0; c9_i37 < 2000; c9_i37++) {
        c9_dv15[c9_i37] = chartInstance->c9_BMLl[c9_i37];
      }

      c9_insertQueueLowc9_Expriment_All(chartInstance, c9_dv14, c9_dv15, c9_dv16);
      for (c9_i38 = 0; c9_i38 < 10000; c9_i38++) {
        chartInstance->c9_newBmlsL[c9_i38] = c9_dv16[c9_i38];
      }

      c9_updateDataWrittenToVector(chartInstance, 11U);
      for (c9_i39 = 0; c9_i39 < 10000; c9_i39++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i39], 26U);
      }

      c9_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
      for (c9_i40 = 0; c9_i40 < 10000; c9_i40++) {
        c9_set_bmlsL(chartInstance, c9_i40, chartInstance->c9_newBmlsL[c9_i40]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 7);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(10, 0, 0);
    chartInstance->c9_is_subFacial = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c9_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_faceTwitches) {
   case c9_IN_ifHighNeurotic:
    CV_STATE_EVAL(1, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_eb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_f_sf_marshallOut,
      c9_e_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 12U, 32U);
    c9_temp = (chartInstance->c9_sfEvent == c9_event_secs);
    if (c9_temp) {
      c9_temp = (chartInstance->c9_temporalCounter_i2 >=
                 _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
                  chartInstance->c9_poseRandFreq, 32U, 12U));
    }

    c9_b_out = CV_EML_IF(12, 0, 0, c9_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_ifHighNeurotic = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_faceTwitches = c9_IN_weightshiftPoseCategory2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_weightshiftPoseCategory2 = 1U;
      c9_enter_atomic_weightshiftPoseCategory2(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_init:
    CV_STATE_EVAL(1, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_db_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_f_sf_marshallOut,
      c9_e_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(14, 0, 0, *c9_personality == 1.0)) {
      guard1 = true;
    } else if (CV_EML_COND(14, 0, 1, *c9_personality == 2.0)) {
      guard1 = true;
    } else {
      CV_EML_MCDC(14, 0, 0, false);
      CV_EML_IF(14, 0, 0, false);
      c9_c_out = false;
    }

    if (guard1 == true) {
      CV_EML_MCDC(14, 0, 0, true);
      CV_EML_IF(14, 0, 0, true);
      c9_c_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_faceTwitches = c9_IN_ifHighNeurotic;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i2 = 0U;
      chartInstance->c9_tp_ifHighNeurotic = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_s_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
        c9_c_sf_marshallOut, c9_c_sf_marshallIn);
      chartInstance->c9_poseNum = (*c9_randArray)[27];
      c9_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c9_poseNum, 33U);
      chartInstance->c9_poseRandFreq = (*c9_randArray)[28];
      c9_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c9_poseRandFreq, 32U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_weightshiftPoseCategory2:
    CV_STATE_EVAL(1, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_weightshiftPoseCategory2 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_faceTwitches = c9_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_init = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 0, 0);
    chartInstance->c9_is_faceTwitches = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
}

static void c9_exit_internal_c9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c9_is_faceTwitches) {
   case c9_IN_ifHighNeurotic:
    CV_STATE_EVAL(1, 1, 1);
    chartInstance->c9_tp_ifHighNeurotic = 0U;
    chartInstance->c9_is_faceTwitches = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_init:
    CV_STATE_EVAL(1, 1, 2);
    chartInstance->c9_tp_init = 0U;
    chartInstance->c9_is_faceTwitches = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_weightshiftPoseCategory2:
    CV_STATE_EVAL(1, 1, 3);
    chartInstance->c9_tp_weightshiftPoseCategory2 = 0U;
    chartInstance->c9_is_faceTwitches = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c9_is_faceTwitches = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_faceTwitches = 0U;
  chartInstance->c9_is_active_faceTwitches = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_subFacial) {
   case c9_IN_initial:
    CV_STATE_EVAL(10, 1, 1);
    chartInstance->c9_tp_initial = 0U;
    chartInstance->c9_is_subFacial = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateFacialExpression:
    CV_STATE_EVAL(10, 1, 2);
    chartInstance->c9_tp_stateFacialExpression = 0U;
    chartInstance->c9_is_subFacial = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_wait3:
    CV_STATE_EVAL(10, 1, 3);
    chartInstance->c9_tp_wait3 = 0U;
    chartInstance->c9_is_subFacial = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(10, 1, 0);
    chartInstance->c9_is_subFacial = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_subFacial = 0U;
  chartInstance->c9_is_active_subFacial = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_subSmile) {
   case c9_IN_checkP:
    CV_STATE_EVAL(14, 1, 1);
    chartInstance->c9_tp_checkP = 0U;
    chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_gazeCamera:
    CV_STATE_EVAL(14, 1, 2);
    chartInstance->c9_tp_gazeCamera = 0U;
    chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateCheckSmile:
    CV_STATE_EVAL(14, 1, 3);
    chartInstance->c9_tp_stateCheckSmile = 0U;
    chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateInitial:
    CV_STATE_EVAL(14, 1, 4);
    chartInstance->c9_tp_stateInitial = 0U;
    chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_wait:
    CV_STATE_EVAL(14, 1, 5);
    chartInstance->c9_tp_wait = 0U;
    chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(14, 1, 0);
    chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_subSmile = 0U;
  chartInstance->c9_is_active_subSmile = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
}

static void c9_initc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_doSetSimStateSideEffects = 0U;
  chartInstance->c9_setSimStateSideEffectsInfo = NULL;
  chartInstance->c9_is_active_faceTwitches = 0U;
  chartInstance->c9_is_faceTwitches = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_faceTwitches = 0U;
  chartInstance->c9_tp_ifHighNeurotic = 0U;
  chartInstance->c9_temporalCounter_i2 = 0U;
  chartInstance->c9_tp_init = 0U;
  chartInstance->c9_tp_weightshiftPoseCategory2 = 0U;
  chartInstance->c9_is_active_subFacial = 0U;
  chartInstance->c9_is_subFacial = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_subFacial = 0U;
  chartInstance->c9_tp_initial = 0U;
  chartInstance->c9_tp_stateFacialExpression = 0U;
  chartInstance->c9_tp_wait3 = 0U;
  chartInstance->c9_temporalCounter_i3 = 0U;
  chartInstance->c9_is_active_subSmile = 0U;
  chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_subSmile = 0U;
  chartInstance->c9_tp_checkP = 0U;
  chartInstance->c9_tp_gazeCamera = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateCheckSmile = 0U;
  chartInstance->c9_tp_stateInitial = 0U;
  chartInstance->c9_tp_wait = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_is_active_c9_Expriment_All = 0U;
}

static void initSimStructsc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c9_subSmile(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_e_out;
  real_T *c9_isSmiling;
  real_T *c9_gameState;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_subSmile) {
   case c9_IN_checkP:
    CV_STATE_EVAL(14, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_checkP = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_subSmile = c9_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_gazeCamera:
    CV_STATE_EVAL(14, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_cb_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_f_sf_marshallOut,
      c9_e_sf_marshallIn);
    guard4 = false;
    if (CV_EML_COND(3, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                    (chartInstance->c9_temporalCounter_i1 >= 1))) {
      if (CV_EML_COND(3, 0, 1, *c9_isSmiling == 1.0)) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c9_out = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c9_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_gazeCamera = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_subSmile = c9_IN_checkP;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_checkP = 1U;
      c9_enter_atomic_checkP(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_y_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U,
        c9_c_sf_marshallOut, c9_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_f_sf_marshallOut,
        c9_e_sf_marshallIn);
      guard3 = false;
      if (CV_EML_COND(7, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                      (chartInstance->c9_temporalCounter_i1 >= 1))) {
        if (CV_EML_COND(7, 0, 1, *c9_isSmiling != 1.0)) {
          CV_EML_MCDC(7, 0, 0, true);
          CV_EML_IF(7, 0, 0, true);
          c9_b_out = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(7, 0, 0, false);
        CV_EML_IF(7, 0, 0, false);
        c9_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_gazeCamera = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_subSmile = c9_IN_stateCheckSmile;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateCheckSmile = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                     chartInstance->c9_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateCheckSmile:
    CV_STATE_EVAL(14, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_bb_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_f_sf_marshallOut,
      c9_e_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    if (CV_EML_COND(4, 0, 0, *c9_isSmiling == 1.0)) {
      if (CV_EML_COND(4, 0, 1, *c9_gameState != c9_get_STATE_GO(chartInstance, 0)))
      {
        if (CV_EML_COND(4, 0, 2, *c9_gameState != c9_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(4, 0, 0, true);
          CV_EML_IF(4, 0, 0, true);
          c9_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
        guard2 = true;
      }
    } else {
      c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
      guard2 = true;
    }

    if (guard2 == true) {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(4, 0, 0, false);
      CV_EML_IF(4, 0, 0, false);
      c9_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_subSmile = c9_IN_gazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_gazeCamera = 1U;
      c9_enter_atomic_gazeCamera(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_subSmile = c9_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckSmile = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateInitial:
    CV_STATE_EVAL(14, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_x_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_f_sf_marshallOut,
      c9_e_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
    c9_d_out = CV_EML_IF(1, 0, 0, *c9_gameState == 20.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateInitial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_subSmile = c9_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_wait:
    CV_STATE_EVAL(14, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ab_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U, c9_f_sf_marshallOut,
      c9_e_sf_marshallIn);
    c9_e_out = CV_EML_IF(5, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 10));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_subSmile = c9_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(14, 0, 0);
    chartInstance->c9_is_subSmile = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_gazeCamera(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLM[2000];
  real_T c9_P;
  int32_T c9_i41;
  real_T c9_c_BMLM[2000];
  int32_T c9_i42;
  int32_T c9_i43;
  int32_T c9_i44;
  static real_T c9_dv17[10000];
  int32_T c9_i45;
  real_T c9_dv18[2000];
  static real_T c9_dv19[10000];
  int32_T c9_i46;
  int32_T c9_i47;
  int32_T c9_i48;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_q_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_smileTablec9_Expriment_All(chartInstance, 2.0, &c9_P, c9_b_BMLM);
  for (c9_i41 = 0; c9_i41 < 2000; c9_i41++) {
    c9_c_BMLM[c9_i41] = c9_b_BMLM[c9_i41];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c9_i42 = 0; c9_i42 < 2000; c9_i42++) {
    chartInstance->c9_BMLM[c9_i42] = c9_c_BMLM[c9_i42];
  }

  c9_updateDataWrittenToVector(chartInstance, 4U);
  for (c9_i43 = 0; c9_i43 < 2000; c9_i43++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLM[c9_i43], 14U);
  }

  c9_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 4U, 14U);
  for (c9_i44 = 0; c9_i44 < 10000; c9_i44++) {
    c9_dv17[c9_i44] = c9_get_bmlsM(chartInstance, c9_i44);
  }

  for (c9_i45 = 0; c9_i45 < 2000; c9_i45++) {
    c9_dv18[c9_i45] = chartInstance->c9_BMLM[c9_i45];
  }

  c9_insertQueuec9_Expriment_All(chartInstance, c9_dv17, c9_dv18, c9_dv19);
  for (c9_i46 = 0; c9_i46 < 10000; c9_i46++) {
    chartInstance->c9_newBmlsM[c9_i46] = c9_dv19[c9_i46];
  }

  c9_updateDataWrittenToVector(chartInstance, 3U);
  for (c9_i47 = 0; c9_i47 < 10000; c9_i47++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsM[c9_i47], 12U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 12U);
  for (c9_i48 = 0; c9_i48 < 10000; c9_i48++) {
    c9_set_bmlsM(chartInstance, c9_i48, chartInstance->c9_newBmlsM[c9_i48]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_checkP(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLM[2000];
  real_T c9_P;
  int32_T c9_i49;
  real_T c9_c_BMLM[2000];
  int32_T c9_i50;
  int32_T c9_i51;
  int32_T c9_i52;
  static real_T c9_dv20[10000];
  int32_T c9_i53;
  real_T c9_dv21[2000];
  static real_T c9_dv22[10000];
  int32_T c9_i54;
  int32_T c9_i55;
  int32_T c9_i56;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_r_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_smileTablec9_Expriment_All(chartInstance, 1.0, &c9_P, c9_b_BMLM);
  for (c9_i49 = 0; c9_i49 < 2000; c9_i49++) {
    c9_c_BMLM[c9_i49] = c9_b_BMLM[c9_i49];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c9_i50 = 0; c9_i50 < 2000; c9_i50++) {
    chartInstance->c9_BMLM[c9_i50] = c9_c_BMLM[c9_i50];
  }

  c9_updateDataWrittenToVector(chartInstance, 4U);
  for (c9_i51 = 0; c9_i51 < 2000; c9_i51++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLM[c9_i51], 14U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 4U, 14U);
  for (c9_i52 = 0; c9_i52 < 10000; c9_i52++) {
    c9_dv20[c9_i52] = c9_get_bmlsM(chartInstance, c9_i52);
  }

  for (c9_i53 = 0; c9_i53 < 2000; c9_i53++) {
    c9_dv21[c9_i53] = chartInstance->c9_BMLM[c9_i53];
  }

  c9_insertQueuec9_Expriment_All(chartInstance, c9_dv20, c9_dv21, c9_dv22);
  for (c9_i54 = 0; c9_i54 < 10000; c9_i54++) {
    chartInstance->c9_newBmlsM[c9_i54] = c9_dv22[c9_i54];
  }

  c9_updateDataWrittenToVector(chartInstance, 3U);
  for (c9_i55 = 0; c9_i55 < 10000; c9_i55++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsM[c9_i55], 12U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 12U);
  for (c9_i56 = 0; c9_i56 < 10000; c9_i56++) {
    c9_set_bmlsM(chartInstance, c9_i56, chartInstance->c9_newBmlsM[c9_i56]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_weightshiftPoseCategory2
  (SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLl[2000];
  real_T c9_P;
  int32_T c9_i57;
  real_T c9_c_BMLl[2000];
  int32_T c9_i58;
  int32_T c9_i59;
  int32_T c9_i60;
  static real_T c9_dv23[10000];
  int32_T c9_i61;
  real_T c9_dv24[2000];
  static real_T c9_dv25[10000];
  int32_T c9_i62;
  int32_T c9_i63;
  int32_T c9_i64;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_t_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 13U, 33U);
  c9_faceTwitchTablec9_Expriment_All(chartInstance, chartInstance->c9_poseNum,
    &c9_P, c9_b_BMLl);
  for (c9_i57 = 0; c9_i57 < 2000; c9_i57++) {
    c9_c_BMLl[c9_i57] = c9_b_BMLl[c9_i57];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c9_i58 = 0; c9_i58 < 2000; c9_i58++) {
    chartInstance->c9_BMLl[c9_i58] = c9_c_BMLl[c9_i58];
  }

  c9_updateDataWrittenToVector(chartInstance, 10U);
  for (c9_i59 = 0; c9_i59 < 2000; c9_i59++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i59], 25U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
  for (c9_i60 = 0; c9_i60 < 10000; c9_i60++) {
    c9_dv23[c9_i60] = c9_get_bmlsL(chartInstance, c9_i60);
  }

  for (c9_i61 = 0; c9_i61 < 2000; c9_i61++) {
    c9_dv24[c9_i61] = chartInstance->c9_BMLl[c9_i61];
  }

  c9_insertQueueLowc9_Expriment_All(chartInstance, c9_dv23, c9_dv24, c9_dv25);
  for (c9_i62 = 0; c9_i62 < 10000; c9_i62++) {
    chartInstance->c9_newBmlsL[c9_i62] = c9_dv25[c9_i62];
  }

  c9_updateDataWrittenToVector(chartInstance, 11U);
  for (c9_i63 = 0; c9_i63 < 10000; c9_i63++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i63], 26U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
  for (c9_i64 = 0; c9_i64 < 10000; c9_i64++) {
    c9_set_bmlsL(chartInstance, c9_i64, chartInstance->c9_newBmlsL[c9_i64]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr;
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i65;
  int32_T c9_i66;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_b_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_arr, 1U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_mystr, 5U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  c9_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1999.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i65 = 0; c9_i65 < 2000; c9_i65++) {
    c9_tt[c9_i65] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_tt[0] = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i66 = 0; c9_i66 < 2000; c9_i66++) {
    c9_myarr256[c9_i66] = c9_tt[c9_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_b_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[222];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[222];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i67;
  static char_T c9_cv0[222] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c', 't',
    '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e',
    '=', '\"', '2', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '3', '\"',
    ' ', 'e', 'n', 'd', '=', '\"', '4', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=', '\"',
    '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k',
    'e', '=', '\"', '2', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '3',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '4', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i68;
  static real_T c9_dv26[222] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 52.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0,
    32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 51.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0,
    107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0,
    61.0, 34.0, 51.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 52.0, 34.0,
    32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i69;
  int32_T c9_i70;
  int32_T c9_i71;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_e_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i67 = 0; c9_i67 < 222; c9_i67++) {
    c9_mystr[c9_i67] = c9_cv0[c9_i67];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i68 = 0; c9_i68 < 222; c9_i68++) {
    c9_arr[c9_i68] = c9_dv26[c9_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 222.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1778.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i69 = 0; c9_i69 < 2000; c9_i69++) {
    c9_tt[c9_i69] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i70 = 0; c9_i70 < 222; c9_i70++) {
    c9_tt[c9_i70] = c9_arr[c9_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i71 = 0; c9_i71 < 2000; c9_i71++) {
    c9_myarr256[c9_i71] = c9_tt[c9_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_c_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[109];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[109];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i72;
  static char_T c9_cv1[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '5', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-',
    'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i73;
  static real_T c9_dv27[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0,
    34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i74;
  int32_T c9_i75;
  int32_T c9_i76;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_f_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i72 = 0; c9_i72 < 109; c9_i72++) {
    c9_mystr[c9_i72] = c9_cv1[c9_i72];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i73 = 0; c9_i73 < 109; c9_i73++) {
    c9_arr[c9_i73] = c9_dv27[c9_i73];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1891.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i74 = 0; c9_i74 < 2000; c9_i74++) {
    c9_tt[c9_i74] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i75 = 0; c9_i75 < 109; c9_i75++) {
    c9_tt[c9_i75] = c9_arr[c9_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i76 = 0; c9_i76 < 2000; c9_i76++) {
    c9_myarr256[c9_i76] = c9_tt[c9_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_d_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[230];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[230];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i77;
  static char_T c9_cv2[230] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c', 't',
    '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e',
    '=', '\"', '1', '0', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '7', '0',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '0', '\"', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a',
    'u', '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '1', '0', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '7', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '0',
    '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i78;
  static real_T c9_dv28[230] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 55.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 49.0, 48.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0,
    97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0,
    115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0,
    114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 114.0, 101.0,
    108.0, 97.0, 120.0, 61.0, 34.0, 55.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0,
    61.0, 34.0, 49.0, 48.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i79;
  int32_T c9_i80;
  int32_T c9_i81;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_h_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i77 = 0; c9_i77 < 230; c9_i77++) {
    c9_mystr[c9_i77] = c9_cv2[c9_i77];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i78 = 0; c9_i78 < 230; c9_i78++) {
    c9_arr[c9_i78] = c9_dv28[c9_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 230.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1770.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i79 = 0; c9_i79 < 2000; c9_i79++) {
    c9_tt[c9_i79] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i80 = 0; c9_i80 < 230; c9_i80++) {
    c9_tt[c9_i80] = c9_arr[c9_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i81 = 0; c9_i81 < 2000; c9_i81++) {
    c9_myarr256[c9_i81] = c9_tt[c9_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_e_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[106];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[106];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i82;
  static char_T c9_cv3[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c', 't',
    '>', '<', 'b', 'm', 'l', '>', '<', 'h', 'e', 'a', 'd', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '0', '.', '0', '5', '\"', ' ', 'r', 'e', 'p', 'e',
    'a', 't', 's', '=', '\"', '0', '.', '2', '\"', ' ', 'v', 'e', 'l', 'o', 'c',
    'i', 't', 'y', '=', '\"', '0', '.', '3', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'S', 'H', 'A', 'K', 'E', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i83;
  static real_T c9_dv29[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 104.0, 101.0, 97.0, 100.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 48.0, 53.0, 34.0, 32.0, 114.0, 101.0, 112.0,
    101.0, 97.0, 116.0, 115.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 118.0,
    101.0, 108.0, 111.0, 99.0, 105.0, 116.0, 121.0, 61.0, 34.0, 48.0, 46.0, 51.0,
    34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 83.0, 72.0, 65.0, 75.0,
    69.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i84;
  int32_T c9_i85;
  int32_T c9_i86;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_k_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i82 = 0; c9_i82 < 106; c9_i82++) {
    c9_mystr[c9_i82] = c9_cv3[c9_i82];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i83 = 0; c9_i83 < 106; c9_i83++) {
    c9_arr[c9_i83] = c9_dv29[c9_i83];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1894.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i84 = 0; c9_i84 < 2000; c9_i84++) {
    c9_tt[c9_i84] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i85 = 0; c9_i85 < 106; c9_i85++) {
    c9_tt[c9_i85] = c9_arr[c9_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i86 = 0; c9_i86 < 2000; c9_i86++) {
    c9_myarr256[c9_i86] = c9_tt[c9_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_f_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[108];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[108];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i87;
  static char_T c9_cv4[108] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'h', 'e', 'a', 'd', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '0', '5', '\"', ' ', 'r', 'e', 'p',
    'e', 'a', 't', 's', '=', '\"', '0', '.', '0', '5', '\"', ' ', 'v', 'e', 'l',
    'o', 'c', 'i', 't', 'y', '=', '\"', '0', '.', '0', '5', '\"', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'T', 'O', 'S', 'S', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i88;
  static real_T c9_dv30[108] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 104.0, 101.0, 97.0, 100.0, 32.0, 97.0, 109.0, 111.0, 117.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 48.0, 53.0, 34.0, 32.0, 114.0, 101.0,
    112.0, 101.0, 97.0, 116.0, 115.0, 61.0, 34.0, 48.0, 46.0, 48.0, 53.0, 34.0,
    32.0, 118.0, 101.0, 108.0, 111.0, 99.0, 105.0, 116.0, 121.0, 61.0, 34.0,
    48.0, 46.0, 48.0, 53.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    84.0, 79.0, 83.0, 83.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i89;
  int32_T c9_i90;
  int32_T c9_i91;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_l_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i87 = 0; c9_i87 < 108; c9_i87++) {
    c9_mystr[c9_i87] = c9_cv4[c9_i87];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i88 = 0; c9_i88 < 108; c9_i88++) {
    c9_arr[c9_i88] = c9_dv30[c9_i88];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1892.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i89 = 0; c9_i89 < 2000; c9_i89++) {
    c9_tt[c9_i89] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i90 = 0; c9_i90 < 108; c9_i90++) {
    c9_tt[c9_i90] = c9_arr[c9_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i91 = 0; c9_i91 < 2000; c9_i91++) {
    c9_myarr256[c9_i91] = c9_tt[c9_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_g_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[135];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[135];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i92;
  static char_T c9_cv5[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c', 't',
    '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '0', '.', '4', '\"', ' ', 'a', 'u', '=', '\"', '1',
    '0', '4', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"', ' ', 'r', 'e', 'l',
    'a', 'x', '=', '\"', '4', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's',
    't', 'r', 'o', 'k', 'e', '=', '\"', '1', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i93;
  static real_T c9_dv31[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 52.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 48.0, 52.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0,
    32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 52.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0,
    116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0,
    111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i94;
  int32_T c9_i95;
  int32_T c9_i96;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_m_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i92 = 0; c9_i92 < 135; c9_i92++) {
    c9_mystr[c9_i92] = c9_cv5[c9_i92];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i93 = 0; c9_i93 < 135; c9_i93++) {
    c9_arr[c9_i93] = c9_dv31[c9_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1865.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i94 = 0; c9_i94 < 2000; c9_i94++) {
    c9_tt[c9_i94] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i95 = 0; c9_i95 < 135; c9_i95++) {
    c9_tt[c9_i95] = c9_arr[c9_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i96 = 0; c9_i96 < 2000; c9_i96++) {
    c9_myarr256[c9_i96] = c9_tt[c9_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_h_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[135];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[135];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i97;
  static char_T c9_cv6[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c', 't',
    '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=', '\"', '1',
    '0', '2', '\"', ' ', 'e', 'n', 'd', '=', '\"', '3', '\"', ' ', 'r', 'e', 'l',
    'a', 'x', '=', '\"', '2', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's',
    't', 'r', 'o', 'k', 'e', '=', '\"', '1', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i98;
  static real_T c9_dv32[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 48.0, 50.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 51.0, 34.0,
    32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 50.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0,
    116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0,
    111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i99;
  int32_T c9_i100;
  int32_T c9_i101;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_n_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i97 = 0; c9_i97 < 135; c9_i97++) {
    c9_mystr[c9_i97] = c9_cv6[c9_i97];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i98 = 0; c9_i98 < 135; c9_i98++) {
    c9_arr[c9_i98] = c9_dv32[c9_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1865.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i99 = 0; c9_i99 < 2000; c9_i99++) {
    c9_tt[c9_i99] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i100 = 0; c9_i100 < 135; c9_i100++) {
    c9_tt[c9_i100] = c9_arr[c9_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i101 = 0; c9_i101 < 2000; c9_i101++) {
    c9_myarr256[c9_i101] = c9_tt[c9_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_i_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[94];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  char_T c9_mystr[94];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i102;
  static char_T c9_cv7[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c', 't',
    '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 'a', 'u', '=', '\"', '6',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 't',
    'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i103;
  static real_T c9_dv33[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    54.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0,
    115.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i104;
  int32_T c9_i105;
  int32_T c9_i106;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_o_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i102 = 0; c9_i102 < 94; c9_i102++) {
    c9_mystr[c9_i102] = c9_cv7[c9_i102];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i103 = 0; c9_i103 < 94; c9_i103++) {
    c9_arr[c9_i103] = c9_dv33[c9_i103];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 1906.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i104 = 0; c9_i104 < 2000; c9_i104++) {
    c9_tt[c9_i104] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i105 = 0; c9_i105 < 94; c9_i105++) {
    c9_tt[c9_i105] = c9_arr[c9_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i106 = 0; c9_i106 < 2000; c9_i106++) {
    c9_myarr256[c9_i106] = c9_tt[c9_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_cmdBML_AU_VA(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_eAmount[15], real_T c9_arrBML[2000])
{
  uint32_T c9_debug_family_var_map[14];
  real_T c9_L;
  const mxArray *c9_str1 = NULL;
  real_T c9_all_AUs[15];
  real_T c9_c;
  real_T c9_AU;
  real_T c9_eA;
  const mxArray *c9_temp = NULL;
  const mxArray *c9_temp2 = NULL;
  const mxArray *c9_str2 = NULL;
  char_T c9_mystr[1713];
  char_T c9_b_mystr[1610];
  char_T c9_c_mystr[1577];
  char_T c9_d_mystr[1474];
  char_T c9_e_mystr[1171];
  char_T c9_f_mystr[1068];
  char_T c9_g_mystr[965];
  char_T c9_h_mystr[862];
  char_T c9_i_mystr[759];
  char_T c9_j_mystr[656];
  char_T c9_k_mystr[515];
  char_T c9_l_mystr[412];
  char_T c9_m_mystr[306];
  char_T c9_n_mystr[206];
  char_T c9_o_mystr[103];
  int32_T c9_mystr_sizes[2];
  char_T c9_mystr_data[1713];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i107;
  static char_T c9_cv8[34] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>' };

  char_T c9_u[34];
  const mxArray *c9_y = NULL;
  int32_T c9_i108;
  static real_T c9_dv34[15] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 12.0, 26.0, 45.0,
    10.0, 25.0, 102.0, 103.0, 104.0, 105.0 };

  int32_T c9_b_c;
  real_T c9_d0;
  real_T c9_varargin_1;
  real_T c9_varargin_2;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_xk;
  real_T c9_c_x;
  real_T c9_maxval;
  int32_T c9_i109;
  static char_T c9_cv9[124] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e',
    '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=', '\\',
    '\"', '%', '1', 'd', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\', '\"',
    '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"', '4',
    '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6', '\\',
    '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '3', 'f', '\\', '\"',
    '/', '>' };

  char_T c9_b_u[124];
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_d_y = NULL;
  int32_T c9_i110;
  static char_T c9_cv10[123] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '2', 'd', '\\', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\', '\"',
    '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"', '4',
    '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6', '\\',
    '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '3', 'f', '\\', '\"',
    '/', '>' };

  char_T c9_e_u[123];
  const mxArray *c9_e_y = NULL;
  real_T c9_f_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_g_u;
  const mxArray *c9_g_y = NULL;
  int32_T c9_i111;
  static char_T c9_cv11[12] = { '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  char_T c9_h_u[12];
  const mxArray *c9_h_y = NULL;
  int32_T c9_i112;
  int32_T c9_i113;
  int32_T c9_i114;
  int32_T c9_i115;
  int32_T c9_i116;
  int32_T c9_i117;
  int32_T c9_i118;
  int32_T c9_i119;
  int32_T c9_i120;
  int32_T c9_i121;
  int32_T c9_i122;
  int32_T c9_i123;
  int32_T c9_i124;
  int32_T c9_i125;
  int32_T c9_i126;
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[1713];
  int32_T c9_p_mystr;
  int32_T c9_q_mystr;
  int32_T c9_loop_ub;
  int32_T c9_i127;
  int32_T c9_b_mystr_sizes[2];
  int32_T c9_r_mystr;
  int32_T c9_s_mystr;
  int32_T c9_b_loop_ub;
  int32_T c9_i128;
  char_T c9_b_mystr_data[1713];
  real_T c9_dv35[2000];
  int32_T c9_i129;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 29U, c9_w_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_L, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_str1, 1U, c9_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_all_AUs, 2U, c9_m_sf_marshallOut,
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_AU, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_eA, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_temp, 6U, c9_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_temp2, 7U, c9_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_str2, 8U, c9_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_mystr, MAX_uint32_T,
    c9_mb_sf_marshallOut, c9_w_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_mystr, MAX_uint32_T,
    c9_lb_sf_marshallOut, c9_v_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_c_mystr, MAX_uint32_T,
    c9_kb_sf_marshallOut, c9_u_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_d_mystr, MAX_uint32_T,
    c9_jb_sf_marshallOut, c9_t_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_e_mystr, MAX_uint32_T,
    c9_ib_sf_marshallOut, c9_s_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_f_mystr, MAX_uint32_T,
    c9_hb_sf_marshallOut, c9_r_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_g_mystr, MAX_uint32_T,
    c9_gb_sf_marshallOut, c9_q_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_h_mystr, MAX_uint32_T,
    c9_fb_sf_marshallOut, c9_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_i_mystr, MAX_uint32_T,
    c9_eb_sf_marshallOut, c9_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_j_mystr, MAX_uint32_T,
    c9_db_sf_marshallOut, c9_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_k_mystr, MAX_uint32_T,
    c9_cb_sf_marshallOut, c9_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_l_mystr, MAX_uint32_T,
    c9_bb_sf_marshallOut, c9_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_m_mystr, MAX_uint32_T,
    c9_ab_sf_marshallOut, c9_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_n_mystr, MAX_uint32_T,
    c9_y_sf_marshallOut, c9_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_o_mystr, MAX_uint32_T,
    c9_x_sf_marshallOut, c9_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_mystr_data, (const int32_T *)
    &c9_mystr_sizes, NULL, 0, -1, (void *)c9_v_sf_marshallOut, (void *)
    c9_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 10U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 11U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_eAmount, 12U, c9_m_sf_marshallOut,
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_arrBML, 13U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 4);
  c9_L = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 6);
  for (c9_i107 = 0; c9_i107 < 34; c9_i107++) {
    c9_u[c9_i107] = c9_cv8[c9_i107];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 34), false);
  sf_mex_assign(&c9_str1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c9_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 7);
  for (c9_i108 = 0; c9_i108 < 15; c9_i108++) {
    c9_all_AUs[c9_i108] = c9_dv34[c9_i108];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 8);
  c9_c = 1.0;
  c9_b_c = 0;
  while (c9_b_c < 15) {
    c9_c = 1.0 + (real_T)c9_b_c;
    CV_SCRIPT_FOR(1, 0, 1);
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 9);
    c9_AU = c9_all_AUs[(int32_T)c9_c - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 9);
    c9_eA = c9_eAmount[(int32_T)c9_c - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 10);
    if (CV_SCRIPT_IF(1, 0, c9_eA >= 0.1)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 11);
      c9_L++;
      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 13);
      c9_d0 = c9_abs(chartInstance, c9_AU);
      c9_b_log10(chartInstance, &c9_d0);
      c9_varargin_1 = c9_d0;
      c9_b_ceil(chartInstance, &c9_varargin_1);
      c9_varargin_2 = c9_varargin_1;
      c9_x = c9_varargin_2;
      c9_b_x = c9_x;
      c9_eml_scalar_eg(chartInstance);
      c9_xk = c9_b_x;
      c9_c_x = c9_xk;
      c9_eml_scalar_eg(chartInstance);
      c9_maxval = muDoubleScalarMax(c9_c_x, 1.0);
      if (CV_SCRIPT_IF(1, 1, c9_maxval == 1.0)) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 14);
        for (c9_i109 = 0; c9_i109 < 124; c9_i109++) {
          c9_b_u[c9_i109] = c9_cv9[c9_i109];
        }

        c9_b_y = NULL;
        sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1,
          124), false);
        c9_c_u = c9_AU;
        c9_c_y = NULL;
        sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0),
                      false);
        c9_d_u = c9_eA;
        c9_d_y = NULL;
        sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c9_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "sprintf", 1U, 3U, 14, c9_b_y, 14, c9_c_y, 14, c9_d_y), false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 15);
        sf_mex_assign(&c9_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "strcat", 1U, 2U, 14, sf_mex_dup(c9_str1), 14, sf_mex_dup(c9_temp)),
                      false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 16);
        sf_mex_assign(&c9_str1, sf_mex_dup(c9_temp2), false);
      } else {
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 18);
        for (c9_i110 = 0; c9_i110 < 123; c9_i110++) {
          c9_e_u[c9_i110] = c9_cv10[c9_i110];
        }

        c9_e_y = NULL;
        sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_e_u, 10, 0U, 1U, 0U, 2, 1,
          123), false);
        c9_f_u = c9_AU;
        c9_f_y = NULL;
        sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0),
                      false);
        c9_g_u = c9_eA;
        c9_g_y = NULL;
        sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_g_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c9_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "sprintf", 1U, 3U, 14, c9_e_y, 14, c9_f_y, 14, c9_g_y), false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 19);
        sf_mex_assign(&c9_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "strcat", 1U, 2U, 14, sf_mex_dup(c9_str1), 14, sf_mex_dup(c9_temp)),
                      false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 20);
        sf_mex_assign(&c9_str1, sf_mex_dup(c9_temp2), false);
      }
    }

    c9_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(1, 0, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 24);
  for (c9_i111 = 0; c9_i111 < 12; c9_i111++) {
    c9_h_u[c9_i111] = c9_cv11[c9_i111];
  }

  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_h_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_assign(&c9_str2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c9_h_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 26);
  if (CV_SCRIPT_IF(1, 2, c9_L == 1.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 27);
    c9_blanks(chartInstance);
    for (c9_i112 = 0; c9_i112 < 103; c9_i112++) {
      c9_o_mystr[c9_i112] = ' ';
    }

    _SFD_SYMBOL_SWITCH(9U, 23U);
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 28);
    if (CV_SCRIPT_IF(1, 3, c9_L == 2.0)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 29);
      c9_b_blanks(chartInstance);
      for (c9_i113 = 0; c9_i113 < 206; c9_i113++) {
        c9_n_mystr[c9_i113] = ' ';
      }

      _SFD_SYMBOL_SWITCH(9U, 22U);
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 30);
      if (CV_SCRIPT_IF(1, 4, c9_L == 3.0)) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 31);
        c9_c_blanks(chartInstance);
        for (c9_i114 = 0; c9_i114 < 306; c9_i114++) {
          c9_m_mystr[c9_i114] = ' ';
        }

        _SFD_SYMBOL_SWITCH(9U, 21U);
      } else {
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 32);
        if (CV_SCRIPT_IF(1, 5, c9_L == 4.0)) {
          _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 33);
          c9_d_blanks(chartInstance);
          for (c9_i115 = 0; c9_i115 < 412; c9_i115++) {
            c9_l_mystr[c9_i115] = ' ';
          }

          _SFD_SYMBOL_SWITCH(9U, 20U);
        } else {
          _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 34);
          if (CV_SCRIPT_IF(1, 6, c9_L == 5.0)) {
            _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 35);
            c9_e_blanks(chartInstance);
            for (c9_i116 = 0; c9_i116 < 515; c9_i116++) {
              c9_k_mystr[c9_i116] = ' ';
            }

            _SFD_SYMBOL_SWITCH(9U, 19U);
          } else {
            _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 36);
            if (CV_SCRIPT_IF(1, 7, c9_L == 6.0)) {
              _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 37);
              c9_f_blanks(chartInstance);
              for (c9_i117 = 0; c9_i117 < 656; c9_i117++) {
                c9_j_mystr[c9_i117] = ' ';
              }

              _SFD_SYMBOL_SWITCH(9U, 18U);
            } else {
              _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 38);
              if (CV_SCRIPT_IF(1, 8, c9_L == 7.0)) {
                _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 39);
                c9_g_blanks(chartInstance);
                for (c9_i118 = 0; c9_i118 < 759; c9_i118++) {
                  c9_i_mystr[c9_i118] = ' ';
                }

                _SFD_SYMBOL_SWITCH(9U, 17U);
              } else {
                _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 40);
                if (CV_SCRIPT_IF(1, 9, c9_L == 8.0)) {
                  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 41);
                  c9_h_blanks(chartInstance);
                  for (c9_i119 = 0; c9_i119 < 862; c9_i119++) {
                    c9_h_mystr[c9_i119] = ' ';
                  }

                  _SFD_SYMBOL_SWITCH(9U, 16U);
                } else {
                  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 42);
                  if (CV_SCRIPT_IF(1, 10, c9_L == 9.0)) {
                    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 43);
                    c9_i_blanks(chartInstance);
                    for (c9_i120 = 0; c9_i120 < 965; c9_i120++) {
                      c9_g_mystr[c9_i120] = ' ';
                    }

                    _SFD_SYMBOL_SWITCH(9U, 15U);
                  } else {
                    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 44);
                    if (CV_SCRIPT_IF(1, 11, c9_L == 10.0)) {
                      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 45);
                      c9_j_blanks(chartInstance);
                      for (c9_i121 = 0; c9_i121 < 1068; c9_i121++) {
                        c9_f_mystr[c9_i121] = ' ';
                      }

                      _SFD_SYMBOL_SWITCH(9U, 14U);
                    } else {
                      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 46);
                      if (CV_SCRIPT_IF(1, 12, c9_L == 11.0)) {
                        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 47);
                        c9_k_blanks(chartInstance);
                        for (c9_i122 = 0; c9_i122 < 1171; c9_i122++) {
                          c9_e_mystr[c9_i122] = ' ';
                        }

                        _SFD_SYMBOL_SWITCH(9U, 13U);
                      } else {
                        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 48);
                        if (CV_SCRIPT_IF(1, 13, c9_L == 12.0)) {
                          _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 49);
                          c9_l_blanks(chartInstance);
                          for (c9_i123 = 0; c9_i123 < 1474; c9_i123++) {
                            c9_d_mystr[c9_i123] = ' ';
                          }

                          _SFD_SYMBOL_SWITCH(9U, 12U);
                        } else {
                          _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 50);
                          if (CV_SCRIPT_IF(1, 14, c9_L == 13.0)) {
                            _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 51);
                            c9_m_blanks(chartInstance);
                            for (c9_i124 = 0; c9_i124 < 1577; c9_i124++) {
                              c9_c_mystr[c9_i124] = ' ';
                            }

                            _SFD_SYMBOL_SWITCH(9U, 11U);
                          } else {
                            _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 52);
                            if (CV_SCRIPT_IF(1, 15, c9_L == 14.0)) {
                              _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 53);
                              c9_n_blanks(chartInstance);
                              for (c9_i125 = 0; c9_i125 < 1610; c9_i125++) {
                                c9_b_mystr[c9_i125] = ' ';
                              }

                              _SFD_SYMBOL_SWITCH(9U, 10U);
                            } else {
                              _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 54);
                              if (CV_SCRIPT_IF(1, 16, c9_L == 15.0)) {
                                _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent,
                                                 55);
                                c9_o_blanks(chartInstance);
                                for (c9_i126 = 0; c9_i126 < 1713; c9_i126++) {
                                  c9_mystr[c9_i126] = ' ';
                                }

                                _SFD_SYMBOL_SWITCH(9U, 9U);
                              } else {
                                _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent,
                                                 57);
                                c9_fprintf(chartInstance, c9_L);
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

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 59);
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "strcat", 1U, 2U, 14,
    sf_mex_dup(c9_str1), 14, sf_mex_dup(c9_str2)), "strcat", c9_tmp_data,
                        c9_tmp_sizes);
  c9_mystr_sizes[0] = 1;
  c9_mystr_sizes[1] = c9_tmp_sizes[1];
  c9_p_mystr = c9_mystr_sizes[0];
  c9_q_mystr = c9_mystr_sizes[1];
  c9_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i127 = 0; c9_i127 <= c9_loop_ub; c9_i127++) {
    c9_mystr_data[c9_i127] = c9_tmp_data[c9_i127];
  }

  _SFD_SYMBOL_SWITCH(9U, 24U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 60);
  c9_b_mystr_sizes[0] = 1;
  c9_b_mystr_sizes[1] = c9_mystr_sizes[1];
  c9_r_mystr = c9_b_mystr_sizes[0];
  c9_s_mystr = c9_b_mystr_sizes[1];
  c9_b_loop_ub = c9_mystr_sizes[0] * c9_mystr_sizes[1] - 1;
  for (c9_i128 = 0; c9_i128 <= c9_b_loop_ub; c9_i128++) {
    c9_b_mystr_data[c9_i128] = c9_mystr_data[c9_i128];
  }

  c9_j_encStr2Arr(chartInstance, c9_b_mystr_data, c9_b_mystr_sizes, c9_dv35);
  for (c9_i129 = 0; c9_i129 < 2000; c9_i129++) {
    c9_arrBML[c9_i129] = c9_dv35[c9_i129];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, -60);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c9_str1);
  sf_mex_destroy(&c9_temp);
  sf_mex_destroy(&c9_temp2);
  sf_mex_destroy(&c9_str2);
}

static real_T c9_abs(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
                     c9_x)
{
  real_T c9_b_x;
  (void)chartInstance;
  c9_b_x = c9_x;
  return c9_b_x;
}

static real_T c9_log10(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
  c9_x)
{
  real_T c9_b_x;
  c9_b_x = c9_x;
  c9_b_log10(chartInstance, &c9_b_x);
  return c9_b_x;
}

static real_T c9_ceil(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
                      c9_x)
{
  real_T c9_b_x;
  c9_b_x = c9_x;
  c9_b_ceil(chartInstance, &c9_b_x);
  return c9_b_x;
}

static void c9_eml_scalar_eg(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_b_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_c_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_d_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_e_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_f_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_g_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_h_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_i_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_j_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_k_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_l_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_m_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_n_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_o_blanks(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_fprintf(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
  c9_formatSpec)
{
  c9_isequal(chartInstance);
  c9_b_fprintf(chartInstance, c9_formatSpec);
}

static void c9_isequal(SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c9_b_fprintf(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_varargin_1)
{
  real_T c9_nbytes;
  int32_T c9_i130;
  static char_T c9_cv12[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c9_u[7];
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  int32_T c9_i131;
  static char_T c9_formatSpec[12] = { ' ', ',', 'L', ':', ' ', '%', '0', '.',
    '0', 'f', '\\', 'r' };

  char_T c9_c_u[12];
  const mxArray *c9_c_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_cfmt = NULL;
  const mxArray *c9_convs = NULL;
  c9_isequal(chartInstance);
  for (c9_i130 = 0; c9_i130 < 7; c9_i130++) {
    c9_u[c9_i130] = c9_cv12[c9_i130];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c9_b_u = 1.0;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c9_i131 = 0; c9_i131 < 12; c9_i131++) {
    c9_c_u[c9_i131] = c9_formatSpec[c9_i131];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_c_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  c9_d_u = c9_varargin_1;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  c9_nbytes = c9_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14, c9_y, 14, c9_b_y, 14,
     c9_c_y, 14, c9_d_y), "feval");
  sf_mex_destroy(&c9_cfmt);
  sf_mex_destroy(&c9_convs);
  return c9_nbytes;
}

static void c9_j_encStr2Arr(SFc9_Expriment_AllInstanceStruct *chartInstance,
  char_T c9_mystr_data[], int32_T c9_mystr_sizes[2], real_T c9_myarr256[2000])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  int32_T c9_arr_sizes;
  real_T c9_arr_data[1713];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[2000];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_loop_ub;
  int32_T c9_i132;
  int32_T c9_i133;
  boolean_T c9_b0;
  boolean_T c9_b1;
  boolean_T c9_b2;
  int32_T c9_i134;
  int32_T c9_tmp_sizes;
  int32_T c9_b_loop_ub;
  int32_T c9_i135;
  int32_T c9_tmp_data[1713];
  int32_T c9_iv0[1];
  int32_T c9_c_loop_ub;
  int32_T c9_i136;
  int32_T c9_i137;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_v_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_arr_data, (const int32_T *)
    &c9_arr_sizes, NULL, 0, 1, (void *)c9_w_sf_marshallOut, (void *)
    c9_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ss, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_mystr_data, (const int32_T *)
    c9_mystr_sizes, NULL, 1, 7, (void *)c9_v_sf_marshallOut, (void *)
    c9_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 2000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_arr_sizes = c9_mystr_sizes[1];
  c9_loop_ub = c9_mystr_sizes[1] - 1;
  for (c9_i132 = 0; c9_i132 <= c9_loop_ub; c9_i132++) {
    c9_arr_data[c9_i132] = (real_T)c9_mystr_data[c9_mystr_sizes[0] * c9_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = (real_T)c9_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 2000.0 - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i133 = 0; c9_i133 < 2000; c9_i133++) {
    c9_tt[c9_i133] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_b0 = (1.0 > c9_ss);
  c9_b1 = c9_b0;
  c9_b2 = c9_b1;
  if (c9_b2) {
    c9_i134 = 0;
  } else {
    c9_i134 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c9_ss, 1, 2000, 0, 0);
  }

  c9_tmp_sizes = c9_i134;
  c9_b_loop_ub = c9_i134 - 1;
  for (c9_i135 = 0; c9_i135 <= c9_b_loop_ub; c9_i135++) {
    c9_tmp_data[c9_i135] = c9_i135;
  }

  c9_iv0[0] = c9_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c9_iv0, 1, *(int32_T (*)[1])&c9_arr_sizes, 1);
  c9_c_loop_ub = c9_arr_sizes - 1;
  for (c9_i136 = 0; c9_i136 <= c9_c_loop_ub; c9_i136++) {
    c9_tt[c9_tmp_data[c9_i136]] = c9_arr_data[c9_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i137 = 0; c9_i137 < 2000; c9_i137++) {
    c9_myarr256[c9_i137] = c9_tt[c9_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\15-1-2016-Matlab\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\15-1-2016-Matlab\\cmdBML_AU_VA.m"));
}

static real_T c9_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_feval, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_feval), &c9_thisId);
  sf_mex_destroy(&c9_feval);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d1;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d1, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_strcat, const char_T *c9_identifier, char_T
  c9_y_data[], int32_T c9_y_sizes[2])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_strcat), &c9_thisId,
                        c9_y_data, c9_y_sizes);
  sf_mex_destroy(&c9_strcat);
}

static void c9_d_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2])
{
  int32_T c9_i138;
  uint32_T c9_uv0[2];
  int32_T c9_i139;
  static boolean_T c9_bv0[2] = { false, true };

  boolean_T c9_bv1[2];
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[1713];
  int32_T c9_y;
  int32_T c9_b_y;
  int32_T c9_loop_ub;
  int32_T c9_i140;
  (void)chartInstance;
  for (c9_i138 = 0; c9_i138 < 2; c9_i138++) {
    c9_uv0[c9_i138] = 1U + 1712U * (uint32_T)c9_i138;
  }

  for (c9_i139 = 0; c9_i139 < 2; c9_i139++) {
    c9_bv1[c9_i139] = c9_bv0[c9_i139];
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c9_bv1, c9_uv0, c9_tmp_sizes);
  c9_y_sizes[0] = 1;
  c9_y_sizes[1] = c9_tmp_sizes[1];
  c9_y = c9_y_sizes[0];
  c9_b_y = c9_y_sizes[1];
  c9_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i140 = 0; c9_i140 <= c9_loop_ub; c9_i140++) {
    c9_y_data[c9_i140] = c9_tmp_data[c9_i140];
  }

  sf_mex_destroy(&c9_u);
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i141;
  int32_T c9_i142;
  int32_T c9_i143;
  real_T c9_b_inData[10000];
  int32_T c9_i144;
  int32_T c9_i145;
  int32_T c9_i146;
  real_T c9_u[10000];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i141 = 0;
  for (c9_i142 = 0; c9_i142 < 5; c9_i142++) {
    for (c9_i143 = 0; c9_i143 < 2000; c9_i143++) {
      c9_b_inData[c9_i143 + c9_i141] = (*(real_T (*)[10000])c9_inData)[c9_i143 +
        c9_i141];
    }

    c9_i141 += 2000;
  }

  c9_i144 = 0;
  for (c9_i145 = 0; c9_i145 < 5; c9_i145++) {
    for (c9_i146 = 0; c9_i146 < 2000; c9_i146++) {
      c9_u[c9_i146 + c9_i144] = c9_b_inData[c9_i146 + c9_i144];
    }

    c9_i144 += 2000;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 2000, 5),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_newBmls, const char_T *c9_identifier, real_T
  c9_y[10000])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_newBmls), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_newBmls);
}

static void c9_f_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[10000])
{
  real_T c9_dv36[10000];
  int32_T c9_i147;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv36, 1, 0, 0U, 1, 0U, 2, 2000,
                5);
  for (c9_i147 = 0; c9_i147 < 10000; c9_i147++) {
    c9_y[c9_i147] = c9_dv36[c9_i147];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_newBmls;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[10000];
  int32_T c9_i148;
  int32_T c9_i149;
  int32_T c9_i150;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_newBmls = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_newBmls), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_newBmls);
  c9_i148 = 0;
  for (c9_i149 = 0; c9_i149 < 5; c9_i149++) {
    for (c9_i150 = 0; c9_i150 < 2000; c9_i150++) {
      (*(real_T (*)[10000])c9_outData)[c9_i150 + c9_i148] = c9_y[c9_i150 +
        c9_i148];
    }

    c9_i148 += 2000;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i151;
  real_T c9_b_inData[2000];
  int32_T c9_i152;
  real_T c9_u[2000];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i151 = 0; c9_i151 < 2000; c9_i151++) {
    c9_b_inData[c9_i151] = (*(real_T (*)[2000])c9_inData)[c9_i151];
  }

  for (c9_i152 = 0; c9_i152 < 2000; c9_i152++) {
    c9_u[c9_i152] = c9_b_inData[c9_i152];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 2000, 1),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_g_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_myBML, const char_T *c9_identifier, real_T
  c9_y[2000])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myBML), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myBML);
}

static void c9_h_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2000])
{
  real_T c9_dv37[2000];
  int32_T c9_i153;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv37, 1, 0, 0U, 1, 0U, 2, 2000,
                1);
  for (c9_i153 = 0; c9_i153 < 2000; c9_i153++) {
    c9_y[c9_i153] = c9_dv37[c9_i153];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_myBML;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[2000];
  int32_T c9_i154;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_myBML = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myBML), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myBML);
  for (c9_i154 = 0; c9_i154 < 2000; c9_i154++) {
    (*(real_T (*)[2000])c9_outData)[c9_i154] = c9_y[c9_i154];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_feval;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_feval = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_feval), &c9_thisId);
  sf_mex_destroy(&c9_feval);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i155;
  real_T c9_b_inData[2000];
  int32_T c9_i156;
  real_T c9_u[2000];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i155 = 0; c9_i155 < 2000; c9_i155++) {
    c9_b_inData[c9_i155] = (*(real_T (*)[2000])c9_inData)[c9_i155];
  }

  for (c9_i156 = 0; c9_i156 < 2000; c9_i156++) {
    c9_u[c9_i156] = c9_b_inData[c9_i156];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 2000), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_i_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_myarr256, const char_T *c9_identifier,
  real_T c9_y[2000])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myarr256), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myarr256);
}

static void c9_j_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2000])
{
  real_T c9_dv38[2000];
  int32_T c9_i157;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv38, 1, 0, 0U, 1, 0U, 1, 2000);
  for (c9_i157 = 0; c9_i157 < 2000; c9_i157++) {
    c9_y[c9_i157] = c9_dv38[c9_i157];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_myarr256;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[2000];
  int32_T c9_i158;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_myarr256 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myarr256), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myarr256);
  for (c9_i158 = 0; c9_i158 < 2000; c9_i158++) {
    (*(real_T (*)[2000])c9_outData)[c9_i158] = c9_y[c9_i158];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  char_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(char_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  boolean_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_k_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_y;
  boolean_T c9_b3;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b3, 1, 11, 0U, 0, 0U, 0);
  c9_y = c9_b3;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_aVarTruthTableCondition_2;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_aVarTruthTableCondition_2 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_aVarTruthTableCondition_2), &c9_thisId);
  sf_mex_destroy(&c9_aVarTruthTableCondition_2);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i159;
  char_T c9_b_inData[222];
  int32_T c9_i160;
  char_T c9_u[222];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i159 = 0; c9_i159 < 222; c9_i159++) {
    c9_b_inData[c9_i159] = (*(char_T (*)[222])c9_inData)[c9_i159];
  }

  for (c9_i160 = 0; c9_i160 < 222; c9_i160++) {
    c9_u[c9_i160] = c9_b_inData[c9_i160];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 222),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i161;
  real_T c9_b_inData[222];
  int32_T c9_i162;
  real_T c9_u[222];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i161 = 0; c9_i161 < 222; c9_i161++) {
    c9_b_inData[c9_i161] = (*(real_T (*)[222])c9_inData)[c9_i161];
  }

  for (c9_i162 = 0; c9_i162 < 222; c9_i162++) {
    c9_u[c9_i162] = c9_b_inData[c9_i162];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 222), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i163;
  char_T c9_b_inData[109];
  int32_T c9_i164;
  char_T c9_u[109];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i163 = 0; c9_i163 < 109; c9_i163++) {
    c9_b_inData[c9_i163] = (*(char_T (*)[109])c9_inData)[c9_i163];
  }

  for (c9_i164 = 0; c9_i164 < 109; c9_i164++) {
    c9_u[c9_i164] = c9_b_inData[c9_i164];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i165;
  real_T c9_b_inData[109];
  int32_T c9_i166;
  real_T c9_u[109];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i165 = 0; c9_i165 < 109; c9_i165++) {
    c9_b_inData[c9_i165] = (*(real_T (*)[109])c9_inData)[c9_i165];
  }

  for (c9_i166 = 0; c9_i166 < 109; c9_i166++) {
    c9_u[c9_i166] = c9_b_inData[c9_i166];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i167;
  char_T c9_b_inData[230];
  int32_T c9_i168;
  char_T c9_u[230];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i167 = 0; c9_i167 < 230; c9_i167++) {
    c9_b_inData[c9_i167] = (*(char_T (*)[230])c9_inData)[c9_i167];
  }

  for (c9_i168 = 0; c9_i168 < 230; c9_i168++) {
    c9_u[c9_i168] = c9_b_inData[c9_i168];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 230),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i169;
  real_T c9_b_inData[230];
  int32_T c9_i170;
  real_T c9_u[230];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i169 = 0; c9_i169 < 230; c9_i169++) {
    c9_b_inData[c9_i169] = (*(real_T (*)[230])c9_inData)[c9_i169];
  }

  for (c9_i170 = 0; c9_i170 < 230; c9_i170++) {
    c9_u[c9_i170] = c9_b_inData[c9_i170];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 230), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i171;
  real_T c9_b_inData[15];
  int32_T c9_i172;
  real_T c9_u[15];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i171 = 0; c9_i171 < 15; c9_i171++) {
    c9_b_inData[c9_i171] = (*(real_T (*)[15])c9_inData)[c9_i171];
  }

  for (c9_i172 = 0; c9_i172 < 15; c9_i172++) {
    c9_u[c9_i172] = c9_b_inData[c9_i172];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 15), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_l_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[15])
{
  real_T c9_dv39[15];
  int32_T c9_i173;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv39, 1, 0, 0U, 1, 0U, 2, 1,
                15);
  for (c9_i173 = 0; c9_i173 < 15; c9_i173++) {
    c9_y[c9_i173] = c9_dv39[c9_i173];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_eAmountFactor;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[15];
  int32_T c9_i174;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_eAmountFactor = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_eAmountFactor), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_eAmountFactor);
  for (c9_i174 = 0; c9_i174 < 15; c9_i174++) {
    (*(real_T (*)[15])c9_outData)[c9_i174] = c9_y[c9_i174];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i175;
  char_T c9_b_inData[106];
  int32_T c9_i176;
  char_T c9_u[106];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i175 = 0; c9_i175 < 106; c9_i175++) {
    c9_b_inData[c9_i175] = (*(char_T (*)[106])c9_inData)[c9_i175];
  }

  for (c9_i176 = 0; c9_i176 < 106; c9_i176++) {
    c9_u[c9_i176] = c9_b_inData[c9_i176];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 106),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_o_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i177;
  real_T c9_b_inData[106];
  int32_T c9_i178;
  real_T c9_u[106];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i177 = 0; c9_i177 < 106; c9_i177++) {
    c9_b_inData[c9_i177] = (*(real_T (*)[106])c9_inData)[c9_i177];
  }

  for (c9_i178 = 0; c9_i178 < 106; c9_i178++) {
    c9_u[c9_i178] = c9_b_inData[c9_i178];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 106), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_p_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i179;
  char_T c9_b_inData[108];
  int32_T c9_i180;
  char_T c9_u[108];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i179 = 0; c9_i179 < 108; c9_i179++) {
    c9_b_inData[c9_i179] = (*(char_T (*)[108])c9_inData)[c9_i179];
  }

  for (c9_i180 = 0; c9_i180 < 108; c9_i180++) {
    c9_u[c9_i180] = c9_b_inData[c9_i180];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 108),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_q_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i181;
  real_T c9_b_inData[108];
  int32_T c9_i182;
  real_T c9_u[108];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i181 = 0; c9_i181 < 108; c9_i181++) {
    c9_b_inData[c9_i181] = (*(real_T (*)[108])c9_inData)[c9_i181];
  }

  for (c9_i182 = 0; c9_i182 < 108; c9_i182++) {
    c9_u[c9_i182] = c9_b_inData[c9_i182];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 108), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_r_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i183;
  char_T c9_b_inData[135];
  int32_T c9_i184;
  char_T c9_u[135];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i183 = 0; c9_i183 < 135; c9_i183++) {
    c9_b_inData[c9_i183] = (*(char_T (*)[135])c9_inData)[c9_i183];
  }

  for (c9_i184 = 0; c9_i184 < 135; c9_i184++) {
    c9_u[c9_i184] = c9_b_inData[c9_i184];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_s_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i185;
  real_T c9_b_inData[135];
  int32_T c9_i186;
  real_T c9_u[135];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i185 = 0; c9_i185 < 135; c9_i185++) {
    c9_b_inData[c9_i185] = (*(real_T (*)[135])c9_inData)[c9_i185];
  }

  for (c9_i186 = 0; c9_i186 < 135; c9_i186++) {
    c9_u[c9_i186] = c9_b_inData[c9_i186];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_t_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i187;
  char_T c9_b_inData[94];
  int32_T c9_i188;
  char_T c9_u[94];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i187 = 0; c9_i187 < 94; c9_i187++) {
    c9_b_inData[c9_i187] = (*(char_T (*)[94])c9_inData)[c9_i187];
  }

  for (c9_i188 = 0; c9_i188 < 94; c9_i188++) {
    c9_u[c9_i188] = c9_b_inData[c9_i188];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_u_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i189;
  real_T c9_b_inData[94];
  int32_T c9_i190;
  real_T c9_u[94];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i189 = 0; c9_i189 < 94; c9_i189++) {
    c9_b_inData[c9_i189] = (*(real_T (*)[94])c9_inData)[c9_i189];
  }

  for (c9_i190 = 0; c9_i190 < 94; c9_i190++) {
    c9_u[c9_i190] = c9_b_inData[c9_i190];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_v_sf_marshallOut(void *chartInstanceVoid, char_T
  c9_inData_data[], int32_T c9_inData_sizes[2])
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_b_inData_sizes[2];
  int32_T c9_loop_ub;
  int32_T c9_i191;
  char_T c9_b_inData_data[1713];
  int32_T c9_u_sizes[2];
  int32_T c9_b_loop_ub;
  int32_T c9_i192;
  char_T c9_u_data[1713];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_b_inData_sizes[0] = 1;
  c9_b_inData_sizes[1] = c9_inData_sizes[1];
  c9_loop_ub = c9_inData_sizes[1] - 1;
  for (c9_i191 = 0; c9_i191 <= c9_loop_ub; c9_i191++) {
    c9_b_inData_data[c9_b_inData_sizes[0] * c9_i191] =
      c9_inData_data[c9_inData_sizes[0] * c9_i191];
  }

  c9_u_sizes[0] = 1;
  c9_u_sizes[1] = c9_b_inData_sizes[1];
  c9_b_loop_ub = c9_b_inData_sizes[1] - 1;
  for (c9_i192 = 0; c9_i192 <= c9_b_loop_ub; c9_i192++) {
    c9_u_data[c9_u_sizes[0] * c9_i192] = c9_b_inData_data[c9_b_inData_sizes[0] *
      c9_i192];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u_data, 10, 0U, 1U, 0U, 2,
    c9_u_sizes[0], c9_u_sizes[1]), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_m_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2])
{
  int32_T c9_i193;
  uint32_T c9_uv1[2];
  int32_T c9_i194;
  static boolean_T c9_bv2[2] = { false, true };

  boolean_T c9_bv3[2];
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[1713];
  int32_T c9_y;
  int32_T c9_b_y;
  int32_T c9_loop_ub;
  int32_T c9_i195;
  (void)chartInstance;
  for (c9_i193 = 0; c9_i193 < 2; c9_i193++) {
    c9_uv1[c9_i193] = 1U + 1712U * (uint32_T)c9_i193;
  }

  for (c9_i194 = 0; c9_i194 < 2; c9_i194++) {
    c9_bv3[c9_i194] = c9_bv2[c9_i194];
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c9_bv3, c9_uv1, c9_tmp_sizes);
  c9_y_sizes[0] = 1;
  c9_y_sizes[1] = c9_tmp_sizes[1];
  c9_y = c9_y_sizes[0];
  c9_b_y = c9_y_sizes[1];
  c9_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i195 = 0; c9_i195 <= c9_loop_ub; c9_i195++) {
    c9_y_data[c9_i195] = c9_tmp_data[c9_i195];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, char_T c9_outData_data[], int32_T
  c9_outData_sizes[2])
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y_sizes[2];
  char_T c9_y_data[1713];
  int32_T c9_loop_ub;
  int32_T c9_i196;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId,
                        c9_y_data, c9_y_sizes);
  sf_mex_destroy(&c9_mystr);
  c9_outData_sizes[0] = 1;
  c9_outData_sizes[1] = c9_y_sizes[1];
  c9_loop_ub = c9_y_sizes[1] - 1;
  for (c9_i196 = 0; c9_i196 <= c9_loop_ub; c9_i196++) {
    c9_outData_data[c9_outData_sizes[0] * c9_i196] = c9_y_data[c9_y_sizes[0] *
      c9_i196];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_w_sf_marshallOut(void *chartInstanceVoid, real_T
  c9_inData_data[], int32_T *c9_inData_sizes)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_b_inData_sizes;
  int32_T c9_loop_ub;
  int32_T c9_i197;
  real_T c9_b_inData_data[1713];
  int32_T c9_u_sizes;
  int32_T c9_b_loop_ub;
  int32_T c9_i198;
  real_T c9_u_data[1713];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_b_inData_sizes = *c9_inData_sizes;
  c9_loop_ub = *c9_inData_sizes - 1;
  for (c9_i197 = 0; c9_i197 <= c9_loop_ub; c9_i197++) {
    c9_b_inData_data[c9_i197] = c9_inData_data[c9_i197];
  }

  c9_u_sizes = c9_b_inData_sizes;
  c9_b_loop_ub = c9_b_inData_sizes - 1;
  for (c9_i198 = 0; c9_i198 <= c9_b_loop_ub; c9_i198++) {
    c9_u_data[c9_i198] = c9_b_inData_data[c9_i198];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u_data, 0, 0U, 1U, 0U, 1,
    c9_u_sizes), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_n_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y_data[], int32_T *c9_y_sizes)
{
  static uint32_T c9_uv2[1] = { 1713U };

  uint32_T c9_uv3[1];
  static boolean_T c9_bv4[1] = { true };

  boolean_T c9_bv5[1];
  int32_T c9_tmp_sizes;
  real_T c9_tmp_data[1713];
  int32_T c9_loop_ub;
  int32_T c9_i199;
  (void)chartInstance;
  c9_uv3[0] = c9_uv2[0];
  c9_bv5[0] = c9_bv4[0];
  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c9_bv5, c9_uv3, &c9_tmp_sizes);
  *c9_y_sizes = c9_tmp_sizes;
  c9_loop_ub = c9_tmp_sizes - 1;
  for (c9_i199 = 0; c9_i199 <= c9_loop_ub; c9_i199++) {
    c9_y_data[c9_i199] = c9_tmp_data[c9_i199];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, real_T c9_outData_data[], int32_T
  *c9_outData_sizes)
{
  const mxArray *c9_arr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y_sizes;
  real_T c9_y_data[1713];
  int32_T c9_loop_ub;
  int32_T c9_i200;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_arr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_arr), &c9_thisId, c9_y_data,
                        &c9_y_sizes);
  sf_mex_destroy(&c9_arr);
  *c9_outData_sizes = c9_y_sizes;
  c9_loop_ub = c9_y_sizes - 1;
  for (c9_i200 = 0; c9_i200 <= c9_loop_ub; c9_i200++) {
    c9_outData_data[c9_i200] = c9_y_data[c9_i200];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_x_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i201;
  char_T c9_b_inData[103];
  int32_T c9_i202;
  char_T c9_u[103];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i201 = 0; c9_i201 < 103; c9_i201++) {
    c9_b_inData[c9_i201] = (*(char_T (*)[103])c9_inData)[c9_i201];
  }

  for (c9_i202 = 0; c9_i202 < 103; c9_i202++) {
    c9_u[c9_i202] = c9_b_inData[c9_i202];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_o_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[103])
{
  char_T c9_cv13[103];
  int32_T c9_i203;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv13, 1, 10, 0U, 1, 0U, 2, 1,
                103);
  for (c9_i203 = 0; c9_i203 < 103; c9_i203++) {
    c9_y[c9_i203] = c9_cv13[c9_i203];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[103];
  int32_T c9_i204;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i204 = 0; c9_i204 < 103; c9_i204++) {
    (*(char_T (*)[103])c9_outData)[c9_i204] = c9_y[c9_i204];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_y_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i205;
  char_T c9_b_inData[206];
  int32_T c9_i206;
  char_T c9_u[206];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i205 = 0; c9_i205 < 206; c9_i205++) {
    c9_b_inData[c9_i205] = (*(char_T (*)[206])c9_inData)[c9_i205];
  }

  for (c9_i206 = 0; c9_i206 < 206; c9_i206++) {
    c9_u[c9_i206] = c9_b_inData[c9_i206];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 206),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_p_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[206])
{
  char_T c9_cv14[206];
  int32_T c9_i207;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv14, 1, 10, 0U, 1, 0U, 2, 1,
                206);
  for (c9_i207 = 0; c9_i207 < 206; c9_i207++) {
    c9_y[c9_i207] = c9_cv14[c9_i207];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[206];
  int32_T c9_i208;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i208 = 0; c9_i208 < 206; c9_i208++) {
    (*(char_T (*)[206])c9_outData)[c9_i208] = c9_y[c9_i208];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i209;
  char_T c9_b_inData[306];
  int32_T c9_i210;
  char_T c9_u[306];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i209 = 0; c9_i209 < 306; c9_i209++) {
    c9_b_inData[c9_i209] = (*(char_T (*)[306])c9_inData)[c9_i209];
  }

  for (c9_i210 = 0; c9_i210 < 306; c9_i210++) {
    c9_u[c9_i210] = c9_b_inData[c9_i210];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 306),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_q_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[306])
{
  char_T c9_cv15[306];
  int32_T c9_i211;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv15, 1, 10, 0U, 1, 0U, 2, 1,
                306);
  for (c9_i211 = 0; c9_i211 < 306; c9_i211++) {
    c9_y[c9_i211] = c9_cv15[c9_i211];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[306];
  int32_T c9_i212;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i212 = 0; c9_i212 < 306; c9_i212++) {
    (*(char_T (*)[306])c9_outData)[c9_i212] = c9_y[c9_i212];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i213;
  char_T c9_b_inData[412];
  int32_T c9_i214;
  char_T c9_u[412];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i213 = 0; c9_i213 < 412; c9_i213++) {
    c9_b_inData[c9_i213] = (*(char_T (*)[412])c9_inData)[c9_i213];
  }

  for (c9_i214 = 0; c9_i214 < 412; c9_i214++) {
    c9_u[c9_i214] = c9_b_inData[c9_i214];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 412),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_r_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[412])
{
  char_T c9_cv16[412];
  int32_T c9_i215;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv16, 1, 10, 0U, 1, 0U, 2, 1,
                412);
  for (c9_i215 = 0; c9_i215 < 412; c9_i215++) {
    c9_y[c9_i215] = c9_cv16[c9_i215];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[412];
  int32_T c9_i216;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i216 = 0; c9_i216 < 412; c9_i216++) {
    (*(char_T (*)[412])c9_outData)[c9_i216] = c9_y[c9_i216];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i217;
  char_T c9_b_inData[515];
  int32_T c9_i218;
  char_T c9_u[515];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i217 = 0; c9_i217 < 515; c9_i217++) {
    c9_b_inData[c9_i217] = (*(char_T (*)[515])c9_inData)[c9_i217];
  }

  for (c9_i218 = 0; c9_i218 < 515; c9_i218++) {
    c9_u[c9_i218] = c9_b_inData[c9_i218];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 515),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_s_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[515])
{
  char_T c9_cv17[515];
  int32_T c9_i219;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv17, 1, 10, 0U, 1, 0U, 2, 1,
                515);
  for (c9_i219 = 0; c9_i219 < 515; c9_i219++) {
    c9_y[c9_i219] = c9_cv17[c9_i219];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[515];
  int32_T c9_i220;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i220 = 0; c9_i220 < 515; c9_i220++) {
    (*(char_T (*)[515])c9_outData)[c9_i220] = c9_y[c9_i220];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_db_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i221;
  char_T c9_b_inData[656];
  int32_T c9_i222;
  char_T c9_u[656];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i221 = 0; c9_i221 < 656; c9_i221++) {
    c9_b_inData[c9_i221] = (*(char_T (*)[656])c9_inData)[c9_i221];
  }

  for (c9_i222 = 0; c9_i222 < 656; c9_i222++) {
    c9_u[c9_i222] = c9_b_inData[c9_i222];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 656),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_t_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[656])
{
  char_T c9_cv18[656];
  int32_T c9_i223;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv18, 1, 10, 0U, 1, 0U, 2, 1,
                656);
  for (c9_i223 = 0; c9_i223 < 656; c9_i223++) {
    c9_y[c9_i223] = c9_cv18[c9_i223];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[656];
  int32_T c9_i224;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i224 = 0; c9_i224 < 656; c9_i224++) {
    (*(char_T (*)[656])c9_outData)[c9_i224] = c9_y[c9_i224];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i225;
  char_T c9_b_inData[759];
  int32_T c9_i226;
  char_T c9_u[759];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i225 = 0; c9_i225 < 759; c9_i225++) {
    c9_b_inData[c9_i225] = (*(char_T (*)[759])c9_inData)[c9_i225];
  }

  for (c9_i226 = 0; c9_i226 < 759; c9_i226++) {
    c9_u[c9_i226] = c9_b_inData[c9_i226];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 759),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_u_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[759])
{
  char_T c9_cv19[759];
  int32_T c9_i227;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv19, 1, 10, 0U, 1, 0U, 2, 1,
                759);
  for (c9_i227 = 0; c9_i227 < 759; c9_i227++) {
    c9_y[c9_i227] = c9_cv19[c9_i227];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[759];
  int32_T c9_i228;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i228 = 0; c9_i228 < 759; c9_i228++) {
    (*(char_T (*)[759])c9_outData)[c9_i228] = c9_y[c9_i228];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i229;
  char_T c9_b_inData[862];
  int32_T c9_i230;
  char_T c9_u[862];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i229 = 0; c9_i229 < 862; c9_i229++) {
    c9_b_inData[c9_i229] = (*(char_T (*)[862])c9_inData)[c9_i229];
  }

  for (c9_i230 = 0; c9_i230 < 862; c9_i230++) {
    c9_u[c9_i230] = c9_b_inData[c9_i230];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 862),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_v_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[862])
{
  char_T c9_cv20[862];
  int32_T c9_i231;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv20, 1, 10, 0U, 1, 0U, 2, 1,
                862);
  for (c9_i231 = 0; c9_i231 < 862; c9_i231++) {
    c9_y[c9_i231] = c9_cv20[c9_i231];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[862];
  int32_T c9_i232;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i232 = 0; c9_i232 < 862; c9_i232++) {
    (*(char_T (*)[862])c9_outData)[c9_i232] = c9_y[c9_i232];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i233;
  char_T c9_b_inData[965];
  int32_T c9_i234;
  char_T c9_u[965];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i233 = 0; c9_i233 < 965; c9_i233++) {
    c9_b_inData[c9_i233] = (*(char_T (*)[965])c9_inData)[c9_i233];
  }

  for (c9_i234 = 0; c9_i234 < 965; c9_i234++) {
    c9_u[c9_i234] = c9_b_inData[c9_i234];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 965),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_w_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[965])
{
  char_T c9_cv21[965];
  int32_T c9_i235;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv21, 1, 10, 0U, 1, 0U, 2, 1,
                965);
  for (c9_i235 = 0; c9_i235 < 965; c9_i235++) {
    c9_y[c9_i235] = c9_cv21[c9_i235];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[965];
  int32_T c9_i236;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i236 = 0; c9_i236 < 965; c9_i236++) {
    (*(char_T (*)[965])c9_outData)[c9_i236] = c9_y[c9_i236];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i237;
  char_T c9_b_inData[1068];
  int32_T c9_i238;
  char_T c9_u[1068];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i237 = 0; c9_i237 < 1068; c9_i237++) {
    c9_b_inData[c9_i237] = (*(char_T (*)[1068])c9_inData)[c9_i237];
  }

  for (c9_i238 = 0; c9_i238 < 1068; c9_i238++) {
    c9_u[c9_i238] = c9_b_inData[c9_i238];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 1068),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_x_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1068])
{
  char_T c9_cv22[1068];
  int32_T c9_i239;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv22, 1, 10, 0U, 1, 0U, 2, 1,
                1068);
  for (c9_i239 = 0; c9_i239 < 1068; c9_i239++) {
    c9_y[c9_i239] = c9_cv22[c9_i239];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[1068];
  int32_T c9_i240;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i240 = 0; c9_i240 < 1068; c9_i240++) {
    (*(char_T (*)[1068])c9_outData)[c9_i240] = c9_y[c9_i240];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i241;
  char_T c9_b_inData[1171];
  int32_T c9_i242;
  char_T c9_u[1171];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i241 = 0; c9_i241 < 1171; c9_i241++) {
    c9_b_inData[c9_i241] = (*(char_T (*)[1171])c9_inData)[c9_i241];
  }

  for (c9_i242 = 0; c9_i242 < 1171; c9_i242++) {
    c9_u[c9_i242] = c9_b_inData[c9_i242];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 1171),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_y_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1171])
{
  char_T c9_cv23[1171];
  int32_T c9_i243;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv23, 1, 10, 0U, 1, 0U, 2, 1,
                1171);
  for (c9_i243 = 0; c9_i243 < 1171; c9_i243++) {
    c9_y[c9_i243] = c9_cv23[c9_i243];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[1171];
  int32_T c9_i244;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i244 = 0; c9_i244 < 1171; c9_i244++) {
    (*(char_T (*)[1171])c9_outData)[c9_i244] = c9_y[c9_i244];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i245;
  char_T c9_b_inData[1474];
  int32_T c9_i246;
  char_T c9_u[1474];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i245 = 0; c9_i245 < 1474; c9_i245++) {
    c9_b_inData[c9_i245] = (*(char_T (*)[1474])c9_inData)[c9_i245];
  }

  for (c9_i246 = 0; c9_i246 < 1474; c9_i246++) {
    c9_u[c9_i246] = c9_b_inData[c9_i246];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 1474),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_ab_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1474])
{
  char_T c9_cv24[1474];
  int32_T c9_i247;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv24, 1, 10, 0U, 1, 0U, 2, 1,
                1474);
  for (c9_i247 = 0; c9_i247 < 1474; c9_i247++) {
    c9_y[c9_i247] = c9_cv24[c9_i247];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[1474];
  int32_T c9_i248;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i248 = 0; c9_i248 < 1474; c9_i248++) {
    (*(char_T (*)[1474])c9_outData)[c9_i248] = c9_y[c9_i248];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i249;
  char_T c9_b_inData[1577];
  int32_T c9_i250;
  char_T c9_u[1577];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i249 = 0; c9_i249 < 1577; c9_i249++) {
    c9_b_inData[c9_i249] = (*(char_T (*)[1577])c9_inData)[c9_i249];
  }

  for (c9_i250 = 0; c9_i250 < 1577; c9_i250++) {
    c9_u[c9_i250] = c9_b_inData[c9_i250];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 1577),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_bb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1577])
{
  char_T c9_cv25[1577];
  int32_T c9_i251;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv25, 1, 10, 0U, 1, 0U, 2, 1,
                1577);
  for (c9_i251 = 0; c9_i251 < 1577; c9_i251++) {
    c9_y[c9_i251] = c9_cv25[c9_i251];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[1577];
  int32_T c9_i252;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i252 = 0; c9_i252 < 1577; c9_i252++) {
    (*(char_T (*)[1577])c9_outData)[c9_i252] = c9_y[c9_i252];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i253;
  char_T c9_b_inData[1610];
  int32_T c9_i254;
  char_T c9_u[1610];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i253 = 0; c9_i253 < 1610; c9_i253++) {
    c9_b_inData[c9_i253] = (*(char_T (*)[1610])c9_inData)[c9_i253];
  }

  for (c9_i254 = 0; c9_i254 < 1610; c9_i254++) {
    c9_u[c9_i254] = c9_b_inData[c9_i254];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 1610),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_cb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1610])
{
  char_T c9_cv26[1610];
  int32_T c9_i255;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv26, 1, 10, 0U, 1, 0U, 2, 1,
                1610);
  for (c9_i255 = 0; c9_i255 < 1610; c9_i255++) {
    c9_y[c9_i255] = c9_cv26[c9_i255];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[1610];
  int32_T c9_i256;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i256 = 0; c9_i256 < 1610; c9_i256++) {
    (*(char_T (*)[1610])c9_outData)[c9_i256] = c9_y[c9_i256];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i257;
  char_T c9_b_inData[1713];
  int32_T c9_i258;
  char_T c9_u[1713];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i257 = 0; c9_i257 < 1713; c9_i257++) {
    c9_b_inData[c9_i257] = (*(char_T (*)[1713])c9_inData)[c9_i257];
  }

  for (c9_i258 = 0; c9_i258 < 1713; c9_i258++) {
    c9_u[c9_i258] = c9_b_inData[c9_i258];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 1713),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_db_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[1713])
{
  char_T c9_cv27[1713];
  int32_T c9_i259;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv27, 1, 10, 0U, 1, 0U, 2, 1,
                1713);
  for (c9_i259 = 0; c9_i259 < 1713; c9_i259++) {
    c9_y[c9_i259] = c9_cv27[c9_i259];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_w_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  char_T c9_y[1713];
  int32_T c9_i260;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_mystr);
  for (c9_i260 = 0; c9_i260 < 1713; c9_i260++) {
    (*(char_T (*)[1713])c9_outData)[c9_i260] = c9_y[c9_i260];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  const mxArray *c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = sf_mex_dup(*(const mxArray **)c9_inData);
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), false);
  sf_mex_destroy(&c9_u);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_Expriment_All_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 85, 1),
                false);
  c9_info_helper(&c9_nameCaptureInfo);
  c9_b_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  const mxArray *c9_rhs4 = NULL;
  const mxArray *c9_lhs4 = NULL;
  const mxArray *c9_rhs5 = NULL;
  const mxArray *c9_lhs5 = NULL;
  const mxArray *c9_rhs6 = NULL;
  const mxArray *c9_lhs6 = NULL;
  const mxArray *c9_rhs7 = NULL;
  const mxArray *c9_lhs7 = NULL;
  const mxArray *c9_rhs8 = NULL;
  const mxArray *c9_lhs8 = NULL;
  const mxArray *c9_rhs9 = NULL;
  const mxArray *c9_lhs9 = NULL;
  const mxArray *c9_rhs10 = NULL;
  const mxArray *c9_lhs10 = NULL;
  const mxArray *c9_rhs11 = NULL;
  const mxArray *c9_lhs11 = NULL;
  const mxArray *c9_rhs12 = NULL;
  const mxArray *c9_lhs12 = NULL;
  const mxArray *c9_rhs13 = NULL;
  const mxArray *c9_lhs13 = NULL;
  const mxArray *c9_rhs14 = NULL;
  const mxArray *c9_lhs14 = NULL;
  const mxArray *c9_rhs15 = NULL;
  const mxArray *c9_lhs15 = NULL;
  const mxArray *c9_rhs16 = NULL;
  const mxArray *c9_lhs16 = NULL;
  const mxArray *c9_rhs17 = NULL;
  const mxArray *c9_lhs17 = NULL;
  const mxArray *c9_rhs18 = NULL;
  const mxArray *c9_lhs18 = NULL;
  const mxArray *c9_rhs19 = NULL;
  const mxArray *c9_lhs19 = NULL;
  const mxArray *c9_rhs20 = NULL;
  const mxArray *c9_lhs20 = NULL;
  const mxArray *c9_rhs21 = NULL;
  const mxArray *c9_lhs21 = NULL;
  const mxArray *c9_rhs22 = NULL;
  const mxArray *c9_lhs22 = NULL;
  const mxArray *c9_rhs23 = NULL;
  const mxArray *c9_lhs23 = NULL;
  const mxArray *c9_rhs24 = NULL;
  const mxArray *c9_lhs24 = NULL;
  const mxArray *c9_rhs25 = NULL;
  const mxArray *c9_lhs25 = NULL;
  const mxArray *c9_rhs26 = NULL;
  const mxArray *c9_lhs26 = NULL;
  const mxArray *c9_rhs27 = NULL;
  const mxArray *c9_lhs27 = NULL;
  const mxArray *c9_rhs28 = NULL;
  const mxArray *c9_lhs28 = NULL;
  const mxArray *c9_rhs29 = NULL;
  const mxArray *c9_lhs29 = NULL;
  const mxArray *c9_rhs30 = NULL;
  const mxArray *c9_lhs30 = NULL;
  const mxArray *c9_rhs31 = NULL;
  const mxArray *c9_lhs31 = NULL;
  const mxArray *c9_rhs32 = NULL;
  const mxArray *c9_lhs32 = NULL;
  const mxArray *c9_rhs33 = NULL;
  const mxArray *c9_lhs33 = NULL;
  const mxArray *c9_rhs34 = NULL;
  const mxArray *c9_lhs34 = NULL;
  const mxArray *c9_rhs35 = NULL;
  const mxArray *c9_lhs35 = NULL;
  const mxArray *c9_rhs36 = NULL;
  const mxArray *c9_lhs36 = NULL;
  const mxArray *c9_rhs37 = NULL;
  const mxArray *c9_lhs37 = NULL;
  const mxArray *c9_rhs38 = NULL;
  const mxArray *c9_lhs38 = NULL;
  const mxArray *c9_rhs39 = NULL;
  const mxArray *c9_lhs39 = NULL;
  const mxArray *c9_rhs40 = NULL;
  const mxArray *c9_lhs40 = NULL;
  const mxArray *c9_rhs41 = NULL;
  const mxArray *c9_lhs41 = NULL;
  const mxArray *c9_rhs42 = NULL;
  const mxArray *c9_lhs42 = NULL;
  const mxArray *c9_rhs43 = NULL;
  const mxArray *c9_lhs43 = NULL;
  const mxArray *c9_rhs44 = NULL;
  const mxArray *c9_lhs44 = NULL;
  const mxArray *c9_rhs45 = NULL;
  const mxArray *c9_lhs45 = NULL;
  const mxArray *c9_rhs46 = NULL;
  const mxArray *c9_lhs46 = NULL;
  const mxArray *c9_rhs47 = NULL;
  const mxArray *c9_lhs47 = NULL;
  const mxArray *c9_rhs48 = NULL;
  const mxArray *c9_lhs48 = NULL;
  const mxArray *c9_rhs49 = NULL;
  const mxArray *c9_lhs49 = NULL;
  const mxArray *c9_rhs50 = NULL;
  const mxArray *c9_lhs50 = NULL;
  const mxArray *c9_rhs51 = NULL;
  const mxArray *c9_lhs51 = NULL;
  const mxArray *c9_rhs52 = NULL;
  const mxArray *c9_lhs52 = NULL;
  const mxArray *c9_rhs53 = NULL;
  const mxArray *c9_lhs53 = NULL;
  const mxArray *c9_rhs54 = NULL;
  const mxArray *c9_lhs54 = NULL;
  const mxArray *c9_rhs55 = NULL;
  const mxArray *c9_lhs55 = NULL;
  const mxArray *c9_rhs56 = NULL;
  const mxArray *c9_lhs56 = NULL;
  const mxArray *c9_rhs57 = NULL;
  const mxArray *c9_lhs57 = NULL;
  const mxArray *c9_rhs58 = NULL;
  const mxArray *c9_lhs58 = NULL;
  const mxArray *c9_rhs59 = NULL;
  const mxArray *c9_lhs59 = NULL;
  const mxArray *c9_rhs60 = NULL;
  const mxArray *c9_lhs60 = NULL;
  const mxArray *c9_rhs61 = NULL;
  const mxArray *c9_lhs61 = NULL;
  const mxArray *c9_rhs62 = NULL;
  const mxArray *c9_lhs62 = NULL;
  const mxArray *c9_rhs63 = NULL;
  const mxArray *c9_lhs63 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1452377975U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c9_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mrdivide"), "name", "name", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c9_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c9_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("rdivide"), "name", "name", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c9_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c9_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c9_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_div"), "name", "name", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c9_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c9_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("cmdBML_AU_VA"), "name", "name",
                  12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1452379246U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c9_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("abs"), "name", "name", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c9_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c9_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c9_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("log10"), "name", "name", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1343862782U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c9_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_error"), "name", "name",
                  17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c9_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851128U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c9_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("realmax"), "name", "name", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1307683642U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c9_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_realmax"), "name", "name",
                  20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c9_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c9_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mrdivide"), "name", "name", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c9_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("ceil"), "name", "name", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c9_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c9_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_ceil"), "name",
                  "name", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_ceil.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851120U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c9_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("max"), "name", "name", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1311287716U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c9_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1378328384U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c9_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c9_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c9_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c9_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c9_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c9_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c9_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c9_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("blanks"), "name", "name", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c9_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c9_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("fprintf"), "name", "name", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c9_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isequal"), "name", "name", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c9_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c9_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isnan"), "name", "name", 40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c9_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c9_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c9_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("fprintf"), "name", "name", 43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c9_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("upper"), "name", "name", 44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c9_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_string_transform"), "name",
                  "name", 45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c9_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c9_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_charmax"), "name", "name",
                  47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c9_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("intmax"), "name", "name", 48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c9_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c9_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_charmax"), "name", "name",
                  50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c9_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("colon"), "name", "name", 51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c9_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("colon"), "name", "name", 52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c9_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c9_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c9_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("floor"), "name", "name", 55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c9_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c9_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c9_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("intmin"), "name", "name", 58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c9_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 59);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c9_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 60);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("intmax"), "name", "name", 60);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c9_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 61);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("intmin"), "name", "name", 61);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c9_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 62);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("intmax"), "name", "name", 62);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c9_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 63);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  63);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c9_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
  sf_mex_destroy(&c9_rhs4);
  sf_mex_destroy(&c9_lhs4);
  sf_mex_destroy(&c9_rhs5);
  sf_mex_destroy(&c9_lhs5);
  sf_mex_destroy(&c9_rhs6);
  sf_mex_destroy(&c9_lhs6);
  sf_mex_destroy(&c9_rhs7);
  sf_mex_destroy(&c9_lhs7);
  sf_mex_destroy(&c9_rhs8);
  sf_mex_destroy(&c9_lhs8);
  sf_mex_destroy(&c9_rhs9);
  sf_mex_destroy(&c9_lhs9);
  sf_mex_destroy(&c9_rhs10);
  sf_mex_destroy(&c9_lhs10);
  sf_mex_destroy(&c9_rhs11);
  sf_mex_destroy(&c9_lhs11);
  sf_mex_destroy(&c9_rhs12);
  sf_mex_destroy(&c9_lhs12);
  sf_mex_destroy(&c9_rhs13);
  sf_mex_destroy(&c9_lhs13);
  sf_mex_destroy(&c9_rhs14);
  sf_mex_destroy(&c9_lhs14);
  sf_mex_destroy(&c9_rhs15);
  sf_mex_destroy(&c9_lhs15);
  sf_mex_destroy(&c9_rhs16);
  sf_mex_destroy(&c9_lhs16);
  sf_mex_destroy(&c9_rhs17);
  sf_mex_destroy(&c9_lhs17);
  sf_mex_destroy(&c9_rhs18);
  sf_mex_destroy(&c9_lhs18);
  sf_mex_destroy(&c9_rhs19);
  sf_mex_destroy(&c9_lhs19);
  sf_mex_destroy(&c9_rhs20);
  sf_mex_destroy(&c9_lhs20);
  sf_mex_destroy(&c9_rhs21);
  sf_mex_destroy(&c9_lhs21);
  sf_mex_destroy(&c9_rhs22);
  sf_mex_destroy(&c9_lhs22);
  sf_mex_destroy(&c9_rhs23);
  sf_mex_destroy(&c9_lhs23);
  sf_mex_destroy(&c9_rhs24);
  sf_mex_destroy(&c9_lhs24);
  sf_mex_destroy(&c9_rhs25);
  sf_mex_destroy(&c9_lhs25);
  sf_mex_destroy(&c9_rhs26);
  sf_mex_destroy(&c9_lhs26);
  sf_mex_destroy(&c9_rhs27);
  sf_mex_destroy(&c9_lhs27);
  sf_mex_destroy(&c9_rhs28);
  sf_mex_destroy(&c9_lhs28);
  sf_mex_destroy(&c9_rhs29);
  sf_mex_destroy(&c9_lhs29);
  sf_mex_destroy(&c9_rhs30);
  sf_mex_destroy(&c9_lhs30);
  sf_mex_destroy(&c9_rhs31);
  sf_mex_destroy(&c9_lhs31);
  sf_mex_destroy(&c9_rhs32);
  sf_mex_destroy(&c9_lhs32);
  sf_mex_destroy(&c9_rhs33);
  sf_mex_destroy(&c9_lhs33);
  sf_mex_destroy(&c9_rhs34);
  sf_mex_destroy(&c9_lhs34);
  sf_mex_destroy(&c9_rhs35);
  sf_mex_destroy(&c9_lhs35);
  sf_mex_destroy(&c9_rhs36);
  sf_mex_destroy(&c9_lhs36);
  sf_mex_destroy(&c9_rhs37);
  sf_mex_destroy(&c9_lhs37);
  sf_mex_destroy(&c9_rhs38);
  sf_mex_destroy(&c9_lhs38);
  sf_mex_destroy(&c9_rhs39);
  sf_mex_destroy(&c9_lhs39);
  sf_mex_destroy(&c9_rhs40);
  sf_mex_destroy(&c9_lhs40);
  sf_mex_destroy(&c9_rhs41);
  sf_mex_destroy(&c9_lhs41);
  sf_mex_destroy(&c9_rhs42);
  sf_mex_destroy(&c9_lhs42);
  sf_mex_destroy(&c9_rhs43);
  sf_mex_destroy(&c9_lhs43);
  sf_mex_destroy(&c9_rhs44);
  sf_mex_destroy(&c9_lhs44);
  sf_mex_destroy(&c9_rhs45);
  sf_mex_destroy(&c9_lhs45);
  sf_mex_destroy(&c9_rhs46);
  sf_mex_destroy(&c9_lhs46);
  sf_mex_destroy(&c9_rhs47);
  sf_mex_destroy(&c9_lhs47);
  sf_mex_destroy(&c9_rhs48);
  sf_mex_destroy(&c9_lhs48);
  sf_mex_destroy(&c9_rhs49);
  sf_mex_destroy(&c9_lhs49);
  sf_mex_destroy(&c9_rhs50);
  sf_mex_destroy(&c9_lhs50);
  sf_mex_destroy(&c9_rhs51);
  sf_mex_destroy(&c9_lhs51);
  sf_mex_destroy(&c9_rhs52);
  sf_mex_destroy(&c9_lhs52);
  sf_mex_destroy(&c9_rhs53);
  sf_mex_destroy(&c9_lhs53);
  sf_mex_destroy(&c9_rhs54);
  sf_mex_destroy(&c9_lhs54);
  sf_mex_destroy(&c9_rhs55);
  sf_mex_destroy(&c9_lhs55);
  sf_mex_destroy(&c9_rhs56);
  sf_mex_destroy(&c9_lhs56);
  sf_mex_destroy(&c9_rhs57);
  sf_mex_destroy(&c9_lhs57);
  sf_mex_destroy(&c9_rhs58);
  sf_mex_destroy(&c9_lhs58);
  sf_mex_destroy(&c9_rhs59);
  sf_mex_destroy(&c9_lhs59);
  sf_mex_destroy(&c9_rhs60);
  sf_mex_destroy(&c9_lhs60);
  sf_mex_destroy(&c9_rhs61);
  sf_mex_destroy(&c9_lhs61);
  sf_mex_destroy(&c9_rhs62);
  sf_mex_destroy(&c9_lhs62);
  sf_mex_destroy(&c9_rhs63);
  sf_mex_destroy(&c9_lhs63);
}

static const mxArray *c9_emlrt_marshallOut(const char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), false);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  return c9_y;
}

static void c9_b_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs64 = NULL;
  const mxArray *c9_lhs64 = NULL;
  const mxArray *c9_rhs65 = NULL;
  const mxArray *c9_lhs65 = NULL;
  const mxArray *c9_rhs66 = NULL;
  const mxArray *c9_lhs66 = NULL;
  const mxArray *c9_rhs67 = NULL;
  const mxArray *c9_lhs67 = NULL;
  const mxArray *c9_rhs68 = NULL;
  const mxArray *c9_lhs68 = NULL;
  const mxArray *c9_rhs69 = NULL;
  const mxArray *c9_lhs69 = NULL;
  const mxArray *c9_rhs70 = NULL;
  const mxArray *c9_lhs70 = NULL;
  const mxArray *c9_rhs71 = NULL;
  const mxArray *c9_lhs71 = NULL;
  const mxArray *c9_rhs72 = NULL;
  const mxArray *c9_lhs72 = NULL;
  const mxArray *c9_rhs73 = NULL;
  const mxArray *c9_lhs73 = NULL;
  const mxArray *c9_rhs74 = NULL;
  const mxArray *c9_lhs74 = NULL;
  const mxArray *c9_rhs75 = NULL;
  const mxArray *c9_lhs75 = NULL;
  const mxArray *c9_rhs76 = NULL;
  const mxArray *c9_lhs76 = NULL;
  const mxArray *c9_rhs77 = NULL;
  const mxArray *c9_lhs77 = NULL;
  const mxArray *c9_rhs78 = NULL;
  const mxArray *c9_lhs78 = NULL;
  const mxArray *c9_rhs79 = NULL;
  const mxArray *c9_lhs79 = NULL;
  const mxArray *c9_rhs80 = NULL;
  const mxArray *c9_lhs80 = NULL;
  const mxArray *c9_rhs81 = NULL;
  const mxArray *c9_lhs81 = NULL;
  const mxArray *c9_rhs82 = NULL;
  const mxArray *c9_lhs82 = NULL;
  const mxArray *c9_rhs83 = NULL;
  const mxArray *c9_lhs83 = NULL;
  const mxArray *c9_rhs84 = NULL;
  const mxArray *c9_lhs84 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 64);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 64);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c9_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 65);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 65);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c9_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.unsignedClass"),
                  "name", "name", 66);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c9_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 67);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 67);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c9_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 68);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 68);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c9_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 69);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("intmax"), "name", "name", 69);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c9_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 70);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  70);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c9_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 71);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 71);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c9_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 72);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c9_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 73);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 73);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c9_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 74);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("intmax"), "name", "name", 74);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c9_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 75);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "name", "name", 75);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c9_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("fidCheck"), "name", "name", 76);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c9_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 77);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("upper"), "name", "name", 77);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c9_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 78);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 78);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c9_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 79);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 79);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c9_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 80);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 80);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c9_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 81);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 81);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c9_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 82);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 82);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c9_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 83);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 83);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c9_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 84);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  84);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/15-1-2016-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1452377975U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c9_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs84), "lhs", "lhs",
                  84);
  sf_mex_destroy(&c9_rhs64);
  sf_mex_destroy(&c9_lhs64);
  sf_mex_destroy(&c9_rhs65);
  sf_mex_destroy(&c9_lhs65);
  sf_mex_destroy(&c9_rhs66);
  sf_mex_destroy(&c9_lhs66);
  sf_mex_destroy(&c9_rhs67);
  sf_mex_destroy(&c9_lhs67);
  sf_mex_destroy(&c9_rhs68);
  sf_mex_destroy(&c9_lhs68);
  sf_mex_destroy(&c9_rhs69);
  sf_mex_destroy(&c9_lhs69);
  sf_mex_destroy(&c9_rhs70);
  sf_mex_destroy(&c9_lhs70);
  sf_mex_destroy(&c9_rhs71);
  sf_mex_destroy(&c9_lhs71);
  sf_mex_destroy(&c9_rhs72);
  sf_mex_destroy(&c9_lhs72);
  sf_mex_destroy(&c9_rhs73);
  sf_mex_destroy(&c9_lhs73);
  sf_mex_destroy(&c9_rhs74);
  sf_mex_destroy(&c9_lhs74);
  sf_mex_destroy(&c9_rhs75);
  sf_mex_destroy(&c9_lhs75);
  sf_mex_destroy(&c9_rhs76);
  sf_mex_destroy(&c9_lhs76);
  sf_mex_destroy(&c9_rhs77);
  sf_mex_destroy(&c9_lhs77);
  sf_mex_destroy(&c9_rhs78);
  sf_mex_destroy(&c9_lhs78);
  sf_mex_destroy(&c9_rhs79);
  sf_mex_destroy(&c9_lhs79);
  sf_mex_destroy(&c9_rhs80);
  sf_mex_destroy(&c9_lhs80);
  sf_mex_destroy(&c9_rhs81);
  sf_mex_destroy(&c9_lhs81);
  sf_mex_destroy(&c9_rhs82);
  sf_mex_destroy(&c9_lhs82);
  sf_mex_destroy(&c9_rhs83);
  sf_mex_destroy(&c9_lhs83);
  sf_mex_destroy(&c9_rhs84);
  sf_mex_destroy(&c9_lhs84);
}

static void c9_activate_secsc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = c9_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_deactivate_secsc9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_increment_counters_secsc9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  if (chartInstance->c9_temporalCounter_i1 < 15U) {
    chartInstance->c9_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c9_temporalCounter_i1 + 1);
  }

  if (chartInstance->c9_temporalCounter_i2 < MAX_uint32_T) {
    chartInstance->c9_temporalCounter_i2++;
  }

  if (chartInstance->c9_temporalCounter_i3 < 15U) {
    chartInstance->c9_temporalCounter_i3 = (uint8_T)(int16_T)
      (chartInstance->c9_temporalCounter_i3 + 1);
  }
}

static void c9_reset_counters_secsc9_Expriment_All
  (SFc9_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c9_Expriment_All_secs(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_activate_secsc9_Expriment_All(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c9_Expriment_All_secs(SimStruct
  *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_increment_counters_secsc9_Expriment_All(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c9_Expriment_All_secs(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_reset_counters_secsc9_Expriment_All(chartInstance);
}

void sf_exported_auto_deactivate_c9_Expriment_All_secs(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_deactivate_secsc9_Expriment_All(chartInstance);
}

boolean_T sf_exported_auto_isStablec9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  return chartInstance->c9_isStable;
}

void sf_exported_auto_duringc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_c9_Expriment_All(chartInstance);
}

void sf_exported_auto_enterc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_enter_atomic_c9_Expriment_All(chartInstance);
  c9_enter_internal_c9_Expriment_All(chartInstance);
}

void sf_exported_auto_exitc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_exit_internal_c9_Expriment_All(chartInstance);
}

void sf_exported_auto_gatewayc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  chartInstance->c9_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_initc9_Expriment_All(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec9_Expriment_All(SimStruct *c9_S)
{
  const mxArray *c9_out = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_out = NULL;
  sf_mex_assign(&c9_out, sf_internal_get_sim_state_c9_Expriment_All(c9_S), false);
  return c9_out;
}

void sf_exported_auto_setSimstatec9_Expriment_All(SimStruct *c9_S, const mxArray
  *c9_in)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c9_Expriment_All(c9_S, sf_mex_dup(c9_in));
  sf_mex_destroy(&c9_in);
}

void sf_exported_auto_check_state_inconsistency_c9_Expriment_All(SimStruct *c9_S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_AllMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_insertQueuec9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmls[10000], real_T c9_myBML[2000], real_T
  c9_newBmls[10000])
{
  uint32_T c9_debug_family_var_map[8];
  real_T c9_full;
  real_T c9_t[2000];
  real_T c9_i;
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i261;
  static real_T c9_dv40[2000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c9_i262;
  int32_T c9_i263;
  int32_T c9_i264;
  int32_T c9_i265;
  int32_T c9_i266;
  int32_T c9_b_i;
  int32_T c9_c_i;
  int32_T c9_i267;
  real_T c9_b_bmls[2000];
  int32_T c9_i268;
  real_T c9_dv41[2000];
  int32_T c9_d_i;
  int32_T c9_i269;
  int32_T c9_i270;
  real_T c9_c_bmls[2000];
  int32_T c9_i271;
  int32_T c9_i272;
  real_T c9_d_bmls[2000];
  int32_T c9_i273;
  int32_T c9_i274;
  real_T c9_e_bmls[2000];
  int32_T c9_i275;
  int32_T c9_i276;
  int32_T c9_i277;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_full, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_t, 1U, c9_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_bmls, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myBML, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_newBmls, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 2);
  c9_full = 1.0;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 3);
  for (c9_i261 = 0; c9_i261 < 2000; c9_i261++) {
    c9_t[c9_i261] = c9_dv40[c9_i261];
  }

  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 4);
  for (c9_i262 = 0; c9_i262 < 2000; c9_i262++) {
    c9_newBmls[c9_i262] = c9_t[c9_i262];
  }

  for (c9_i263 = 0; c9_i263 < 2000; c9_i263++) {
    c9_newBmls[c9_i263 + 2000] = c9_t[c9_i263];
  }

  for (c9_i264 = 0; c9_i264 < 2000; c9_i264++) {
    c9_newBmls[c9_i264 + 4000] = c9_t[c9_i264];
  }

  for (c9_i265 = 0; c9_i265 < 2000; c9_i265++) {
    c9_newBmls[c9_i265 + 6000] = c9_t[c9_i265];
  }

  for (c9_i266 = 0; c9_i266 < 2000; c9_i266++) {
    c9_newBmls[c9_i266 + 8000] = c9_t[c9_i266];
  }

  c9_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 5);
  c9_i = 1.0;
  c9_b_i = 0;
  do {
    exitg1 = 0;
    if (c9_b_i < 5) {
      c9_i = 1.0 + (real_T)c9_b_i;
      CV_EML_FOR(6, 1, 0, 1);
      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 6);
      c9_c_i = (int32_T)c9_i - 1;
      for (c9_i267 = 0; c9_i267 < 2000; c9_i267++) {
        c9_b_bmls[c9_i267] = c9_bmls[c9_i267 + 2000 * c9_c_i];
      }

      for (c9_i268 = 0; c9_i268 < 2000; c9_i268++) {
        c9_dv41[c9_i268] = c9_dv40[c9_i268];
      }

      if (CV_EML_IF(6, 1, 0, c9_b_isequal(chartInstance, c9_b_bmls, c9_dv41))) {
        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 8);
        c9_d_i = (int32_T)c9_i - 1;
        for (c9_i269 = 0; c9_i269 < 2000; c9_i269++) {
          c9_bmls[c9_i269 + 2000 * c9_d_i] = c9_myBML[c9_i269];
        }

        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 9);
        c9_full = 0.0;
        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 10);
        exitg1 = 1;
      } else {
        c9_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(6, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 13);
  if (CV_EML_IF(6, 1, 1, c9_full != 0.0)) {
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 15);
    for (c9_i270 = 0; c9_i270 < 2000; c9_i270++) {
      c9_c_bmls[c9_i270] = c9_bmls[c9_i270 + 2000];
    }

    for (c9_i271 = 0; c9_i271 < 2000; c9_i271++) {
      c9_bmls[c9_i271] = c9_c_bmls[c9_i271];
    }

    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 16);
    for (c9_i272 = 0; c9_i272 < 2000; c9_i272++) {
      c9_d_bmls[c9_i272] = c9_bmls[c9_i272 + 4000];
    }

    for (c9_i273 = 0; c9_i273 < 2000; c9_i273++) {
      c9_bmls[c9_i273 + 2000] = c9_d_bmls[c9_i273];
    }

    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 17);
    for (c9_i274 = 0; c9_i274 < 2000; c9_i274++) {
      c9_e_bmls[c9_i274] = c9_bmls[c9_i274 + 6000];
    }

    for (c9_i275 = 0; c9_i275 < 2000; c9_i275++) {
      c9_bmls[c9_i275 + 4000] = c9_e_bmls[c9_i275];
    }

    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 18);
    for (c9_i276 = 0; c9_i276 < 2000; c9_i276++) {
      c9_bmls[c9_i276 + 8000] = c9_myBML[c9_i276];
    }
  }

  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 20);
  for (c9_i277 = 0; c9_i277 < 10000; c9_i277++) {
    c9_newBmls[c9_i277] = c9_bmls[c9_i277];
  }

  c9_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_insertQueueLowc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmls[10000], real_T c9_myBML[2000], real_T
  c9_newBmls[10000])
{
  uint32_T c9_debug_family_var_map[8];
  real_T c9_full;
  real_T c9_t[2000];
  real_T c9_i;
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i278;
  static real_T c9_dv42[2000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c9_i279;
  int32_T c9_i280;
  int32_T c9_i281;
  int32_T c9_i282;
  int32_T c9_i283;
  int32_T c9_b_i;
  int32_T c9_c_i;
  int32_T c9_i284;
  real_T c9_b_bmls[2000];
  int32_T c9_i285;
  real_T c9_dv43[2000];
  int32_T c9_d_i;
  int32_T c9_i286;
  int32_T c9_i287;
  real_T c9_c_bmls[2000];
  int32_T c9_i288;
  int32_T c9_i289;
  real_T c9_d_bmls[2000];
  int32_T c9_i290;
  int32_T c9_i291;
  real_T c9_e_bmls[2000];
  int32_T c9_i292;
  int32_T c9_i293;
  int32_T c9_i294;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c9_c_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_full, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_t, 1U, c9_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_bmls, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myBML, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_newBmls, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 2);
  c9_full = 1.0;
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 3);
  for (c9_i278 = 0; c9_i278 < 2000; c9_i278++) {
    c9_t[c9_i278] = c9_dv42[c9_i278];
  }

  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 4);
  for (c9_i279 = 0; c9_i279 < 2000; c9_i279++) {
    c9_newBmls[c9_i279] = c9_t[c9_i279];
  }

  for (c9_i280 = 0; c9_i280 < 2000; c9_i280++) {
    c9_newBmls[c9_i280 + 2000] = c9_t[c9_i280];
  }

  for (c9_i281 = 0; c9_i281 < 2000; c9_i281++) {
    c9_newBmls[c9_i281 + 4000] = c9_t[c9_i281];
  }

  for (c9_i282 = 0; c9_i282 < 2000; c9_i282++) {
    c9_newBmls[c9_i282 + 6000] = c9_t[c9_i282];
  }

  for (c9_i283 = 0; c9_i283 < 2000; c9_i283++) {
    c9_newBmls[c9_i283 + 8000] = c9_t[c9_i283];
  }

  c9_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 5);
  c9_i = 1.0;
  c9_b_i = 0;
  do {
    exitg1 = 0;
    if (c9_b_i < 5) {
      c9_i = 1.0 + (real_T)c9_b_i;
      CV_EML_FOR(7, 1, 0, 1);
      _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 6);
      c9_c_i = (int32_T)c9_i - 1;
      for (c9_i284 = 0; c9_i284 < 2000; c9_i284++) {
        c9_b_bmls[c9_i284] = c9_bmls[c9_i284 + 2000 * c9_c_i];
      }

      for (c9_i285 = 0; c9_i285 < 2000; c9_i285++) {
        c9_dv43[c9_i285] = c9_dv42[c9_i285];
      }

      if (CV_EML_IF(7, 1, 0, c9_b_isequal(chartInstance, c9_b_bmls, c9_dv43))) {
        _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 8);
        c9_d_i = (int32_T)c9_i - 1;
        for (c9_i286 = 0; c9_i286 < 2000; c9_i286++) {
          c9_bmls[c9_i286 + 2000 * c9_d_i] = c9_myBML[c9_i286];
        }

        _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 9);
        c9_full = 0.0;
        _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 10);
        exitg1 = 1;
      } else {
        c9_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(7, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 13);
  if (CV_EML_IF(7, 1, 1, c9_full != 0.0)) {
    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 15);
    for (c9_i287 = 0; c9_i287 < 2000; c9_i287++) {
      c9_c_bmls[c9_i287] = c9_bmls[c9_i287 + 2000];
    }

    for (c9_i288 = 0; c9_i288 < 2000; c9_i288++) {
      c9_bmls[c9_i288] = c9_c_bmls[c9_i288];
    }

    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 16);
    for (c9_i289 = 0; c9_i289 < 2000; c9_i289++) {
      c9_d_bmls[c9_i289] = c9_bmls[c9_i289 + 4000];
    }

    for (c9_i290 = 0; c9_i290 < 2000; c9_i290++) {
      c9_bmls[c9_i290 + 2000] = c9_d_bmls[c9_i290];
    }

    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 17);
    for (c9_i291 = 0; c9_i291 < 2000; c9_i291++) {
      c9_e_bmls[c9_i291] = c9_bmls[c9_i291 + 6000];
    }

    for (c9_i292 = 0; c9_i292 < 2000; c9_i292++) {
      c9_bmls[c9_i292 + 4000] = c9_e_bmls[c9_i292];
    }

    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 18);
    for (c9_i293 = 0; c9_i293 < 2000; c9_i293++) {
      c9_bmls[c9_i293 + 8000] = c9_myBML[c9_i293];
    }
  }

  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 20);
  for (c9_i294 = 0; c9_i294 < 10000; c9_i294++) {
    c9_newBmls[c9_i294] = c9_bmls[c9_i294];
  }

  c9_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_smileTablec9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv44[2000];
  int32_T c9_i295;
  int32_T c9_i296;
  int32_T c9_i297;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_d_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(9, 0);
  _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 15);
  if (CV_EML_IF(9, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 16);
    CV_EML_FCN(9, 1);
    _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 27);
    c9_b_encStr2Arr(chartInstance, c9_dv44);
    for (c9_i295 = 0; c9_i295 < 2000; c9_i295++) {
      c9_poseBML[c9_i295] = c9_dv44[c9_i295];
    }

    c9_updateDataWrittenToVector(chartInstance, 17U);
    _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 27);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 16U);
    _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, -27);
  } else {
    _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 17);
    if (CV_EML_IF(9, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 18);
      CV_EML_FCN(9, 2);
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 33);
      c9_c_encStr2Arr(chartInstance, c9_dv44);
      for (c9_i296 = 0; c9_i296 < 2000; c9_i296++) {
        c9_poseBML[c9_i296] = c9_dv44[c9_i296];
      }

      c9_updateDataWrittenToVector(chartInstance, 17U);
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 33);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, -33);
    } else {
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 20);
      CV_EML_FCN(9, 1);
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 27);
      c9_b_encStr2Arr(chartInstance, c9_dv44);
      for (c9_i297 = 0; c9_i297 < 2000; c9_i297++) {
        c9_poseBML[c9_i297] = c9_dv44[c9_i297];
      }

      c9_updateDataWrittenToVector(chartInstance, 17U);
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, 27);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(9U, chartInstance->c9_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_facialExprc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv45[2000];
  int32_T c9_i298;
  int32_T c9_i299;
  int32_T c9_i300;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_g_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 15);
  if (CV_EML_IF(5, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 16);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 27);
    c9_d_encStr2Arr(chartInstance, c9_dv45);
    for (c9_i298 = 0; c9_i298 < 2000; c9_i298++) {
      c9_poseBML[c9_i298] = c9_dv45[c9_i298];
    }

    c9_updateDataWrittenToVector(chartInstance, 19U);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 27);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -27);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 17);
    if (CV_EML_IF(5, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 18);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 33);
      c9_c_encStr2Arr(chartInstance, c9_dv45);
      for (c9_i299 = 0; c9_i299 < 2000; c9_i299++) {
        c9_poseBML[c9_i299] = c9_dv45[c9_i299];
      }

      c9_updateDataWrittenToVector(chartInstance, 19U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 33);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -33);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 20);
      CV_EML_FCN(5, 1);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 27);
      c9_d_encStr2Arr(chartInstance, c9_dv45);
      for (c9_i300 = 0; c9_i300 < 2000; c9_i300++) {
        c9_poseBML[c9_i300] = c9_dv45[c9_i300];
      }

      c9_updateDataWrittenToVector(chartInstance, 19U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 27);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_set_AU_Amountc9_Expriment_All(SFc9_Expriment_AllInstanceStruct
  *chartInstance, real_T c9_arousal, real_T c9_valence, real_T c9_inPersonality,
  real_T c9_eAmountFactor[15])
{
  uint32_T c9_debug_family_var_map[10];
  real_T c9_p;
  real_T c9_a;
  real_T c9_all_AUs[15];
  real_T c9_c;
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i301;
  static real_T c9_dv46[15] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 12.0, 26.0, 45.0,
    10.0, 25.0, 102.0, 103.0, 104.0, 105.0 };

  int32_T c9_i302;
  int32_T c9_b_c;
  int32_T c9_i303;
  real_T c9_A[15];
  int32_T c9_i304;
  int32_T c9_i305;
  int32_T c9_i306;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c9_i_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_p, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_a, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_all_AUs, 2U, c9_m_sf_marshallOut,
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_arousal, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_valence, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_inPersonality, 8U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_eAmountFactor, 9U, c9_m_sf_marshallOut,
    c9_f_sf_marshallIn);
  CV_EML_FCN(8, 0);
  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 8);
  c9_p = c9_valence;
  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 8);
  c9_a = c9_arousal;
  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 9);
  for (c9_i301 = 0; c9_i301 < 15; c9_i301++) {
    c9_all_AUs[c9_i301] = c9_dv46[c9_i301];
  }

  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 9);
  for (c9_i302 = 0; c9_i302 < 15; c9_i302++) {
    c9_eAmountFactor[c9_i302] = 0.0;
  }

  c9_updateDataWrittenToVector(chartInstance, 20U);
  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 10);
  c9_c = 1.0;
  c9_b_c = 0;
  while (c9_b_c < 15) {
    c9_c = 1.0 + (real_T)c9_b_c;
    CV_EML_FOR(8, 1, 0, 1);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 11);
    c9_eAmountFactor[0] = 0.0036 * c9_p - -0.01 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 12);
    c9_eAmountFactor[1] = 0.0024 * c9_p + 0.04 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 14);
    c9_eAmountFactor[7] = -0.002 * c9_p + 0.023 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 15);
    c9_eAmountFactor[4] = -0.008 * c9_p + 0.009 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 17);
    c9_eAmountFactor[12] = (0.007 * c9_p + 0.025 * c9_a) * 0.3;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 19);
    c9_eAmountFactor[14] = (0.003 * c9_p + 0.009 * c9_a) * 0.5;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 20);
    c9_eAmountFactor[13] = (0.003 * c9_p + 0.009 * c9_a) * 0.5;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 27);
    c9_eAmountFactor[9] = -0.02 * c9_p + 0.026 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 28);
    c9_eAmountFactor[3] = -0.003 * c9_p + 0.057600000000000005 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 29);
    c9_eAmountFactor[8] = -0.0021000000000000003 * c9_p - 0.0074 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 30);
    c9_eAmountFactor[2] = -0.053999999999999992 * c9_p + 0.011 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 35);
    c9_eAmountFactor[10] = -0.011 * c9_p + 0.023 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 44);
    c9_eAmountFactor[11] = (0.039 * c9_p + 0.015 * c9_a) * 0.2;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 45);
    c9_eAmountFactor[5] = -0.005 * c9_p - 0.001 * c9_a;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 46);
    c9_eAmountFactor[6] = (0.057 * c9_p + 0.009 * c9_a) * 1.1;
    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 52);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 20U, 46U);
    for (c9_i303 = 0; c9_i303 < 15; c9_i303++) {
      c9_A[c9_i303] = c9_eAmountFactor[c9_i303];
    }

    for (c9_i304 = 0; c9_i304 < 15; c9_i304++) {
      c9_eAmountFactor[c9_i304] = c9_A[c9_i304] / 4.5;
    }

    c9_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 53);
    guard1 = false;
    if (CV_EML_COND(8, 1, 0, c9_inPersonality == 2.0)) {
      guard1 = true;
    } else if (CV_EML_COND(8, 1, 1, c9_inPersonality == 4.0)) {
      guard1 = true;
    } else {
      CV_EML_MCDC(8, 1, 0, false);
      CV_EML_IF(8, 1, 0, false);
    }

    if (guard1 == true) {
      CV_EML_MCDC(8, 1, 0, true);
      CV_EML_IF(8, 1, 0, true);
      _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 54);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 20U, 46U);
      for (c9_i305 = 0; c9_i305 < 15; c9_i305++) {
        c9_A[c9_i305] = c9_eAmountFactor[c9_i305];
      }

      for (c9_i306 = 0; c9_i306 < 15; c9_i306++) {
        c9_eAmountFactor[c9_i306] = c9_A[c9_i306] / 1.3;
      }

      c9_updateDataWrittenToVector(chartInstance, 20U);
    }

    c9_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(8, 1, 0, 0);
  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_faceTwitchTablec9_Expriment_All(SFc9_Expriment_AllInstanceStruct *
  chartInstance, real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000])
{
  uint32_T c9_debug_family_var_map[10];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  boolean_T c9_aVarTruthTableCondition_4;
  boolean_T c9_aVarTruthTableCondition_5;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv47[2000];
  int32_T c9_i307;
  int32_T c9_i308;
  int32_T c9_i309;
  int32_T c9_i310;
  int32_T c9_i311;
  int32_T c9_i312;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c9_j_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_4, 3U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_5, 4U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 7U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 8U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 9U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 20);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 24);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 28);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 30);
  if (CV_EML_IF(0, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 31);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 48);
    c9_e_encStr2Arr(chartInstance, c9_dv47);
    for (c9_i307 = 0; c9_i307 < 2000; c9_i307++) {
      c9_poseBML[c9_i307] = c9_dv47[c9_i307];
    }

    c9_updateDataWrittenToVector(chartInstance, 22U);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 48);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 21U);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -48);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 32);
    if (CV_EML_IF(0, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 33);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 54);
      c9_f_encStr2Arr(chartInstance, c9_dv47);
      for (c9_i308 = 0; c9_i308 < 2000; c9_i308++) {
        c9_poseBML[c9_i308] = c9_dv47[c9_i308];
      }

      c9_updateDataWrittenToVector(chartInstance, 22U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 54);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 21U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -54);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 34);
      if (CV_EML_IF(0, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 35);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 60);
        c9_g_encStr2Arr(chartInstance, c9_dv47);
        for (c9_i309 = 0; c9_i309 < 2000; c9_i309++) {
          c9_poseBML[c9_i309] = c9_dv47[c9_i309];
        }

        c9_updateDataWrittenToVector(chartInstance, 22U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 60);
        *c9_p = 3.0;
        c9_updateDataWrittenToVector(chartInstance, 21U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -60);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 36);
        if (CV_EML_IF(0, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 37);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 66);
          c9_h_encStr2Arr(chartInstance, c9_dv47);
          for (c9_i310 = 0; c9_i310 < 2000; c9_i310++) {
            c9_poseBML[c9_i310] = c9_dv47[c9_i310];
          }

          c9_updateDataWrittenToVector(chartInstance, 22U);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 66);
          *c9_p = 3.0;
          c9_updateDataWrittenToVector(chartInstance, 21U);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -66);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 38);
          if (CV_EML_IF(0, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 39);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 72);
            c9_i_encStr2Arr(chartInstance, c9_dv47);
            for (c9_i311 = 0; c9_i311 < 2000; c9_i311++) {
              c9_poseBML[c9_i311] = c9_dv47[c9_i311];
            }

            c9_updateDataWrittenToVector(chartInstance, 22U);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 72);
            *c9_p = 3.0;
            c9_updateDataWrittenToVector(chartInstance, 21U);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -72);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 41);
            CV_EML_FCN(0, 1);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 48);
            c9_e_encStr2Arr(chartInstance, c9_dv47);
            for (c9_i312 = 0; c9_i312 < 2000; c9_i312++) {
              c9_poseBML[c9_i312] = c9_dv47[c9_i312];
            }

            c9_updateDataWrittenToVector(chartInstance, 22U);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 48);
            *c9_p = 3.0;
            c9_updateDataWrittenToVector(chartInstance, 21U);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -48);
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -41);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c9_b_isequal(SFc9_Expriment_AllInstanceStruct *chartInstance,
  real_T c9_varargin_1[2000], real_T c9_varargin_2[2000])
{
  boolean_T c9_p;
  boolean_T c9_b_p;
  int32_T c9_k;
  real_T c9_b_k;
  real_T c9_x1;
  real_T c9_x2;
  boolean_T c9_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c9_p = false;
  c9_b_p = true;
  c9_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c9_k < 2000)) {
    c9_b_k = 1.0 + (real_T)c9_k;
    c9_x1 = c9_varargin_1[(int32_T)c9_b_k - 1];
    c9_x2 = c9_varargin_2[(int32_T)c9_b_k - 1];
    c9_c_p = (c9_x1 == c9_x2);
    if (!c9_c_p) {
      c9_b_p = false;
      exitg1 = true;
    } else {
      c9_k++;
    }
  }

  if (!c9_b_p) {
  } else {
    c9_p = true;
  }

  return c9_p;
}

void sf_exported_user_c9_Expriment_All_faceTwitchTable(SimStruct *c9_S, real_T
  c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000])
{
  real_T c9_b_p;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_faceTwitchTablec9_Expriment_All(chartInstance, c9_bmlID, &c9_b_p,
    c9_poseBML);
  *c9_p = c9_b_p;
}

void sf_exported_user_c9_Expriment_All_facialExpr(SimStruct *c9_S, real_T
  c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000])
{
  real_T c9_b_p;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_facialExprc9_Expriment_All(chartInstance, c9_bmlID, &c9_b_p, c9_poseBML);
  *c9_p = c9_b_p;
}

void sf_exported_user_c9_Expriment_All_insertQueue(SimStruct *c9_S, real_T
  c9_bmls[10000], real_T c9_myBML[2000], real_T c9_newBmls[10000])
{
  int32_T c9_i313;
  real_T c9_b_bmls[10000];
  int32_T c9_i314;
  real_T c9_b_myBML[2000];
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  for (c9_i313 = 0; c9_i313 < 10000; c9_i313++) {
    c9_b_bmls[c9_i313] = c9_bmls[c9_i313];
  }

  for (c9_i314 = 0; c9_i314 < 2000; c9_i314++) {
    c9_b_myBML[c9_i314] = c9_myBML[c9_i314];
  }

  c9_insertQueuec9_Expriment_All(chartInstance, c9_b_bmls, c9_b_myBML,
    c9_newBmls);
}

void sf_exported_user_c9_Expriment_All_insertQueueLow(SimStruct *c9_S, real_T
  c9_bmls[10000], real_T c9_myBML[2000], real_T c9_newBmls[10000])
{
  int32_T c9_i315;
  real_T c9_b_bmls[10000];
  int32_T c9_i316;
  real_T c9_b_myBML[2000];
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  for (c9_i315 = 0; c9_i315 < 10000; c9_i315++) {
    c9_b_bmls[c9_i315] = c9_bmls[c9_i315];
  }

  for (c9_i316 = 0; c9_i316 < 2000; c9_i316++) {
    c9_b_myBML[c9_i316] = c9_myBML[c9_i316];
  }

  c9_insertQueueLowc9_Expriment_All(chartInstance, c9_b_bmls, c9_b_myBML,
    c9_newBmls);
}

void sf_exported_user_c9_Expriment_All_set_AU_Amount(SimStruct *c9_S, real_T
  c9_arousal, real_T c9_valence, real_T c9_inPersonality, real_T
  c9_eAmountFactor[15])
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_set_AU_Amountc9_Expriment_All(chartInstance, c9_arousal, c9_valence,
    c9_inPersonality, c9_eAmountFactor);
}

void sf_exported_user_c9_Expriment_All_smileTable(SimStruct *c9_S, real_T
  c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000])
{
  real_T c9_b_p;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_smileTablec9_Expriment_All(chartInstance, c9_bmlID, &c9_b_p, c9_poseBML);
  *c9_p = c9_b_p;
}

static const mxArray *c9_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int8_T c9_eb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int8_T c9_y;
  int8_T c9_i317;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i317, 1, 2, 0U, 0, 0U, 0);
  c9_y = c9_i317;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_x_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_secs;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int8_T c9_y;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_secs = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_secs), &c9_thisId);
  sf_mex_destroy(&c9_secs);
  *(int8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_fb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i318;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i318, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i318;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_y_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint8_T c9_gb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_subSmile, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_subSmile),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_subSmile);
  return c9_y;
}

static uint8_T c9_hb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_ab_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_tp_subSmile;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_b_tp_subSmile = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_subSmile),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_subSmile);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i319;
  real_T c9_b_inData[40];
  int32_T c9_i320;
  real_T c9_u[40];
  const mxArray *c9_y = NULL;
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i319 = 0; c9_i319 < 40; c9_i319++) {
    c9_b_inData[c9_i319] = (*(real_T (*)[40])c9_inData)[c9_i319];
  }

  for (c9_i320 = 0; c9_i320 < 40; c9_i320++) {
    c9_u[c9_i320] = c9_b_inData[c9_i320];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 40), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint32_T c9_ib_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i2, const char_T
  *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_jb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_temporalCounter_i2), &c9_thisId);
  sf_mex_destroy(&c9_b_temporalCounter_i2);
  return c9_y;
}

static uint32_T c9_jb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u1;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u1, 1, 7, 0U, 0, 0U, 0);
  c9_y = c9_u1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static const mxArray *c9_kb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T
  *c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_lb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_setSimStateSideEffectsInfo), &c9_thisId), false);
  sf_mex_destroy(&c9_b_setSimStateSideEffectsInfo);
  return c9_y;
}

static const mxArray *c9_lb_emlrt_marshallIn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  (void)c9_parentId;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), false);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_updateDataWrittenToVector(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex)
{
  (void)chartInstance;
  c9_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c9_vectorIndex, 0, 22, 1, 0)] = true;
}

static void c9_errorIfDataNotWrittenToFcn(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c9_dataNumber, c9_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c9_vectorIndex, 0, 22, 1,
    0)]);
}

static void c9_b_log10(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
  *c9_x)
{
  (void)chartInstance;
  *c9_x = muDoubleScalarLog10(*c9_x);
}

static void c9_b_ceil(SFc9_Expriment_AllInstanceStruct *chartInstance, real_T
                      *c9_x)
{
  (void)chartInstance;
  *c9_x = muDoubleScalarCeil(*c9_x);
}

static real_T c9_get_BML(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#706) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c9_BML_address)[c9_b];
}

static void c9_set_BML(SFc9_Expriment_AllInstanceStruct *chartInstance, uint32_T
  c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#706) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c9_BML_address)[c9_b] = c9_c;
}

static real_T *c9_access_BML(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c9_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#706) in the initialization routine of the chart.\n");
  }

  c9_c = *chartInstance->c9_BML_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_WIN(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#705) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_WIN_address;
}

static void c9_set_GAZE_WIN(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#705) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_WIN_address = c9_c;
}

static real_T *c9_access_GAZE_WIN(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#705) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_WIN_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c9_c;
}

static real_T c9_get_P(SFc9_Expriment_AllInstanceStruct *chartInstance, uint32_T
  c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#707) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_P_address;
}

static void c9_set_P(SFc9_Expriment_AllInstanceStruct *chartInstance, uint32_T
                     c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#707) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_P_address = c9_c;
}

static real_T *c9_access_P(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c9_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#707) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_P_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_BEFORE(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#712) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_BEFORE_address;
}

static void c9_set_STATE_BEFORE(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#712) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_BEFORE_address = c9_c;
}

static real_T *c9_access_STATE_BEFORE(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#712) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_BEFORE_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_GO(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#710) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_GO_address;
}

static void c9_set_STATE_GO(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#710) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_GO_address = c9_c;
}

static real_T *c9_access_STATE_GO(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c9_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#710) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_GO_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_READY(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#711) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_READY_address;
}

static void c9_set_STATE_READY(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#711) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_READY_address = c9_c;
}

static real_T *c9_access_STATE_READY(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#711) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_READY_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c9_c;
}

static real_T c9_get_avert(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#703) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_avert_address;
}

static void c9_set_avert(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#703) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_avert_address = c9_c;
}

static real_T *c9_access_avert(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#703) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_avert_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c9_c;
}

static real_T c9_get_bmlsL(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#725) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c9_bmlsL_address)[c9_b];
}

static void c9_set_bmlsL(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#725) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c9_bmlsL_address)[c9_b] = c9_c;
}

static real_T *c9_access_bmlsL(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c9_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#725) in the initialization routine of the chart.\n");
  }

  c9_c = *chartInstance->c9_bmlsL_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c9_c;
}

static real_T c9_get_bmlsM(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#714) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c9_bmlsM_address)[c9_b];
}

static void c9_set_bmlsM(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#714) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c9_bmlsM_address)[c9_b] = c9_c;
}

static real_T *c9_access_bmlsM(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c9_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#714) in the initialization routine of the chart.\n");
  }

  c9_c = *chartInstance->c9_bmlsM_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c9_c;
}

static real_T c9_get_emotion_amount_factor(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#720) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c9_emotion_amount_factor_address)[c9_b];
}

static void c9_set_emotion_amount_factor(SFc9_Expriment_AllInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#720) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c9_emotion_amount_factor_address)[c9_b] = c9_c;
}

static real_T *c9_access_emotion_amount_factor(SFc9_Expriment_AllInstanceStruct *
  chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c9_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#720) in the initialization routine of the chart.\n");
  }

  c9_c = *chartInstance->c9_emotion_amount_factor_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c9_c;
}

static real_T c9_get_gazing(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#704) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_gazing_address;
}

static void c9_set_gazing(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#704) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_gazing_address = c9_c;
}

static real_T *c9_access_gazing(SFc9_Expriment_AllInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#704) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_gazing_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c9_c;
}

static void init_dsm_address_info(SFc9_Expriment_AllInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c9_BML_address, &chartInstance->c9_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c9_GAZE_WIN_address, &chartInstance->c9_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c9_P_address, &chartInstance->c9_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c9_STATE_BEFORE_address,
    &chartInstance->c9_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c9_STATE_GO_address, &chartInstance->c9_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c9_STATE_READY_address, &chartInstance->c9_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c9_avert_address, &chartInstance->c9_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c9_bmlsL_address, &chartInstance->c9_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c9_bmlsM_address, &chartInstance->c9_bmlsM_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "emotion_amount_factor", (void
    **)&chartInstance->c9_emotion_amount_factor_address,
    &chartInstance->c9_emotion_amount_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c9_gazing_address, &chartInstance->c9_gazing_index);
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

void sf_c9_Expriment_All_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1767705483U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3784883491U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3090922031U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3920499198U);
}

mxArray *sf_c9_Expriment_All_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Vra5nsDVgkSpHRH0hXVKPF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(40);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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
      pr[0] = (double)(2000);
      pr[1] = (double)(5);
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
      pr[0] = (double)(2000);
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
      pr[0] = (double)(2000);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2000);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2000);
      pr[1] = (double)(5);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_Expriment_All_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_Expriment_All_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_Expriment_All(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[61],T\"gameState\",},{M[3],M[79],T\"BMLM\",},{M[3],M[175],T\"BMLl\",},{M[3],M[104],T\"au\",},{M[3],M[142],T\"au_L\",},{M[3],M[141],T\"au_i\",},{M[3],M[166],T\"emoDisp\",},{M[3],M[55],T\"fileID\",},{M[3],M[80],T\"n\",},{M[3],M[176],T\"newBmlsL\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[77],T\"newBmlsM\",},{M[3],M[228],T\"poseNum\",},{M[3],M[227],T\"poseRandFreq\",},{M[3],M[10],T\"smileN\",},{M[8],M[0],T\"is_active_c9_Expriment_All\",},{M[8],M[95],T\"is_active_subSmile\",},{M[8],M[116],T\"is_active_subFacial\",},{M[8],M[218],T\"is_active_faceTwitches\",},{M[9],M[95],T\"is_subSmile\",},{M[9],M[116],T\"is_subFacial\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[9],M[218],T\"is_faceTwitches\",},{M[11],M[39],T\"temporalCounter_i3\",S'et','os','ct'{{T\"ev\",M[197],M[1]}}},{M[11],M[39],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M[223],M[1]}}},{M[11],M[39],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x2[67 81],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 24, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_Expriment_All_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_Expriment_AllInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_Expriment_AllInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_AllMachineNumber_,
           9,
           20,
           16,
           0,
           53,
           1,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_AllMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_AllMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_AllMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(1,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(2,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(3,11,0,0,"gazing");
          _SFD_SET_DATA_PROPS(4,11,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(5,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(6,11,0,0,"P");
          _SFD_SET_DATA_PROPS(7,0,0,0,"fileID");
          _SFD_SET_DATA_PROPS(8,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(9,11,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(10,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(11,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(12,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(13,11,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(14,0,0,0,"BMLM");
          _SFD_SET_DATA_PROPS(15,0,0,0,"n");
          _SFD_SET_DATA_PROPS(16,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(17,1,1,0,"internalE");
          _SFD_SET_DATA_PROPS(18,0,0,0,"au");
          _SFD_SET_DATA_PROPS(19,11,0,0,"emotion_amount_factor");
          _SFD_SET_DATA_PROPS(20,1,1,0,"aChange");
          _SFD_SET_DATA_PROPS(21,0,0,0,"au_i");
          _SFD_SET_DATA_PROPS(22,0,0,0,"au_L");
          _SFD_SET_DATA_PROPS(23,0,0,0,"emoDisp");
          _SFD_SET_DATA_PROPS(24,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(25,0,0,0,"BMLl");
          _SFD_SET_DATA_PROPS(26,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(27,1,1,0,"emotion_amount_custom");
          _SFD_SET_DATA_PROPS(28,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(29,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(30,1,1,0,"vChange");
          _SFD_SET_DATA_PROPS(31,1,1,0,"randArray");
          _SFD_SET_DATA_PROPS(32,0,0,0,"poseRandFreq");
          _SFD_SET_DATA_PROPS(33,0,0,0,"poseNum");
          _SFD_SET_DATA_PROPS(34,8,0,0,"");
          _SFD_SET_DATA_PROPS(35,8,0,0,"");
          _SFD_SET_DATA_PROPS(36,9,0,0,"");
          _SFD_SET_DATA_PROPS(37,8,0,0,"");
          _SFD_SET_DATA_PROPS(38,8,0,0,"");
          _SFD_SET_DATA_PROPS(39,9,0,0,"");
          _SFD_SET_DATA_PROPS(40,8,0,0,"");
          _SFD_SET_DATA_PROPS(41,9,0,0,"");
          _SFD_SET_DATA_PROPS(42,9,0,0,"");
          _SFD_SET_DATA_PROPS(43,8,0,0,"");
          _SFD_SET_DATA_PROPS(44,9,0,0,"");
          _SFD_SET_DATA_PROPS(45,9,0,0,"");
          _SFD_SET_DATA_PROPS(46,9,0,0,"");
          _SFD_SET_DATA_PROPS(47,8,0,0,"");
          _SFD_SET_DATA_PROPS(48,8,0,0,"");
          _SFD_SET_DATA_PROPS(49,8,0,0,"");
          _SFD_SET_DATA_PROPS(50,8,0,0,"");
          _SFD_SET_DATA_PROPS(51,9,0,0,"");
          _SFD_SET_DATA_PROPS(52,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(10,0,1);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,1);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,14);
          _SFD_CH_SUBSTATE_INDEX(1,10);
          _SFD_CH_SUBSTATE_INDEX(2,1);
          _SFD_ST_SUBSTATE_COUNT(14,5);
          _SFD_ST_SUBSTATE_INDEX(14,0,15);
          _SFD_ST_SUBSTATE_INDEX(14,1,16);
          _SFD_ST_SUBSTATE_INDEX(14,2,17);
          _SFD_ST_SUBSTATE_INDEX(14,3,18);
          _SFD_ST_SUBSTATE_INDEX(14,4,19);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(10,3);
          _SFD_ST_SUBSTATE_INDEX(10,0,11);
          _SFD_ST_SUBSTATE_INDEX(10,1,12);
          _SFD_ST_SUBSTATE_INDEX(10,2,13);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(1,3,1,1,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(10,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,5,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(6,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"insertQueuec9_Expriment_All",0,-1,565);
        _SFD_CV_INIT_EML_IF(6,1,0,126,151,-1,-2);
        _SFD_CV_INIT_EML_IF(6,1,1,296,307,-1,546);
        _SFD_CV_INIT_EML_FOR(6,1,0,106,118,291);
        _SFD_CV_INIT_EML(7,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"insertQueueLowc9_Expriment_All",0,-1,568);
        _SFD_CV_INIT_EML_IF(7,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(7,1,1,299,310,-1,549);
        _SFD_CV_INIT_EML_FOR(7,1,0,109,121,294);
        _SFD_CV_INIT_EML(9,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(9,0,"smileTablec9_Expriment_All",0,-1,404);
        _SFD_CV_INIT_EML_FCN(9,1,"aFcnTruthTableAction_1",404,-1,699);
        _SFD_CV_INIT_EML_FCN(9,2,"aFcnTruthTableAction_2",699,-1,891);
        _SFD_CV_INIT_EML_FCN(9,3,"aFcnTruthTableAction_3",891,-1,1190);
        _SFD_CV_INIT_EML_IF(9,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(9,1,1,289,323,354,402);
        _SFD_CV_INIT_EML(5,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"facialExprc9_Expriment_All",0,-1,404);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",404,-1,707);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",707,-1,899);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",899,-1,1198);
        _SFD_CV_INIT_EML_IF(5,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(5,1,1,289,323,354,402);
        _SFD_CV_INIT_EML(8,1,1,1,0,0,0,1,0,2,1);
        _SFD_CV_INIT_EML_FCN(8,0,"set_AU_Amountc9_Expriment_All",0,-1,3034);
        _SFD_CV_INIT_EML_IF(8,1,0,2901,2941,-1,3024);
        _SFD_CV_INIT_EML_FOR(8,1,0,422,433,3032);

        {
          static int condStart[] = { 2904, 2924 };

          static int condEnd[] = { 2920, 2940 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(8,1,0,2904,2940,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(0,1,6,5,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"faceTwitchTablec9_Expriment_All",0,-1,867);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",867,-1,1046);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1046,-1,1226);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1226,-1,1432);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1432,-1,1638);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1638,-1,1813);
        _SFD_CV_INIT_EML_IF(0,1,0,496,526,557,865);
        _SFD_CV_INIT_EML_IF(0,1,1,557,591,622,865);
        _SFD_CV_INIT_EML_IF(0,1,2,622,656,687,865);
        _SFD_CV_INIT_EML_IF(0,1,3,687,721,752,865);
        _SFD_CV_INIT_EML_IF(0,1,4,752,786,817,865);
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
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,0,26,0,26);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,0,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,66,1,48);

        {
          static int condStart[] = { 1, 16, 40 };

          static int condEnd[] = { 15, 39, 66 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,66,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,0,26,0,26);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,0,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(14,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 17, 34 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(14,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,24,0,24);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2000;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)
            c9_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 15;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_m_sf_marshallOut,(MexInFcnForType)
            c9_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 40;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_rb_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 15;
          _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_m_sf_marshallOut,(MexInFcnForType)
            c9_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(36,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(37,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(38,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(39,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(40,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(41,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(42,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(43,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(44,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(45,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(46,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(47,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(48,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(49,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(50,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(51,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(52,(void *)(NULL));

        {
          real_T *c9_isSmiling;
          real_T *c9_gameState;
          real_T *c9_personality;
          real_T *c9_internalE;
          boolean_T *c9_aChange;
          real_T *c9_emotion_amount_custom;
          real_T *c9_inA;
          real_T *c9_inV;
          boolean_T *c9_vChange;
          real_T (*c9_randArray)[40];
          c9_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S,
            8);
          c9_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c9_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c9_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c9_emotion_amount_custom = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 4);
          c9_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c9_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c9_smileN);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_avert_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c9_BML_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_P_address);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c9_fileID);
          _SFD_SET_DATA_VALUE_PTR(8U, c9_gameState);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c9_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c9_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c9_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c9_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(13U, *chartInstance->c9_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c9_BMLM);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c9_n);
          _SFD_SET_DATA_VALUE_PTR(16U, c9_personality);
          _SFD_SET_DATA_VALUE_PTR(17U, c9_internalE);
          _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance->c9_au);
          _SFD_SET_DATA_VALUE_PTR(19U,
            *chartInstance->c9_emotion_amount_factor_address);
          _SFD_SET_DATA_VALUE_PTR(20U, c9_aChange);
          _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c9_au_i);
          _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c9_au_L);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c9_emoDisp);
          _SFD_SET_DATA_VALUE_PTR(24U, *chartInstance->c9_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c9_BMLl);
          _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c9_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(27U, c9_emotion_amount_custom);
          _SFD_SET_DATA_VALUE_PTR(28U, c9_inA);
          _SFD_SET_DATA_VALUE_PTR(29U, c9_inV);
          _SFD_SET_DATA_VALUE_PTR(30U, c9_vChange);
          _SFD_SET_DATA_VALUE_PTR(31U, *c9_randArray);
          _SFD_SET_DATA_VALUE_PTR(32U, &chartInstance->c9_poseRandFreq);
          _SFD_SET_DATA_VALUE_PTR(33U, &chartInstance->c9_poseNum);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_AllMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "gRidHTfiv0iwdE1L2enrJH";
}

static void sf_opaque_initialize_c9_Expriment_All(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_Expriment_AllInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*)
    chartInstanceVar);
  initialize_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_Expriment_All(void *chartInstanceVar)
{
  enable_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_Expriment_All(void *chartInstanceVar)
{
  disable_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_Expriment_All(void *chartInstanceVar)
{
  sf_gateway_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_Expriment_All(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_Expriment_All
    ((SFc9_Expriment_AllInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_Expriment_All();/* state var info */
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

extern void sf_internal_set_sim_state_c9_Expriment_All(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c9_Expriment_All();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_Expriment_All(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c9_Expriment_All(SimStruct* S, const mxArray
  *st)
{
}

static void sf_opaque_terminate_c9_Expriment_All(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_Expriment_AllInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_All_optimization_info();
    }

    finalize_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*)
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
  initSimStructsc9_Expriment_All((SFc9_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_Expriment_All(SimStruct *S)
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
    initialize_params_c9_Expriment_All((SFc9_Expriment_AllInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_Expriment_All(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_All_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
    }

    ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2619963220U));
  ssSetChecksum1(S,(2118888113U));
  ssSetChecksum2(S,(2274934904U));
  ssSetChecksum3(S,(58360335U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_Expriment_All(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_Expriment_All(SimStruct *S)
{
  SFc9_Expriment_AllInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_Expriment_AllInstanceStruct *)utMalloc(sizeof
    (SFc9_Expriment_AllInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_Expriment_AllInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_Expriment_All;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_Expriment_All;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_Expriment_All;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_Expriment_All;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_Expriment_All;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_Expriment_All;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_Expriment_All;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_Expriment_All;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_Expriment_All;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_Expriment_All;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_Expriment_All;
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

void c9_Expriment_All_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_Expriment_All(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_Expriment_All(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_Expriment_All(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_Expriment_All_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
