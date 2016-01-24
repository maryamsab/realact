/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_PointUser_AnTS_sfun.h"
#include "c3_ARP_02_PointUser_AnTS.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_PointUser_AnTS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_p                        ((uint8_T)1U)
#define c3_IN_stateCalculateUserStatus ((uint8_T)1U)
#define c3_IN_stateIdle                ((uint8_T)2U)
#define c3_IN_statePointLeft           ((uint8_T)3U)
#define c3_IN_statePointRight          ((uint8_T)4U)
#define c3_IN_stateTarget              ((uint8_T)5U)
#define c3_IN_stateFacialExpression    ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c3_c_debug_family_names[4] = { "mystr", "nargin", "nargout",
  "arrBML" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c3_f_debug_family_names[4] = { "mystr", "nargin", "nargout",
  "arrBML" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c3_i_debug_family_names[5] = { "r", "mystr", "nargin",
  "nargout", "arrBML" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c3_l_debug_family_names[4] = { "mystr", "nargin", "nargout",
  "arrBML" };

static const char * c3_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_n_debug_family_names[13] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9", "nargin", "nargout",
  "E", "AU" };

static const char * c3_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c3_p_debug_family_names[12] = { "str1", "i", "AU", "temp",
  "temp2", "str2", "n", "mystr", "nargin", "nargout", "arrAU", "arrBML" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[3];

/* Function Declarations */
static void initialize_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void initialize_params_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void enable_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void disable_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void set_sim_state_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void finalize_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void sf_gateway_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void initSimStructsc3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c3_p(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c3_enter_atomic_stateIdle(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance);
static void c3_stateCalculateUserStatus(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance);
static void c3_enter_atomic_statePointLeft
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c3_encStr2Arr(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, char_T c3_mystr[88], real_T c3_myarr256[256]);
static real_T c3_rand(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c3_eml_rand_mt19937ar(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_d_state[625]);
static void c3_twister_state_vector(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625]);
static void c3_b_eml_rand_mt19937ar(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_d_state[625], uint32_T c3_e_state[625], real_T
  *c3_r);
static void c3_eml_error(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance);
static void c3_cmdBML_AUs(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, real_T c3_arrAU_data[], int32_T c3_arrAU_sizes[2], real_T
  c3_arrBML[256]);
static void c3_eml_scalar_eg(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance);
static void c3_b_encStr2Arr(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, char_T c3_mystr_data[], int32_T c3_mystr_sizes[2], real_T
  c3_myarr256[256]);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static void c3_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[85]);
static void c3_b_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[85]);
static void c3_c_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[88]);
static void c3_d_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[88]);
static void c3_e_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[90]);
static void c3_f_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[90]);
static void c3_g_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[92]);
static void c3_h_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[92]);
static void c3_i_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_strcat, const char_T *c3_identifier, char_T
  c3_y_data[], int32_T c3_y_sizes[2]);
static void c3_j_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2]);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_k_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_l_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_m_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_n_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[85]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_o_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[88]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_p_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[90]);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_q_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[92]);
static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T c3_inData_sizes[2]);
static void c3_r_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T c3_y_sizes[2]);
static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  c3_outData_sizes[2]);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_s_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, char_T
  c3_inData_data[], int32_T c3_inData_sizes[2]);
static void c3_t_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2]);
static void c3_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, char_T c3_outData_data[], int32_T
  c3_outData_sizes[2]);
static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T *c3_inData_sizes);
static void c3_u_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T *c3_y_sizes);
static void c3_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  *c3_outData_sizes);
static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static void c3_b_info_helper(const mxArray **c3_info);
static void c3_sendBML(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance,
  real_T c3_arg[256]);
static void c3_EAU(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance,
                   real_T c3_E, real_T c3_AU_data[], int32_T c3_AU_sizes[2]);
static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_v_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_w_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_x_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_p, const char_T *c3_identifier);
static uint8_T c3_y_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_ab_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint32_T c3_bb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_b_method, const char_T *c3_identifier);
static uint32_T c3_cb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint32_T c3_db_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier);
static uint32_T c3_eb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_fb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[625]);
static void c3_gb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[625]);
static void c3_hb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[2]);
static void c3_ib_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[2]);
static const mxArray *c3_jb_emlrt_marshallIn
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_kb_emlrt_marshallIn
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber);
static void c3_b_twister_state_vector(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed);
static real_T c3_c_eml_rand_mt19937ar(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_d_state[625]);
static void init_dsm_address_info(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_method_not_empty = false;
  chartInstance->c3_state_not_empty = false;
  chartInstance->c3_b_state_not_empty = false;
  chartInstance->c3_c_state_not_empty = false;
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_p = 0U;
  chartInstance->c3_is_active_1 = 0U;
  chartInstance->c3_is_1 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_1 = 0U;
  chartInstance->c3_tp_stateCalculateUserStatus = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateIdle = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_statePointLeft = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_statePointRight = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateTarget = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_is_active_2 = 0U;
  chartInstance->c3_is_2 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_2 = 0U;
  chartInstance->c3_tp_stateFacialExpression = 0U;
  chartInstance->c3_temporalCounter_i2 = 0U;
  chartInstance->c3_is_active_c3_ARP_02_PointUser_AnTS = 0U;
  chartInstance->c3_is_c3_ARP_02_PointUser_AnTS = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void disable_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

static void c3_update_debugger_state_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_ARP_02_PointUser_AnTS == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_PointUser_AnTS == c3_IN_p) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_1 == c3_IN_stateIdle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_1 == c3_IN_stateCalculateUserStatus) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_1 == c3_IN_statePointRight) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_1 == c3_IN_statePointLeft) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_1 == c3_IN_stateTarget) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_2 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_2 == c3_IN_stateFacialExpression) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint32_T c3_c_hoistedGlobal;
  uint32_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint32_T c3_d_hoistedGlobal;
  uint32_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  int32_T c3_i0;
  uint32_T c3_e_u[625];
  const mxArray *c3_f_y = NULL;
  int32_T c3_i1;
  uint32_T c3_f_u[2];
  const mxArray *c3_g_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  uint8_T c3_i_hoistedGlobal;
  uint8_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  uint8_T c3_j_hoistedGlobal;
  uint8_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  uint8_T c3_k_hoistedGlobal;
  uint8_T c3_m_u;
  const mxArray *c3_n_y = NULL;
  uint8_T c3_l_hoistedGlobal;
  uint8_T c3_n_u;
  const mxArray *c3_o_y = NULL;
  real_T *c3_agentState;
  c3_agentState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(14, 1), false);
  c3_hoistedGlobal = *c3_agentState;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_round_count;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_method;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  if (!chartInstance->c3_method_not_empty) {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_state;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  if (!chartInstance->c3_state_not_empty) {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 3, c3_e_y);
  for (c3_i0 = 0; c3_i0 < 625; c3_i0++) {
    c3_e_u[c3_i0] = chartInstance->c3_c_state[c3_i0];
  }

  c3_f_y = NULL;
  if (!chartInstance->c3_c_state_not_empty) {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_e_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c3_y, 4, c3_f_y);
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    c3_f_u[c3_i1] = chartInstance->c3_b_state[c3_i1];
  }

  c3_g_y = NULL;
  if (!chartInstance->c3_b_state_not_empty) {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_f_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_ARP_02_PointUser_AnTS;
  c3_g_u = c3_e_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_active_1;
  c3_h_u = c3_f_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_active_2;
  c3_i_u = c3_g_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_c3_ARP_02_PointUser_AnTS;
  c3_j_u = c3_h_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_i_hoistedGlobal = chartInstance->c3_is_1;
  c3_k_u = c3_i_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_j_hoistedGlobal = chartInstance->c3_is_2;
  c3_l_u = c3_j_hoistedGlobal;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_k_hoistedGlobal = chartInstance->c3_temporalCounter_i2;
  c3_m_u = c3_k_hoistedGlobal;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_l_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_n_u = c3_l_hoistedGlobal;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  uint32_T c3_uv0[625];
  int32_T c3_i2;
  uint32_T c3_uv1[2];
  int32_T c3_i3;
  real_T *c3_agentState;
  c3_agentState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_agentState = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "agentState");
  chartInstance->c3_round_count = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "round_count");
  chartInstance->c3_method = c3_bb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "method");
  chartInstance->c3_state = c3_db_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "state");
  c3_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
    "state", c3_uv0);
  for (c3_i2 = 0; c3_i2 < 625; c3_i2++) {
    chartInstance->c3_c_state[c3_i2] = c3_uv0[c3_i2];
  }

  c3_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
    "state", c3_uv1);
  for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
    chartInstance->c3_b_state[c3_i3] = c3_uv1[c3_i3];
  }

  chartInstance->c3_is_active_c3_ARP_02_PointUser_AnTS = c3_x_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
     "is_active_c3_ARP_02_PointUser_AnTS");
  chartInstance->c3_is_active_1 = c3_x_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 7)), "is_active_1");
  chartInstance->c3_is_active_2 = c3_x_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 8)), "is_active_2");
  chartInstance->c3_is_c3_ARP_02_PointUser_AnTS = c3_x_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)),
     "is_c3_ARP_02_PointUser_AnTS");
  chartInstance->c3_is_1 = c3_x_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 10)), "is_1");
  chartInstance->c3_is_2 = c3_x_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "is_2");
  chartInstance->c3_temporalCounter_i2 = c3_x_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 12)), "temporalCounter_i2");
  chartInstance->c3_temporalCounter_i1 = c3_x_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 13)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 14)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_ARP_02_PointUser_AnTS(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_ARP_02_PointUser_AnTS == c3_IN_p) {
      chartInstance->c3_tp_p = 1U;
    } else {
      chartInstance->c3_tp_p = 0U;
    }

    if (chartInstance->c3_is_active_1 == 1U) {
      chartInstance->c3_tp_1 = 1U;
    } else {
      chartInstance->c3_tp_1 = 0U;
    }

    if (chartInstance->c3_is_1 == c3_IN_stateCalculateUserStatus) {
      chartInstance->c3_tp_stateCalculateUserStatus = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateCalculateUserStatus = 0U;
    }

    if (chartInstance->c3_is_1 == c3_IN_stateIdle) {
      chartInstance->c3_tp_stateIdle = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateIdle = 0U;
    }

    if (chartInstance->c3_is_1 == c3_IN_statePointLeft) {
      chartInstance->c3_tp_statePointLeft = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_statePointLeft = 0U;
    }

    if (chartInstance->c3_is_1 == c3_IN_statePointRight) {
      chartInstance->c3_tp_statePointRight = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_statePointRight = 0U;
    }

    if (chartInstance->c3_is_1 == c3_IN_stateTarget) {
      chartInstance->c3_tp_stateTarget = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateTarget = 0U;
    }

    if (chartInstance->c3_is_active_2 == 1U) {
      chartInstance->c3_tp_2 = 1U;
    } else {
      chartInstance->c3_tp_2 = 0U;
    }

    if (chartInstance->c3_is_2 == c3_IN_stateFacialExpression) {
      chartInstance->c3_tp_stateFacialExpression = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c3_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateFacialExpression = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_hoistedGlobal;
  int32_T c3_tmp_sizes[2];
  real_T c3_tmp_data[7];
  int32_T c3_u_sizes[2];
  int32_T c3_u;
  int32_T c3_b_u;
  int32_T c3_loop_ub;
  int32_T c3_i4;
  real_T c3_u_data[7];
  const mxArray *c3_y = NULL;
  int32_T c3_b_tmp_sizes[2];
  real_T c3_b_tmp_data[7];
  int32_T c3_c_tmp_sizes[2];
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_b_loop_ub;
  int32_T c3_i7;
  real_T c3_c_tmp_data[7];
  real_T c3_dv0[256];
  int32_T c3_i8;
  real_T c3_dv1[256];
  real_T *c3_step;
  real_T *c3_xd;
  real_T *c3_internalE;
  real_T *c3_agentState;
  c3_agentState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_xd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_ARP_02_PointUser_AnTS(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_round_count, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_step, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_xd, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_internalE, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_agentState, 4U);
  if (chartInstance->c3_temporalCounter_i1 < 3U) {
    chartInstance->c3_temporalCounter_i1++;
  }

  if (chartInstance->c3_temporalCounter_i2 < 3U) {
    chartInstance->c3_temporalCounter_i2++;
  }

  chartInstance->c3_sfEvent = c3_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_ARP_02_PointUser_AnTS == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_ARP_02_PointUser_AnTS = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_ARP_02_PointUser_AnTS = c3_IN_p;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_p = 1U;
    chartInstance->c3_is_active_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_1 = c3_IN_stateIdle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i1 = 0U;
    chartInstance->c3_tp_stateIdle = 1U;
    c3_enter_atomic_stateIdle(chartInstance);
    chartInstance->c3_is_active_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_2 = c3_IN_stateFacialExpression;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i2 = 0U;
    chartInstance->c3_tp_stateFacialExpression = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_m_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    sf_mex_printf("%s =\\n", "ans");
    c3_hoistedGlobal = *c3_internalE;
    c3_EAU(chartInstance, c3_hoistedGlobal, c3_tmp_data, c3_tmp_sizes);
    c3_u_sizes[0] = 1;
    c3_u_sizes[1] = c3_tmp_sizes[1];
    c3_u = c3_u_sizes[0];
    c3_b_u = c3_u_sizes[1];
    c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
    for (c3_i4 = 0; c3_i4 <= c3_loop_ub; c3_i4++) {
      c3_u_data[c3_i4] = c3_tmp_data[c3_i4];
    }

    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 2,
      c3_u_sizes[0], c3_u_sizes[1]), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
    c3_EAU(chartInstance, *c3_internalE, c3_b_tmp_data, c3_b_tmp_sizes);
    c3_c_tmp_sizes[0] = 1;
    c3_c_tmp_sizes[1] = c3_b_tmp_sizes[1];
    c3_i5 = c3_c_tmp_sizes[0];
    c3_i6 = c3_c_tmp_sizes[1];
    c3_b_loop_ub = c3_b_tmp_sizes[0] * c3_b_tmp_sizes[1] - 1;
    for (c3_i7 = 0; c3_i7 <= c3_b_loop_ub; c3_i7++) {
      c3_c_tmp_data[c3_i7] = c3_b_tmp_data[c3_i7];
    }

    c3_cmdBML_AUs(chartInstance, c3_c_tmp_data, c3_c_tmp_sizes, c3_dv0);
    for (c3_i8 = 0; c3_i8 < 256; c3_i8++) {
      c3_dv1[c3_i8] = c3_dv0[c3_i8];
    }

    c3_sendBML(chartInstance, c3_dv1);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    c3_p(chartInstance);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_PointUser_AnTSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_ARP_02_PointUser_AnTS
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_p(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_e_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_hoistedGlobal;
  int32_T c3_tmp_sizes[2];
  real_T c3_tmp_data[7];
  int32_T c3_u_sizes[2];
  int32_T c3_u;
  int32_T c3_b_u;
  int32_T c3_loop_ub;
  int32_T c3_i9;
  real_T c3_u_data[7];
  const mxArray *c3_y = NULL;
  int32_T c3_b_tmp_sizes[2];
  real_T c3_b_tmp_data[7];
  int32_T c3_c_tmp_sizes[2];
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_b_loop_ub;
  int32_T c3_i12;
  real_T c3_c_tmp_data[7];
  real_T c3_dv2[256];
  int32_T c3_i13;
  real_T c3_dv3[256];
  real_T *c3_internalE;
  c3_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_1) {
   case c3_IN_stateCalculateUserStatus:
    CV_STATE_EVAL(2, 0, 1);
    c3_stateCalculateUserStatus(chartInstance);
    break;

   case c3_IN_stateIdle:
    CV_STATE_EVAL(2, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_l_sf_marshallOut,
      c3_l_sf_marshallIn);
    c3_out = CV_EML_IF(2, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                       (chartInstance->c3_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateIdle = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_1 = c3_IN_stateCalculateUserStatus;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateCalculateUserStatus = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_statePointLeft:
    CV_STATE_EVAL(2, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_l_sf_marshallOut,
      c3_l_sf_marshallIn);
    c3_b_out = CV_EML_IF(3, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                         (chartInstance->c3_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_statePointLeft = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_1 = c3_IN_stateIdle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateIdle = 1U;
      c3_enter_atomic_stateIdle(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_statePointRight:
    CV_STATE_EVAL(2, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_l_sf_marshallOut,
      c3_l_sf_marshallIn);
    c3_c_out = CV_EML_IF(4, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                         (chartInstance->c3_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_statePointRight = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_1 = c3_IN_stateIdle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateIdle = 1U;
      c3_enter_atomic_stateIdle(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_stateTarget:
    CV_STATE_EVAL(2, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_l_sf_marshallOut,
      c3_l_sf_marshallIn);
    c3_d_out = CV_EML_IF(1, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                         (chartInstance->c3_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateTarget = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_1 = c3_IN_stateIdle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateIdle = 1U;
      c3_enter_atomic_stateIdle(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(2, 0, 0);
    chartInstance->c3_is_1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_x_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_l_sf_marshallOut,
    c3_l_sf_marshallIn);
  c3_e_out = CV_EML_IF(9, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                       (chartInstance->c3_temporalCounter_i2 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_e_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateFacialExpression = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_2 = c3_IN_stateFacialExpression;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i2 = 0U;
    chartInstance->c3_tp_stateFacialExpression = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_m_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    sf_mex_printf("%s =\\n", "ans");
    c3_hoistedGlobal = *c3_internalE;
    c3_EAU(chartInstance, c3_hoistedGlobal, c3_tmp_data, c3_tmp_sizes);
    c3_u_sizes[0] = 1;
    c3_u_sizes[1] = c3_tmp_sizes[1];
    c3_u = c3_u_sizes[0];
    c3_b_u = c3_u_sizes[1];
    c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
    for (c3_i9 = 0; c3_i9 <= c3_loop_ub; c3_i9++) {
      c3_u_data[c3_i9] = c3_tmp_data[c3_i9];
    }

    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 2,
      c3_u_sizes[0], c3_u_sizes[1]), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
    c3_EAU(chartInstance, *c3_internalE, c3_b_tmp_data, c3_b_tmp_sizes);
    c3_c_tmp_sizes[0] = 1;
    c3_c_tmp_sizes[1] = c3_b_tmp_sizes[1];
    c3_i10 = c3_c_tmp_sizes[0];
    c3_i11 = c3_c_tmp_sizes[1];
    c3_b_loop_ub = c3_b_tmp_sizes[0] * c3_b_tmp_sizes[1] - 1;
    for (c3_i12 = 0; c3_i12 <= c3_b_loop_ub; c3_i12++) {
      c3_c_tmp_data[c3_i12] = c3_b_tmp_data[c3_i12];
    }

    c3_cmdBML_AUs(chartInstance, c3_c_tmp_data, c3_c_tmp_sizes, c3_dv2);
    for (c3_i13 = 0; c3_i13 < 256; c3_i13++) {
      c3_dv3[c3_i13] = c3_dv2[c3_i13];
    }

    c3_sendBML(chartInstance, c3_dv3);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_stateIdle(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[4];
  char_T c3_mystr[85];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_arrBML[256];
  int32_T c3_i14;
  int32_T c3_i15;
  static char_T c3_cv0[89] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'b', 'o', 'd', 'y',
    ' ', 'p', 'o', 's', 't', 'u', 'r', 'e', '=', '\\', '\"', 'C', 'h', 'r', 'B',
    'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd',
    'l', 'e', '0', '2', '\\', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  char_T c3_u[89];
  const mxArray *c3_y = NULL;
  char_T c3_cv1[85];
  int32_T c3_i16;
  int32_T c3_i17;
  char_T c3_b_mystr[85];
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[85];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  real_T c3_b_arrBML[256];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_c_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mystr, 0U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i14 = 0; c3_i14 < 85; c3_i14++) {
    c3_mystr[c3_i14] = ' ';
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i15 = 0; c3_i15 < 89; c3_i15++) {
    c3_u[c3_i15] = c3_cv0[c3_i15];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 89), false);
  c3_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U, 14, c3_y),
                      "sprintf", c3_cv1);
  for (c3_i16 = 0; c3_i16 < 85; c3_i16++) {
    c3_mystr[c3_i16] = c3_cv1[c3_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 12);
  for (c3_i17 = 0; c3_i17 < 85; c3_i17++) {
    c3_b_mystr[c3_i17] = c3_mystr[c3_i17];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_b_debug_family_names,
    c3_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arr, 1U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_mystr, 7U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 6);
  for (c3_i18 = 0; c3_i18 < 85; c3_i18++) {
    c3_arr[c3_i18] = (real_T)c3_b_mystr[c3_i18];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 7);
  c3_ss = 85.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 171.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 9);
  for (c3_i19 = 0; c3_i19 < 256; c3_i19++) {
    c3_tt[c3_i19] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 10);
  for (c3_i20 = 0; c3_i20 < 85; c3_i20++) {
    c3_tt[c3_i20] = c3_arr[c3_i20];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 11);
  for (c3_i21 = 0; c3_i21 < 256; c3_i21++) {
    c3_arrBML[c3_i21] = c3_tt[c3_i21];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i22 = 0; c3_i22 < 256; c3_i22++) {
    c3_b_arrBML[c3_i22] = c3_arrBML[c3_i22];
  }

  c3_sendBML(chartInstance, c3_b_arrBML);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_stateCalculateUserStatus(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[4];
  char_T c3_mystr[88];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  real_T c3_arrBML[256];
  int32_T c3_i23;
  int32_T c3_i24;
  static char_T c3_cv2[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm',
    'a', 't', 'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\\', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'P', 'o',
    'i', 'n', 't', 'R', 't', '0', '1', '\\', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  char_T c3_u[92];
  const mxArray *c3_y = NULL;
  char_T c3_cv3[88];
  int32_T c3_i25;
  int32_T c3_i26;
  char_T c3_b_mystr[88];
  real_T c3_dv4[256];
  int32_T c3_i27;
  int32_T c3_i28;
  real_T c3_b_arrBML[256];
  real_T c3_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  char_T c3_c_mystr[92];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  real_T c3_c_arrBML[256];
  int32_T c3_i29;
  int32_T c3_i30;
  static char_T c3_cv4[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm',
    'a', 't', 'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\\', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 't',
    'o', 'p', 'B', 't', '0', '2', '\\', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  char_T c3_c_u[91];
  const mxArray *c3_c_y = NULL;
  char_T c3_cv5[92];
  int32_T c3_i31;
  int32_T c3_i32;
  char_T c3_d_mystr[92];
  uint32_T c3_d_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[92];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_h_nargin = 1.0;
  real_T c3_h_nargout = 1.0;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  real_T c3_d_arrBML[256];
  real_T c3_b_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_xd;
  real_T *c3_agentState;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c3_agentState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_xd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_l_sf_marshallOut,
    c3_l_sf_marshallIn);
  guard3 = false;
  if (CV_EML_COND(6, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                  (chartInstance->c3_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(6, 0, 1, *c3_xd > 0.0)) {
      CV_EML_MCDC(6, 0, 0, true);
      CV_EML_IF(6, 0, 0, true);
      c3_out = true;
    } else {
      guard3 = true;
    }
  } else {
    guard3 = true;
  }

  if (guard3 == true) {
    CV_EML_MCDC(6, 0, 0, false);
    CV_EML_IF(6, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateCalculateUserStatus = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_1 = c3_IN_statePointLeft;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i1 = 0U;
    chartInstance->c3_tp_statePointLeft = 1U;
    c3_enter_atomic_statePointLeft(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_l_sf_marshallOut,
      c3_l_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(5, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                    (chartInstance->c3_temporalCounter_i1 >= 1))) {
      if (CV_EML_COND(5, 0, 1, *c3_xd <= 0.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c3_b_out = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateCalculateUserStatus = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_1 = c3_IN_statePointRight;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_statePointRight = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_f_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mystr, 0U, c3_e_sf_marshallOut,
        c3_e_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 2U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 3U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      CV_SCRIPT_FCN(2, 0);
      _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 2);
      _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 10);
      for (c3_i23 = 0; c3_i23 < 88; c3_i23++) {
        c3_mystr[c3_i23] = ' ';
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 11);
      for (c3_i24 = 0; c3_i24 < 92; c3_i24++) {
        c3_u[c3_i24] = c3_cv2[c3_i24];
      }

      c3_y = NULL;
      sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 92),
                    false);
      c3_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U, 14,
        c3_y), "sprintf", c3_cv3);
      for (c3_i25 = 0; c3_i25 < 88; c3_i25++) {
        c3_mystr[c3_i25] = c3_cv3[c3_i25];
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 12);
      for (c3_i26 = 0; c3_i26 < 88; c3_i26++) {
        c3_b_mystr[c3_i26] = c3_mystr[c3_i26];
      }

      c3_encStr2Arr(chartInstance, c3_b_mystr, c3_dv4);
      for (c3_i27 = 0; c3_i27 < 256; c3_i27++) {
        c3_arrBML[c3_i27] = c3_dv4[c3_i27];
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, -12);
      _SFD_SYMBOL_SCOPE_POP();
      for (c3_i28 = 0; c3_i28 < 256; c3_i28++) {
        c3_b_arrBML[c3_i28] = c3_arrBML[c3_i28];
      }

      c3_sendBML(chartInstance, c3_b_arrBML);
      *c3_agentState = 1.0;
      c3_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(*c3_agentState, 4U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 4U);
      sf_mex_printf("%s =\\n", "agentState");
      c3_hoistedGlobal = *c3_agentState;
      c3_b_u = c3_hoistedGlobal;
      c3_b_y = NULL;
      sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_b_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_w_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_l_sf_marshallOut,
        c3_l_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(7, 0, 0, (chartInstance->c3_sfEvent == c3_event_secs) &&
                      (chartInstance->c3_temporalCounter_i1 >= 1))) {
        if (CV_EML_COND(7, 0, 1, *c3_xd == 0.0)) {
          CV_EML_MCDC(7, 0, 0, true);
          CV_EML_IF(7, 0, 0, true);
          c3_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(7, 0, 0, false);
        CV_EML_IF(7, 0, 0, false);
        c3_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateCalculateUserStatus = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_1 = c3_IN_stateTarget;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateTarget = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_l_debug_family_names,
          c3_c_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_c_mystr, 0U, c3_i_sf_marshallOut,
          c3_i_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 1U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 2U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_c_arrBML, 3U,
          c3_b_sf_marshallOut, c3_b_sf_marshallIn);
        CV_SCRIPT_FCN(4, 0);
        _SFD_SCRIPT_CALL(4U, chartInstance->c3_sfEvent, 2);
        _SFD_SCRIPT_CALL(4U, chartInstance->c3_sfEvent, 10);
        for (c3_i29 = 0; c3_i29 < 92; c3_i29++) {
          c3_c_mystr[c3_i29] = ' ';
        }

        _SFD_SCRIPT_CALL(4U, chartInstance->c3_sfEvent, 11);
        for (c3_i30 = 0; c3_i30 < 91; c3_i30++) {
          c3_c_u[c3_i30] = c3_cv4[c3_i30];
        }

        c3_c_y = NULL;
        sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_c_u, 10, 0U, 1U, 0U, 2, 1,
          91), false);
        c3_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U,
          14, c3_c_y), "sprintf", c3_cv5);
        for (c3_i31 = 0; c3_i31 < 92; c3_i31++) {
          c3_c_mystr[c3_i31] = c3_cv5[c3_i31];
        }

        _SFD_SCRIPT_CALL(4U, chartInstance->c3_sfEvent, 12);
        for (c3_i32 = 0; c3_i32 < 92; c3_i32++) {
          c3_d_mystr[c3_i32] = c3_c_mystr[c3_i32];
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_k_debug_family_names,
          c3_d_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arr, 1U, c3_j_sf_marshallOut,
          c3_j_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 5U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 6U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_d_mystr, 7U, c3_i_sf_marshallOut,
          c3_i_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_c_arrBML, 8U,
          c3_b_sf_marshallOut, c3_b_sf_marshallIn);
        CV_SCRIPT_FCN(1, 0);
        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 3);
        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 4);
        c3_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 6);
        for (c3_i33 = 0; c3_i33 < 92; c3_i33++) {
          c3_arr[c3_i33] = (real_T)c3_d_mystr[c3_i33];
        }

        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 7);
        c3_ss = 92.0;
        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 8);
        c3_padsize = 164.0;
        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 9);
        for (c3_i34 = 0; c3_i34 < 256; c3_i34++) {
          c3_tt[c3_i34] = 0.0;
        }

        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 10);
        for (c3_i35 = 0; c3_i35 < 92; c3_i35++) {
          c3_tt[c3_i35] = c3_arr[c3_i35];
        }

        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 11);
        for (c3_i36 = 0; c3_i36 < 256; c3_i36++) {
          c3_c_arrBML[c3_i36] = c3_tt[c3_i36];
        }

        _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_SCRIPT_CALL(4U, chartInstance->c3_sfEvent, -12);
        _SFD_SYMBOL_SCOPE_POP();
        for (c3_i37 = 0; c3_i37 < 256; c3_i37++) {
          c3_d_arrBML[c3_i37] = c3_c_arrBML[c3_i37];
        }

        c3_sendBML(chartInstance, c3_d_arrBML);
        *c3_agentState = 3.0;
        c3_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c3_agentState, 4U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 4U);
        sf_mex_printf("%s =\\n", "agentState");
        c3_b_hoistedGlobal = *c3_agentState;
        c3_d_u = c3_b_hoistedGlobal;
        c3_d_y = NULL;
        sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_d_y);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c3_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_statePointLeft
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[5];
  real_T c3_r;
  char_T c3_mystr[90];
  char_T c3_b_mystr[88];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_arrBML[256];
  real_T c3_x;
  real_T c3_b_x;
  int32_T c3_i38;
  int32_T c3_i39;
  static char_T c3_cv6[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm',
    'a', 't', 'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\\', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'P', 'o',
    'i', 'n', 't', 'L', 'f', '0', '1', '\\', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  char_T c3_u[92];
  const mxArray *c3_y = NULL;
  char_T c3_cv7[88];
  int32_T c3_i40;
  int32_T c3_i41;
  char_T c3_c_mystr[88];
  real_T c3_dv5[256];
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  static char_T c3_cv8[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm',
    'a', 't', 'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\\', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e',
    's', 'i', 'd', 'e', 's', 'L', 'f', '0', '1', '\\', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  char_T c3_b_u[94];
  const mxArray *c3_b_y = NULL;
  char_T c3_cv9[90];
  int32_T c3_i45;
  int32_T c3_i46;
  char_T c3_d_mystr[90];
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[90];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  real_T c3_b_arrBML[256];
  real_T c3_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_agentState;
  c3_agentState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 6U, c3_i_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mystr, MAX_uint32_T,
    c3_g_sf_marshallOut, c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_mystr, MAX_uint32_T,
    c3_e_sf_marshallOut, c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 2);
  _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 9);
  c3_x = c3_rand(chartInstance);
  c3_r = c3_x;
  c3_b_x = c3_r;
  c3_r = c3_b_x;
  c3_r = muDoubleScalarRound(c3_r);
  _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 10);
  if (CV_SCRIPT_IF(3, 0, c3_r == 0.0)) {
    _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 11);
    for (c3_i38 = 0; c3_i38 < 88; c3_i38++) {
      c3_b_mystr[c3_i38] = ' ';
    }

    _SFD_SYMBOL_SWITCH(1U, 2U);
    _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 12);
    for (c3_i39 = 0; c3_i39 < 92; c3_i39++) {
      c3_u[c3_i39] = c3_cv6[c3_i39];
    }

    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 92),
                  false);
    c3_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U, 14,
      c3_y), "sprintf", c3_cv7);
    for (c3_i40 = 0; c3_i40 < 88; c3_i40++) {
      c3_b_mystr[c3_i40] = c3_cv7[c3_i40];
    }

    _SFD_SYMBOL_SWITCH(1U, 2U);
    _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 13);
    for (c3_i41 = 0; c3_i41 < 88; c3_i41++) {
      c3_c_mystr[c3_i41] = c3_b_mystr[c3_i41];
    }

    c3_encStr2Arr(chartInstance, c3_c_mystr, c3_dv5);
    for (c3_i42 = 0; c3_i42 < 256; c3_i42++) {
      c3_arrBML[c3_i42] = c3_dv5[c3_i42];
    }
  } else {
    _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 15);
    for (c3_i43 = 0; c3_i43 < 90; c3_i43++) {
      c3_mystr[c3_i43] = ' ';
    }

    _SFD_SYMBOL_SWITCH(1U, 1U);
    _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 16);
    for (c3_i44 = 0; c3_i44 < 94; c3_i44++) {
      c3_b_u[c3_i44] = c3_cv8[c3_i44];
    }

    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 94),
                  false);
    c3_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U, 14,
      c3_b_y), "sprintf", c3_cv9);
    for (c3_i45 = 0; c3_i45 < 90; c3_i45++) {
      c3_mystr[c3_i45] = c3_cv9[c3_i45];
    }

    _SFD_SYMBOL_SWITCH(1U, 1U);
    _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, 17);
    for (c3_i46 = 0; c3_i46 < 90; c3_i46++) {
      c3_d_mystr[c3_i46] = c3_mystr[c3_i46];
    }

    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_h_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arr, 1U, c3_h_sf_marshallOut,
      c3_h_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_d_mystr, 7U, c3_g_sf_marshallOut,
      c3_g_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 8U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    CV_SCRIPT_FCN(1, 0);
    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 3);
    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 4);
    c3_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 6);
    for (c3_i47 = 0; c3_i47 < 90; c3_i47++) {
      c3_arr[c3_i47] = (real_T)c3_d_mystr[c3_i47];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 7);
    c3_ss = 90.0;
    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 8);
    c3_padsize = 166.0;
    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 9);
    for (c3_i48 = 0; c3_i48 < 256; c3_i48++) {
      c3_tt[c3_i48] = 0.0;
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 10);
    for (c3_i49 = 0; c3_i49 < 90; c3_i49++) {
      c3_tt[c3_i49] = c3_arr[c3_i49];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 11);
    for (c3_i50 = 0; c3_i50 < 256; c3_i50++) {
      c3_arrBML[c3_i50] = c3_tt[c3_i50];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c3_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i51 = 0; c3_i51 < 256; c3_i51++) {
    c3_b_arrBML[c3_i51] = c3_arrBML[c3_i51];
  }

  c3_sendBML(chartInstance, c3_b_arrBML);
  *c3_agentState = 2.0;
  c3_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_agentState, 4U);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 4U);
  sf_mex_printf("%s =\\n", "agentState");
  c3_hoistedGlobal = *c3_agentState;
  c3_c_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_c_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_encStr2Arr(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, char_T c3_mystr[88], real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[88];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_e_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arr, 1U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mystr, 7U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 6);
  for (c3_i52 = 0; c3_i52 < 88; c3_i52++) {
    c3_arr[c3_i52] = (real_T)c3_mystr[c3_i52];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 7);
  c3_ss = 88.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 168.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 9);
  for (c3_i53 = 0; c3_i53 < 256; c3_i53++) {
    c3_tt[c3_i53] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 10);
  for (c3_i54 = 0; c3_i54 < 88; c3_i54++) {
    c3_tt[c3_i54] = c3_arr[c3_i54];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 11);
  for (c3_i55 = 0; c3_i55 < 256; c3_i55++) {
    c3_myarr256[c3_i55] = c3_tt[c3_i55];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c3_rand(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  uint32_T c3_uv2[625];
  int32_T c3_i56;
  real_T c3_d0;
  if (!chartInstance->c3_method_not_empty) {
    chartInstance->c3_method = 7U;
    chartInstance->c3_method_not_empty = true;
  }

  if (!chartInstance->c3_c_state_not_empty) {
    c3_eml_rand_mt19937ar(chartInstance, c3_uv2);
    for (c3_i56 = 0; c3_i56 < 625; c3_i56++) {
      chartInstance->c3_c_state[c3_i56] = c3_uv2[c3_i56];
    }

    chartInstance->c3_c_state_not_empty = true;
  }

  c3_d0 = c3_c_eml_rand_mt19937ar(chartInstance, chartInstance->c3_c_state);
  return c3_d0;
}

static void c3_eml_rand_mt19937ar(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_d_state[625])
{
  real_T c3_d1;
  int32_T c3_i57;
  c3_d1 = 5489.0;
  for (c3_i57 = 0; c3_i57 < 625; c3_i57++) {
    c3_d_state[c3_i57] = 0U;
  }

  c3_b_twister_state_vector(chartInstance, c3_d_state, c3_d1);
}

static void c3_twister_state_vector(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625])
{
  int32_T c3_i58;
  for (c3_i58 = 0; c3_i58 < 625; c3_i58++) {
    c3_b_mt[c3_i58] = c3_mt[c3_i58];
  }

  c3_b_twister_state_vector(chartInstance, c3_b_mt, c3_seed);
}

static void c3_b_eml_rand_mt19937ar(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_d_state[625], uint32_T c3_e_state[625], real_T
  *c3_r)
{
  int32_T c3_i59;
  for (c3_i59 = 0; c3_i59 < 625; c3_i59++) {
    c3_e_state[c3_i59] = c3_d_state[c3_i59];
  }

  *c3_r = c3_c_eml_rand_mt19937ar(chartInstance, c3_e_state);
}

static void c3_eml_error(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance)
{
  int32_T c3_i60;
  static char_T c3_cv10[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c3_u[37];
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  for (c3_i60 = 0; c3_i60 < 37; c3_i60++) {
    c3_u[c3_i60] = c3_cv10[c3_i60];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c3_y));
}

static void c3_cmdBML_AUs(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, real_T c3_arrAU_data[], int32_T c3_arrAU_sizes[2], real_T
  c3_arrBML[256])
{
  uint32_T c3_debug_family_var_map[12];
  const mxArray *c3_str1 = NULL;
  real_T c3_i;
  real_T c3_AU;
  const mxArray *c3_temp = NULL;
  const mxArray *c3_temp2 = NULL;
  const mxArray *c3_str2 = NULL;
  real_T c3_n;
  int32_T c3_mystr_sizes[2];
  char_T c3_mystr_data[410];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i61;
  static char_T c3_cv11[34] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>' };

  char_T c3_u[34];
  const mxArray *c3_y = NULL;
  int32_T c3_x_sizes[2];
  int32_T c3_x;
  int32_T c3_b_x;
  int32_T c3_loop_ub;
  int32_T c3_i62;
  real_T c3_x_data[7];
  real_T c3_b_n;
  real_T c3_d2;
  int32_T c3_i63;
  int32_T c3_b_i;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_xk;
  real_T c3_k_x;
  real_T c3_maxval;
  int32_T c3_i64;
  static char_T c3_cv12[82] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e',
    '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=', '\\',
    '\"', '%', '1', 'd', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '3', '\\',
    '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '1', '\\', '\"',
    '/', '>' };

  char_T c3_b_u[82];
  const mxArray *c3_c_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_i65;
  static char_T c3_cv13[82] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e',
    '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=', '\\',
    '\"', '%', '2', 'd', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '3', '\\',
    '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '1', '\\', '\"',
    '/', '>' };

  char_T c3_d_u[82];
  const mxArray *c3_e_y = NULL;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  int32_T c3_i66;
  static char_T c3_cv14[12] = { '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  char_T c3_f_u[12];
  const mxArray *c3_g_y = NULL;
  int32_T c3_l_x;
  int32_T c3_m_x;
  int32_T c3_b_loop_ub;
  int32_T c3_i67;
  real_T c3_c_n;
  real_T c3_dv6[2];
  int32_T c3_iv0[2];
  int32_T c3_mystr;
  int32_T c3_b_mystr;
  int32_T c3_c_loop_ub;
  int32_T c3_i68;
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[410];
  int32_T c3_c_mystr;
  int32_T c3_d_mystr;
  int32_T c3_d_loop_ub;
  int32_T c3_i69;
  int32_T c3_b_mystr_sizes[2];
  int32_T c3_e_mystr;
  int32_T c3_f_mystr;
  int32_T c3_e_loop_ub;
  int32_T c3_i70;
  char_T c3_b_mystr_data[410];
  real_T c3_dv7[256];
  int32_T c3_i71;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c3_p_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_str1, 0U, c3_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_AU, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_temp, 3U, c3_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_temp2, 4U, c3_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_str2, 5U, c3_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_mystr_data, (const int32_T *)
    &c3_mystr_sizes, NULL, 0, 7, (void *)c3_m_sf_marshallOut, (void *)
    c3_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_arrAU_data, (const int32_T *)
    c3_arrAU_sizes, NULL, 1, 10, (void *)c3_k_sf_marshallOut, (void *)
    c3_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 11U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 2);
  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 7);
  for (c3_i61 = 0; c3_i61 < 34; c3_i61++) {
    c3_u[c3_i61] = c3_cv11[c3_i61];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 34), false);
  sf_mex_assign(&c3_str1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c3_y), false);
  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 8);
  c3_x_sizes[0] = 1;
  c3_x_sizes[1] = c3_arrAU_sizes[1];
  c3_x = c3_x_sizes[0];
  c3_b_x = c3_x_sizes[1];
  c3_loop_ub = c3_arrAU_sizes[0] * c3_arrAU_sizes[1] - 1;
  for (c3_i62 = 0; c3_i62 <= c3_loop_ub; c3_i62++) {
    c3_x_data[c3_i62] = c3_arrAU_data[c3_i62];
  }

  c3_b_n = (real_T)c3_x_sizes[1];
  c3_d2 = c3_b_n - 1.0;
  c3_i63 = (int32_T)c3_d2 - 1;
  c3_i = 1.0;
  c3_b_i = 0;
  while (c3_b_i <= c3_i63) {
    c3_i = 1.0 + (real_T)c3_b_i;
    CV_SCRIPT_FOR(5, 0, 1);
    _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 9);
    c3_AU = c3_arrAU_data[_SFD_EML_ARRAY_BOUNDS_CHECK("arrAU", (int32_T)c3_i, 1,
      c3_arrAU_sizes[1], 1, 0) - 1];
    _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 10);
    c3_c_x = c3_AU;
    c3_d_x = c3_c_x;
    c3_b_y = c3_d_x;
    c3_e_x = c3_b_y;
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarLog10(c3_f_x);
    c3_g_x = c3_f_x;
    c3_h_x = c3_g_x;
    c3_h_x = muDoubleScalarCeil(c3_h_x);
    c3_varargin_1 = c3_h_x;
    c3_varargin_2 = c3_varargin_1;
    c3_i_x = c3_varargin_2;
    c3_j_x = c3_i_x;
    c3_eml_scalar_eg(chartInstance);
    c3_xk = c3_j_x;
    c3_k_x = c3_xk;
    c3_eml_scalar_eg(chartInstance);
    c3_maxval = muDoubleScalarMax(c3_k_x, 1.0);
    if (CV_SCRIPT_IF(5, 0, c3_maxval == 1.0)) {
      _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 11);
      for (c3_i64 = 0; c3_i64 < 82; c3_i64++) {
        c3_b_u[c3_i64] = c3_cv12[c3_i64];
      }

      c3_c_y = NULL;
      sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 82),
                    false);
      c3_c_u = c3_AU;
      c3_d_y = NULL;
      sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c3_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "sprintf", 1U, 2U, 14, c3_c_y, 14, c3_d_y), false);
      _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 12);
      sf_mex_assign(&c3_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "strcat", 1U, 2U, 14, sf_mex_dup(c3_str1), 14, sf_mex_dup(c3_temp)),
                    false);
      _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 13);
      sf_mex_assign(&c3_str1, sf_mex_dup(c3_temp2), false);
    } else {
      _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 15);
      for (c3_i65 = 0; c3_i65 < 82; c3_i65++) {
        c3_d_u[c3_i65] = c3_cv13[c3_i65];
      }

      c3_e_y = NULL;
      sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_d_u, 10, 0U, 1U, 0U, 2, 1, 82),
                    false);
      c3_e_u = c3_AU;
      c3_f_y = NULL;
      sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c3_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "sprintf", 1U, 2U, 14, c3_e_y, 14, c3_f_y), false);
      _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 16);
      sf_mex_assign(&c3_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "strcat", 1U, 2U, 14, sf_mex_dup(c3_str1), 14, sf_mex_dup(c3_temp)),
                    false);
      _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 17);
      sf_mex_assign(&c3_str1, sf_mex_dup(c3_temp2), false);
    }

    c3_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(5, 0, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 20);
  for (c3_i66 = 0; c3_i66 < 12; c3_i66++) {
    c3_f_u[c3_i66] = c3_cv14[c3_i66];
  }

  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_f_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_assign(&c3_str2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c3_g_y), false);
  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 21);
  c3_x_sizes[0] = 1;
  c3_x_sizes[1] = c3_arrAU_sizes[1];
  c3_l_x = c3_x_sizes[0];
  c3_m_x = c3_x_sizes[1];
  c3_b_loop_ub = c3_arrAU_sizes[0] * c3_arrAU_sizes[1] - 1;
  for (c3_i67 = 0; c3_i67 <= c3_b_loop_ub; c3_i67++) {
    c3_x_data[c3_i67] = c3_arrAU_data[c3_i67];
  }

  c3_n = (real_T)c3_x_sizes[1];
  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 22);
  c3_c_n = c3_arrAU_data[_SFD_EML_ARRAY_BOUNDS_CHECK("arrAU", (int32_T)c3_n, 1,
    c3_arrAU_sizes[1], 1, 0) - 1];
  c3_dv6[0] = 1.0;
  c3_dv6[1] = c3_c_n;
  c3_mystr_sizes[0] = 1;
  c3_iv0[0] = 1;
  c3_iv0[1] = (int32_T)c3_dv6[1];
  c3_mystr_sizes[1] = c3_iv0[1];
  c3_mystr = c3_mystr_sizes[0];
  c3_b_mystr = c3_mystr_sizes[1];
  c3_c_loop_ub = (int32_T)c3_dv6[1] - 1;
  for (c3_i68 = 0; c3_i68 <= c3_c_loop_ub; c3_i68++) {
    c3_mystr_data[c3_i68] = ' ';
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 23);
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "strcat", 1U, 2U, 14,
    sf_mex_dup(c3_str1), 14, sf_mex_dup(c3_str2)), "strcat", c3_tmp_data,
                        c3_tmp_sizes);
  c3_mystr_sizes[0] = 1;
  c3_mystr_sizes[1] = c3_tmp_sizes[1];
  c3_c_mystr = c3_mystr_sizes[0];
  c3_d_mystr = c3_mystr_sizes[1];
  c3_d_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i69 = 0; c3_i69 <= c3_d_loop_ub; c3_i69++) {
    c3_mystr_data[c3_i69] = c3_tmp_data[c3_i69];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, 24);
  c3_b_mystr_sizes[0] = 1;
  c3_b_mystr_sizes[1] = c3_mystr_sizes[1];
  c3_e_mystr = c3_b_mystr_sizes[0];
  c3_f_mystr = c3_b_mystr_sizes[1];
  c3_e_loop_ub = c3_mystr_sizes[0] * c3_mystr_sizes[1] - 1;
  for (c3_i70 = 0; c3_i70 <= c3_e_loop_ub; c3_i70++) {
    c3_b_mystr_data[c3_i70] = c3_mystr_data[c3_i70];
  }

  c3_b_encStr2Arr(chartInstance, c3_b_mystr_data, c3_b_mystr_sizes, c3_dv7);
  for (c3_i71 = 0; c3_i71 < 256; c3_i71++) {
    c3_arrBML[c3_i71] = c3_dv7[c3_i71];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c3_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c3_str1);
  sf_mex_destroy(&c3_temp);
  sf_mex_destroy(&c3_temp2);
  sf_mex_destroy(&c3_str2);
}

static void c3_eml_scalar_eg(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_b_encStr2Arr(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, char_T c3_mystr_data[], int32_T c3_mystr_sizes[2], real_T
  c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  int32_T c3_arr_sizes;
  real_T c3_arr_data[410];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_loop_ub;
  int32_T c3_i72;
  int32_T c3_i73;
  boolean_T c3_b0;
  boolean_T c3_b1;
  boolean_T c3_b2;
  int32_T c3_i74;
  int32_T c3_tmp_sizes;
  int32_T c3_b_loop_ub;
  int32_T c3_i75;
  int32_T c3_tmp_data[256];
  int32_T c3_iv1[1];
  int32_T c3_c_loop_ub;
  int32_T c3_i76;
  int32_T c3_i77;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_o_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_arr_data, (const int32_T *)
    &c3_arr_sizes, NULL, 0, 1, (void *)c3_n_sf_marshallOut, (void *)
    c3_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ss, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_mystr_data, (const int32_T *)
    c3_mystr_sizes, NULL, 1, 7, (void *)c3_m_sf_marshallOut, (void *)
    c3_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 6);
  c3_arr_sizes = c3_mystr_sizes[1];
  c3_loop_ub = c3_mystr_sizes[1] - 1;
  for (c3_i72 = 0; c3_i72 <= c3_loop_ub; c3_i72++) {
    c3_arr_data[c3_i72] = (real_T)c3_mystr_data[c3_mystr_sizes[0] * c3_i72];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 7);
  c3_ss = (real_T)c3_arr_sizes;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 256.0 - c3_ss;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 9);
  for (c3_i73 = 0; c3_i73 < 256; c3_i73++) {
    c3_tt[c3_i73] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 10);
  c3_b0 = (1.0 > c3_ss);
  c3_b1 = c3_b0;
  c3_b2 = c3_b1;
  if (c3_b2) {
    c3_i74 = 0;
  } else {
    c3_i74 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c3_ss, 1, 256, 0, 0);
  }

  c3_tmp_sizes = c3_i74;
  c3_b_loop_ub = c3_i74 - 1;
  for (c3_i75 = 0; c3_i75 <= c3_b_loop_ub; c3_i75++) {
    c3_tmp_data[c3_i75] = c3_i75;
  }

  c3_iv1[0] = c3_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c3_iv1, 1, *(int32_T (*)[1])&c3_arr_sizes, 1);
  c3_c_loop_ub = c3_arr_sizes - 1;
  for (c3_i76 = 0; c3_i76 <= c3_c_loop_ub; c3_i76++) {
    c3_tt[c3_tmp_data[c3_i76]] = c3_arr_data[c3_i76];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 11);
  for (c3_i77 = 0; c3_i77 < 256; c3_i77++) {
    c3_myarr256[c3_i77] = c3_tt[c3_i77];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\cmdBML_idle.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\cmdBML_pointRt.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\cmdBML_pointLf.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 4U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\cmdBML_target.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 5U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\cmdBML_AUs.m"));
}

static void c3_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[85])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_b_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[85])
{
  char_T c3_cv15[85];
  int32_T c3_i78;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_cv15, 1, 10, 0U, 1, 0U, 2, 1,
                85);
  for (c3_i78 = 0; c3_i78 < 85; c3_i78++) {
    c3_y[c3_i78] = c3_cv15[c3_i78];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[88])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_d_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[88])
{
  char_T c3_cv16[88];
  int32_T c3_i79;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_cv16, 1, 10, 0U, 1, 0U, 2, 1,
                88);
  for (c3_i79 = 0; c3_i79 < 88; c3_i79++) {
    c3_y[c3_i79] = c3_cv16[c3_i79];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[90])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_f_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[90])
{
  char_T c3_cv17[90];
  int32_T c3_i80;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_cv17, 1, 10, 0U, 1, 0U, 2, 1,
                90);
  for (c3_i80 = 0; c3_i80 < 90; c3_i80++) {
    c3_y[c3_i80] = c3_cv17[c3_i80];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[92])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_h_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[92])
{
  char_T c3_cv18[92];
  int32_T c3_i81;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_cv18, 1, 10, 0U, 1, 0U, 2, 1,
                92);
  for (c3_i81 = 0; c3_i81 < 92; c3_i81++) {
    c3_y[c3_i81] = c3_cv18[c3_i81];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_i_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_strcat, const char_T *c3_identifier, char_T
  c3_y_data[], int32_T c3_y_sizes[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_strcat), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_strcat);
}

static void c3_j_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2])
{
  int32_T c3_i82;
  uint32_T c3_uv3[2];
  int32_T c3_i83;
  static boolean_T c3_bv0[2] = { false, true };

  boolean_T c3_bv1[2];
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[410];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i84;
  (void)chartInstance;
  for (c3_i82 = 0; c3_i82 < 2; c3_i82++) {
    c3_uv3[c3_i82] = 1U + 409U * (uint32_T)c3_i82;
  }

  for (c3_i83 = 0; c3_i83 < 2; c3_i83++) {
    c3_bv1[c3_i83] = c3_bv0[c3_i83];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c3_bv1, c3_uv3, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i84 = 0; c3_i84 <= c3_loop_ub; c3_i84++) {
    c3_y_data[c3_i84] = c3_tmp_data[c3_i84];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_k_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_l_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d3, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i85;
  real_T c3_b_inData[256];
  int32_T c3_i86;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i85 = 0; c3_i85 < 256; c3_i85++) {
    c3_b_inData[c3_i85] = (*(real_T (*)[256])c3_inData)[c3_i85];
  }

  for (c3_i86 = 0; c3_i86 < 256; c3_i86++) {
    c3_u[c3_i86] = c3_b_inData[c3_i86];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_m_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv8[256];
  int32_T c3_i87;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv8, 1, 0, 0U, 1, 0U, 1, 256);
  for (c3_i87 = 0; c3_i87 < 256; c3_i87++) {
    c3_y[c3_i87] = c3_dv8[c3_i87];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_myarr256;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i88;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_myarr256 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
  for (c3_i88 = 0; c3_i88 < 256; c3_i88++) {
    (*(real_T (*)[256])c3_outData)[c3_i88] = c3_y[c3_i88];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i89;
  char_T c3_b_inData[85];
  int32_T c3_i90;
  char_T c3_u[85];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i89 = 0; c3_i89 < 85; c3_i89++) {
    c3_b_inData[c3_i89] = (*(char_T (*)[85])c3_inData)[c3_i89];
  }

  for (c3_i90 = 0; c3_i90 < 85; c3_i90++) {
    c3_u[c3_i90] = c3_b_inData[c3_i90];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 85), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sprintf;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  char_T c3_y[85];
  int32_T c3_i91;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_sprintf = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
  for (c3_i91 = 0; c3_i91 < 85; c3_i91++) {
    (*(char_T (*)[85])c3_outData)[c3_i91] = c3_y[c3_i91];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i92;
  real_T c3_b_inData[85];
  int32_T c3_i93;
  real_T c3_u[85];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i92 = 0; c3_i92 < 85; c3_i92++) {
    c3_b_inData[c3_i92] = (*(real_T (*)[85])c3_inData)[c3_i92];
  }

  for (c3_i93 = 0; c3_i93 < 85; c3_i93++) {
    c3_u[c3_i93] = c3_b_inData[c3_i93];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 85), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_n_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[85])
{
  real_T c3_dv9[85];
  int32_T c3_i94;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv9, 1, 0, 0U, 1, 0U, 1, 85);
  for (c3_i94 = 0; c3_i94 < 85; c3_i94++) {
    c3_y[c3_i94] = c3_dv9[c3_i94];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[85];
  int32_T c3_i95;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arr);
  for (c3_i95 = 0; c3_i95 < 85; c3_i95++) {
    (*(real_T (*)[85])c3_outData)[c3_i95] = c3_y[c3_i95];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i96;
  char_T c3_b_inData[88];
  int32_T c3_i97;
  char_T c3_u[88];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i96 = 0; c3_i96 < 88; c3_i96++) {
    c3_b_inData[c3_i96] = (*(char_T (*)[88])c3_inData)[c3_i96];
  }

  for (c3_i97 = 0; c3_i97 < 88; c3_i97++) {
    c3_u[c3_i97] = c3_b_inData[c3_i97];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sprintf;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  char_T c3_y[88];
  int32_T c3_i98;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_sprintf = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
  for (c3_i98 = 0; c3_i98 < 88; c3_i98++) {
    (*(char_T (*)[88])c3_outData)[c3_i98] = c3_y[c3_i98];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i99;
  real_T c3_b_inData[88];
  int32_T c3_i100;
  real_T c3_u[88];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i99 = 0; c3_i99 < 88; c3_i99++) {
    c3_b_inData[c3_i99] = (*(real_T (*)[88])c3_inData)[c3_i99];
  }

  for (c3_i100 = 0; c3_i100 < 88; c3_i100++) {
    c3_u[c3_i100] = c3_b_inData[c3_i100];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_o_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[88])
{
  real_T c3_dv10[88];
  int32_T c3_i101;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv10, 1, 0, 0U, 1, 0U, 1, 88);
  for (c3_i101 = 0; c3_i101 < 88; c3_i101++) {
    c3_y[c3_i101] = c3_dv10[c3_i101];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[88];
  int32_T c3_i102;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arr);
  for (c3_i102 = 0; c3_i102 < 88; c3_i102++) {
    (*(real_T (*)[88])c3_outData)[c3_i102] = c3_y[c3_i102];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i103;
  char_T c3_b_inData[90];
  int32_T c3_i104;
  char_T c3_u[90];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i103 = 0; c3_i103 < 90; c3_i103++) {
    c3_b_inData[c3_i103] = (*(char_T (*)[90])c3_inData)[c3_i103];
  }

  for (c3_i104 = 0; c3_i104 < 90; c3_i104++) {
    c3_u[c3_i104] = c3_b_inData[c3_i104];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 90), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sprintf;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  char_T c3_y[90];
  int32_T c3_i105;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_sprintf = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
  for (c3_i105 = 0; c3_i105 < 90; c3_i105++) {
    (*(char_T (*)[90])c3_outData)[c3_i105] = c3_y[c3_i105];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i106;
  real_T c3_b_inData[90];
  int32_T c3_i107;
  real_T c3_u[90];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i106 = 0; c3_i106 < 90; c3_i106++) {
    c3_b_inData[c3_i106] = (*(real_T (*)[90])c3_inData)[c3_i106];
  }

  for (c3_i107 = 0; c3_i107 < 90; c3_i107++) {
    c3_u[c3_i107] = c3_b_inData[c3_i107];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 90), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_p_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[90])
{
  real_T c3_dv11[90];
  int32_T c3_i108;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv11, 1, 0, 0U, 1, 0U, 1, 90);
  for (c3_i108 = 0; c3_i108 < 90; c3_i108++) {
    c3_y[c3_i108] = c3_dv11[c3_i108];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[90];
  int32_T c3_i109;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arr);
  for (c3_i109 = 0; c3_i109 < 90; c3_i109++) {
    (*(real_T (*)[90])c3_outData)[c3_i109] = c3_y[c3_i109];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i110;
  char_T c3_b_inData[92];
  int32_T c3_i111;
  char_T c3_u[92];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i110 = 0; c3_i110 < 92; c3_i110++) {
    c3_b_inData[c3_i110] = (*(char_T (*)[92])c3_inData)[c3_i110];
  }

  for (c3_i111 = 0; c3_i111 < 92; c3_i111++) {
    c3_u[c3_i111] = c3_b_inData[c3_i111];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sprintf;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  char_T c3_y[92];
  int32_T c3_i112;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_sprintf = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
  for (c3_i112 = 0; c3_i112 < 92; c3_i112++) {
    (*(char_T (*)[92])c3_outData)[c3_i112] = c3_y[c3_i112];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i113;
  real_T c3_b_inData[92];
  int32_T c3_i114;
  real_T c3_u[92];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i113 = 0; c3_i113 < 92; c3_i113++) {
    c3_b_inData[c3_i113] = (*(real_T (*)[92])c3_inData)[c3_i113];
  }

  for (c3_i114 = 0; c3_i114 < 92; c3_i114++) {
    c3_u[c3_i114] = c3_b_inData[c3_i114];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_q_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[92])
{
  real_T c3_dv12[92];
  int32_T c3_i115;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv12, 1, 0, 0U, 1, 0U, 1, 92);
  for (c3_i115 = 0; c3_i115 < 92; c3_i115++) {
    c3_y[c3_i115] = c3_dv12[c3_i115];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[92];
  int32_T c3_i116;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arr);
  for (c3_i116 = 0; c3_i116 < 92; c3_i116++) {
    (*(real_T (*)[92])c3_outData)[c3_i116] = c3_y[c3_i116];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T c3_inData_sizes[2])
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes[2];
  int32_T c3_loop_ub;
  int32_T c3_i117;
  real_T c3_b_inData_data[7];
  int32_T c3_u_sizes[2];
  int32_T c3_b_loop_ub;
  int32_T c3_i118;
  real_T c3_u_data[7];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes[0] = 1;
  c3_b_inData_sizes[1] = c3_inData_sizes[1];
  c3_loop_ub = c3_inData_sizes[1] - 1;
  for (c3_i117 = 0; c3_i117 <= c3_loop_ub; c3_i117++) {
    c3_b_inData_data[c3_b_inData_sizes[0] * c3_i117] =
      c3_inData_data[c3_inData_sizes[0] * c3_i117];
  }

  c3_u_sizes[0] = 1;
  c3_u_sizes[1] = c3_b_inData_sizes[1];
  c3_b_loop_ub = c3_b_inData_sizes[1] - 1;
  for (c3_i118 = 0; c3_i118 <= c3_b_loop_ub; c3_i118++) {
    c3_u_data[c3_u_sizes[0] * c3_i118] = c3_b_inData_data[c3_b_inData_sizes[0] *
      c3_i118];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 2,
    c3_u_sizes[0], c3_u_sizes[1]), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_r_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T c3_y_sizes[2])
{
  int32_T c3_i119;
  uint32_T c3_uv4[2];
  int32_T c3_i120;
  static boolean_T c3_bv2[2] = { false, true };

  boolean_T c3_bv3[2];
  int32_T c3_tmp_sizes[2];
  real_T c3_tmp_data[7];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i121;
  (void)chartInstance;
  for (c3_i119 = 0; c3_i119 < 2; c3_i119++) {
    c3_uv4[c3_i119] = 1U + 6U * (uint32_T)c3_i119;
  }

  for (c3_i120 = 0; c3_i120 < 2; c3_i120++) {
    c3_bv3[c3_i120] = c3_bv2[c3_i120];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 0, 0U, 1, 0U,
                   2, c3_bv3, c3_uv4, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i121 = 0; c3_i121 <= c3_loop_ub; c3_i121++) {
    c3_y_data[c3_i121] = c3_tmp_data[c3_i121];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  c3_outData_sizes[2])
{
  const mxArray *c3_AU;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes[2];
  real_T c3_y_data[7];
  int32_T c3_loop_ub;
  int32_T c3_i122;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_AU = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_AU), &c3_thisId, c3_y_data,
                        c3_y_sizes);
  sf_mex_destroy(&c3_AU);
  c3_outData_sizes[0] = 1;
  c3_outData_sizes[1] = c3_y_sizes[1];
  c3_loop_ub = c3_y_sizes[1] - 1;
  for (c3_i122 = 0; c3_i122 <= c3_loop_ub; c3_i122++) {
    c3_outData_data[c3_outData_sizes[0] * c3_i122] = c3_y_data[c3_y_sizes[0] *
      c3_i122];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_s_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b3, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_aVarTruthTableCondition_9;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_aVarTruthTableCondition_9 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_aVarTruthTableCondition_9), &c3_thisId);
  sf_mex_destroy(&c3_aVarTruthTableCondition_9);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, char_T
  c3_inData_data[], int32_T c3_inData_sizes[2])
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes[2];
  int32_T c3_loop_ub;
  int32_T c3_i123;
  char_T c3_b_inData_data[410];
  int32_T c3_u_sizes[2];
  int32_T c3_b_loop_ub;
  int32_T c3_i124;
  char_T c3_u_data[410];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes[0] = 1;
  c3_b_inData_sizes[1] = c3_inData_sizes[1];
  c3_loop_ub = c3_inData_sizes[1] - 1;
  for (c3_i123 = 0; c3_i123 <= c3_loop_ub; c3_i123++) {
    c3_b_inData_data[c3_b_inData_sizes[0] * c3_i123] =
      c3_inData_data[c3_inData_sizes[0] * c3_i123];
  }

  c3_u_sizes[0] = 1;
  c3_u_sizes[1] = c3_b_inData_sizes[1];
  c3_b_loop_ub = c3_b_inData_sizes[1] - 1;
  for (c3_i124 = 0; c3_i124 <= c3_b_loop_ub; c3_i124++) {
    c3_u_data[c3_u_sizes[0] * c3_i124] = c3_b_inData_data[c3_b_inData_sizes[0] *
      c3_i124];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 10, 0U, 1U, 0U, 2,
    c3_u_sizes[0], c3_u_sizes[1]), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_t_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2])
{
  int32_T c3_i125;
  uint32_T c3_uv5[2];
  int32_T c3_i126;
  static boolean_T c3_bv4[2] = { false, true };

  boolean_T c3_bv5[2];
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[410];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i127;
  (void)chartInstance;
  for (c3_i125 = 0; c3_i125 < 2; c3_i125++) {
    c3_uv5[c3_i125] = 1U + 409U * (uint32_T)c3_i125;
  }

  for (c3_i126 = 0; c3_i126 < 2; c3_i126++) {
    c3_bv5[c3_i126] = c3_bv4[c3_i126];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c3_bv5, c3_uv5, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i127 = 0; c3_i127 <= c3_loop_ub; c3_i127++) {
    c3_y_data[c3_i127] = c3_tmp_data[c3_i127];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, char_T c3_outData_data[], int32_T
  c3_outData_sizes[2])
{
  const mxArray *c3_mystr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes[2];
  char_T c3_y_data[410];
  int32_T c3_loop_ub;
  int32_T c3_i128;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mystr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mystr), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_mystr);
  c3_outData_sizes[0] = 1;
  c3_outData_sizes[1] = c3_y_sizes[1];
  c3_loop_ub = c3_y_sizes[1] - 1;
  for (c3_i128 = 0; c3_i128 <= c3_loop_ub; c3_i128++) {
    c3_outData_data[c3_outData_sizes[0] * c3_i128] = c3_y_data[c3_y_sizes[0] *
      c3_i128];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T *c3_inData_sizes)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes;
  int32_T c3_loop_ub;
  int32_T c3_i129;
  real_T c3_b_inData_data[410];
  int32_T c3_u_sizes;
  int32_T c3_b_loop_ub;
  int32_T c3_i130;
  real_T c3_u_data[410];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes = *c3_inData_sizes;
  c3_loop_ub = *c3_inData_sizes - 1;
  for (c3_i129 = 0; c3_i129 <= c3_loop_ub; c3_i129++) {
    c3_b_inData_data[c3_i129] = c3_inData_data[c3_i129];
  }

  c3_u_sizes = c3_b_inData_sizes;
  c3_b_loop_ub = c3_b_inData_sizes - 1;
  for (c3_i130 = 0; c3_i130 <= c3_b_loop_ub; c3_i130++) {
    c3_u_data[c3_i130] = c3_b_inData_data[c3_i130];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 1,
    c3_u_sizes), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_u_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T *c3_y_sizes)
{
  static uint32_T c3_uv6[1] = { 410U };

  uint32_T c3_uv7[1];
  static boolean_T c3_bv6[1] = { true };

  boolean_T c3_bv7[1];
  int32_T c3_tmp_sizes;
  real_T c3_tmp_data[410];
  int32_T c3_loop_ub;
  int32_T c3_i131;
  (void)chartInstance;
  c3_uv7[0] = c3_uv6[0];
  c3_bv7[0] = c3_bv6[0];
  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c3_bv7, c3_uv7, &c3_tmp_sizes);
  *c3_y_sizes = c3_tmp_sizes;
  c3_loop_ub = c3_tmp_sizes - 1;
  for (c3_i131 = 0; c3_i131 <= c3_loop_ub; c3_i131++) {
    c3_y_data[c3_i131] = c3_tmp_data[c3_i131];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  *c3_outData_sizes)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes;
  real_T c3_y_data[410];
  int32_T c3_loop_ub;
  int32_T c3_i132;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y_data,
                        &c3_y_sizes);
  sf_mex_destroy(&c3_arr);
  *c3_outData_sizes = c3_y_sizes;
  c3_loop_ub = c3_y_sizes - 1;
  for (c3_i132 = 0; c3_i132 <= c3_loop_ub; c3_i132++) {
    c3_outData_data[c3_i132] = c3_y_data[c3_i132];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  const mxArray *c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = sf_mex_dup(*(const mxArray **)c3_inData);
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_ARP_02_PointUser_AnTS_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 73, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  c3_b_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  const mxArray *c3_rhs26 = NULL;
  const mxArray *c3_lhs26 = NULL;
  const mxArray *c3_rhs27 = NULL;
  const mxArray *c3_lhs27 = NULL;
  const mxArray *c3_rhs28 = NULL;
  const mxArray *c3_lhs28 = NULL;
  const mxArray *c3_rhs29 = NULL;
  const mxArray *c3_lhs29 = NULL;
  const mxArray *c3_rhs30 = NULL;
  const mxArray *c3_lhs30 = NULL;
  const mxArray *c3_rhs31 = NULL;
  const mxArray *c3_lhs31 = NULL;
  const mxArray *c3_rhs32 = NULL;
  const mxArray *c3_lhs32 = NULL;
  const mxArray *c3_rhs33 = NULL;
  const mxArray *c3_lhs33 = NULL;
  const mxArray *c3_rhs34 = NULL;
  const mxArray *c3_lhs34 = NULL;
  const mxArray *c3_rhs35 = NULL;
  const mxArray *c3_lhs35 = NULL;
  const mxArray *c3_rhs36 = NULL;
  const mxArray *c3_lhs36 = NULL;
  const mxArray *c3_rhs37 = NULL;
  const mxArray *c3_lhs37 = NULL;
  const mxArray *c3_rhs38 = NULL;
  const mxArray *c3_lhs38 = NULL;
  const mxArray *c3_rhs39 = NULL;
  const mxArray *c3_lhs39 = NULL;
  const mxArray *c3_rhs40 = NULL;
  const mxArray *c3_lhs40 = NULL;
  const mxArray *c3_rhs41 = NULL;
  const mxArray *c3_lhs41 = NULL;
  const mxArray *c3_rhs42 = NULL;
  const mxArray *c3_lhs42 = NULL;
  const mxArray *c3_rhs43 = NULL;
  const mxArray *c3_lhs43 = NULL;
  const mxArray *c3_rhs44 = NULL;
  const mxArray *c3_lhs44 = NULL;
  const mxArray *c3_rhs45 = NULL;
  const mxArray *c3_lhs45 = NULL;
  const mxArray *c3_rhs46 = NULL;
  const mxArray *c3_lhs46 = NULL;
  const mxArray *c3_rhs47 = NULL;
  const mxArray *c3_lhs47 = NULL;
  const mxArray *c3_rhs48 = NULL;
  const mxArray *c3_lhs48 = NULL;
  const mxArray *c3_rhs49 = NULL;
  const mxArray *c3_lhs49 = NULL;
  const mxArray *c3_rhs50 = NULL;
  const mxArray *c3_lhs50 = NULL;
  const mxArray *c3_rhs51 = NULL;
  const mxArray *c3_lhs51 = NULL;
  const mxArray *c3_rhs52 = NULL;
  const mxArray *c3_lhs52 = NULL;
  const mxArray *c3_rhs53 = NULL;
  const mxArray *c3_lhs53 = NULL;
  const mxArray *c3_rhs54 = NULL;
  const mxArray *c3_lhs54 = NULL;
  const mxArray *c3_rhs55 = NULL;
  const mxArray *c3_lhs55 = NULL;
  const mxArray *c3_rhs56 = NULL;
  const mxArray *c3_lhs56 = NULL;
  const mxArray *c3_rhs57 = NULL;
  const mxArray *c3_lhs57 = NULL;
  const mxArray *c3_rhs58 = NULL;
  const mxArray *c3_lhs58 = NULL;
  const mxArray *c3_rhs59 = NULL;
  const mxArray *c3_lhs59 = NULL;
  const mxArray *c3_rhs60 = NULL;
  const mxArray *c3_lhs60 = NULL;
  const mxArray *c3_rhs61 = NULL;
  const mxArray *c3_lhs61 = NULL;
  const mxArray *c3_rhs62 = NULL;
  const mxArray *c3_lhs62 = NULL;
  const mxArray *c3_rhs63 = NULL;
  const mxArray *c3_lhs63 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cmdBML_idle"), "name", "name",
                  0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_idle.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1408408129U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_idle.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_idle.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cmdBML_pointRt"), "name",
                  "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointRt.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1409773474U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointRt.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointRt.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cmdBML_pointLf"), "name",
                  "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointLf.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1409773478U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointLf.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rand"), "name", "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand"), "name", "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eps"), "name", "name", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_eps"), "name", "name", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isequal"), "name", "name", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c3_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isnan"), "name", "name", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c3_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c3_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c3_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c3_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c3_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c3_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointLf.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("round"), "name", "name", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c3_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c3_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1307683638U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c3_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointLf.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c3_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_pointLf.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c3_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cmdBML_target"), "name",
                  "name", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_target.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1409773386U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c3_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_target.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c3_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_target.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c3_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cmdBML_AUs"), "name", "name",
                  41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1409774302U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c3_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("length"), "name", "name", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1303178606U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c3_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c3_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c3_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c3_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("log10"), "name", "name", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343862782U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c3_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c3_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851128U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c3_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("realmax"), "name", "name", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1307683642U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c3_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_realmax"), "name", "name",
                  50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c3_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c3_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c3_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c3_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c3_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c3_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c3_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c3_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c3_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "context", "context", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("ceil"), "name", "name", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c3_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c3_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_ceil"), "name",
                  "name", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_ceil.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851120U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c3_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "context", "context", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("max"), "name", "name", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1311287716U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c3_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1378328384U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c3_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
  sf_mex_destroy(&c3_rhs26);
  sf_mex_destroy(&c3_lhs26);
  sf_mex_destroy(&c3_rhs27);
  sf_mex_destroy(&c3_lhs27);
  sf_mex_destroy(&c3_rhs28);
  sf_mex_destroy(&c3_lhs28);
  sf_mex_destroy(&c3_rhs29);
  sf_mex_destroy(&c3_lhs29);
  sf_mex_destroy(&c3_rhs30);
  sf_mex_destroy(&c3_lhs30);
  sf_mex_destroy(&c3_rhs31);
  sf_mex_destroy(&c3_lhs31);
  sf_mex_destroy(&c3_rhs32);
  sf_mex_destroy(&c3_lhs32);
  sf_mex_destroy(&c3_rhs33);
  sf_mex_destroy(&c3_lhs33);
  sf_mex_destroy(&c3_rhs34);
  sf_mex_destroy(&c3_lhs34);
  sf_mex_destroy(&c3_rhs35);
  sf_mex_destroy(&c3_lhs35);
  sf_mex_destroy(&c3_rhs36);
  sf_mex_destroy(&c3_lhs36);
  sf_mex_destroy(&c3_rhs37);
  sf_mex_destroy(&c3_lhs37);
  sf_mex_destroy(&c3_rhs38);
  sf_mex_destroy(&c3_lhs38);
  sf_mex_destroy(&c3_rhs39);
  sf_mex_destroy(&c3_lhs39);
  sf_mex_destroy(&c3_rhs40);
  sf_mex_destroy(&c3_lhs40);
  sf_mex_destroy(&c3_rhs41);
  sf_mex_destroy(&c3_lhs41);
  sf_mex_destroy(&c3_rhs42);
  sf_mex_destroy(&c3_lhs42);
  sf_mex_destroy(&c3_rhs43);
  sf_mex_destroy(&c3_lhs43);
  sf_mex_destroy(&c3_rhs44);
  sf_mex_destroy(&c3_lhs44);
  sf_mex_destroy(&c3_rhs45);
  sf_mex_destroy(&c3_lhs45);
  sf_mex_destroy(&c3_rhs46);
  sf_mex_destroy(&c3_lhs46);
  sf_mex_destroy(&c3_rhs47);
  sf_mex_destroy(&c3_lhs47);
  sf_mex_destroy(&c3_rhs48);
  sf_mex_destroy(&c3_lhs48);
  sf_mex_destroy(&c3_rhs49);
  sf_mex_destroy(&c3_lhs49);
  sf_mex_destroy(&c3_rhs50);
  sf_mex_destroy(&c3_lhs50);
  sf_mex_destroy(&c3_rhs51);
  sf_mex_destroy(&c3_lhs51);
  sf_mex_destroy(&c3_rhs52);
  sf_mex_destroy(&c3_lhs52);
  sf_mex_destroy(&c3_rhs53);
  sf_mex_destroy(&c3_lhs53);
  sf_mex_destroy(&c3_rhs54);
  sf_mex_destroy(&c3_lhs54);
  sf_mex_destroy(&c3_rhs55);
  sf_mex_destroy(&c3_lhs55);
  sf_mex_destroy(&c3_rhs56);
  sf_mex_destroy(&c3_lhs56);
  sf_mex_destroy(&c3_rhs57);
  sf_mex_destroy(&c3_lhs57);
  sf_mex_destroy(&c3_rhs58);
  sf_mex_destroy(&c3_lhs58);
  sf_mex_destroy(&c3_rhs59);
  sf_mex_destroy(&c3_lhs59);
  sf_mex_destroy(&c3_rhs60);
  sf_mex_destroy(&c3_lhs60);
  sf_mex_destroy(&c3_rhs61);
  sf_mex_destroy(&c3_lhs61);
  sf_mex_destroy(&c3_rhs62);
  sf_mex_destroy(&c3_lhs62);
  sf_mex_destroy(&c3_rhs63);
  sf_mex_destroy(&c3_lhs63);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static void c3_b_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs64 = NULL;
  const mxArray *c3_lhs64 = NULL;
  const mxArray *c3_rhs65 = NULL;
  const mxArray *c3_lhs65 = NULL;
  const mxArray *c3_rhs66 = NULL;
  const mxArray *c3_lhs66 = NULL;
  const mxArray *c3_rhs67 = NULL;
  const mxArray *c3_lhs67 = NULL;
  const mxArray *c3_rhs68 = NULL;
  const mxArray *c3_lhs68 = NULL;
  const mxArray *c3_rhs69 = NULL;
  const mxArray *c3_lhs69 = NULL;
  const mxArray *c3_rhs70 = NULL;
  const mxArray *c3_lhs70 = NULL;
  const mxArray *c3_rhs71 = NULL;
  const mxArray *c3_lhs71 = NULL;
  const mxArray *c3_rhs72 = NULL;
  const mxArray *c3_lhs72 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 64);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 64);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c3_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 65);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c3_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 66);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 66);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c3_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 67);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c3_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 68);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 68);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c3_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 69);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 69);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c3_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 70);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 70);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c3_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "context", "context", 71);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 71);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c3_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/cmdBML_AUs.m"),
                  "context", "context", 72);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  72);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c3_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs72), "lhs", "lhs",
                  72);
  sf_mex_destroy(&c3_rhs64);
  sf_mex_destroy(&c3_lhs64);
  sf_mex_destroy(&c3_rhs65);
  sf_mex_destroy(&c3_lhs65);
  sf_mex_destroy(&c3_rhs66);
  sf_mex_destroy(&c3_lhs66);
  sf_mex_destroy(&c3_rhs67);
  sf_mex_destroy(&c3_lhs67);
  sf_mex_destroy(&c3_rhs68);
  sf_mex_destroy(&c3_lhs68);
  sf_mex_destroy(&c3_rhs69);
  sf_mex_destroy(&c3_lhs69);
  sf_mex_destroy(&c3_rhs70);
  sf_mex_destroy(&c3_lhs70);
  sf_mex_destroy(&c3_rhs71);
  sf_mex_destroy(&c3_lhs71);
  sf_mex_destroy(&c3_rhs72);
  sf_mex_destroy(&c3_lhs72);
}

static void c3_sendBML(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance,
  real_T c3_arg[256])
{
  int32_T c3_i133;
  int32_T c3_i134;
  int32_T c3_i135;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  for (c3_i133 = 0; c3_i133 < 256; c3_i133++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i133], 5U);
  }

  _SFD_SET_DATA_VALUE_PTR(5U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_s_sf_marshallOut,
    c3_r_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c3_sfEvent);
  for (c3_i134 = 0; c3_i134 < 256; c3_i134++) {
    (*c3_b_arg)[c3_i134] = c3_arg[c3_i134];
  }

  for (c3_i135 = 0; c3_i135 < 256; c3_i135++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i135], 5U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(5U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c3_sfEvent);
}

static void c3_EAU(SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance,
                   real_T c3_E, real_T c3_AU_data[], int32_T c3_AU_sizes[2])
{
  uint32_T c3_debug_family_var_map[13];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  boolean_T c3_aVarTruthTableCondition_3;
  boolean_T c3_aVarTruthTableCondition_4;
  boolean_T c3_aVarTruthTableCondition_5;
  boolean_T c3_aVarTruthTableCondition_6;
  boolean_T c3_aVarTruthTableCondition_7;
  boolean_T c3_aVarTruthTableCondition_8;
  boolean_T c3_aVarTruthTableCondition_9;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_AU;
  int32_T c3_b_AU;
  int32_T c3_i136;
  static real_T c3_dv13[3] = { 6.0, 12.0, 142.0 };

  int32_T c3_c_AU;
  int32_T c3_d_AU;
  int32_T c3_i137;
  static real_T c3_dv14[3] = { 1.0, 2.0, 144.0 };

  int32_T c3_e_AU;
  int32_T c3_f_AU;
  int32_T c3_i138;
  static real_T c3_dv15[6] = { 1.0, 2.0, 4.0, 20.0, 26.0, 386.0 };

  int32_T c3_g_AU;
  int32_T c3_h_AU;
  int32_T c3_i139;
  int32_T c3_i_AU;
  int32_T c3_j_AU;
  int32_T c3_i140;
  int32_T c3_k_AU;
  int32_T c3_l_AU;
  int32_T c3_i141;
  static real_T c3_dv16[3] = { 12.0, 14.0, 143.0 };

  int32_T c3_m_AU;
  int32_T c3_n_AU;
  int32_T c3_i142;
  int32_T c3_o_AU;
  int32_T c3_p_AU;
  int32_T c3_i143;
  static real_T c3_dv17[4] = { 1.0, 4.0, 15.0, 180.0 };

  int32_T c3_q_AU;
  int32_T c3_r_AU;
  int32_T c3_i144;
  static real_T c3_dv18[7] = { 4.0, 5.0, 7.0, 10.0, 23.0, 26.0, 410.0 };

  int32_T c3_s_AU;
  int32_T c3_t_AU;
  int32_T c3_i145;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c3_n_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_3, 2U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_4, 3U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_5, 4U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_6, 5U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_7, 6U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_8, 7U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_9, 8U,
    c3_l_sf_marshallOut, c3_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_E, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_AU_data, (const int32_T *)
    c3_AU_sizes, NULL, 0, 12, (void *)c3_k_sf_marshallOut, (void *)
    c3_k_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_aVarTruthTableCondition_1 = (c3_E == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  c3_aVarTruthTableCondition_2 = (c3_E == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  c3_aVarTruthTableCondition_3 = (c3_E == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_aVarTruthTableCondition_4 = (c3_E == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_aVarTruthTableCondition_5 = (c3_E == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
  c3_aVarTruthTableCondition_6 = (c3_E == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  c3_aVarTruthTableCondition_7 = (c3_E == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
  c3_aVarTruthTableCondition_8 = (c3_E == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
  c3_aVarTruthTableCondition_9 = (c3_E == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
  if (CV_EML_IF(0, 1, 0, c3_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 76);
    c3_AU_sizes[0] = 1;
    c3_AU_sizes[1] = 3;
    c3_AU = c3_AU_sizes[0];
    c3_b_AU = c3_AU_sizes[1];
    for (c3_i136 = 0; c3_i136 < 3; c3_i136++) {
      c3_AU_data[c3_i136] = c3_dv13[c3_i136];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -76);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
    if (CV_EML_IF(0, 1, 1, c3_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
      c3_AU_sizes[0] = 1;
      c3_AU_sizes[1] = 3;
      c3_c_AU = c3_AU_sizes[0];
      c3_d_AU = c3_AU_sizes[1];
      for (c3_i137 = 0; c3_i137 < 3; c3_i137++) {
        c3_AU_data[c3_i137] = c3_dv14[c3_i137];
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -81);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
      if (CV_EML_IF(0, 1, 2, c3_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 86);
        c3_AU_sizes[0] = 1;
        c3_AU_sizes[1] = 6;
        c3_e_AU = c3_AU_sizes[0];
        c3_f_AU = c3_AU_sizes[1];
        for (c3_i138 = 0; c3_i138 < 6; c3_i138++) {
          c3_AU_data[c3_i138] = c3_dv15[c3_i138];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -86);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
        if (CV_EML_IF(0, 1, 3, c3_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 91);
          c3_AU_sizes[0] = 1;
          c3_AU_sizes[1] = 3;
          c3_g_AU = c3_AU_sizes[0];
          c3_h_AU = c3_AU_sizes[1];
          for (c3_i139 = 0; c3_i139 < 3; c3_i139++) {
            c3_AU_data[c3_i139] = c3_dv14[c3_i139];
          }

          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -91);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
          if (CV_EML_IF(0, 1, 4, c3_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
            c3_AU_sizes[0] = 1;
            c3_AU_sizes[1] = 3;
            c3_i_AU = c3_AU_sizes[0];
            c3_j_AU = c3_AU_sizes[1];
            for (c3_i140 = 0; c3_i140 < 3; c3_i140++) {
              c3_AU_data[c3_i140] = c3_dv13[c3_i140];
            }

            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -96);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 60);
            if (CV_EML_IF(0, 1, 5, c3_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 61);
              CV_EML_FCN(0, 6);
              _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 101);
              c3_AU_sizes[0] = 1;
              c3_AU_sizes[1] = 3;
              c3_k_AU = c3_AU_sizes[0];
              c3_l_AU = c3_AU_sizes[1];
              for (c3_i141 = 0; c3_i141 < 3; c3_i141++) {
                c3_AU_data[c3_i141] = c3_dv16[c3_i141];
              }

              _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -101);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
              if (CV_EML_IF(0, 1, 6, c3_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 63);
                CV_EML_FCN(0, 7);
                _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 106);
                c3_AU_sizes[0] = 1;
                c3_AU_sizes[1] = 3;
                c3_m_AU = c3_AU_sizes[0];
                c3_n_AU = c3_AU_sizes[1];
                for (c3_i142 = 0; c3_i142 < 3; c3_i142++) {
                  c3_AU_data[c3_i142] = c3_dv13[c3_i142];
                }

                _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -106);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 64);
                if (CV_EML_IF(0, 1, 7, c3_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 65);
                  CV_EML_FCN(0, 8);
                  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 111);
                  c3_AU_sizes[0] = 1;
                  c3_AU_sizes[1] = 4;
                  c3_o_AU = c3_AU_sizes[0];
                  c3_p_AU = c3_AU_sizes[1];
                  for (c3_i143 = 0; c3_i143 < 4; c3_i143++) {
                    c3_AU_data[c3_i143] = c3_dv17[c3_i143];
                  }

                  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
                  if (CV_EML_IF(0, 1, 8, c3_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
                    CV_EML_FCN(0, 9);
                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 116);
                    c3_AU_sizes[0] = 1;
                    c3_AU_sizes[1] = 7;
                    c3_q_AU = c3_AU_sizes[0];
                    c3_r_AU = c3_AU_sizes[1];
                    for (c3_i144 = 0; c3_i144 < 7; c3_i144++) {
                      c3_AU_data[c3_i144] = c3_dv18[c3_i144];
                    }

                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -116);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 69);
                    CV_EML_FCN(0, 5);
                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
                    c3_AU_sizes[0] = 1;
                    c3_AU_sizes[1] = 3;
                    c3_s_AU = c3_AU_sizes[0];
                    c3_t_AU = c3_AU_sizes[1];
                    for (c3_i145 = 0; c3_i145 < 3; c3_i145++) {
                      c3_AU_data[c3_i145] = c3_dv13[c3_i145];
                    }

                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -96);
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -69);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_v_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i146;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i146, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i146;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_secs;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_secs = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_secs), &c3_thisId);
  sf_mex_destroy(&c3_secs);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_w_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i147;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i147, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i147;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_x_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_p, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_p), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_p);
  return c3_y;
}

static uint8_T c3_y_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
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

static void c3_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_p;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_b_tp_p = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_p), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_p);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i148;
  real_T c3_b_inData[256];
  int32_T c3_i149;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i148 = 0; c3_i148 < 256; c3_i148++) {
    c3_b_inData[c3_i148] = (*(real_T (*)[256])c3_inData)[c3_i148];
  }

  for (c3_i149 = 0; c3_i149 < 256; c3_i149++) {
    c3_u[c3_i149] = c3_b_inData[c3_i149];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_ab_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv19[256];
  int32_T c3_i150;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv19, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c3_i150 = 0; c3_i150 < 256; c3_i150++) {
    c3_y[c3_i150] = c3_dv19[c3_i150];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arg;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i151;
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)chartInstanceVoid;
  c3_arg = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arg), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arg);
  for (c3_i151 = 0; c3_i151 < 256; c3_i151++) {
    (*(real_T (*)[256])c3_outData)[c3_i151] = c3_y[c3_i151];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static uint32_T c3_bb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_b_method, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_method),
    &c3_thisId);
  sf_mex_destroy(&c3_b_method);
  return c3_y;
}

static uint32_T c3_cb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u1;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_method_not_empty = false;
  } else {
    chartInstance->c3_method_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u1;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint32_T c3_db_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state),
    &c3_thisId);
  sf_mex_destroy(&c3_d_state);
  return c3_y;
}

static uint32_T c3_eb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u2;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_state_not_empty = false;
  } else {
    chartInstance->c3_state_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u2, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u2;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_fb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[625])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_d_state);
}

static void c3_gb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[625])
{
  uint32_T c3_uv8[625];
  int32_T c3_i152;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_c_state_not_empty = false;
  } else {
    chartInstance->c3_c_state_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv8, 1, 7, 0U, 1, 0U, 1, 625);
    for (c3_i152 = 0; c3_i152 < 625; c3_i152++) {
      c3_y[c3_i152] = c3_uv8[c3_i152];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_hb_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_d_state);
}

static void c3_ib_emlrt_marshallIn(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[2])
{
  uint32_T c3_uv9[2];
  int32_T c3_i153;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_b_state_not_empty = false;
  } else {
    chartInstance->c3_b_state_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv9, 1, 7, 0U, 1, 0U, 1, 2);
    for (c3_i153 = 0; c3_i153 < 2; c3_i153++) {
      c3_y[c3_i153] = c3_uv9[c3_i153];
    }
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_jb_emlrt_marshallIn
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_kb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_kb_emlrt_marshallIn
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, const mxArray *c3_u,
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

static void c3_updateDataWrittenToVector
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex)
{
  (void)chartInstance;
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 2, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn
  (SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 2, 1,
    0)]);
}

static void c3_b_twister_state_vector(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed)
{
  uint32_T c3_r;
  int32_T c3_mti;
  real_T c3_b_mti;
  real_T c3_d4;
  uint32_T c3_u3;
  (void)chartInstance;
  (void)c3_seed;
  c3_r = 5489U;
  c3_mt[0] = 5489U;
  for (c3_mti = 0; c3_mti < 623; c3_mti++) {
    c3_b_mti = 2.0 + (real_T)c3_mti;
    c3_d4 = muDoubleScalarRound(c3_b_mti - 1.0);
    if (c3_d4 < 4.294967296E+9) {
      if (c3_d4 >= 0.0) {
        c3_u3 = (uint32_T)c3_d4;
      } else {
        c3_u3 = 0U;
      }
    } else if (c3_d4 >= 4.294967296E+9) {
      c3_u3 = MAX_uint32_T;
    } else {
      c3_u3 = 0U;
    }

    c3_r = (c3_r ^ c3_r >> 30U) * 1812433253U + c3_u3;
    c3_mt[(int32_T)c3_b_mti - 1] = c3_r;
  }

  c3_mt[624] = 624U;
}

static real_T c3_c_eml_rand_mt19937ar(SFc3_ARP_02_PointUser_AnTSInstanceStruct
  *chartInstance, uint32_T c3_d_state[625])
{
  int32_T c3_i154;
  uint32_T c3_u[2];
  int32_T c3_j;
  real_T c3_b_j;
  uint32_T c3_mti;
  int32_T c3_kk;
  real_T c3_b_kk;
  uint32_T c3_y;
  uint32_T c3_b_y;
  uint32_T c3_c_y;
  int32_T c3_c_kk;
  uint32_T c3_d_y;
  uint32_T c3_e_y;
  uint32_T c3_f_y;
  uint32_T c3_g_y;
  real_T c3_b_r;
  boolean_T c3_b4;
  boolean_T c3_isvalid;
  int32_T c3_k;
  int32_T c3_a;
  int32_T c3_b_a;
  real_T c3_d5;
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
    for (c3_i154 = 0; c3_i154 < 2; c3_i154++) {
      c3_u[c3_i154] = 0U;
    }

    for (c3_j = 0; c3_j < 2; c3_j++) {
      c3_b_j = 1.0 + (real_T)c3_j;
      c3_mti = c3_d_state[624] + 1U;
      if ((real_T)c3_mti >= 625.0) {
        for (c3_kk = 0; c3_kk < 227; c3_kk++) {
          c3_b_kk = 1.0 + (real_T)c3_kk;
          c3_y = (c3_d_state[(int32_T)c3_b_kk - 1] & 2147483648U) | (c3_d_state
            [(int32_T)(c3_b_kk + 1.0) - 1] & 2147483647U);
          c3_b_y = c3_y;
          c3_c_y = c3_b_y;
          if ((real_T)(c3_c_y & 1U) == 0.0) {
            c3_c_y >>= 1U;
          } else {
            c3_c_y = c3_c_y >> 1U ^ 2567483615U;
          }

          c3_d_state[(int32_T)c3_b_kk - 1] = c3_d_state[(int32_T)(c3_b_kk +
            397.0) - 1] ^ c3_c_y;
        }

        for (c3_c_kk = 0; c3_c_kk < 396; c3_c_kk++) {
          c3_b_kk = 228.0 + (real_T)c3_c_kk;
          c3_y = (c3_d_state[(int32_T)c3_b_kk - 1] & 2147483648U) | (c3_d_state
            [(int32_T)(c3_b_kk + 1.0) - 1] & 2147483647U);
          c3_d_y = c3_y;
          c3_e_y = c3_d_y;
          if ((real_T)(c3_e_y & 1U) == 0.0) {
            c3_e_y >>= 1U;
          } else {
            c3_e_y = c3_e_y >> 1U ^ 2567483615U;
          }

          c3_d_state[(int32_T)c3_b_kk - 1] = c3_d_state[(int32_T)((c3_b_kk + 1.0)
            - 228.0) - 1] ^ c3_e_y;
        }

        c3_y = (c3_d_state[623] & 2147483648U) | (c3_d_state[0] & 2147483647U);
        c3_f_y = c3_y;
        c3_g_y = c3_f_y;
        if ((real_T)(c3_g_y & 1U) == 0.0) {
          c3_g_y >>= 1U;
        } else {
          c3_g_y = c3_g_y >> 1U ^ 2567483615U;
        }

        c3_d_state[623] = c3_d_state[396] ^ c3_g_y;
        c3_mti = 1U;
      }

      c3_y = c3_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c3_mti, 1, 625, 1, 0) - 1];
      c3_d_state[624] = c3_mti;
      c3_y ^= c3_y >> 11U;
      c3_y ^= c3_y << 7U & 2636928640U;
      c3_y ^= c3_y << 15U & 4022730752U;
      c3_y ^= c3_y >> 18U;
      c3_u[(int32_T)c3_b_j - 1] = c3_y;
    }

    c3_u[0] >>= 5U;
    c3_u[1] >>= 6U;
    c3_b_r = 1.1102230246251565E-16 * ((real_T)c3_u[0] * 6.7108864E+7 + (real_T)
      c3_u[1]);
    if (c3_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c3_d_state[624] >= 1.0) {
        if ((real_T)c3_d_state[624] < 625.0) {
          c3_b4 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c3_b4 = false;
      }

      c3_isvalid = c3_b4;
      if (c3_isvalid) {
        c3_isvalid = false;
        c3_k = 0;
        exitg2 = false;
        while ((exitg2 == false) && (c3_k + 1 < 625)) {
          if ((real_T)c3_d_state[c3_k] == 0.0) {
            c3_a = c3_k + 1;
            c3_b_a = c3_a;
            c3_k = c3_b_a;
          } else {
            c3_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c3_isvalid) {
        c3_eml_error(chartInstance);
        c3_d5 = 5489.0;
        c3_b_twister_state_vector(chartInstance, c3_d_state, c3_d5);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c3_b_r;
}

static void init_dsm_address_info(SFc3_ARP_02_PointUser_AnTSInstanceStruct
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

void sf_c3_ARP_02_PointUser_AnTS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2048599917U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(516952938U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(345166050U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2157783938U);
}

mxArray *sf_c3_ARP_02_PointUser_AnTS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BPrdeq9bC3u5ubtbqodBAC");
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_ARP_02_PointUser_AnTS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_ARP_02_PointUser_AnTS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_ARP_02_PointUser_AnTS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[180],T\"agentState\",},{M[3],M[17],T\"round_count\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c3_ARP_02_PointUser_AnTS\",},{M[8],M[233],T\"is_active_1\",},{M[8],M[250],T\"is_active_2\",},{M[9],M[0],T\"is_c3_ARP_02_PointUser_AnTS\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[9],M[233],T\"is_1\",},{M[9],M[250],T\"is_2\",},{M[11],M[194],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M[254],M[1]}}},{M[11],M[194],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x5[249 243 248 247 244],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ARP_02_PointUser_AnTS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_PointUser_AnTSMachineNumber_,
           3,
           11,
           10,
           0,
           8,
           1,
           0,
           0,
           0,
           6,
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
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"round_count");
          _SFD_SET_DATA_PROPS(1,1,1,0,"step");
          _SFD_SET_DATA_PROPS(2,1,1,0,"xd");
          _SFD_SET_DATA_PROPS(3,1,1,0,"internalE");
          _SFD_SET_DATA_PROPS(4,2,0,1,"agentState");
          _SFD_SET_DATA_PROPS(5,8,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(1,1,0);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_ST_SUBSTATE_COUNT(1,2);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,8);
          _SFD_ST_SUBSTATE_COUNT(2,5);
          _SFD_ST_SUBSTATE_INDEX(2,0,3);
          _SFD_ST_SUBSTATE_INDEX(2,1,4);
          _SFD_ST_SUBSTATE_INDEX(2,2,5);
          _SFD_ST_SUBSTATE_INDEX(2,3,6);
          _SFD_ST_SUBSTATE_INDEX(2,4,7);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,1);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_COUNT(9,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(1,2,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,5,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(8,1,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,10,9,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"EAU",0,-1,1473);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1473,-1,1539);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1539,-1,1590);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1590,-1,1649);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1649,-1,1700);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1700,-1,1752);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",1752,-1,1805);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",1805,-1,1857);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",1857,-1,1911);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",1911,-1,1972);
        _SFD_CV_INIT_EML_IF(0,1,0,842,872,903,1471);
        _SFD_CV_INIT_EML_IF(0,1,1,903,937,968,1471);
        _SFD_CV_INIT_EML_IF(0,1,2,968,1002,1033,1471);
        _SFD_CV_INIT_EML_IF(0,1,3,1033,1067,1098,1471);
        _SFD_CV_INIT_EML_IF(0,1,4,1098,1132,1163,1471);
        _SFD_CV_INIT_EML_IF(0,1,5,1163,1197,1228,1471);
        _SFD_CV_INIT_EML_IF(0,1,6,1228,1262,1293,1471);
        _SFD_CV_INIT_EML_IF(0,1,7,1293,1327,1358,1471);
        _SFD_CV_INIT_EML_IF(0,1,8,1358,1392,1423,1471);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"cmdBML_idle",0,-1,506);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"cmdBML_pointRt",0,-1,512);
        _SFD_CV_INIT_SCRIPT(3,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"cmdBML_pointLf",0,-1,737);
        _SFD_CV_INIT_SCRIPT_IF(3,0,370,380,552,733);
        _SFD_CV_INIT_SCRIPT(4,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"cmdBML_target",0,-1,517);
        _SFD_CV_INIT_SCRIPT(5,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"cmdBML_AUs",0,-1,864);
        _SFD_CV_INIT_SCRIPT_IF(5,0,317,351,543,727);
        _SFD_CV_INIT_SCRIPT_FOR(5,0,271,296,731);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,0,19,0,19);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,0,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,0,18,0,18);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 18 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,0,18,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,0,19,0,19);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,0,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_s_sf_marshallOut,(MexInFcnForType)
            c3_r_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));

        {
          real_T *c3_step;
          real_T *c3_xd;
          real_T *c3_internalE;
          real_T *c3_agentState;
          c3_agentState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_xd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c3_round_count);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_step);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_xd);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_internalE);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_agentState);
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
  return "6057eR81smXpoBTeJWbdLF";
}

static void sf_opaque_initialize_c3_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_ARP_02_PointUser_AnTS
    ((SFc3_ARP_02_PointUser_AnTSInstanceStruct*) chartInstanceVar);
  initialize_c3_ARP_02_PointUser_AnTS((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  enable_c3_ARP_02_PointUser_AnTS((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  disable_c3_ARP_02_PointUser_AnTS((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  sf_gateway_c3_ARP_02_PointUser_AnTS((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_ARP_02_PointUser_AnTS
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_ARP_02_PointUser_AnTS
    ((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ARP_02_PointUser_AnTS();/* state var info */
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

extern void sf_internal_set_sim_state_c3_ARP_02_PointUser_AnTS(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_ARP_02_PointUser_AnTS();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_ARP_02_PointUser_AnTS
    ((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_ARP_02_PointUser_AnTS(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c3_ARP_02_PointUser_AnTS(S);
}

static void sf_opaque_set_sim_state_c3_ARP_02_PointUser_AnTS(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_ARP_02_PointUser_AnTS(S, st);
}

static void sf_opaque_terminate_c3_ARP_02_PointUser_AnTS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ARP_02_PointUser_AnTSInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_PointUser_AnTS_optimization_info();
    }

    finalize_c3_ARP_02_PointUser_AnTS((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)
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
  initSimStructsc3_ARP_02_PointUser_AnTS
    ((SFc3_ARP_02_PointUser_AnTSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ARP_02_PointUser_AnTS(SimStruct *S)
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
    initialize_params_c3_ARP_02_PointUser_AnTS
      ((SFc3_ARP_02_PointUser_AnTSInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_ARP_02_PointUser_AnTS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_PointUser_AnTS_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,3,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(656283956U));
  ssSetChecksum1(S,(368363868U));
  ssSetChecksum2(S,(2484081962U));
  ssSetChecksum3(S,(918998101U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ARP_02_PointUser_AnTS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_ARP_02_PointUser_AnTS(SimStruct *S)
{
  SFc3_ARP_02_PointUser_AnTSInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_ARP_02_PointUser_AnTSInstanceStruct *)utMalloc(sizeof
    (SFc3_ARP_02_PointUser_AnTSInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ARP_02_PointUser_AnTSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ARP_02_PointUser_AnTS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_ARP_02_PointUser_AnTS;
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

void c3_ARP_02_PointUser_AnTS_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ARP_02_PointUser_AnTS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ARP_02_PointUser_AnTS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ARP_02_PointUser_AnTS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ARP_02_PointUser_AnTS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
