/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_EP_IdleRandMerg_sfun.h"
#include "c11_Demo_EP_IdleRandMerg.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_EP_IdleRandMerg_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c11_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_checkP                  ((uint8_T)1U)
#define c11_IN_gazeCamera              ((uint8_T)2U)
#define c11_IN_stateCheckSmile         ((uint8_T)3U)
#define c11_IN_stateInitial            ((uint8_T)4U)
#define c11_IN_wait                    ((uint8_T)5U)
#define c11_IN_initial                 ((uint8_T)1U)
#define c11_IN_stateFacialExpression   ((uint8_T)2U)
#define c11_b_IN_wait                  ((uint8_T)3U)
#define c11_IN_wait2                   ((uint8_T)4U)
#define c11_IN_wait3                   ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c11_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_c_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c11_d_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c11_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_g_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c11_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_i_debug_family_names[5] = { "nargin", "nargout", "E",
  "AU", "L" };

static const char * c11_j_debug_family_names[13] = { "pFactor", "a_factor",
  "v_factor", "c", "nargin", "nargout", "E", "p", "cFactor", "AU", "arousal",
  "valence", "eAmountFactor" };

static const char * c11_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_o_debug_family_names[4] = { "nargin", "nargout", "x",
  "num" };

static const char * c11_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c11_q_debug_family_names[22] = { "csum", "str1", "j", "AU",
  "eA", "c1", "c2", "temp", "temp2", "currentTime", "all_AUs", "c", "filename",
  "fileID", "str2", "mystr", "nargin", "nargout", "arrAU", "eAmount", "L",
  "arrBML" };

static const char * c11_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c11_dataWrittenToVector[21];

/* Function Declarations */
static void initialize_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initialize_params_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void enable_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void disable_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void set_sim_state_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c11_st);
static void c11_set_sim_state_side_effects_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void finalize_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void sf_gateway_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_enter_atomic_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_enter_internal_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_exit_internal_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_initc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initSimStructsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_subSmile(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_enter_atomic_gazeCamera(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void c11_enter_atomic_checkP(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void c11_enter_atomic_stateFacialExpression
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000]);
static void c11_b_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000]);
static void c11_c_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000]);
static void c11_d_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000]);
static void c11_cmdBML_AUmerg(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_arrAU[6], real_T c11_eAmount[6], real_T c11_L,
  real_T c11_arrBML[1000]);
static real_T c11_countDigits(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_x);
static real_T c11_log10(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T c11_x);
static real_T c11_ceil(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T c11_x);
static void c11_eml_scalar_eg(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void c11_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_b_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_c_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_d_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_e_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, char_T c11_mystr_data[], int32_T c11_mystr_sizes[2], real_T
  c11_myarr256[1000]);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static void c11_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_strcat, const char_T *c11_identifier,
  char_T c11_y_data[], int32_T c11_y_sizes[2]);
static void c11_b_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2]);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_newBmls, const char_T *c11_identifier,
  real_T c11_y[5000]);
static void c11_d_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[5000]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_e_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_myBML, const char_T *c11_identifier, real_T
  c11_y[1000]);
static void c11_f_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1000]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_g_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_nargout, const char_T *c11_identifier);
static real_T c11_h_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_i_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_myarr256, const char_T *c11_identifier,
  real_T c11_y[1000]);
static void c11_j_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1000]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_k_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_l_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_AU, const char_T *c11_identifier, real_T
  c11_y[6]);
static void c11_m_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6]);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, char_T
  c11_inData_data[], int32_T c11_inData_sizes[2]);
static void c11_n_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2]);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, char_T c11_outData_data[],
  int32_T c11_outData_sizes[2]);
static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, real_T
  c11_inData_data[], int32_T *c11_inData_sizes);
static void c11_o_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y_data[], int32_T *c11_y_sizes);
static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, real_T c11_outData_data[],
  int32_T *c11_outData_sizes);
static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_p_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[103]);
static void c11_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_q_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[206]);
static void c11_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_r_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_r_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[306]);
static void c11_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_s_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_s_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[412]);
static void c11_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_t_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_t_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[515]);
static void c11_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_u_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_u_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[656]);
static void c11_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_v_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_w_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_v_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9]);
static void c11_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_activate_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_deactivate_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_increment_counters_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_reset_counters_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c11_insertQueuec11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmls[5000],
   real_T c11_myBML[1000], real_T c11_newBmls[5000]);
static void c11_insertQueueLowc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmls[5000],
   real_T c11_myBML[1000], real_T c11_newBmls[5000]);
static void c11_smileTablec11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmlID,
   real_T *c11_p, real_T c11_poseBML[1000]);
static void c11_facialExprc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmlID,
   real_T *c11_p, real_T c11_poseBML[1000]);
static void c11_setAUc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_E, real_T
   c11_AU[6], real_T *c11_L);
static void c11_set_eAmountFactorc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_E, real_T
   c11_p, real_T c11_cFactor, real_T c11_AU[6], real_T c11_arousal, real_T
   c11_valence, real_T c11_eAmountFactor[6]);
static boolean_T c11_isequal(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_varargin_1[1000], real_T c11_varargin_2[1000]);
static real_T c11_abs(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
                      real_T c11_x);
static const mxArray *c11_x_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int8_T c11_w_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_y_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_x_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_y_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_subSmile, const char_T *c11_identifier);
static uint8_T c11_ab_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_bb_emlrt_marshallIn
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier);
static const mxArray *c11_cb_emlrt_marshallIn
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray *c11_u,
   const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex);
static void c11_errorIfDataNotWrittenToFcn
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex, uint32_T c11_dataNumber);
static void c11_b_log10(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T *c11_x);
static void c11_b_ceil(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T *c11_x);
static real_T c11_get_BML(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_BML(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_BML(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_GAZE_WIN(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_GAZE_WIN(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_GAZE_WIN(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_P(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_P(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
                      uint32_T c11_b, real_T c11_c);
static real_T *c11_access_P(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_BEFORE(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_BEFORE(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_BEFORE(SFc11_Demo_EP_IdleRandMergInstanceStruct *
  chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_GO(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_GO(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_GO(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_READY(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_READY(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_READY(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_avert(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_avert(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_bmlsL(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_bmlsL(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_bmlsL(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_bmlsM(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_bmlsM(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_bmlsM(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_emotion_amount_factor
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T c11_b);
static void c11_set_emotion_amount_factor
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T c11_b,
   real_T c11_c);
static real_T *c11_access_emotion_amount_factor
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_gazing(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_gazing(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_gazing(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b);
static void init_dsm_address_info(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_debugger_state_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_Demo_EP_IdleRandMerg == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_active_subSmile == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_stateCheckSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_checkP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_active_subFacial == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_stateFacialExpression) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_initial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_b_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_wait3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_wait2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  int32_T c11_i0;
  real_T c11_b_u[1000];
  const mxArray *c11_c_y = NULL;
  int32_T c11_i1;
  real_T c11_c_u[1000];
  const mxArray *c11_d_y = NULL;
  int32_T c11_i2;
  real_T c11_d_u[6];
  const mxArray *c11_e_y = NULL;
  real_T c11_b_hoistedGlobal;
  real_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_f_u;
  const mxArray *c11_g_y = NULL;
  real_T c11_d_hoistedGlobal;
  real_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  real_T c11_e_hoistedGlobal;
  real_T c11_h_u;
  const mxArray *c11_i_y = NULL;
  int32_T c11_i3;
  real_T c11_i_u[1000];
  const mxArray *c11_j_y = NULL;
  int32_T c11_i4;
  real_T c11_j_u[5000];
  const mxArray *c11_k_y = NULL;
  int32_T c11_i5;
  real_T c11_k_u[5000];
  const mxArray *c11_l_y = NULL;
  real_T c11_f_hoistedGlobal;
  real_T c11_l_u;
  const mxArray *c11_m_y = NULL;
  uint8_T c11_g_hoistedGlobal;
  uint8_T c11_m_u;
  const mxArray *c11_n_y = NULL;
  uint8_T c11_h_hoistedGlobal;
  uint8_T c11_n_u;
  const mxArray *c11_o_y = NULL;
  uint8_T c11_i_hoistedGlobal;
  uint8_T c11_o_u;
  const mxArray *c11_p_y = NULL;
  uint8_T c11_j_hoistedGlobal;
  uint8_T c11_p_u;
  const mxArray *c11_q_y = NULL;
  uint8_T c11_k_hoistedGlobal;
  uint8_T c11_q_u;
  const mxArray *c11_r_y = NULL;
  uint8_T c11_l_hoistedGlobal;
  uint8_T c11_r_u;
  const mxArray *c11_s_y = NULL;
  uint8_T c11_m_hoistedGlobal;
  uint8_T c11_s_u;
  const mxArray *c11_t_y = NULL;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(19, 1), false);
  c11_hoistedGlobal = *c11_gameState;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  for (c11_i0 = 0; c11_i0 < 1000; c11_i0++) {
    c11_b_u[c11_i0] = chartInstance->c11_BMLM[c11_i0];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  for (c11_i1 = 0; c11_i1 < 1000; c11_i1++) {
    c11_c_u[c11_i1] = chartInstance->c11_BMLl[c11_i1];
  }

  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  for (c11_i2 = 0; c11_i2 < 6; c11_i2++) {
    c11_d_u[c11_i2] = chartInstance->c11_au[c11_i2];
  }

  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_d_u, 0, 0U, 1U, 0U, 2, 1, 6),
                false);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_b_hoistedGlobal = chartInstance->c11_au_L;
  c11_e_u = c11_b_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  c11_c_hoistedGlobal = chartInstance->c11_au_i;
  c11_f_u = c11_c_hoistedGlobal;
  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 5, c11_g_y);
  c11_d_hoistedGlobal = chartInstance->c11_emoDisp;
  c11_g_u = c11_d_hoistedGlobal;
  c11_h_y = NULL;
  sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 6, c11_h_y);
  c11_e_hoistedGlobal = chartInstance->c11_fileID;
  c11_h_u = c11_e_hoistedGlobal;
  c11_i_y = NULL;
  sf_mex_assign(&c11_i_y, sf_mex_create("y", &c11_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 7, c11_i_y);
  for (c11_i3 = 0; c11_i3 < 1000; c11_i3++) {
    c11_i_u[c11_i3] = chartInstance->c11_n[c11_i3];
  }

  c11_j_y = NULL;
  sf_mex_assign(&c11_j_y, sf_mex_create("y", c11_i_u, 0, 0U, 1U, 0U, 1, 1000),
                false);
  sf_mex_setcell(c11_y, 8, c11_j_y);
  for (c11_i4 = 0; c11_i4 < 5000; c11_i4++) {
    c11_j_u[c11_i4] = chartInstance->c11_newBmlsL[c11_i4];
  }

  c11_k_y = NULL;
  sf_mex_assign(&c11_k_y, sf_mex_create("y", c11_j_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c11_y, 9, c11_k_y);
  for (c11_i5 = 0; c11_i5 < 5000; c11_i5++) {
    c11_k_u[c11_i5] = chartInstance->c11_newBmlsM[c11_i5];
  }

  c11_l_y = NULL;
  sf_mex_assign(&c11_l_y, sf_mex_create("y", c11_k_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c11_y, 10, c11_l_y);
  c11_f_hoistedGlobal = chartInstance->c11_smileN;
  c11_l_u = c11_f_hoistedGlobal;
  c11_m_y = NULL;
  sf_mex_assign(&c11_m_y, sf_mex_create("y", &c11_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 11, c11_m_y);
  c11_g_hoistedGlobal = chartInstance->c11_is_active_c11_Demo_EP_IdleRandMerg;
  c11_m_u = c11_g_hoistedGlobal;
  c11_n_y = NULL;
  sf_mex_assign(&c11_n_y, sf_mex_create("y", &c11_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 12, c11_n_y);
  c11_h_hoistedGlobal = chartInstance->c11_is_active_subSmile;
  c11_n_u = c11_h_hoistedGlobal;
  c11_o_y = NULL;
  sf_mex_assign(&c11_o_y, sf_mex_create("y", &c11_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 13, c11_o_y);
  c11_i_hoistedGlobal = chartInstance->c11_is_active_subFacial;
  c11_o_u = c11_i_hoistedGlobal;
  c11_p_y = NULL;
  sf_mex_assign(&c11_p_y, sf_mex_create("y", &c11_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 14, c11_p_y);
  c11_j_hoistedGlobal = chartInstance->c11_is_subSmile;
  c11_p_u = c11_j_hoistedGlobal;
  c11_q_y = NULL;
  sf_mex_assign(&c11_q_y, sf_mex_create("y", &c11_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 15, c11_q_y);
  c11_k_hoistedGlobal = chartInstance->c11_is_subFacial;
  c11_q_u = c11_k_hoistedGlobal;
  c11_r_y = NULL;
  sf_mex_assign(&c11_r_y, sf_mex_create("y", &c11_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 16, c11_r_y);
  c11_l_hoistedGlobal = chartInstance->c11_temporalCounter_i1;
  c11_r_u = c11_l_hoistedGlobal;
  c11_s_y = NULL;
  sf_mex_assign(&c11_s_y, sf_mex_create("y", &c11_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 17, c11_s_y);
  c11_m_hoistedGlobal = chartInstance->c11_temporalCounter_i2;
  c11_s_u = c11_m_hoistedGlobal;
  c11_t_y = NULL;
  sf_mex_assign(&c11_t_y, sf_mex_create("y", &c11_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 18, c11_t_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[1000];
  int32_T c11_i6;
  real_T c11_dv1[1000];
  int32_T c11_i7;
  real_T c11_dv2[6];
  int32_T c11_i8;
  real_T c11_dv3[1000];
  int32_T c11_i9;
  real_T c11_dv4[5000];
  int32_T c11_i10;
  real_T c11_dv5[5000];
  int32_T c11_i11;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_u = sf_mex_dup(c11_st);
  *c11_gameState = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 0)), "gameState");
  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "BMLM", c11_dv0);
  for (c11_i6 = 0; c11_i6 < 1000; c11_i6++) {
    chartInstance->c11_BMLM[c11_i6] = c11_dv0[c11_i6];
  }

  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
    "BMLl", c11_dv1);
  for (c11_i7 = 0; c11_i7 < 1000; c11_i7++) {
    chartInstance->c11_BMLl[c11_i7] = c11_dv1[c11_i7];
  }

  c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 3)),
    "au", c11_dv2);
  for (c11_i8 = 0; c11_i8 < 6; c11_i8++) {
    chartInstance->c11_au[c11_i8] = c11_dv2[c11_i8];
  }

  chartInstance->c11_au_L = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 4)), "au_L");
  chartInstance->c11_au_i = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 5)), "au_i");
  chartInstance->c11_emoDisp = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 6)), "emoDisp");
  chartInstance->c11_fileID = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 7)), "fileID");
  c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 8)),
    "n", c11_dv3);
  for (c11_i9 = 0; c11_i9 < 1000; c11_i9++) {
    chartInstance->c11_n[c11_i9] = c11_dv3[c11_i9];
  }

  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 9)),
    "newBmlsL", c11_dv4);
  for (c11_i10 = 0; c11_i10 < 5000; c11_i10++) {
    chartInstance->c11_newBmlsL[c11_i10] = c11_dv4[c11_i10];
  }

  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 10)),
    "newBmlsM", c11_dv5);
  for (c11_i11 = 0; c11_i11 < 5000; c11_i11++) {
    chartInstance->c11_newBmlsM[c11_i11] = c11_dv5[c11_i11];
  }

  chartInstance->c11_smileN = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 11)), "smileN");
  chartInstance->c11_is_active_c11_Demo_EP_IdleRandMerg = c11_y_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 12)),
     "is_active_c11_Demo_EP_IdleRandMerg");
  chartInstance->c11_is_active_subSmile = c11_y_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 13)), "is_active_subSmile");
  chartInstance->c11_is_active_subFacial = c11_y_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 14)), "is_active_subFacial");
  chartInstance->c11_is_subSmile = c11_y_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 15)), "is_subSmile");
  chartInstance->c11_is_subFacial = c11_y_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 16)), "is_subFacial");
  chartInstance->c11_temporalCounter_i1 = c11_y_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 17)), "temporalCounter_i1");
  chartInstance->c11_temporalCounter_i2 = c11_y_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 18)), "temporalCounter_i2");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
                  (c11_u, 19)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_Demo_EP_IdleRandMerg(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_active_subSmile == 1U) {
      chartInstance->c11_tp_subSmile = 1U;
    } else {
      chartInstance->c11_tp_subSmile = 0U;
    }

    if (chartInstance->c11_is_subSmile == c11_IN_checkP) {
      chartInstance->c11_tp_checkP = 1U;
    } else {
      chartInstance->c11_tp_checkP = 0U;
    }

    if (chartInstance->c11_is_subSmile == c11_IN_gazeCamera) {
      chartInstance->c11_tp_gazeCamera = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c11_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c11_tp_gazeCamera = 0U;
    }

    if (chartInstance->c11_is_subSmile == c11_IN_stateCheckSmile) {
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      chartInstance->c11_tp_stateCheckSmile = 0U;
    }

    if (chartInstance->c11_is_subSmile == c11_IN_stateInitial) {
      chartInstance->c11_tp_stateInitial = 1U;
    } else {
      chartInstance->c11_tp_stateInitial = 0U;
    }

    if (chartInstance->c11_is_subSmile == c11_IN_wait) {
      chartInstance->c11_tp_wait = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c11_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c11_tp_wait = 0U;
    }

    if (chartInstance->c11_is_active_subFacial == 1U) {
      chartInstance->c11_tp_subFacial = 1U;
    } else {
      chartInstance->c11_tp_subFacial = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_IN_initial) {
      chartInstance->c11_tp_initial = 1U;
    } else {
      chartInstance->c11_tp_initial = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_IN_stateFacialExpression) {
      chartInstance->c11_tp_stateFacialExpression = 1U;
    } else {
      chartInstance->c11_tp_stateFacialExpression = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_b_IN_wait) {
      chartInstance->c11_b_tp_wait = 1U;
    } else {
      chartInstance->c11_b_tp_wait = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_IN_wait2) {
      chartInstance->c11_tp_wait2 = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c11_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c11_tp_wait2 = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_IN_wait3) {
      chartInstance->c11_tp_wait3 = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c11_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c11_tp_wait3 = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  c11_set_sim_state_side_effects_c11_Demo_EP_IdleRandMerg(chartInstance);
}

static void c11_enter_atomic_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_Demo_EP_IdleRandMerg = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_dv6[1000];
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i20;
  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  int32_T c11_i24;
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 0.0;
  int32_T c11_i25;
  int32_T c11_i26;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_active_subSmile = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_subSmile = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_subSmile = c11_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_stateInitial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_k_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  *c11_gameState = 14.0;
  c11_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_gameState, 8U);
  c11_encStr2Arr(chartInstance, c11_dv6);
  for (c11_i12 = 0; c11_i12 < 1000; c11_i12++) {
    chartInstance->c11_n[c11_i12] = c11_dv6[c11_i12];
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  for (c11_i13 = 0; c11_i13 < 1000; c11_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_n[c11_i13], 15U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 5U, 15U);
  for (c11_i14 = 0; c11_i14 < 1000; c11_i14++) {
    c11_set_bmlsM(chartInstance, c11_i14, chartInstance->c11_n[c11_i14]);
  }

  for (c11_i15 = 0; c11_i15 < 1000; c11_i15++) {
    c11_set_bmlsM(chartInstance, c11_i15 + 1000, chartInstance->c11_n[c11_i15]);
  }

  for (c11_i16 = 0; c11_i16 < 1000; c11_i16++) {
    c11_set_bmlsM(chartInstance, c11_i16 + 2000, chartInstance->c11_n[c11_i16]);
  }

  for (c11_i17 = 0; c11_i17 < 1000; c11_i17++) {
    c11_set_bmlsM(chartInstance, c11_i17 + 3000, chartInstance->c11_n[c11_i17]);
  }

  for (c11_i18 = 0; c11_i18 < 1000; c11_i18++) {
    c11_set_bmlsM(chartInstance, c11_i18 + 4000, chartInstance->c11_n[c11_i18]);
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 5U, 15U);
  for (c11_i19 = 0; c11_i19 < 1000; c11_i19++) {
    chartInstance->c11_newBmlsM[c11_i19] = chartInstance->c11_n[c11_i19];
  }

  for (c11_i20 = 0; c11_i20 < 1000; c11_i20++) {
    chartInstance->c11_newBmlsM[c11_i20 + 1000] = chartInstance->c11_n[c11_i20];
  }

  for (c11_i21 = 0; c11_i21 < 1000; c11_i21++) {
    chartInstance->c11_newBmlsM[c11_i21 + 2000] = chartInstance->c11_n[c11_i21];
  }

  for (c11_i22 = 0; c11_i22 < 1000; c11_i22++) {
    chartInstance->c11_newBmlsM[c11_i22 + 3000] = chartInstance->c11_n[c11_i22];
  }

  for (c11_i23 = 0; c11_i23 < 1000; c11_i23++) {
    chartInstance->c11_newBmlsM[c11_i23 + 4000] = chartInstance->c11_n[c11_i23];
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 3U);
  for (c11_i24 = 0; c11_i24 < 5000; c11_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i24], 12U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_active_subFacial = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_subFacial = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_subFacial = c11_IN_initial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_initial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_r_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  for (c11_i25 = 0; c11_i25 < 6; c11_i25++) {
    chartInstance->c11_au[c11_i25] = 0.0;
  }

  c11_updateDataWrittenToVector(chartInstance, 6U);
  for (c11_i26 = 0; c11_i26 < 6; c11_i26++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_au[c11_i26], 18U);
  }

  chartInstance->c11_au_L = 0.0;
  c11_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_L, 22U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[3];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 1.0;
  boolean_T c11_out;
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 1.0;
  boolean_T c11_b_out;
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 1.0;
  boolean_T c11_c_out;
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 1.0;
  boolean_T c11_d_out;
  real_T *c11_internalE;
  c11_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_isStable = true;
  c11_subSmile(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c11_sfEvent);
  switch (chartInstance->c11_is_subFacial) {
   case c11_IN_initial:
    CV_STATE_EVAL(6, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_initial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_subFacial = c11_b_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
    chartInstance->c11_b_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateFacialExpression:
    CV_STATE_EVAL(6, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_y_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_out = CV_EML_IF(11, 0, 0, *c11_internalE == 6.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_b_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_b_tp_wait = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_wait3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
      chartInstance->c11_temporalCounter_i2 = 0U;
      chartInstance->c11_tp_wait3 = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
    break;

   case c11_b_IN_wait:
    CV_STATE_EVAL(6, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_x_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_b_out = CV_EML_IF(8, 0, 0, *c11_internalE != 6.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_b_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 1U;
      c11_enter_atomic_stateFacialExpression(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
      chartInstance->c11_b_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_b_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_b_tp_wait = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait2:
    CV_STATE_EVAL(6, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_bb_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_c_out = CV_EML_IF(14, 0, 0, (chartInstance->c11_sfEvent ==
      c11_event_secs) && (chartInstance->c11_temporalCounter_i2 >= 7));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_wait2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 1U;
      c11_enter_atomic_stateFacialExpression(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait3:
    CV_STATE_EVAL(6, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_ab_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_d_out = CV_EML_IF(16, 0, 0, (chartInstance->c11_sfEvent ==
      c11_event_secs) && (chartInstance->c11_temporalCounter_i2 >= 7));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_wait3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 1U;
      c11_enter_atomic_stateFacialExpression(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 0, 0);
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c11_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  switch (chartInstance->c11_is_subFacial) {
   case c11_IN_initial:
    CV_STATE_EVAL(6, 1, 1);
    chartInstance->c11_tp_initial = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateFacialExpression:
    CV_STATE_EVAL(6, 1, 2);
    chartInstance->c11_tp_stateFacialExpression = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
    break;

   case c11_b_IN_wait:
    CV_STATE_EVAL(6, 1, 3);
    chartInstance->c11_b_tp_wait = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait2:
    CV_STATE_EVAL(6, 1, 4);
    chartInstance->c11_tp_wait2 = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait3:
    CV_STATE_EVAL(6, 1, 5);
    chartInstance->c11_tp_wait3 = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 1, 0);
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
    break;
  }

  chartInstance->c11_tp_subFacial = 0U;
  chartInstance->c11_is_active_subFacial = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  switch (chartInstance->c11_is_subSmile) {
   case c11_IN_checkP:
    CV_STATE_EVAL(12, 1, 1);
    chartInstance->c11_tp_checkP = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_STATE_EVAL(12, 1, 2);
    chartInstance->c11_tp_gazeCamera = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateCheckSmile:
    CV_STATE_EVAL(12, 1, 3);
    chartInstance->c11_tp_stateCheckSmile = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_STATE_EVAL(12, 1, 4);
    chartInstance->c11_tp_stateInitial = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_STATE_EVAL(12, 1, 5);
    chartInstance->c11_tp_wait = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(12, 1, 0);
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
    break;
  }

  chartInstance->c11_tp_subSmile = 0U;
  chartInstance->c11_is_active_subSmile = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
}

static void c11_initc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_is_active_subFacial = 0U;
  chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
  chartInstance->c11_tp_subFacial = 0U;
  chartInstance->c11_tp_initial = 0U;
  chartInstance->c11_tp_stateFacialExpression = 0U;
  chartInstance->c11_b_tp_wait = 0U;
  chartInstance->c11_tp_wait2 = 0U;
  chartInstance->c11_temporalCounter_i2 = 0U;
  chartInstance->c11_tp_wait3 = 0U;
  chartInstance->c11_temporalCounter_i2 = 0U;
  chartInstance->c11_is_active_subSmile = 0U;
  chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
  chartInstance->c11_tp_subSmile = 0U;
  chartInstance->c11_tp_checkP = 0U;
  chartInstance->c11_tp_gazeCamera = 0U;
  chartInstance->c11_temporalCounter_i1 = 0U;
  chartInstance->c11_tp_stateCheckSmile = 0U;
  chartInstance->c11_tp_stateInitial = 0U;
  chartInstance->c11_tp_wait = 0U;
  chartInstance->c11_temporalCounter_i1 = 0U;
  chartInstance->c11_is_active_c11_Demo_EP_IdleRandMerg = 0U;
}

static void initSimStructsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_subSmile(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[3];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 1.0;
  boolean_T c11_out;
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 1.0;
  boolean_T c11_b_out;
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 1.0;
  boolean_T c11_c_out;
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 1.0;
  boolean_T c11_d_out;
  real_T c11_e_nargin = 0.0;
  real_T c11_e_nargout = 1.0;
  boolean_T c11_e_out;
  real_T *c11_isSmiling;
  real_T *c11_gameState;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c11_sfEvent);
  switch (chartInstance->c11_is_subSmile) {
   case c11_IN_checkP:
    CV_STATE_EVAL(12, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_checkP = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_subSmile = c11_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c11_sfEvent);
    chartInstance->c11_temporalCounter_i1 = 0U;
    chartInstance->c11_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_STATE_EVAL(12, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_w_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    guard4 = false;
    if (CV_EML_COND(3, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs) &&
                    (chartInstance->c11_temporalCounter_i1 >= 1))) {
      if (CV_EML_COND(3, 0, 1, *c11_isSmiling == 1.0)) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c11_out = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c11_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_gazeCamera = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_checkP;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_checkP = 1U;
      c11_enter_atomic_checkP(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_t_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_f_sf_marshallOut,
        c11_e_sf_marshallIn);
      guard3 = false;
      if (CV_EML_COND(7, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs) &&
                      (chartInstance->c11_temporalCounter_i1 >= 1))) {
        if (CV_EML_COND(7, 0, 1, *c11_isSmiling != 1.0)) {
          CV_EML_MCDC(7, 0, 0, true);
          CV_EML_IF(7, 0, 0, true);
          c11_b_out = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(7, 0, 0, false);
        CV_EML_IF(7, 0, 0, false);
        c11_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c11_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_gazeCamera = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateCheckSmile = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                     chartInstance->c11_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateCheckSmile:
    CV_STATE_EVAL(12, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_v_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    if (CV_EML_COND(4, 0, 0, *c11_isSmiling == 1.0)) {
      if (CV_EML_COND(4, 0, 1, *c11_gameState != c11_get_STATE_GO(chartInstance,
            0))) {
        if (CV_EML_COND(4, 0, 2, *c11_gameState != c11_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(4, 0, 0, true);
          CV_EML_IF(4, 0, 0, true);
          c11_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
        guard2 = true;
      }
    } else {
      c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
      guard2 = true;
    }

    if (guard2 == true) {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(4, 0, 0, false);
      CV_EML_IF(4, 0, 0, false);
      c11_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_gazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
      chartInstance->c11_temporalCounter_i1 = 0U;
      chartInstance->c11_tp_gazeCamera = 1U;
      c11_enter_atomic_gazeCamera(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_STATE_EVAL(12, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_s_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
    c11_d_out = CV_EML_IF(1, 0, 0, *c11_gameState == 20.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateInitial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_STATE_EVAL(12, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_u_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_e_out = CV_EML_IF(5, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs)
                          && (chartInstance->c11_temporalCounter_i1 >= 10));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(12, 0, 0);
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c11_sfEvent);
}

static void c11_enter_atomic_gazeCamera(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_b_BMLM[1000];
  real_T c11_P;
  int32_T c11_i27;
  real_T c11_c_BMLM[1000];
  int32_T c11_i28;
  int32_T c11_i29;
  int32_T c11_i30;
  real_T c11_dv7[5000];
  int32_T c11_i31;
  real_T c11_dv8[1000];
  real_T c11_dv9[5000];
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_l_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_smileTablec11_Demo_EP_IdleRandMerg(chartInstance, 2.0, &c11_P, c11_b_BMLM);
  for (c11_i27 = 0; c11_i27 < 1000; c11_i27++) {
    c11_c_BMLM[c11_i27] = c11_b_BMLM[c11_i27];
  }

  c11_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c11_i28 = 0; c11_i28 < 1000; c11_i28++) {
    chartInstance->c11_BMLM[c11_i28] = c11_c_BMLM[c11_i28];
  }

  c11_updateDataWrittenToVector(chartInstance, 4U);
  for (c11_i29 = 0; c11_i29 < 1000; c11_i29++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i29], 14U);
  }

  c11_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 14U);
  for (c11_i30 = 0; c11_i30 < 5000; c11_i30++) {
    c11_dv7[c11_i30] = c11_get_bmlsM(chartInstance, c11_i30);
  }

  for (c11_i31 = 0; c11_i31 < 1000; c11_i31++) {
    c11_dv8[c11_i31] = chartInstance->c11_BMLM[c11_i31];
  }

  c11_insertQueuec11_Demo_EP_IdleRandMerg(chartInstance, c11_dv7, c11_dv8,
    c11_dv9);
  for (c11_i32 = 0; c11_i32 < 5000; c11_i32++) {
    chartInstance->c11_newBmlsM[c11_i32] = c11_dv9[c11_i32];
  }

  c11_updateDataWrittenToVector(chartInstance, 3U);
  for (c11_i33 = 0; c11_i33 < 5000; c11_i33++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i33], 12U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 12U);
  for (c11_i34 = 0; c11_i34 < 5000; c11_i34++) {
    c11_set_bmlsM(chartInstance, c11_i34, chartInstance->c11_newBmlsM[c11_i34]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_enter_atomic_checkP(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_b_BMLM[1000];
  real_T c11_P;
  int32_T c11_i35;
  real_T c11_c_BMLM[1000];
  int32_T c11_i36;
  int32_T c11_i37;
  int32_T c11_i38;
  real_T c11_dv10[5000];
  int32_T c11_i39;
  real_T c11_dv11[1000];
  real_T c11_dv12[5000];
  int32_T c11_i40;
  int32_T c11_i41;
  int32_T c11_i42;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_m_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_smileTablec11_Demo_EP_IdleRandMerg(chartInstance, 1.0, &c11_P, c11_b_BMLM);
  for (c11_i35 = 0; c11_i35 < 1000; c11_i35++) {
    c11_c_BMLM[c11_i35] = c11_b_BMLM[c11_i35];
  }

  c11_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c11_i36 = 0; c11_i36 < 1000; c11_i36++) {
    chartInstance->c11_BMLM[c11_i36] = c11_c_BMLM[c11_i36];
  }

  c11_updateDataWrittenToVector(chartInstance, 4U);
  for (c11_i37 = 0; c11_i37 < 1000; c11_i37++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i37], 14U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 14U);
  for (c11_i38 = 0; c11_i38 < 5000; c11_i38++) {
    c11_dv10[c11_i38] = c11_get_bmlsM(chartInstance, c11_i38);
  }

  for (c11_i39 = 0; c11_i39 < 1000; c11_i39++) {
    c11_dv11[c11_i39] = chartInstance->c11_BMLM[c11_i39];
  }

  c11_insertQueuec11_Demo_EP_IdleRandMerg(chartInstance, c11_dv10, c11_dv11,
    c11_dv12);
  for (c11_i40 = 0; c11_i40 < 5000; c11_i40++) {
    chartInstance->c11_newBmlsM[c11_i40] = c11_dv12[c11_i40];
  }

  c11_updateDataWrittenToVector(chartInstance, 3U);
  for (c11_i41 = 0; c11_i41 < 5000; c11_i41++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i41], 12U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 12U);
  for (c11_i42 = 0; c11_i42 < 5000; c11_i42++) {
    c11_set_bmlsM(chartInstance, c11_i42, chartInstance->c11_newBmlsM[c11_i42]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_enter_atomic_stateFacialExpression
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_b_au_L;
  real_T c11_dv13[6];
  int32_T c11_i43;
  int32_T c11_i44;
  int32_T c11_i45;
  real_T c11_dv14[6];
  real_T c11_dv15[6];
  int32_T c11_i46;
  int32_T c11_i47;
  real_T c11_dv16[6];
  int32_T c11_i48;
  real_T c11_dv17[6];
  real_T c11_dv18[1000];
  int32_T c11_i49;
  int32_T c11_i50;
  int32_T c11_i51;
  real_T c11_dv19[5000];
  int32_T c11_i52;
  real_T c11_dv20[1000];
  real_T c11_dv21[5000];
  int32_T c11_i53;
  int32_T c11_i54;
  int32_T c11_i55;
  real_T *c11_internalE;
  real_T *c11_personality;
  real_T *c11_emotion_amount_custom;
  real_T *c11_inA;
  real_T *c11_inV;
  c11_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c11_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c11_emotion_amount_custom = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c11_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_n_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_setAUc11_Demo_EP_IdleRandMerg(chartInstance, *c11_internalE, c11_dv13,
    &c11_b_au_L);
  for (c11_i43 = 0; c11_i43 < 6; c11_i43++) {
    chartInstance->c11_au[c11_i43] = c11_dv13[c11_i43];
  }

  c11_updateDataWrittenToVector(chartInstance, 6U);
  for (c11_i44 = 0; c11_i44 < 6; c11_i44++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_au[c11_i44], 18U);
  }

  chartInstance->c11_au_L = c11_b_au_L;
  c11_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_L, 22U);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 6U, 18U);
  for (c11_i45 = 0; c11_i45 < 6; c11_i45++) {
    c11_dv14[c11_i45] = chartInstance->c11_au[c11_i45];
  }

  c11_set_eAmountFactorc11_Demo_EP_IdleRandMerg(chartInstance, *c11_internalE,
    *c11_personality, *c11_emotion_amount_custom, c11_dv14, *c11_inA, *c11_inV,
    c11_dv15);
  for (c11_i46 = 0; c11_i46 < 6; c11_i46++) {
    c11_set_emotion_amount_factor(chartInstance, c11_i46, c11_dv15[c11_i46]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 9);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 6U, 18U);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 8U, 22U);
  for (c11_i47 = 0; c11_i47 < 6; c11_i47++) {
    c11_dv16[c11_i47] = chartInstance->c11_au[c11_i47];
  }

  for (c11_i48 = 0; c11_i48 < 6; c11_i48++) {
    c11_dv17[c11_i48] = c11_get_emotion_amount_factor(chartInstance, c11_i48);
  }

  c11_cmdBML_AUmerg(chartInstance, c11_dv16, c11_dv17, chartInstance->c11_au_L,
                    c11_dv18);
  for (c11_i49 = 0; c11_i49 < 1000; c11_i49++) {
    chartInstance->c11_BMLl[c11_i49] = c11_dv18[c11_i49];
  }

  c11_updateDataWrittenToVector(chartInstance, 10U);
  for (c11_i50 = 0; c11_i50 < 1000; c11_i50++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLl[c11_i50], 25U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
  for (c11_i51 = 0; c11_i51 < 5000; c11_i51++) {
    c11_dv19[c11_i51] = c11_get_bmlsL(chartInstance, c11_i51);
  }

  for (c11_i52 = 0; c11_i52 < 1000; c11_i52++) {
    c11_dv20[c11_i52] = chartInstance->c11_BMLl[c11_i52];
  }

  c11_insertQueueLowc11_Demo_EP_IdleRandMerg(chartInstance, c11_dv19, c11_dv20,
    c11_dv21);
  for (c11_i53 = 0; c11_i53 < 5000; c11_i53++) {
    chartInstance->c11_newBmlsL[c11_i53] = c11_dv21[c11_i53];
  }

  c11_updateDataWrittenToVector(chartInstance, 11U);
  for (c11_i54 = 0; c11_i54 < 5000; c11_i54++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsL[c11_i54], 26U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
  for (c11_i55 = 0; c11_i55 < 5000; c11_i55++) {
    c11_set_bmlsL(chartInstance, c11_i55, chartInstance->c11_newBmlsL[c11_i55]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr;
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[1000];
  char_T c11_mystr;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i56;
  int32_T c11_i57;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_b_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_arr, 1U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_mystr, 5U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  c11_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 999.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i56 = 0; c11_i56 < 1000; c11_i56++) {
    c11_tt[c11_i56] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_tt[0] = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i57 = 0; c11_i57 < 1000; c11_i57++) {
    c11_myarr256[c11_i57] = c11_tt[c11_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_b_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[222];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[1000];
  char_T c11_mystr[222];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i58;
  static char_T c11_cv0[222] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
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

  int32_T c11_i59;
  static real_T c11_dv22[222] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c11_i60;
  int32_T c11_i61;
  int32_T c11_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_e_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i58 = 0; c11_i58 < 222; c11_i58++) {
    c11_mystr[c11_i58] = c11_cv0[c11_i58];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i59 = 0; c11_i59 < 222; c11_i59++) {
    c11_arr[c11_i59] = c11_dv22[c11_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 222.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 778.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i60 = 0; c11_i60 < 1000; c11_i60++) {
    c11_tt[c11_i60] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i61 = 0; c11_i61 < 222; c11_i61++) {
    c11_tt[c11_i61] = c11_arr[c11_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i62 = 0; c11_i62 < 1000; c11_i62++) {
    c11_myarr256[c11_i62] = c11_tt[c11_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[109];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[1000];
  char_T c11_mystr[109];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i63;
  static char_T c11_cv1[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g',
    'e', 't', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '5', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e',
    '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i64;
  static real_T c11_dv23[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0,
    34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i65;
  int32_T c11_i66;
  int32_T c11_i67;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_f_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i63 = 0; c11_i63 < 109; c11_i63++) {
    c11_mystr[c11_i63] = c11_cv1[c11_i63];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i64 = 0; c11_i64 < 109; c11_i64++) {
    c11_arr[c11_i64] = c11_dv23[c11_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 891.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i65 = 0; c11_i65 < 1000; c11_i65++) {
    c11_tt[c11_i65] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i66 = 0; c11_i66 < 109; c11_i66++) {
    c11_tt[c11_i66] = c11_arr[c11_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i67 = 0; c11_i67 < 1000; c11_i67++) {
    c11_myarr256[c11_i67] = c11_tt[c11_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_d_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_myarr256[1000])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[230];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[1000];
  char_T c11_mystr[230];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i68;
  static char_T c11_cv2[230] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
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

  int32_T c11_i69;
  static real_T c11_dv24[230] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c11_i70;
  int32_T c11_i71;
  int32_T c11_i72;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_h_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i68 = 0; c11_i68 < 230; c11_i68++) {
    c11_mystr[c11_i68] = c11_cv2[c11_i68];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i69 = 0; c11_i69 < 230; c11_i69++) {
    c11_arr[c11_i69] = c11_dv24[c11_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 230.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 770.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i70 = 0; c11_i70 < 1000; c11_i70++) {
    c11_tt[c11_i70] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i71 = 0; c11_i71 < 230; c11_i71++) {
    c11_tt[c11_i71] = c11_arr[c11_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i72 = 0; c11_i72 < 1000; c11_i72++) {
    c11_myarr256[c11_i72] = c11_tt[c11_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_cmdBML_AUmerg(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_arrAU[6], real_T c11_eAmount[6], real_T c11_L,
  real_T c11_arrBML[1000])
{
  uint32_T c11_debug_family_var_map[22];
  real_T c11_csum;
  const mxArray *c11_str1 = NULL;
  real_T c11_j;
  real_T c11_AU;
  real_T c11_eA;
  real_T c11_c1;
  real_T c11_c2;
  const mxArray *c11_temp = NULL;
  const mxArray *c11_temp2 = NULL;
  const mxArray *c11_currentTime = NULL;
  real_T c11_all_AUs[9];
  real_T c11_c;
  const mxArray *c11_filename = NULL;
  const mxArray *c11_b_fileID = NULL;
  const mxArray *c11_str2 = NULL;
  char_T c11_mystr[656];
  char_T c11_b_mystr[515];
  char_T c11_c_mystr[412];
  char_T c11_d_mystr[306];
  char_T c11_e_mystr[206];
  char_T c11_f_mystr[103];
  int32_T c11_mystr_sizes[2];
  char_T c11_mystr_data[656];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i73;
  static char_T c11_cv3[34] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>' };

  char_T c11_u[34];
  const mxArray *c11_y = NULL;
  real_T c11_b_L;
  int32_T c11_i74;
  int32_T c11_b_j;
  real_T c11_d0;
  real_T c11_varargin_1;
  real_T c11_varargin_2;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_xk;
  real_T c11_c_x;
  real_T c11_maxval;
  int32_T c11_i75;
  static char_T c11_cv4[124] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '1', 'd', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't',
    '=', '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\',
    '\"', '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"',
    '4', '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6',
    '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '1', 'f', '\\',
    '\"', '/', '>' };

  char_T c11_b_u[124];
  const mxArray *c11_b_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_d_y = NULL;
  int32_T c11_i76;
  static char_T c11_cv5[123] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '2', 'd', '\\', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\', '\"',
    '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"', '4',
    '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6', '\\',
    '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '1', 'f', '\\', '\"',
    '/', '>' };

  char_T c11_e_u[123];
  const mxArray *c11_e_y = NULL;
  real_T c11_f_u;
  const mxArray *c11_f_y = NULL;
  real_T c11_g_u;
  const mxArray *c11_g_y = NULL;
  int32_T c11_i77;
  static char_T c11_cv6[20] = { 'D', 'e', 'm', 'o', '_', 'E', 'P', '_', 'I', 'd',
    'l', 'e', 'R', 'a', 'n', 'd', 'M', 'e', 'r', 'g' };

  char_T c11_h_u[20];
  const mxArray *c11_h_y = NULL;
  int32_T c11_i78;
  static char_T c11_cv7[14] = { 'S', 'i', 'm', 'u', 'l', 'a', 't', 'i', 'o', 'n',
    'T', 'i', 'm', 'e' };

  char_T c11_i_u[14];
  const mxArray *c11_i_y = NULL;
  int32_T c11_i79;
  static real_T c11_dv25[9] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 12.0, 26.0, 45.0 };

  int32_T c11_b_c;
  int32_T c11_i80;
  static char_T c11_cv8[2] = { 'A', 'U' };

  char_T c11_j_u[2];
  const mxArray *c11_j_y = NULL;
  real_T c11_k_u;
  const mxArray *c11_k_y = NULL;
  int32_T c11_i81;
  static char_T c11_cv9[4] = { '.', 't', 'x', 't' };

  char_T c11_l_u[4];
  const mxArray *c11_l_y = NULL;
  char_T c11_m_u;
  const mxArray *c11_m_y = NULL;
  int32_T c11_i82;
  static char_T c11_cv10[15] = { '%', '0', '.', '3', 'f', ',', '%', '0', '.',
    '1', 'f', '\\', 'r', '\\', 'n' };

  char_T c11_n_u[15];
  const mxArray *c11_n_y = NULL;
  real_T c11_o_u;
  const mxArray *c11_o_y = NULL;
  int32_T c11_i83;
  static char_T c11_cv11[12] = { '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  char_T c11_p_u[12];
  const mxArray *c11_p_y = NULL;
  int32_T c11_i84;
  int32_T c11_i85;
  int32_T c11_i86;
  int32_T c11_i87;
  int32_T c11_i88;
  int32_T c11_i89;
  int32_T c11_tmp_sizes[2];
  char_T c11_tmp_data[656];
  int32_T c11_g_mystr;
  int32_T c11_h_mystr;
  int32_T c11_loop_ub;
  int32_T c11_i90;
  int32_T c11_b_mystr_sizes[2];
  int32_T c11_i_mystr;
  int32_T c11_j_mystr;
  int32_T c11_b_loop_ub;
  int32_T c11_i91;
  char_T c11_b_mystr_data[656];
  real_T c11_dv26[1000];
  int32_T c11_i92;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 28U, c11_q_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_csum, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_str1, 1U, c11_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_j, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_AU, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_eA, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c1, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c2, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_temp, 7U, c11_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_temp2, 8U, c11_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_currentTime, 9U, c11_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_all_AUs, 10U, c11_w_sf_marshallOut,
    c11_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c, 11U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_filename, 12U, c11_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_fileID, 13U, c11_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_str2, 14U, c11_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_mystr, MAX_uint32_T,
    c11_u_sf_marshallOut, c11_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_b_mystr, MAX_uint32_T,
    c11_t_sf_marshallOut, c11_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_c_mystr, MAX_uint32_T,
    c11_s_sf_marshallOut, c11_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_d_mystr, MAX_uint32_T,
    c11_r_sf_marshallOut, c11_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_e_mystr, MAX_uint32_T,
    c11_q_sf_marshallOut, c11_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_f_mystr, MAX_uint32_T,
    c11_p_sf_marshallOut, c11_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c11_mystr_data, (const int32_T *)
    &c11_mystr_sizes, NULL, 0, -1, (void *)c11_n_sf_marshallOut, (void *)
    c11_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 16U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 17U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_arrAU, 18U, c11_m_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_eAmount, 19U, c11_m_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_L, 20U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_arrBML, 21U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 5);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 6);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 7);
  c11_csum = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 9);
  for (c11_i73 = 0; c11_i73 < 34; c11_i73++) {
    c11_u[c11_i73] = c11_cv3[c11_i73];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  sf_mex_assign(&c11_str1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c11_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 11);
  c11_b_L = c11_L;
  c11_i74 = (int32_T)c11_b_L;
  _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c11_b_L, mxDOUBLE_CLASS, c11_i74);
  c11_j = 1.0;
  c11_b_j = 0;
  while (c11_b_j <= c11_i74 - 1) {
    c11_j = 1.0 + (real_T)c11_b_j;
    CV_SCRIPT_FOR(1, 0, 1);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 12);
    c11_AU = c11_arrAU[_SFD_EML_ARRAY_BOUNDS_CHECK("arrAU", (int32_T)c11_j, 1, 6,
      1, 0) - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 12);
    c11_eA = c11_eAmount[(int32_T)c11_j - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 13);
    c11_c1 = c11_countDigits(chartInstance, c11_AU);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 13);
    c11_c2 = c11_countDigits(chartInstance, c11_eA);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 13);
    c11_csum += c11_c1 + c11_c2;
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 14);
    c11_d0 = c11_abs(chartInstance, c11_AU);
    c11_b_log10(chartInstance, &c11_d0);
    c11_varargin_1 = c11_d0;
    c11_b_ceil(chartInstance, &c11_varargin_1);
    c11_varargin_2 = c11_varargin_1;
    c11_x = c11_varargin_2;
    c11_b_x = c11_x;
    c11_eml_scalar_eg(chartInstance);
    c11_xk = c11_b_x;
    c11_c_x = c11_xk;
    c11_eml_scalar_eg(chartInstance);
    c11_maxval = muDoubleScalarMax(c11_c_x, 1.0);
    if (CV_SCRIPT_IF(1, 0, c11_maxval == 1.0)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 15);
      for (c11_i75 = 0; c11_i75 < 124; c11_i75++) {
        c11_b_u[c11_i75] = c11_cv4[c11_i75];
      }

      c11_b_y = NULL;
      sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1,
        124), false);
      c11_c_u = c11_AU;
      c11_c_y = NULL;
      sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c11_d_u = c11_eA;
      c11_d_y = NULL;
      sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c11_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "sprintf", 1U, 3U, 14, c11_b_y, 14, c11_c_y, 14, c11_d_y), false);
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 17);
      sf_mex_assign(&c11_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "strcat", 1U, 2U, 14, sf_mex_dup(c11_str1), 14, sf_mex_dup(c11_temp)),
                    false);
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 18);
      sf_mex_assign(&c11_str1, sf_mex_dup(c11_temp2), false);
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 20);
      for (c11_i76 = 0; c11_i76 < 123; c11_i76++) {
        c11_e_u[c11_i76] = c11_cv5[c11_i76];
      }

      c11_e_y = NULL;
      sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_e_u, 10, 0U, 1U, 0U, 2, 1,
        123), false);
      c11_f_u = c11_AU;
      c11_f_y = NULL;
      sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_f_u, 0, 0U, 0U, 0U, 0),
                    false);
      c11_g_u = c11_eA;
      c11_g_y = NULL;
      sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_g_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c11_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "sprintf", 1U, 3U, 14, c11_e_y, 14, c11_f_y, 14, c11_g_y), false);
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 22);
      sf_mex_assign(&c11_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "strcat", 1U, 2U, 14, sf_mex_dup(c11_str1), 14, sf_mex_dup(c11_temp)),
                    false);
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 23);
      sf_mex_assign(&c11_str1, sf_mex_dup(c11_temp2), false);
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 27);
    for (c11_i77 = 0; c11_i77 < 20; c11_i77++) {
      c11_h_u[c11_i77] = c11_cv6[c11_i77];
    }

    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_h_u, 10, 0U, 1U, 0U, 2, 1, 20),
                  false);
    for (c11_i78 = 0; c11_i78 < 14; c11_i78++) {
      c11_i_u[c11_i78] = c11_cv7[c11_i78];
    }

    c11_i_y = NULL;
    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_i_u, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    sf_mex_assign(&c11_currentTime, sf_mex_call_debug
                  (sfGlobalDebugInstanceStruct, "get_param", 1U, 2U, 14, c11_h_y,
                   14, c11_i_y), false);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 28);
    for (c11_i79 = 0; c11_i79 < 9; c11_i79++) {
      c11_all_AUs[c11_i79] = c11_dv25[c11_i79];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 29);
    c11_c = 1.0;
    c11_b_c = 0;
    do {
      exitg1 = 0;
      if (c11_b_c < 9) {
        c11_c = 1.0 + (real_T)c11_b_c;
        CV_SCRIPT_FOR(1, 1, 1);
        _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 30);
        if (CV_SCRIPT_IF(1, 1, c11_AU == c11_all_AUs[(int32_T)c11_c - 1])) {
          _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 31);
          for (c11_i80 = 0; c11_i80 < 2; c11_i80++) {
            c11_j_u[c11_i80] = c11_cv8[c11_i80];
          }

          c11_j_y = NULL;
          sf_mex_assign(&c11_j_y, sf_mex_create("y", c11_j_u, 10, 0U, 1U, 0U, 2,
            1, 2), false);
          c11_k_u = c11_AU;
          c11_k_y = NULL;
          sf_mex_assign(&c11_k_y, sf_mex_create("y", &c11_k_u, 0, 0U, 0U, 0U, 0),
                        false);
          for (c11_i81 = 0; c11_i81 < 4; c11_i81++) {
            c11_l_u[c11_i81] = c11_cv9[c11_i81];
          }

          c11_l_y = NULL;
          sf_mex_assign(&c11_l_y, sf_mex_create("y", c11_l_u, 10, 0U, 1U, 0U, 2,
            1, 4), false);
          sf_mex_assign(&c11_filename, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "horzcat", 1U, 3U, 14,
                         c11_j_y, 14, sf_mex_call_debug
                         (sfGlobalDebugInstanceStruct, "num2str", 1U, 1U, 14,
                          c11_k_y), 14, c11_l_y), false);
          _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 32);
          c11_m_u = 'a';
          c11_m_y = NULL;
          sf_mex_assign(&c11_m_y, sf_mex_create("y", &c11_m_u, 10, 0U, 0U, 0U, 0),
                        false);
          sf_mex_assign(&c11_b_fileID, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "fopen", 1U, 2U, 14,
                         sf_mex_dup(c11_filename), 14, c11_m_y), false);
          _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 33);
          for (c11_i82 = 0; c11_i82 < 15; c11_i82++) {
            c11_n_u[c11_i82] = c11_cv10[c11_i82];
          }

          c11_n_y = NULL;
          sf_mex_assign(&c11_n_y, sf_mex_create("y", c11_n_u, 10, 0U, 1U, 0U, 2,
            1, 15), false);
          c11_o_u = c11_eA;
          c11_o_y = NULL;
          sf_mex_assign(&c11_o_y, sf_mex_create("y", &c11_o_u, 0, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "fprintf", 0U, 4U, 14,
                            sf_mex_dup(c11_b_fileID), 14, c11_n_y, 14, c11_o_y,
                            14, sf_mex_dup(c11_currentTime));
          _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 34);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "fclose", 0U, 1U, 14,
                            sf_mex_dup(c11_b_fileID));
          _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 35);
          exitg1 = 1;
        } else {
          c11_b_c++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }
      } else {
        CV_SCRIPT_FOR(1, 1, 0);
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    c11_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(1, 0, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 42);
  for (c11_i83 = 0; c11_i83 < 12; c11_i83++) {
    c11_p_u[c11_i83] = c11_cv11[c11_i83];
  }

  c11_p_y = NULL;
  sf_mex_assign(&c11_p_y, sf_mex_create("y", c11_p_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_assign(&c11_str2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c11_p_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 46);
  if (CV_SCRIPT_IF(1, 2, c11_L == 1.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 47);
    for (c11_i84 = 0; c11_i84 < 103; c11_i84++) {
      c11_f_mystr[c11_i84] = ' ';
    }

    _SFD_SYMBOL_SWITCH(15U, 20U);
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 48);
    if (CV_SCRIPT_IF(1, 3, c11_L == 2.0)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 49);
      c11_blanks(chartInstance);
      for (c11_i85 = 0; c11_i85 < 206; c11_i85++) {
        c11_e_mystr[c11_i85] = ' ';
      }

      _SFD_SYMBOL_SWITCH(15U, 19U);
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 50);
      if (CV_SCRIPT_IF(1, 4, c11_L == 3.0)) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 51);
        c11_b_blanks(chartInstance);
        for (c11_i86 = 0; c11_i86 < 306; c11_i86++) {
          c11_d_mystr[c11_i86] = ' ';
        }

        _SFD_SYMBOL_SWITCH(15U, 18U);
      } else {
        _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 52);
        if (CV_SCRIPT_IF(1, 5, c11_L == 4.0)) {
          _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 53);
          c11_c_blanks(chartInstance);
          for (c11_i87 = 0; c11_i87 < 412; c11_i87++) {
            c11_c_mystr[c11_i87] = ' ';
          }

          _SFD_SYMBOL_SWITCH(15U, 17U);
        } else {
          _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 54);
          if (CV_SCRIPT_IF(1, 6, c11_L == 5.0)) {
            _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 55);
            c11_d_blanks(chartInstance);
            for (c11_i88 = 0; c11_i88 < 515; c11_i88++) {
              c11_b_mystr[c11_i88] = ' ';
            }

            _SFD_SYMBOL_SWITCH(15U, 16U);
          } else {
            _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 56);
            if (CV_SCRIPT_IF(1, 7, c11_L == 6.0)) {
              _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 57);
              for (c11_i89 = 0; c11_i89 < 656; c11_i89++) {
                c11_mystr[c11_i89] = ' ';
              }

              _SFD_SYMBOL_SWITCH(15U, 15U);
            }
          }
        }
      }
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 63);
  c11_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                       (sfGlobalDebugInstanceStruct, "strcat", 1U, 2U, 14,
                        sf_mex_dup(c11_str1), 14, sf_mex_dup(c11_str2)),
                       "strcat", c11_tmp_data, c11_tmp_sizes);
  c11_mystr_sizes[0] = 1;
  c11_mystr_sizes[1] = c11_tmp_sizes[1];
  c11_g_mystr = c11_mystr_sizes[0];
  c11_h_mystr = c11_mystr_sizes[1];
  c11_loop_ub = c11_tmp_sizes[0] * c11_tmp_sizes[1] - 1;
  for (c11_i90 = 0; c11_i90 <= c11_loop_ub; c11_i90++) {
    c11_mystr_data[c11_i90] = c11_tmp_data[c11_i90];
  }

  _SFD_SYMBOL_SWITCH(15U, 21U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 64);
  c11_b_mystr_sizes[0] = 1;
  c11_b_mystr_sizes[1] = c11_mystr_sizes[1];
  c11_i_mystr = c11_b_mystr_sizes[0];
  c11_j_mystr = c11_b_mystr_sizes[1];
  c11_b_loop_ub = c11_mystr_sizes[0] * c11_mystr_sizes[1] - 1;
  for (c11_i91 = 0; c11_i91 <= c11_b_loop_ub; c11_i91++) {
    c11_b_mystr_data[c11_i91] = c11_mystr_data[c11_i91];
  }

  c11_e_encStr2Arr(chartInstance, c11_b_mystr_data, c11_b_mystr_sizes, c11_dv26);
  for (c11_i92 = 0; c11_i92 < 1000; c11_i92++) {
    c11_arrBML[c11_i92] = c11_dv26[c11_i92];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, -64);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c11_str1);
  sf_mex_destroy(&c11_temp);
  sf_mex_destroy(&c11_temp2);
  sf_mex_destroy(&c11_currentTime);
  sf_mex_destroy(&c11_filename);
  sf_mex_destroy(&c11_b_fileID);
  sf_mex_destroy(&c11_str2);
}

static real_T c11_countDigits(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_x)
{
  real_T c11_num;
  uint32_T c11_debug_family_var_map[4];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_b_x;
  real_T c11_c_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c11_o_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_x, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_num, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 2);
  c11_num = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 3);
  if (CV_SCRIPT_IF(2, 0, c11_x < 0.0)) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 4);
    c11_num = 1.0;
    _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 5);
    c11_b_x = c11_x;
    c11_c_x = c11_b_x;
    c11_x = muDoubleScalarAbs(c11_c_x);
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 7);
  guard1 = false;
  if (CV_SCRIPT_COND(2, 0, c11_x > 0.0)) {
    if (CV_SCRIPT_COND(2, 1, c11_x < 9.0)) {
      CV_SCRIPT_MCDC(2, 0, true);
      CV_SCRIPT_IF(2, 1, true);
      _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 8);
      c11_num++;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(2, 0, false);
    CV_SCRIPT_IF(2, 1, false);
    _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 9);
    guard2 = false;
    if (CV_SCRIPT_COND(2, 2, c11_x > 10.0)) {
      if (CV_SCRIPT_COND(2, 3, c11_x < 99.0)) {
        CV_SCRIPT_MCDC(2, 1, true);
        CV_SCRIPT_IF(2, 2, true);
        _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 10);
        c11_num += 2.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_SCRIPT_MCDC(2, 1, false);
      CV_SCRIPT_IF(2, 2, false);
      _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 11);
      guard3 = false;
      if (CV_SCRIPT_COND(2, 4, c11_x > 100.0)) {
        if (CV_SCRIPT_COND(2, 5, c11_x < 999.0)) {
          CV_SCRIPT_MCDC(2, 2, true);
          CV_SCRIPT_IF(2, 3, true);
          _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, 12);
          c11_num += 3.0;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_SCRIPT_MCDC(2, 2, false);
        CV_SCRIPT_IF(2, 3, false);
      }
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c11_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  return c11_num;
}

static real_T c11_log10(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T c11_x)
{
  real_T c11_b_x;
  c11_b_x = c11_x;
  c11_b_log10(chartInstance, &c11_b_x);
  return c11_b_x;
}

static real_T c11_ceil(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T c11_x)
{
  real_T c11_b_x;
  c11_b_x = c11_x;
  c11_b_ceil(chartInstance, &c11_b_x);
  return c11_b_x;
}

static void c11_eml_scalar_eg(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_b_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_c_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_d_blanks(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_e_encStr2Arr(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, char_T c11_mystr_data[], int32_T c11_mystr_sizes[2], real_T
  c11_myarr256[1000])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  int32_T c11_arr_sizes;
  real_T c11_arr_data[656];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[1000];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_loop_ub;
  int32_T c11_i93;
  int32_T c11_i94;
  boolean_T c11_b0;
  boolean_T c11_b1;
  boolean_T c11_b2;
  int32_T c11_i95;
  int32_T c11_tmp_sizes;
  int32_T c11_b_loop_ub;
  int32_T c11_i96;
  int32_T c11_tmp_data[656];
  int32_T c11_iv0[1];
  int32_T c11_c_loop_ub;
  int32_T c11_i97;
  int32_T c11_i98;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_p_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c11_arr_data, (const int32_T *)
    &c11_arr_sizes, NULL, 0, 1, (void *)c11_o_sf_marshallOut, (void *)
    c11_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_ss, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c11_mystr_data, (const int32_T *)
    c11_mystr_sizes, NULL, 1, 7, (void *)c11_n_sf_marshallOut, (void *)
    c11_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_arr_sizes = c11_mystr_sizes[1];
  c11_loop_ub = c11_mystr_sizes[1] - 1;
  for (c11_i93 = 0; c11_i93 <= c11_loop_ub; c11_i93++) {
    c11_arr_data[c11_i93] = (real_T)c11_mystr_data[c11_mystr_sizes[0] * c11_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = (real_T)c11_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 1000.0 - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i94 = 0; c11_i94 < 1000; c11_i94++) {
    c11_tt[c11_i94] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_b0 = (1.0 > c11_ss);
  c11_b1 = c11_b0;
  c11_b2 = c11_b1;
  if (c11_b2) {
    c11_i95 = 0;
  } else {
    c11_i95 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c11_ss, 1, 1000, 0, 0);
  }

  c11_tmp_sizes = c11_i95;
  c11_b_loop_ub = c11_i95 - 1;
  for (c11_i96 = 0; c11_i96 <= c11_b_loop_ub; c11_i96++) {
    c11_tmp_data[c11_i96] = c11_i96;
  }

  c11_iv0[0] = c11_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c11_iv0, 1, *(int32_T (*)[1])&c11_arr_sizes, 1);
  c11_c_loop_ub = c11_arr_sizes - 1;
  for (c11_i97 = 0; c11_i97 <= c11_c_loop_ub; c11_i97++) {
    c11_tt[c11_tmp_data[c11_i97]] = c11_arr_data[c11_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i98 = 0; c11_i98 < 1000; c11_i98++) {
    c11_myarr256[c11_i98] = c11_tt[c11_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\11-12-2015-Matlab\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\11-12-2015-Matlab\\cmdBML_AUmerg.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\11-12-2015-Matlab\\countDigits.m"));
}

static void c11_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_strcat, const char_T *c11_identifier,
  char_T c11_y_data[], int32_T c11_y_sizes[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_strcat), &c11_thisId,
    c11_y_data, c11_y_sizes);
  sf_mex_destroy(&c11_strcat);
}

static void c11_b_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2])
{
  int32_T c11_i99;
  uint32_T c11_uv0[2];
  int32_T c11_i100;
  static boolean_T c11_bv0[2] = { false, true };

  boolean_T c11_bv1[2];
  int32_T c11_tmp_sizes[2];
  char_T c11_tmp_data[656];
  int32_T c11_y;
  int32_T c11_b_y;
  int32_T c11_loop_ub;
  int32_T c11_i101;
  (void)chartInstance;
  for (c11_i99 = 0; c11_i99 < 2; c11_i99++) {
    c11_uv0[c11_i99] = 1U + 655U * (uint32_T)c11_i99;
  }

  for (c11_i100 = 0; c11_i100 < 2; c11_i100++) {
    c11_bv1[c11_i100] = c11_bv0[c11_i100];
  }

  sf_mex_import_vs(c11_parentId, sf_mex_dup(c11_u), c11_tmp_data, 0, 10, 0U, 1,
                   0U, 2, c11_bv1, c11_uv0, c11_tmp_sizes);
  c11_y_sizes[0] = 1;
  c11_y_sizes[1] = c11_tmp_sizes[1];
  c11_y = c11_y_sizes[0];
  c11_b_y = c11_y_sizes[1];
  c11_loop_ub = c11_tmp_sizes[0] * c11_tmp_sizes[1] - 1;
  for (c11_i101 = 0; c11_i101 <= c11_loop_ub; c11_i101++) {
    c11_y_data[c11_i101] = c11_tmp_data[c11_i101];
  }

  sf_mex_destroy(&c11_u);
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i102;
  int32_T c11_i103;
  int32_T c11_i104;
  real_T c11_b_inData[5000];
  int32_T c11_i105;
  int32_T c11_i106;
  int32_T c11_i107;
  real_T c11_u[5000];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i102 = 0;
  for (c11_i103 = 0; c11_i103 < 5; c11_i103++) {
    for (c11_i104 = 0; c11_i104 < 1000; c11_i104++) {
      c11_b_inData[c11_i104 + c11_i102] = (*(real_T (*)[5000])c11_inData)
        [c11_i104 + c11_i102];
    }

    c11_i102 += 1000;
  }

  c11_i105 = 0;
  for (c11_i106 = 0; c11_i106 < 5; c11_i106++) {
    for (c11_i107 = 0; c11_i107 < 1000; c11_i107++) {
      c11_u[c11_i107 + c11_i105] = c11_b_inData[c11_i107 + c11_i105];
    }

    c11_i105 += 1000;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_newBmls, const char_T *c11_identifier,
  real_T c11_y[5000])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_newBmls), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_newBmls);
}

static void c11_d_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[5000])
{
  real_T c11_dv27[5000];
  int32_T c11_i108;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv27, 1, 0, 0U, 1, 0U, 2,
                1000, 5);
  for (c11_i108 = 0; c11_i108 < 5000; c11_i108++) {
    c11_y[c11_i108] = c11_dv27[c11_i108];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_newBmls;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[5000];
  int32_T c11_i109;
  int32_T c11_i110;
  int32_T c11_i111;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_newBmls = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_newBmls), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_newBmls);
  c11_i109 = 0;
  for (c11_i110 = 0; c11_i110 < 5; c11_i110++) {
    for (c11_i111 = 0; c11_i111 < 1000; c11_i111++) {
      (*(real_T (*)[5000])c11_outData)[c11_i111 + c11_i109] = c11_y[c11_i111 +
        c11_i109];
    }

    c11_i109 += 1000;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i112;
  real_T c11_b_inData[1000];
  int32_T c11_i113;
  real_T c11_u[1000];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i112 = 0; c11_i112 < 1000; c11_i112++) {
    c11_b_inData[c11_i112] = (*(real_T (*)[1000])c11_inData)[c11_i112];
  }

  for (c11_i113 = 0; c11_i113 < 1000; c11_i113++) {
    c11_u[c11_i113] = c11_b_inData[c11_i113];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_e_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_myBML, const char_T *c11_identifier, real_T
  c11_y[1000])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myBML), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myBML);
}

static void c11_f_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1000])
{
  real_T c11_dv28[1000];
  int32_T c11_i114;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv28, 1, 0, 0U, 1, 0U, 2,
                1000, 1);
  for (c11_i114 = 0; c11_i114 < 1000; c11_i114++) {
    c11_y[c11_i114] = c11_dv28[c11_i114];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_myBML;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[1000];
  int32_T c11_i115;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_myBML = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myBML), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myBML);
  for (c11_i115 = 0; c11_i115 < 1000; c11_i115++) {
    (*(real_T (*)[1000])c11_outData)[c11_i115] = c11_y[c11_i115];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_g_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_nargout, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  return c11_y;
}

static real_T c11_h_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d1;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d1, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d1;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i116;
  real_T c11_b_inData[1000];
  int32_T c11_i117;
  real_T c11_u[1000];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i116 = 0; c11_i116 < 1000; c11_i116++) {
    c11_b_inData[c11_i116] = (*(real_T (*)[1000])c11_inData)[c11_i116];
  }

  for (c11_i117 = 0; c11_i117 < 1000; c11_i117++) {
    c11_u[c11_i117] = c11_b_inData[c11_i117];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 1000), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_i_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_myarr256, const char_T *c11_identifier,
  real_T c11_y[1000])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
}

static void c11_j_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1000])
{
  real_T c11_dv29[1000];
  int32_T c11_i118;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv29, 1, 0, 0U, 1, 0U, 1,
                1000);
  for (c11_i118 = 0; c11_i118 < 1000; c11_i118++) {
    c11_y[c11_i118] = c11_dv29[c11_i118];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_myarr256;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[1000];
  int32_T c11_i119;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_myarr256 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
  for (c11_i119 = 0; c11_i119 < 1000; c11_i119++) {
    (*(real_T (*)[1000])c11_outData)[c11_i119] = c11_y[c11_i119];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  char_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(char_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_k_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  boolean_T c11_y;
  boolean_T c11_b3;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b3, 1, 11, 0U, 0, 0U, 0);
  c11_y = c11_b3;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_aVarTruthTableCondition_2;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_aVarTruthTableCondition_2 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_aVarTruthTableCondition_2), &c11_thisId);
  sf_mex_destroy(&c11_aVarTruthTableCondition_2);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i120;
  char_T c11_b_inData[222];
  int32_T c11_i121;
  char_T c11_u[222];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i120 = 0; c11_i120 < 222; c11_i120++) {
    c11_b_inData[c11_i120] = (*(char_T (*)[222])c11_inData)[c11_i120];
  }

  for (c11_i121 = 0; c11_i121 < 222; c11_i121++) {
    c11_u[c11_i121] = c11_b_inData[c11_i121];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 222),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i122;
  real_T c11_b_inData[222];
  int32_T c11_i123;
  real_T c11_u[222];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i122 = 0; c11_i122 < 222; c11_i122++) {
    c11_b_inData[c11_i122] = (*(real_T (*)[222])c11_inData)[c11_i122];
  }

  for (c11_i123 = 0; c11_i123 < 222; c11_i123++) {
    c11_u[c11_i123] = c11_b_inData[c11_i123];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 222), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i124;
  char_T c11_b_inData[109];
  int32_T c11_i125;
  char_T c11_u[109];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i124 = 0; c11_i124 < 109; c11_i124++) {
    c11_b_inData[c11_i124] = (*(char_T (*)[109])c11_inData)[c11_i124];
  }

  for (c11_i125 = 0; c11_i125 < 109; c11_i125++) {
    c11_u[c11_i125] = c11_b_inData[c11_i125];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i126;
  real_T c11_b_inData[109];
  int32_T c11_i127;
  real_T c11_u[109];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i126 = 0; c11_i126 < 109; c11_i126++) {
    c11_b_inData[c11_i126] = (*(real_T (*)[109])c11_inData)[c11_i126];
  }

  for (c11_i127 = 0; c11_i127 < 109; c11_i127++) {
    c11_u[c11_i127] = c11_b_inData[c11_i127];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i128;
  char_T c11_b_inData[230];
  int32_T c11_i129;
  char_T c11_u[230];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i128 = 0; c11_i128 < 230; c11_i128++) {
    c11_b_inData[c11_i128] = (*(char_T (*)[230])c11_inData)[c11_i128];
  }

  for (c11_i129 = 0; c11_i129 < 230; c11_i129++) {
    c11_u[c11_i129] = c11_b_inData[c11_i129];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 230),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i130;
  real_T c11_b_inData[230];
  int32_T c11_i131;
  real_T c11_u[230];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i130 = 0; c11_i130 < 230; c11_i130++) {
    c11_b_inData[c11_i130] = (*(real_T (*)[230])c11_inData)[c11_i130];
  }

  for (c11_i131 = 0; c11_i131 < 230; c11_i131++) {
    c11_u[c11_i131] = c11_b_inData[c11_i131];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 230), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i132;
  real_T c11_b_inData[6];
  int32_T c11_i133;
  real_T c11_u[6];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i132 = 0; c11_i132 < 6; c11_i132++) {
    c11_b_inData[c11_i132] = (*(real_T (*)[6])c11_inData)[c11_i132];
  }

  for (c11_i133 = 0; c11_i133 < 6; c11_i133++) {
    c11_u[c11_i133] = c11_b_inData[c11_i133];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_l_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_AU, const char_T *c11_identifier, real_T
  c11_y[6])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_AU), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_AU);
}

static void c11_m_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6])
{
  real_T c11_dv30[6];
  int32_T c11_i134;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv30, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c11_i134 = 0; c11_i134 < 6; c11_i134++) {
    c11_y[c11_i134] = c11_dv30[c11_i134];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_AU;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[6];
  int32_T c11_i135;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_AU = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_AU), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_AU);
  for (c11_i135 = 0; c11_i135 < 6; c11_i135++) {
    (*(real_T (*)[6])c11_outData)[c11_i135] = c11_y[c11_i135];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, char_T
  c11_inData_data[], int32_T c11_inData_sizes[2])
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_b_inData_sizes[2];
  int32_T c11_loop_ub;
  int32_T c11_i136;
  char_T c11_b_inData_data[656];
  int32_T c11_u_sizes[2];
  int32_T c11_b_loop_ub;
  int32_T c11_i137;
  char_T c11_u_data[656];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_b_inData_sizes[0] = 1;
  c11_b_inData_sizes[1] = c11_inData_sizes[1];
  c11_loop_ub = c11_inData_sizes[1] - 1;
  for (c11_i136 = 0; c11_i136 <= c11_loop_ub; c11_i136++) {
    c11_b_inData_data[c11_b_inData_sizes[0] * c11_i136] =
      c11_inData_data[c11_inData_sizes[0] * c11_i136];
  }

  c11_u_sizes[0] = 1;
  c11_u_sizes[1] = c11_b_inData_sizes[1];
  c11_b_loop_ub = c11_b_inData_sizes[1] - 1;
  for (c11_i137 = 0; c11_i137 <= c11_b_loop_ub; c11_i137++) {
    c11_u_data[c11_u_sizes[0] * c11_i137] =
      c11_b_inData_data[c11_b_inData_sizes[0] * c11_i137];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u_data, 10, 0U, 1U, 0U, 2,
    c11_u_sizes[0], c11_u_sizes[1]), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_n_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2])
{
  int32_T c11_i138;
  uint32_T c11_uv1[2];
  int32_T c11_i139;
  static boolean_T c11_bv2[2] = { false, true };

  boolean_T c11_bv3[2];
  int32_T c11_tmp_sizes[2];
  char_T c11_tmp_data[656];
  int32_T c11_y;
  int32_T c11_b_y;
  int32_T c11_loop_ub;
  int32_T c11_i140;
  (void)chartInstance;
  for (c11_i138 = 0; c11_i138 < 2; c11_i138++) {
    c11_uv1[c11_i138] = 1U + 655U * (uint32_T)c11_i138;
  }

  for (c11_i139 = 0; c11_i139 < 2; c11_i139++) {
    c11_bv3[c11_i139] = c11_bv2[c11_i139];
  }

  sf_mex_import_vs(c11_parentId, sf_mex_dup(c11_u), c11_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c11_bv3, c11_uv1, c11_tmp_sizes);
  c11_y_sizes[0] = 1;
  c11_y_sizes[1] = c11_tmp_sizes[1];
  c11_y = c11_y_sizes[0];
  c11_b_y = c11_y_sizes[1];
  c11_loop_ub = c11_tmp_sizes[0] * c11_tmp_sizes[1] - 1;
  for (c11_i140 = 0; c11_i140 <= c11_loop_ub; c11_i140++) {
    c11_y_data[c11_i140] = c11_tmp_data[c11_i140];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, char_T c11_outData_data[],
  int32_T c11_outData_sizes[2])
{
  const mxArray *c11_mystr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y_sizes[2];
  char_T c11_y_data[656];
  int32_T c11_loop_ub;
  int32_T c11_i141;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mystr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_mystr), &c11_thisId,
    c11_y_data, c11_y_sizes);
  sf_mex_destroy(&c11_mystr);
  c11_outData_sizes[0] = 1;
  c11_outData_sizes[1] = c11_y_sizes[1];
  c11_loop_ub = c11_y_sizes[1] - 1;
  for (c11_i141 = 0; c11_i141 <= c11_loop_ub; c11_i141++) {
    c11_outData_data[c11_outData_sizes[0] * c11_i141] = c11_y_data[c11_y_sizes[0]
      * c11_i141];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, real_T
  c11_inData_data[], int32_T *c11_inData_sizes)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_b_inData_sizes;
  int32_T c11_loop_ub;
  int32_T c11_i142;
  real_T c11_b_inData_data[656];
  int32_T c11_u_sizes;
  int32_T c11_b_loop_ub;
  int32_T c11_i143;
  real_T c11_u_data[656];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_b_inData_sizes = *c11_inData_sizes;
  c11_loop_ub = *c11_inData_sizes - 1;
  for (c11_i142 = 0; c11_i142 <= c11_loop_ub; c11_i142++) {
    c11_b_inData_data[c11_i142] = c11_inData_data[c11_i142];
  }

  c11_u_sizes = c11_b_inData_sizes;
  c11_b_loop_ub = c11_b_inData_sizes - 1;
  for (c11_i143 = 0; c11_i143 <= c11_b_loop_ub; c11_i143++) {
    c11_u_data[c11_i143] = c11_b_inData_data[c11_i143];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u_data, 0, 0U, 1U, 0U, 1,
    c11_u_sizes), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_o_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y_data[], int32_T *c11_y_sizes)
{
  static uint32_T c11_uv2[1] = { 656U };

  uint32_T c11_uv3[1];
  static boolean_T c11_bv4[1] = { true };

  boolean_T c11_bv5[1];
  int32_T c11_tmp_sizes;
  real_T c11_tmp_data[656];
  int32_T c11_loop_ub;
  int32_T c11_i144;
  (void)chartInstance;
  c11_uv3[0] = c11_uv2[0];
  c11_bv5[0] = c11_bv4[0];
  sf_mex_import_vs(c11_parentId, sf_mex_dup(c11_u), c11_tmp_data, 1, 0, 0U, 1,
                   0U, 1, c11_bv5, c11_uv3, &c11_tmp_sizes);
  *c11_y_sizes = c11_tmp_sizes;
  c11_loop_ub = c11_tmp_sizes - 1;
  for (c11_i144 = 0; c11_i144 <= c11_loop_ub; c11_i144++) {
    c11_y_data[c11_i144] = c11_tmp_data[c11_i144];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, real_T c11_outData_data[],
  int32_T *c11_outData_sizes)
{
  const mxArray *c11_arr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y_sizes;
  real_T c11_y_data[656];
  int32_T c11_loop_ub;
  int32_T c11_i145;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_arr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_arr), &c11_thisId,
    c11_y_data, &c11_y_sizes);
  sf_mex_destroy(&c11_arr);
  *c11_outData_sizes = c11_y_sizes;
  c11_loop_ub = c11_y_sizes - 1;
  for (c11_i145 = 0; c11_i145 <= c11_loop_ub; c11_i145++) {
    c11_outData_data[c11_i145] = c11_y_data[c11_i145];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i146;
  char_T c11_b_inData[103];
  int32_T c11_i147;
  char_T c11_u[103];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i146 = 0; c11_i146 < 103; c11_i146++) {
    c11_b_inData[c11_i146] = (*(char_T (*)[103])c11_inData)[c11_i146];
  }

  for (c11_i147 = 0; c11_i147 < 103; c11_i147++) {
    c11_u[c11_i147] = c11_b_inData[c11_i147];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_p_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[103])
{
  char_T c11_cv12[103];
  int32_T c11_i148;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_cv12, 1, 10, 0U, 1, 0U, 2,
                1, 103);
  for (c11_i148 = 0; c11_i148 < 103; c11_i148++) {
    c11_y[c11_i148] = c11_cv12[c11_i148];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_mystr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  char_T c11_y[103];
  int32_T c11_i149;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mystr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_mystr), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_mystr);
  for (c11_i149 = 0; c11_i149 < 103; c11_i149++) {
    (*(char_T (*)[103])c11_outData)[c11_i149] = c11_y[c11_i149];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i150;
  char_T c11_b_inData[206];
  int32_T c11_i151;
  char_T c11_u[206];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i150 = 0; c11_i150 < 206; c11_i150++) {
    c11_b_inData[c11_i150] = (*(char_T (*)[206])c11_inData)[c11_i150];
  }

  for (c11_i151 = 0; c11_i151 < 206; c11_i151++) {
    c11_u[c11_i151] = c11_b_inData[c11_i151];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 206),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_q_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[206])
{
  char_T c11_cv13[206];
  int32_T c11_i152;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_cv13, 1, 10, 0U, 1, 0U, 2,
                1, 206);
  for (c11_i152 = 0; c11_i152 < 206; c11_i152++) {
    c11_y[c11_i152] = c11_cv13[c11_i152];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_mystr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  char_T c11_y[206];
  int32_T c11_i153;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mystr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_mystr), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_mystr);
  for (c11_i153 = 0; c11_i153 < 206; c11_i153++) {
    (*(char_T (*)[206])c11_outData)[c11_i153] = c11_y[c11_i153];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_r_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i154;
  char_T c11_b_inData[306];
  int32_T c11_i155;
  char_T c11_u[306];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i154 = 0; c11_i154 < 306; c11_i154++) {
    c11_b_inData[c11_i154] = (*(char_T (*)[306])c11_inData)[c11_i154];
  }

  for (c11_i155 = 0; c11_i155 < 306; c11_i155++) {
    c11_u[c11_i155] = c11_b_inData[c11_i155];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 306),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_r_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[306])
{
  char_T c11_cv14[306];
  int32_T c11_i156;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_cv14, 1, 10, 0U, 1, 0U, 2,
                1, 306);
  for (c11_i156 = 0; c11_i156 < 306; c11_i156++) {
    c11_y[c11_i156] = c11_cv14[c11_i156];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_mystr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  char_T c11_y[306];
  int32_T c11_i157;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mystr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_mystr), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_mystr);
  for (c11_i157 = 0; c11_i157 < 306; c11_i157++) {
    (*(char_T (*)[306])c11_outData)[c11_i157] = c11_y[c11_i157];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_s_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i158;
  char_T c11_b_inData[412];
  int32_T c11_i159;
  char_T c11_u[412];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i158 = 0; c11_i158 < 412; c11_i158++) {
    c11_b_inData[c11_i158] = (*(char_T (*)[412])c11_inData)[c11_i158];
  }

  for (c11_i159 = 0; c11_i159 < 412; c11_i159++) {
    c11_u[c11_i159] = c11_b_inData[c11_i159];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 412),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_s_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[412])
{
  char_T c11_cv15[412];
  int32_T c11_i160;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_cv15, 1, 10, 0U, 1, 0U, 2,
                1, 412);
  for (c11_i160 = 0; c11_i160 < 412; c11_i160++) {
    c11_y[c11_i160] = c11_cv15[c11_i160];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_mystr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  char_T c11_y[412];
  int32_T c11_i161;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mystr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_mystr), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_mystr);
  for (c11_i161 = 0; c11_i161 < 412; c11_i161++) {
    (*(char_T (*)[412])c11_outData)[c11_i161] = c11_y[c11_i161];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_t_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i162;
  char_T c11_b_inData[515];
  int32_T c11_i163;
  char_T c11_u[515];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i162 = 0; c11_i162 < 515; c11_i162++) {
    c11_b_inData[c11_i162] = (*(char_T (*)[515])c11_inData)[c11_i162];
  }

  for (c11_i163 = 0; c11_i163 < 515; c11_i163++) {
    c11_u[c11_i163] = c11_b_inData[c11_i163];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 515),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_t_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[515])
{
  char_T c11_cv16[515];
  int32_T c11_i164;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_cv16, 1, 10, 0U, 1, 0U, 2,
                1, 515);
  for (c11_i164 = 0; c11_i164 < 515; c11_i164++) {
    c11_y[c11_i164] = c11_cv16[c11_i164];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_mystr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  char_T c11_y[515];
  int32_T c11_i165;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mystr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_mystr), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_mystr);
  for (c11_i165 = 0; c11_i165 < 515; c11_i165++) {
    (*(char_T (*)[515])c11_outData)[c11_i165] = c11_y[c11_i165];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_u_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i166;
  char_T c11_b_inData[656];
  int32_T c11_i167;
  char_T c11_u[656];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i166 = 0; c11_i166 < 656; c11_i166++) {
    c11_b_inData[c11_i166] = (*(char_T (*)[656])c11_inData)[c11_i166];
  }

  for (c11_i167 = 0; c11_i167 < 656; c11_i167++) {
    c11_u[c11_i167] = c11_b_inData[c11_i167];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 656),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_u_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[656])
{
  char_T c11_cv17[656];
  int32_T c11_i168;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_cv17, 1, 10, 0U, 1, 0U, 2,
                1, 656);
  for (c11_i168 = 0; c11_i168 < 656; c11_i168++) {
    c11_y[c11_i168] = c11_cv17[c11_i168];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_mystr;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  char_T c11_y[656];
  int32_T c11_i169;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mystr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_mystr), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_mystr);
  for (c11_i169 = 0; c11_i169 < 656; c11_i169++) {
    (*(char_T (*)[656])c11_outData)[c11_i169] = c11_y[c11_i169];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_v_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  const mxArray *c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = sf_mex_dup(*(const mxArray **)c11_inData);
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_w_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i170;
  real_T c11_b_inData[9];
  int32_T c11_i171;
  real_T c11_u[9];
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i170 = 0; c11_i170 < 9; c11_i170++) {
    c11_b_inData[c11_i170] = (*(real_T (*)[9])c11_inData)[c11_i170];
  }

  for (c11_i171 = 0; c11_i171 < 9; c11_i171++) {
    c11_u[c11_i171] = c11_b_inData[c11_i171];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1, 9), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_v_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[9])
{
  real_T c11_dv31[9];
  int32_T c11_i172;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv31, 1, 0, 0U, 1, 0U, 2, 1,
                9);
  for (c11_i172 = 0; c11_i172 < 9; c11_i172++) {
    c11_y[c11_i172] = c11_dv31[c11_i172];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_all_AUs;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[9];
  int32_T c11_i173;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_all_AUs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_all_AUs), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_all_AUs);
  for (c11_i173 = 0; c11_i173 < 9; c11_i173++) {
    (*(real_T (*)[9])c11_outData)[c11_i173] = c11_y[c11_i173];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 47, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  const mxArray *c11_rhs1 = NULL;
  const mxArray *c11_lhs1 = NULL;
  const mxArray *c11_rhs2 = NULL;
  const mxArray *c11_lhs2 = NULL;
  const mxArray *c11_rhs3 = NULL;
  const mxArray *c11_lhs3 = NULL;
  const mxArray *c11_rhs4 = NULL;
  const mxArray *c11_lhs4 = NULL;
  const mxArray *c11_rhs5 = NULL;
  const mxArray *c11_lhs5 = NULL;
  const mxArray *c11_rhs6 = NULL;
  const mxArray *c11_lhs6 = NULL;
  const mxArray *c11_rhs7 = NULL;
  const mxArray *c11_lhs7 = NULL;
  const mxArray *c11_rhs8 = NULL;
  const mxArray *c11_lhs8 = NULL;
  const mxArray *c11_rhs9 = NULL;
  const mxArray *c11_lhs9 = NULL;
  const mxArray *c11_rhs10 = NULL;
  const mxArray *c11_lhs10 = NULL;
  const mxArray *c11_rhs11 = NULL;
  const mxArray *c11_lhs11 = NULL;
  const mxArray *c11_rhs12 = NULL;
  const mxArray *c11_lhs12 = NULL;
  const mxArray *c11_rhs13 = NULL;
  const mxArray *c11_lhs13 = NULL;
  const mxArray *c11_rhs14 = NULL;
  const mxArray *c11_lhs14 = NULL;
  const mxArray *c11_rhs15 = NULL;
  const mxArray *c11_lhs15 = NULL;
  const mxArray *c11_rhs16 = NULL;
  const mxArray *c11_lhs16 = NULL;
  const mxArray *c11_rhs17 = NULL;
  const mxArray *c11_lhs17 = NULL;
  const mxArray *c11_rhs18 = NULL;
  const mxArray *c11_lhs18 = NULL;
  const mxArray *c11_rhs19 = NULL;
  const mxArray *c11_lhs19 = NULL;
  const mxArray *c11_rhs20 = NULL;
  const mxArray *c11_lhs20 = NULL;
  const mxArray *c11_rhs21 = NULL;
  const mxArray *c11_lhs21 = NULL;
  const mxArray *c11_rhs22 = NULL;
  const mxArray *c11_lhs22 = NULL;
  const mxArray *c11_rhs23 = NULL;
  const mxArray *c11_lhs23 = NULL;
  const mxArray *c11_rhs24 = NULL;
  const mxArray *c11_lhs24 = NULL;
  const mxArray *c11_rhs25 = NULL;
  const mxArray *c11_lhs25 = NULL;
  const mxArray *c11_rhs26 = NULL;
  const mxArray *c11_lhs26 = NULL;
  const mxArray *c11_rhs27 = NULL;
  const mxArray *c11_lhs27 = NULL;
  const mxArray *c11_rhs28 = NULL;
  const mxArray *c11_lhs28 = NULL;
  const mxArray *c11_rhs29 = NULL;
  const mxArray *c11_lhs29 = NULL;
  const mxArray *c11_rhs30 = NULL;
  const mxArray *c11_lhs30 = NULL;
  const mxArray *c11_rhs31 = NULL;
  const mxArray *c11_lhs31 = NULL;
  const mxArray *c11_rhs32 = NULL;
  const mxArray *c11_lhs32 = NULL;
  const mxArray *c11_rhs33 = NULL;
  const mxArray *c11_lhs33 = NULL;
  const mxArray *c11_rhs34 = NULL;
  const mxArray *c11_lhs34 = NULL;
  const mxArray *c11_rhs35 = NULL;
  const mxArray *c11_lhs35 = NULL;
  const mxArray *c11_rhs36 = NULL;
  const mxArray *c11_lhs36 = NULL;
  const mxArray *c11_rhs37 = NULL;
  const mxArray *c11_lhs37 = NULL;
  const mxArray *c11_rhs38 = NULL;
  const mxArray *c11_lhs38 = NULL;
  const mxArray *c11_rhs39 = NULL;
  const mxArray *c11_lhs39 = NULL;
  const mxArray *c11_rhs40 = NULL;
  const mxArray *c11_lhs40 = NULL;
  const mxArray *c11_rhs41 = NULL;
  const mxArray *c11_lhs41 = NULL;
  const mxArray *c11_rhs42 = NULL;
  const mxArray *c11_lhs42 = NULL;
  const mxArray *c11_rhs43 = NULL;
  const mxArray *c11_lhs43 = NULL;
  const mxArray *c11_rhs44 = NULL;
  const mxArray *c11_lhs44 = NULL;
  const mxArray *c11_rhs45 = NULL;
  const mxArray *c11_lhs45 = NULL;
  const mxArray *c11_rhs46 = NULL;
  const mxArray *c11_lhs46 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c11_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c11_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c11_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c11_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c11_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("disp"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 5);
  sf_mex_assign(&c11_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383909694U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c11_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c11_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("mrdivide"), "name", "name",
                  8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c11_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c11_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("rdivide"), "name", "name",
                  10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c11_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c11_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c11_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_div"), "name", "name",
                  13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c11_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c11_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("abs"), "name", "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c11_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c11_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c11_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("cmdBML_AUmerg"), "name",
                  "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1450138623U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c11_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("countDigits"), "name",
                  "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/countDigits.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1408487908U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c11_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/countDigits.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("abs"), "name", "name", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c11_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("abs"), "name", "name", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c11_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("log10"), "name", "name", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1343862782U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c11_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_error"), "name", "name",
                  23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c11_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851128U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c11_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("realmax"), "name", "name",
                  25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1307683642U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c11_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c11_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c11_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("mrdivide"), "name", "name",
                  28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c11_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("ceil"), "name", "name", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c11_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c11_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_ceil"), "name",
                  "name", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_ceil.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851120U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c11_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("max"), "name", "name", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1311287716U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c11_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378328384U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c11_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c11_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c11_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c11_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c11_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c11_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c11_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c11_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fopen"), "name", "name", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fopen.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c11_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fprintf"), "name", "name",
                  42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c11_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fclose"), "name", "name", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("mxArray"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c11_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("blanks"), "name", "name", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c11_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c11_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/cmdBML_AUmerg.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/11-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c11_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs46), "lhs", "lhs",
                  46);
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
  sf_mex_destroy(&c11_rhs1);
  sf_mex_destroy(&c11_lhs1);
  sf_mex_destroy(&c11_rhs2);
  sf_mex_destroy(&c11_lhs2);
  sf_mex_destroy(&c11_rhs3);
  sf_mex_destroy(&c11_lhs3);
  sf_mex_destroy(&c11_rhs4);
  sf_mex_destroy(&c11_lhs4);
  sf_mex_destroy(&c11_rhs5);
  sf_mex_destroy(&c11_lhs5);
  sf_mex_destroy(&c11_rhs6);
  sf_mex_destroy(&c11_lhs6);
  sf_mex_destroy(&c11_rhs7);
  sf_mex_destroy(&c11_lhs7);
  sf_mex_destroy(&c11_rhs8);
  sf_mex_destroy(&c11_lhs8);
  sf_mex_destroy(&c11_rhs9);
  sf_mex_destroy(&c11_lhs9);
  sf_mex_destroy(&c11_rhs10);
  sf_mex_destroy(&c11_lhs10);
  sf_mex_destroy(&c11_rhs11);
  sf_mex_destroy(&c11_lhs11);
  sf_mex_destroy(&c11_rhs12);
  sf_mex_destroy(&c11_lhs12);
  sf_mex_destroy(&c11_rhs13);
  sf_mex_destroy(&c11_lhs13);
  sf_mex_destroy(&c11_rhs14);
  sf_mex_destroy(&c11_lhs14);
  sf_mex_destroy(&c11_rhs15);
  sf_mex_destroy(&c11_lhs15);
  sf_mex_destroy(&c11_rhs16);
  sf_mex_destroy(&c11_lhs16);
  sf_mex_destroy(&c11_rhs17);
  sf_mex_destroy(&c11_lhs17);
  sf_mex_destroy(&c11_rhs18);
  sf_mex_destroy(&c11_lhs18);
  sf_mex_destroy(&c11_rhs19);
  sf_mex_destroy(&c11_lhs19);
  sf_mex_destroy(&c11_rhs20);
  sf_mex_destroy(&c11_lhs20);
  sf_mex_destroy(&c11_rhs21);
  sf_mex_destroy(&c11_lhs21);
  sf_mex_destroy(&c11_rhs22);
  sf_mex_destroy(&c11_lhs22);
  sf_mex_destroy(&c11_rhs23);
  sf_mex_destroy(&c11_lhs23);
  sf_mex_destroy(&c11_rhs24);
  sf_mex_destroy(&c11_lhs24);
  sf_mex_destroy(&c11_rhs25);
  sf_mex_destroy(&c11_lhs25);
  sf_mex_destroy(&c11_rhs26);
  sf_mex_destroy(&c11_lhs26);
  sf_mex_destroy(&c11_rhs27);
  sf_mex_destroy(&c11_lhs27);
  sf_mex_destroy(&c11_rhs28);
  sf_mex_destroy(&c11_lhs28);
  sf_mex_destroy(&c11_rhs29);
  sf_mex_destroy(&c11_lhs29);
  sf_mex_destroy(&c11_rhs30);
  sf_mex_destroy(&c11_lhs30);
  sf_mex_destroy(&c11_rhs31);
  sf_mex_destroy(&c11_lhs31);
  sf_mex_destroy(&c11_rhs32);
  sf_mex_destroy(&c11_lhs32);
  sf_mex_destroy(&c11_rhs33);
  sf_mex_destroy(&c11_lhs33);
  sf_mex_destroy(&c11_rhs34);
  sf_mex_destroy(&c11_lhs34);
  sf_mex_destroy(&c11_rhs35);
  sf_mex_destroy(&c11_lhs35);
  sf_mex_destroy(&c11_rhs36);
  sf_mex_destroy(&c11_lhs36);
  sf_mex_destroy(&c11_rhs37);
  sf_mex_destroy(&c11_lhs37);
  sf_mex_destroy(&c11_rhs38);
  sf_mex_destroy(&c11_lhs38);
  sf_mex_destroy(&c11_rhs39);
  sf_mex_destroy(&c11_lhs39);
  sf_mex_destroy(&c11_rhs40);
  sf_mex_destroy(&c11_lhs40);
  sf_mex_destroy(&c11_rhs41);
  sf_mex_destroy(&c11_lhs41);
  sf_mex_destroy(&c11_rhs42);
  sf_mex_destroy(&c11_lhs42);
  sf_mex_destroy(&c11_rhs43);
  sf_mex_destroy(&c11_lhs43);
  sf_mex_destroy(&c11_rhs44);
  sf_mex_destroy(&c11_lhs44);
  sf_mex_destroy(&c11_rhs45);
  sf_mex_destroy(&c11_lhs45);
  sf_mex_destroy(&c11_rhs46);
  sf_mex_destroy(&c11_lhs46);
}

static const mxArray *c11_emlrt_marshallOut(const char * c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c11_u)), false);
  return c11_y;
}

static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  return c11_y;
}

static void c11_activate_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = c11_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_deactivate_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_increment_counters_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  if (chartInstance->c11_temporalCounter_i1 < 15U) {
    chartInstance->c11_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c11_temporalCounter_i1 + 1);
  }

  if (chartInstance->c11_temporalCounter_i2 < 15U) {
    chartInstance->c11_temporalCounter_i2 = (uint8_T)(int16_T)
      (chartInstance->c11_temporalCounter_i2 + 1);
  }
}

static void c11_reset_counters_secsc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c11_Demo_EP_IdleRandMerg_secs(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_activate_secsc11_Demo_EP_IdleRandMerg(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c11_Demo_EP_IdleRandMerg_secs
  (SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_increment_counters_secsc11_Demo_EP_IdleRandMerg(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c11_Demo_EP_IdleRandMerg_secs
  (SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_reset_counters_secsc11_Demo_EP_IdleRandMerg(chartInstance);
}

void sf_exported_auto_deactivate_c11_Demo_EP_IdleRandMerg_secs(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_deactivate_secsc11_Demo_EP_IdleRandMerg(chartInstance);
}

boolean_T sf_exported_auto_isStablec11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  return chartInstance->c11_isStable;
}

void sf_exported_auto_duringc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_c11_Demo_EP_IdleRandMerg(chartInstance);
}

void sf_exported_auto_enterc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_enter_atomic_c11_Demo_EP_IdleRandMerg(chartInstance);
  c11_enter_internal_c11_Demo_EP_IdleRandMerg(chartInstance);
}

void sf_exported_auto_exitc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_exit_internal_c11_Demo_EP_IdleRandMerg(chartInstance);
}

void sf_exported_auto_gatewayc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc11_Demo_EP_IdleRandMerg(SimStruct
  *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc11_Demo_EP_IdleRandMerg(SimStruct
  *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc11_Demo_EP_IdleRandMerg(SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_initc11_Demo_EP_IdleRandMerg(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec11_Demo_EP_IdleRandMerg(SimStruct
  *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out, sf_internal_get_sim_state_c11_Demo_EP_IdleRandMerg
                (c11_S), false);
  return c11_out;
}

void sf_exported_auto_setSimstatec11_Demo_EP_IdleRandMerg(SimStruct *c11_S,
  const mxArray *c11_in)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c11_Demo_EP_IdleRandMerg(c11_S, sf_mex_dup(c11_in));
  sf_mex_destroy(&c11_in);
}

void sf_exported_auto_check_state_inconsistency_c11_Demo_EP_IdleRandMerg
  (SimStruct *c11_S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_EP_IdleRandMergMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_insertQueuec11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmls[5000],
   real_T c11_myBML[1000], real_T c11_newBmls[5000])
{
  uint32_T c11_debug_family_var_map[8];
  real_T c11_full;
  real_T c11_t[1000];
  real_T c11_i;
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i174;
  static real_T c11_dv32[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  int32_T c11_i175;
  int32_T c11_i176;
  int32_T c11_i177;
  int32_T c11_i178;
  int32_T c11_i179;
  int32_T c11_b_i;
  int32_T c11_c_i;
  int32_T c11_i180;
  real_T c11_b_bmls[1000];
  int32_T c11_i181;
  real_T c11_dv33[1000];
  int32_T c11_d_i;
  int32_T c11_i182;
  int32_T c11_i183;
  real_T c11_c_bmls[1000];
  int32_T c11_i184;
  int32_T c11_i185;
  real_T c11_d_bmls[1000];
  int32_T c11_i186;
  int32_T c11_i187;
  real_T c11_e_bmls[1000];
  int32_T c11_i188;
  int32_T c11_i189;
  int32_T c11_i190;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_full, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_t, 1U, c11_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_bmls, 5U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myBML, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_newBmls, 7U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 2);
  c11_full = 1.0;
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 3);
  for (c11_i174 = 0; c11_i174 < 1000; c11_i174++) {
    c11_t[c11_i174] = c11_dv32[c11_i174];
  }

  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 4);
  for (c11_i175 = 0; c11_i175 < 1000; c11_i175++) {
    c11_newBmls[c11_i175] = c11_t[c11_i175];
  }

  for (c11_i176 = 0; c11_i176 < 1000; c11_i176++) {
    c11_newBmls[c11_i176 + 1000] = c11_t[c11_i176];
  }

  for (c11_i177 = 0; c11_i177 < 1000; c11_i177++) {
    c11_newBmls[c11_i177 + 2000] = c11_t[c11_i177];
  }

  for (c11_i178 = 0; c11_i178 < 1000; c11_i178++) {
    c11_newBmls[c11_i178 + 3000] = c11_t[c11_i178];
  }

  for (c11_i179 = 0; c11_i179 < 1000; c11_i179++) {
    c11_newBmls[c11_i179 + 4000] = c11_t[c11_i179];
  }

  c11_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 5);
  c11_i = 1.0;
  c11_b_i = 0;
  do {
    exitg1 = 0;
    if (c11_b_i < 5) {
      c11_i = 1.0 + (real_T)c11_b_i;
      CV_EML_FOR(1, 1, 0, 1);
      _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 6);
      c11_c_i = (int32_T)c11_i - 1;
      for (c11_i180 = 0; c11_i180 < 1000; c11_i180++) {
        c11_b_bmls[c11_i180] = c11_bmls[c11_i180 + 1000 * c11_c_i];
      }

      for (c11_i181 = 0; c11_i181 < 1000; c11_i181++) {
        c11_dv33[c11_i181] = c11_dv32[c11_i181];
      }

      if (CV_EML_IF(1, 1, 0, c11_isequal(chartInstance, c11_b_bmls, c11_dv33)))
      {
        _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 8);
        c11_d_i = (int32_T)c11_i - 1;
        for (c11_i182 = 0; c11_i182 < 1000; c11_i182++) {
          c11_bmls[c11_i182 + 1000 * c11_d_i] = c11_myBML[c11_i182];
        }

        _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 9);
        c11_full = 0.0;
        _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 10);
        exitg1 = 1;
      } else {
        c11_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(1, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 13);
  if (CV_EML_IF(1, 1, 1, c11_full != 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 15);
    for (c11_i183 = 0; c11_i183 < 1000; c11_i183++) {
      c11_c_bmls[c11_i183] = c11_bmls[c11_i183 + 1000];
    }

    for (c11_i184 = 0; c11_i184 < 1000; c11_i184++) {
      c11_bmls[c11_i184] = c11_c_bmls[c11_i184];
    }

    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 16);
    for (c11_i185 = 0; c11_i185 < 1000; c11_i185++) {
      c11_d_bmls[c11_i185] = c11_bmls[c11_i185 + 2000];
    }

    for (c11_i186 = 0; c11_i186 < 1000; c11_i186++) {
      c11_bmls[c11_i186 + 1000] = c11_d_bmls[c11_i186];
    }

    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 17);
    for (c11_i187 = 0; c11_i187 < 1000; c11_i187++) {
      c11_e_bmls[c11_i187] = c11_bmls[c11_i187 + 3000];
    }

    for (c11_i188 = 0; c11_i188 < 1000; c11_i188++) {
      c11_bmls[c11_i188 + 2000] = c11_e_bmls[c11_i188];
    }

    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 18);
    for (c11_i189 = 0; c11_i189 < 1000; c11_i189++) {
      c11_bmls[c11_i189 + 4000] = c11_myBML[c11_i189];
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 20);
  for (c11_i190 = 0; c11_i190 < 5000; c11_i190++) {
    c11_newBmls[c11_i190] = c11_bmls[c11_i190];
  }

  c11_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_insertQueueLowc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmls[5000],
   real_T c11_myBML[1000], real_T c11_newBmls[5000])
{
  uint32_T c11_debug_family_var_map[8];
  real_T c11_full;
  real_T c11_t[1000];
  real_T c11_i;
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i191;
  static real_T c11_dv34[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  int32_T c11_i192;
  int32_T c11_i193;
  int32_T c11_i194;
  int32_T c11_i195;
  int32_T c11_i196;
  int32_T c11_b_i;
  int32_T c11_c_i;
  int32_T c11_i197;
  real_T c11_b_bmls[1000];
  int32_T c11_i198;
  real_T c11_dv35[1000];
  int32_T c11_d_i;
  int32_T c11_i199;
  int32_T c11_i200;
  real_T c11_c_bmls[1000];
  int32_T c11_i201;
  int32_T c11_i202;
  real_T c11_d_bmls[1000];
  int32_T c11_i203;
  int32_T c11_i204;
  real_T c11_e_bmls[1000];
  int32_T c11_i205;
  int32_T c11_i206;
  int32_T c11_i207;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c11_c_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_full, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_t, 1U, c11_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_bmls, 5U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myBML, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_newBmls, 7U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 2);
  c11_full = 1.0;
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 3);
  for (c11_i191 = 0; c11_i191 < 1000; c11_i191++) {
    c11_t[c11_i191] = c11_dv34[c11_i191];
  }

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 4);
  for (c11_i192 = 0; c11_i192 < 1000; c11_i192++) {
    c11_newBmls[c11_i192] = c11_t[c11_i192];
  }

  for (c11_i193 = 0; c11_i193 < 1000; c11_i193++) {
    c11_newBmls[c11_i193 + 1000] = c11_t[c11_i193];
  }

  for (c11_i194 = 0; c11_i194 < 1000; c11_i194++) {
    c11_newBmls[c11_i194 + 2000] = c11_t[c11_i194];
  }

  for (c11_i195 = 0; c11_i195 < 1000; c11_i195++) {
    c11_newBmls[c11_i195 + 3000] = c11_t[c11_i195];
  }

  for (c11_i196 = 0; c11_i196 < 1000; c11_i196++) {
    c11_newBmls[c11_i196 + 4000] = c11_t[c11_i196];
  }

  c11_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 5);
  c11_i = 1.0;
  c11_b_i = 0;
  do {
    exitg1 = 0;
    if (c11_b_i < 5) {
      c11_i = 1.0 + (real_T)c11_b_i;
      CV_EML_FOR(2, 1, 0, 1);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 6);
      c11_c_i = (int32_T)c11_i - 1;
      for (c11_i197 = 0; c11_i197 < 1000; c11_i197++) {
        c11_b_bmls[c11_i197] = c11_bmls[c11_i197 + 1000 * c11_c_i];
      }

      for (c11_i198 = 0; c11_i198 < 1000; c11_i198++) {
        c11_dv35[c11_i198] = c11_dv34[c11_i198];
      }

      if (CV_EML_IF(2, 1, 0, c11_isequal(chartInstance, c11_b_bmls, c11_dv35)))
      {
        _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 8);
        c11_d_i = (int32_T)c11_i - 1;
        for (c11_i199 = 0; c11_i199 < 1000; c11_i199++) {
          c11_bmls[c11_i199 + 1000 * c11_d_i] = c11_myBML[c11_i199];
        }

        _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 9);
        c11_full = 0.0;
        _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 10);
        exitg1 = 1;
      } else {
        c11_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(2, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 13);
  if (CV_EML_IF(2, 1, 1, c11_full != 0.0)) {
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 15);
    for (c11_i200 = 0; c11_i200 < 1000; c11_i200++) {
      c11_c_bmls[c11_i200] = c11_bmls[c11_i200 + 1000];
    }

    for (c11_i201 = 0; c11_i201 < 1000; c11_i201++) {
      c11_bmls[c11_i201] = c11_c_bmls[c11_i201];
    }

    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 16);
    for (c11_i202 = 0; c11_i202 < 1000; c11_i202++) {
      c11_d_bmls[c11_i202] = c11_bmls[c11_i202 + 2000];
    }

    for (c11_i203 = 0; c11_i203 < 1000; c11_i203++) {
      c11_bmls[c11_i203 + 1000] = c11_d_bmls[c11_i203];
    }

    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 17);
    for (c11_i204 = 0; c11_i204 < 1000; c11_i204++) {
      c11_e_bmls[c11_i204] = c11_bmls[c11_i204 + 3000];
    }

    for (c11_i205 = 0; c11_i205 < 1000; c11_i205++) {
      c11_bmls[c11_i205 + 2000] = c11_e_bmls[c11_i205];
    }

    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 18);
    for (c11_i206 = 0; c11_i206 < 1000; c11_i206++) {
      c11_bmls[c11_i206 + 4000] = c11_myBML[c11_i206];
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 20);
  for (c11_i207 = 0; c11_i207 < 5000; c11_i207++) {
    c11_newBmls[c11_i207] = c11_bmls[c11_i207];
  }

  c11_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_smileTablec11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmlID,
   real_T *c11_p, real_T c11_poseBML[1000])
{
  uint32_T c11_debug_family_var_map[7];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  real_T c11_dv36[1000];
  int32_T c11_i208;
  int32_T c11_i209;
  int32_T c11_i210;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_d_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_1, 0U,
    c11_f_sf_marshallOut, c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_2, 1U,
    c11_f_sf_marshallOut, c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_bmlID, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_poseBML, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 3);
  c11_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 4);
  c11_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 9);
  c11_aVarTruthTableCondition_1 = (c11_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 13);
  c11_aVarTruthTableCondition_2 = (c11_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 15);
  if (CV_EML_IF(5, 1, 0, c11_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 16);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 27);
    c11_b_encStr2Arr(chartInstance, c11_dv36);
    for (c11_i208 = 0; c11_i208 < 1000; c11_i208++) {
      c11_poseBML[c11_i208] = c11_dv36[c11_i208];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 27);
    *c11_p = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, -27);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 17);
    if (CV_EML_IF(5, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 18);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 33);
      c11_c_encStr2Arr(chartInstance, c11_dv36);
      for (c11_i209 = 0; c11_i209 < 1000; c11_i209++) {
        c11_poseBML[c11_i209] = c11_dv36[c11_i209];
      }

      c11_updateDataWrittenToVector(chartInstance, 15U);
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 33);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 14U);
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, -33);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 20);
      CV_EML_FCN(5, 1);
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 27);
      c11_b_encStr2Arr(chartInstance, c11_dv36);
      for (c11_i210 = 0; c11_i210 < 1000; c11_i210++) {
        c11_poseBML[c11_i210] = c11_dv36[c11_i210];
      }

      c11_updateDataWrittenToVector(chartInstance, 15U);
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, 27);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 14U);
      _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_facialExprc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_bmlID,
   real_T *c11_p, real_T c11_poseBML[1000])
{
  uint32_T c11_debug_family_var_map[7];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  real_T c11_dv37[1000];
  int32_T c11_i211;
  int32_T c11_i212;
  int32_T c11_i213;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_g_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_1, 0U,
    c11_f_sf_marshallOut, c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_2, 1U,
    c11_f_sf_marshallOut, c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_bmlID, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_poseBML, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 3);
  c11_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 9);
  c11_aVarTruthTableCondition_1 = (c11_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  c11_aVarTruthTableCondition_2 = (c11_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 15);
  if (CV_EML_IF(0, 1, 0, c11_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 16);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
    c11_d_encStr2Arr(chartInstance, c11_dv37);
    for (c11_i211 = 0; c11_i211 < 1000; c11_i211++) {
      c11_poseBML[c11_i211] = c11_dv37[c11_i211];
    }

    c11_updateDataWrittenToVector(chartInstance, 17U);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
    *c11_p = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -27);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 17);
    if (CV_EML_IF(0, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
      c11_c_encStr2Arr(chartInstance, c11_dv37);
      for (c11_i212 = 0; c11_i212 < 1000; c11_i212++) {
        c11_poseBML[c11_i212] = c11_dv37[c11_i212];
      }

      c11_updateDataWrittenToVector(chartInstance, 17U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -33);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 20);
      CV_EML_FCN(0, 1);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
      c11_d_encStr2Arr(chartInstance, c11_dv37);
      for (c11_i213 = 0; c11_i213 < 1000; c11_i213++) {
        c11_poseBML[c11_i213] = c11_dv37[c11_i213];
      }

      c11_updateDataWrittenToVector(chartInstance, 17U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_setAUc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_E, real_T
   c11_AU[6], real_T *c11_L)
{
  uint32_T c11_debug_family_var_map[5];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  int32_T c11_i214;
  int32_T c11_i215;
  static real_T c11_dv38[6] = { 1.0, 2.0, 45.0, 0.0, 0.0, 0.0 };

  int32_T c11_i216;
  static real_T c11_dv39[6] = { 1.0, 4.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i217;
  static real_T c11_dv40[6] = { 1.0, 2.0, 4.0, 5.0, 6.0, 0.0 };

  int32_T c11_i218;
  static real_T c11_dv41[6] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0 };

  int32_T c11_i219;
  static real_T c11_dv42[6] = { 12.0, 45.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i220;
  static real_T c11_dv43[6] = { 6.0, 12.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i221;
  static real_T c11_dv44[6] = { 6.0, 12.0, 1.0, 2.0, 0.0, 0.0 };

  int32_T c11_i222;
  static real_T c11_dv45[6] = { 12.0, 26.0, 5.0, 1.0, 2.0, 6.0 };

  int32_T c11_i223;
  static real_T c11_dv46[6] = { 2.0, 4.0, 5.0, 7.0, 45.0, 0.0 };

  const mxArray *c11_y = NULL;
  char_T c11_u[31];
  static char_T c11_cv18[31] = { 'e', 'r', 'r', 'o', 'r', ',', ' ', 's', 'e',
    't', 'A', 'U', ',', 'e', 'm', 'o', 't', 'i', 'o', 'n', ' ', 'n', 'o', 't',
    ' ', 'l', 'i', 's', 't', 'e', 'd' };

  int32_T c11_i224;
  int32_T c11_i225;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c11_i_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_E, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_AU, 3U, c11_m_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_L, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 12);
  for (c11_i214 = 0; c11_i214 < 6; c11_i214++) {
    c11_AU[c11_i214] = 0.0;
  }

  c11_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 12);
  *c11_L = 0.0;
  c11_updateDataWrittenToVector(chartInstance, 19U);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 16);
  switch ((int16_T)_SFD_INTEGER_CHECK("E", c11_E)) {
   case 1:
    CV_EML_SWITCH(3, 1, 0, 1);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 18);
    for (c11_i215 = 0; c11_i215 < 6; c11_i215++) {
      c11_AU[c11_i215] = c11_dv38[c11_i215];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 18);
    *c11_L = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 2:
    CV_EML_SWITCH(3, 1, 0, 2);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 21);
    for (c11_i216 = 0; c11_i216 < 6; c11_i216++) {
      c11_AU[c11_i216] = c11_dv39[c11_i216];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 21);
    *c11_L = 2.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 3:
    CV_EML_SWITCH(3, 1, 0, 3);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 24);
    for (c11_i217 = 0; c11_i217 < 6; c11_i217++) {
      c11_AU[c11_i217] = c11_dv40[c11_i217];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 24);
    *c11_L = 5.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 4:
    CV_EML_SWITCH(3, 1, 0, 4);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 27);
    for (c11_i218 = 0; c11_i218 < 6; c11_i218++) {
      c11_AU[c11_i218] = c11_dv41[c11_i218];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 27);
    *c11_L = 6.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 5:
    CV_EML_SWITCH(3, 1, 0, 5);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 30);
    for (c11_i219 = 0; c11_i219 < 6; c11_i219++) {
      c11_AU[c11_i219] = c11_dv42[c11_i219];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 30);
    *c11_L = 2.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 6:
    CV_EML_SWITCH(3, 1, 0, 6);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 33);
    for (c11_i220 = 0; c11_i220 < 6; c11_i220++) {
      c11_AU[c11_i220] = c11_dv43[c11_i220];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 33);
    *c11_L = 2.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 7:
    CV_EML_SWITCH(3, 1, 0, 7);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 36);
    for (c11_i221 = 0; c11_i221 < 6; c11_i221++) {
      c11_AU[c11_i221] = c11_dv44[c11_i221];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 36);
    *c11_L = 4.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 8:
    CV_EML_SWITCH(3, 1, 0, 8);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 39);
    for (c11_i222 = 0; c11_i222 < 6; c11_i222++) {
      c11_AU[c11_i222] = c11_dv45[c11_i222];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 39);
    *c11_L = 6.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   case 9:
    CV_EML_SWITCH(3, 1, 0, 9);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 42);
    for (c11_i223 = 0; c11_i223 < 6; c11_i223++) {
      c11_AU[c11_i223] = c11_dv46[c11_i223];
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 42);
    *c11_L = 5.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    break;

   default:
    CV_EML_SWITCH(3, 1, 0, 0);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 49);
    for (c11_i224 = 0; c11_i224 < 6; c11_i224++) {
      c11_AU[c11_i224] = 0.0;
    }

    c11_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 49);
    *c11_L = 0.0;
    c11_updateDataWrittenToVector(chartInstance, 19U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 50);
    for (c11_i225 = 0; c11_i225 < 31; c11_i225++) {
      c11_u[c11_i225] = c11_cv18[c11_i225];
    }

    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c11_y);
    break;
  }

  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, -50);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_set_eAmountFactorc11_Demo_EP_IdleRandMerg
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, real_T c11_E, real_T
   c11_p, real_T c11_cFactor, real_T c11_AU[6], real_T c11_arousal, real_T
   c11_valence, real_T c11_eAmountFactor[6])
{
  uint32_T c11_debug_family_var_map[13];
  real_T c11_pFactor;
  real_T c11_a_factor;
  real_T c11_v_factor;
  real_T c11_c;
  real_T c11_nargin = 6.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i226;
  int32_T c11_i227;
  static real_T c11_dv47[6] = { 1.0, 1.0, 0.25, 0.0, 0.0, 0.0 };

  int32_T c11_i228;
  static real_T c11_dv48[6] = { 0.7, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i229;
  static real_T c11_dv49[6] = { 1.0, 1.0, 1.0, 0.7, 0.7, 0.0 };

  int32_T c11_i230;
  static real_T c11_dv50[6] = { 1.0, 1.0, 1.0, 0.8, 0.8, 0.2 };

  int32_T c11_i231;
  static real_T c11_dv51[6] = { 0.7, 0.25, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i232;
  static real_T c11_dv52[6] = { 0.4, 0.4, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i233;
  static real_T c11_dv53[6] = { 0.9, 1.2, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i234;
  static real_T c11_dv54[6] = { 0.7, 0.5, 0.8, 0.8, 0.8, 0.5 };

  int32_T c11_i235;
  int32_T c11_i236;
  static char_T c11_cv19[43] = { 'e', 'r', 'r', 'o', 'r', ',', ' ', 's', 'e',
    't', '_', 'e', 'A', 'm', 'o', 'u', 'n', 't', 'F', 'a', 'c', 't', 'o', 'r',
    ',', 'e', 'm', 'o', 't', 'i', 'o', 'n', ' ', 'n', 'o', 't', ' ', 'l', 'i',
    's', 't', 'e', 'd' };

  char_T c11_u[43];
  const mxArray *c11_y = NULL;
  int32_T c11_i237;
  real_T c11_a[6];
  real_T c11_b;
  int32_T c11_i238;
  int32_T c11_i239;
  int32_T c11_i240;
  int32_T c11_i241;
  int32_T c11_i242;
  int32_T c11_i243;
  int32_T c11_i244;
  int32_T c11_i245;
  static real_T c11_dv55[6] = { 0.9, 1.2, 0.4, 0.4, 0.0, 0.0 };

  int32_T c11_i246;
  static real_T c11_dv56[6] = { 0.7, 0.5, 0.8, 0.8, 0.8, 0.0 };

  int32_T c11_i247;
  int32_T c11_i248;
  char_T c11_b_u[43];
  const mxArray *c11_b_y = NULL;
  int32_T c11_i249;
  real_T c11_b_b;
  int32_T c11_i250;
  int32_T c11_i251;
  int32_T c11_i252;
  int32_T c11_i253;
  int32_T c11_i254;
  int32_T c11_i255;
  int32_T c11_i256;
  int32_T c11_i257;
  int32_T c11_i258;
  int32_T c11_i259;
  int32_T c11_i260;
  char_T c11_c_u[43];
  const mxArray *c11_c_y = NULL;
  int32_T c11_i261;
  int32_T c11_i262;
  real_T c11_c_b;
  int32_T c11_i263;
  int32_T c11_i264;
  int32_T c11_i265;
  int32_T c11_i266;
  int32_T c11_i267;
  int32_T c11_i268;
  int32_T c11_i269;
  int32_T c11_i270;
  int32_T c11_i271;
  int32_T c11_i272;
  int32_T c11_i273;
  char_T c11_d_u[43];
  const mxArray *c11_d_y = NULL;
  int32_T c11_i274;
  int32_T c11_i275;
  real_T c11_d_b;
  int32_T c11_i276;
  real_T c11_A;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_e_y;
  real_T c11_b_A;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_f_y;
  int32_T c11_b_c;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c11_j_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_pFactor, 0U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_a_factor, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_v_factor, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_E, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_p, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_cFactor, 8U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_AU, 9U, c11_m_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_arousal, 10U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_valence, 11U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_eAmountFactor, 12U,
    c11_m_sf_marshallOut, c11_f_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 2);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 3);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 4);
  for (c11_i226 = 0; c11_i226 < 6; c11_i226++) {
    c11_eAmountFactor[c11_i226] = 0.0;
  }

  c11_updateDataWrittenToVector(chartInstance, 20U);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 4);
  c11_pFactor = 0.8;
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 22);
  if (CV_EML_IF(4, 1, 0, c11_p == 1.0)) {
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 24);
    if (CV_EML_IF(4, 1, 1, c11_E == 1.0)) {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 25);
      for (c11_i227 = 0; c11_i227 < 6; c11_i227++) {
        c11_eAmountFactor[c11_i227] = c11_dv47[c11_i227];
      }

      c11_updateDataWrittenToVector(chartInstance, 20U);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 26);
      if (CV_EML_IF(4, 1, 2, c11_E == 2.0)) {
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 27);
        for (c11_i228 = 0; c11_i228 < 6; c11_i228++) {
          c11_eAmountFactor[c11_i228] = c11_dv48[c11_i228];
        }

        c11_updateDataWrittenToVector(chartInstance, 20U);
      } else {
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 28);
        if (CV_EML_IF(4, 1, 3, c11_E == 3.0)) {
          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 29);
          for (c11_i229 = 0; c11_i229 < 6; c11_i229++) {
            c11_eAmountFactor[c11_i229] = c11_dv49[c11_i229];
          }

          c11_updateDataWrittenToVector(chartInstance, 20U);
        } else {
          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 30);
          if (CV_EML_IF(4, 1, 4, c11_E == 4.0)) {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 31);
            for (c11_i230 = 0; c11_i230 < 6; c11_i230++) {
              c11_eAmountFactor[c11_i230] = c11_dv50[c11_i230];
            }

            c11_updateDataWrittenToVector(chartInstance, 20U);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 32);
            if (CV_EML_IF(4, 1, 5, c11_E == 5.0)) {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 33);
              for (c11_i231 = 0; c11_i231 < 6; c11_i231++) {
                c11_eAmountFactor[c11_i231] = c11_dv51[c11_i231];
              }

              c11_updateDataWrittenToVector(chartInstance, 20U);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 34);
              if (CV_EML_IF(4, 1, 6, c11_E == 6.0)) {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 35);
                for (c11_i232 = 0; c11_i232 < 6; c11_i232++) {
                  c11_eAmountFactor[c11_i232] = c11_dv52[c11_i232];
                }

                c11_updateDataWrittenToVector(chartInstance, 20U);
              } else {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 36);
                if (CV_EML_IF(4, 1, 7, c11_E == 7.0)) {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 37);
                  for (c11_i233 = 0; c11_i233 < 6; c11_i233++) {
                    c11_eAmountFactor[c11_i233] = c11_dv53[c11_i233];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 20U);
                } else {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 38);
                  if (CV_EML_IF(4, 1, 8, c11_E == 8.0)) {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 39);
                    for (c11_i234 = 0; c11_i234 < 6; c11_i234++) {
                      c11_eAmountFactor[c11_i234] = c11_dv54[c11_i234];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 20U);
                  } else {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 41);
                    for (c11_i235 = 0; c11_i235 < 6; c11_i235++) {
                      c11_eAmountFactor[c11_i235] = 0.0;
                    }

                    c11_updateDataWrittenToVector(chartInstance, 20U);
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 42);
                    for (c11_i236 = 0; c11_i236 < 43; c11_i236++) {
                      c11_u[c11_i236] = c11_cv19[c11_i236];
                    }

                    c11_y = NULL;
                    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U,
                      0U, 2, 1, 43), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c11_y);
                  }
                }
              }
            }
          }
        }
      }
    }

    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 44);
    c11_errorIfDataNotWrittenToFcn(chartInstance, 20U, 47U);
    for (c11_i237 = 0; c11_i237 < 6; c11_i237++) {
      c11_a[c11_i237] = c11_eAmountFactor[c11_i237];
    }

    c11_b = c11_cFactor;
    for (c11_i238 = 0; c11_i238 < 6; c11_i238++) {
      c11_eAmountFactor[c11_i238] = c11_a[c11_i238] * c11_b;
    }

    c11_updateDataWrittenToVector(chartInstance, 20U);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 46);
    if (CV_EML_IF(4, 1, 9, c11_p == 2.0)) {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 47);
      if (CV_EML_IF(4, 1, 10, c11_E == 1.0)) {
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 48);
        for (c11_i239 = 0; c11_i239 < 6; c11_i239++) {
          c11_eAmountFactor[c11_i239] = c11_dv47[c11_i239];
        }

        c11_updateDataWrittenToVector(chartInstance, 20U);
      } else {
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 49);
        if (CV_EML_IF(4, 1, 11, c11_E == 2.0)) {
          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 50);
          for (c11_i240 = 0; c11_i240 < 6; c11_i240++) {
            c11_eAmountFactor[c11_i240] = c11_dv48[c11_i240];
          }

          c11_updateDataWrittenToVector(chartInstance, 20U);
        } else {
          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 51);
          if (CV_EML_IF(4, 1, 12, c11_E == 3.0)) {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 52);
            for (c11_i241 = 0; c11_i241 < 6; c11_i241++) {
              c11_eAmountFactor[c11_i241] = c11_dv49[c11_i241];
            }

            c11_updateDataWrittenToVector(chartInstance, 20U);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 53);
            if (CV_EML_IF(4, 1, 13, c11_E == 4.0)) {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 54);
              for (c11_i242 = 0; c11_i242 < 6; c11_i242++) {
                c11_eAmountFactor[c11_i242] = c11_dv50[c11_i242];
              }

              c11_updateDataWrittenToVector(chartInstance, 20U);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 55);
              if (CV_EML_IF(4, 1, 14, c11_E == 5.0)) {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 56);
                for (c11_i243 = 0; c11_i243 < 6; c11_i243++) {
                  c11_eAmountFactor[c11_i243] = c11_dv51[c11_i243];
                }

                c11_updateDataWrittenToVector(chartInstance, 20U);
              } else {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 57);
                if (CV_EML_IF(4, 1, 15, c11_E == 6.0)) {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 58);
                  for (c11_i244 = 0; c11_i244 < 6; c11_i244++) {
                    c11_eAmountFactor[c11_i244] = c11_dv52[c11_i244];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 20U);
                } else {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 59);
                  if (CV_EML_IF(4, 1, 16, c11_E == 7.0)) {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 60);
                    for (c11_i245 = 0; c11_i245 < 6; c11_i245++) {
                      c11_eAmountFactor[c11_i245] = c11_dv55[c11_i245];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 20U);
                  } else {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 61);
                    if (CV_EML_IF(4, 1, 17, c11_E == 8.0)) {
                      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 62);
                      for (c11_i246 = 0; c11_i246 < 6; c11_i246++) {
                        c11_eAmountFactor[c11_i246] = c11_dv56[c11_i246];
                      }

                      c11_updateDataWrittenToVector(chartInstance, 20U);
                    } else {
                      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 64);
                      for (c11_i247 = 0; c11_i247 < 6; c11_i247++) {
                        c11_eAmountFactor[c11_i247] = 0.0;
                      }

                      c11_updateDataWrittenToVector(chartInstance, 20U);
                      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 65);
                      for (c11_i248 = 0; c11_i248 < 43; c11_i248++) {
                        c11_b_u[c11_i248] = c11_cv19[c11_i248];
                      }

                      c11_b_y = NULL;
                      sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U,
                        1U, 0U, 2, 1, 43), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c11_b_y);
                    }
                  }
                }
              }
            }
          }
        }
      }

      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 67);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 20U, 47U);
      for (c11_i249 = 0; c11_i249 < 6; c11_i249++) {
        c11_a[c11_i249] = c11_eAmountFactor[c11_i249];
      }

      c11_b_b = c11_cFactor;
      for (c11_i250 = 0; c11_i250 < 6; c11_i250++) {
        c11_eAmountFactor[c11_i250] = c11_a[c11_i250] * c11_b_b;
      }

      c11_updateDataWrittenToVector(chartInstance, 20U);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 69);
      if (CV_EML_IF(4, 1, 18, c11_p == 3.0)) {
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 70);
        if (CV_EML_IF(4, 1, 19, c11_E == 1.0)) {
          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 71);
          for (c11_i251 = 0; c11_i251 < 6; c11_i251++) {
            c11_eAmountFactor[c11_i251] = c11_dv47[c11_i251];
          }

          c11_updateDataWrittenToVector(chartInstance, 20U);
        } else {
          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 72);
          if (CV_EML_IF(4, 1, 20, c11_E == 2.0)) {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 73);
            for (c11_i252 = 0; c11_i252 < 6; c11_i252++) {
              c11_eAmountFactor[c11_i252] = c11_dv48[c11_i252];
            }

            c11_updateDataWrittenToVector(chartInstance, 20U);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 74);
            if (CV_EML_IF(4, 1, 21, c11_E == 3.0)) {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 75);
              for (c11_i253 = 0; c11_i253 < 6; c11_i253++) {
                c11_eAmountFactor[c11_i253] = c11_dv49[c11_i253];
              }

              c11_updateDataWrittenToVector(chartInstance, 20U);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 76);
              if (CV_EML_IF(4, 1, 22, c11_E == 4.0)) {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 77);
                for (c11_i254 = 0; c11_i254 < 6; c11_i254++) {
                  c11_eAmountFactor[c11_i254] = c11_dv50[c11_i254];
                }

                c11_updateDataWrittenToVector(chartInstance, 20U);
              } else {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 78);
                if (CV_EML_IF(4, 1, 23, c11_E == 5.0)) {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 79);
                  for (c11_i255 = 0; c11_i255 < 6; c11_i255++) {
                    c11_eAmountFactor[c11_i255] = c11_dv51[c11_i255];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 20U);
                } else {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 80);
                  if (CV_EML_IF(4, 1, 24, c11_E == 6.0)) {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 81);
                    for (c11_i256 = 0; c11_i256 < 6; c11_i256++) {
                      c11_eAmountFactor[c11_i256] = c11_dv52[c11_i256];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 20U);
                  } else {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 82);
                    if (CV_EML_IF(4, 1, 25, c11_E == 7.0)) {
                      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 83);
                      for (c11_i257 = 0; c11_i257 < 6; c11_i257++) {
                        c11_eAmountFactor[c11_i257] = c11_dv55[c11_i257];
                      }

                      c11_updateDataWrittenToVector(chartInstance, 20U);
                    } else {
                      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 84);
                      if (CV_EML_IF(4, 1, 26, c11_E == 8.0)) {
                        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 85);
                        for (c11_i258 = 0; c11_i258 < 6; c11_i258++) {
                          c11_eAmountFactor[c11_i258] = c11_dv56[c11_i258];
                        }

                        c11_updateDataWrittenToVector(chartInstance, 20U);
                      } else {
                        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 87);
                        for (c11_i259 = 0; c11_i259 < 6; c11_i259++) {
                          c11_eAmountFactor[c11_i259] = 0.0;
                        }

                        c11_updateDataWrittenToVector(chartInstance, 20U);
                        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 88);
                        for (c11_i260 = 0; c11_i260 < 43; c11_i260++) {
                          c11_c_u[c11_i260] = c11_cv19[c11_i260];
                        }

                        c11_c_y = NULL;
                        sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_c_u, 10,
                          0U, 1U, 0U, 2, 1, 43), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c11_c_y);
                      }
                    }
                  }
                }
              }
            }
          }
        }

        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 90);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 20U, 47U);
        for (c11_i261 = 0; c11_i261 < 6; c11_i261++) {
          c11_a[c11_i261] = c11_eAmountFactor[c11_i261];
        }

        for (c11_i262 = 0; c11_i262 < 6; c11_i262++) {
          c11_a[c11_i262] *= 0.8;
        }

        c11_c_b = c11_cFactor;
        for (c11_i263 = 0; c11_i263 < 6; c11_i263++) {
          c11_eAmountFactor[c11_i263] = c11_a[c11_i263] * c11_c_b;
        }

        c11_updateDataWrittenToVector(chartInstance, 20U);
      } else {
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 92);
        if (CV_EML_IF(4, 1, 27, c11_p == 4.0)) {
          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 93);
          if (CV_EML_IF(4, 1, 28, c11_E == 1.0)) {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 94);
            for (c11_i264 = 0; c11_i264 < 6; c11_i264++) {
              c11_eAmountFactor[c11_i264] = c11_dv47[c11_i264];
            }

            c11_updateDataWrittenToVector(chartInstance, 20U);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 95);
            if (CV_EML_IF(4, 1, 29, c11_E == 2.0)) {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 96);
              for (c11_i265 = 0; c11_i265 < 6; c11_i265++) {
                c11_eAmountFactor[c11_i265] = c11_dv48[c11_i265];
              }

              c11_updateDataWrittenToVector(chartInstance, 20U);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 97);
              if (CV_EML_IF(4, 1, 30, c11_E == 3.0)) {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 98);
                for (c11_i266 = 0; c11_i266 < 6; c11_i266++) {
                  c11_eAmountFactor[c11_i266] = c11_dv49[c11_i266];
                }

                c11_updateDataWrittenToVector(chartInstance, 20U);
              } else {
                _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 99);
                if (CV_EML_IF(4, 1, 31, c11_E == 4.0)) {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 100);
                  for (c11_i267 = 0; c11_i267 < 6; c11_i267++) {
                    c11_eAmountFactor[c11_i267] = c11_dv50[c11_i267];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 20U);
                } else {
                  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 101);
                  if (CV_EML_IF(4, 1, 32, c11_E == 5.0)) {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 102);
                    for (c11_i268 = 0; c11_i268 < 6; c11_i268++) {
                      c11_eAmountFactor[c11_i268] = c11_dv51[c11_i268];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 20U);
                  } else {
                    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 103);
                    if (CV_EML_IF(4, 1, 33, c11_E == 6.0)) {
                      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 104);
                      for (c11_i269 = 0; c11_i269 < 6; c11_i269++) {
                        c11_eAmountFactor[c11_i269] = c11_dv52[c11_i269];
                      }

                      c11_updateDataWrittenToVector(chartInstance, 20U);
                    } else {
                      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 105);
                      if (CV_EML_IF(4, 1, 34, c11_E == 7.0)) {
                        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 106);
                        for (c11_i270 = 0; c11_i270 < 6; c11_i270++) {
                          c11_eAmountFactor[c11_i270] = c11_dv55[c11_i270];
                        }

                        c11_updateDataWrittenToVector(chartInstance, 20U);
                      } else {
                        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 107);
                        if (CV_EML_IF(4, 1, 35, c11_E == 8.0)) {
                          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 108);
                          for (c11_i271 = 0; c11_i271 < 6; c11_i271++) {
                            c11_eAmountFactor[c11_i271] = c11_dv56[c11_i271];
                          }

                          c11_updateDataWrittenToVector(chartInstance, 20U);
                        } else {
                          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 110);
                          for (c11_i272 = 0; c11_i272 < 6; c11_i272++) {
                            c11_eAmountFactor[c11_i272] = 0.0;
                          }

                          c11_updateDataWrittenToVector(chartInstance, 20U);
                          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 111);
                          for (c11_i273 = 0; c11_i273 < 43; c11_i273++) {
                            c11_d_u[c11_i273] = c11_cv19[c11_i273];
                          }

                          c11_d_y = NULL;
                          sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_d_u, 10,
                            0U, 1U, 0U, 2, 1, 43), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c11_d_y);
                        }
                      }
                    }
                  }
                }
              }
            }
          }

          _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 113);
          c11_errorIfDataNotWrittenToFcn(chartInstance, 20U, 47U);
          for (c11_i274 = 0; c11_i274 < 6; c11_i274++) {
            c11_a[c11_i274] = c11_eAmountFactor[c11_i274];
          }

          for (c11_i275 = 0; c11_i275 < 6; c11_i275++) {
            c11_a[c11_i275] *= 0.8;
          }

          c11_d_b = c11_cFactor;
          for (c11_i276 = 0; c11_i276 < 6; c11_i276++) {
            c11_eAmountFactor[c11_i276] = c11_a[c11_i276] * c11_d_b;
          }

          c11_updateDataWrittenToVector(chartInstance, 20U);
        }
      }
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 119);
  c11_A = c11_arousal;
  c11_x = c11_A;
  c11_b_x = c11_x;
  c11_c_x = c11_b_x;
  c11_e_y = c11_c_x / 250.0;
  c11_a_factor = c11_abs(chartInstance, 0.4 + c11_e_y);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 120);
  c11_b_A = c11_valence;
  c11_d_x = c11_b_A;
  c11_e_x = c11_d_x;
  c11_f_x = c11_e_x;
  c11_f_y = c11_f_x / 250.0;
  c11_v_factor = c11_abs(chartInstance, 0.4 + c11_f_y);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 124);
  c11_c = 1.0;
  c11_b_c = 0;
  while (c11_b_c < 6) {
    c11_c = 1.0 + (real_T)c11_b_c;
    CV_EML_FOR(4, 1, 0, 1);
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 125);
    if (CV_EML_IF(4, 1, 36, c11_arousal > 0.0)) {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 126);
      guard2 = false;
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(4, 1, 0, c11_AU[(int32_T)c11_c - 1] == 1.0)) {
        guard4 = true;
      } else if (CV_EML_COND(4, 1, 1, c11_AU[(int32_T)c11_c - 1] == 2.0)) {
        guard4 = true;
      } else if (CV_EML_COND(4, 1, 2, c11_AU[(int32_T)c11_c - 1] == 5.0)) {
        guard3 = true;
      } else if (CV_EML_COND(4, 1, 3, c11_AU[(int32_T)c11_c - 1] == 26.0)) {
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
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, MAX_int8_T);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 20U, 47U);
        c11_eAmountFactor[(int32_T)c11_c - 1] *= c11_a_factor;
        c11_updateDataWrittenToVector(chartInstance, 20U);
      }
    }

    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 130U);
    if (CV_EML_IF(4, 1, 38, c11_valence > 0.0)) {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 131U);
      guard1 = false;
      if (CV_EML_COND(4, 1, 4, c11_AU[(int32_T)c11_c - 1] == 6.0)) {
        guard1 = true;
      } else if (CV_EML_COND(4, 1, 5, c11_AU[(int32_T)c11_c - 1] == 12.0)) {
        guard1 = true;
      } else {
        CV_EML_MCDC(4, 1, 1, false);
        CV_EML_IF(4, 1, 39, false);
      }

      if (guard1 == true) {
        CV_EML_MCDC(4, 1, 1, true);
        CV_EML_IF(4, 1, 39, true);
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 132U);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 20U, 47U);
        c11_eAmountFactor[(int32_T)c11_c - 1] *= c11_v_factor;
        c11_updateDataWrittenToVector(chartInstance, 20U);
      }
    } else {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 135U);
      if (CV_EML_IF(4, 1, 40, c11_AU[(int32_T)c11_c - 1] == 4.0)) {
        _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 136U);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 20U, 47U);
        c11_eAmountFactor[(int32_T)c11_c - 1] *= c11_v_factor;
        c11_updateDataWrittenToVector(chartInstance, 20U);
      }
    }

    c11_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(4, 1, 0, 0);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, -136);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c11_isequal(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c11_varargin_1[1000], real_T c11_varargin_2[1000])
{
  boolean_T c11_p;
  boolean_T c11_b_p;
  int32_T c11_k;
  real_T c11_b_k;
  real_T c11_x1;
  real_T c11_x2;
  boolean_T c11_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c11_p = false;
  c11_b_p = true;
  c11_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c11_k < 1000)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    c11_x1 = c11_varargin_1[(int32_T)c11_b_k - 1];
    c11_x2 = c11_varargin_2[(int32_T)c11_b_k - 1];
    c11_c_p = (c11_x1 == c11_x2);
    if (!c11_c_p) {
      c11_b_p = false;
      exitg1 = true;
    } else {
      c11_k++;
    }
  }

  if (!c11_b_p) {
  } else {
    c11_p = true;
  }

  return c11_p;
}

static real_T c11_abs(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
                      real_T c11_x)
{
  real_T c11_b_x;
  (void)chartInstance;
  c11_b_x = c11_x;
  return muDoubleScalarAbs(c11_b_x);
}

void sf_exported_user_c11_Demo_EP_IdleRandMerg_facialExpr(SimStruct *c11_S,
  real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[1000])
{
  real_T c11_b_p;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_facialExprc11_Demo_EP_IdleRandMerg(chartInstance, c11_bmlID, &c11_b_p,
    c11_poseBML);
  *c11_p = c11_b_p;
}

void sf_exported_user_c11_Demo_EP_IdleRandMerg_insertQueue(SimStruct *c11_S,
  real_T c11_bmls[5000], real_T c11_myBML[1000], real_T c11_newBmls[5000])
{
  int32_T c11_i277;
  real_T c11_b_bmls[5000];
  int32_T c11_i278;
  real_T c11_b_myBML[1000];
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  for (c11_i277 = 0; c11_i277 < 5000; c11_i277++) {
    c11_b_bmls[c11_i277] = c11_bmls[c11_i277];
  }

  for (c11_i278 = 0; c11_i278 < 1000; c11_i278++) {
    c11_b_myBML[c11_i278] = c11_myBML[c11_i278];
  }

  c11_insertQueuec11_Demo_EP_IdleRandMerg(chartInstance, c11_b_bmls, c11_b_myBML,
    c11_newBmls);
}

void sf_exported_user_c11_Demo_EP_IdleRandMerg_insertQueueLow(SimStruct *c11_S,
  real_T c11_bmls[5000], real_T c11_myBML[1000], real_T c11_newBmls[5000])
{
  int32_T c11_i279;
  real_T c11_b_bmls[5000];
  int32_T c11_i280;
  real_T c11_b_myBML[1000];
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  for (c11_i279 = 0; c11_i279 < 5000; c11_i279++) {
    c11_b_bmls[c11_i279] = c11_bmls[c11_i279];
  }

  for (c11_i280 = 0; c11_i280 < 1000; c11_i280++) {
    c11_b_myBML[c11_i280] = c11_myBML[c11_i280];
  }

  c11_insertQueueLowc11_Demo_EP_IdleRandMerg(chartInstance, c11_b_bmls,
    c11_b_myBML, c11_newBmls);
}

void sf_exported_user_c11_Demo_EP_IdleRandMerg_setAU(SimStruct *c11_S, real_T
  c11_E, real_T c11_AU[6], real_T *c11_L)
{
  real_T c11_b_L;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_setAUc11_Demo_EP_IdleRandMerg(chartInstance, c11_E, c11_AU, &c11_b_L);
  *c11_L = c11_b_L;
}

void sf_exported_user_c11_Demo_EP_IdleRandMerg_set_eAmountFactor(SimStruct
  *c11_S, real_T c11_E, real_T c11_p, real_T c11_cFactor, real_T c11_AU[6],
  real_T c11_arousal, real_T c11_valence, real_T c11_eAmountFactor[6])
{
  int32_T c11_i281;
  real_T c11_b_AU[6];
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  for (c11_i281 = 0; c11_i281 < 6; c11_i281++) {
    c11_b_AU[c11_i281] = c11_AU[c11_i281];
  }

  c11_set_eAmountFactorc11_Demo_EP_IdleRandMerg(chartInstance, c11_E, c11_p,
    c11_cFactor, c11_b_AU, c11_arousal, c11_valence, c11_eAmountFactor);
}

void sf_exported_user_c11_Demo_EP_IdleRandMerg_smileTable(SimStruct *c11_S,
  real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[1000])
{
  real_T c11_b_p;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_smileTablec11_Demo_EP_IdleRandMerg(chartInstance, c11_bmlID, &c11_b_p,
    c11_poseBML);
  *c11_p = c11_b_p;
}

static const mxArray *c11_x_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int8_T c11_w_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int8_T c11_y;
  int8_T c11_i282;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i282, 1, 2, 0U, 0, 0U, 0);
  c11_y = c11_i282;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_secs;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int8_T c11_y;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_secs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_secs),
    &c11_thisId);
  sf_mex_destroy(&c11_secs);
  *(int8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_y_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_x_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i283;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i283, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i283;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_y_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_subSmile, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_subSmile),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_subSmile);
  return c11_y;
}

static uint8_T c11_ab_emlrt_marshallIn(SFc11_Demo_EP_IdleRandMergInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_subSmile;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c11_b_tp_subSmile = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_subSmile),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_subSmile);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_bb_emlrt_marshallIn
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_cb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_cb_emlrt_marshallIn
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray *c11_u,
   const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  (void)c11_parentId;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_updateDataWrittenToVector
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex)
{
  (void)chartInstance;
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 20, 1, 0)] = true;
}

static void c11_errorIfDataNotWrittenToFcn
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex, uint32_T c11_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c11_dataNumber, c11_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c11_vectorIndex, 0, 20, 1,
    0)]);
}

static void c11_b_log10(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T *c11_x)
{
  (void)chartInstance;
  *c11_x = muDoubleScalarLog10(*c11_x);
}

static void c11_b_ceil(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T *c11_x)
{
  (void)chartInstance;
  *c11_x = muDoubleScalarCeil(*c11_x);
}

static real_T c11_get_BML(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#923) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_BML_address)[c11_b];
}

static void c11_set_BML(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#923) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_BML_address)[c11_b] = c11_c;
}

static real_T *c11_access_BML(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#923) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_BML_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static real_T c11_get_GAZE_WIN(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#922) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_GAZE_WIN_address;
}

static void c11_set_GAZE_WIN(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#922) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_GAZE_WIN_address = c11_c;
}

static real_T *c11_access_GAZE_WIN(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#922) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_GAZE_WIN_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c11_c;
}

static real_T c11_get_P(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#924) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_P_address;
}

static void c11_set_P(SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
                      uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#924) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_P_address = c11_c;
}

static real_T *c11_access_P(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#924) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_P_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_BEFORE(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#929) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_BEFORE_address;
}

static void c11_set_STATE_BEFORE(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#929) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_BEFORE_address = c11_c;
}

static real_T *c11_access_STATE_BEFORE(SFc11_Demo_EP_IdleRandMergInstanceStruct *
  chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#929) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_BEFORE_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_GO(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#927) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_GO_address;
}

static void c11_set_STATE_GO(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#927) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_GO_address = c11_c;
}

static real_T *c11_access_STATE_GO(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#927) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_GO_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_READY(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#928) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_READY_address;
}

static void c11_set_STATE_READY(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#928) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_READY_address = c11_c;
}

static real_T *c11_access_STATE_READY(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#928) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_READY_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#920) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_address;
}

static void c11_set_avert(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#920) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_address = c11_c;
}

static real_T *c11_access_avert(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#920) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c11_c;
}

static real_T c11_get_bmlsL(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#942) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_bmlsL_address)[c11_b];
}

static void c11_set_bmlsL(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#942) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_bmlsL_address)[c11_b] = c11_c;
}

static real_T *c11_access_bmlsL(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c11_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#942) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_bmlsL_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c11_c;
}

static real_T c11_get_bmlsM(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#931) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_bmlsM_address)[c11_b];
}

static void c11_set_bmlsM(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#931) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_bmlsM_address)[c11_b] = c11_c;
}

static real_T *c11_access_bmlsM(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#931) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_bmlsM_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c11_c;
}

static real_T c11_get_emotion_amount_factor
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#937) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_emotion_amount_factor_address)[c11_b];
}

static void c11_set_emotion_amount_factor
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T c11_b,
   real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#937) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_emotion_amount_factor_address)[c11_b] = c11_c;
}

static real_T *c11_access_emotion_amount_factor
  (SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c11_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#937) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_emotion_amount_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c11_c;
}

static real_T c11_get_gazing(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#921) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_gazing_address;
}

static void c11_set_gazing(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#921) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_gazing_address = c11_c;
}

static real_T *c11_access_gazing(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#921) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_gazing_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info(SFc11_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c11_BML_address, &chartInstance->c11_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c11_GAZE_WIN_address, &chartInstance->c11_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c11_P_address, &chartInstance->c11_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c11_STATE_BEFORE_address,
    &chartInstance->c11_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c11_STATE_GO_address, &chartInstance->c11_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c11_STATE_READY_address,
    &chartInstance->c11_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c11_avert_address, &chartInstance->c11_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c11_bmlsL_address, &chartInstance->c11_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c11_bmlsM_address, &chartInstance->c11_bmlsM_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "emotion_amount_factor", (void
    **)&chartInstance->c11_emotion_amount_factor_address,
    &chartInstance->c11_emotion_amount_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c11_gazing_address, &chartInstance->c11_gazing_index);
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

void sf_c11_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3343029876U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2582395579U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2736589356U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(705481857U);
}

mxArray *sf_c11_Demo_EP_IdleRandMerg_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zecKv8Et7UmYg1AgCMmnQE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

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
      pr[0] = (double)(1000);
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
      pr[0] = (double)(1000);
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
      pr[0] = (double)(1000);
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
      pr[1] = (double)(6);
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
      pr[0] = (double)(1000);
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
      pr[0] = (double)(1000);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_Demo_EP_IdleRandMerg_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_Demo_EP_IdleRandMerg_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_Demo_EP_IdleRandMerg(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[61],T\"gameState\",},{M[3],M[79],T\"BMLM\",},{M[3],M[175],T\"BMLl\",},{M[3],M[104],T\"au\",},{M[3],M[142],T\"au_L\",},{M[3],M[141],T\"au_i\",},{M[3],M[166],T\"emoDisp\",},{M[3],M[55],T\"fileID\",},{M[3],M[80],T\"n\",},{M[3],M[176],T\"newBmlsL\",}}",
    "100 S1x9'type','srcId','name','auxInfo'{{M[3],M[77],T\"newBmlsM\",},{M[3],M[10],T\"smileN\",},{M[8],M[0],T\"is_active_c11_Demo_EP_IdleRandMerg\",},{M[8],M[95],T\"is_active_subSmile\",},{M[8],M[116],T\"is_active_subFacial\",},{M[9],M[95],T\"is_subSmile\",},{M[9],M[116],T\"is_subFacial\",},{M[11],M[39],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x2[67 81],M[1]}}},{M[11],M[39],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M1x2[197 180],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 19, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Demo_EP_IdleRandMerg_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_EP_IdleRandMergMachineNumber_,
           11,
           18,
           17,
           0,
           53,
           1,
           0,
           0,
           0,
           3,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_EP_IdleRandMergMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_EP_IdleRandMergMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_EP_IdleRandMergMachineNumber_,
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
          _SFD_SET_DATA_PROPS(31,8,0,0,"");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
          _SFD_SET_DATA_PROPS(33,9,0,0,"");
          _SFD_SET_DATA_PROPS(34,8,0,0,"");
          _SFD_SET_DATA_PROPS(35,8,0,0,"");
          _SFD_SET_DATA_PROPS(36,9,0,0,"");
          _SFD_SET_DATA_PROPS(37,8,0,0,"");
          _SFD_SET_DATA_PROPS(38,9,0,0,"");
          _SFD_SET_DATA_PROPS(39,9,0,0,"");
          _SFD_SET_DATA_PROPS(40,8,0,0,"");
          _SFD_SET_DATA_PROPS(41,9,0,0,"");
          _SFD_SET_DATA_PROPS(42,9,0,0,"");
          _SFD_SET_DATA_PROPS(43,8,0,0,"");
          _SFD_SET_DATA_PROPS(44,9,0,0,"");
          _SFD_SET_DATA_PROPS(45,9,0,0,"");
          _SFD_SET_DATA_PROPS(46,8,0,0,"");
          _SFD_SET_DATA_PROPS(47,9,0,0,"");
          _SFD_SET_DATA_PROPS(48,8,0,0,"");
          _SFD_SET_DATA_PROPS(49,8,0,0,"");
          _SFD_SET_DATA_PROPS(50,8,0,0,"");
          _SFD_SET_DATA_PROPS(51,8,0,0,"");
          _SFD_SET_DATA_PROPS(52,8,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,1);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,12);
          _SFD_CH_SUBSTATE_INDEX(1,6);
          _SFD_ST_SUBSTATE_COUNT(12,5);
          _SFD_ST_SUBSTATE_INDEX(12,0,13);
          _SFD_ST_SUBSTATE_INDEX(12,1,14);
          _SFD_ST_SUBSTATE_INDEX(12,2,15);
          _SFD_ST_SUBSTATE_INDEX(12,3,16);
          _SFD_ST_SUBSTATE_INDEX(12,4,17);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(6,5);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_INDEX(6,2,9);
          _SFD_ST_SUBSTATE_INDEX(6,3,10);
          _SFD_ST_SUBSTATE_INDEX(6,4,11);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
        }

        _SFD_CV_INIT_CHART(2,0,0,0);

        {
          _SFD_CV_INIT_STATE(6,5,1,1,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,5,1,1,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"insertQueuec11_Demo_EP_IdleRandMerg",0,-1,565);
        _SFD_CV_INIT_EML_IF(1,1,0,126,151,-1,-2);
        _SFD_CV_INIT_EML_IF(1,1,1,296,307,-1,546);
        _SFD_CV_INIT_EML_FOR(1,1,0,106,118,291);
        _SFD_CV_INIT_EML(2,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"insertQueueLowc11_Demo_EP_IdleRandMerg",0,-1,
                             568);
        _SFD_CV_INIT_EML_IF(2,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(2,1,1,299,310,-1,549);
        _SFD_CV_INIT_EML_FOR(2,1,0,109,121,294);
        _SFD_CV_INIT_EML(5,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"smileTablec11_Demo_EP_IdleRandMerg",0,-1,404);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",404,-1,699);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",699,-1,891);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",891,-1,1190);
        _SFD_CV_INIT_EML_IF(5,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(5,1,1,289,323,354,402);
        _SFD_CV_INIT_EML(0,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"facialExprc11_Demo_EP_IdleRandMerg",0,-1,404);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",404,-1,707);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",707,-1,899);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",899,-1,1198);
        _SFD_CV_INIT_EML_IF(0,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(0,1,1,289,323,354,402);
        _SFD_CV_INIT_EML(3,1,1,0,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"setAUc11_Demo_EP_IdleRandMerg",0,-1,2056);

        {
          static int caseStart[] = { 1696, 776, 867, 995, 1138, 1243, 1334, 1429,
            1516, 1604 };

          static int caseExprEnd[] = { 1705, 782, 873, 1001, 1144, 1249, 1340,
            1435, 1522, 1610 };

          _SFD_CV_INIT_EML_SWITCH(3,1,0,758,767,1966,10,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_EML(4,1,1,41,0,0,0,1,0,6,2);
        _SFD_CV_INIT_EML_FCN(4,0,"set_eAmountFactorc11_Demo_EP_IdleRandMerg",0,
                             -1,6929);
        _SFD_CV_INIT_EML_IF(4,1,0,806,814,1729,1741);
        _SFD_CV_INIT_EML_IF(4,1,1,837,845,915,1663);
        _SFD_CV_INIT_EML_IF(4,1,2,915,927,990,1663);
        _SFD_CV_INIT_EML_IF(4,1,3,990,1002,1075,1663);
        _SFD_CV_INIT_EML_IF(4,1,4,1075,1087,1162,1663);
        _SFD_CV_INIT_EML_IF(4,1,5,1162,1174,1251,1663);
        _SFD_CV_INIT_EML_IF(4,1,6,1251,1263,1343,1663);
        _SFD_CV_INIT_EML_IF(4,1,7,1343,1355,1429,1663);
        _SFD_CV_INIT_EML_IF(4,1,8,1429,1441,1531,1663);
        _SFD_CV_INIT_EML_IF(4,1,9,1729,1741,2631,4483);
        _SFD_CV_INIT_EML_IF(4,1,10,1750,1758,1828,2568);
        _SFD_CV_INIT_EML_IF(4,1,11,1828,1840,1903,2568);
        _SFD_CV_INIT_EML_IF(4,1,12,1903,1915,1988,2568);
        _SFD_CV_INIT_EML_IF(4,1,13,1988,2000,2075,2568);
        _SFD_CV_INIT_EML_IF(4,1,14,2075,2087,2164,2568);
        _SFD_CV_INIT_EML_IF(4,1,15,2164,2176,2256,2568);
        _SFD_CV_INIT_EML_IF(4,1,16,2256,2268,2346,2568);
        _SFD_CV_INIT_EML_IF(4,1,17,2346,2358,2446,2568);
        _SFD_CV_INIT_EML_IF(4,1,18,2631,2643,3562,4483);
        _SFD_CV_INIT_EML_IF(4,1,19,2652,2660,2730,3490);
        _SFD_CV_INIT_EML_IF(4,1,20,2730,2742,2805,3490);
        _SFD_CV_INIT_EML_IF(4,1,21,2805,2817,2890,3490);
        _SFD_CV_INIT_EML_IF(4,1,22,2890,2902,2977,3490);
        _SFD_CV_INIT_EML_IF(4,1,23,2977,2989,3066,3490);
        _SFD_CV_INIT_EML_IF(4,1,24,3066,3078,3158,3490);
        _SFD_CV_INIT_EML_IF(4,1,25,3158,3170,3248,3490);
        _SFD_CV_INIT_EML_IF(4,1,26,3248,3260,3348,3490);
        _SFD_CV_INIT_EML_IF(4,1,27,3562,3574,-1,3574);
        _SFD_CV_INIT_EML_IF(4,1,28,3584,3592,3662,4422);
        _SFD_CV_INIT_EML_IF(4,1,29,3662,3674,3737,4422);
        _SFD_CV_INIT_EML_IF(4,1,30,3737,3749,3822,4422);
        _SFD_CV_INIT_EML_IF(4,1,31,3822,3834,3909,4422);
        _SFD_CV_INIT_EML_IF(4,1,32,3909,3921,3998,4422);
        _SFD_CV_INIT_EML_IF(4,1,33,3998,4010,4090,4422);
        _SFD_CV_INIT_EML_IF(4,1,34,4090,4102,4180,4422);
        _SFD_CV_INIT_EML_IF(4,1,35,4180,4192,4280,4422);
        _SFD_CV_INIT_EML_IF(4,1,36,4930,4943,-1,5091);
        _SFD_CV_INIT_EML_IF(4,1,37,4956,5003,-1,5079);
        _SFD_CV_INIT_EML_IF(4,1,38,5100,5113,5236,5362);
        _SFD_CV_INIT_EML_IF(4,1,39,5126,5151,-1,5227);
        _SFD_CV_INIT_EML_IF(4,1,40,5261,5273,-1,5350);
        _SFD_CV_INIT_EML_FOR(4,1,0,4910,4922,5374);

        {
          static int condStart[] = { 4960, 4971, 4982, 4993 };

          static int condEnd[] = { 4968, 4979, 4990, 5002 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2, 3, -2 };

          _SFD_CV_INIT_EML_MCDC(4,1,0,4960,5002,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5130, 5141 };

          static int condEnd[] = { 5138, 5150 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(4,1,1,5130,5150,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_SCRIPT(1,1,8,0,0,0,2,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"cmdBML_AUmerg",0,-1,3068);
        _SFD_CV_INIT_SCRIPT_IF(1,0,487,521,1167,1803);
        _SFD_CV_INIT_SCRIPT_IF(1,1,2058,2077,-1,-2);
        _SFD_CV_INIT_SCRIPT_IF(1,2,2651,2659,2691,2703);
        _SFD_CV_INIT_SCRIPT_IF(1,3,2691,2703,2735,2914);
        _SFD_CV_INIT_SCRIPT_IF(1,4,2735,2747,2779,2914);
        _SFD_CV_INIT_SCRIPT_IF(1,5,2779,2791,2823,2914);
        _SFD_CV_INIT_SCRIPT_IF(1,6,2823,2835,2867,2914);
        _SFD_CV_INIT_SCRIPT_IF(1,7,2867,2879,-1,2879);
        _SFD_CV_INIT_SCRIPT_FOR(1,0,355,367,2519);
        _SFD_CV_INIT_SCRIPT_FOR(1,1,2036,2046,2350);
        _SFD_CV_INIT_SCRIPT(2,1,4,0,0,0,0,0,6,3);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"countDigits",0,-1,267);
        _SFD_CV_INIT_SCRIPT_IF(2,0,43,49,-1,94);
        _SFD_CV_INIT_SCRIPT_IF(2,1,103,120,152,175);
        _SFD_CV_INIT_SCRIPT_IF(2,2,152,175,207,263);
        _SFD_CV_INIT_SCRIPT_IF(2,3,207,232,-1,232);

        {
          static int condStart[] = { 107, 116 };

          static int condEnd[] = { 110, 119 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(2,0,106,120,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 160, 170 };

          static int condEnd[] = { 164, 174 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(2,1,159,175,2,2,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 215, 226 };

          static int condEnd[] = { 220, 231 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(2,2,214,232,2,4,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
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

        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 1000;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)
            c11_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_m_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_m_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_m_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_m_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_m_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
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
          real_T *c11_isSmiling;
          real_T *c11_gameState;
          real_T *c11_personality;
          real_T *c11_internalE;
          boolean_T *c11_aChange;
          real_T *c11_emotion_amount_custom;
          real_T *c11_inA;
          real_T *c11_inV;
          boolean_T *c11_vChange;
          c11_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c11_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c11_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c11_emotion_amount_custom = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 4);
          c11_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c11_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c11_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c11_smileN);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c11_avert_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c11_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c11_BML_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c11_P_address);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c11_fileID);
          _SFD_SET_DATA_VALUE_PTR(8U, c11_gameState);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c11_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c11_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c11_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c11_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(13U, *chartInstance->c11_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c11_BMLM);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c11_n);
          _SFD_SET_DATA_VALUE_PTR(16U, c11_personality);
          _SFD_SET_DATA_VALUE_PTR(17U, c11_internalE);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c11_au);
          _SFD_SET_DATA_VALUE_PTR(19U,
            *chartInstance->c11_emotion_amount_factor_address);
          _SFD_SET_DATA_VALUE_PTR(20U, c11_aChange);
          _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c11_au_i);
          _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c11_au_L);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c11_emoDisp);
          _SFD_SET_DATA_VALUE_PTR(24U, *chartInstance->c11_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c11_BMLl);
          _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c11_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(27U, c11_emotion_amount_custom);
          _SFD_SET_DATA_VALUE_PTR(28U, c11_inA);
          _SFD_SET_DATA_VALUE_PTR(29U, c11_inV);
          _SFD_SET_DATA_VALUE_PTR(30U, c11_vChange);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_EP_IdleRandMergMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "JlhR2Cyz8cIGjzYYR8u2ZB";
}

static void sf_opaque_initialize_c11_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_Demo_EP_IdleRandMerg
    ((SFc11_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
  initialize_c11_Demo_EP_IdleRandMerg((SFc11_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  enable_c11_Demo_EP_IdleRandMerg((SFc11_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  disable_c11_Demo_EP_IdleRandMerg((SFc11_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  sf_gateway_c11_Demo_EP_IdleRandMerg((SFc11_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_Demo_EP_IdleRandMerg
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_Demo_EP_IdleRandMerg
    ((SFc11_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_Demo_EP_IdleRandMerg();/* state var info */
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

extern void sf_internal_set_sim_state_c11_Demo_EP_IdleRandMerg(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_Demo_EP_IdleRandMerg();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_Demo_EP_IdleRandMerg
    ((SFc11_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_Demo_EP_IdleRandMerg(SimStruct*
  S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c11_Demo_EP_IdleRandMerg(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c11_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_EP_IdleRandMerg_optimization_info();
    }

    finalize_c11_Demo_EP_IdleRandMerg((SFc11_Demo_EP_IdleRandMergInstanceStruct*)
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
  initSimStructsc11_Demo_EP_IdleRandMerg
    ((SFc11_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Demo_EP_IdleRandMerg(SimStruct *S)
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
    initialize_params_c11_Demo_EP_IdleRandMerg
      ((SFc11_Demo_EP_IdleRandMergInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_EP_IdleRandMerg_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3680866130U));
  ssSetChecksum1(S,(2100659291U));
  ssSetChecksum2(S,(3203697754U));
  ssSetChecksum3(S,(3635479284U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_Demo_EP_IdleRandMerg(SimStruct *S)
{
  SFc11_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_Demo_EP_IdleRandMergInstanceStruct *)utMalloc(sizeof
    (SFc11_Demo_EP_IdleRandMergInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_Demo_EP_IdleRandMergInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Demo_EP_IdleRandMerg;
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

void c11_Demo_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Demo_EP_IdleRandMerg(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Demo_EP_IdleRandMerg_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}