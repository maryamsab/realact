/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EP_IdleRand_K_sfun.h"
#include "c11_EP_IdleRand_K.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EP_IdleRand_K_sfun_debug_macros.h"
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
#define c11_IN_check_i                 ((uint8_T)1U)
#define c11_IN_initial                 ((uint8_T)2U)
#define c11_IN_loop                    ((uint8_T)3U)
#define c11_IN_stateFacialExpression   ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c11_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_c_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c11_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_f_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c11_g_debug_family_names[5] = { "nargin", "nargout", "E",
  "AU", "L" };

static const char * c11_h_debug_family_names[7] = { "AU", "pFactor", "nargin",
  "nargout", "E", "Pt", "eAmountFactor" };

static const char * c11_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_o_debug_family_names[4] = { "nargin", "nargout", "x",
  "num" };

static const char * c11_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c11_q_debug_family_names[15] = { "AU", "eA", "c1", "c2",
  "str1", "temp", "temp2", "str2", "mystr", "nargin", "nargout", "i", "arrAU",
  "eAmount", "arrBML" };

static const char * c11_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

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

static const char * c11_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c11_dataWrittenToVector[18];

/* Function Declarations */
static void initialize_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void initialize_params_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void enable_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void disable_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void set_sim_state_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_st);
static void c11_set_sim_state_side_effects_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void finalize_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void sf_gateway_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_enter_atomic_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_enter_internal_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_exit_internal_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_initc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void initSimStructsc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_subSmile(SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_enter_atomic_gazeCamera(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_enter_atomic_checkP(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_subFacial(SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_enter_atomic_stateFacialExpression
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_encStr2Arr(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_myarr256[256]);
static void c11_b_encStr2Arr(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_myarr256[256]);
static void c11_fprintf(SFc11_EP_IdleRand_KInstanceStruct *chartInstance, real_T
  c11_formatSpec);
static void c11_isequal(SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static real_T c11_b_fprintf(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_varargin_1);
static void c11_cmdBML_AU(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_i, real_T c11_arrAU[6], real_T c11_eAmount[6], real_T c11_arrBML
  [256]);
static real_T c11_countDigits(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_x);
static void c11_eml_scalar_eg(SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_c_encStr2Arr(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  char_T c11_mystr_data[], int32_T c11_mystr_sizes[2], real_T c11_myarr256[256]);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static real_T c11_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_feval, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_strcat, const char_T *c11_identifier,
  char_T c11_y_data[], int32_T c11_y_sizes[2]);
static void c11_d_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2]);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_e_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_newBmls, const char_T *c11_identifier,
  real_T c11_y[1280]);
static void c11_f_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1280]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_g_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_myBML, const char_T *c11_identifier, real_T
  c11_y[256]);
static void c11_h_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_i_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_myarr256, const char_T *c11_identifier,
  real_T c11_y[256]);
static void c11_j_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_k_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
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
static void c11_l_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_AU, const char_T *c11_identifier, real_T
  c11_y[6]);
static void c11_m_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6]);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, char_T
  c11_inData_data[], int32_T c11_inData_sizes[2]);
static void c11_n_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2]);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, char_T c11_outData_data[],
  int32_T c11_outData_sizes[2]);
static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, real_T
  c11_inData_data[], int32_T *c11_inData_sizes);
static void c11_o_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y_data[], int32_T *c11_y_sizes);
static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, real_T c11_outData_data[],
  int32_T *c11_outData_sizes);
static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_b_info_helper(const mxArray **c11_info);
static void c11_activate_secsc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);
static void c11_deactivate_secsc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_increment_counters_secsc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_reset_counters_secsc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance);
static void c11_insertQueuec11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_bmls[1280], real_T c11_myBML[256], real_T
  c11_newBmls[1280]);
static void c11_smileTablec11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256]);
static void c11_facialExprc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256]);
static void c11_setAUc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_E, real_T c11_AU[6], real_T *c11_L);
static void c11_set_eAmountFactorc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance, real_T c11_E, real_T c11_Pt,
   real_T c11_eAmountFactor[6]);
static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int8_T c11_p_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_q_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_r_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_subSmile, const char_T *c11_identifier);
static uint8_T c11_s_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint16_T c11_t_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_b_temporalCounter_i1, const char_T
  *c11_identifier);
static uint16_T c11_u_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static const mxArray *c11_v_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier);
static const mxArray *c11_w_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex);
static void c11_errorIfDataNotWrittenToFcn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex, uint32_T c11_dataNumber);
static real_T c11_get_BML(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_BML(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_BML(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static real_T c11_get_GAZE_WIN(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_GAZE_WIN(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_GAZE_WIN(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_P(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_P(SFc11_EP_IdleRand_KInstanceStruct *chartInstance, uint32_T
                      c11_b, real_T c11_c);
static real_T *c11_access_P(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static real_T c11_get_STATE_BEFORE(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_BEFORE(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_BEFORE(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_GO(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_STATE_GO(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_GO(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_READY(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_READY(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_READY(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_avert(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_avert(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static real_T c11_get_bmlsM(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_bmlsM(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_bmlsM(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static real_T c11_get_changeFlag(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_changeFlag(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_changeFlag(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_gazing(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_gazing(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_gazing(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b);
static void init_dsm_address_info(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_debugger_state_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_EP_IdleRand_K == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_active_subSmile == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_stateCheckSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subSmile == c11_IN_checkP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_active_subFacial == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_initial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_stateFacialExpression) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_check_i) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_subFacial == c11_IN_loop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  int32_T c11_i0;
  real_T c11_b_u[256];
  const mxArray *c11_c_y = NULL;
  int32_T c11_i1;
  real_T c11_c_u[6];
  const mxArray *c11_d_y = NULL;
  real_T c11_b_hoistedGlobal;
  real_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  int32_T c11_i2;
  real_T c11_f_u[6];
  const mxArray *c11_g_y = NULL;
  real_T c11_d_hoistedGlobal;
  real_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  int32_T c11_i3;
  real_T c11_h_u[256];
  const mxArray *c11_i_y = NULL;
  int32_T c11_i4;
  real_T c11_i_u[1280];
  const mxArray *c11_j_y = NULL;
  real_T c11_e_hoistedGlobal;
  real_T c11_j_u;
  const mxArray *c11_k_y = NULL;
  uint8_T c11_f_hoistedGlobal;
  uint8_T c11_k_u;
  const mxArray *c11_l_y = NULL;
  uint8_T c11_g_hoistedGlobal;
  uint8_T c11_l_u;
  const mxArray *c11_m_y = NULL;
  uint8_T c11_h_hoistedGlobal;
  uint8_T c11_m_u;
  const mxArray *c11_n_y = NULL;
  uint8_T c11_i_hoistedGlobal;
  uint8_T c11_n_u;
  const mxArray *c11_o_y = NULL;
  uint8_T c11_j_hoistedGlobal;
  uint8_T c11_o_u;
  const mxArray *c11_p_y = NULL;
  uint8_T c11_k_hoistedGlobal;
  uint8_T c11_p_u;
  const mxArray *c11_q_y = NULL;
  uint16_T c11_l_hoistedGlobal;
  uint16_T c11_q_u;
  const mxArray *c11_r_y = NULL;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(17, 1), false);
  c11_hoistedGlobal = *c11_gameState;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  for (c11_i0 = 0; c11_i0 < 256; c11_i0++) {
    c11_b_u[c11_i0] = chartInstance->c11_BMLM[c11_i0];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  for (c11_i1 = 0; c11_i1 < 6; c11_i1++) {
    c11_c_u[c11_i1] = chartInstance->c11_au[c11_i1];
  }

  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 1, 6),
                false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_b_hoistedGlobal = chartInstance->c11_au_L;
  c11_d_u = c11_b_hoistedGlobal;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_c_hoistedGlobal = chartInstance->c11_au_i;
  c11_e_u = c11_c_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  for (c11_i2 = 0; c11_i2 < 6; c11_i2++) {
    c11_f_u[c11_i2] = chartInstance->c11_eAmountF[c11_i2];
  }

  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_f_u, 0, 0U, 1U, 0U, 2, 1, 6),
                false);
  sf_mex_setcell(c11_y, 5, c11_g_y);
  c11_d_hoistedGlobal = chartInstance->c11_fileID;
  c11_g_u = c11_d_hoistedGlobal;
  c11_h_y = NULL;
  sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 6, c11_h_y);
  for (c11_i3 = 0; c11_i3 < 256; c11_i3++) {
    c11_h_u[c11_i3] = chartInstance->c11_n[c11_i3];
  }

  c11_i_y = NULL;
  sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_h_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c11_y, 7, c11_i_y);
  for (c11_i4 = 0; c11_i4 < 1280; c11_i4++) {
    c11_i_u[c11_i4] = chartInstance->c11_newBmlsM[c11_i4];
  }

  c11_j_y = NULL;
  sf_mex_assign(&c11_j_y, sf_mex_create("y", c11_i_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c11_y, 8, c11_j_y);
  c11_e_hoistedGlobal = chartInstance->c11_smileN;
  c11_j_u = c11_e_hoistedGlobal;
  c11_k_y = NULL;
  sf_mex_assign(&c11_k_y, sf_mex_create("y", &c11_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 9, c11_k_y);
  c11_f_hoistedGlobal = chartInstance->c11_is_active_c11_EP_IdleRand_K;
  c11_k_u = c11_f_hoistedGlobal;
  c11_l_y = NULL;
  sf_mex_assign(&c11_l_y, sf_mex_create("y", &c11_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 10, c11_l_y);
  c11_g_hoistedGlobal = chartInstance->c11_is_active_subSmile;
  c11_l_u = c11_g_hoistedGlobal;
  c11_m_y = NULL;
  sf_mex_assign(&c11_m_y, sf_mex_create("y", &c11_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 11, c11_m_y);
  c11_h_hoistedGlobal = chartInstance->c11_is_active_subFacial;
  c11_m_u = c11_h_hoistedGlobal;
  c11_n_y = NULL;
  sf_mex_assign(&c11_n_y, sf_mex_create("y", &c11_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 12, c11_n_y);
  c11_i_hoistedGlobal = chartInstance->c11_is_subSmile;
  c11_n_u = c11_i_hoistedGlobal;
  c11_o_y = NULL;
  sf_mex_assign(&c11_o_y, sf_mex_create("y", &c11_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 13, c11_o_y);
  c11_j_hoistedGlobal = chartInstance->c11_is_subFacial;
  c11_o_u = c11_j_hoistedGlobal;
  c11_p_y = NULL;
  sf_mex_assign(&c11_p_y, sf_mex_create("y", &c11_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 14, c11_p_y);
  c11_k_hoistedGlobal = chartInstance->c11_temporalCounter_i2;
  c11_p_u = c11_k_hoistedGlobal;
  c11_q_y = NULL;
  sf_mex_assign(&c11_q_y, sf_mex_create("y", &c11_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 15, c11_q_y);
  c11_l_hoistedGlobal = chartInstance->c11_temporalCounter_i1;
  c11_q_u = c11_l_hoistedGlobal;
  c11_r_y = NULL;
  sf_mex_assign(&c11_r_y, sf_mex_create("y", &c11_q_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 16, c11_r_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[256];
  int32_T c11_i5;
  real_T c11_dv1[6];
  int32_T c11_i6;
  real_T c11_dv2[6];
  int32_T c11_i7;
  real_T c11_dv3[256];
  int32_T c11_i8;
  real_T c11_dv4[1280];
  int32_T c11_i9;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_u = sf_mex_dup(c11_st);
  *c11_gameState = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 0)), "gameState");
  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "BMLM", c11_dv0);
  for (c11_i5 = 0; c11_i5 < 256; c11_i5++) {
    chartInstance->c11_BMLM[c11_i5] = c11_dv0[c11_i5];
  }

  c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
    "au", c11_dv1);
  for (c11_i6 = 0; c11_i6 < 6; c11_i6++) {
    chartInstance->c11_au[c11_i6] = c11_dv1[c11_i6];
  }

  chartInstance->c11_au_L = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 3)), "au_L");
  chartInstance->c11_au_i = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 4)), "au_i");
  c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 5)),
    "eAmountF", c11_dv2);
  for (c11_i7 = 0; c11_i7 < 6; c11_i7++) {
    chartInstance->c11_eAmountF[c11_i7] = c11_dv2[c11_i7];
  }

  chartInstance->c11_fileID = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 6)), "fileID");
  c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 7)),
    "n", c11_dv3);
  for (c11_i8 = 0; c11_i8 < 256; c11_i8++) {
    chartInstance->c11_n[c11_i8] = c11_dv3[c11_i8];
  }

  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 8)),
    "newBmlsM", c11_dv4);
  for (c11_i9 = 0; c11_i9 < 1280; c11_i9++) {
    chartInstance->c11_newBmlsM[c11_i9] = c11_dv4[c11_i9];
  }

  chartInstance->c11_smileN = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 9)), "smileN");
  chartInstance->c11_is_active_c11_EP_IdleRand_K = c11_r_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 10)),
     "is_active_c11_EP_IdleRand_K");
  chartInstance->c11_is_active_subSmile = c11_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 11)), "is_active_subSmile");
  chartInstance->c11_is_active_subFacial = c11_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 12)), "is_active_subFacial");
  chartInstance->c11_is_subSmile = c11_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 13)), "is_subSmile");
  chartInstance->c11_is_subFacial = c11_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 14)), "is_subFacial");
  chartInstance->c11_temporalCounter_i2 = c11_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 15)), "temporalCounter_i2");
  chartInstance->c11_temporalCounter_i1 = c11_t_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 16)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 17)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_EP_IdleRand_K(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
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

    if (chartInstance->c11_is_subFacial == c11_IN_check_i) {
      chartInstance->c11_tp_check_i = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c11_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c11_tp_check_i = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_IN_initial) {
      chartInstance->c11_tp_initial = 1U;
    } else {
      chartInstance->c11_tp_initial = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_IN_loop) {
      chartInstance->c11_tp_loop = 1U;
    } else {
      chartInstance->c11_tp_loop = 0U;
    }

    if (chartInstance->c11_is_subFacial == c11_IN_stateFacialExpression) {
      chartInstance->c11_tp_stateFacialExpression = 1U;
    } else {
      chartInstance->c11_tp_stateFacialExpression = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  c11_set_sim_state_side_effects_c11_EP_IdleRand_K(chartInstance);
}

static void c11_enter_atomic_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_EP_IdleRand_K = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  uint32_T c11_b_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr;
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr;
  real_T c11_b_nargin = 1.0;
  real_T c11_b_nargout = 1.0;
  real_T c11_myarr256[256];
  int32_T c11_i10;
  int32_T c11_i11;
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
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 0.0;
  int32_T c11_i25;
  static real_T c11_dv5[6] = { 6.0, 12.0, 142.0, 0.0, 0.0, 0.0 };

  int32_T c11_i26;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_active_subSmile = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_subSmile = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_subSmile = c11_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_stateInitial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_i_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  *c11_gameState = c11_get_STATE_READY(chartInstance, 0);
  c11_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_gameState, 8U);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_b_debug_family_names,
    c11_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_arr, 1U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_mystr, 5U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  c11_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 255.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i10 = 0; c11_i10 < 256; c11_i10++) {
    c11_tt[c11_i10] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_tt[0] = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i11 = 0; c11_i11 < 256; c11_i11++) {
    c11_myarr256[c11_i11] = c11_tt[c11_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i12 = 0; c11_i12 < 256; c11_i12++) {
    chartInstance->c11_n[c11_i12] = c11_myarr256[c11_i12];
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  for (c11_i13 = 0; c11_i13 < 256; c11_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_n[c11_i13], 16U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 5U, 16U);
  for (c11_i14 = 0; c11_i14 < 256; c11_i14++) {
    c11_set_bmlsM(chartInstance, c11_i14, chartInstance->c11_n[c11_i14]);
  }

  for (c11_i15 = 0; c11_i15 < 256; c11_i15++) {
    c11_set_bmlsM(chartInstance, c11_i15 + 256, chartInstance->c11_n[c11_i15]);
  }

  for (c11_i16 = 0; c11_i16 < 256; c11_i16++) {
    c11_set_bmlsM(chartInstance, c11_i16 + 512, chartInstance->c11_n[c11_i16]);
  }

  for (c11_i17 = 0; c11_i17 < 256; c11_i17++) {
    c11_set_bmlsM(chartInstance, c11_i17 + 768, chartInstance->c11_n[c11_i17]);
  }

  for (c11_i18 = 0; c11_i18 < 256; c11_i18++) {
    c11_set_bmlsM(chartInstance, c11_i18 + 1024, chartInstance->c11_n[c11_i18]);
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 5U, 16U);
  for (c11_i19 = 0; c11_i19 < 256; c11_i19++) {
    chartInstance->c11_newBmlsM[c11_i19] = chartInstance->c11_n[c11_i19];
  }

  for (c11_i20 = 0; c11_i20 < 256; c11_i20++) {
    chartInstance->c11_newBmlsM[c11_i20 + 256] = chartInstance->c11_n[c11_i20];
  }

  for (c11_i21 = 0; c11_i21 < 256; c11_i21++) {
    chartInstance->c11_newBmlsM[c11_i21 + 512] = chartInstance->c11_n[c11_i21];
  }

  for (c11_i22 = 0; c11_i22 < 256; c11_i22++) {
    chartInstance->c11_newBmlsM[c11_i22 + 768] = chartInstance->c11_n[c11_i22];
  }

  for (c11_i23 = 0; c11_i23 < 256; c11_i23++) {
    chartInstance->c11_newBmlsM[c11_i23 + 1024] = chartInstance->c11_n[c11_i23];
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 3U);
  for (c11_i24 = 0; c11_i24 < 1280; c11_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i24], 13U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_active_subFacial = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_subFacial = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_subFacial = c11_IN_initial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_initial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_l_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  for (c11_i25 = 0; c11_i25 < 6; c11_i25++) {
    chartInstance->c11_au[c11_i25] = c11_dv5[c11_i25];
  }

  c11_updateDataWrittenToVector(chartInstance, 6U);
  for (c11_i26 = 0; c11_i26 < 6; c11_i26++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_au[c11_i26], 19U);
  }

  chartInstance->c11_au_L = 3.0;
  c11_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_L, 23U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_isStable = true;
  c11_subSmile(chartInstance);
  c11_subFacial(chartInstance);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  switch (chartInstance->c11_is_subFacial) {
   case c11_IN_check_i:
    CV_STATE_EVAL(5, 1, 1);
    chartInstance->c11_tp_check_i = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_initial:
    CV_STATE_EVAL(5, 1, 2);
    chartInstance->c11_tp_initial = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_loop:
    CV_STATE_EVAL(5, 1, 3);
    chartInstance->c11_tp_loop = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateFacialExpression:
    CV_STATE_EVAL(5, 1, 4);
    chartInstance->c11_tp_stateFacialExpression = 0U;
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 1, 0);
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    break;
  }

  chartInstance->c11_tp_subFacial = 0U;
  chartInstance->c11_is_active_subFacial = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  switch (chartInstance->c11_is_subSmile) {
   case c11_IN_checkP:
    CV_STATE_EVAL(10, 1, 1);
    chartInstance->c11_tp_checkP = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_STATE_EVAL(10, 1, 2);
    chartInstance->c11_tp_gazeCamera = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateCheckSmile:
    CV_STATE_EVAL(10, 1, 3);
    chartInstance->c11_tp_stateCheckSmile = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_STATE_EVAL(10, 1, 4);
    chartInstance->c11_tp_stateInitial = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_STATE_EVAL(10, 1, 5);
    chartInstance->c11_tp_wait = 0U;
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(10, 1, 0);
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
    break;
  }

  chartInstance->c11_tp_subSmile = 0U;
  chartInstance->c11_is_active_subSmile = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
}

static void c11_initc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_is_active_subFacial = 0U;
  chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
  chartInstance->c11_tp_subFacial = 0U;
  chartInstance->c11_tp_check_i = 0U;
  chartInstance->c11_temporalCounter_i2 = 0U;
  chartInstance->c11_tp_initial = 0U;
  chartInstance->c11_tp_loop = 0U;
  chartInstance->c11_tp_stateFacialExpression = 0U;
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
  chartInstance->c11_is_active_c11_EP_IdleRand_K = 0U;
}

static void initSimStructsc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_subSmile(SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
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
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  switch (chartInstance->c11_is_subSmile) {
   case c11_IN_checkP:
    CV_STATE_EVAL(10, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_checkP = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_subSmile = c11_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
    chartInstance->c11_temporalCounter_i1 = 0U;
    chartInstance->c11_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_STATE_EVAL(10, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_v_debug_family_names,
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
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_checkP;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
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
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateCheckSmile = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                     chartInstance->c11_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateCheckSmile:
    CV_STATE_EVAL(10, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_u_debug_family_names,
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
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_gazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
      chartInstance->c11_temporalCounter_i1 = 0U;
      chartInstance->c11_tp_gazeCamera = 1U;
      c11_enter_atomic_gazeCamera(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_STATE_EVAL(10, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_r_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
    c11_d_out = CV_EML_IF(1, 0, 0, *c11_gameState == 10.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateInitial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_STATE_EVAL(10, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_s_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_e_out = CV_EML_IF(5, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs)
                          && (chartInstance->c11_temporalCounter_i1 >= 300));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subSmile = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(10, 0, 0);
    chartInstance->c11_is_subSmile = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
}

static void c11_enter_atomic_gazeCamera(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_b_BMLM[256];
  real_T c11_P;
  int32_T c11_i27;
  real_T c11_c_BMLM[256];
  int32_T c11_i28;
  int32_T c11_i29;
  int32_T c11_i30;
  real_T c11_dv6[1280];
  int32_T c11_i31;
  real_T c11_dv7[256];
  real_T c11_dv8[1280];
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_j_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_smileTablec11_EP_IdleRand_K(chartInstance, 2.0, &c11_P, c11_b_BMLM);
  for (c11_i27 = 0; c11_i27 < 256; c11_i27++) {
    c11_c_BMLM[c11_i27] = c11_b_BMLM[c11_i27];
  }

  c11_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c11_i28 = 0; c11_i28 < 256; c11_i28++) {
    chartInstance->c11_BMLM[c11_i28] = c11_c_BMLM[c11_i28];
  }

  c11_updateDataWrittenToVector(chartInstance, 4U);
  for (c11_i29 = 0; c11_i29 < 256; c11_i29++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i29], 15U);
  }

  c11_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 15U);
  for (c11_i30 = 0; c11_i30 < 1280; c11_i30++) {
    c11_dv6[c11_i30] = c11_get_bmlsM(chartInstance, c11_i30);
  }

  for (c11_i31 = 0; c11_i31 < 256; c11_i31++) {
    c11_dv7[c11_i31] = chartInstance->c11_BMLM[c11_i31];
  }

  c11_insertQueuec11_EP_IdleRand_K(chartInstance, c11_dv6, c11_dv7, c11_dv8);
  for (c11_i32 = 0; c11_i32 < 1280; c11_i32++) {
    chartInstance->c11_newBmlsM[c11_i32] = c11_dv8[c11_i32];
  }

  c11_updateDataWrittenToVector(chartInstance, 3U);
  for (c11_i33 = 0; c11_i33 < 1280; c11_i33++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i33], 13U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 13U);
  for (c11_i34 = 0; c11_i34 < 1280; c11_i34++) {
    c11_set_bmlsM(chartInstance, c11_i34, chartInstance->c11_newBmlsM[c11_i34]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_enter_atomic_checkP(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_b_BMLM[256];
  real_T c11_P;
  int32_T c11_i35;
  real_T c11_c_BMLM[256];
  int32_T c11_i36;
  int32_T c11_i37;
  int32_T c11_i38;
  real_T c11_dv9[1280];
  int32_T c11_i39;
  real_T c11_dv10[256];
  real_T c11_dv11[1280];
  int32_T c11_i40;
  int32_T c11_i41;
  int32_T c11_i42;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_k_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_smileTablec11_EP_IdleRand_K(chartInstance, 1.0, &c11_P, c11_b_BMLM);
  for (c11_i35 = 0; c11_i35 < 256; c11_i35++) {
    c11_c_BMLM[c11_i35] = c11_b_BMLM[c11_i35];
  }

  c11_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c11_i36 = 0; c11_i36 < 256; c11_i36++) {
    chartInstance->c11_BMLM[c11_i36] = c11_c_BMLM[c11_i36];
  }

  c11_updateDataWrittenToVector(chartInstance, 4U);
  for (c11_i37 = 0; c11_i37 < 256; c11_i37++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i37], 15U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 15U);
  for (c11_i38 = 0; c11_i38 < 1280; c11_i38++) {
    c11_dv9[c11_i38] = c11_get_bmlsM(chartInstance, c11_i38);
  }

  for (c11_i39 = 0; c11_i39 < 256; c11_i39++) {
    c11_dv10[c11_i39] = chartInstance->c11_BMLM[c11_i39];
  }

  c11_insertQueuec11_EP_IdleRand_K(chartInstance, c11_dv9, c11_dv10, c11_dv11);
  for (c11_i40 = 0; c11_i40 < 1280; c11_i40++) {
    chartInstance->c11_newBmlsM[c11_i40] = c11_dv11[c11_i40];
  }

  c11_updateDataWrittenToVector(chartInstance, 3U);
  for (c11_i41 = 0; c11_i41 < 1280; c11_i41++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i41], 13U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 13U);
  for (c11_i42 = 0; c11_i42 < 1280; c11_i42++) {
    c11_set_bmlsM(chartInstance, c11_i42, chartInstance->c11_newBmlsM[c11_i42]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_subFacial(SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
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
  uint32_T c11_b_debug_family_var_map[2];
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 0.0;
  int32_T c11_i43;
  real_T c11_dv12[6];
  int32_T c11_i44;
  real_T c11_dv13[6];
  real_T c11_dv14[256];
  int32_T c11_i45;
  int32_T c11_i46;
  int32_T c11_i47;
  real_T c11_dv15[1280];
  int32_T c11_i48;
  real_T c11_dv16[256];
  real_T c11_dv17[1280];
  int32_T c11_i49;
  int32_T c11_i50;
  int32_T c11_i51;
  real_T c11_e_nargin = 0.0;
  real_T c11_e_nargout = 1.0;
  boolean_T c11_d_out;
  real_T c11_f_nargin = 0.0;
  real_T c11_f_nargout = 0.0;
  int32_T c11_i52;
  static real_T c11_dv18[6] = { 6.0, 12.0, 142.0, 0.0, 0.0, 0.0 };

  int32_T c11_i53;
  real_T c11_g_nargin = 0.0;
  real_T c11_g_nargout = 1.0;
  boolean_T c11_e_out;
  real_T c11_h_nargin = 0.0;
  real_T c11_h_nargout = 0.0;
  int32_T c11_i54;
  int32_T c11_i55;
  real_T c11_i_nargin = 0.0;
  real_T c11_i_nargout = 0.0;
  int32_T c11_i56;
  real_T c11_dv19[6];
  int32_T c11_i57;
  real_T c11_dv20[6];
  int32_T c11_i58;
  int32_T c11_i59;
  int32_T c11_i60;
  real_T c11_dv21[1280];
  int32_T c11_i61;
  real_T c11_dv22[256];
  real_T c11_dv23[1280];
  int32_T c11_i62;
  int32_T c11_i63;
  int32_T c11_i64;
  real_T *c11_internalE;
  boolean_T guard1 = false;
  c11_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  switch (chartInstance->c11_is_subFacial) {
   case c11_IN_check_i:
    CV_STATE_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_ab_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_errorIfDataNotWrittenToFcn(chartInstance, 8U, 22U);
    c11_errorIfDataNotWrittenToFcn(chartInstance, 9U, 23U);
    c11_out = CV_EML_IF(12, 0, 0, chartInstance->c11_au_i >
                        chartInstance->c11_au_L);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c11_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_y_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_f_sf_marshallOut,
        c11_e_sf_marshallIn);
      c11_b_out = CV_EML_IF(14, 0, 0, (chartInstance->c11_sfEvent ==
        c11_event_secs) && (chartInstance->c11_temporalCounter_i2 >= 10));
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_check_i = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_subFacial = c11_IN_stateFacialExpression;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateFacialExpression = 1U;
        c11_enter_atomic_stateFacialExpression(chartInstance);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_bb_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U, c11_f_sf_marshallOut,
        c11_e_sf_marshallIn);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 8U, 22U);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 9U, 23U);
      c11_c_out = CV_EML_IF(13, 0, 0, chartInstance->c11_au_i <=
                            chartInstance->c11_au_L);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_check_i = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_subFacial = c11_IN_loop;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_loop = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_n_debug_family_names,
          c11_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U,
          c11_c_sf_marshallOut, c11_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
          c11_c_sf_marshallOut, c11_c_sf_marshallIn);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 8U, 22U);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 6U, 19U);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 7U, 20U);
        for (c11_i43 = 0; c11_i43 < 6; c11_i43++) {
          c11_dv12[c11_i43] = chartInstance->c11_au[c11_i43];
        }

        for (c11_i44 = 0; c11_i44 < 6; c11_i44++) {
          c11_dv13[c11_i44] = chartInstance->c11_eAmountF[c11_i44];
        }

        c11_cmdBML_AU(chartInstance, chartInstance->c11_au_i, c11_dv12, c11_dv13,
                      c11_dv14);
        for (c11_i45 = 0; c11_i45 < 256; c11_i45++) {
          chartInstance->c11_BMLM[c11_i45] = c11_dv14[c11_i45];
        }

        c11_updateDataWrittenToVector(chartInstance, 4U);
        for (c11_i46 = 0; c11_i46 < 256; c11_i46++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i46], 15U);
        }

        c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 15U);
        for (c11_i47 = 0; c11_i47 < 1280; c11_i47++) {
          c11_dv15[c11_i47] = c11_get_bmlsM(chartInstance, c11_i47);
        }

        for (c11_i48 = 0; c11_i48 < 256; c11_i48++) {
          c11_dv16[c11_i48] = chartInstance->c11_BMLM[c11_i48];
        }

        c11_insertQueuec11_EP_IdleRand_K(chartInstance, c11_dv15, c11_dv16,
          c11_dv17);
        for (c11_i49 = 0; c11_i49 < 1280; c11_i49++) {
          chartInstance->c11_newBmlsM[c11_i49] = c11_dv17[c11_i49];
        }

        c11_updateDataWrittenToVector(chartInstance, 3U);
        for (c11_i50 = 0; c11_i50 < 1280; c11_i50++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i50], 13U);
        }

        c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 13U);
        for (c11_i51 = 0; c11_i51 < 1280; c11_i51++) {
          c11_set_bmlsM(chartInstance, c11_i51, chartInstance->
                        c11_newBmlsM[c11_i51]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 7);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 8U, 22U);
        chartInstance->c11_au_i++;
        c11_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_i, 22U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c11_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_initial:
    CV_STATE_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_w_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_d_out = CV_EML_IF(8, 0, 0, *c11_internalE != 6.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_initial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 1U;
      c11_enter_atomic_stateFacialExpression(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_initial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_initial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_initial = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_l_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargin, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargout, 1U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      for (c11_i52 = 0; c11_i52 < 6; c11_i52++) {
        chartInstance->c11_au[c11_i52] = c11_dv18[c11_i52];
      }

      c11_updateDataWrittenToVector(chartInstance, 6U);
      for (c11_i53 = 0; c11_i53 < 6; c11_i53++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c11_au[c11_i53], 19U);
      }

      chartInstance->c11_au_L = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_L, 23U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_loop:
    CV_STATE_EVAL(5, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_loop = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_subFacial = c11_IN_check_i;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    chartInstance->c11_temporalCounter_i2 = 0U;
    chartInstance->c11_tp_check_i = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateFacialExpression:
    CV_STATE_EVAL(5, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_x_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_g_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_g_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_e_out = CV_EML_IF(16, 0, 0, *c11_internalE == 6.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_initial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_initial = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_l_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_h_nargin, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_h_nargout, 1U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      for (c11_i54 = 0; c11_i54 < 6; c11_i54++) {
        chartInstance->c11_au[c11_i54] = c11_dv18[c11_i54];
      }

      c11_updateDataWrittenToVector(chartInstance, 6U);
      for (c11_i55 = 0; c11_i55 < 6; c11_i55++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c11_au[c11_i55], 19U);
      }

      chartInstance->c11_au_L = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_L, 23U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateFacialExpression = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_subFacial = c11_IN_loop;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_loop = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_n_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i_nargin, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i_nargout, 1U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 8U, 22U);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 6U, 19U);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 7U, 20U);
      for (c11_i56 = 0; c11_i56 < 6; c11_i56++) {
        c11_dv19[c11_i56] = chartInstance->c11_au[c11_i56];
      }

      for (c11_i57 = 0; c11_i57 < 6; c11_i57++) {
        c11_dv20[c11_i57] = chartInstance->c11_eAmountF[c11_i57];
      }

      c11_cmdBML_AU(chartInstance, chartInstance->c11_au_i, c11_dv19, c11_dv20,
                    c11_dv14);
      for (c11_i58 = 0; c11_i58 < 256; c11_i58++) {
        chartInstance->c11_BMLM[c11_i58] = c11_dv14[c11_i58];
      }

      c11_updateDataWrittenToVector(chartInstance, 4U);
      for (c11_i59 = 0; c11_i59 < 256; c11_i59++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i59], 15U);
      }

      c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 15U);
      for (c11_i60 = 0; c11_i60 < 1280; c11_i60++) {
        c11_dv21[c11_i60] = c11_get_bmlsM(chartInstance, c11_i60);
      }

      for (c11_i61 = 0; c11_i61 < 256; c11_i61++) {
        c11_dv22[c11_i61] = chartInstance->c11_BMLM[c11_i61];
      }

      c11_insertQueuec11_EP_IdleRand_K(chartInstance, c11_dv21, c11_dv22,
        c11_dv23);
      for (c11_i62 = 0; c11_i62 < 1280; c11_i62++) {
        chartInstance->c11_newBmlsM[c11_i62] = c11_dv23[c11_i62];
      }

      c11_updateDataWrittenToVector(chartInstance, 3U);
      for (c11_i63 = 0; c11_i63 < 1280; c11_i63++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i63], 13U);
      }

      c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 13U);
      for (c11_i64 = 0; c11_i64 < 1280; c11_i64++) {
        c11_set_bmlsM(chartInstance, c11_i64, chartInstance->
                      c11_newBmlsM[c11_i64]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 7);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 8U, 22U);
      chartInstance->c11_au_i++;
      c11_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_i, 22U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 0, 0);
    chartInstance->c11_is_subFacial = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
}

static void c11_enter_atomic_stateFacialExpression
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_b_au_L;
  real_T c11_dv24[6];
  int32_T c11_i65;
  int32_T c11_i66;
  real_T c11_dv25[6];
  int32_T c11_i67;
  int32_T c11_i68;
  int32_T c11_i69;
  static char_T c11_cv0[4] = { 'n', 'e', 'x', 't' };

  char_T c11_u[4];
  const mxArray *c11_y = NULL;
  real_T *c11_internalE;
  real_T *c11_personality;
  c11_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_m_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_setAUc11_EP_IdleRand_K(chartInstance, *c11_internalE, c11_dv24,
    &c11_b_au_L);
  for (c11_i65 = 0; c11_i65 < 6; c11_i65++) {
    chartInstance->c11_au[c11_i65] = c11_dv24[c11_i65];
  }

  c11_updateDataWrittenToVector(chartInstance, 6U);
  for (c11_i66 = 0; c11_i66 < 6; c11_i66++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_au[c11_i66], 19U);
  }

  chartInstance->c11_au_L = c11_b_au_L;
  c11_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_L, 23U);
  c11_set_eAmountFactorc11_EP_IdleRand_K(chartInstance, *c11_internalE,
    *c11_personality, c11_dv25);
  for (c11_i67 = 0; c11_i67 < 6; c11_i67++) {
    chartInstance->c11_eAmountF[c11_i67] = c11_dv25[c11_i67];
  }

  c11_updateDataWrittenToVector(chartInstance, 7U);
  for (c11_i68 = 0; c11_i68 < 6; c11_i68++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_eAmountF[c11_i68], 20U);
  }

  chartInstance->c11_au_i = 1.0;
  c11_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c11_au_i, 22U);
  for (c11_i69 = 0; c11_i69 < 4; c11_i69++) {
    c11_u[c11_i69] = c11_cv0[c11_i69];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c11_y);
  c11_fprintf(chartInstance, *c11_internalE);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_encStr2Arr(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[230];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[230];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i70;
  static char_T c11_cv1[230] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c11_i71;
  static real_T c11_dv26[230] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c11_i72;
  int32_T c11_i73;
  int32_T c11_i74;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_d_debug_family_names,
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
  for (c11_i70 = 0; c11_i70 < 230; c11_i70++) {
    c11_mystr[c11_i70] = c11_cv1[c11_i70];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i71 = 0; c11_i71 < 230; c11_i71++) {
    c11_arr[c11_i71] = c11_dv26[c11_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 230.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 26.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i72 = 0; c11_i72 < 256; c11_i72++) {
    c11_tt[c11_i72] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i73 = 0; c11_i73 < 230; c11_i73++) {
    c11_tt[c11_i73] = c11_arr[c11_i73];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i74 = 0; c11_i74 < 256; c11_i74++) {
    c11_myarr256[c11_i74] = c11_tt[c11_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_b_encStr2Arr(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[109];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[109];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i75;
  static char_T c11_cv2[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g',
    'e', 't', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '5', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e',
    '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i76;
  static real_T c11_dv27[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0,
    34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i77;
  int32_T c11_i78;
  int32_T c11_i79;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_e_debug_family_names,
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
  for (c11_i75 = 0; c11_i75 < 109; c11_i75++) {
    c11_mystr[c11_i75] = c11_cv2[c11_i75];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i76 = 0; c11_i76 < 109; c11_i76++) {
    c11_arr[c11_i76] = c11_dv27[c11_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i77 = 0; c11_i77 < 256; c11_i77++) {
    c11_tt[c11_i77] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i78 = 0; c11_i78 < 109; c11_i78++) {
    c11_tt[c11_i78] = c11_arr[c11_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i79 = 0; c11_i79 < 256; c11_i79++) {
    c11_myarr256[c11_i79] = c11_tt[c11_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_fprintf(SFc11_EP_IdleRand_KInstanceStruct *chartInstance, real_T
  c11_formatSpec)
{
  c11_isequal(chartInstance);
  c11_b_fprintf(chartInstance, c11_formatSpec);
}

static void c11_isequal(SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c11_b_fprintf(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_varargin_1)
{
  real_T c11_nbytes;
  int32_T c11_i80;
  static char_T c11_cv3[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c11_u[7];
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  int32_T c11_i81;
  static char_T c11_formatSpec[5] = { '%', '1', '.', '1', 'f' };

  char_T c11_c_u[5];
  const mxArray *c11_c_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_d_y = NULL;
  const mxArray *c11_cfmt = NULL;
  const mxArray *c11_convs = NULL;
  c11_isequal(chartInstance);
  for (c11_i80 = 0; c11_i80 < 7; c11_i80++) {
    c11_u[c11_i80] = c11_cv3[c11_i80];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c11_b_u = 1.0;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c11_i81 = 0; c11_i81 < 5; c11_i81++) {
    c11_c_u[c11_i81] = c11_formatSpec[c11_i81];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c11_d_u = c11_varargin_1;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0), false);
  c11_nbytes = c11_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14, c11_y, 14, c11_b_y, 14,
     c11_c_y, 14, c11_d_y), "feval");
  sf_mex_destroy(&c11_cfmt);
  sf_mex_destroy(&c11_convs);
  return c11_nbytes;
}

static void c11_cmdBML_AU(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_i, real_T c11_arrAU[6], real_T c11_eAmount[6], real_T c11_arrBML
  [256])
{
  uint32_T c11_debug_family_var_map[15];
  real_T c11_AU;
  real_T c11_eA;
  real_T c11_c1;
  real_T c11_c2;
  const mxArray *c11_str1 = NULL;
  const mxArray *c11_temp = NULL;
  const mxArray *c11_temp2 = NULL;
  const mxArray *c11_str2 = NULL;
  int32_T c11_mystr_sizes[2];
  char_T c11_mystr_data[148];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i82;
  static char_T c11_cv4[34] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>' };

  char_T c11_u[34];
  const mxArray *c11_y = NULL;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_b_y;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_varargin_1;
  real_T c11_varargin_2;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_xk;
  real_T c11_i_x;
  real_T c11_maxval;
  int32_T c11_i83;
  static char_T c11_cv5[64] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e',
    '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=', '\\',
    '\"', '%', '1', 'd', '\\', '\"', ' ', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=',
    '\\', '\"', '%', '0', '.', '1', 'f', '\\', '\"', '/', '>' };

  char_T c11_b_u[64];
  const mxArray *c11_c_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  int32_T c11_i84;
  static char_T c11_cv6[63] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e',
    '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=', '\\',
    '\"', '%', '2', 'd', '\\', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=',
    '\\', '\"', '%', '0', '.', '1', 'f', '\\', '\"', '/', '>' };

  char_T c11_e_u[63];
  const mxArray *c11_f_y = NULL;
  real_T c11_f_u;
  const mxArray *c11_g_y = NULL;
  real_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  int32_T c11_i85;
  static char_T c11_cv7[12] = { '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  char_T c11_h_u[12];
  const mxArray *c11_i_y = NULL;
  real_T c11_b_n;
  real_T c11_dv28[2];
  int32_T c11_iv0[2];
  int32_T c11_mystr;
  int32_T c11_b_mystr;
  int32_T c11_loop_ub;
  int32_T c11_i86;
  int32_T c11_tmp_sizes[2];
  char_T c11_tmp_data[148];
  int32_T c11_c_mystr;
  int32_T c11_d_mystr;
  int32_T c11_b_loop_ub;
  int32_T c11_i87;
  int32_T c11_b_mystr_sizes[2];
  int32_T c11_e_mystr;
  int32_T c11_f_mystr;
  int32_T c11_c_loop_ub;
  int32_T c11_i88;
  char_T c11_b_mystr_data[148];
  real_T c11_dv29[256];
  int32_T c11_i89;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c11_q_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_AU, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_eA, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c1, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c2, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_str1, 4U, c11_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_temp, 5U, c11_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_temp2, 6U, c11_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_str2, 7U, c11_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c11_mystr_data, (const int32_T *)
    &c11_mystr_sizes, NULL, 0, 8, (void *)c11_l_sf_marshallOut, (void *)
    c11_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 9U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 10U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i, 11U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_arrAU, 12U, c11_k_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_eAmount, 13U, c11_k_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_arrBML, 14U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 10);
  c11_AU = c11_arrAU[_SFD_EML_ARRAY_BOUNDS_CHECK("arrAU", (int32_T)
    _SFD_INTEGER_CHECK("i", c11_i), 1, 6, 1, 0) - 1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 10);
  c11_eA = c11_eAmount[(int32_T)c11_i - 1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 11);
  c11_c1 = c11_countDigits(chartInstance, c11_AU);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 11);
  c11_c2 = c11_countDigits(chartInstance, c11_eA);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 13);
  for (c11_i82 = 0; c11_i82 < 34; c11_i82++) {
    c11_u[c11_i82] = c11_cv4[c11_i82];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  sf_mex_assign(&c11_str1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c11_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 15);
  c11_x = c11_AU;
  c11_b_x = c11_x;
  c11_b_y = muDoubleScalarAbs(c11_b_x);
  c11_c_x = c11_b_y;
  c11_d_x = c11_c_x;
  c11_d_x = muDoubleScalarLog10(c11_d_x);
  c11_e_x = c11_d_x;
  c11_f_x = c11_e_x;
  c11_f_x = muDoubleScalarCeil(c11_f_x);
  c11_varargin_1 = c11_f_x;
  c11_varargin_2 = c11_varargin_1;
  c11_g_x = c11_varargin_2;
  c11_h_x = c11_g_x;
  c11_eml_scalar_eg(chartInstance);
  c11_xk = c11_h_x;
  c11_i_x = c11_xk;
  c11_eml_scalar_eg(chartInstance);
  c11_maxval = muDoubleScalarMax(c11_i_x, 1.0);
  if (CV_SCRIPT_IF(1, 0, c11_maxval == 1.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 17);
    for (c11_i83 = 0; c11_i83 < 64; c11_i83++) {
      c11_b_u[c11_i83] = c11_cv5[c11_i83];
    }

    c11_c_y = NULL;
    sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1, 64),
                  false);
    c11_c_u = c11_AU;
    c11_d_y = NULL;
    sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0),
                  false);
    c11_d_u = c11_eA;
    c11_e_y = NULL;
    sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_assign(&c11_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "sprintf", 1U, 3U, 14, c11_c_y, 14, c11_d_y, 14, c11_e_y), false);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 18);
    sf_mex_assign(&c11_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "strcat", 1U, 2U, 14, sf_mex_dup(c11_str1), 14, sf_mex_dup(c11_temp)),
                  false);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 19);
    sf_mex_assign(&c11_str1, sf_mex_dup(c11_temp2), false);
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 22);
    for (c11_i84 = 0; c11_i84 < 63; c11_i84++) {
      c11_e_u[c11_i84] = c11_cv6[c11_i84];
    }

    c11_f_y = NULL;
    sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_e_u, 10, 0U, 1U, 0U, 2, 1, 63),
                  false);
    c11_f_u = c11_AU;
    c11_g_y = NULL;
    sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_f_u, 0, 0U, 0U, 0U, 0),
                  false);
    c11_g_u = c11_eA;
    c11_h_y = NULL;
    sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 0, 0U, 0U, 0U, 0),
                  false);
    sf_mex_assign(&c11_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "sprintf", 1U, 3U, 14, c11_f_y, 14, c11_g_y, 14, c11_h_y), false);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 23);
    sf_mex_assign(&c11_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "strcat", 1U, 2U, 14, sf_mex_dup(c11_str1), 14, sf_mex_dup(c11_temp)),
                  false);
    _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 24);
    sf_mex_assign(&c11_str1, sf_mex_dup(c11_temp2), false);
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 27);
  for (c11_i85 = 0; c11_i85 < 12; c11_i85++) {
    c11_h_u[c11_i85] = c11_cv7[c11_i85];
  }

  c11_i_y = NULL;
  sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_h_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_assign(&c11_str2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c11_i_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 30);
  c11_b_n = (140.0 + c11_c1) + c11_c2;
  c11_dv28[0] = 1.0;
  c11_dv28[1] = c11_b_n;
  c11_mystr_sizes[0] = 1;
  c11_iv0[0] = 1;
  c11_iv0[1] = (int32_T)c11_dv28[1];
  c11_mystr_sizes[1] = c11_iv0[1];
  c11_mystr = c11_mystr_sizes[0];
  c11_b_mystr = c11_mystr_sizes[1];
  c11_loop_ub = (int32_T)c11_dv28[1] - 1;
  for (c11_i86 = 0; c11_i86 <= c11_loop_ub; c11_i86++) {
    c11_mystr_data[c11_i86] = ' ';
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 31);
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "strcat", 1U, 2U, 14, sf_mex_dup(c11_str1), 14,
     sf_mex_dup(c11_str2)), "strcat", c11_tmp_data, c11_tmp_sizes);
  c11_mystr_sizes[0] = 1;
  c11_mystr_sizes[1] = c11_tmp_sizes[1];
  c11_c_mystr = c11_mystr_sizes[0];
  c11_d_mystr = c11_mystr_sizes[1];
  c11_b_loop_ub = c11_tmp_sizes[0] * c11_tmp_sizes[1] - 1;
  for (c11_i87 = 0; c11_i87 <= c11_b_loop_ub; c11_i87++) {
    c11_mystr_data[c11_i87] = c11_tmp_data[c11_i87];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, 32);
  c11_b_mystr_sizes[0] = 1;
  c11_b_mystr_sizes[1] = c11_mystr_sizes[1];
  c11_e_mystr = c11_b_mystr_sizes[0];
  c11_f_mystr = c11_b_mystr_sizes[1];
  c11_c_loop_ub = c11_mystr_sizes[0] * c11_mystr_sizes[1] - 1;
  for (c11_i88 = 0; c11_i88 <= c11_c_loop_ub; c11_i88++) {
    c11_b_mystr_data[c11_i88] = c11_mystr_data[c11_i88];
  }

  c11_c_encStr2Arr(chartInstance, c11_b_mystr_data, c11_b_mystr_sizes, c11_dv29);
  for (c11_i89 = 0; c11_i89 < 256; c11_i89++) {
    c11_arrBML[c11_i89] = c11_dv29[c11_i89];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c11_sfEvent, -32);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c11_str1);
  sf_mex_destroy(&c11_temp);
  sf_mex_destroy(&c11_temp2);
  sf_mex_destroy(&c11_str2);
}

static real_T c11_countDigits(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  real_T c11_x)
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

static void c11_eml_scalar_eg(SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_c_encStr2Arr(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  char_T c11_mystr_data[], int32_T c11_mystr_sizes[2], real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  int32_T c11_arr_sizes;
  real_T c11_arr_data[148];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_loop_ub;
  int32_T c11_i90;
  int32_T c11_i91;
  boolean_T c11_b0;
  boolean_T c11_b1;
  boolean_T c11_b2;
  int32_T c11_i92;
  int32_T c11_tmp_sizes;
  int32_T c11_b_loop_ub;
  int32_T c11_i93;
  int32_T c11_tmp_data[148];
  int32_T c11_iv1[1];
  int32_T c11_c_loop_ub;
  int32_T c11_i94;
  int32_T c11_i95;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_p_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c11_arr_data, (const int32_T *)
    &c11_arr_sizes, NULL, 0, 1, (void *)c11_m_sf_marshallOut, (void *)
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
    c11_mystr_sizes, NULL, 1, 7, (void *)c11_l_sf_marshallOut, (void *)
    c11_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_arr_sizes = c11_mystr_sizes[1];
  c11_loop_ub = c11_mystr_sizes[1] - 1;
  for (c11_i90 = 0; c11_i90 <= c11_loop_ub; c11_i90++) {
    c11_arr_data[c11_i90] = (real_T)c11_mystr_data[c11_mystr_sizes[0] * c11_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = (real_T)c11_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = 256.0 - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i91 = 0; c11_i91 < 256; c11_i91++) {
    c11_tt[c11_i91] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_b0 = (1.0 > c11_ss);
  c11_b1 = c11_b0;
  c11_b2 = c11_b1;
  if (c11_b2) {
    c11_i92 = 0;
  } else {
    c11_i92 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c11_ss, 1, 256, 0, 0);
  }

  c11_tmp_sizes = c11_i92;
  c11_b_loop_ub = c11_i92 - 1;
  for (c11_i93 = 0; c11_i93 <= c11_b_loop_ub; c11_i93++) {
    c11_tmp_data[c11_i93] = c11_i93;
  }

  c11_iv1[0] = c11_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c11_iv1, 1, *(int32_T (*)[1])&c11_arr_sizes, 1);
  c11_c_loop_ub = c11_arr_sizes - 1;
  for (c11_i94 = 0; c11_i94 <= c11_c_loop_ub; c11_i94++) {
    c11_tt[c11_tmp_data[c11_i94]] = c11_arr_data[c11_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i95 = 0; c11_i95 < 256; c11_i95++) {
    c11_myarr256[c11_i95] = c11_tt[c11_i95];
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
    "C:\\Users\\root180\\Documents\\affective-project\\17-10-2015-Matlab-Demo\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\17-10-2015-Matlab-Demo\\cmdBML_AU.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\17-10-2015-Matlab-Demo\\countDigits.m"));
}

static real_T c11_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_feval, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_feval),
    &c11_thisId);
  sf_mex_destroy(&c11_feval);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_strcat, const char_T *c11_identifier,
  char_T c11_y_data[], int32_T c11_y_sizes[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_strcat), &c11_thisId,
    c11_y_data, c11_y_sizes);
  sf_mex_destroy(&c11_strcat);
}

static void c11_d_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2])
{
  int32_T c11_i96;
  uint32_T c11_uv0[2];
  int32_T c11_i97;
  static boolean_T c11_bv0[2] = { false, true };

  boolean_T c11_bv1[2];
  int32_T c11_tmp_sizes[2];
  char_T c11_tmp_data[148];
  int32_T c11_y;
  int32_T c11_b_y;
  int32_T c11_loop_ub;
  int32_T c11_i98;
  (void)chartInstance;
  for (c11_i96 = 0; c11_i96 < 2; c11_i96++) {
    c11_uv0[c11_i96] = 1U + 147U * (uint32_T)c11_i96;
  }

  for (c11_i97 = 0; c11_i97 < 2; c11_i97++) {
    c11_bv1[c11_i97] = c11_bv0[c11_i97];
  }

  sf_mex_import_vs(c11_parentId, sf_mex_dup(c11_u), c11_tmp_data, 0, 10, 0U, 1,
                   0U, 2, c11_bv1, c11_uv0, c11_tmp_sizes);
  c11_y_sizes[0] = 1;
  c11_y_sizes[1] = c11_tmp_sizes[1];
  c11_y = c11_y_sizes[0];
  c11_b_y = c11_y_sizes[1];
  c11_loop_ub = c11_tmp_sizes[0] * c11_tmp_sizes[1] - 1;
  for (c11_i98 = 0; c11_i98 <= c11_loop_ub; c11_i98++) {
    c11_y_data[c11_i98] = c11_tmp_data[c11_i98];
  }

  sf_mex_destroy(&c11_u);
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i99;
  int32_T c11_i100;
  int32_T c11_i101;
  real_T c11_b_inData[1280];
  int32_T c11_i102;
  int32_T c11_i103;
  int32_T c11_i104;
  real_T c11_u[1280];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i99 = 0;
  for (c11_i100 = 0; c11_i100 < 5; c11_i100++) {
    for (c11_i101 = 0; c11_i101 < 256; c11_i101++) {
      c11_b_inData[c11_i101 + c11_i99] = (*(real_T (*)[1280])c11_inData)
        [c11_i101 + c11_i99];
    }

    c11_i99 += 256;
  }

  c11_i102 = 0;
  for (c11_i103 = 0; c11_i103 < 5; c11_i103++) {
    for (c11_i104 = 0; c11_i104 < 256; c11_i104++) {
      c11_u[c11_i104 + c11_i102] = c11_b_inData[c11_i104 + c11_i102];
    }

    c11_i102 += 256;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_e_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_newBmls, const char_T *c11_identifier,
  real_T c11_y[1280])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_newBmls), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_newBmls);
}

static void c11_f_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1280])
{
  real_T c11_dv30[1280];
  int32_T c11_i105;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv30, 1, 0, 0U, 1, 0U, 2,
                256, 5);
  for (c11_i105 = 0; c11_i105 < 1280; c11_i105++) {
    c11_y[c11_i105] = c11_dv30[c11_i105];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_newBmls;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[1280];
  int32_T c11_i106;
  int32_T c11_i107;
  int32_T c11_i108;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_newBmls = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_newBmls), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_newBmls);
  c11_i106 = 0;
  for (c11_i107 = 0; c11_i107 < 5; c11_i107++) {
    for (c11_i108 = 0; c11_i108 < 256; c11_i108++) {
      (*(real_T (*)[1280])c11_outData)[c11_i108 + c11_i106] = c11_y[c11_i108 +
        c11_i106];
    }

    c11_i106 += 256;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i109;
  real_T c11_b_inData[256];
  int32_T c11_i110;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i109 = 0; c11_i109 < 256; c11_i109++) {
    c11_b_inData[c11_i109] = (*(real_T (*)[256])c11_inData)[c11_i109];
  }

  for (c11_i110 = 0; c11_i110 < 256; c11_i110++) {
    c11_u[c11_i110] = c11_b_inData[c11_i110];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_g_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_myBML, const char_T *c11_identifier, real_T
  c11_y[256])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myBML), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myBML);
}

static void c11_h_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256])
{
  real_T c11_dv31[256];
  int32_T c11_i111;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv31, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c11_i111 = 0; c11_i111 < 256; c11_i111++) {
    c11_y[c11_i111] = c11_dv31[c11_i111];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_myBML;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[256];
  int32_T c11_i112;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_myBML = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myBML), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myBML);
  for (c11_i112 = 0; c11_i112 < 256; c11_i112++) {
    (*(real_T (*)[256])c11_outData)[c11_i112] = c11_y[c11_i112];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_feval;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_feval = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_feval),
    &c11_thisId);
  sf_mex_destroy(&c11_feval);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i113;
  real_T c11_b_inData[256];
  int32_T c11_i114;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i113 = 0; c11_i113 < 256; c11_i113++) {
    c11_b_inData[c11_i113] = (*(real_T (*)[256])c11_inData)[c11_i113];
  }

  for (c11_i114 = 0; c11_i114 < 256; c11_i114++) {
    c11_u[c11_i114] = c11_b_inData[c11_i114];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_i_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_myarr256, const char_T *c11_identifier,
  real_T c11_y[256])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
}

static void c11_j_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256])
{
  real_T c11_dv32[256];
  int32_T c11_i115;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv32, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c11_i115 = 0; c11_i115 < 256; c11_i115++) {
    c11_y[c11_i115] = c11_dv32[c11_i115];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_myarr256;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[256];
  int32_T c11_i116;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_myarr256 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
  for (c11_i116 = 0; c11_i116 < 256; c11_i116++) {
    (*(real_T (*)[256])c11_outData)[c11_i116] = c11_y[c11_i116];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  char_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
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
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_k_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
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
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
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
  int32_T c11_i117;
  char_T c11_b_inData[230];
  int32_T c11_i118;
  char_T c11_u[230];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i117 = 0; c11_i117 < 230; c11_i117++) {
    c11_b_inData[c11_i117] = (*(char_T (*)[230])c11_inData)[c11_i117];
  }

  for (c11_i118 = 0; c11_i118 < 230; c11_i118++) {
    c11_u[c11_i118] = c11_b_inData[c11_i118];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 230),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i119;
  real_T c11_b_inData[230];
  int32_T c11_i120;
  real_T c11_u[230];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i119 = 0; c11_i119 < 230; c11_i119++) {
    c11_b_inData[c11_i119] = (*(real_T (*)[230])c11_inData)[c11_i119];
  }

  for (c11_i120 = 0; c11_i120 < 230; c11_i120++) {
    c11_u[c11_i120] = c11_b_inData[c11_i120];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 230), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i121;
  char_T c11_b_inData[109];
  int32_T c11_i122;
  char_T c11_u[109];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i121 = 0; c11_i121 < 109; c11_i121++) {
    c11_b_inData[c11_i121] = (*(char_T (*)[109])c11_inData)[c11_i121];
  }

  for (c11_i122 = 0; c11_i122 < 109; c11_i122++) {
    c11_u[c11_i122] = c11_b_inData[c11_i122];
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
  int32_T c11_i123;
  real_T c11_b_inData[109];
  int32_T c11_i124;
  real_T c11_u[109];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i123 = 0; c11_i123 < 109; c11_i123++) {
    c11_b_inData[c11_i123] = (*(real_T (*)[109])c11_inData)[c11_i123];
  }

  for (c11_i124 = 0; c11_i124 < 109; c11_i124++) {
    c11_u[c11_i124] = c11_b_inData[c11_i124];
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
  int32_T c11_i125;
  real_T c11_b_inData[6];
  int32_T c11_i126;
  real_T c11_u[6];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i125 = 0; c11_i125 < 6; c11_i125++) {
    c11_b_inData[c11_i125] = (*(real_T (*)[6])c11_inData)[c11_i125];
  }

  for (c11_i126 = 0; c11_i126 < 6; c11_i126++) {
    c11_u[c11_i126] = c11_b_inData[c11_i126];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_l_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_AU, const char_T *c11_identifier, real_T
  c11_y[6])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_AU), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_AU);
}

static void c11_m_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6])
{
  real_T c11_dv33[6];
  int32_T c11_i127;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv33, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c11_i127 = 0; c11_i127 < 6; c11_i127++) {
    c11_y[c11_i127] = c11_dv33[c11_i127];
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
  int32_T c11_i128;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_AU = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_AU), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_AU);
  for (c11_i128 = 0; c11_i128 < 6; c11_i128++) {
    (*(real_T (*)[6])c11_outData)[c11_i128] = c11_y[c11_i128];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, char_T
  c11_inData_data[], int32_T c11_inData_sizes[2])
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_b_inData_sizes[2];
  int32_T c11_loop_ub;
  int32_T c11_i129;
  char_T c11_b_inData_data[148];
  int32_T c11_u_sizes[2];
  int32_T c11_b_loop_ub;
  int32_T c11_i130;
  char_T c11_u_data[148];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_b_inData_sizes[0] = 1;
  c11_b_inData_sizes[1] = c11_inData_sizes[1];
  c11_loop_ub = c11_inData_sizes[1] - 1;
  for (c11_i129 = 0; c11_i129 <= c11_loop_ub; c11_i129++) {
    c11_b_inData_data[c11_b_inData_sizes[0] * c11_i129] =
      c11_inData_data[c11_inData_sizes[0] * c11_i129];
  }

  c11_u_sizes[0] = 1;
  c11_u_sizes[1] = c11_b_inData_sizes[1];
  c11_b_loop_ub = c11_b_inData_sizes[1] - 1;
  for (c11_i130 = 0; c11_i130 <= c11_b_loop_ub; c11_i130++) {
    c11_u_data[c11_u_sizes[0] * c11_i130] =
      c11_b_inData_data[c11_b_inData_sizes[0] * c11_i130];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u_data, 10, 0U, 1U, 0U, 2,
    c11_u_sizes[0], c11_u_sizes[1]), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_n_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y_data[], int32_T c11_y_sizes[2])
{
  int32_T c11_i131;
  uint32_T c11_uv1[2];
  int32_T c11_i132;
  static boolean_T c11_bv2[2] = { false, true };

  boolean_T c11_bv3[2];
  int32_T c11_tmp_sizes[2];
  char_T c11_tmp_data[148];
  int32_T c11_y;
  int32_T c11_b_y;
  int32_T c11_loop_ub;
  int32_T c11_i133;
  (void)chartInstance;
  for (c11_i131 = 0; c11_i131 < 2; c11_i131++) {
    c11_uv1[c11_i131] = 1U + 147U * (uint32_T)c11_i131;
  }

  for (c11_i132 = 0; c11_i132 < 2; c11_i132++) {
    c11_bv3[c11_i132] = c11_bv2[c11_i132];
  }

  sf_mex_import_vs(c11_parentId, sf_mex_dup(c11_u), c11_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c11_bv3, c11_uv1, c11_tmp_sizes);
  c11_y_sizes[0] = 1;
  c11_y_sizes[1] = c11_tmp_sizes[1];
  c11_y = c11_y_sizes[0];
  c11_b_y = c11_y_sizes[1];
  c11_loop_ub = c11_tmp_sizes[0] * c11_tmp_sizes[1] - 1;
  for (c11_i133 = 0; c11_i133 <= c11_loop_ub; c11_i133++) {
    c11_y_data[c11_i133] = c11_tmp_data[c11_i133];
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
  char_T c11_y_data[148];
  int32_T c11_loop_ub;
  int32_T c11_i134;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
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
  for (c11_i134 = 0; c11_i134 <= c11_loop_ub; c11_i134++) {
    c11_outData_data[c11_outData_sizes[0] * c11_i134] = c11_y_data[c11_y_sizes[0]
      * c11_i134];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, real_T
  c11_inData_data[], int32_T *c11_inData_sizes)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_b_inData_sizes;
  int32_T c11_loop_ub;
  int32_T c11_i135;
  real_T c11_b_inData_data[148];
  int32_T c11_u_sizes;
  int32_T c11_b_loop_ub;
  int32_T c11_i136;
  real_T c11_u_data[148];
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_b_inData_sizes = *c11_inData_sizes;
  c11_loop_ub = *c11_inData_sizes - 1;
  for (c11_i135 = 0; c11_i135 <= c11_loop_ub; c11_i135++) {
    c11_b_inData_data[c11_i135] = c11_inData_data[c11_i135];
  }

  c11_u_sizes = c11_b_inData_sizes;
  c11_b_loop_ub = c11_b_inData_sizes - 1;
  for (c11_i136 = 0; c11_i136 <= c11_b_loop_ub; c11_i136++) {
    c11_u_data[c11_i136] = c11_b_inData_data[c11_i136];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u_data, 0, 0U, 1U, 0U, 1,
    c11_u_sizes), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_o_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y_data[], int32_T *c11_y_sizes)
{
  static uint32_T c11_uv2[1] = { 148U };

  uint32_T c11_uv3[1];
  static boolean_T c11_bv4[1] = { true };

  boolean_T c11_bv5[1];
  int32_T c11_tmp_sizes;
  real_T c11_tmp_data[148];
  int32_T c11_loop_ub;
  int32_T c11_i137;
  (void)chartInstance;
  c11_uv3[0] = c11_uv2[0];
  c11_bv5[0] = c11_bv4[0];
  sf_mex_import_vs(c11_parentId, sf_mex_dup(c11_u), c11_tmp_data, 1, 0, 0U, 1,
                   0U, 1, c11_bv5, c11_uv3, &c11_tmp_sizes);
  *c11_y_sizes = c11_tmp_sizes;
  c11_loop_ub = c11_tmp_sizes - 1;
  for (c11_i137 = 0; c11_i137 <= c11_loop_ub; c11_i137++) {
    c11_y_data[c11_i137] = c11_tmp_data[c11_i137];
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
  real_T c11_y_data[148];
  int32_T c11_loop_ub;
  int32_T c11_i138;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_arr = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_arr), &c11_thisId,
    c11_y_data, &c11_y_sizes);
  sf_mex_destroy(&c11_arr);
  *c11_outData_sizes = c11_y_sizes;
  c11_loop_ub = c11_y_sizes - 1;
  for (c11_i138 = 0; c11_i138 <= c11_loop_ub; c11_i138++) {
    c11_outData_data[c11_i138] = c11_y_data[c11_i138];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  const mxArray *c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = sf_mex_dup(*(const mxArray **)c11_inData);
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

const mxArray *sf_c11_EP_IdleRand_K_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 89, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  c11_b_info_helper(&c11_nameCaptureInfo);
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
  const mxArray *c11_rhs47 = NULL;
  const mxArray *c11_lhs47 = NULL;
  const mxArray *c11_rhs48 = NULL;
  const mxArray *c11_lhs48 = NULL;
  const mxArray *c11_rhs49 = NULL;
  const mxArray *c11_lhs49 = NULL;
  const mxArray *c11_rhs50 = NULL;
  const mxArray *c11_lhs50 = NULL;
  const mxArray *c11_rhs51 = NULL;
  const mxArray *c11_lhs51 = NULL;
  const mxArray *c11_rhs52 = NULL;
  const mxArray *c11_lhs52 = NULL;
  const mxArray *c11_rhs53 = NULL;
  const mxArray *c11_lhs53 = NULL;
  const mxArray *c11_rhs54 = NULL;
  const mxArray *c11_lhs54 = NULL;
  const mxArray *c11_rhs55 = NULL;
  const mxArray *c11_lhs55 = NULL;
  const mxArray *c11_rhs56 = NULL;
  const mxArray *c11_lhs56 = NULL;
  const mxArray *c11_rhs57 = NULL;
  const mxArray *c11_lhs57 = NULL;
  const mxArray *c11_rhs58 = NULL;
  const mxArray *c11_lhs58 = NULL;
  const mxArray *c11_rhs59 = NULL;
  const mxArray *c11_lhs59 = NULL;
  const mxArray *c11_rhs60 = NULL;
  const mxArray *c11_lhs60 = NULL;
  const mxArray *c11_rhs61 = NULL;
  const mxArray *c11_lhs61 = NULL;
  const mxArray *c11_rhs62 = NULL;
  const mxArray *c11_lhs62 = NULL;
  const mxArray *c11_rhs63 = NULL;
  const mxArray *c11_lhs63 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1445215678U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fprintf"), "name", "name", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnan"), "name", "name", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fprintf"), "name", "name",
                  14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("upper"), "name", "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("colon"), "name", "name", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("colon"), "name", "name", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("floor"), "name", "name", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
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
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "name", "name", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fidCheck"), "name", "name",
                  47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c11_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("upper"), "name", "name", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c11_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c11_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c11_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c11_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c11_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c11_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c11_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("cmdBML_AU"), "name", "name",
                  55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1445130918U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c11_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("countDigits"), "name",
                  "name", 56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/countDigits.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1408487908U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c11_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/countDigits.m"),
                  "context", "context", 57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("abs"), "name", "name", 57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c11_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c11_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c11_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("abs"), "name", "name", 60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c11_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("log10"), "name", "name", 61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1343862782U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c11_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_error"), "name", "name",
                  62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c11_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 63);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 63);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851128U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c11_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs63), "lhs", "lhs",
                  63);
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
  sf_mex_destroy(&c11_rhs47);
  sf_mex_destroy(&c11_lhs47);
  sf_mex_destroy(&c11_rhs48);
  sf_mex_destroy(&c11_lhs48);
  sf_mex_destroy(&c11_rhs49);
  sf_mex_destroy(&c11_lhs49);
  sf_mex_destroy(&c11_rhs50);
  sf_mex_destroy(&c11_lhs50);
  sf_mex_destroy(&c11_rhs51);
  sf_mex_destroy(&c11_lhs51);
  sf_mex_destroy(&c11_rhs52);
  sf_mex_destroy(&c11_lhs52);
  sf_mex_destroy(&c11_rhs53);
  sf_mex_destroy(&c11_lhs53);
  sf_mex_destroy(&c11_rhs54);
  sf_mex_destroy(&c11_lhs54);
  sf_mex_destroy(&c11_rhs55);
  sf_mex_destroy(&c11_lhs55);
  sf_mex_destroy(&c11_rhs56);
  sf_mex_destroy(&c11_lhs56);
  sf_mex_destroy(&c11_rhs57);
  sf_mex_destroy(&c11_lhs57);
  sf_mex_destroy(&c11_rhs58);
  sf_mex_destroy(&c11_lhs58);
  sf_mex_destroy(&c11_rhs59);
  sf_mex_destroy(&c11_lhs59);
  sf_mex_destroy(&c11_rhs60);
  sf_mex_destroy(&c11_lhs60);
  sf_mex_destroy(&c11_rhs61);
  sf_mex_destroy(&c11_lhs61);
  sf_mex_destroy(&c11_rhs62);
  sf_mex_destroy(&c11_lhs62);
  sf_mex_destroy(&c11_rhs63);
  sf_mex_destroy(&c11_lhs63);
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

static void c11_b_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs64 = NULL;
  const mxArray *c11_lhs64 = NULL;
  const mxArray *c11_rhs65 = NULL;
  const mxArray *c11_lhs65 = NULL;
  const mxArray *c11_rhs66 = NULL;
  const mxArray *c11_lhs66 = NULL;
  const mxArray *c11_rhs67 = NULL;
  const mxArray *c11_lhs67 = NULL;
  const mxArray *c11_rhs68 = NULL;
  const mxArray *c11_lhs68 = NULL;
  const mxArray *c11_rhs69 = NULL;
  const mxArray *c11_lhs69 = NULL;
  const mxArray *c11_rhs70 = NULL;
  const mxArray *c11_lhs70 = NULL;
  const mxArray *c11_rhs71 = NULL;
  const mxArray *c11_lhs71 = NULL;
  const mxArray *c11_rhs72 = NULL;
  const mxArray *c11_lhs72 = NULL;
  const mxArray *c11_rhs73 = NULL;
  const mxArray *c11_lhs73 = NULL;
  const mxArray *c11_rhs74 = NULL;
  const mxArray *c11_lhs74 = NULL;
  const mxArray *c11_rhs75 = NULL;
  const mxArray *c11_lhs75 = NULL;
  const mxArray *c11_rhs76 = NULL;
  const mxArray *c11_lhs76 = NULL;
  const mxArray *c11_rhs77 = NULL;
  const mxArray *c11_lhs77 = NULL;
  const mxArray *c11_rhs78 = NULL;
  const mxArray *c11_lhs78 = NULL;
  const mxArray *c11_rhs79 = NULL;
  const mxArray *c11_lhs79 = NULL;
  const mxArray *c11_rhs80 = NULL;
  const mxArray *c11_lhs80 = NULL;
  const mxArray *c11_rhs81 = NULL;
  const mxArray *c11_lhs81 = NULL;
  const mxArray *c11_rhs82 = NULL;
  const mxArray *c11_lhs82 = NULL;
  const mxArray *c11_rhs83 = NULL;
  const mxArray *c11_lhs83 = NULL;
  const mxArray *c11_rhs84 = NULL;
  const mxArray *c11_lhs84 = NULL;
  const mxArray *c11_rhs85 = NULL;
  const mxArray *c11_lhs85 = NULL;
  const mxArray *c11_rhs86 = NULL;
  const mxArray *c11_lhs86 = NULL;
  const mxArray *c11_rhs87 = NULL;
  const mxArray *c11_lhs87 = NULL;
  const mxArray *c11_rhs88 = NULL;
  const mxArray *c11_lhs88 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("realmax"), "name", "name",
                  64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1307683642U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c11_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c11_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c11_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("mrdivide"), "name", "name",
                  67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c11_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c11_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("rdivide"), "name", "name",
                  69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c11_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c11_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c11_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_div"), "name", "name",
                  72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c11_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c11_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "context", "context", 74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("ceil"), "name", "name", 74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c11_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c11_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_ceil"), "name",
                  "name", 76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_ceil.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851120U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c11_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "context", "context", 77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("max"), "name", "name", 77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1311287716U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c11_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378328384U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c11_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c11_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c11_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c11_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c11_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c11_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c11_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c11_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("blanks"), "name", "name", 86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c11_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c11_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/cmdBML_AU.m"),
                  "context", "context", 88);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  88);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1445215678U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c11_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs88), "lhs", "lhs",
                  88);
  sf_mex_destroy(&c11_rhs64);
  sf_mex_destroy(&c11_lhs64);
  sf_mex_destroy(&c11_rhs65);
  sf_mex_destroy(&c11_lhs65);
  sf_mex_destroy(&c11_rhs66);
  sf_mex_destroy(&c11_lhs66);
  sf_mex_destroy(&c11_rhs67);
  sf_mex_destroy(&c11_lhs67);
  sf_mex_destroy(&c11_rhs68);
  sf_mex_destroy(&c11_lhs68);
  sf_mex_destroy(&c11_rhs69);
  sf_mex_destroy(&c11_lhs69);
  sf_mex_destroy(&c11_rhs70);
  sf_mex_destroy(&c11_lhs70);
  sf_mex_destroy(&c11_rhs71);
  sf_mex_destroy(&c11_lhs71);
  sf_mex_destroy(&c11_rhs72);
  sf_mex_destroy(&c11_lhs72);
  sf_mex_destroy(&c11_rhs73);
  sf_mex_destroy(&c11_lhs73);
  sf_mex_destroy(&c11_rhs74);
  sf_mex_destroy(&c11_lhs74);
  sf_mex_destroy(&c11_rhs75);
  sf_mex_destroy(&c11_lhs75);
  sf_mex_destroy(&c11_rhs76);
  sf_mex_destroy(&c11_lhs76);
  sf_mex_destroy(&c11_rhs77);
  sf_mex_destroy(&c11_lhs77);
  sf_mex_destroy(&c11_rhs78);
  sf_mex_destroy(&c11_lhs78);
  sf_mex_destroy(&c11_rhs79);
  sf_mex_destroy(&c11_lhs79);
  sf_mex_destroy(&c11_rhs80);
  sf_mex_destroy(&c11_lhs80);
  sf_mex_destroy(&c11_rhs81);
  sf_mex_destroy(&c11_lhs81);
  sf_mex_destroy(&c11_rhs82);
  sf_mex_destroy(&c11_lhs82);
  sf_mex_destroy(&c11_rhs83);
  sf_mex_destroy(&c11_lhs83);
  sf_mex_destroy(&c11_rhs84);
  sf_mex_destroy(&c11_lhs84);
  sf_mex_destroy(&c11_rhs85);
  sf_mex_destroy(&c11_lhs85);
  sf_mex_destroy(&c11_rhs86);
  sf_mex_destroy(&c11_lhs86);
  sf_mex_destroy(&c11_rhs87);
  sf_mex_destroy(&c11_lhs87);
  sf_mex_destroy(&c11_rhs88);
  sf_mex_destroy(&c11_lhs88);
}

static void c11_activate_secsc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance)
{
  chartInstance->c11_sfEvent = c11_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_deactivate_secsc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_increment_counters_secsc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  if (chartInstance->c11_temporalCounter_i1 < 511U) {
    chartInstance->c11_temporalCounter_i1 = (uint16_T)((uint32_T)
      chartInstance->c11_temporalCounter_i1 + 1U);
  }

  if (chartInstance->c11_temporalCounter_i2 < 15U) {
    chartInstance->c11_temporalCounter_i2 = (uint8_T)(int16_T)
      (chartInstance->c11_temporalCounter_i2 + 1);
  }
}

static void c11_reset_counters_secsc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c11_EP_IdleRand_K_secs(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_activate_secsc11_EP_IdleRand_K(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c11_EP_IdleRand_K_secs(SimStruct *
  c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_increment_counters_secsc11_EP_IdleRand_K(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c11_EP_IdleRand_K_secs(SimStruct
  *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_reset_counters_secsc11_EP_IdleRand_K(chartInstance);
}

void sf_exported_auto_deactivate_c11_EP_IdleRand_K_secs(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_deactivate_secsc11_EP_IdleRand_K(chartInstance);
}

boolean_T sf_exported_auto_isStablec11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  return chartInstance->c11_isStable;
}

void sf_exported_auto_duringc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_c11_EP_IdleRand_K(chartInstance);
}

void sf_exported_auto_enterc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_enter_atomic_c11_EP_IdleRand_K(chartInstance);
  c11_enter_internal_c11_EP_IdleRand_K(chartInstance);
}

void sf_exported_auto_exitc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_exit_internal_c11_EP_IdleRand_K(chartInstance);
}

void sf_exported_auto_gatewayc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc11_EP_IdleRand_K(SimStruct *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_initc11_EP_IdleRand_K(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec11_EP_IdleRand_K(SimStruct *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out, sf_internal_get_sim_state_c11_EP_IdleRand_K(c11_S),
                false);
  return c11_out;
}

void sf_exported_auto_setSimstatec11_EP_IdleRand_K(SimStruct *c11_S, const
  mxArray *c11_in)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c11_EP_IdleRand_K(c11_S, sf_mex_dup(c11_in));
  sf_mex_destroy(&c11_in);
}

void sf_exported_auto_check_state_inconsistency_c11_EP_IdleRand_K(SimStruct
  *c11_S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EP_IdleRand_KMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_insertQueuec11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_bmls[1280], real_T c11_myBML[256], real_T
  c11_newBmls[1280])
{
  uint32_T c11_debug_family_var_map[8];
  real_T c11_full;
  real_T c11_t[256];
  real_T c11_i;
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i139;
  static real_T c11_varargin_2[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i140;
  int32_T c11_i141;
  int32_T c11_i142;
  int32_T c11_i143;
  int32_T c11_i144;
  int32_T c11_b_i;
  int32_T c11_c_i;
  int32_T c11_i145;
  real_T c11_varargin_1[256];
  boolean_T c11_p;
  boolean_T c11_b_p;
  int32_T c11_k;
  real_T c11_b_k;
  real_T c11_x1;
  real_T c11_x2;
  boolean_T c11_c_p;
  int32_T c11_d_i;
  int32_T c11_i146;
  int32_T c11_i147;
  real_T c11_b_bmls[256];
  int32_T c11_i148;
  int32_T c11_i149;
  real_T c11_c_bmls[256];
  int32_T c11_i150;
  int32_T c11_i151;
  real_T c11_d_bmls[256];
  int32_T c11_i152;
  int32_T c11_i153;
  int32_T c11_i154;
  int32_T exitg1;
  boolean_T exitg2;
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
  for (c11_i139 = 0; c11_i139 < 256; c11_i139++) {
    c11_t[c11_i139] = c11_varargin_2[c11_i139];
  }

  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 4);
  for (c11_i140 = 0; c11_i140 < 256; c11_i140++) {
    c11_newBmls[c11_i140] = c11_t[c11_i140];
  }

  for (c11_i141 = 0; c11_i141 < 256; c11_i141++) {
    c11_newBmls[c11_i141 + 256] = c11_t[c11_i141];
  }

  for (c11_i142 = 0; c11_i142 < 256; c11_i142++) {
    c11_newBmls[c11_i142 + 512] = c11_t[c11_i142];
  }

  for (c11_i143 = 0; c11_i143 < 256; c11_i143++) {
    c11_newBmls[c11_i143 + 768] = c11_t[c11_i143];
  }

  for (c11_i144 = 0; c11_i144 < 256; c11_i144++) {
    c11_newBmls[c11_i144 + 1024] = c11_t[c11_i144];
  }

  c11_updateDataWrittenToVector(chartInstance, 10U);
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
      for (c11_i145 = 0; c11_i145 < 256; c11_i145++) {
        c11_varargin_1[c11_i145] = c11_bmls[c11_i145 + (c11_c_i << 8)];
      }

      c11_p = false;
      c11_b_p = true;
      c11_k = 0;
      exitg2 = false;
      while ((exitg2 == false) && (c11_k < 256)) {
        c11_b_k = 1.0 + (real_T)c11_k;
        c11_x1 = c11_varargin_1[(int32_T)c11_b_k - 1];
        c11_x2 = c11_varargin_2[(int32_T)c11_b_k - 1];
        c11_c_p = (c11_x1 == c11_x2);
        if (!c11_c_p) {
          c11_b_p = false;
          exitg2 = true;
        } else {
          c11_k++;
        }
      }

      if (!c11_b_p) {
      } else {
        c11_p = true;
      }

      if (CV_EML_IF(1, 1, 0, c11_p)) {
        _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 8);
        c11_d_i = (int32_T)c11_i - 1;
        for (c11_i146 = 0; c11_i146 < 256; c11_i146++) {
          c11_bmls[c11_i146 + (c11_d_i << 8)] = c11_myBML[c11_i146];
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
    for (c11_i147 = 0; c11_i147 < 256; c11_i147++) {
      c11_b_bmls[c11_i147] = c11_bmls[c11_i147 + 256];
    }

    for (c11_i148 = 0; c11_i148 < 256; c11_i148++) {
      c11_bmls[c11_i148] = c11_b_bmls[c11_i148];
    }

    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 16);
    for (c11_i149 = 0; c11_i149 < 256; c11_i149++) {
      c11_c_bmls[c11_i149] = c11_bmls[c11_i149 + 512];
    }

    for (c11_i150 = 0; c11_i150 < 256; c11_i150++) {
      c11_bmls[c11_i150 + 256] = c11_c_bmls[c11_i150];
    }

    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 17);
    for (c11_i151 = 0; c11_i151 < 256; c11_i151++) {
      c11_d_bmls[c11_i151] = c11_bmls[c11_i151 + 768];
    }

    for (c11_i152 = 0; c11_i152 < 256; c11_i152++) {
      c11_bmls[c11_i152 + 512] = c11_d_bmls[c11_i152];
    }

    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 18);
    for (c11_i153 = 0; c11_i153 < 256; c11_i153++) {
      c11_bmls[c11_i153 + 1024] = c11_myBML[c11_i153];
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 20);
  for (c11_i154 = 0; c11_i154 < 1280; c11_i154++) {
    c11_newBmls[c11_i154] = c11_bmls[c11_i154];
  }

  c11_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_smileTablec11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256])
{
  uint32_T c11_debug_family_var_map[7];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  real_T c11_dv34[256];
  int32_T c11_i155;
  int32_T c11_i156;
  int32_T c11_i157;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_c_debug_family_names,
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
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 3);
  c11_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 4);
  c11_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 9);
  c11_aVarTruthTableCondition_1 = (c11_bmlID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 13);
  c11_aVarTruthTableCondition_2 = (c11_bmlID == 2.0);
  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 15);
  if (CV_EML_IF(4, 1, 0, c11_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 16);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 27);
    c11_encStr2Arr(chartInstance, c11_dv34);
    for (c11_i155 = 0; c11_i155 < 256; c11_i155++) {
      c11_poseBML[c11_i155] = c11_dv34[c11_i155];
    }

    c11_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 27);
    *c11_p = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, -27);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 17);
    if (CV_EML_IF(4, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 18);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 33);
      c11_b_encStr2Arr(chartInstance, c11_dv34);
      for (c11_i156 = 0; c11_i156 < 256; c11_i156++) {
        c11_poseBML[c11_i156] = c11_dv34[c11_i156];
      }

      c11_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 33);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, -33);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 20);
      CV_EML_FCN(4, 1);
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 27);
      c11_encStr2Arr(chartInstance, c11_dv34);
      for (c11_i157 = 0; c11_i157 < 256; c11_i157++) {
        c11_poseBML[c11_i157] = c11_dv34[c11_i157];
      }

      c11_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, 27);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_facialExprc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256])
{
  uint32_T c11_debug_family_var_map[7];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  real_T c11_dv35[256];
  int32_T c11_i158;
  int32_T c11_i159;
  int32_T c11_i160;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_f_debug_family_names,
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
    c11_encStr2Arr(chartInstance, c11_dv35);
    for (c11_i158 = 0; c11_i158 < 256; c11_i158++) {
      c11_poseBML[c11_i158] = c11_dv35[c11_i158];
    }

    c11_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
    *c11_p = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -27);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 17);
    if (CV_EML_IF(0, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
      c11_b_encStr2Arr(chartInstance, c11_dv35);
      for (c11_i159 = 0; c11_i159 < 256; c11_i159++) {
        c11_poseBML[c11_i159] = c11_dv35[c11_i159];
      }

      c11_updateDataWrittenToVector(chartInstance, 14U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -33);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 20);
      CV_EML_FCN(0, 1);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
      c11_encStr2Arr(chartInstance, c11_dv35);
      for (c11_i160 = 0; c11_i160 < 256; c11_i160++) {
        c11_poseBML[c11_i160] = c11_dv35[c11_i160];
      }

      c11_updateDataWrittenToVector(chartInstance, 14U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_setAUc11_EP_IdleRand_K(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, real_T c11_E, real_T c11_AU[6], real_T *c11_L)
{
  uint32_T c11_debug_family_var_map[5];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  int32_T c11_i161;
  int32_T c11_i162;
  static real_T c11_dv36[6] = { 1.0, 2.0, 45.0, 0.0, 0.0, 0.0 };

  int32_T c11_i163;
  static real_T c11_dv37[6] = { 1.0, 4.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i164;
  static real_T c11_dv38[6] = { 1.0, 2.0, 4.0, 5.0, 6.0, 0.0 };

  int32_T c11_i165;
  static real_T c11_dv39[6] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0 };

  int32_T c11_i166;
  static real_T c11_dv40[6] = { 12.0, 14.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i167;
  static real_T c11_dv41[6] = { 6.0, 12.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i168;
  static real_T c11_dv42[6] = { 12.0, 26.0, 5.0, 1.0, 2.0, 0.0 };

  int32_T c11_i169;
  static real_T c11_dv43[6] = { 2.0, 4.0, 5.0, 7.0, 45.0, 0.0 };

  const mxArray *c11_y = NULL;
  char_T c11_u[31];
  static char_T c11_cv8[31] = { 'e', 'r', 'r', 'o', 'r', ',', ' ', 's', 'e', 't',
    'A', 'U', ',', 'e', 'm', 'o', 't', 'i', 'o', 'n', ' ', 'n', 'o', 't', ' ',
    'l', 'i', 's', 't', 'e', 'd' };

  int32_T c11_i170;
  int32_T c11_i171;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c11_g_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_E, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_AU, 3U, c11_k_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_L, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 12);
  for (c11_i161 = 0; c11_i161 < 6; c11_i161++) {
    c11_AU[c11_i161] = 0.0;
  }

  c11_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 12);
  *c11_L = 0.0;
  c11_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 16);
  switch ((int16_T)_SFD_INTEGER_CHECK("E", c11_E)) {
   case 1:
    CV_EML_SWITCH(2, 1, 0, 1);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 18);
    for (c11_i162 = 0; c11_i162 < 6; c11_i162++) {
      c11_AU[c11_i162] = c11_dv36[c11_i162];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 18);
    *c11_L = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   case 2:
    CV_EML_SWITCH(2, 1, 0, 2);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 21);
    for (c11_i163 = 0; c11_i163 < 6; c11_i163++) {
      c11_AU[c11_i163] = c11_dv37[c11_i163];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 21);
    *c11_L = 2.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   case 3:
    CV_EML_SWITCH(2, 1, 0, 3);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 24);
    for (c11_i164 = 0; c11_i164 < 6; c11_i164++) {
      c11_AU[c11_i164] = c11_dv38[c11_i164];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 24);
    *c11_L = 5.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   case 4:
    CV_EML_SWITCH(2, 1, 0, 4);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 27);
    for (c11_i165 = 0; c11_i165 < 6; c11_i165++) {
      c11_AU[c11_i165] = c11_dv39[c11_i165];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 27);
    *c11_L = 6.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   case 5:
    CV_EML_SWITCH(2, 1, 0, 5);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 30);
    for (c11_i166 = 0; c11_i166 < 6; c11_i166++) {
      c11_AU[c11_i166] = c11_dv40[c11_i166];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 30);
    *c11_L = 2.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   case 7:
    CV_EML_SWITCH(2, 1, 0, 6);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 33);
    for (c11_i167 = 0; c11_i167 < 6; c11_i167++) {
      c11_AU[c11_i167] = c11_dv41[c11_i167];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 33);
    *c11_L = 2.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   case 8:
    CV_EML_SWITCH(2, 1, 0, 7);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 36);
    for (c11_i168 = 0; c11_i168 < 6; c11_i168++) {
      c11_AU[c11_i168] = c11_dv42[c11_i168];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 36);
    *c11_L = 5.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   case 9:
    CV_EML_SWITCH(2, 1, 0, 8);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 39);
    for (c11_i169 = 0; c11_i169 < 6; c11_i169++) {
      c11_AU[c11_i169] = c11_dv43[c11_i169];
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 39);
    *c11_L = 5.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    break;

   default:
    CV_EML_SWITCH(2, 1, 0, 0);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 46);
    for (c11_i170 = 0; c11_i170 < 6; c11_i170++) {
      c11_AU[c11_i170] = 0.0;
    }

    c11_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 46);
    *c11_L = 0.0;
    c11_updateDataWrittenToVector(chartInstance, 16U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 47);
    for (c11_i171 = 0; c11_i171 < 31; c11_i171++) {
      c11_u[c11_i171] = c11_cv8[c11_i171];
    }

    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c11_y);
    break;
  }

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, -47);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_set_eAmountFactorc11_EP_IdleRand_K
  (SFc11_EP_IdleRand_KInstanceStruct *chartInstance, real_T c11_E, real_T c11_Pt,
   real_T c11_eAmountFactor[6])
{
  uint32_T c11_debug_family_var_map[7];
  real_T c11_AU[6];
  real_T c11_pFactor;
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i172;
  int32_T c11_i173;
  int32_T c11_i174;
  static real_T c11_dv44[6] = { 1.0, 1.0, 0.0, 0.35, 0.0, 0.0 };

  int32_T c11_i175;
  static real_T c11_dv45[6] = { 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i176;
  static real_T c11_dv46[6] = { 1.0, 1.0, 1.0, 0.5, 0.5, 0.0 };

  int32_T c11_i177;
  static real_T c11_dv47[6] = { 1.0, 1.0, 1.0, 0.2, 0.2, 0.0 };

  int32_T c11_i178;
  static real_T c11_dv48[6] = { 0.7, 0.3, 0.3, 0.0, 0.0, 0.0 };

  int32_T c11_i179;
  static real_T c11_dv49[6] = { 1.0, 0.5, 0.0, 0.0, 0.0, 0.0 };

  int32_T c11_i180;
  static real_T c11_dv50[6] = { 1.0, 1.0, 1.0, 1.0, 1.0, 0.0 };

  int32_T c11_i181;
  int32_T c11_i182;
  static char_T c11_cv9[43] = { 'e', 'r', 'r', 'o', 'r', ',', ' ', 's', 'e', 't',
    '_', 'e', 'A', 'm', 'o', 'u', 'n', 't', 'F', 'a', 'c', 't', 'o', 'r', ',',
    'e', 'm', 'o', 't', 'i', 'o', 'n', ' ', 'n', 'o', 't', ' ', 'l', 'i', 's',
    't', 'e', 'd' };

  char_T c11_u[43];
  const mxArray *c11_y = NULL;
  int32_T c11_i183;
  int32_T c11_i184;
  int32_T c11_i185;
  int32_T c11_i186;
  int32_T c11_i187;
  int32_T c11_i188;
  int32_T c11_i189;
  int32_T c11_i190;
  int32_T c11_i191;
  char_T c11_b_u[43];
  const mxArray *c11_b_y = NULL;
  int32_T c11_i192;
  int32_T c11_i193;
  int32_T c11_i194;
  int32_T c11_i195;
  int32_T c11_i196;
  int32_T c11_i197;
  int32_T c11_i198;
  int32_T c11_i199;
  int32_T c11_i200;
  char_T c11_c_u[43];
  const mxArray *c11_c_y = NULL;
  int32_T c11_i201;
  real_T c11_a[6];
  int32_T c11_i202;
  int32_T c11_i203;
  int32_T c11_i204;
  int32_T c11_i205;
  int32_T c11_i206;
  int32_T c11_i207;
  int32_T c11_i208;
  int32_T c11_i209;
  int32_T c11_i210;
  int32_T c11_i211;
  char_T c11_d_u[43];
  const mxArray *c11_d_y = NULL;
  int32_T c11_i212;
  int32_T c11_i213;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_h_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_AU, 0U, c11_k_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_pFactor, 1U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_E, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_Pt, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_eAmountFactor, 6U,
    c11_k_sf_marshallOut, c11_f_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 2);
  for (c11_i172 = 0; c11_i172 < 6; c11_i172++) {
    c11_AU[c11_i172] = 0.0;
  }

  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 2);
  for (c11_i173 = 0; c11_i173 < 6; c11_i173++) {
    c11_eAmountFactor[c11_i173] = 0.0;
  }

  c11_updateDataWrittenToVector(chartInstance, 17U);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 2);
  c11_pFactor = 1.0;
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 4);
  if (CV_EML_IF(3, 1, 0, c11_Pt == 1.0)) {
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 6);
    if (CV_EML_IF(3, 1, 1, c11_E == 1.0)) {
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 7);
      for (c11_i174 = 0; c11_i174 < 6; c11_i174++) {
        c11_eAmountFactor[c11_i174] = c11_dv44[c11_i174];
      }

      c11_updateDataWrittenToVector(chartInstance, 17U);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 8);
      if (CV_EML_IF(3, 1, 2, c11_E == 2.0)) {
        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 9);
        for (c11_i175 = 0; c11_i175 < 6; c11_i175++) {
          c11_eAmountFactor[c11_i175] = c11_dv45[c11_i175];
        }

        c11_updateDataWrittenToVector(chartInstance, 17U);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 10);
        if (CV_EML_IF(3, 1, 3, c11_E == 3.0)) {
          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 11);
          for (c11_i176 = 0; c11_i176 < 6; c11_i176++) {
            c11_eAmountFactor[c11_i176] = c11_dv46[c11_i176];
          }

          c11_updateDataWrittenToVector(chartInstance, 17U);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 12);
          if (CV_EML_IF(3, 1, 4, c11_E == 4.0)) {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 13);
            for (c11_i177 = 0; c11_i177 < 6; c11_i177++) {
              c11_eAmountFactor[c11_i177] = c11_dv47[c11_i177];
            }

            c11_updateDataWrittenToVector(chartInstance, 17U);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 14);
            if (CV_EML_IF(3, 1, 5, c11_E == 5.0)) {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 15);
              for (c11_i178 = 0; c11_i178 < 6; c11_i178++) {
                c11_eAmountFactor[c11_i178] = c11_dv48[c11_i178];
              }

              c11_updateDataWrittenToVector(chartInstance, 17U);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 16);
              if (CV_EML_IF(3, 1, 6, c11_E == 7.0)) {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 17);
                for (c11_i179 = 0; c11_i179 < 6; c11_i179++) {
                  c11_eAmountFactor[c11_i179] = c11_dv49[c11_i179];
                }

                c11_updateDataWrittenToVector(chartInstance, 17U);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 18);
                if (CV_EML_IF(3, 1, 7, c11_E == 8.0)) {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 19);
                  for (c11_i180 = 0; c11_i180 < 6; c11_i180++) {
                    c11_eAmountFactor[c11_i180] = c11_dv50[c11_i180];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 17U);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 21);
                  for (c11_i181 = 0; c11_i181 < 6; c11_i181++) {
                    c11_eAmountFactor[c11_i181] = 0.0;
                  }

                  c11_updateDataWrittenToVector(chartInstance, 17U);
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 22);
                  for (c11_i182 = 0; c11_i182 < 43; c11_i182++) {
                    c11_u[c11_i182] = c11_cv9[c11_i182];
                  }

                  c11_y = NULL;
                  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U,
                    2, 1, 43), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c11_y);
                }
              }
            }
          }
        }
      }
    }
  } else {
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 26);
    if (CV_EML_IF(3, 1, 8, c11_Pt == 2.0)) {
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 27);
      if (CV_EML_IF(3, 1, 9, c11_E == 1.0)) {
        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 28);
        for (c11_i183 = 0; c11_i183 < 6; c11_i183++) {
          c11_eAmountFactor[c11_i183] = c11_dv44[c11_i183];
        }

        c11_updateDataWrittenToVector(chartInstance, 17U);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 29);
        if (CV_EML_IF(3, 1, 10, c11_E == 2.0)) {
          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 30);
          for (c11_i184 = 0; c11_i184 < 6; c11_i184++) {
            c11_eAmountFactor[c11_i184] = c11_dv45[c11_i184];
          }

          c11_updateDataWrittenToVector(chartInstance, 17U);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 31);
          if (CV_EML_IF(3, 1, 11, c11_E == 3.0)) {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 32);
            for (c11_i185 = 0; c11_i185 < 6; c11_i185++) {
              c11_eAmountFactor[c11_i185] = c11_dv46[c11_i185];
            }

            c11_updateDataWrittenToVector(chartInstance, 17U);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 33);
            if (CV_EML_IF(3, 1, 12, c11_E == 4.0)) {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 34);
              for (c11_i186 = 0; c11_i186 < 6; c11_i186++) {
                c11_eAmountFactor[c11_i186] = c11_dv47[c11_i186];
              }

              c11_updateDataWrittenToVector(chartInstance, 17U);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 35);
              if (CV_EML_IF(3, 1, 13, c11_E == 5.0)) {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 36);
                for (c11_i187 = 0; c11_i187 < 6; c11_i187++) {
                  c11_eAmountFactor[c11_i187] = c11_dv48[c11_i187];
                }

                c11_updateDataWrittenToVector(chartInstance, 17U);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 37);
                if (CV_EML_IF(3, 1, 14, c11_E == 7.0)) {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 38);
                  for (c11_i188 = 0; c11_i188 < 6; c11_i188++) {
                    c11_eAmountFactor[c11_i188] = c11_dv49[c11_i188];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 17U);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 39);
                  if (CV_EML_IF(3, 1, 15, c11_E == 8.0)) {
                    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 40);
                    for (c11_i189 = 0; c11_i189 < 6; c11_i189++) {
                      c11_eAmountFactor[c11_i189] = c11_dv50[c11_i189];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 17U);
                  } else {
                    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 42);
                    for (c11_i190 = 0; c11_i190 < 6; c11_i190++) {
                      c11_eAmountFactor[c11_i190] = 0.0;
                    }

                    c11_updateDataWrittenToVector(chartInstance, 17U);
                    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 43);
                    for (c11_i191 = 0; c11_i191 < 43; c11_i191++) {
                      c11_b_u[c11_i191] = c11_cv9[c11_i191];
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
    } else {
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 47);
      if (CV_EML_IF(3, 1, 16, c11_Pt == 3.0)) {
        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 48);
        if (CV_EML_IF(3, 1, 17, c11_E == 1.0)) {
          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 49);
          for (c11_i192 = 0; c11_i192 < 6; c11_i192++) {
            c11_eAmountFactor[c11_i192] = c11_dv44[c11_i192];
          }

          c11_updateDataWrittenToVector(chartInstance, 17U);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 50);
          if (CV_EML_IF(3, 1, 18, c11_E == 2.0)) {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 51);
            for (c11_i193 = 0; c11_i193 < 6; c11_i193++) {
              c11_eAmountFactor[c11_i193] = c11_dv45[c11_i193];
            }

            c11_updateDataWrittenToVector(chartInstance, 17U);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 52);
            if (CV_EML_IF(3, 1, 19, c11_E == 3.0)) {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 53);
              for (c11_i194 = 0; c11_i194 < 6; c11_i194++) {
                c11_eAmountFactor[c11_i194] = c11_dv46[c11_i194];
              }

              c11_updateDataWrittenToVector(chartInstance, 17U);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 54);
              if (CV_EML_IF(3, 1, 20, c11_E == 4.0)) {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 55);
                for (c11_i195 = 0; c11_i195 < 6; c11_i195++) {
                  c11_eAmountFactor[c11_i195] = c11_dv47[c11_i195];
                }

                c11_updateDataWrittenToVector(chartInstance, 17U);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 56);
                if (CV_EML_IF(3, 1, 21, c11_E == 5.0)) {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 57);
                  for (c11_i196 = 0; c11_i196 < 6; c11_i196++) {
                    c11_eAmountFactor[c11_i196] = c11_dv48[c11_i196];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 17U);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 58);
                  if (CV_EML_IF(3, 1, 22, c11_E == 7.0)) {
                    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 59);
                    for (c11_i197 = 0; c11_i197 < 6; c11_i197++) {
                      c11_eAmountFactor[c11_i197] = c11_dv49[c11_i197];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 17U);
                  } else {
                    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 60);
                    if (CV_EML_IF(3, 1, 23, c11_E == 8.0)) {
                      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 61);
                      for (c11_i198 = 0; c11_i198 < 6; c11_i198++) {
                        c11_eAmountFactor[c11_i198] = c11_dv50[c11_i198];
                      }

                      c11_updateDataWrittenToVector(chartInstance, 17U);
                    } else {
                      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 63);
                      for (c11_i199 = 0; c11_i199 < 6; c11_i199++) {
                        c11_eAmountFactor[c11_i199] = 0.0;
                      }

                      c11_updateDataWrittenToVector(chartInstance, 17U);
                      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 64);
                      for (c11_i200 = 0; c11_i200 < 43; c11_i200++) {
                        c11_c_u[c11_i200] = c11_cv9[c11_i200];
                      }

                      c11_c_y = NULL;
                      sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_c_u, 10, 0U,
                        1U, 0U, 2, 1, 43), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c11_c_y);
                    }
                  }
                }
              }
            }
          }
        }

        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 66);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 17U, 37U);
        for (c11_i201 = 0; c11_i201 < 6; c11_i201++) {
          c11_a[c11_i201] = c11_eAmountFactor[c11_i201];
        }

        for (c11_i202 = 0; c11_i202 < 6; c11_i202++) {
          c11_eAmountFactor[c11_i202] = c11_a[c11_i202];
        }

        c11_updateDataWrittenToVector(chartInstance, 17U);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 68);
        if (CV_EML_IF(3, 1, 24, c11_Pt == 4.0)) {
          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 69);
          if (CV_EML_IF(3, 1, 25, c11_E == 1.0)) {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 70);
            for (c11_i203 = 0; c11_i203 < 6; c11_i203++) {
              c11_eAmountFactor[c11_i203] = c11_dv44[c11_i203];
            }

            c11_updateDataWrittenToVector(chartInstance, 17U);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 71);
            if (CV_EML_IF(3, 1, 26, c11_E == 2.0)) {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 72);
              for (c11_i204 = 0; c11_i204 < 6; c11_i204++) {
                c11_eAmountFactor[c11_i204] = c11_dv45[c11_i204];
              }

              c11_updateDataWrittenToVector(chartInstance, 17U);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 73);
              if (CV_EML_IF(3, 1, 27, c11_E == 3.0)) {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 74);
                for (c11_i205 = 0; c11_i205 < 6; c11_i205++) {
                  c11_eAmountFactor[c11_i205] = c11_dv46[c11_i205];
                }

                c11_updateDataWrittenToVector(chartInstance, 17U);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 75);
                if (CV_EML_IF(3, 1, 28, c11_E == 4.0)) {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 76);
                  for (c11_i206 = 0; c11_i206 < 6; c11_i206++) {
                    c11_eAmountFactor[c11_i206] = c11_dv47[c11_i206];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 17U);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 77);
                  if (CV_EML_IF(3, 1, 29, c11_E == 5.0)) {
                    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 78);
                    for (c11_i207 = 0; c11_i207 < 6; c11_i207++) {
                      c11_eAmountFactor[c11_i207] = c11_dv48[c11_i207];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 17U);
                  } else {
                    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 79);
                    if (CV_EML_IF(3, 1, 30, c11_E == 7.0)) {
                      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 80);
                      for (c11_i208 = 0; c11_i208 < 6; c11_i208++) {
                        c11_eAmountFactor[c11_i208] = c11_dv49[c11_i208];
                      }

                      c11_updateDataWrittenToVector(chartInstance, 17U);
                    } else {
                      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 81);
                      if (CV_EML_IF(3, 1, 31, c11_E == 8.0)) {
                        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 82);
                        for (c11_i209 = 0; c11_i209 < 6; c11_i209++) {
                          c11_eAmountFactor[c11_i209] = c11_dv50[c11_i209];
                        }

                        c11_updateDataWrittenToVector(chartInstance, 17U);
                      } else {
                        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 84);
                        for (c11_i210 = 0; c11_i210 < 6; c11_i210++) {
                          c11_eAmountFactor[c11_i210] = 0.0;
                        }

                        c11_updateDataWrittenToVector(chartInstance, 17U);
                        _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 85);
                        for (c11_i211 = 0; c11_i211 < 43; c11_i211++) {
                          c11_d_u[c11_i211] = c11_cv9[c11_i211];
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

          _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 87);
          c11_errorIfDataNotWrittenToFcn(chartInstance, 17U, 37U);
          for (c11_i212 = 0; c11_i212 < 6; c11_i212++) {
            c11_a[c11_i212] = c11_eAmountFactor[c11_i212];
          }

          for (c11_i213 = 0; c11_i213 < 6; c11_i213++) {
            c11_eAmountFactor[c11_i213] = c11_a[c11_i213];
          }

          c11_updateDataWrittenToVector(chartInstance, 17U);
        }
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, -87);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c11_EP_IdleRand_K_facialExpr(SimStruct *c11_S, real_T
  c11_bmlID, real_T *c11_p, real_T c11_poseBML[256])
{
  real_T c11_b_p;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_facialExprc11_EP_IdleRand_K(chartInstance, c11_bmlID, &c11_b_p,
    c11_poseBML);
  *c11_p = c11_b_p;
}

void sf_exported_user_c11_EP_IdleRand_K_insertQueue(SimStruct *c11_S, real_T
  c11_bmls[1280], real_T c11_myBML[256], real_T c11_newBmls[1280])
{
  int32_T c11_i214;
  real_T c11_b_bmls[1280];
  int32_T c11_i215;
  real_T c11_b_myBML[256];
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  for (c11_i214 = 0; c11_i214 < 1280; c11_i214++) {
    c11_b_bmls[c11_i214] = c11_bmls[c11_i214];
  }

  for (c11_i215 = 0; c11_i215 < 256; c11_i215++) {
    c11_b_myBML[c11_i215] = c11_myBML[c11_i215];
  }

  c11_insertQueuec11_EP_IdleRand_K(chartInstance, c11_b_bmls, c11_b_myBML,
    c11_newBmls);
}

void sf_exported_user_c11_EP_IdleRand_K_setAU(SimStruct *c11_S, real_T c11_E,
  real_T c11_AU[6], real_T *c11_L)
{
  real_T c11_b_L;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_setAUc11_EP_IdleRand_K(chartInstance, c11_E, c11_AU, &c11_b_L);
  *c11_L = c11_b_L;
}

void sf_exported_user_c11_EP_IdleRand_K_set_eAmountFactor(SimStruct *c11_S,
  real_T c11_E, real_T c11_Pt, real_T c11_eAmountFactor[6])
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_set_eAmountFactorc11_EP_IdleRand_K(chartInstance, c11_E, c11_Pt,
    c11_eAmountFactor);
}

void sf_exported_user_c11_EP_IdleRand_K_smileTable(SimStruct *c11_S, real_T
  c11_bmlID, real_T *c11_p, real_T c11_poseBML[256])
{
  real_T c11_b_p;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_smileTablec11_EP_IdleRand_K(chartInstance, c11_bmlID, &c11_b_p,
    c11_poseBML);
  *c11_p = c11_b_p;
}

static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int8_T c11_p_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int8_T c11_y;
  int8_T c11_i216;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i216, 1, 2, 0U, 0, 0U, 0);
  c11_y = c11_i216;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_secs;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int8_T c11_y;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_secs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_secs),
    &c11_thisId);
  sf_mex_destroy(&c11_secs);
  *(int8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_q_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i217;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i217, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i217;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_r_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_subSmile, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_subSmile),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_subSmile);
  return c11_y;
}

static uint8_T c11_s_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_subSmile;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)chartInstanceVoid;
  c11_b_tp_subSmile = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_subSmile),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_subSmile);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint16_T c11_t_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_b_temporalCounter_i1, const char_T
  *c11_identifier)
{
  uint16_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_u_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_temporalCounter_i1), &c11_thisId);
  sf_mex_destroy(&c11_b_temporalCounter_i1);
  return c11_y;
}

static uint16_T c11_u_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint16_T c11_y;
  uint16_T c11_u1;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u1, 1, 5, 0U, 0, 0U, 0);
  c11_y = c11_u1;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static const mxArray *c11_v_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_w_emlrt_marshallIn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  (void)c11_parentId;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_updateDataWrittenToVector(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex)
{
  (void)chartInstance;
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 17, 1, 0)] = true;
}

static void c11_errorIfDataNotWrittenToFcn(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex, uint32_T c11_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c11_dataNumber, c11_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c11_vectorIndex, 0, 17, 1,
    0)]);
}

static real_T c11_get_BML(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1016) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_BML_address)[c11_b];
}

static void c11_set_BML(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1016) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_BML_address)[c11_b] = c11_c;
}

static real_T *c11_access_BML(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1016) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_BML_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static real_T c11_get_GAZE_WIN(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1015) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_GAZE_WIN_address;
}

static void c11_set_GAZE_WIN(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1015) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_GAZE_WIN_address = c11_c;
}

static real_T *c11_access_GAZE_WIN(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1015) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_GAZE_WIN_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c11_c;
}

static real_T c11_get_P(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1017) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_P_address;
}

static void c11_set_P(SFc11_EP_IdleRand_KInstanceStruct *chartInstance, uint32_T
                      c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1017) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_P_address = c11_c;
}

static real_T *c11_access_P(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1017) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_P_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_BEFORE(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1022) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_BEFORE_address;
}

static void c11_set_STATE_BEFORE(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1022) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_BEFORE_address = c11_c;
}

static real_T *c11_access_STATE_BEFORE(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1022) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_BEFORE_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_GO(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1020) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_GO_address;
}

static void c11_set_STATE_GO(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1020) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_GO_address = c11_c;
}

static real_T *c11_access_STATE_GO(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1020) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_GO_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_READY(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1021) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_READY_address;
}

static void c11_set_STATE_READY(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1021) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_READY_address = c11_c;
}

static real_T *c11_access_STATE_READY(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1021) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_READY_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1013) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_address;
}

static void c11_set_avert(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1013) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_address = c11_c;
}

static real_T *c11_access_avert(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1013) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c11_c;
}

static real_T c11_get_bmlsM(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#1025) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_bmlsM_address)[c11_b];
}

static void c11_set_bmlsM(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#1025) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_bmlsM_address)[c11_b] = c11_c;
}

static real_T *c11_access_bmlsM(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#1025) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_bmlsM_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c11_c;
}

static real_T c11_get_changeFlag(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1023) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_changeFlag_address;
}

static void c11_set_changeFlag(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1023) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_changeFlag_address = c11_c;
}

static real_T *c11_access_changeFlag(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1023) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_changeFlag_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c11_c;
}

static real_T c11_get_gazing(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1014) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_gazing_address;
}

static void c11_set_gazing(SFc11_EP_IdleRand_KInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1014) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_gazing_address = c11_c;
}

static real_T *c11_access_gazing(SFc11_EP_IdleRand_KInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1014) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_gazing_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info(SFc11_EP_IdleRand_KInstanceStruct
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
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c11_bmlsM_address, &chartInstance->c11_bmlsM_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "changeFlag", (void **)
    &chartInstance->c11_changeFlag_address, &chartInstance->c11_changeFlag_index);
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

void sf_c11_EP_IdleRand_K_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3157562700U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1973940413U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3539250395U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2321053797U);
}

mxArray *sf_c11_EP_IdleRand_K_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nTMvNUkutCAieCgyZ3kVbE");
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[1] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_EP_IdleRand_K_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_EP_IdleRand_K_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_EP_IdleRand_K(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[61],T\"gameState\",},{M[3],M[79],T\"BMLM\",},{M[3],M[104],T\"au\",},{M[3],M[142],T\"au_L\",},{M[3],M[141],T\"au_i\",},{M[3],M[115],T\"eAmountF\",},{M[3],M[55],T\"fileID\",},{M[3],M[80],T\"n\",},{M[3],M[77],T\"newBmlsM\",},{M[3],M[10],T\"smileN\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c11_EP_IdleRand_K\",},{M[8],M[95],T\"is_active_subSmile\",},{M[8],M[116],T\"is_active_subFacial\",},{M[9],M[95],T\"is_subSmile\",},{M[9],M[116],T\"is_subFacial\",},{M[11],M[39],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M[139],M[1]}}},{M[11],M[39],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x2[81 67],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_EP_IdleRand_K_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EP_IdleRand_KMachineNumber_,
           11,
           16,
           17,
           0,
           39,
           1,
           0,
           0,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(12,11,0,0,"changeFlag");
          _SFD_SET_DATA_PROPS(13,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(14,11,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(15,0,0,0,"BMLM");
          _SFD_SET_DATA_PROPS(16,0,0,0,"n");
          _SFD_SET_DATA_PROPS(17,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(18,1,1,0,"internalE");
          _SFD_SET_DATA_PROPS(19,0,0,0,"au");
          _SFD_SET_DATA_PROPS(20,0,0,0,"eAmountF");
          _SFD_SET_DATA_PROPS(21,1,1,0,"emoChange");
          _SFD_SET_DATA_PROPS(22,0,0,0,"au_i");
          _SFD_SET_DATA_PROPS(23,0,0,0,"au_L");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,9,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,9,0,0,"");
          _SFD_SET_DATA_PROPS(30,8,0,0,"");
          _SFD_SET_DATA_PROPS(31,9,0,0,"");
          _SFD_SET_DATA_PROPS(32,9,0,0,"");
          _SFD_SET_DATA_PROPS(33,8,0,0,"");
          _SFD_SET_DATA_PROPS(34,9,0,0,"");
          _SFD_SET_DATA_PROPS(35,9,0,0,"");
          _SFD_SET_DATA_PROPS(36,8,0,0,"");
          _SFD_SET_DATA_PROPS(37,9,0,0,"");
          _SFD_SET_DATA_PROPS(38,8,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(5,0,1);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,1);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,10);
          _SFD_CH_SUBSTATE_INDEX(1,5);
          _SFD_ST_SUBSTATE_COUNT(10,5);
          _SFD_ST_SUBSTATE_INDEX(10,0,11);
          _SFD_ST_SUBSTATE_INDEX(10,1,12);
          _SFD_ST_SUBSTATE_INDEX(10,2,13);
          _SFD_ST_SUBSTATE_INDEX(10,3,14);
          _SFD_ST_SUBSTATE_INDEX(10,4,15);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(5,4);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_INDEX(5,2,8);
          _SFD_ST_SUBSTATE_INDEX(5,3,9);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
        }

        _SFD_CV_INIT_CHART(2,0,0,0);

        {
          _SFD_CV_INIT_STATE(5,4,1,1,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(10,5,1,1,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"insertQueuec11_EP_IdleRand_K",0,-1,565);
        _SFD_CV_INIT_EML_IF(1,1,0,126,151,-1,-2);
        _SFD_CV_INIT_EML_IF(1,1,1,296,307,-1,546);
        _SFD_CV_INIT_EML_FOR(1,1,0,106,118,291);
        _SFD_CV_INIT_EML(4,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"smileTablec11_EP_IdleRand_K",0,-1,404);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",404,-1,707);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",707,-1,899);
        _SFD_CV_INIT_EML_FCN(4,3,"aFcnTruthTableAction_3",899,-1,1198);
        _SFD_CV_INIT_EML_IF(4,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(4,1,1,289,323,354,402);
        _SFD_CV_INIT_EML(0,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"facialExprc11_EP_IdleRand_K",0,-1,404);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",404,-1,707);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",707,-1,899);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",899,-1,1198);
        _SFD_CV_INIT_EML_IF(0,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(0,1,1,289,323,354,402);
        _SFD_CV_INIT_EML(2,1,1,0,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"setAUc11_EP_IdleRand_K",0,-1,1966);

        {
          static int caseStart[] = { 1606, 776, 867, 995, 1138, 1243, 1339, 1426,
            1514 };

          static int caseExprEnd[] = { 1615, 782, 873, 1001, 1144, 1249, 1345,
            1432, 1520 };

          _SFD_CV_INIT_EML_SWITCH(2,1,0,758,767,1876,9,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_EML(3,1,1,32,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"set_eAmountFactorc11_EP_IdleRand_K",0,-1,3853);
        _SFD_CV_INIT_EML_IF(3,1,0,117,126,807,820);
        _SFD_CV_INIT_EML_IF(3,1,1,149,157,218,781);
        _SFD_CV_INIT_EML_IF(3,1,2,218,230,285,781);
        _SFD_CV_INIT_EML_IF(3,1,3,285,297,358,781);
        _SFD_CV_INIT_EML_IF(3,1,4,358,370,430,781);
        _SFD_CV_INIT_EML_IF(3,1,5,430,442,505,781);
        _SFD_CV_INIT_EML_IF(3,1,6,505,517,575,781);
        _SFD_CV_INIT_EML_IF(3,1,7,575,587,649,781);
        _SFD_CV_INIT_EML_IF(3,1,8,807,820,1479,2904);
        _SFD_CV_INIT_EML_IF(3,1,9,828,836,897,1460);
        _SFD_CV_INIT_EML_IF(3,1,10,897,909,964,1460);
        _SFD_CV_INIT_EML_IF(3,1,11,964,976,1037,1460);
        _SFD_CV_INIT_EML_IF(3,1,12,1037,1049,1109,1460);
        _SFD_CV_INIT_EML_IF(3,1,13,1109,1121,1184,1460);
        _SFD_CV_INIT_EML_IF(3,1,14,1184,1196,1254,1460);
        _SFD_CV_INIT_EML_IF(3,1,15,1254,1266,1328,1460);
        _SFD_CV_INIT_EML_IF(3,1,16,1479,1492,2197,2904);
        _SFD_CV_INIT_EML_IF(3,1,17,1501,1509,1570,2133);
        _SFD_CV_INIT_EML_IF(3,1,18,1570,1582,1637,2133);
        _SFD_CV_INIT_EML_IF(3,1,19,1637,1649,1710,2133);
        _SFD_CV_INIT_EML_IF(3,1,20,1710,1722,1782,2133);
        _SFD_CV_INIT_EML_IF(3,1,21,1782,1794,1857,2133);
        _SFD_CV_INIT_EML_IF(3,1,22,1857,1869,1927,2133);
        _SFD_CV_INIT_EML_IF(3,1,23,1927,1939,2001,2133);
        _SFD_CV_INIT_EML_IF(3,1,24,2197,2210,-1,2210);
        _SFD_CV_INIT_EML_IF(3,1,25,2219,2227,2288,2851);
        _SFD_CV_INIT_EML_IF(3,1,26,2288,2300,2355,2851);
        _SFD_CV_INIT_EML_IF(3,1,27,2355,2367,2428,2851);
        _SFD_CV_INIT_EML_IF(3,1,28,2428,2440,2500,2851);
        _SFD_CV_INIT_EML_IF(3,1,29,2500,2512,2575,2851);
        _SFD_CV_INIT_EML_IF(3,1,30,2575,2587,2645,2851);
        _SFD_CV_INIT_EML_IF(3,1,31,2645,2657,2719,2851);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_SCRIPT(1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"cmdBML_AU",0,-1,1346);
        _SFD_CV_INIT_SCRIPT_IF(1,0,460,494,830,1155);
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

        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,0,26,0,26);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,0,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

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
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,11,1,11);
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
          dimVector[0]= 256;
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
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)
            c11_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_k_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_k_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_k_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_k_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(36,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(37,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(38,(void *)(NULL));

        {
          real_T *c11_isSmiling;
          real_T *c11_gameState;
          real_T *c11_personality;
          real_T *c11_internalE;
          real_T *c11_emoChange;
          c11_emoChange = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
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
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c11_changeFlag_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c11_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(14U, *chartInstance->c11_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c11_BMLM);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c11_n);
          _SFD_SET_DATA_VALUE_PTR(17U, c11_personality);
          _SFD_SET_DATA_VALUE_PTR(18U, c11_internalE);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c11_au);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c11_eAmountF);
          _SFD_SET_DATA_VALUE_PTR(21U, c11_emoChange);
          _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c11_au_i);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c11_au_L);
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
  return "O0CATq6ZL656CCzSstgHK";
}

static void sf_opaque_initialize_c11_EP_IdleRand_K(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
  initialize_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_EP_IdleRand_K(void *chartInstanceVar)
{
  enable_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_EP_IdleRand_K(void *chartInstanceVar)
{
  disable_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_EP_IdleRand_K(void *chartInstanceVar)
{
  sf_gateway_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_EP_IdleRand_K(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_EP_IdleRand_K
    ((SFc11_EP_IdleRand_KInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_EP_IdleRand_K();/* state var info */
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

extern void sf_internal_set_sim_state_c11_EP_IdleRand_K(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_EP_IdleRand_K();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_EP_IdleRand_K(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c11_EP_IdleRand_K(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c11_EP_IdleRand_K(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_EP_IdleRand_KInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EP_IdleRand_K_optimization_info();
    }

    finalize_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
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
  initSimStructsc11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_EP_IdleRand_K(SimStruct *S)
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
    initialize_params_c11_EP_IdleRand_K((SFc11_EP_IdleRand_KInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_EP_IdleRand_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EP_IdleRand_K_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2205101963U));
  ssSetChecksum1(S,(865278400U));
  ssSetChecksum2(S,(132248201U));
  ssSetChecksum3(S,(3793222119U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_EP_IdleRand_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_EP_IdleRand_K(SimStruct *S)
{
  SFc11_EP_IdleRand_KInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_EP_IdleRand_KInstanceStruct *)utMalloc(sizeof
    (SFc11_EP_IdleRand_KInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_EP_IdleRand_KInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_EP_IdleRand_K;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_EP_IdleRand_K;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_EP_IdleRand_K;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_EP_IdleRand_K;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_EP_IdleRand_K;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_EP_IdleRand_K;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_EP_IdleRand_K;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_EP_IdleRand_K;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_EP_IdleRand_K;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_EP_IdleRand_K;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_EP_IdleRand_K;
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

void c11_EP_IdleRand_K_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_EP_IdleRand_K(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_EP_IdleRand_K(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_EP_IdleRand_K(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_EP_IdleRand_K_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
