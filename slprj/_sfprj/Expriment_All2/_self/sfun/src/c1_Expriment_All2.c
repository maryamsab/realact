/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_All2_sfun.h"
#include "c1_Expriment_All2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_All2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_Mid                      ((uint8_T)1U)
#define c1_IN_checkHighPriority        ((uint8_T)2U)
#define c1_IN_init                     ((uint8_T)3U)
#define c1_IN_low                      ((uint8_T)4U)
#define c1_IN_sendH                    ((uint8_T)5U)
#define c1_IN_sendL                    ((uint8_T)6U)
#define c1_IN_sendM                    ((uint8_T)7U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c1_subchartSimStateInfo;
static const mxArray *c1_b_subchartSimStateInfo;
static const mxArray *c1_c_subchartSimStateInfo;
static const mxArray *c1_d_subchartSimStateInfo;
static const mxArray *c1_e_subchartSimStateInfo;
static const mxArray *c1_f_subchartSimStateInfo;
static const mxArray *c1_g_subchartSimStateInfo;
static const mxArray *c1_h_subchartSimStateInfo;
static const mxArray *c1_i_subchartSimStateInfo;
static const mxArray *c1_j_subchartSimStateInfo;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_c_debug_family_names[4] = { "nargin", "nargout", "bmls",
  "newBmls" };

static const char * c1_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_f_debug_family_names[6] = { "tempp", "i", "nargin",
  "nargout", "bmls", "empty" };

static const char * c1_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[12];

/* Function Declarations */
static void initialize_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void initialize_params_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance);
static void enable_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void disable_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance);
static void set_sim_state_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance);
static void finalize_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void sf_gateway_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void c1_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void initSimStructsc1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void c1_sendBMLbyPriority(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void c1_enter_atomic_sendH(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void c1_enter_atomic_sendM(SFc1_Expriment_All2InstanceStruct
  *chartInstance);
static void c1_low(SFc1_Expriment_All2InstanceStruct *chartInstance);
static void c1_encStr2Arr(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_myarr256[1000]);
static boolean_T c1_isequal(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_varargin_1[1000], real_T c1_varargin_2[1000]);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_newBmls, const char_T *c1_identifier, real_T
  c1_y[5000]);
static void c1_e_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5000]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_f_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_removeQueue(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_bmls[5000], real_T c1_newBmls[5000]);
static real_T c1_isEmptyQueue(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_bmls[5000]);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int8_T c1_g_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_h_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_i_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_b_tp_RPS_Scenario, const char_T
  *c1_identifier);
static uint8_T c1_j_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_k_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_BML, const char_T *c1_identifier, real_T
  c1_y[1000]);
static void c1_l_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_m_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_emotion_amount_factor, const char_T
  *c1_identifier, real_T c1_y[11]);
static void c1_n_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[11]);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_o_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u);
static const mxArray *c1_p_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_k_subchartSimStateInfo, const char_T
  *c1_identifier);
static const mxArray *c1_q_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber);
static real_T c1_get_BML(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_BML(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BML(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_BML1(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_BML1(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BML1(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_BML2(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_BML2(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BML2(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_BORED(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_BORED(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BORED(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_BOREDOM_THRESHOLD(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_BOREDOM_THRESHOLD(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BOREDOM_THRESHOLD(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_CONTEMPT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_CONTEMPT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_CONTEMPT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_EXCITE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_EXCITE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_EXCITE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_FEAR(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_FEAR(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_FEAR(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_FRUST(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_FRUST(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_FRUST(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_GAZE_GUI(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_GAZE_GUI(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_GUI(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_GAZE_SOFTEYE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_GAZE_SOFTEYE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_SOFTEYE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_GAZE_USER_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_GAZE_USER_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_USER_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_GAZE_WIN(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_GAZE_WIN(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_WIN(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_HAPPY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_HAPPY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_HAPPY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_IDLE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_IDLE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_IDLE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_P(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_P(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c);
static real_T *c1_access_P(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_SAD(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_SAD(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_SAD(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_STATE_BEFORE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_BEFORE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_BEFORE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_GO(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_STATE_GO(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_GO(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_HAND(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_STATE_HAND(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_OVER(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_STATE_OVER(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_OVER(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_READY(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_READY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_READY(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_RESULT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_RESULT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_RESULT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_WAIT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_STATE_WAIT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_WAIT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_avert(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_avert(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_avertH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_avertH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avertH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_avert_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_avert_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_avert_gaze_dirs_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_avert_gaze_dirs_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert_gaze_dirs_chance
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_avert_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b);
static void c1_set_avert_gaze_duration_factor(SFc1_Expriment_All2InstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_avert_head_frequency_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b);
static void c1_set_avert_head_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert_head_frequency_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_avert_head_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_avert_head_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert_head_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_bHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_bHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_blink_flag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_blink_flag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_blink_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_blinkperiod_max(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_blinkperiod_max(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_blinkperiod_max(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_blinkperiod_min(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_blinkperiod_min(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_blinkperiod_min(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_bmlsH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_bmlsH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bmlsH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_bmlsL(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_bmlsL(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bmlsL(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_bmlsM(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_bmlsM(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bmlsM(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_bodyBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_bodyBusyFlag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bodyBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_boredom(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_boredom(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_boredom(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_diff(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_diff(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_diff(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_emotion_amount_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_emotion_amount_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_emotion_amount_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_faceBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_faceBusyFlag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_faceBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_fileID(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_fileID(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_fileID(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_gazing(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_gazing(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_gazing(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_interest(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_interest(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_interest(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_mut_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_mut_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_mut_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_mutual_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b);
static void c1_set_mutual_gaze_duration_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_mutual_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_n(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_n(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c);
static real_T *c1_access_n(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_pa(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_pa(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c);
static real_T *c1_access_pa(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_pose_cat_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose_cat_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_cat_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_chance_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose_chance_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_chance_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_change_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose_change_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_change_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_lean(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_pose_lean(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_lean(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_lean_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose_lean_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_lean_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_space(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_pose_space(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_space(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_speed(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_pose_speed(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose_twitch(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose_twitch(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose_twitch(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pr(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_pr(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c);
static real_T *c1_access_pr(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_r(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_r(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c);
static real_T *c1_access_r(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_randAvertGazeChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randAvertGazeChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randAvertGazeChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_randGazeDur(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randGazeDur(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randGazeDur(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_randPoseChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randPoseChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randPoseChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_randSlowPose(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randSlowPose(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randSlowPose(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_randSmile(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_randSmile(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randSmile(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_s(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_s(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c);
static real_T *c1_access_s(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_t(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_t(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c);
static real_T *c1_access_t(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_temp(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_temp(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_temp(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_uHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_uHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_uHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b);
static void init_dsm_address_info(SFc1_Expriment_All2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T *c1_gameState;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  real_T *c1_round;
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  sf_exported_auto_initc5_Expriment_All2(chartInstance->c1_subchartSimstruct);
  sf_exported_auto_initc8_Expriment_All2(chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_initc20_Expriment_All2(chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_initc57_Expriment_All2(chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_initc9_Expriment_All2(chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_initc4_Expriment_All2(chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_initc42_Expriment_All2(chartInstance->c1_g_subchartSimstruct);
  sf_exported_auto_initc11_Expriment_All2(chartInstance->c1_h_subchartSimstruct);
  sf_exported_auto_initc44_Expriment_All2(chartInstance->c1_i_subchartSimstruct);
  sf_exported_auto_initc10_Expriment_All2(chartInstance->c1_j_subchartSimstruct);
  _sfTime_ = sf_get_time(chartInstance->S);
  c1_subchartSimStateInfo = NULL;
  c1_b_subchartSimStateInfo = NULL;
  c1_c_subchartSimStateInfo = NULL;
  c1_d_subchartSimStateInfo = NULL;
  c1_e_subchartSimStateInfo = NULL;
  c1_f_subchartSimStateInfo = NULL;
  c1_g_subchartSimStateInfo = NULL;
  c1_h_subchartSimStateInfo = NULL;
  c1_i_subchartSimStateInfo = NULL;
  c1_j_subchartSimStateInfo = NULL;
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_Gaze_Controller = 0U;
  chartInstance->c1_tp_Gaze_Controller = 0U;
  chartInstance->c1_is_active_RPS_Scenario = 0U;
  chartInstance->c1_tp_RPS_Scenario = 0U;
  chartInstance->c1_is_active_attention_Controller = 0U;
  chartInstance->c1_tp_attention_Controller = 0U;
  chartInstance->c1_is_active_custom_Behavior_Factors = 0U;
  chartInstance->c1_tp_custom_Behavior_Factors = 0U;
  chartInstance->c1_is_active_emotion_Behavior_Factors = 0U;
  chartInstance->c1_tp_emotion_Behavior_Factors = 0U;
  chartInstance->c1_is_active_facialExpression_Controller = 0U;
  chartInstance->c1_tp_facialExpression_Controller = 0U;
  chartInstance->c1_is_active_idlePose_Controller = 0U;
  chartInstance->c1_tp_idlePose_Controller = 0U;
  chartInstance->c1_is_active_personalSpace_Controller = 0U;
  chartInstance->c1_tp_personalSpace_Controller = 0U;
  chartInstance->c1_is_active_personality_Behavior_Factors = 0U;
  chartInstance->c1_tp_personality_Behavior_Factors = 0U;
  chartInstance->c1_is_active_sendBMLbyPriority = 0U;
  chartInstance->c1_is_sendBMLbyPriority = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_sendBMLbyPriority = 0U;
  chartInstance->c1_tp_Mid = 0U;
  chartInstance->c1_tp_checkHighPriority = 0U;
  chartInstance->c1_tp_init = 0U;
  chartInstance->c1_tp_low = 0U;
  chartInstance->c1_tp_sendH = 0U;
  chartInstance->c1_tp_sendL = 0U;
  chartInstance->c1_tp_sendM = 0U;
  chartInstance->c1_is_active_wave_Controller = 0U;
  chartInstance->c1_tp_wave_Controller = 0U;
  chartInstance->c1_is_active_c1_Expriment_All2 = 0U;
  c1_set_temp(chartInstance, 0, 0.0);
  c1_set_diff(chartInstance, 0, 0.0);
  c1_set_uHand(chartInstance, 0, 0.0);
  c1_set_bHand(chartInstance, 0, 0.0);
  c1_set_randSmile(chartInstance, 0, 0.0);
  c1_set_boredom(chartInstance, 0, 0.0);
  c1_set_BOREDOM_THRESHOLD(chartInstance, 0, 0.0);
  c1_set_randAvertGazeChance(chartInstance, 0, 0.0);
  c1_set_randPoseChance(chartInstance, 0, 0.0);
  c1_set_interest(chartInstance, 0, 0.0);
  c1_set_r(chartInstance, 0, 0.0);
  c1_set_pa(chartInstance, 0, 0.0);
  c1_set_s(chartInstance, 0, 0.0);
  c1_set_randGazeDur(chartInstance, 0, 0.0);
  c1_set_P(chartInstance, 0, 0.0);
  c1_set_avert(chartInstance, 0, 0.0);
  c1_set_GAZE_GUI(chartInstance, 0, 0.0);
  c1_set_GAZE_SOFTEYE(chartInstance, 0, 0.0);
  c1_set_GAZE_USER_HAND(chartInstance, 0, 0.0);
  c1_set_STATE_READY(chartInstance, 0, 0.0);
  c1_set_STATE_GO(chartInstance, 0, 1.0);
  c1_set_STATE_HAND(chartInstance, 0, 2.0);
  c1_set_STATE_OVER(chartInstance, 0, 3.0);
  c1_set_gazing(chartInstance, 0, 0.0);
  c1_set_GAZE_WIN(chartInstance, 0, 0.0);
  c1_set_randSlowPose(chartInstance, 0, 0.0);
  c1_set_STATE_BEFORE(chartInstance, 0, 4.0);
  c1_set_STATE_RESULT(chartInstance, 0, 5.0);
  c1_set_STATE_WAIT(chartInstance, 0, 6.0);
  c1_set_HAPPY(chartInstance, 0, 4.0);
  c1_set_SAD(chartInstance, 0, 4.0);
  c1_set_CONTEMPT(chartInstance, 0, 4.0);
  c1_set_BORED(chartInstance, 0, 4.0);
  c1_set_FRUST(chartInstance, 0, 4.0);
  c1_set_FEAR(chartInstance, 0, 4.0);
  c1_set_IDLE(chartInstance, 0, 4.0);
  c1_set_EXCITE(chartInstance, 0, 4.0);
  for (c1_i0 = 0; c1_i0 < 1000; c1_i0++) {
    c1_set_BML(chartInstance, c1_i0, 0.0);
  }

  c1_set_pr(chartInstance, 0, 0.0);
  c1_set_fileID(chartInstance, 0, 0.0);
  for (c1_i1 = 0; c1_i1 < 1000; c1_i1++) {
    c1_set_BML2(chartInstance, c1_i1, 0.0);
  }

  for (c1_i2 = 0; c1_i2 < 1000; c1_i2++) {
    c1_set_BML1(chartInstance, c1_i2, 0.0);
  }

  c1_set_t(chartInstance, 0, 0.0);
  c1_set_bodyBusyFlag(chartInstance, 0, 0.0);
  for (c1_i3 = 0; c1_i3 < 1000; c1_i3++) {
    c1_set_n(chartInstance, c1_i3, 0.0);
  }

  for (c1_i4 = 0; c1_i4 < 5000; c1_i4++) {
    c1_set_bmlsL(chartInstance, c1_i4, 0.0);
  }

  for (c1_i5 = 0; c1_i5 < 5000; c1_i5++) {
    c1_set_bmlsH(chartInstance, c1_i5, 0.0);
  }

  for (c1_i6 = 0; c1_i6 < 5000; c1_i6++) {
    c1_set_bmlsM(chartInstance, c1_i6, 0.0);
  }

  c1_set_avertH(chartInstance, 0, 0.0);
  c1_set_faceBusyFlag(chartInstance, 0, 0.0);
  c1_set_mutual_gaze_duration_factor(chartInstance, 0, 0.0);
  c1_set_avert_gaze_duration_factor(chartInstance, 0, 0.0);
  c1_set_avert_head_frequency_factor(chartInstance, 0, 0.0);
  c1_set_avert_gaze_dirs_chance(chartInstance, 0, 0.0);
  c1_set_avert_head_speed(chartInstance, 0, 0.0);
  c1_set_pose_chance_factor(chartInstance, 0, 0.0);
  c1_set_pose_cat_chance(chartInstance, 0, 0.0);
  c1_set_pose_frequency_factor(chartInstance, 0, 0.0);
  c1_set_pose_speed(chartInstance, 0, 0.0);
  c1_set_pose_lean(chartInstance, 0, 0.0);
  c1_set_pose_lean_flag(chartInstance, 0, 0.0);
  c1_set_pose_change_flag(chartInstance, 0, 0.0);
  for (c1_i7 = 0; c1_i7 < 11; c1_i7++) {
    c1_set_emotion_amount_factor(chartInstance, c1_i7, 0.0);
  }

  c1_set_avert_freq_factor(chartInstance, 0, 0.0);
  c1_set_mut_freq_factor(chartInstance, 0, 0.0);
  c1_set_pose_twitch(chartInstance, 0, 0.0);
  c1_set_blink_flag(chartInstance, 0, 0.0);
  c1_set_blinkperiod_min(chartInstance, 0, 0.0);
  c1_set_blinkperiod_max(chartInstance, 0, 0.0);
  c1_set_pose_space(chartInstance, 0, 0.0);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c1_gameState = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c1_bradHand = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *c1_userHand = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *c1_win = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *c1_bWinT = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    *c1_uWinT = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 7) != 0)) {
    *c1_round = 0.0;
  }
}

static void initialize_params_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
    sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
  }

  if (chartInstance->c1_is_active_RPS_Scenario == 1U) {
    sf_exported_auto_enablec5_Expriment_All2(chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_personalSpace_Controller == 1U) {
    sf_exported_auto_enablec8_Expriment_All2
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_wave_Controller == 1U) {
    sf_exported_auto_enablec20_Expriment_All2
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_Gaze_Controller == 1U) {
    sf_exported_auto_enablec57_Expriment_All2
      (chartInstance->c1_d_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_facialExpression_Controller == 1U) {
    sf_exported_auto_enablec9_Expriment_All2
      (chartInstance->c1_e_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePose_Controller == 1U) {
    sf_exported_auto_enablec4_Expriment_All2
      (chartInstance->c1_f_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_personality_Behavior_Factors == 1U) {
    sf_exported_auto_enablec42_Expriment_All2
      (chartInstance->c1_g_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_emotion_Behavior_Factors == 1U) {
    sf_exported_auto_enablec11_Expriment_All2
      (chartInstance->c1_h_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_custom_Behavior_Factors == 1U) {
    sf_exported_auto_enablec44_Expriment_All2
      (chartInstance->c1_i_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_attention_Controller == 1U) {
    sf_exported_auto_enablec10_Expriment_All2
      (chartInstance->c1_j_subchartSimstruct);
  }
}

static void disable_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
    sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
  }

  if (chartInstance->c1_is_active_RPS_Scenario == 1U) {
    sf_exported_auto_disablec5_Expriment_All2
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_personalSpace_Controller == 1U) {
    sf_exported_auto_disablec8_Expriment_All2
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_wave_Controller == 1U) {
    sf_exported_auto_disablec20_Expriment_All2
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_Gaze_Controller == 1U) {
    sf_exported_auto_disablec57_Expriment_All2
      (chartInstance->c1_d_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_facialExpression_Controller == 1U) {
    sf_exported_auto_disablec9_Expriment_All2
      (chartInstance->c1_e_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePose_Controller == 1U) {
    sf_exported_auto_disablec4_Expriment_All2
      (chartInstance->c1_f_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_personality_Behavior_Factors == 1U) {
    sf_exported_auto_disablec42_Expriment_All2
      (chartInstance->c1_g_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_emotion_Behavior_Factors == 1U) {
    sf_exported_auto_disablec11_Expriment_All2
      (chartInstance->c1_h_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_custom_Behavior_Factors == 1U) {
    sf_exported_auto_disablec44_Expriment_All2
      (chartInstance->c1_i_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_attention_Controller == 1U) {
    sf_exported_auto_disablec10_Expriment_All2
      (chartInstance->c1_j_subchartSimstruct);
  }
}

static void c1_update_debugger_state_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_Expriment_All2 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_RPS_Scenario == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_personalSpace_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_wave_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Gaze_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_facialExpression_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_idlePose_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_personality_Behavior_Factors == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_emotion_Behavior_Factors == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_custom_Behavior_Factors == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_attention_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_sendH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_checkHighPriority) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_sendM) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_Mid) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_sendL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_low) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  int32_T c1_i8;
  real_T c1_h_u[1000];
  const mxArray *c1_i_y = NULL;
  int32_T c1_i9;
  real_T c1_i_u[1000];
  const mxArray *c1_j_y = NULL;
  int32_T c1_i10;
  real_T c1_j_u[1000];
  const mxArray *c1_k_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  real_T c1_l_hoistedGlobal;
  real_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_m_hoistedGlobal;
  real_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_n_hoistedGlobal;
  real_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_o_hoistedGlobal;
  real_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_p_hoistedGlobal;
  real_T c1_s_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_q_hoistedGlobal;
  real_T c1_t_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_r_hoistedGlobal;
  real_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_s_hoistedGlobal;
  real_T c1_v_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_t_hoistedGlobal;
  real_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_u_hoistedGlobal;
  real_T c1_x_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_v_hoistedGlobal;
  real_T c1_y_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_w_hoistedGlobal;
  real_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  real_T c1_x_hoistedGlobal;
  real_T c1_bb_u;
  const mxArray *c1_cb_y = NULL;
  real_T c1_y_hoistedGlobal;
  real_T c1_cb_u;
  const mxArray *c1_db_y = NULL;
  real_T c1_ab_hoistedGlobal;
  real_T c1_db_u;
  const mxArray *c1_eb_y = NULL;
  real_T c1_bb_hoistedGlobal;
  real_T c1_eb_u;
  const mxArray *c1_fb_y = NULL;
  real_T c1_cb_hoistedGlobal;
  real_T c1_fb_u;
  const mxArray *c1_gb_y = NULL;
  real_T c1_db_hoistedGlobal;
  real_T c1_gb_u;
  const mxArray *c1_hb_y = NULL;
  real_T c1_eb_hoistedGlobal;
  real_T c1_hb_u;
  const mxArray *c1_ib_y = NULL;
  real_T c1_fb_hoistedGlobal;
  real_T c1_ib_u;
  const mxArray *c1_jb_y = NULL;
  real_T c1_gb_hoistedGlobal;
  real_T c1_jb_u;
  const mxArray *c1_kb_y = NULL;
  real_T c1_hb_hoistedGlobal;
  real_T c1_kb_u;
  const mxArray *c1_lb_y = NULL;
  real_T c1_ib_hoistedGlobal;
  real_T c1_lb_u;
  const mxArray *c1_mb_y = NULL;
  real_T c1_jb_hoistedGlobal;
  real_T c1_mb_u;
  const mxArray *c1_nb_y = NULL;
  real_T c1_kb_hoistedGlobal;
  real_T c1_nb_u;
  const mxArray *c1_ob_y = NULL;
  real_T c1_lb_hoistedGlobal;
  real_T c1_ob_u;
  const mxArray *c1_pb_y = NULL;
  real_T c1_mb_hoistedGlobal;
  real_T c1_pb_u;
  const mxArray *c1_qb_y = NULL;
  real_T c1_nb_hoistedGlobal;
  real_T c1_qb_u;
  const mxArray *c1_rb_y = NULL;
  int32_T c1_i11;
  static real_T c1_rb_u[5000];
  const mxArray *c1_sb_y = NULL;
  int32_T c1_i12;
  static real_T c1_sb_u[5000];
  const mxArray *c1_tb_y = NULL;
  int32_T c1_i13;
  real_T c1_tb_u[5000];
  const mxArray *c1_ub_y = NULL;
  real_T c1_ob_hoistedGlobal;
  real_T c1_ub_u;
  const mxArray *c1_vb_y = NULL;
  real_T c1_pb_hoistedGlobal;
  real_T c1_vb_u;
  const mxArray *c1_wb_y = NULL;
  real_T c1_qb_hoistedGlobal;
  real_T c1_wb_u;
  const mxArray *c1_xb_y = NULL;
  int32_T c1_i14;
  real_T c1_xb_u[11];
  const mxArray *c1_yb_y = NULL;
  real_T c1_rb_hoistedGlobal;
  real_T c1_yb_u;
  const mxArray *c1_ac_y = NULL;
  real_T c1_sb_hoistedGlobal;
  real_T c1_ac_u;
  const mxArray *c1_bc_y = NULL;
  real_T c1_tb_hoistedGlobal;
  real_T c1_bc_u;
  const mxArray *c1_cc_y = NULL;
  real_T c1_ub_hoistedGlobal;
  real_T c1_cc_u;
  const mxArray *c1_dc_y = NULL;
  real_T c1_vb_hoistedGlobal;
  real_T c1_dc_u;
  const mxArray *c1_ec_y = NULL;
  real_T c1_wb_hoistedGlobal;
  real_T c1_ec_u;
  const mxArray *c1_fc_y = NULL;
  real_T c1_xb_hoistedGlobal;
  real_T c1_fc_u;
  const mxArray *c1_gc_y = NULL;
  real_T c1_yb_hoistedGlobal;
  real_T c1_gc_u;
  const mxArray *c1_hc_y = NULL;
  real_T c1_ac_hoistedGlobal;
  real_T c1_hc_u;
  const mxArray *c1_ic_y = NULL;
  int32_T c1_i15;
  real_T c1_ic_u[1000];
  const mxArray *c1_jc_y = NULL;
  real_T c1_bc_hoistedGlobal;
  real_T c1_jc_u;
  const mxArray *c1_kc_y = NULL;
  int32_T c1_i16;
  real_T c1_kc_u[5000];
  const mxArray *c1_lc_y = NULL;
  int32_T c1_i17;
  real_T c1_lc_u[5000];
  const mxArray *c1_mc_y = NULL;
  int32_T c1_i18;
  real_T c1_mc_u[5000];
  const mxArray *c1_nc_y = NULL;
  real_T c1_cc_hoistedGlobal;
  real_T c1_nc_u;
  const mxArray *c1_oc_y = NULL;
  real_T c1_dc_hoistedGlobal;
  real_T c1_oc_u;
  const mxArray *c1_pc_y = NULL;
  real_T c1_ec_hoistedGlobal;
  real_T c1_pc_u;
  const mxArray *c1_qc_y = NULL;
  real_T c1_fc_hoistedGlobal;
  real_T c1_qc_u;
  const mxArray *c1_rc_y = NULL;
  real_T c1_gc_hoistedGlobal;
  real_T c1_rc_u;
  const mxArray *c1_sc_y = NULL;
  real_T c1_hc_hoistedGlobal;
  real_T c1_sc_u;
  const mxArray *c1_tc_y = NULL;
  real_T c1_ic_hoistedGlobal;
  real_T c1_tc_u;
  const mxArray *c1_uc_y = NULL;
  real_T c1_jc_hoistedGlobal;
  real_T c1_uc_u;
  const mxArray *c1_vc_y = NULL;
  real_T c1_kc_hoistedGlobal;
  real_T c1_vc_u;
  const mxArray *c1_wc_y = NULL;
  real_T c1_lc_hoistedGlobal;
  real_T c1_wc_u;
  const mxArray *c1_xc_y = NULL;
  real_T c1_mc_hoistedGlobal;
  real_T c1_xc_u;
  const mxArray *c1_yc_y = NULL;
  real_T c1_nc_hoistedGlobal;
  real_T c1_yc_u;
  const mxArray *c1_ad_y = NULL;
  real_T c1_oc_hoistedGlobal;
  real_T c1_ad_u;
  const mxArray *c1_bd_y = NULL;
  real_T c1_pc_hoistedGlobal;
  real_T c1_bd_u;
  const mxArray *c1_cd_y = NULL;
  real_T c1_qc_hoistedGlobal;
  real_T c1_cd_u;
  const mxArray *c1_dd_y = NULL;
  real_T c1_rc_hoistedGlobal;
  real_T c1_dd_u;
  const mxArray *c1_ed_y = NULL;
  real_T c1_sc_hoistedGlobal;
  real_T c1_ed_u;
  const mxArray *c1_fd_y = NULL;
  real_T c1_tc_hoistedGlobal;
  real_T c1_fd_u;
  const mxArray *c1_gd_y = NULL;
  real_T c1_uc_hoistedGlobal;
  real_T c1_gd_u;
  const mxArray *c1_hd_y = NULL;
  real_T c1_vc_hoistedGlobal;
  real_T c1_hd_u;
  const mxArray *c1_id_y = NULL;
  real_T c1_wc_hoistedGlobal;
  real_T c1_id_u;
  const mxArray *c1_jd_y = NULL;
  real_T c1_xc_hoistedGlobal;
  real_T c1_jd_u;
  const mxArray *c1_kd_y = NULL;
  real_T c1_yc_hoistedGlobal;
  real_T c1_kd_u;
  const mxArray *c1_ld_y = NULL;
  real_T c1_ad_hoistedGlobal;
  real_T c1_ld_u;
  const mxArray *c1_md_y = NULL;
  uint8_T c1_bd_hoistedGlobal;
  uint8_T c1_md_u;
  const mxArray *c1_nd_y = NULL;
  uint8_T c1_cd_hoistedGlobal;
  uint8_T c1_nd_u;
  const mxArray *c1_od_y = NULL;
  uint8_T c1_dd_hoistedGlobal;
  uint8_T c1_od_u;
  const mxArray *c1_pd_y = NULL;
  uint8_T c1_ed_hoistedGlobal;
  uint8_T c1_pd_u;
  const mxArray *c1_qd_y = NULL;
  uint8_T c1_fd_hoistedGlobal;
  uint8_T c1_qd_u;
  const mxArray *c1_rd_y = NULL;
  uint8_T c1_gd_hoistedGlobal;
  uint8_T c1_rd_u;
  const mxArray *c1_sd_y = NULL;
  uint8_T c1_hd_hoistedGlobal;
  uint8_T c1_sd_u;
  const mxArray *c1_td_y = NULL;
  uint8_T c1_id_hoistedGlobal;
  uint8_T c1_td_u;
  const mxArray *c1_ud_y = NULL;
  uint8_T c1_jd_hoistedGlobal;
  uint8_T c1_ud_u;
  const mxArray *c1_vd_y = NULL;
  uint8_T c1_kd_hoistedGlobal;
  uint8_T c1_vd_u;
  const mxArray *c1_wd_y = NULL;
  uint8_T c1_ld_hoistedGlobal;
  uint8_T c1_wd_u;
  const mxArray *c1_xd_y = NULL;
  uint8_T c1_md_hoistedGlobal;
  uint8_T c1_xd_u;
  const mxArray *c1_yd_y = NULL;
  uint8_T c1_nd_hoistedGlobal;
  uint8_T c1_yd_u;
  const mxArray *c1_ae_y = NULL;
  const mxArray *c1_ae_u;
  const mxArray *c1_be_y = NULL;
  const mxArray *c1_be_u;
  const mxArray *c1_ce_y = NULL;
  const mxArray *c1_ce_u;
  const mxArray *c1_de_y = NULL;
  const mxArray *c1_de_u;
  const mxArray *c1_ee_y = NULL;
  const mxArray *c1_ee_u;
  const mxArray *c1_fe_y = NULL;
  const mxArray *c1_fe_u;
  const mxArray *c1_ge_y = NULL;
  const mxArray *c1_ge_u;
  const mxArray *c1_he_y = NULL;
  const mxArray *c1_he_u;
  const mxArray *c1_ie_y = NULL;
  const mxArray *c1_ie_u;
  const mxArray *c1_je_y = NULL;
  const mxArray *c1_je_u;
  const mxArray *c1_ke_y = NULL;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_round;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_subchartSimStateInfo,
                sf_exported_auto_getSimstatec5_Expriment_All2
                (chartInstance->c1_subchartSimstruct), true);
  sf_mex_assign(&c1_b_subchartSimStateInfo,
                sf_exported_auto_getSimstatec8_Expriment_All2
                (chartInstance->c1_b_subchartSimstruct), true);
  sf_mex_assign(&c1_c_subchartSimStateInfo,
                sf_exported_auto_getSimstatec20_Expriment_All2
                (chartInstance->c1_c_subchartSimstruct), true);
  sf_mex_assign(&c1_d_subchartSimStateInfo,
                sf_exported_auto_getSimstatec57_Expriment_All2
                (chartInstance->c1_d_subchartSimstruct), true);
  sf_mex_assign(&c1_e_subchartSimStateInfo,
                sf_exported_auto_getSimstatec9_Expriment_All2
                (chartInstance->c1_e_subchartSimstruct), true);
  sf_mex_assign(&c1_f_subchartSimStateInfo,
                sf_exported_auto_getSimstatec4_Expriment_All2
                (chartInstance->c1_f_subchartSimstruct), true);
  sf_mex_assign(&c1_g_subchartSimStateInfo,
                sf_exported_auto_getSimstatec42_Expriment_All2
                (chartInstance->c1_g_subchartSimstruct), true);
  sf_mex_assign(&c1_h_subchartSimStateInfo,
                sf_exported_auto_getSimstatec11_Expriment_All2
                (chartInstance->c1_h_subchartSimstruct), true);
  sf_mex_assign(&c1_i_subchartSimStateInfo,
                sf_exported_auto_getSimstatec44_Expriment_All2
                (chartInstance->c1_i_subchartSimstruct), true);
  sf_mex_assign(&c1_j_subchartSimStateInfo,
                sf_exported_auto_getSimstatec10_Expriment_All2
                (chartInstance->c1_j_subchartSimstruct), true);
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(110, 1), false);
  c1_hoistedGlobal = *c1_bWinT;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_bradHand;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_gameState;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_round;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_uWinT;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_userHand;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *c1_win;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  for (c1_i8 = 0; c1_i8 < 1000; c1_i8++) {
    c1_h_u[c1_i8] = c1_get_BML(chartInstance, c1_i8);
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  for (c1_i9 = 0; c1_i9 < 1000; c1_i9++) {
    c1_i_u[c1_i9] = c1_get_BML1(chartInstance, c1_i9);
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_i_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  for (c1_i10 = 0; c1_i10 < 1000; c1_i10++) {
    c1_j_u[c1_i10] = c1_get_BML2(chartInstance, c1_i10);
  }

  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_j_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_h_hoistedGlobal = c1_get_BORED(chartInstance, 0);
  c1_k_u = c1_h_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_i_hoistedGlobal = c1_get_BOREDOM_THRESHOLD(chartInstance, 0);
  c1_l_u = c1_i_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_j_hoistedGlobal = c1_get_CONTEMPT(chartInstance, 0);
  c1_m_u = c1_j_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_k_hoistedGlobal = c1_get_EXCITE(chartInstance, 0);
  c1_n_u = c1_k_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_l_hoistedGlobal = c1_get_FEAR(chartInstance, 0);
  c1_o_u = c1_l_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_m_hoistedGlobal = c1_get_FRUST(chartInstance, 0);
  c1_p_u = c1_m_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_n_hoistedGlobal = c1_get_GAZE_GUI(chartInstance, 0);
  c1_q_u = c1_n_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_o_hoistedGlobal = c1_get_GAZE_SOFTEYE(chartInstance, 0);
  c1_r_u = c1_o_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_p_hoistedGlobal = c1_get_GAZE_USER_HAND(chartInstance, 0);
  c1_s_u = c1_p_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_q_hoistedGlobal = c1_get_GAZE_WIN(chartInstance, 0);
  c1_t_u = c1_q_hoistedGlobal;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_r_hoistedGlobal = c1_get_HAPPY(chartInstance, 0);
  c1_u_u = c1_r_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_s_hoistedGlobal = c1_get_IDLE(chartInstance, 0);
  c1_v_u = c1_s_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_t_hoistedGlobal = c1_get_P(chartInstance, 0);
  c1_w_u = c1_t_hoistedGlobal;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_u_hoistedGlobal = c1_get_SAD(chartInstance, 0);
  c1_x_u = c1_u_hoistedGlobal;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_v_hoistedGlobal = c1_get_STATE_BEFORE(chartInstance, 0);
  c1_y_u = c1_v_hoistedGlobal;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_w_hoistedGlobal = c1_get_STATE_GO(chartInstance, 0);
  c1_ab_u = c1_w_hoistedGlobal;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_x_hoistedGlobal = c1_get_STATE_HAND(chartInstance, 0);
  c1_bb_u = c1_x_hoistedGlobal;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 26, c1_cb_y);
  c1_y_hoistedGlobal = c1_get_STATE_OVER(chartInstance, 0);
  c1_cb_u = c1_y_hoistedGlobal;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_cb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 27, c1_db_y);
  c1_ab_hoistedGlobal = c1_get_STATE_READY(chartInstance, 0);
  c1_db_u = c1_ab_hoistedGlobal;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_bb_hoistedGlobal = c1_get_STATE_RESULT(chartInstance, 0);
  c1_eb_u = c1_bb_hoistedGlobal;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_eb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 29, c1_fb_y);
  c1_cb_hoistedGlobal = c1_get_STATE_WAIT(chartInstance, 0);
  c1_fb_u = c1_cb_hoistedGlobal;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_fb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 30, c1_gb_y);
  c1_db_hoistedGlobal = c1_get_avert(chartInstance, 0);
  c1_gb_u = c1_db_hoistedGlobal;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_gb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 31, c1_hb_y);
  c1_eb_hoistedGlobal = c1_get_avertH(chartInstance, 0);
  c1_hb_u = c1_eb_hoistedGlobal;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_hb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 32, c1_ib_y);
  c1_fb_hoistedGlobal = c1_get_avert_freq_factor(chartInstance, 0);
  c1_ib_u = c1_fb_hoistedGlobal;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_ib_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 33, c1_jb_y);
  c1_gb_hoistedGlobal = c1_get_avert_gaze_dirs_chance(chartInstance, 0);
  c1_jb_u = c1_gb_hoistedGlobal;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_jb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 34, c1_kb_y);
  c1_hb_hoistedGlobal = c1_get_avert_gaze_duration_factor(chartInstance, 0);
  c1_kb_u = c1_hb_hoistedGlobal;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_kb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 35, c1_lb_y);
  c1_ib_hoistedGlobal = c1_get_avert_head_frequency_factor(chartInstance, 0);
  c1_lb_u = c1_ib_hoistedGlobal;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_lb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 36, c1_mb_y);
  c1_jb_hoistedGlobal = c1_get_avert_head_speed(chartInstance, 0);
  c1_mb_u = c1_jb_hoistedGlobal;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", &c1_mb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 37, c1_nb_y);
  c1_kb_hoistedGlobal = c1_get_bHand(chartInstance, 0);
  c1_nb_u = c1_kb_hoistedGlobal;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_nb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 38, c1_ob_y);
  c1_lb_hoistedGlobal = c1_get_blink_flag(chartInstance, 0);
  c1_ob_u = c1_lb_hoistedGlobal;
  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", &c1_ob_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 39, c1_pb_y);
  c1_mb_hoistedGlobal = c1_get_blinkperiod_max(chartInstance, 0);
  c1_pb_u = c1_mb_hoistedGlobal;
  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", &c1_pb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 40, c1_qb_y);
  c1_nb_hoistedGlobal = c1_get_blinkperiod_min(chartInstance, 0);
  c1_qb_u = c1_nb_hoistedGlobal;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_qb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 41, c1_rb_y);
  for (c1_i11 = 0; c1_i11 < 5000; c1_i11++) {
    c1_rb_u[c1_i11] = c1_get_bmlsH(chartInstance, c1_i11);
  }

  c1_sb_y = NULL;
  sf_mex_assign(&c1_sb_y, sf_mex_create("y", c1_rb_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c1_y, 42, c1_sb_y);
  for (c1_i12 = 0; c1_i12 < 5000; c1_i12++) {
    c1_sb_u[c1_i12] = c1_get_bmlsL(chartInstance, c1_i12);
  }

  c1_tb_y = NULL;
  sf_mex_assign(&c1_tb_y, sf_mex_create("y", c1_sb_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c1_y, 43, c1_tb_y);
  for (c1_i13 = 0; c1_i13 < 5000; c1_i13++) {
    c1_tb_u[c1_i13] = c1_get_bmlsM(chartInstance, c1_i13);
  }

  c1_ub_y = NULL;
  sf_mex_assign(&c1_ub_y, sf_mex_create("y", c1_tb_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c1_y, 44, c1_ub_y);
  c1_ob_hoistedGlobal = c1_get_bodyBusyFlag(chartInstance, 0);
  c1_ub_u = c1_ob_hoistedGlobal;
  c1_vb_y = NULL;
  sf_mex_assign(&c1_vb_y, sf_mex_create("y", &c1_ub_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 45, c1_vb_y);
  c1_pb_hoistedGlobal = c1_get_boredom(chartInstance, 0);
  c1_vb_u = c1_pb_hoistedGlobal;
  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", &c1_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 46, c1_wb_y);
  c1_qb_hoistedGlobal = c1_get_diff(chartInstance, 0);
  c1_wb_u = c1_qb_hoistedGlobal;
  c1_xb_y = NULL;
  sf_mex_assign(&c1_xb_y, sf_mex_create("y", &c1_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 47, c1_xb_y);
  for (c1_i14 = 0; c1_i14 < 11; c1_i14++) {
    c1_xb_u[c1_i14] = c1_get_emotion_amount_factor(chartInstance, c1_i14);
  }

  c1_yb_y = NULL;
  sf_mex_assign(&c1_yb_y, sf_mex_create("y", c1_xb_u, 0, 0U, 1U, 0U, 2, 1, 11),
                false);
  sf_mex_setcell(c1_y, 48, c1_yb_y);
  c1_rb_hoistedGlobal = c1_get_faceBusyFlag(chartInstance, 0);
  c1_yb_u = c1_rb_hoistedGlobal;
  c1_ac_y = NULL;
  sf_mex_assign(&c1_ac_y, sf_mex_create("y", &c1_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 49, c1_ac_y);
  c1_sb_hoistedGlobal = c1_get_fileID(chartInstance, 0);
  c1_ac_u = c1_sb_hoistedGlobal;
  c1_bc_y = NULL;
  sf_mex_assign(&c1_bc_y, sf_mex_create("y", &c1_ac_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 50, c1_bc_y);
  c1_tb_hoistedGlobal = c1_get_gazing(chartInstance, 0);
  c1_bc_u = c1_tb_hoistedGlobal;
  c1_cc_y = NULL;
  sf_mex_assign(&c1_cc_y, sf_mex_create("y", &c1_bc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 51, c1_cc_y);
  c1_ub_hoistedGlobal = chartInstance->c1_hEmpty;
  c1_cc_u = c1_ub_hoistedGlobal;
  c1_dc_y = NULL;
  sf_mex_assign(&c1_dc_y, sf_mex_create("y", &c1_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 52, c1_dc_y);
  c1_vb_hoistedGlobal = c1_get_interest(chartInstance, 0);
  c1_dc_u = c1_vb_hoistedGlobal;
  c1_ec_y = NULL;
  sf_mex_assign(&c1_ec_y, sf_mex_create("y", &c1_dc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 53, c1_ec_y);
  c1_wb_hoistedGlobal = chartInstance->c1_lEmpty;
  c1_ec_u = c1_wb_hoistedGlobal;
  c1_fc_y = NULL;
  sf_mex_assign(&c1_fc_y, sf_mex_create("y", &c1_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 54, c1_fc_y);
  c1_xb_hoistedGlobal = chartInstance->c1_mEmpty;
  c1_fc_u = c1_xb_hoistedGlobal;
  c1_gc_y = NULL;
  sf_mex_assign(&c1_gc_y, sf_mex_create("y", &c1_fc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 55, c1_gc_y);
  c1_yb_hoistedGlobal = c1_get_mut_freq_factor(chartInstance, 0);
  c1_gc_u = c1_yb_hoistedGlobal;
  c1_hc_y = NULL;
  sf_mex_assign(&c1_hc_y, sf_mex_create("y", &c1_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 56, c1_hc_y);
  c1_ac_hoistedGlobal = c1_get_mutual_gaze_duration_factor(chartInstance, 0);
  c1_hc_u = c1_ac_hoistedGlobal;
  c1_ic_y = NULL;
  sf_mex_assign(&c1_ic_y, sf_mex_create("y", &c1_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 57, c1_ic_y);
  for (c1_i15 = 0; c1_i15 < 1000; c1_i15++) {
    c1_ic_u[c1_i15] = c1_get_n(chartInstance, c1_i15);
  }

  c1_jc_y = NULL;
  sf_mex_assign(&c1_jc_y, sf_mex_create("y", c1_ic_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c1_y, 58, c1_jc_y);
  c1_bc_hoistedGlobal = chartInstance->c1_newBmlA;
  c1_jc_u = c1_bc_hoistedGlobal;
  c1_kc_y = NULL;
  sf_mex_assign(&c1_kc_y, sf_mex_create("y", &c1_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 59, c1_kc_y);
  for (c1_i16 = 0; c1_i16 < 5000; c1_i16++) {
    c1_kc_u[c1_i16] = chartInstance->c1_newBmlsH[c1_i16];
  }

  c1_lc_y = NULL;
  sf_mex_assign(&c1_lc_y, sf_mex_create("y", c1_kc_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c1_y, 60, c1_lc_y);
  for (c1_i17 = 0; c1_i17 < 5000; c1_i17++) {
    c1_lc_u[c1_i17] = chartInstance->c1_newBmlsL[c1_i17];
  }

  c1_mc_y = NULL;
  sf_mex_assign(&c1_mc_y, sf_mex_create("y", c1_lc_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c1_y, 61, c1_mc_y);
  for (c1_i18 = 0; c1_i18 < 5000; c1_i18++) {
    c1_mc_u[c1_i18] = chartInstance->c1_newBmlsM[c1_i18];
  }

  c1_nc_y = NULL;
  sf_mex_assign(&c1_nc_y, sf_mex_create("y", c1_mc_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c1_y, 62, c1_nc_y);
  c1_cc_hoistedGlobal = c1_get_pa(chartInstance, 0);
  c1_nc_u = c1_cc_hoistedGlobal;
  c1_oc_y = NULL;
  sf_mex_assign(&c1_oc_y, sf_mex_create("y", &c1_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 63, c1_oc_y);
  c1_dc_hoistedGlobal = c1_get_pose_cat_chance(chartInstance, 0);
  c1_oc_u = c1_dc_hoistedGlobal;
  c1_pc_y = NULL;
  sf_mex_assign(&c1_pc_y, sf_mex_create("y", &c1_oc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 64, c1_pc_y);
  c1_ec_hoistedGlobal = c1_get_pose_chance_factor(chartInstance, 0);
  c1_pc_u = c1_ec_hoistedGlobal;
  c1_qc_y = NULL;
  sf_mex_assign(&c1_qc_y, sf_mex_create("y", &c1_pc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 65, c1_qc_y);
  c1_fc_hoistedGlobal = c1_get_pose_change_flag(chartInstance, 0);
  c1_qc_u = c1_fc_hoistedGlobal;
  c1_rc_y = NULL;
  sf_mex_assign(&c1_rc_y, sf_mex_create("y", &c1_qc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 66, c1_rc_y);
  c1_gc_hoistedGlobal = c1_get_pose_frequency_factor(chartInstance, 0);
  c1_rc_u = c1_gc_hoistedGlobal;
  c1_sc_y = NULL;
  sf_mex_assign(&c1_sc_y, sf_mex_create("y", &c1_rc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 67, c1_sc_y);
  c1_hc_hoistedGlobal = c1_get_pose_lean(chartInstance, 0);
  c1_sc_u = c1_hc_hoistedGlobal;
  c1_tc_y = NULL;
  sf_mex_assign(&c1_tc_y, sf_mex_create("y", &c1_sc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 68, c1_tc_y);
  c1_ic_hoistedGlobal = c1_get_pose_lean_flag(chartInstance, 0);
  c1_tc_u = c1_ic_hoistedGlobal;
  c1_uc_y = NULL;
  sf_mex_assign(&c1_uc_y, sf_mex_create("y", &c1_tc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 69, c1_uc_y);
  c1_jc_hoistedGlobal = c1_get_pose_space(chartInstance, 0);
  c1_uc_u = c1_jc_hoistedGlobal;
  c1_vc_y = NULL;
  sf_mex_assign(&c1_vc_y, sf_mex_create("y", &c1_uc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 70, c1_vc_y);
  c1_kc_hoistedGlobal = c1_get_pose_speed(chartInstance, 0);
  c1_vc_u = c1_kc_hoistedGlobal;
  c1_wc_y = NULL;
  sf_mex_assign(&c1_wc_y, sf_mex_create("y", &c1_vc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 71, c1_wc_y);
  c1_lc_hoistedGlobal = c1_get_pose_twitch(chartInstance, 0);
  c1_wc_u = c1_lc_hoistedGlobal;
  c1_xc_y = NULL;
  sf_mex_assign(&c1_xc_y, sf_mex_create("y", &c1_wc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 72, c1_xc_y);
  c1_mc_hoistedGlobal = c1_get_pr(chartInstance, 0);
  c1_xc_u = c1_mc_hoistedGlobal;
  c1_yc_y = NULL;
  sf_mex_assign(&c1_yc_y, sf_mex_create("y", &c1_xc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 73, c1_yc_y);
  c1_nc_hoistedGlobal = c1_get_r(chartInstance, 0);
  c1_yc_u = c1_nc_hoistedGlobal;
  c1_ad_y = NULL;
  sf_mex_assign(&c1_ad_y, sf_mex_create("y", &c1_yc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 74, c1_ad_y);
  c1_oc_hoistedGlobal = c1_get_randAvertGazeChance(chartInstance, 0);
  c1_ad_u = c1_oc_hoistedGlobal;
  c1_bd_y = NULL;
  sf_mex_assign(&c1_bd_y, sf_mex_create("y", &c1_ad_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 75, c1_bd_y);
  c1_pc_hoistedGlobal = c1_get_randGazeDur(chartInstance, 0);
  c1_bd_u = c1_pc_hoistedGlobal;
  c1_cd_y = NULL;
  sf_mex_assign(&c1_cd_y, sf_mex_create("y", &c1_bd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 76, c1_cd_y);
  c1_qc_hoistedGlobal = c1_get_randPoseChance(chartInstance, 0);
  c1_cd_u = c1_qc_hoistedGlobal;
  c1_dd_y = NULL;
  sf_mex_assign(&c1_dd_y, sf_mex_create("y", &c1_cd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 77, c1_dd_y);
  c1_rc_hoistedGlobal = c1_get_randSlowPose(chartInstance, 0);
  c1_dd_u = c1_rc_hoistedGlobal;
  c1_ed_y = NULL;
  sf_mex_assign(&c1_ed_y, sf_mex_create("y", &c1_dd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 78, c1_ed_y);
  c1_sc_hoistedGlobal = c1_get_randSmile(chartInstance, 0);
  c1_ed_u = c1_sc_hoistedGlobal;
  c1_fd_y = NULL;
  sf_mex_assign(&c1_fd_y, sf_mex_create("y", &c1_ed_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 79, c1_fd_y);
  c1_tc_hoistedGlobal = c1_get_s(chartInstance, 0);
  c1_fd_u = c1_tc_hoistedGlobal;
  c1_gd_y = NULL;
  sf_mex_assign(&c1_gd_y, sf_mex_create("y", &c1_fd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 80, c1_gd_y);
  c1_uc_hoistedGlobal = chartInstance->c1_smileN;
  c1_gd_u = c1_uc_hoistedGlobal;
  c1_hd_y = NULL;
  sf_mex_assign(&c1_hd_y, sf_mex_create("y", &c1_gd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 81, c1_hd_y);
  c1_vc_hoistedGlobal = c1_get_t(chartInstance, 0);
  c1_hd_u = c1_vc_hoistedGlobal;
  c1_id_y = NULL;
  sf_mex_assign(&c1_id_y, sf_mex_create("y", &c1_hd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 82, c1_id_y);
  c1_wc_hoistedGlobal = chartInstance->c1_t1;
  c1_id_u = c1_wc_hoistedGlobal;
  c1_jd_y = NULL;
  sf_mex_assign(&c1_jd_y, sf_mex_create("y", &c1_id_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 83, c1_jd_y);
  c1_xc_hoistedGlobal = chartInstance->c1_t2;
  c1_jd_u = c1_xc_hoistedGlobal;
  c1_kd_y = NULL;
  sf_mex_assign(&c1_kd_y, sf_mex_create("y", &c1_jd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 84, c1_kd_y);
  c1_yc_hoistedGlobal = c1_get_temp(chartInstance, 0);
  c1_kd_u = c1_yc_hoistedGlobal;
  c1_ld_y = NULL;
  sf_mex_assign(&c1_ld_y, sf_mex_create("y", &c1_kd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 85, c1_ld_y);
  c1_ad_hoistedGlobal = c1_get_uHand(chartInstance, 0);
  c1_ld_u = c1_ad_hoistedGlobal;
  c1_md_y = NULL;
  sf_mex_assign(&c1_md_y, sf_mex_create("y", &c1_ld_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 86, c1_md_y);
  c1_bd_hoistedGlobal = chartInstance->c1_is_active_c1_Expriment_All2;
  c1_md_u = c1_bd_hoistedGlobal;
  c1_nd_y = NULL;
  sf_mex_assign(&c1_nd_y, sf_mex_create("y", &c1_md_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 87, c1_nd_y);
  c1_cd_hoistedGlobal = chartInstance->c1_is_active_personalSpace_Controller;
  c1_nd_u = c1_cd_hoistedGlobal;
  c1_od_y = NULL;
  sf_mex_assign(&c1_od_y, sf_mex_create("y", &c1_nd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 88, c1_od_y);
  c1_dd_hoistedGlobal = chartInstance->c1_is_active_sendBMLbyPriority;
  c1_od_u = c1_dd_hoistedGlobal;
  c1_pd_y = NULL;
  sf_mex_assign(&c1_pd_y, sf_mex_create("y", &c1_od_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 89, c1_pd_y);
  c1_ed_hoistedGlobal = chartInstance->c1_is_active_RPS_Scenario;
  c1_pd_u = c1_ed_hoistedGlobal;
  c1_qd_y = NULL;
  sf_mex_assign(&c1_qd_y, sf_mex_create("y", &c1_pd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 90, c1_qd_y);
  c1_fd_hoistedGlobal = chartInstance->c1_is_active_wave_Controller;
  c1_qd_u = c1_fd_hoistedGlobal;
  c1_rd_y = NULL;
  sf_mex_assign(&c1_rd_y, sf_mex_create("y", &c1_qd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 91, c1_rd_y);
  c1_gd_hoistedGlobal = chartInstance->c1_is_active_attention_Controller;
  c1_rd_u = c1_gd_hoistedGlobal;
  c1_sd_y = NULL;
  sf_mex_assign(&c1_sd_y, sf_mex_create("y", &c1_rd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 92, c1_sd_y);
  c1_hd_hoistedGlobal = chartInstance->c1_is_active_personality_Behavior_Factors;
  c1_sd_u = c1_hd_hoistedGlobal;
  c1_td_y = NULL;
  sf_mex_assign(&c1_td_y, sf_mex_create("y", &c1_sd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 93, c1_td_y);
  c1_id_hoistedGlobal = chartInstance->c1_is_active_custom_Behavior_Factors;
  c1_td_u = c1_id_hoistedGlobal;
  c1_ud_y = NULL;
  sf_mex_assign(&c1_ud_y, sf_mex_create("y", &c1_td_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 94, c1_ud_y);
  c1_jd_hoistedGlobal = chartInstance->c1_is_active_Gaze_Controller;
  c1_ud_u = c1_jd_hoistedGlobal;
  c1_vd_y = NULL;
  sf_mex_assign(&c1_vd_y, sf_mex_create("y", &c1_ud_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 95, c1_vd_y);
  c1_kd_hoistedGlobal = chartInstance->c1_is_active_facialExpression_Controller;
  c1_vd_u = c1_kd_hoistedGlobal;
  c1_wd_y = NULL;
  sf_mex_assign(&c1_wd_y, sf_mex_create("y", &c1_vd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 96, c1_wd_y);
  c1_ld_hoistedGlobal = chartInstance->c1_is_active_idlePose_Controller;
  c1_wd_u = c1_ld_hoistedGlobal;
  c1_xd_y = NULL;
  sf_mex_assign(&c1_xd_y, sf_mex_create("y", &c1_wd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 97, c1_xd_y);
  c1_md_hoistedGlobal = chartInstance->c1_is_active_emotion_Behavior_Factors;
  c1_xd_u = c1_md_hoistedGlobal;
  c1_yd_y = NULL;
  sf_mex_assign(&c1_yd_y, sf_mex_create("y", &c1_xd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 98, c1_yd_y);
  c1_nd_hoistedGlobal = chartInstance->c1_is_sendBMLbyPriority;
  c1_yd_u = c1_nd_hoistedGlobal;
  c1_ae_y = NULL;
  sf_mex_assign(&c1_ae_y, sf_mex_create("y", &c1_yd_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 99, c1_ae_y);
  c1_ae_u = sf_mex_dup(c1_b_subchartSimStateInfo);
  c1_be_y = NULL;
  sf_mex_assign(&c1_be_y, sf_mex_duplicatearraysafe(&c1_ae_u), false);
  sf_mex_destroy(&c1_ae_u);
  sf_mex_setcell(c1_y, 100, c1_be_y);
  c1_be_u = sf_mex_dup(c1_subchartSimStateInfo);
  c1_ce_y = NULL;
  sf_mex_assign(&c1_ce_y, sf_mex_duplicatearraysafe(&c1_be_u), false);
  sf_mex_destroy(&c1_be_u);
  sf_mex_setcell(c1_y, 101, c1_ce_y);
  c1_ce_u = sf_mex_dup(c1_c_subchartSimStateInfo);
  c1_de_y = NULL;
  sf_mex_assign(&c1_de_y, sf_mex_duplicatearraysafe(&c1_ce_u), false);
  sf_mex_destroy(&c1_ce_u);
  sf_mex_setcell(c1_y, 102, c1_de_y);
  c1_de_u = sf_mex_dup(c1_j_subchartSimStateInfo);
  c1_ee_y = NULL;
  sf_mex_assign(&c1_ee_y, sf_mex_duplicatearraysafe(&c1_de_u), false);
  sf_mex_destroy(&c1_de_u);
  sf_mex_setcell(c1_y, 103, c1_ee_y);
  c1_ee_u = sf_mex_dup(c1_g_subchartSimStateInfo);
  c1_fe_y = NULL;
  sf_mex_assign(&c1_fe_y, sf_mex_duplicatearraysafe(&c1_ee_u), false);
  sf_mex_destroy(&c1_ee_u);
  sf_mex_setcell(c1_y, 104, c1_fe_y);
  c1_fe_u = sf_mex_dup(c1_i_subchartSimStateInfo);
  c1_ge_y = NULL;
  sf_mex_assign(&c1_ge_y, sf_mex_duplicatearraysafe(&c1_fe_u), false);
  sf_mex_destroy(&c1_fe_u);
  sf_mex_setcell(c1_y, 105, c1_ge_y);
  c1_ge_u = sf_mex_dup(c1_d_subchartSimStateInfo);
  c1_he_y = NULL;
  sf_mex_assign(&c1_he_y, sf_mex_duplicatearraysafe(&c1_ge_u), false);
  sf_mex_destroy(&c1_ge_u);
  sf_mex_setcell(c1_y, 106, c1_he_y);
  c1_he_u = sf_mex_dup(c1_e_subchartSimStateInfo);
  c1_ie_y = NULL;
  sf_mex_assign(&c1_ie_y, sf_mex_duplicatearraysafe(&c1_he_u), false);
  sf_mex_destroy(&c1_he_u);
  sf_mex_setcell(c1_y, 107, c1_ie_y);
  c1_ie_u = sf_mex_dup(c1_f_subchartSimStateInfo);
  c1_je_y = NULL;
  sf_mex_assign(&c1_je_y, sf_mex_duplicatearraysafe(&c1_ie_u), false);
  sf_mex_destroy(&c1_ie_u);
  sf_mex_setcell(c1_y, 108, c1_je_y);
  c1_je_u = sf_mex_dup(c1_h_subchartSimStateInfo);
  c1_ke_y = NULL;
  sf_mex_assign(&c1_ke_y, sf_mex_duplicatearraysafe(&c1_je_u), false);
  sf_mex_destroy(&c1_je_u);
  sf_mex_setcell(c1_y, 109, c1_ke_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_st));
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_Expriment_All2(chartInstance);
  sf_exported_auto_setSimstatec5_Expriment_All2
    (chartInstance->c1_subchartSimstruct, sf_mex_dup(c1_subchartSimStateInfo));
  sf_exported_auto_setSimstatec8_Expriment_All2
    (chartInstance->c1_b_subchartSimstruct, sf_mex_dup(c1_b_subchartSimStateInfo));
  sf_exported_auto_setSimstatec20_Expriment_All2
    (chartInstance->c1_c_subchartSimstruct, sf_mex_dup(c1_c_subchartSimStateInfo));
  sf_exported_auto_setSimstatec57_Expriment_All2
    (chartInstance->c1_d_subchartSimstruct, sf_mex_dup(c1_d_subchartSimStateInfo));
  sf_exported_auto_setSimstatec9_Expriment_All2
    (chartInstance->c1_e_subchartSimstruct, sf_mex_dup(c1_e_subchartSimStateInfo));
  sf_exported_auto_setSimstatec4_Expriment_All2
    (chartInstance->c1_f_subchartSimstruct, sf_mex_dup(c1_f_subchartSimStateInfo));
  sf_exported_auto_setSimstatec42_Expriment_All2
    (chartInstance->c1_g_subchartSimstruct, sf_mex_dup(c1_g_subchartSimStateInfo));
  sf_exported_auto_setSimstatec11_Expriment_All2
    (chartInstance->c1_h_subchartSimstruct, sf_mex_dup(c1_h_subchartSimStateInfo));
  sf_exported_auto_setSimstatec44_Expriment_All2
    (chartInstance->c1_i_subchartSimstruct, sf_mex_dup(c1_i_subchartSimStateInfo));
  sf_exported_auto_setSimstatec10_Expriment_All2
    (chartInstance->c1_j_subchartSimstruct, sf_mex_dup(c1_j_subchartSimStateInfo));
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_Expriment_All2
  (SFc1_Expriment_All2InstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_RPS_Scenario == 1U) {
      chartInstance->c1_tp_RPS_Scenario = 1U;
    } else {
      chartInstance->c1_tp_RPS_Scenario = 0U;
    }

    if (chartInstance->c1_is_active_personalSpace_Controller == 1U) {
      chartInstance->c1_tp_personalSpace_Controller = 1U;
    } else {
      chartInstance->c1_tp_personalSpace_Controller = 0U;
    }

    if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
      chartInstance->c1_tp_sendBMLbyPriority = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
      }
    } else {
      chartInstance->c1_tp_sendBMLbyPriority = 0U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) > 0.0) {
        sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
      }
    }

    if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_Mid) {
      chartInstance->c1_tp_Mid = 1U;
    } else {
      chartInstance->c1_tp_Mid = 0U;
    }

    if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_checkHighPriority) {
      chartInstance->c1_tp_checkHighPriority = 1U;
    } else {
      chartInstance->c1_tp_checkHighPriority = 0U;
    }

    if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_init) {
      chartInstance->c1_tp_init = 1U;
    } else {
      chartInstance->c1_tp_init = 0U;
    }

    if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_low) {
      chartInstance->c1_tp_low = 1U;
    } else {
      chartInstance->c1_tp_low = 0U;
    }

    if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_sendH) {
      chartInstance->c1_tp_sendH = 1U;
    } else {
      chartInstance->c1_tp_sendH = 0U;
    }

    if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_sendL) {
      chartInstance->c1_tp_sendL = 1U;
    } else {
      chartInstance->c1_tp_sendL = 0U;
    }

    if (chartInstance->c1_is_sendBMLbyPriority == c1_IN_sendM) {
      chartInstance->c1_tp_sendM = 1U;
    } else {
      chartInstance->c1_tp_sendM = 0U;
    }

    if (chartInstance->c1_is_active_wave_Controller == 1U) {
      chartInstance->c1_tp_wave_Controller = 1U;
    } else {
      chartInstance->c1_tp_wave_Controller = 0U;
    }

    if (chartInstance->c1_is_active_attention_Controller == 1U) {
      chartInstance->c1_tp_attention_Controller = 1U;
    } else {
      chartInstance->c1_tp_attention_Controller = 0U;
    }

    if (chartInstance->c1_is_active_personality_Behavior_Factors == 1U) {
      chartInstance->c1_tp_personality_Behavior_Factors = 1U;
    } else {
      chartInstance->c1_tp_personality_Behavior_Factors = 0U;
    }

    if (chartInstance->c1_is_active_custom_Behavior_Factors == 1U) {
      chartInstance->c1_tp_custom_Behavior_Factors = 1U;
    } else {
      chartInstance->c1_tp_custom_Behavior_Factors = 0U;
    }

    if (chartInstance->c1_is_active_Gaze_Controller == 1U) {
      chartInstance->c1_tp_Gaze_Controller = 1U;
    } else {
      chartInstance->c1_tp_Gaze_Controller = 0U;
    }

    if (chartInstance->c1_is_active_facialExpression_Controller == 1U) {
      chartInstance->c1_tp_facialExpression_Controller = 1U;
    } else {
      chartInstance->c1_tp_facialExpression_Controller = 0U;
    }

    if (chartInstance->c1_is_active_idlePose_Controller == 1U) {
      chartInstance->c1_tp_idlePose_Controller = 1U;
    } else {
      chartInstance->c1_tp_idlePose_Controller = 0U;
    }

    if (chartInstance->c1_is_active_emotion_Behavior_Factors == 1U) {
      chartInstance->c1_tp_emotion_Behavior_Factors = 1U;
    } else {
      chartInstance->c1_tp_emotion_Behavior_Factors = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c1_subchartSimStateInfo);
  sf_mex_destroy(&c1_b_subchartSimStateInfo);
  sf_mex_destroy(&c1_c_subchartSimStateInfo);
  sf_mex_destroy(&c1_d_subchartSimStateInfo);
  sf_mex_destroy(&c1_e_subchartSimStateInfo);
  sf_mex_destroy(&c1_f_subchartSimStateInfo);
  sf_mex_destroy(&c1_g_subchartSimStateInfo);
  sf_mex_destroy(&c1_h_subchartSimStateInfo);
  sf_mex_destroy(&c1_i_subchartSimStateInfo);
  sf_mex_destroy(&c1_j_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T *c1_emotion_amount_custom;
  real_T *c1_gameState;
  real_T *c1_inputUser;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  real_T *c1_isSmiling;
  boolean_T *c1_body_isAttending;
  boolean_T *c1_face_isAttending;
  real_T *c1_round;
  boolean_T *c1_xChangeFlag;
  boolean_T *c1_zChangeFlag;
  real_T *c1_isInvading;
  real_T *c1_inA;
  real_T *c1_handUp;
  real_T *c1_inV;
  real_T *c1_internalE;
  real_T *c1_personality;
  boolean_T *c1_aChange;
  boolean_T *c1_vChange;
  boolean_T *c1_personalityChange;
  boolean_T *c1_personalityFlag;
  boolean_T *c1_vaFlag;
  real_T (*c1_gazeArray)[6];
  real_T (*c1_poseArray)[6];
  real_T (*c1_randArray)[40];
  c1_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 20);
  c1_personalityFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c1_personalityChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c1_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c1_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c1_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_zChangeFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_xChangeFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_face_isAttending = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_body_isAttending = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
  c1_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c1_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 1);
  c1_emotion_amount_custom = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_set_sim_state_side_effects_c1_Expriment_All2(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc5_Expriment_All2(chartInstance->c1_subchartSimstruct);
  sf_exported_auto_gatewayc8_Expriment_All2
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_gatewayc20_Expriment_All2
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_gatewayc57_Expriment_All2
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_gatewayc9_Expriment_All2
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_gatewayc4_Expriment_All2
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_gatewayc42_Expriment_All2
    (chartInstance->c1_g_subchartSimstruct);
  sf_exported_auto_gatewayc11_Expriment_All2
    (chartInstance->c1_h_subchartSimstruct);
  sf_exported_auto_gatewayc44_Expriment_All2
    (chartInstance->c1_i_subchartSimstruct);
  sf_exported_auto_gatewayc10_Expriment_All2
    (chartInstance->c1_j_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_emotion_amount_custom, 0U);
  for (c1_i19 = 0; c1_i19 < 40; c1_i19++) {
    _SFD_DATA_RANGE_CHECK((*c1_randArray)[c1_i19], 1U);
  }

  for (c1_i20 = 0; c1_i20 < 6; c1_i20++) {
    _SFD_DATA_RANGE_CHECK((*c1_poseArray)[c1_i20], 2U);
  }

  for (c1_i21 = 0; c1_i21 < 6; c1_i21++) {
    _SFD_DATA_RANGE_CHECK((*c1_gazeArray)[c1_i21], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_gameState, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_inputUser, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_bradHand, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_userHand, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 8U);
  _SFD_DATA_RANGE_CHECK(c1_get_temp(chartInstance, 0), 9U);
  _SFD_DATA_RANGE_CHECK(c1_get_diff(chartInstance, 0), 10U);
  _SFD_DATA_RANGE_CHECK(c1_get_uHand(chartInstance, 0), 11U);
  _SFD_DATA_RANGE_CHECK(c1_get_bHand(chartInstance, 0), 12U);
  _SFD_DATA_RANGE_CHECK(*c1_bWinT, 13U);
  _SFD_DATA_RANGE_CHECK(*c1_uWinT, 14U);
  _SFD_DATA_RANGE_CHECK(c1_get_randSmile(chartInstance, 0), 15U);
  _SFD_DATA_RANGE_CHECK(c1_get_boredom(chartInstance, 0), 16U);
  _SFD_DATA_RANGE_CHECK(c1_get_BOREDOM_THRESHOLD(chartInstance, 0), 17U);
  _SFD_DATA_RANGE_CHECK(c1_get_randAvertGazeChance(chartInstance, 0), 18U);
  _SFD_DATA_RANGE_CHECK(c1_get_randPoseChance(chartInstance, 0), 19U);
  _SFD_DATA_RANGE_CHECK(c1_get_interest(chartInstance, 0), 20U);
  _SFD_DATA_RANGE_CHECK(c1_get_r(chartInstance, 0), 21U);
  _SFD_DATA_RANGE_CHECK(c1_get_pa(chartInstance, 0), 22U);
  _SFD_DATA_RANGE_CHECK(c1_get_s(chartInstance, 0), 23U);
  _SFD_DATA_RANGE_CHECK(c1_get_randGazeDur(chartInstance, 0), 24U);
  _SFD_DATA_RANGE_CHECK(c1_get_P(chartInstance, 0), 25U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 26U);
  _SFD_DATA_RANGE_CHECK(*c1_isSmiling, 27U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_body_isAttending, 28U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_face_isAttending, 29U);
  _SFD_DATA_RANGE_CHECK(c1_get_avert(chartInstance, 0), 30U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_GUI(chartInstance, 0), 31U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_SOFTEYE(chartInstance, 0), 32U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_USER_HAND(chartInstance, 0), 33U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_READY(chartInstance, 0), 34U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_GO(chartInstance, 0), 35U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_HAND(chartInstance, 0), 36U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_OVER(chartInstance, 0), 37U);
  _SFD_DATA_RANGE_CHECK(c1_get_gazing(chartInstance, 0), 38U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_WIN(chartInstance, 0), 39U);
  _SFD_DATA_RANGE_CHECK(c1_get_randSlowPose(chartInstance, 0), 40U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_BEFORE(chartInstance, 0), 41U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_RESULT(chartInstance, 0), 42U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_WAIT(chartInstance, 0), 43U);
  _SFD_DATA_RANGE_CHECK(c1_get_HAPPY(chartInstance, 0), 44U);
  _SFD_DATA_RANGE_CHECK(c1_get_SAD(chartInstance, 0), 45U);
  _SFD_DATA_RANGE_CHECK(c1_get_CONTEMPT(chartInstance, 0), 46U);
  _SFD_DATA_RANGE_CHECK(c1_get_BORED(chartInstance, 0), 47U);
  _SFD_DATA_RANGE_CHECK(c1_get_FRUST(chartInstance, 0), 48U);
  _SFD_DATA_RANGE_CHECK(c1_get_FEAR(chartInstance, 0), 49U);
  _SFD_DATA_RANGE_CHECK(c1_get_IDLE(chartInstance, 0), 50U);
  _SFD_DATA_RANGE_CHECK(c1_get_EXCITE(chartInstance, 0), 51U);
  for (c1_i22 = 0; c1_i22 < 1000; c1_i22++) {
    _SFD_DATA_RANGE_CHECK(c1_get_BML(chartInstance, c1_i22), 52U);
  }

  _SFD_DATA_RANGE_CHECK(c1_get_pr(chartInstance, 0), 53U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_t1, 54U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_t2, 55U);
  _SFD_DATA_RANGE_CHECK(*c1_round, 56U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_newBmlA, 57U);
  _SFD_DATA_RANGE_CHECK(c1_get_fileID(chartInstance, 0), 58U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_xChangeFlag, 59U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_zChangeFlag, 60U);
  _SFD_DATA_RANGE_CHECK(*c1_isInvading, 61U);
  _SFD_DATA_RANGE_CHECK(*c1_inA, 62U);
  _SFD_DATA_RANGE_CHECK(*c1_handUp, 63U);
  _SFD_DATA_RANGE_CHECK(*c1_inV, 64U);
  _SFD_DATA_RANGE_CHECK(*c1_internalE, 65U);
  _SFD_DATA_RANGE_CHECK(*c1_personality, 66U);
  for (c1_i23 = 0; c1_i23 < 1000; c1_i23++) {
    _SFD_DATA_RANGE_CHECK(c1_get_BML2(chartInstance, c1_i23), 67U);
  }

  for (c1_i24 = 0; c1_i24 < 1000; c1_i24++) {
    _SFD_DATA_RANGE_CHECK(c1_get_BML1(chartInstance, c1_i24), 68U);
  }

  _SFD_DATA_RANGE_CHECK(c1_get_t(chartInstance, 0), 69U);
  _SFD_DATA_RANGE_CHECK(c1_get_bodyBusyFlag(chartInstance, 0), 70U);
  for (c1_i25 = 0; c1_i25 < 1000; c1_i25++) {
    _SFD_DATA_RANGE_CHECK(c1_get_n(chartInstance, c1_i25), 71U);
  }

  for (c1_i26 = 0; c1_i26 < 5000; c1_i26++) {
    _SFD_DATA_RANGE_CHECK(c1_get_bmlsL(chartInstance, c1_i26), 72U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c1_hEmpty, 73U);
  for (c1_i27 = 0; c1_i27 < 5000; c1_i27++) {
    _SFD_DATA_RANGE_CHECK(c1_get_bmlsH(chartInstance, c1_i27), 74U);
  }

  for (c1_i28 = 0; c1_i28 < 5000; c1_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_newBmlsH[c1_i28], 75U);
  }

  for (c1_i29 = 0; c1_i29 < 5000; c1_i29++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_newBmlsL[c1_i29], 76U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c1_lEmpty, 77U);
  for (c1_i30 = 0; c1_i30 < 5000; c1_i30++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_newBmlsM[c1_i30], 78U);
  }

  for (c1_i31 = 0; c1_i31 < 5000; c1_i31++) {
    _SFD_DATA_RANGE_CHECK(c1_get_bmlsM(chartInstance, c1_i31), 79U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c1_mEmpty, 80U);
  _SFD_DATA_RANGE_CHECK(c1_get_avertH(chartInstance, 0), 81U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_aChange, 82U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_vChange, 83U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_personalityChange, 84U);
  _SFD_DATA_RANGE_CHECK(c1_get_faceBusyFlag(chartInstance, 0), 85U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_personalityFlag, 86U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_vaFlag, 87U);
  _SFD_DATA_RANGE_CHECK(c1_get_mutual_gaze_duration_factor(chartInstance, 0),
                        88U);
  _SFD_DATA_RANGE_CHECK(c1_get_avert_gaze_duration_factor(chartInstance, 0), 89U);
  _SFD_DATA_RANGE_CHECK(c1_get_avert_head_frequency_factor(chartInstance, 0),
                        90U);
  _SFD_DATA_RANGE_CHECK(c1_get_avert_gaze_dirs_chance(chartInstance, 0), 91U);
  _SFD_DATA_RANGE_CHECK(c1_get_avert_head_speed(chartInstance, 0), 92U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_chance_factor(chartInstance, 0), 93U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_cat_chance(chartInstance, 0), 94U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_frequency_factor(chartInstance, 0), 95U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_speed(chartInstance, 0), 96U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_lean(chartInstance, 0), 97U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_lean_flag(chartInstance, 0), 98U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_change_flag(chartInstance, 0), 99U);
  for (c1_i32 = 0; c1_i32 < 11; c1_i32++) {
    _SFD_DATA_RANGE_CHECK(c1_get_emotion_amount_factor(chartInstance, c1_i32),
                          100U);
  }

  _SFD_DATA_RANGE_CHECK(c1_get_avert_freq_factor(chartInstance, 0), 101U);
  _SFD_DATA_RANGE_CHECK(c1_get_mut_freq_factor(chartInstance, 0), 102U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_twitch(chartInstance, 0), 103U);
  _SFD_DATA_RANGE_CHECK(c1_get_blink_flag(chartInstance, 0), 104U);
  _SFD_DATA_RANGE_CHECK(c1_get_blinkperiod_min(chartInstance, 0), 105U);
  _SFD_DATA_RANGE_CHECK(c1_get_blinkperiod_max(chartInstance, 0), 106U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose_space(chartInstance, 0), 107U);
  sf_exported_auto_activate_c5_Expriment_All2_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_activate_c8_Expriment_All2_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_activate_c20_Expriment_All2_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_activate_c57_Expriment_All2_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_activate_c9_Expriment_All2_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_activate_c4_Expriment_All2_secs
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_activate_callc42_Expriment_All2
    (chartInstance->c1_g_subchartSimstruct);
  sf_exported_auto_activate_callc11_Expriment_All2
    (chartInstance->c1_h_subchartSimstruct);
  sf_exported_auto_activate_callc44_Expriment_All2
    (chartInstance->c1_i_subchartSimstruct);
  sf_exported_auto_activate_c10_Expriment_All2_secs
    (chartInstance->c1_j_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c5_Expriment_All2_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c8_Expriment_All2_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c20_Expriment_All2_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c57_Expriment_All2_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c9_Expriment_All2_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c4_Expriment_All2_secs
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c10_Expriment_All2_secs
    (chartInstance->c1_j_subchartSimstruct);
  chartInstance->c1_sfEvent = c1_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_stepBuffersc5_Expriment_All2
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_stepBuffersc8_Expriment_All2
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_stepBuffersc20_Expriment_All2
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_stepBuffersc57_Expriment_All2
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_stepBuffersc9_Expriment_All2
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_stepBuffersc4_Expriment_All2
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_stepBuffersc42_Expriment_All2
    (chartInstance->c1_g_subchartSimstruct);
  sf_exported_auto_stepBuffersc11_Expriment_All2
    (chartInstance->c1_h_subchartSimstruct);
  sf_exported_auto_stepBuffersc44_Expriment_All2
    (chartInstance->c1_i_subchartSimstruct);
  sf_exported_auto_stepBuffersc10_Expriment_All2
    (chartInstance->c1_j_subchartSimstruct);
  c1_c1_Expriment_All2(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_resetTemporalCounter_c5_Expriment_All2_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c8_Expriment_All2_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c20_Expriment_All2_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c57_Expriment_All2_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c9_Expriment_All2_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c4_Expriment_All2_secs
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c10_Expriment_All2_secs
    (chartInstance->c1_j_subchartSimstruct);
  sf_exported_auto_deactivate_c5_Expriment_All2_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_deactivate_c8_Expriment_All2_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_deactivate_c20_Expriment_All2_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_deactivate_c57_Expriment_All2_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_deactivate_c9_Expriment_All2_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_deactivate_c4_Expriment_All2_secs
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_deactivate_callc42_Expriment_All2
    (chartInstance->c1_g_subchartSimstruct);
  sf_exported_auto_deactivate_callc11_Expriment_All2
    (chartInstance->c1_h_subchartSimstruct);
  sf_exported_auto_deactivate_callc44_Expriment_All2
    (chartInstance->c1_i_subchartSimstruct);
  sf_exported_auto_deactivate_c10_Expriment_All2_secs
    (chartInstance->c1_j_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_All2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c1_is_active_RPS_Scenario == 1U) {
    sf_exported_auto_check_state_inconsistency_c5_Expriment_All2
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_personalSpace_Controller == 1U) {
    sf_exported_auto_check_state_inconsistency_c8_Expriment_All2
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_wave_Controller == 1U) {
    sf_exported_auto_check_state_inconsistency_c20_Expriment_All2
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_Gaze_Controller == 1U) {
    sf_exported_auto_check_state_inconsistency_c57_Expriment_All2
      (chartInstance->c1_d_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_facialExpression_Controller == 1U) {
    sf_exported_auto_check_state_inconsistency_c9_Expriment_All2
      (chartInstance->c1_e_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePose_Controller == 1U) {
    sf_exported_auto_check_state_inconsistency_c4_Expriment_All2
      (chartInstance->c1_f_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_personality_Behavior_Factors == 1U) {
    sf_exported_auto_check_state_inconsistency_c42_Expriment_All2
      (chartInstance->c1_g_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_emotion_Behavior_Factors == 1U) {
    sf_exported_auto_check_state_inconsistency_c11_Expriment_All2
      (chartInstance->c1_h_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_custom_Behavior_Factors == 1U) {
    sf_exported_auto_check_state_inconsistency_c44_Expriment_All2
      (chartInstance->c1_i_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_attention_Controller == 1U) {
    sf_exported_auto_check_state_inconsistency_c10_Expriment_All2
      (chartInstance->c1_j_subchartSimstruct);
  }
}

static void c1_c1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv0[1000];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_Expriment_All2 == 0U) {
    sf_exported_auto_initBuffersc5_Expriment_All2
      (chartInstance->c1_subchartSimstruct);
    sf_exported_auto_initBuffersc8_Expriment_All2
      (chartInstance->c1_b_subchartSimstruct);
    sf_exported_auto_initBuffersc20_Expriment_All2
      (chartInstance->c1_c_subchartSimstruct);
    sf_exported_auto_initBuffersc57_Expriment_All2
      (chartInstance->c1_d_subchartSimstruct);
    sf_exported_auto_initBuffersc9_Expriment_All2
      (chartInstance->c1_e_subchartSimstruct);
    sf_exported_auto_initBuffersc4_Expriment_All2
      (chartInstance->c1_f_subchartSimstruct);
    sf_exported_auto_initBuffersc42_Expriment_All2
      (chartInstance->c1_g_subchartSimstruct);
    sf_exported_auto_initBuffersc11_Expriment_All2
      (chartInstance->c1_h_subchartSimstruct);
    sf_exported_auto_initBuffersc44_Expriment_All2
      (chartInstance->c1_i_subchartSimstruct);
    sf_exported_auto_initBuffersc10_Expriment_All2
      (chartInstance->c1_j_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_Expriment_All2 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_RPS_Scenario = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_RPS_Scenario = 1U;
    sf_exported_auto_enterc5_Expriment_All2(chartInstance->c1_subchartSimstruct);
    chartInstance->c1_is_active_personalSpace_Controller = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_personalSpace_Controller = 1U;
    sf_exported_auto_enterc8_Expriment_All2
      (chartInstance->c1_b_subchartSimstruct);
    chartInstance->c1_is_active_sendBMLbyPriority = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_sendBMLbyPriority = 1U;
    sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_sendBMLbyPriority = c1_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_encStr2Arr(chartInstance, c1_dv0);
    for (c1_i33 = 0; c1_i33 < 1000; c1_i33++) {
      c1_set_n(chartInstance, c1_i33, c1_dv0[c1_i33]);
    }

    for (c1_i34 = 0; c1_i34 < 1000; c1_i34++) {
      _SFD_DATA_RANGE_CHECK(c1_get_n(chartInstance, c1_i34), 71U);
    }

    for (c1_i35 = 0; c1_i35 < 1000; c1_i35++) {
      c1_set_bmlsH(chartInstance, c1_i35, c1_get_n(chartInstance, c1_i35));
    }

    for (c1_i36 = 0; c1_i36 < 1000; c1_i36++) {
      c1_set_bmlsH(chartInstance, c1_i36 + 1000, c1_get_n(chartInstance, c1_i36));
    }

    for (c1_i37 = 0; c1_i37 < 1000; c1_i37++) {
      c1_set_bmlsH(chartInstance, c1_i37 + 2000, c1_get_n(chartInstance, c1_i37));
    }

    for (c1_i38 = 0; c1_i38 < 1000; c1_i38++) {
      c1_set_bmlsH(chartInstance, c1_i38 + 3000, c1_get_n(chartInstance, c1_i38));
    }

    for (c1_i39 = 0; c1_i39 < 1000; c1_i39++) {
      c1_set_bmlsH(chartInstance, c1_i39 + 4000, c1_get_n(chartInstance, c1_i39));
    }

    for (c1_i40 = 0; c1_i40 < 5000; c1_i40++) {
      _SFD_DATA_RANGE_CHECK(c1_get_bmlsH(chartInstance, c1_i40), 74U);
    }

    for (c1_i41 = 0; c1_i41 < 1000; c1_i41++) {
      c1_set_bmlsM(chartInstance, c1_i41, c1_get_n(chartInstance, c1_i41));
    }

    for (c1_i42 = 0; c1_i42 < 1000; c1_i42++) {
      c1_set_bmlsM(chartInstance, c1_i42 + 1000, c1_get_n(chartInstance, c1_i42));
    }

    for (c1_i43 = 0; c1_i43 < 1000; c1_i43++) {
      c1_set_bmlsM(chartInstance, c1_i43 + 2000, c1_get_n(chartInstance, c1_i43));
    }

    for (c1_i44 = 0; c1_i44 < 1000; c1_i44++) {
      c1_set_bmlsM(chartInstance, c1_i44 + 3000, c1_get_n(chartInstance, c1_i44));
    }

    for (c1_i45 = 0; c1_i45 < 1000; c1_i45++) {
      c1_set_bmlsM(chartInstance, c1_i45 + 4000, c1_get_n(chartInstance, c1_i45));
    }

    for (c1_i46 = 0; c1_i46 < 5000; c1_i46++) {
      _SFD_DATA_RANGE_CHECK(c1_get_bmlsM(chartInstance, c1_i46), 79U);
    }

    for (c1_i47 = 0; c1_i47 < 1000; c1_i47++) {
      c1_set_bmlsL(chartInstance, c1_i47, c1_get_n(chartInstance, c1_i47));
    }

    for (c1_i48 = 0; c1_i48 < 1000; c1_i48++) {
      c1_set_bmlsL(chartInstance, c1_i48 + 1000, c1_get_n(chartInstance, c1_i48));
    }

    for (c1_i49 = 0; c1_i49 < 1000; c1_i49++) {
      c1_set_bmlsL(chartInstance, c1_i49 + 2000, c1_get_n(chartInstance, c1_i49));
    }

    for (c1_i50 = 0; c1_i50 < 1000; c1_i50++) {
      c1_set_bmlsL(chartInstance, c1_i50 + 3000, c1_get_n(chartInstance, c1_i50));
    }

    for (c1_i51 = 0; c1_i51 < 1000; c1_i51++) {
      c1_set_bmlsL(chartInstance, c1_i51 + 4000, c1_get_n(chartInstance, c1_i51));
    }

    for (c1_i52 = 0; c1_i52 < 5000; c1_i52++) {
      _SFD_DATA_RANGE_CHECK(c1_get_bmlsL(chartInstance, c1_i52), 72U);
    }

    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_is_active_wave_Controller = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_wave_Controller = 1U;
    sf_exported_auto_enterc20_Expriment_All2
      (chartInstance->c1_c_subchartSimstruct);
    chartInstance->c1_is_active_attention_Controller = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_attention_Controller = 1U;
    sf_exported_auto_enterc10_Expriment_All2
      (chartInstance->c1_j_subchartSimstruct);
    chartInstance->c1_is_active_personality_Behavior_Factors = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_personality_Behavior_Factors = 1U;
    sf_exported_auto_enterc42_Expriment_All2
      (chartInstance->c1_g_subchartSimstruct);
    chartInstance->c1_is_active_custom_Behavior_Factors = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_custom_Behavior_Factors = 1U;
    sf_exported_auto_enterc44_Expriment_All2
      (chartInstance->c1_i_subchartSimstruct);
    chartInstance->c1_is_active_Gaze_Controller = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_Gaze_Controller = 1U;
    sf_exported_auto_enterc57_Expriment_All2
      (chartInstance->c1_d_subchartSimstruct);
    chartInstance->c1_is_active_facialExpression_Controller = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_facialExpression_Controller = 1U;
    sf_exported_auto_enterc9_Expriment_All2
      (chartInstance->c1_e_subchartSimstruct);
    chartInstance->c1_is_active_idlePose_Controller = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_idlePose_Controller = 1U;
    sf_exported_auto_enterc4_Expriment_All2
      (chartInstance->c1_f_subchartSimstruct);
    chartInstance->c1_is_active_emotion_Behavior_Factors = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_emotion_Behavior_Factors = 1U;
    sf_exported_auto_enterc11_Expriment_All2
      (chartInstance->c1_h_subchartSimstruct);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc5_Expriment_All2(chartInstance->c1_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc8_Expriment_All2
      (chartInstance->c1_b_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
    c1_sendBMLbyPriority(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc20_Expriment_All2
      (chartInstance->c1_c_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc10_Expriment_All2
      (chartInstance->c1_j_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc42_Expriment_All2
      (chartInstance->c1_g_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc44_Expriment_All2
      (chartInstance->c1_i_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc57_Expriment_All2
      (chartInstance->c1_d_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc9_Expriment_All2
      (chartInstance->c1_e_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc4_Expriment_All2
      (chartInstance->c1_f_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc11_Expriment_All2
      (chartInstance->c1_h_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_Expriment_All2(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  chartInstance->c1_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "RPS_Scenario");
  chartInstance->c1_b_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "personalSpace_Controller");
  chartInstance->c1_c_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "wave_Controller");
  chartInstance->c1_d_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "Gaze_Controller");
  chartInstance->c1_e_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "facialExpression_Controller");
  chartInstance->c1_f_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "idlePose_Controller");
  chartInstance->c1_g_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "personality_Behavior_Factors");
  chartInstance->c1_h_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "emotion_Behavior_Factors");
  chartInstance->c1_i_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "custom_Behavior_Factors");
  chartInstance->c1_j_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "attention_Controller");
}

static void c1_sendBMLbyPriority(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  int32_T c1_i53;
  static real_T c1_dv1[5000];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  int32_T c1_i54;
  static real_T c1_dv2[5000];
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  int32_T c1_i55;
  static real_T c1_dv3[5000];
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  int32_T c1_i56;
  static real_T c1_dv4[5000];
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  int32_T c1_i57;
  static real_T c1_dv5[5000];
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  int32_T c1_i58;
  static real_T c1_dv6[5000];
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 1.0;
  boolean_T c1_g_out;
  int32_T c1_i59;
  static real_T c1_dv7[5000];
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 1.0;
  boolean_T c1_h_out;
  int32_T c1_i60;
  static real_T c1_dv8[5000];
  real_T c1_n_nargin = 0.0;
  real_T c1_n_nargout = 0.0;
  int32_T c1_i61;
  static real_T c1_dv9[5000];
  real_T c1_o_nargin = 0.0;
  real_T c1_o_nargout = 1.0;
  boolean_T c1_i_out;
  int32_T c1_i62;
  static real_T c1_dv10[5000];
  real_T c1_p_nargin = 0.0;
  real_T c1_p_nargout = 0.0;
  int32_T c1_i63;
  static real_T c1_dv11[5000];
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_sendBMLbyPriority) {
   case c1_IN_Mid:
    CV_STATE_EVAL(9, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_o_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_e_sf_marshallOut,
      c1_d_sf_marshallIn);
    for (c1_i53 = 0; c1_i53 < 5000; c1_i53++) {
      c1_dv1[c1_i53] = c1_get_bmlsH(chartInstance, c1_i53);
    }

    c1_out = CV_EML_IF(8, 0, 0, c1_isEmptyQueue(chartInstance, c1_dv1) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Mid = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendH;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_sendH = 1U;
      c1_enter_atomic_sendH(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_r_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_e_sf_marshallOut,
        c1_d_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 9U, 80U);
      c1_b_out = CV_EML_IF(6, 0, 0, chartInstance->c1_mEmpty != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Mid = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendM;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_sendM = 1U;
        c1_enter_atomic_sendM(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_s_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_e_sf_marshallOut,
          c1_d_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 9U, 80U);
        c1_c_out = CV_EML_IF(11, 0, 0, chartInstance->c1_mEmpty == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_Mid = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_sendBMLbyPriority = c1_IN_low;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_low = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_j_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          for (c1_i54 = 0; c1_i54 < 5000; c1_i54++) {
            c1_dv2[c1_i54] = c1_get_bmlsL(chartInstance, c1_i54);
          }

          chartInstance->c1_lEmpty = c1_isEmptyQueue(chartInstance, c1_dv2);
          c1_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_lEmpty, 77U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_m_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U,
            c1_e_sf_marshallOut, c1_d_sf_marshallIn);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 9U, 80U);
          c1_d_out = CV_EML_IF(7, 0, 0, chartInstance->c1_mEmpty == 1.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_Mid = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_sendBMLbyPriority = c1_IN_checkHighPriority;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_checkHighPriority = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
              c1_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            for (c1_i55 = 0; c1_i55 < 5000; c1_i55++) {
              c1_dv3[c1_i55] = c1_get_bmlsH(chartInstance, c1_i55);
            }

            chartInstance->c1_hEmpty = c1_isEmptyQueue(chartInstance, c1_dv3);
            c1_updateDataWrittenToVector(chartInstance, 4U);
            _SFD_DATA_RANGE_CHECK(chartInstance->c1_hEmpty, 73U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                         chartInstance->c1_sfEvent);
          }
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_checkHighPriority:
    CV_STATE_EVAL(9, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_l_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_e_sf_marshallOut,
      c1_d_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 4U, 73U);
    c1_e_out = CV_EML_IF(5, 0, 0, chartInstance->c1_hEmpty == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_checkHighPriority = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_sendBMLbyPriority = c1_IN_Mid;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Mid = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_h_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      for (c1_i56 = 0; c1_i56 < 5000; c1_i56++) {
        c1_dv4[c1_i56] = c1_get_bmlsM(chartInstance, c1_i56);
      }

      chartInstance->c1_mEmpty = c1_isEmptyQueue(chartInstance, c1_dv4);
      c1_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_mEmpty, 80U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_k_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_e_sf_marshallOut,
        c1_d_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 4U, 73U);
      c1_f_out = CV_EML_IF(1, 0, 0, chartInstance->c1_hEmpty != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_checkHighPriority = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendH;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_sendH = 1U;
        c1_enter_atomic_sendH(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                     chartInstance->c1_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(9, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_sendBMLbyPriority = c1_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    for (c1_i57 = 0; c1_i57 < 5000; c1_i57++) {
      c1_dv5[c1_i57] = c1_get_bmlsH(chartInstance, c1_i57);
    }

    chartInstance->c1_hEmpty = c1_isEmptyQueue(chartInstance, c1_dv5);
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_hEmpty, 73U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_low:
    CV_STATE_EVAL(9, 0, 4);
    c1_low(chartInstance);
    break;

   case c1_IN_sendH:
    CV_STATE_EVAL(9, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_sendH = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_sendBMLbyPriority = c1_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    for (c1_i58 = 0; c1_i58 < 5000; c1_i58++) {
      c1_dv6[c1_i58] = c1_get_bmlsH(chartInstance, c1_i58);
    }

    chartInstance->c1_hEmpty = c1_isEmptyQueue(chartInstance, c1_dv6);
    c1_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_hEmpty, 73U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_sendL:
    CV_STATE_EVAL(9, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_v_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_e_sf_marshallOut,
      c1_d_sf_marshallIn);
    for (c1_i59 = 0; c1_i59 < 5000; c1_i59++) {
      c1_dv7[c1_i59] = c1_get_bmlsM(chartInstance, c1_i59);
    }

    c1_g_out = CV_EML_IF(15, 0, 0, c1_isEmptyQueue(chartInstance, c1_dv7) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_sendL = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendM;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_sendM = 1U;
      c1_enter_atomic_sendM(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_q_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_e_sf_marshallOut,
        c1_d_sf_marshallIn);
      for (c1_i60 = 0; c1_i60 < 5000; c1_i60++) {
        c1_dv8[c1_i60] = c1_get_bmlsH(chartInstance, c1_i60);
      }

      c1_h_out = CV_EML_IF(16, 0, 0, c1_isEmptyQueue(chartInstance, c1_dv8) !=
                           1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_sendL = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendH;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_sendH = 1U;
        c1_enter_atomic_sendH(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_sendL = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_sendBMLbyPriority = c1_IN_checkHighPriority;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_checkHighPriority = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        for (c1_i61 = 0; c1_i61 < 5000; c1_i61++) {
          c1_dv9[c1_i61] = c1_get_bmlsH(chartInstance, c1_i61);
        }

        chartInstance->c1_hEmpty = c1_isEmptyQueue(chartInstance, c1_dv9);
        c1_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_hEmpty, 73U);
        _SFD_SYMBOL_SCOPE_POP();
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_sendM:
    CV_STATE_EVAL(9, 0, 7);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_p_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U, c1_e_sf_marshallOut,
      c1_d_sf_marshallIn);
    for (c1_i62 = 0; c1_i62 < 5000; c1_i62++) {
      c1_dv10[c1_i62] = c1_get_bmlsH(chartInstance, c1_i62);
    }

    c1_i_out = CV_EML_IF(9, 0, 0, c1_isEmptyQueue(chartInstance, c1_dv10) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_i_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_sendM = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendH;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_sendH = 1U;
      c1_enter_atomic_sendH(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_sendM = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_sendBMLbyPriority = c1_IN_checkHighPriority;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_checkHighPriority = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      for (c1_i63 = 0; c1_i63 < 5000; c1_i63++) {
        c1_dv11[c1_i63] = c1_get_bmlsH(chartInstance, c1_i63);
      }

      chartInstance->c1_hEmpty = c1_isEmptyQueue(chartInstance, c1_dv11);
      c1_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_hEmpty, 73U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 0, 0);
    chartInstance->c1_is_sendBMLbyPriority = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_sendH(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  real_T c1_In1[1000];
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  real_T c1_dv12[5000];
  real_T c1_dv13[5000];
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  real_T (*c1_b_In1)[1000];
  c1_b_In1 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 15);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  for (c1_i64 = 0; c1_i64 < 1000; c1_i64++) {
    c1_set_BML(chartInstance, c1_i64, c1_get_bmlsH(chartInstance, c1_i64));
  }

  for (c1_i65 = 0; c1_i65 < 1000; c1_i65++) {
    _SFD_DATA_RANGE_CHECK(c1_get_BML(chartInstance, c1_i65), 52U);
  }

  for (c1_i66 = 0; c1_i66 < 1000; c1_i66++) {
    c1_In1[c1_i66] = c1_get_BML(chartInstance, c1_i66);
  }

  for (c1_i67 = 0; c1_i67 < 1000; c1_i67++) {
    _SFD_DATA_RANGE_CHECK(c1_In1[c1_i67], 108U);
  }

  _SFD_SET_DATA_VALUE_PTR(108U, c1_In1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("In1", c1_In1, c1_k_sf_marshallOut,
    c1_h_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
  for (c1_i68 = 0; c1_i68 < 1000; c1_i68++) {
    (*c1_b_In1)[c1_i68] = c1_In1[c1_i68];
  }

  for (c1_i69 = 0; c1_i69 < 1000; c1_i69++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_In1)[c1_i69], 108U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(108U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
  for (c1_i70 = 0; c1_i70 < 5000; c1_i70++) {
    c1_dv12[c1_i70] = c1_get_bmlsH(chartInstance, c1_i70);
  }

  c1_removeQueue(chartInstance, c1_dv12, c1_dv13);
  for (c1_i71 = 0; c1_i71 < 5000; c1_i71++) {
    chartInstance->c1_newBmlsH[c1_i71] = c1_dv13[c1_i71];
  }

  c1_updateDataWrittenToVector(chartInstance, 5U);
  for (c1_i72 = 0; c1_i72 < 5000; c1_i72++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_newBmlsH[c1_i72], 75U);
  }

  c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 75U);
  for (c1_i73 = 0; c1_i73 < 5000; c1_i73++) {
    c1_set_bmlsH(chartInstance, c1_i73, chartInstance->c1_newBmlsH[c1_i73]);
  }

  for (c1_i74 = 0; c1_i74 < 5000; c1_i74++) {
    _SFD_DATA_RANGE_CHECK(c1_get_bmlsH(chartInstance, c1_i74), 74U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_enter_atomic_sendM(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  real_T c1_In1[1000];
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i80;
  int32_T c1_i81;
  real_T c1_dv14[5000];
  real_T c1_dv15[5000];
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  real_T (*c1_b_In1)[1000];
  c1_b_In1 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 15);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_g_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  for (c1_i75 = 0; c1_i75 < 1000; c1_i75++) {
    c1_set_BML(chartInstance, c1_i75, c1_get_bmlsM(chartInstance, c1_i75));
  }

  for (c1_i76 = 0; c1_i76 < 1000; c1_i76++) {
    _SFD_DATA_RANGE_CHECK(c1_get_BML(chartInstance, c1_i76), 52U);
  }

  for (c1_i77 = 0; c1_i77 < 1000; c1_i77++) {
    c1_In1[c1_i77] = c1_get_BML(chartInstance, c1_i77);
  }

  for (c1_i78 = 0; c1_i78 < 1000; c1_i78++) {
    _SFD_DATA_RANGE_CHECK(c1_In1[c1_i78], 108U);
  }

  _SFD_SET_DATA_VALUE_PTR(108U, c1_In1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("In1", c1_In1, c1_k_sf_marshallOut,
    c1_h_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
  for (c1_i79 = 0; c1_i79 < 1000; c1_i79++) {
    (*c1_b_In1)[c1_i79] = c1_In1[c1_i79];
  }

  for (c1_i80 = 0; c1_i80 < 1000; c1_i80++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_In1)[c1_i80], 108U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(108U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
  for (c1_i81 = 0; c1_i81 < 5000; c1_i81++) {
    c1_dv14[c1_i81] = c1_get_bmlsM(chartInstance, c1_i81);
  }

  c1_removeQueue(chartInstance, c1_dv14, c1_dv15);
  for (c1_i82 = 0; c1_i82 < 5000; c1_i82++) {
    chartInstance->c1_newBmlsM[c1_i82] = c1_dv15[c1_i82];
  }

  c1_updateDataWrittenToVector(chartInstance, 8U);
  for (c1_i83 = 0; c1_i83 < 5000; c1_i83++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_newBmlsM[c1_i83], 78U);
  }

  c1_errorIfDataNotWrittenToFcn(chartInstance, 8U, 78U);
  for (c1_i84 = 0; c1_i84 < 5000; c1_i84++) {
    c1_set_bmlsM(chartInstance, c1_i84, chartInstance->c1_newBmlsM[c1_i84]);
  }

  for (c1_i85 = 0; c1_i85 < 5000; c1_i85++) {
    _SFD_DATA_RANGE_CHECK(c1_get_bmlsM(chartInstance, c1_i85), 79U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_low(SFc1_Expriment_All2InstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  int32_T c1_i86;
  static real_T c1_dv16[5000];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  int32_T c1_i87;
  static real_T c1_dv17[5000];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i90;
  real_T c1_In1[1000];
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  static real_T c1_dv18[5000];
  static real_T c1_dv19[5000];
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  int32_T c1_i99;
  real_T c1_dv20[5000];
  real_T (*c1_b_In1)[1000];
  c1_b_In1 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 15);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_n_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i86 = 0; c1_i86 < 5000; c1_i86++) {
    c1_dv16[c1_i86] = c1_get_bmlsH(chartInstance, c1_i86);
  }

  c1_out = CV_EML_IF(14, 0, 0, c1_isEmptyQueue(chartInstance, c1_dv16) != 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_low = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_sendH = 1U;
    c1_enter_atomic_sendH(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_u_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_e_sf_marshallOut,
      c1_d_sf_marshallIn);
    for (c1_i87 = 0; c1_i87 < 5000; c1_i87++) {
      c1_dv17[c1_i87] = c1_get_bmlsM(chartInstance, c1_i87);
    }

    c1_b_out = CV_EML_IF(13, 0, 0, c1_isEmptyQueue(chartInstance, c1_dv17) !=
                         1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_low = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendM;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_sendM = 1U;
      c1_enter_atomic_sendM(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_w_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_e_sf_marshallOut,
        c1_d_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 77U);
      c1_c_out = CV_EML_IF(10, 0, 0, chartInstance->c1_lEmpty != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_low = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_sendBMLbyPriority = c1_IN_sendL;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_sendL = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_i_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        for (c1_i88 = 0; c1_i88 < 1000; c1_i88++) {
          c1_set_BML(chartInstance, c1_i88, c1_get_bmlsL(chartInstance, c1_i88));
        }

        for (c1_i89 = 0; c1_i89 < 1000; c1_i89++) {
          _SFD_DATA_RANGE_CHECK(c1_get_BML(chartInstance, c1_i89), 52U);
        }

        for (c1_i90 = 0; c1_i90 < 1000; c1_i90++) {
          c1_In1[c1_i90] = c1_get_BML(chartInstance, c1_i90);
        }

        for (c1_i91 = 0; c1_i91 < 1000; c1_i91++) {
          _SFD_DATA_RANGE_CHECK(c1_In1[c1_i91], 108U);
        }

        _SFD_SET_DATA_VALUE_PTR(108U, c1_In1);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("In1", c1_In1, c1_k_sf_marshallOut,
          c1_h_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                     chartInstance->c1_sfEvent);
        for (c1_i92 = 0; c1_i92 < 1000; c1_i92++) {
          (*c1_b_In1)[c1_i92] = c1_In1[c1_i92];
        }

        for (c1_i93 = 0; c1_i93 < 1000; c1_i93++) {
          _SFD_DATA_RANGE_CHECK((*c1_b_In1)[c1_i93], 108U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(108U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
        for (c1_i94 = 0; c1_i94 < 5000; c1_i94++) {
          c1_dv18[c1_i94] = c1_get_bmlsL(chartInstance, c1_i94);
        }

        c1_removeQueue(chartInstance, c1_dv18, c1_dv19);
        for (c1_i95 = 0; c1_i95 < 5000; c1_i95++) {
          chartInstance->c1_newBmlsL[c1_i95] = c1_dv19[c1_i95];
        }

        c1_updateDataWrittenToVector(chartInstance, 6U);
        for (c1_i96 = 0; c1_i96 < 5000; c1_i96++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_newBmlsL[c1_i96], 76U);
        }

        c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 76U);
        for (c1_i97 = 0; c1_i97 < 5000; c1_i97++) {
          c1_set_bmlsL(chartInstance, c1_i97, chartInstance->c1_newBmlsL[c1_i97]);
        }

        for (c1_i98 = 0; c1_i98 < 5000; c1_i98++) {
          _SFD_DATA_RANGE_CHECK(c1_get_bmlsL(chartInstance, c1_i98), 72U);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_t_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_e_sf_marshallOut,
          c1_d_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 77U);
        c1_d_out = CV_EML_IF(12, 0, 0, chartInstance->c1_lEmpty == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_low = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_sendBMLbyPriority = c1_IN_Mid;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_Mid = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_h_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          for (c1_i99 = 0; c1_i99 < 5000; c1_i99++) {
            c1_dv20[c1_i99] = c1_get_bmlsM(chartInstance, c1_i99);
          }

          chartInstance->c1_mEmpty = c1_isEmptyQueue(chartInstance, c1_dv20);
          c1_updateDataWrittenToVector(chartInstance, 9U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_mEmpty, 80U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                       chartInstance->c1_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
}

static void c1_encStr2Arr(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_myarr256[1000])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr;
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[1000];
  char_T c1_mystr;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i100;
  int32_T c1_i101;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_arr, 1U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_mystr, 5U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i100 = 0; c1_i100 < 1000; c1_i100++) {
    c1_tt[c1_i100] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_tt[0] = c1_arr;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i101 = 0; c1_i101 < 1000; c1_i101++) {
    c1_myarr256[c1_i101] = c1_tt[c1_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c1_isequal(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_varargin_1[1000], real_T c1_varargin_2[1000])
{
  boolean_T c1_p;
  boolean_T c1_b_p;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_x1;
  real_T c1_x2;
  boolean_T c1_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c1_k < 1000)) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_x1 = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 1000, 1, 0) - 1];
    c1_x2 = c1_varargin_2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 1000, 1, 0) - 1];
    c1_c_p = (c1_x1 == c1_x2);
    if (!c1_c_p) {
      c1_b_p = false;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (!c1_b_p) {
  } else {
    c1_p = true;
  }

  return c1_p;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\28-12-2015-Matlab\\encStr2Arr.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i102;
  real_T c1_b_inData[1000];
  int32_T c1_i103;
  real_T c1_u[1000];
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i102 = 0; c1_i102 < 1000; c1_i102++) {
    c1_b_inData[c1_i102] = (*(real_T (*)[1000])c1_inData)[c1_i102];
  }

  for (c1_i103 = 0; c1_i103 < 1000; c1_i103++) {
    c1_u[c1_i103] = c1_b_inData[c1_i103];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 1000), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000])
{
  real_T c1_dv21[1000];
  int32_T c1_i104;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv21, 1, 0, 0U, 1, 0U, 1, 1000);
  for (c1_i104 = 0; c1_i104 < 1000; c1_i104++) {
    c1_y[c1_i104] = c1_dv21[c1_i104];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_myarr256;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[1000];
  int32_T c1_i105;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_myarr256 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_myarr256), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_myarr256);
  for (c1_i105 = 0; c1_i105 < 1000; c1_i105++) {
    (*(real_T (*)[1000])c1_outData)[c1_i105] = c1_y[c1_i105];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  char_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(char_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  real_T c1_b_inData[5000];
  int32_T c1_i109;
  int32_T c1_i110;
  int32_T c1_i111;
  real_T c1_u[5000];
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i106 = 0;
  for (c1_i107 = 0; c1_i107 < 5; c1_i107++) {
    for (c1_i108 = 0; c1_i108 < 1000; c1_i108++) {
      c1_b_inData[c1_i108 + c1_i106] = (*(real_T (*)[5000])c1_inData)[c1_i108 +
        c1_i106];
    }

    c1_i106 += 1000;
  }

  c1_i109 = 0;
  for (c1_i110 = 0; c1_i110 < 5; c1_i110++) {
    for (c1_i111 = 0; c1_i111 < 1000; c1_i111++) {
      c1_u[c1_i111 + c1_i109] = c1_b_inData[c1_i111 + c1_i109];
    }

    c1_i109 += 1000;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_newBmls, const char_T *c1_identifier, real_T
  c1_y[5000])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_newBmls), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_newBmls);
}

static void c1_e_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[5000])
{
  real_T c1_dv22[5000];
  int32_T c1_i112;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv22, 1, 0, 0U, 1, 0U, 2, 1000,
                5);
  for (c1_i112 = 0; c1_i112 < 5000; c1_i112++) {
    c1_y[c1_i112] = c1_dv22[c1_i112];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_newBmls;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[5000];
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_newBmls = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_newBmls), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_newBmls);
  c1_i113 = 0;
  for (c1_i114 = 0; c1_i114 < 5; c1_i114++) {
    for (c1_i115 = 0; c1_i115 < 1000; c1_i115++) {
      (*(real_T (*)[5000])c1_outData)[c1_i115 + c1_i113] = c1_y[c1_i115 +
        c1_i113];
    }

    c1_i113 += 1000;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_f_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sf_internal_predicateOutput;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_sf_internal_predicateOutput = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_sf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_sf_internal_predicateOutput);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Expriment_All2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 5, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/28-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static void c1_removeQueue(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_bmls[5000], real_T c1_newBmls[5000])
{
  uint32_T c1_debug_family_var_map[4];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_dv23[1000];
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  int32_T c1_i119;
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  real_T c1_dv24[1000];
  int32_T c1_i126;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_bmls, 2U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_newBmls, 3U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  CV_EML_FCN(15, 0);
  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, 2);
  c1_encStr2Arr(chartInstance, c1_dv23);
  for (c1_i116 = 0; c1_i116 < 1000; c1_i116++) {
    c1_set_n(chartInstance, c1_i116, c1_dv23[c1_i116]);
  }

  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, 3);
  for (c1_i117 = 0; c1_i117 < 1000; c1_i117++) {
    c1_newBmls[c1_i117] = c1_get_n(chartInstance, c1_i117);
  }

  for (c1_i118 = 0; c1_i118 < 1000; c1_i118++) {
    c1_newBmls[c1_i118 + 1000] = c1_get_n(chartInstance, c1_i118);
  }

  for (c1_i119 = 0; c1_i119 < 1000; c1_i119++) {
    c1_newBmls[c1_i119 + 2000] = c1_get_n(chartInstance, c1_i119);
  }

  for (c1_i120 = 0; c1_i120 < 1000; c1_i120++) {
    c1_newBmls[c1_i120 + 3000] = c1_get_n(chartInstance, c1_i120);
  }

  for (c1_i121 = 0; c1_i121 < 1000; c1_i121++) {
    c1_newBmls[c1_i121 + 4000] = c1_get_n(chartInstance, c1_i121);
  }

  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, 4);
  for (c1_i122 = 0; c1_i122 < 1000; c1_i122++) {
    c1_newBmls[c1_i122] = c1_bmls[c1_i122 + 1000];
  }

  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, 5);
  for (c1_i123 = 0; c1_i123 < 1000; c1_i123++) {
    c1_newBmls[c1_i123 + 1000] = c1_bmls[c1_i123 + 2000];
  }

  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, 6);
  for (c1_i124 = 0; c1_i124 < 1000; c1_i124++) {
    c1_newBmls[c1_i124 + 2000] = c1_bmls[c1_i124 + 3000];
  }

  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, 7);
  for (c1_i125 = 0; c1_i125 < 1000; c1_i125++) {
    c1_newBmls[c1_i125 + 3000] = c1_bmls[c1_i125 + 4000];
  }

  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, 8);
  c1_encStr2Arr(chartInstance, c1_dv24);
  for (c1_i126 = 0; c1_i126 < 1000; c1_i126++) {
    c1_newBmls[c1_i126 + 4000] = c1_dv24[c1_i126];
  }

  _SFD_EML_CALL(15U, chartInstance->c1_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c1_isEmptyQueue(SFc1_Expriment_All2InstanceStruct *chartInstance,
  real_T c1_bmls[5000])
{
  real_T c1_empty;
  uint32_T c1_debug_family_var_map[6];
  real_T c1_tempp[1000];
  real_T c1_i;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i127;
  static real_T c1_dv25[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c1_b_i;
  int32_T c1_c_i;
  int32_T c1_i128;
  real_T c1_b_bmls[1000];
  int32_T c1_i129;
  real_T c1_dv26[1000];
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_f_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_tempp, 0U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_bmls, 4U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_empty, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(13, 0);
  _SFD_EML_CALL(13U, chartInstance->c1_sfEvent, 2);
  c1_empty = 1.0;
  _SFD_EML_CALL(13U, chartInstance->c1_sfEvent, 3);
  for (c1_i127 = 0; c1_i127 < 1000; c1_i127++) {
    c1_tempp[c1_i127] = c1_dv25[c1_i127];
  }

  _SFD_EML_CALL(13U, chartInstance->c1_sfEvent, 4);
  c1_i = 1.0;
  c1_b_i = 0;
  do {
    exitg1 = 0;
    if (c1_b_i < 5) {
      c1_i = 1.0 + (real_T)c1_b_i;
      CV_EML_FOR(13, 1, 0, 1);
      _SFD_EML_CALL(13U, chartInstance->c1_sfEvent, 5);
      c1_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c1_i), 1, 5, 2, 0) - 1;
      for (c1_i128 = 0; c1_i128 < 1000; c1_i128++) {
        c1_b_bmls[c1_i128] = c1_bmls[c1_i128 + 1000 * c1_c_i];
      }

      for (c1_i129 = 0; c1_i129 < 1000; c1_i129++) {
        c1_dv26[c1_i129] = c1_dv25[c1_i129];
      }

      if (CV_EML_IF(13, 1, 0, (real_T)c1_isequal(chartInstance, c1_b_bmls,
            c1_dv26) == 0.0)) {
        _SFD_EML_CALL(13U, chartInstance->c1_sfEvent, 6);
        c1_empty = 0.0;
        _SFD_EML_CALL(13U, chartInstance->c1_sfEvent, 7);
        exitg1 = 1;
      } else {
        c1_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(13, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(13U, chartInstance->c1_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  return c1_empty;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int8_T c1_g_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i130;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i130, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i130;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_secs;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_secs = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_secs), &c1_thisId);
  sf_mex_destroy(&c1_secs);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_h_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i131;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i131, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i131;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_b_tp_RPS_Scenario, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_RPS_Scenario),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_RPS_Scenario);
  return c1_y;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_RPS_Scenario;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_b_tp_RPS_Scenario = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_RPS_Scenario),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_RPS_Scenario);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i132;
  real_T c1_b_inData[40];
  int32_T c1_i133;
  real_T c1_u[40];
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i132 = 0; c1_i132 < 40; c1_i132++) {
    c1_b_inData[c1_i132] = (*(real_T (*)[40])c1_inData)[c1_i132];
  }

  for (c1_i133 = 0; c1_i133 < 40; c1_i133++) {
    c1_u[c1_i133] = c1_b_inData[c1_i133];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 40), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i134;
  real_T c1_b_inData[6];
  int32_T c1_i135;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i134 = 0; c1_i134 < 6; c1_i134++) {
    c1_b_inData[c1_i134] = (*(real_T (*)[6])c1_inData)[c1_i134];
  }

  for (c1_i135 = 0; c1_i135 < 6; c1_i135++) {
    c1_u[c1_i135] = c1_b_inData[c1_i135];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i136;
  real_T c1_b_inData[1000];
  int32_T c1_i137;
  real_T c1_u[1000];
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i136 = 0; c1_i136 < 1000; c1_i136++) {
    c1_b_inData[c1_i136] = (*(real_T (*)[1000])c1_inData)[c1_i136];
  }

  for (c1_i137 = 0; c1_i137 < 1000; c1_i137++) {
    c1_u[c1_i137] = c1_b_inData[c1_i137];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_BML, const char_T *c1_identifier, real_T
  c1_y[1000])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_BML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_BML);
}

static void c1_l_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000])
{
  real_T c1_dv27[1000];
  int32_T c1_i138;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv27, 1, 0, 0U, 1, 0U, 2, 1000,
                1);
  for (c1_i138 = 0; c1_i138 < 1000; c1_i138++) {
    c1_y[c1_i138] = c1_dv27[c1_i138];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_BML;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[1000];
  int32_T c1_i139;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_BML = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_BML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_BML);
  for (c1_i139 = 0; c1_i139 < 1000; c1_i139++) {
    (*(real_T (*)[1000])c1_outData)[c1_i139] = c1_y[c1_i139];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i140;
  real_T c1_b_inData[11];
  int32_T c1_i141;
  real_T c1_u[11];
  const mxArray *c1_y = NULL;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i140 = 0; c1_i140 < 11; c1_i140++) {
    c1_b_inData[c1_i140] = (*(real_T (*)[11])c1_inData)[c1_i140];
  }

  for (c1_i141 = 0; c1_i141 < 11; c1_i141++) {
    c1_u[c1_i141] = c1_b_inData[c1_i141];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 11), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_m_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_emotion_amount_factor, const char_T
  *c1_identifier, real_T c1_y[11])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_emotion_amount_factor),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_emotion_amount_factor);
}

static void c1_n_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[11])
{
  real_T c1_dv28[11];
  int32_T c1_i142;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv28, 1, 0, 0U, 1, 0U, 2, 1,
                11);
  for (c1_i142 = 0; c1_i142 < 11; c1_i142++) {
    c1_y[c1_i142] = c1_dv28[c1_i142];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_emotion_amount_factor;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[11];
  int32_T c1_i143;
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c1_emotion_amount_factor = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_emotion_amount_factor),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_emotion_amount_factor);
  for (c1_i143 = 0; c1_i143 < 11; c1_i143++) {
    (*(real_T (*)[11])c1_outData)[c1_i143] = c1_y[c1_i143];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_o_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u)
{
  real_T c1_dv29[1000];
  int32_T c1_i144;
  real_T c1_dv30[1000];
  int32_T c1_i145;
  real_T c1_dv31[1000];
  int32_T c1_i146;
  static real_T c1_dv32[5000];
  int32_T c1_i147;
  static real_T c1_dv33[5000];
  int32_T c1_i148;
  static real_T c1_dv34[5000];
  int32_T c1_i149;
  real_T c1_dv35[11];
  int32_T c1_i150;
  real_T c1_dv36[1000];
  int32_T c1_i151;
  real_T c1_dv37[5000];
  int32_T c1_i152;
  real_T c1_dv38[5000];
  int32_T c1_i153;
  real_T c1_dv39[5000];
  int32_T c1_i154;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_round;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  *c1_bWinT = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "bWinT");
  *c1_bradHand = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "bradHand");
  *c1_gameState = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "gameState");
  *c1_round = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    3)), "round");
  *c1_uWinT = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    4)), "uWinT");
  *c1_userHand = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "userHand");
  *c1_win = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
    "win");
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
                        "BML", c1_dv29);
  for (c1_i144 = 0; c1_i144 < 1000; c1_i144++) {
    c1_set_BML(chartInstance, c1_i144, c1_dv29[c1_i144]);
  }

  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)),
                        "BML1", c1_dv30);
  for (c1_i145 = 0; c1_i145 < 1000; c1_i145++) {
    c1_set_BML1(chartInstance, c1_i145, c1_dv30[c1_i145]);
  }

  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 9)),
                        "BML2", c1_dv31);
  for (c1_i146 = 0; c1_i146 < 1000; c1_i146++) {
    c1_set_BML2(chartInstance, c1_i146, c1_dv31[c1_i146]);
  }

  c1_set_BORED(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 10)), "BORED"));
  c1_set_BOREDOM_THRESHOLD(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 11)), "BOREDOM_THRESHOLD"));
  c1_set_CONTEMPT(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 12)), "CONTEMPT"));
  c1_set_EXCITE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 13)), "EXCITE"));
  c1_set_FEAR(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 14)), "FEAR"));
  c1_set_FRUST(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 15)), "FRUST"));
  c1_set_GAZE_GUI(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 16)), "GAZE_GUI"));
  c1_set_GAZE_SOFTEYE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 17)), "GAZE_SOFTEYE"));
  c1_set_GAZE_USER_HAND(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 18)), "GAZE_USER_HAND"));
  c1_set_GAZE_WIN(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 19)), "GAZE_WIN"));
  c1_set_HAPPY(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 20)), "HAPPY"));
  c1_set_IDLE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 21)), "IDLE"));
  c1_set_P(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 22)), "P"));
  c1_set_SAD(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
              (sf_mex_getcell(c1_u, 23)), "SAD"));
  c1_set_STATE_BEFORE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 24)), "STATE_BEFORE"));
  c1_set_STATE_GO(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 25)), "STATE_GO"));
  c1_set_STATE_HAND(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 26)), "STATE_HAND"));
  c1_set_STATE_OVER(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 27)), "STATE_OVER"));
  c1_set_STATE_READY(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 28)), "STATE_READY"));
  c1_set_STATE_RESULT(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 29)), "STATE_RESULT"));
  c1_set_STATE_WAIT(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 30)), "STATE_WAIT"));
  c1_set_avert(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 31)), "avert"));
  c1_set_avertH(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 32)), "avertH"));
  c1_set_avert_freq_factor(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 33)), "avert_freq_factor"));
  c1_set_avert_gaze_dirs_chance(chartInstance, 0, c1_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 34)),
     "avert_gaze_dirs_chance"));
  c1_set_avert_gaze_duration_factor(chartInstance, 0, c1_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 35)),
     "avert_gaze_duration_factor"));
  c1_set_avert_head_frequency_factor(chartInstance, 0, c1_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 36)),
     "avert_head_frequency_factor"));
  c1_set_avert_head_speed(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 37)), "avert_head_speed"));
  c1_set_bHand(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 38)), "bHand"));
  c1_set_blink_flag(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 39)), "blink_flag"));
  c1_set_blinkperiod_max(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 40)), "blinkperiod_max"));
  c1_set_blinkperiod_min(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 41)), "blinkperiod_min"));
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 42)),
                        "bmlsH", c1_dv32);
  for (c1_i147 = 0; c1_i147 < 5000; c1_i147++) {
    c1_set_bmlsH(chartInstance, c1_i147, c1_dv32[c1_i147]);
  }

  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 43)),
                        "bmlsL", c1_dv33);
  for (c1_i148 = 0; c1_i148 < 5000; c1_i148++) {
    c1_set_bmlsL(chartInstance, c1_i148, c1_dv33[c1_i148]);
  }

  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 44)),
                        "bmlsM", c1_dv34);
  for (c1_i149 = 0; c1_i149 < 5000; c1_i149++) {
    c1_set_bmlsM(chartInstance, c1_i149, c1_dv34[c1_i149]);
  }

  c1_set_bodyBusyFlag(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 45)), "bodyBusyFlag"));
  c1_set_boredom(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
                  (sf_mex_getcell(c1_u, 46)), "boredom"));
  c1_set_diff(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 47)), "diff"));
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 48)),
                        "emotion_amount_factor", c1_dv35);
  for (c1_i150 = 0; c1_i150 < 11; c1_i150++) {
    c1_set_emotion_amount_factor(chartInstance, c1_i150, c1_dv35[c1_i150]);
  }

  c1_set_faceBusyFlag(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 49)), "faceBusyFlag"));
  c1_set_fileID(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 50)), "fileID"));
  c1_set_gazing(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 51)), "gazing"));
  chartInstance->c1_hEmpty = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 52)), "hEmpty");
  c1_set_interest(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 53)), "interest"));
  chartInstance->c1_lEmpty = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 54)), "lEmpty");
  chartInstance->c1_mEmpty = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 55)), "mEmpty");
  c1_set_mut_freq_factor(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 56)), "mut_freq_factor"));
  c1_set_mutual_gaze_duration_factor(chartInstance, 0, c1_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 57)),
     "mutual_gaze_duration_factor"));
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 58)), "n",
                        c1_dv36);
  for (c1_i151 = 0; c1_i151 < 1000; c1_i151++) {
    c1_set_n(chartInstance, c1_i151, c1_dv36[c1_i151]);
  }

  chartInstance->c1_newBmlA = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 59)), "newBmlA");
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 60)),
                        "newBmlsH", c1_dv37);
  for (c1_i152 = 0; c1_i152 < 5000; c1_i152++) {
    chartInstance->c1_newBmlsH[c1_i152] = c1_dv37[c1_i152];
  }

  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 61)),
                        "newBmlsL", c1_dv38);
  for (c1_i153 = 0; c1_i153 < 5000; c1_i153++) {
    chartInstance->c1_newBmlsL[c1_i153] = c1_dv38[c1_i153];
  }

  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 62)),
                        "newBmlsM", c1_dv39);
  for (c1_i154 = 0; c1_i154 < 5000; c1_i154++) {
    chartInstance->c1_newBmlsM[c1_i154] = c1_dv39[c1_i154];
  }

  c1_set_pa(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
             (sf_mex_getcell(c1_u, 63)), "pa"));
  c1_set_pose_cat_chance(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 64)), "pose_cat_chance"));
  c1_set_pose_chance_factor(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 65)), "pose_chance_factor"));
  c1_set_pose_change_flag(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 66)), "pose_change_flag"));
  c1_set_pose_frequency_factor(chartInstance, 0, c1_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 67)),
     "pose_frequency_factor"));
  c1_set_pose_lean(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 68)), "pose_lean"));
  c1_set_pose_lean_flag(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 69)), "pose_lean_flag"));
  c1_set_pose_space(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 70)), "pose_space"));
  c1_set_pose_speed(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 71)), "pose_speed"));
  c1_set_pose_twitch(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 72)), "pose_twitch"));
  c1_set_pr(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
             (sf_mex_getcell(c1_u, 73)), "pr"));
  c1_set_r(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 74)), "r"));
  c1_set_randAvertGazeChance(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 75)), "randAvertGazeChance"));
  c1_set_randGazeDur(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 76)), "randGazeDur"));
  c1_set_randPoseChance(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 77)), "randPoseChance"));
  c1_set_randSlowPose(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 78)), "randSlowPose"));
  c1_set_randSmile(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 79)), "randSmile"));
  c1_set_s(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 80)), "s"));
  chartInstance->c1_smileN = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 81)), "smileN");
  c1_set_t(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 82)), "t"));
  chartInstance->c1_t1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 83)), "t1");
  chartInstance->c1_t2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 84)), "t2");
  c1_set_temp(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 85)), "temp"));
  c1_set_uHand(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 86)), "uHand"));
  chartInstance->c1_is_active_c1_Expriment_All2 = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 87)),
     "is_active_c1_Expriment_All2");
  chartInstance->c1_is_active_personalSpace_Controller = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 88)),
     "is_active_personalSpace_Controller");
  chartInstance->c1_is_active_sendBMLbyPriority = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 89)),
     "is_active_sendBMLbyPriority");
  chartInstance->c1_is_active_RPS_Scenario = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 90)), "is_active_RPS_Scenario");
  chartInstance->c1_is_active_wave_Controller = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 91)),
     "is_active_wave_Controller");
  chartInstance->c1_is_active_attention_Controller = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 92)),
     "is_active_attention_Controller");
  chartInstance->c1_is_active_personality_Behavior_Factors =
    c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 93)),
    "is_active_personality_Behavior_Factors");
  chartInstance->c1_is_active_custom_Behavior_Factors = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 94)),
     "is_active_custom_Behavior_Factors");
  chartInstance->c1_is_active_Gaze_Controller = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 95)),
     "is_active_Gaze_Controller");
  chartInstance->c1_is_active_facialExpression_Controller =
    c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 96)),
    "is_active_facialExpression_Controller");
  chartInstance->c1_is_active_idlePose_Controller = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 97)),
     "is_active_idlePose_Controller");
  chartInstance->c1_is_active_emotion_Behavior_Factors = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 98)),
     "is_active_emotion_Behavior_Factors");
  chartInstance->c1_is_sendBMLbyPriority = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 99)), "is_sendBMLbyPriority");
  sf_mex_assign(&c1_b_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 100)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 101)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_c_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 102)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_j_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 103)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_g_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 104)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_i_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 105)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_d_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 106)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_e_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 107)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_f_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 108)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_h_subchartSimStateInfo, c1_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 109)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 110)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_p_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_k_subchartSimStateInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_k_subchartSimStateInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_k_subchartSimStateInfo);
  return c1_y;
}

static const mxArray *c1_q_emlrt_marshallIn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 11, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 11, 1,
    0)]);
}

static real_T c1_get_BML(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#3945) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_BML_address)[c1_b];
}

static void c1_set_BML(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#3945) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_BML_address)[c1_b] = c1_c;
}

static real_T *c1_access_BML(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c1_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#3945) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_BML_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c1_c;
}

static real_T c1_get_BML1(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#3961) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_BML1_address)[c1_b];
}

static void c1_set_BML1(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#3961) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_BML1_address)[c1_b] = c1_c;
}

static real_T *c1_access_BML1(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c1_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#3961) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_BML1_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c1_c;
}

static real_T c1_get_BML2(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#3960) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_BML2_address)[c1_b];
}

static void c1_set_BML2(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#3960) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_BML2_address)[c1_b] = c1_c;
}

static real_T *c1_access_BML2(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c1_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#3960) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_BML2_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c1_c;
}

static real_T c1_get_BORED(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#3940) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_BORED_address;
}

static void c1_set_BORED(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#3940) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_BORED_address = c1_c;
}

static real_T *c1_access_BORED(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c1_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#3940) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_BORED_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c1_c;
}

static real_T c1_get_BOREDOM_THRESHOLD(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#3910) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_BOREDOM_THRESHOLD_address;
}

static void c1_set_BOREDOM_THRESHOLD(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#3910) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_BOREDOM_THRESHOLD_address = c1_c;
}

static real_T *c1_access_BOREDOM_THRESHOLD(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c1_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#3910) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_BOREDOM_THRESHOLD_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c1_c;
}

static real_T c1_get_CONTEMPT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#3939) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_CONTEMPT_address;
}

static void c1_set_CONTEMPT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#3939) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_CONTEMPT_address = c1_c;
}

static real_T *c1_access_CONTEMPT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c1_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#3939) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_CONTEMPT_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c1_c;
}

static real_T c1_get_EXCITE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#3944) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_EXCITE_address;
}

static void c1_set_EXCITE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#3944) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_EXCITE_address = c1_c;
}

static real_T *c1_access_EXCITE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c1_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#3944) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_EXCITE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c1_c;
}

static real_T c1_get_FEAR(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c1_b);
  if (chartInstance->c1_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#3942) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_FEAR_address;
}

static void c1_set_FEAR(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c1_b);
  if (chartInstance->c1_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#3942) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_FEAR_address = c1_c;
}

static real_T *c1_access_FEAR(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c1_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#3942) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_FEAR_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c1_c;
}

static real_T c1_get_FRUST(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c1_b);
  if (chartInstance->c1_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#3941) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_FRUST_address;
}

static void c1_set_FRUST(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c1_b);
  if (chartInstance->c1_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#3941) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_FRUST_address = c1_c;
}

static real_T *c1_access_FRUST(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c1_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#3941) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_FRUST_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_GUI(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c1_b);
  if (chartInstance->c1_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#3924) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_GUI_address;
}

static void c1_set_GAZE_GUI(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c1_b);
  if (chartInstance->c1_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#3924) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_GUI_address = c1_c;
}

static real_T *c1_access_GAZE_GUI(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c1_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#3924) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_GUI_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_SOFTEYE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c1_b);
  if (chartInstance->c1_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#3925) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_SOFTEYE_address;
}

static void c1_set_GAZE_SOFTEYE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c1_b);
  if (chartInstance->c1_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#3925) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_SOFTEYE_address = c1_c;
}

static real_T *c1_access_GAZE_SOFTEYE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c1_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#3925) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_SOFTEYE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_USER_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c1_b);
  if (chartInstance->c1_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#3926) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_USER_HAND_address;
}

static void c1_set_GAZE_USER_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c1_b);
  if (chartInstance->c1_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#3926) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_USER_HAND_address = c1_c;
}

static real_T *c1_access_GAZE_USER_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c1_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#3926) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_USER_HAND_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_WIN(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c1_b);
  if (chartInstance->c1_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#3932) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_WIN_address;
}

static void c1_set_GAZE_WIN(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c1_b);
  if (chartInstance->c1_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#3932) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_WIN_address = c1_c;
}

static real_T *c1_access_GAZE_WIN(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c1_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#3932) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_WIN_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c1_c;
}

static real_T c1_get_HAPPY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c1_b);
  if (chartInstance->c1_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#3937) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_HAPPY_address;
}

static void c1_set_HAPPY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c1_b);
  if (chartInstance->c1_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#3937) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_HAPPY_address = c1_c;
}

static real_T *c1_access_HAPPY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c1_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#3937) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_HAPPY_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c1_c;
}

static real_T c1_get_IDLE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c1_b);
  if (chartInstance->c1_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#3943) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_IDLE_address;
}

static void c1_set_IDLE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c1_b);
  if (chartInstance->c1_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#3943) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_IDLE_address = c1_c;
}

static real_T *c1_access_IDLE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c1_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#3943) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_IDLE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c1_c;
}

static real_T c1_get_P(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c1_b);
  if (chartInstance->c1_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#3918) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_P_address;
}

static void c1_set_P(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c1_b);
  if (chartInstance->c1_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#3918) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_P_address = c1_c;
}

static real_T *c1_access_P(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c1_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#3918) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_P_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c1_c;
}

static real_T c1_get_SAD(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c1_b);
  if (chartInstance->c1_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#3938) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_SAD_address;
}

static void c1_set_SAD(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c1_b);
  if (chartInstance->c1_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#3938) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_SAD_address = c1_c;
}

static real_T *c1_access_SAD(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c1_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#3938) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_SAD_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_BEFORE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c1_b);
  if (chartInstance->c1_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#3934) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_BEFORE_address;
}

static void c1_set_STATE_BEFORE(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c1_b);
  if (chartInstance->c1_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#3934) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_BEFORE_address = c1_c;
}

static real_T *c1_access_STATE_BEFORE(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c1_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#3934) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_BEFORE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_GO(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c1_b);
  if (chartInstance->c1_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#3928) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_GO_address;
}

static void c1_set_STATE_GO(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c1_b);
  if (chartInstance->c1_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#3928) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_GO_address = c1_c;
}

static real_T *c1_access_STATE_GO(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c1_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#3928) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_GO_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_HAND(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 19, NULL, c1_b);
  if (chartInstance->c1_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#3929) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_HAND_address;
}

static void c1_set_STATE_HAND(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 19, NULL, c1_b);
  if (chartInstance->c1_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#3929) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_HAND_address = c1_c;
}

static real_T *c1_access_STATE_HAND(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 19, NULL);
  if (chartInstance->c1_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#3929) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_HAND_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 19, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_OVER(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 20, NULL, c1_b);
  if (chartInstance->c1_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#3930) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_OVER_address;
}

static void c1_set_STATE_OVER(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 20, NULL, c1_b);
  if (chartInstance->c1_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#3930) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_OVER_address = c1_c;
}

static real_T *c1_access_STATE_OVER(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 20, NULL);
  if (chartInstance->c1_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#3930) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_OVER_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 20, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_READY(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 21, NULL, c1_b);
  if (chartInstance->c1_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#3927) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_READY_address;
}

static void c1_set_STATE_READY(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 21, NULL, c1_b);
  if (chartInstance->c1_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#3927) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_READY_address = c1_c;
}

static real_T *c1_access_STATE_READY(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 21, NULL);
  if (chartInstance->c1_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#3927) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_READY_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 21, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_RESULT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 22, NULL, c1_b);
  if (chartInstance->c1_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#3935) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_RESULT_address;
}

static void c1_set_STATE_RESULT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 22, NULL, c1_b);
  if (chartInstance->c1_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#3935) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_RESULT_address = c1_c;
}

static real_T *c1_access_STATE_RESULT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 22, NULL);
  if (chartInstance->c1_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#3935) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_RESULT_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 22, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_WAIT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 23, NULL, c1_b);
  if (chartInstance->c1_STATE_WAIT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAIT\' (#3936) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_WAIT_address;
}

static void c1_set_STATE_WAIT(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 23, NULL, c1_b);
  if (chartInstance->c1_STATE_WAIT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAIT\' (#3936) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_WAIT_address = c1_c;
}

static real_T *c1_access_STATE_WAIT(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 23, NULL);
  if (chartInstance->c1_STATE_WAIT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAIT\' (#3936) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_WAIT_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 23, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 24, NULL, c1_b);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#3923) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_address;
}

static void c1_set_avert(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 24, NULL, c1_b);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#3923) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_address = c1_c;
}

static real_T *c1_access_avert(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 24, NULL);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#3923) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 24, NULL);
  }

  return c1_c;
}

static real_T c1_get_avertH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 25, NULL, c1_b);
  if (chartInstance->c1_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#3974) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avertH_address;
}

static void c1_set_avertH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 25, NULL, c1_b);
  if (chartInstance->c1_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#3974) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avertH_address = c1_c;
}

static real_T *c1_access_avertH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 25, NULL);
  if (chartInstance->c1_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#3974) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avertH_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 25, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 26, NULL, c1_b);
  if (chartInstance->c1_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#3994) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_freq_factor_address;
}

static void c1_set_avert_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 26, NULL, c1_b);
  if (chartInstance->c1_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#3994) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_freq_factor_address = c1_c;
}

static real_T *c1_access_avert_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 26, NULL);
  if (chartInstance->c1_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#3994) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_freq_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 26, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert_gaze_dirs_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 27, NULL, c1_b);
  if (chartInstance->c1_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#3984) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_gaze_dirs_chance_address;
}

static void c1_set_avert_gaze_dirs_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 27, NULL, c1_b);
  if (chartInstance->c1_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#3984) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_gaze_dirs_chance_address = c1_c;
}

static real_T *c1_access_avert_gaze_dirs_chance
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 27, NULL);
  if (chartInstance->c1_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#3984) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_gaze_dirs_chance_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 27, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 28, NULL, c1_b);
  if (chartInstance->c1_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#3982) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_gaze_duration_factor_address;
}

static void c1_set_avert_gaze_duration_factor(SFc1_Expriment_All2InstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 28, NULL, c1_b);
  if (chartInstance->c1_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#3982) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_gaze_duration_factor_address = c1_c;
}

static real_T *c1_access_avert_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 28, NULL);
  if (chartInstance->c1_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#3982) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_gaze_duration_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 28, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert_head_frequency_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 29, NULL, c1_b);
  if (chartInstance->c1_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#3983) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_head_frequency_factor_address;
}

static void c1_set_avert_head_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 29, NULL, c1_b);
  if (chartInstance->c1_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#3983) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_head_frequency_factor_address = c1_c;
}

static real_T *c1_access_avert_head_frequency_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 29, NULL);
  if (chartInstance->c1_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#3983) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_head_frequency_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 29, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert_head_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 30, NULL, c1_b);
  if (chartInstance->c1_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#3985) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_head_speed_address;
}

static void c1_set_avert_head_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 30, NULL, c1_b);
  if (chartInstance->c1_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#3985) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_head_speed_address = c1_c;
}

static real_T *c1_access_avert_head_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 30, NULL);
  if (chartInstance->c1_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#3985) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_head_speed_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 30, NULL);
  }

  return c1_c;
}

static real_T c1_get_bHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 31, NULL, c1_b);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#3905) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_bHand_address;
}

static void c1_set_bHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 31, NULL, c1_b);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#3905) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_bHand_address = c1_c;
}

static real_T *c1_access_bHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 31, NULL);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#3905) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_bHand_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 31, NULL);
  }

  return c1_c;
}

static real_T c1_get_blink_flag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 32, NULL, c1_b);
  if (chartInstance->c1_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#3997) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_blink_flag_address;
}

static void c1_set_blink_flag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 32, NULL, c1_b);
  if (chartInstance->c1_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#3997) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_blink_flag_address = c1_c;
}

static real_T *c1_access_blink_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 32, NULL);
  if (chartInstance->c1_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#3997) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_blink_flag_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 32, NULL);
  }

  return c1_c;
}

static real_T c1_get_blinkperiod_max(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 33, NULL, c1_b);
  if (chartInstance->c1_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#3999) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_blinkperiod_max_address;
}

static void c1_set_blinkperiod_max(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 33, NULL, c1_b);
  if (chartInstance->c1_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#3999) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_blinkperiod_max_address = c1_c;
}

static real_T *c1_access_blinkperiod_max(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 33, NULL);
  if (chartInstance->c1_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#3999) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_blinkperiod_max_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 33, NULL);
  }

  return c1_c;
}

static real_T c1_get_blinkperiod_min(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 34, NULL, c1_b);
  if (chartInstance->c1_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#3998) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_blinkperiod_min_address;
}

static void c1_set_blinkperiod_min(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 34, NULL, c1_b);
  if (chartInstance->c1_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#3998) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_blinkperiod_min_address = c1_c;
}

static real_T *c1_access_blinkperiod_min(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 34, NULL);
  if (chartInstance->c1_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#3998) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_blinkperiod_min_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 34, NULL);
  }

  return c1_c;
}

static real_T c1_get_bmlsH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 35, NULL, c1_b);
  if (chartInstance->c1_bmlsH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsH\' (#3967) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_bmlsH_address)[c1_b];
}

static void c1_set_bmlsH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 35, NULL, c1_b);
  if (chartInstance->c1_bmlsH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsH\' (#3967) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_bmlsH_address)[c1_b] = c1_c;
}

static real_T *c1_access_bmlsH(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 35, NULL);
  if (chartInstance->c1_bmlsH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsH\' (#3967) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_bmlsH_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 35, NULL);
  }

  return c1_c;
}

static real_T c1_get_bmlsL(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 36, NULL, c1_b);
  if (chartInstance->c1_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#3965) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_bmlsL_address)[c1_b];
}

static void c1_set_bmlsL(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 36, NULL, c1_b);
  if (chartInstance->c1_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#3965) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_bmlsL_address)[c1_b] = c1_c;
}

static real_T *c1_access_bmlsL(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 36, NULL);
  if (chartInstance->c1_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#3965) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_bmlsL_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 36, NULL);
  }

  return c1_c;
}

static real_T c1_get_bmlsM(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 37, NULL, c1_b);
  if (chartInstance->c1_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#3972) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_bmlsM_address)[c1_b];
}

static void c1_set_bmlsM(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 37, NULL, c1_b);
  if (chartInstance->c1_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#3972) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_bmlsM_address)[c1_b] = c1_c;
}

static real_T *c1_access_bmlsM(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 37, NULL);
  if (chartInstance->c1_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#3972) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_bmlsM_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 37, NULL);
  }

  return c1_c;
}

static real_T c1_get_bodyBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 38, NULL, c1_b);
  if (chartInstance->c1_bodyBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bodyBusyFlag\' (#3963) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_bodyBusyFlag_address;
}

static void c1_set_bodyBusyFlag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 38, NULL, c1_b);
  if (chartInstance->c1_bodyBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bodyBusyFlag\' (#3963) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_bodyBusyFlag_address = c1_c;
}

static real_T *c1_access_bodyBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 38, NULL);
  if (chartInstance->c1_bodyBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bodyBusyFlag\' (#3963) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_bodyBusyFlag_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 38, NULL);
  }

  return c1_c;
}

static real_T c1_get_boredom(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 39, NULL, c1_b);
  if (chartInstance->c1_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#3909) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_boredom_address;
}

static void c1_set_boredom(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 39, NULL, c1_b);
  if (chartInstance->c1_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#3909) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_boredom_address = c1_c;
}

static real_T *c1_access_boredom(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 39, NULL);
  if (chartInstance->c1_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#3909) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_boredom_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 39, NULL);
  }

  return c1_c;
}

static real_T c1_get_diff(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 40, NULL, c1_b);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#3903) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_diff_address;
}

static void c1_set_diff(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 40, NULL, c1_b);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#3903) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_diff_address = c1_c;
}

static real_T *c1_access_diff(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 40, NULL);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#3903) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_diff_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 40, NULL);
  }

  return c1_c;
}

static real_T c1_get_emotion_amount_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 41, NULL, c1_b);
  if (chartInstance->c1_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#3993) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_emotion_amount_factor_address)[c1_b];
}

static void c1_set_emotion_amount_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 41, NULL, c1_b);
  if (chartInstance->c1_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#3993) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_emotion_amount_factor_address)[c1_b] = c1_c;
}

static real_T *c1_access_emotion_amount_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 41, NULL);
  if (chartInstance->c1_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#3993) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_emotion_amount_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 41, NULL);
  }

  return c1_c;
}

static real_T c1_get_faceBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 42, NULL, c1_b);
  if (chartInstance->c1_faceBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'faceBusyFlag\' (#3978) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_faceBusyFlag_address;
}

static void c1_set_faceBusyFlag(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 42, NULL, c1_b);
  if (chartInstance->c1_faceBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'faceBusyFlag\' (#3978) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_faceBusyFlag_address = c1_c;
}

static real_T *c1_access_faceBusyFlag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 42, NULL);
  if (chartInstance->c1_faceBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'faceBusyFlag\' (#3978) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_faceBusyFlag_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 42, NULL);
  }

  return c1_c;
}

static real_T c1_get_fileID(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 43, NULL, c1_b);
  if (chartInstance->c1_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#3951) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_fileID_address;
}

static void c1_set_fileID(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 43, NULL, c1_b);
  if (chartInstance->c1_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#3951) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_fileID_address = c1_c;
}

static real_T *c1_access_fileID(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 43, NULL);
  if (chartInstance->c1_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#3951) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_fileID_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 43, NULL);
  }

  return c1_c;
}

static real_T c1_get_gazing(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 44, NULL, c1_b);
  if (chartInstance->c1_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#3931) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_gazing_address;
}

static void c1_set_gazing(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 44, NULL, c1_b);
  if (chartInstance->c1_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#3931) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_gazing_address = c1_c;
}

static real_T *c1_access_gazing(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 44, NULL);
  if (chartInstance->c1_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#3931) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_gazing_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 44, NULL);
  }

  return c1_c;
}

static real_T c1_get_interest(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 45, NULL, c1_b);
  if (chartInstance->c1_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#3913) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_interest_address;
}

static void c1_set_interest(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 45, NULL, c1_b);
  if (chartInstance->c1_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#3913) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_interest_address = c1_c;
}

static real_T *c1_access_interest(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 45, NULL);
  if (chartInstance->c1_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#3913) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_interest_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 45, NULL);
  }

  return c1_c;
}

static real_T c1_get_mut_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 46, NULL, c1_b);
  if (chartInstance->c1_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#3995) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_mut_freq_factor_address;
}

static void c1_set_mut_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 46, NULL, c1_b);
  if (chartInstance->c1_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#3995) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_mut_freq_factor_address = c1_c;
}

static real_T *c1_access_mut_freq_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 46, NULL);
  if (chartInstance->c1_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#3995) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_mut_freq_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 46, NULL);
  }

  return c1_c;
}

static real_T c1_get_mutual_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 47, NULL, c1_b);
  if (chartInstance->c1_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#3981) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_mutual_gaze_duration_factor_address;
}

static void c1_set_mutual_gaze_duration_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 47, NULL, c1_b);
  if (chartInstance->c1_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#3981) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_mutual_gaze_duration_factor_address = c1_c;
}

static real_T *c1_access_mutual_gaze_duration_factor
  (SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 47, NULL);
  if (chartInstance->c1_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#3981) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_mutual_gaze_duration_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 47, NULL);
  }

  return c1_c;
}

static real_T c1_get_n(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 48, NULL, c1_b);
  if (chartInstance->c1_n_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'n\' (#3964) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_n_address)[c1_b];
}

static void c1_set_n(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 48, NULL, c1_b);
  if (chartInstance->c1_n_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'n\' (#3964) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_n_address)[c1_b] = c1_c;
}

static real_T *c1_access_n(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 48, NULL);
  if (chartInstance->c1_n_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'n\' (#3964) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_n_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 48, NULL);
  }

  return c1_c;
}

static real_T c1_get_pa(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 49, NULL, c1_b);
  if (chartInstance->c1_pa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pa\' (#3915) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pa_address;
}

static void c1_set_pa(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 49, NULL, c1_b);
  if (chartInstance->c1_pa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pa\' (#3915) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pa_address = c1_c;
}

static real_T *c1_access_pa(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 49, NULL);
  if (chartInstance->c1_pa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pa\' (#3915) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pa_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 49, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_cat_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 50, NULL, c1_b);
  if (chartInstance->c1_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#3987) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_cat_chance_address;
}

static void c1_set_pose_cat_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 50, NULL, c1_b);
  if (chartInstance->c1_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#3987) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_cat_chance_address = c1_c;
}

static real_T *c1_access_pose_cat_chance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 50, NULL);
  if (chartInstance->c1_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#3987) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_cat_chance_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 50, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_chance_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 51, NULL, c1_b);
  if (chartInstance->c1_pose_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chance_factor\' (#3986) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_chance_factor_address;
}

static void c1_set_pose_chance_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 51, NULL, c1_b);
  if (chartInstance->c1_pose_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chance_factor\' (#3986) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_chance_factor_address = c1_c;
}

static real_T *c1_access_pose_chance_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 51, NULL);
  if (chartInstance->c1_pose_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chance_factor\' (#3986) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_chance_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 51, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_change_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 52, NULL, c1_b);
  if (chartInstance->c1_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#3992) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_change_flag_address;
}

static void c1_set_pose_change_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 52, NULL, c1_b);
  if (chartInstance->c1_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#3992) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_change_flag_address = c1_c;
}

static real_T *c1_access_pose_change_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 52, NULL);
  if (chartInstance->c1_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#3992) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_change_flag_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 52, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 53, NULL, c1_b);
  if (chartInstance->c1_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#3988) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_frequency_factor_address;
}

static void c1_set_pose_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 53, NULL, c1_b);
  if (chartInstance->c1_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#3988) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_frequency_factor_address = c1_c;
}

static real_T *c1_access_pose_frequency_factor(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 53, NULL);
  if (chartInstance->c1_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#3988) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_frequency_factor_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 53, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_lean(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 54, NULL, c1_b);
  if (chartInstance->c1_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#3990) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_lean_address;
}

static void c1_set_pose_lean(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 54, NULL, c1_b);
  if (chartInstance->c1_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#3990) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_lean_address = c1_c;
}

static real_T *c1_access_pose_lean(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 54, NULL);
  if (chartInstance->c1_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#3990) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_lean_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 54, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_lean_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 55, NULL, c1_b);
  if (chartInstance->c1_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#3991) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_lean_flag_address;
}

static void c1_set_pose_lean_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 55, NULL, c1_b);
  if (chartInstance->c1_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#3991) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_lean_flag_address = c1_c;
}

static real_T *c1_access_pose_lean_flag(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 55, NULL);
  if (chartInstance->c1_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#3991) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_lean_flag_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 55, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_space(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 56, NULL, c1_b);
  if (chartInstance->c1_pose_space_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_space\' (#21) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_space_address;
}

static void c1_set_pose_space(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 56, NULL, c1_b);
  if (chartInstance->c1_pose_space_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_space\' (#21) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_space_address = c1_c;
}

static real_T *c1_access_pose_space(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 56, NULL);
  if (chartInstance->c1_pose_space_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_space\' (#21) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_space_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 56, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_speed(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 57, NULL, c1_b);
  if (chartInstance->c1_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#3989) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_speed_address;
}

static void c1_set_pose_speed(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 57, NULL, c1_b);
  if (chartInstance->c1_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#3989) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_speed_address = c1_c;
}

static real_T *c1_access_pose_speed(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 57, NULL);
  if (chartInstance->c1_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#3989) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_speed_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 57, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose_twitch(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 58, NULL, c1_b);
  if (chartInstance->c1_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#3996) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_twitch_address;
}

static void c1_set_pose_twitch(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 58, NULL, c1_b);
  if (chartInstance->c1_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#3996) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_twitch_address = c1_c;
}

static real_T *c1_access_pose_twitch(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 58, NULL);
  if (chartInstance->c1_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#3996) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_twitch_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 58, NULL);
  }

  return c1_c;
}

static real_T c1_get_pr(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 59, NULL, c1_b);
  if (chartInstance->c1_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#3946) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pr_address;
}

static void c1_set_pr(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 59, NULL, c1_b);
  if (chartInstance->c1_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#3946) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pr_address = c1_c;
}

static real_T *c1_access_pr(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 59, NULL);
  if (chartInstance->c1_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#3946) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pr_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 59, NULL);
  }

  return c1_c;
}

static real_T c1_get_r(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 60, NULL, c1_b);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#3914) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_r_address;
}

static void c1_set_r(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 60, NULL, c1_b);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#3914) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_r_address = c1_c;
}

static real_T *c1_access_r(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 60, NULL);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#3914) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_r_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 60, NULL);
  }

  return c1_c;
}

static real_T c1_get_randAvertGazeChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 61, NULL, c1_b);
  if (chartInstance->c1_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#3911) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randAvertGazeChance_address;
}

static void c1_set_randAvertGazeChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 61, NULL, c1_b);
  if (chartInstance->c1_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#3911) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randAvertGazeChance_address = c1_c;
}

static real_T *c1_access_randAvertGazeChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 61, NULL);
  if (chartInstance->c1_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#3911) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randAvertGazeChance_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 61, NULL);
  }

  return c1_c;
}

static real_T c1_get_randGazeDur(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 62, NULL, c1_b);
  if (chartInstance->c1_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#3917) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randGazeDur_address;
}

static void c1_set_randGazeDur(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 62, NULL, c1_b);
  if (chartInstance->c1_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#3917) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randGazeDur_address = c1_c;
}

static real_T *c1_access_randGazeDur(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 62, NULL);
  if (chartInstance->c1_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#3917) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randGazeDur_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 62, NULL);
  }

  return c1_c;
}

static real_T c1_get_randPoseChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 63, NULL, c1_b);
  if (chartInstance->c1_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#3912) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randPoseChance_address;
}

static void c1_set_randPoseChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 63, NULL, c1_b);
  if (chartInstance->c1_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#3912) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randPoseChance_address = c1_c;
}

static real_T *c1_access_randPoseChance(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 63, NULL);
  if (chartInstance->c1_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#3912) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randPoseChance_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 63, NULL);
  }

  return c1_c;
}

static real_T c1_get_randSlowPose(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 64, NULL, c1_b);
  if (chartInstance->c1_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#3933) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randSlowPose_address;
}

static void c1_set_randSlowPose(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 64, NULL, c1_b);
  if (chartInstance->c1_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#3933) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randSlowPose_address = c1_c;
}

static real_T *c1_access_randSlowPose(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 64, NULL);
  if (chartInstance->c1_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#3933) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randSlowPose_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 64, NULL);
  }

  return c1_c;
}

static real_T c1_get_randSmile(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 65, NULL, c1_b);
  if (chartInstance->c1_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#3908) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randSmile_address;
}

static void c1_set_randSmile(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 65, NULL, c1_b);
  if (chartInstance->c1_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#3908) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randSmile_address = c1_c;
}

static real_T *c1_access_randSmile(SFc1_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 65, NULL);
  if (chartInstance->c1_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#3908) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randSmile_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 65, NULL);
  }

  return c1_c;
}

static real_T c1_get_s(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 66, NULL, c1_b);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#3916) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_s_address;
}

static void c1_set_s(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 66, NULL, c1_b);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#3916) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_s_address = c1_c;
}

static real_T *c1_access_s(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 66, NULL);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#3916) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_s_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 66, NULL);
  }

  return c1_c;
}

static real_T c1_get_t(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 67, NULL, c1_b);
  if (chartInstance->c1_t_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'t\' (#3962) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_t_address;
}

static void c1_set_t(SFc1_Expriment_All2InstanceStruct *chartInstance, uint32_T
                     c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 67, NULL, c1_b);
  if (chartInstance->c1_t_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'t\' (#3962) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_t_address = c1_c;
}

static real_T *c1_access_t(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 67, NULL);
  if (chartInstance->c1_t_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'t\' (#3962) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_t_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 67, NULL);
  }

  return c1_c;
}

static real_T c1_get_temp(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 68, NULL, c1_b);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#3902) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_temp_address;
}

static void c1_set_temp(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 68, NULL, c1_b);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#3902) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_temp_address = c1_c;
}

static real_T *c1_access_temp(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 68, NULL);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#3902) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_temp_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 68, NULL);
  }

  return c1_c;
}

static real_T c1_get_uHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 69, NULL, c1_b);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#3904) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_uHand_address;
}

static void c1_set_uHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 69, NULL, c1_b);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#3904) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_uHand_address = c1_c;
}

static real_T *c1_access_uHand(SFc1_Expriment_All2InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 69, NULL);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#3904) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_uHand_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 69, NULL);
  }

  return c1_c;
}

static void init_dsm_address_info(SFc1_Expriment_All2InstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c1_BML_address, &chartInstance->c1_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML1", (void **)
    &chartInstance->c1_BML1_address, &chartInstance->c1_BML1_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML2", (void **)
    &chartInstance->c1_BML2_address, &chartInstance->c1_BML2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BORED", (void **)
    &chartInstance->c1_BORED_address, &chartInstance->c1_BORED_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c1_BOREDOM_THRESHOLD_address,
    &chartInstance->c1_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "CONTEMPT", (void **)
    &chartInstance->c1_CONTEMPT_address, &chartInstance->c1_CONTEMPT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "EXCITE", (void **)
    &chartInstance->c1_EXCITE_address, &chartInstance->c1_EXCITE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FEAR", (void **)
    &chartInstance->c1_FEAR_address, &chartInstance->c1_FEAR_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FRUST", (void **)
    &chartInstance->c1_FRUST_address, &chartInstance->c1_FRUST_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_GUI", (void **)
    &chartInstance->c1_GAZE_GUI_address, &chartInstance->c1_GAZE_GUI_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_SOFTEYE", (void **)
    &chartInstance->c1_GAZE_SOFTEYE_address,
    &chartInstance->c1_GAZE_SOFTEYE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_USER_HAND", (void **)
    &chartInstance->c1_GAZE_USER_HAND_address,
    &chartInstance->c1_GAZE_USER_HAND_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c1_GAZE_WIN_address, &chartInstance->c1_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "HAPPY", (void **)
    &chartInstance->c1_HAPPY_address, &chartInstance->c1_HAPPY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "IDLE", (void **)
    &chartInstance->c1_IDLE_address, &chartInstance->c1_IDLE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c1_P_address, &chartInstance->c1_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "SAD", (void **)
    &chartInstance->c1_SAD_address, &chartInstance->c1_SAD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c1_STATE_BEFORE_address,
    &chartInstance->c1_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c1_STATE_GO_address, &chartInstance->c1_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_HAND", (void **)
    &chartInstance->c1_STATE_HAND_address, &chartInstance->c1_STATE_HAND_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c1_STATE_OVER_address, &chartInstance->c1_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c1_STATE_READY_address, &chartInstance->c1_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_RESULT", (void **)
    &chartInstance->c1_STATE_RESULT_address,
    &chartInstance->c1_STATE_RESULT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_WAIT", (void **)
    &chartInstance->c1_STATE_WAIT_address, &chartInstance->c1_STATE_WAIT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c1_avert_address, &chartInstance->c1_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avertH", (void **)
    &chartInstance->c1_avertH_address, &chartInstance->c1_avertH_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_freq_factor", (void **)
    &chartInstance->c1_avert_freq_factor_address,
    &chartInstance->c1_avert_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_dirs_chance",
    (void **)&chartInstance->c1_avert_gaze_dirs_chance_address,
    &chartInstance->c1_avert_gaze_dirs_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_duration_factor",
                                (void **)
    &chartInstance->c1_avert_gaze_duration_factor_address,
    &chartInstance->c1_avert_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_frequency_factor",
                                (void **)
    &chartInstance->c1_avert_head_frequency_factor_address,
    &chartInstance->c1_avert_head_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_speed", (void **)
    &chartInstance->c1_avert_head_speed_address,
    &chartInstance->c1_avert_head_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c1_bHand_address, &chartInstance->c1_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blink_flag", (void **)
    &chartInstance->c1_blink_flag_address, &chartInstance->c1_blink_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blinkperiod_max", (void **)
    &chartInstance->c1_blinkperiod_max_address,
    &chartInstance->c1_blinkperiod_max_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blinkperiod_min", (void **)
    &chartInstance->c1_blinkperiod_min_address,
    &chartInstance->c1_blinkperiod_min_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsH", (void **)
    &chartInstance->c1_bmlsH_address, &chartInstance->c1_bmlsH_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c1_bmlsL_address, &chartInstance->c1_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c1_bmlsM_address, &chartInstance->c1_bmlsM_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bodyBusyFlag", (void **)
    &chartInstance->c1_bodyBusyFlag_address,
    &chartInstance->c1_bodyBusyFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c1_boredom_address, &chartInstance->c1_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c1_diff_address, &chartInstance->c1_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "emotion_amount_factor", (void
    **)&chartInstance->c1_emotion_amount_factor_address,
    &chartInstance->c1_emotion_amount_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "faceBusyFlag", (void **)
    &chartInstance->c1_faceBusyFlag_address,
    &chartInstance->c1_faceBusyFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c1_fileID_address, &chartInstance->c1_fileID_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c1_gazing_address, &chartInstance->c1_gazing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c1_interest_address, &chartInstance->c1_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mut_freq_factor", (void **)
    &chartInstance->c1_mut_freq_factor_address,
    &chartInstance->c1_mut_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mutual_gaze_duration_factor",
                                (void **)
    &chartInstance->c1_mutual_gaze_duration_factor_address,
    &chartInstance->c1_mutual_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "n", (void **)
    &chartInstance->c1_n_address, &chartInstance->c1_n_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pa", (void **)
    &chartInstance->c1_pa_address, &chartInstance->c1_pa_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_cat_chance", (void **)
    &chartInstance->c1_pose_cat_chance_address,
    &chartInstance->c1_pose_cat_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_chance_factor", (void **)
    &chartInstance->c1_pose_chance_factor_address,
    &chartInstance->c1_pose_chance_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_change_flag", (void **)
    &chartInstance->c1_pose_change_flag_address,
    &chartInstance->c1_pose_change_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_frequency_factor", (void
    **)&chartInstance->c1_pose_frequency_factor_address,
    &chartInstance->c1_pose_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean", (void **)
    &chartInstance->c1_pose_lean_address, &chartInstance->c1_pose_lean_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean_flag", (void **)
    &chartInstance->c1_pose_lean_flag_address,
    &chartInstance->c1_pose_lean_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_space", (void **)
    &chartInstance->c1_pose_space_address, &chartInstance->c1_pose_space_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_speed", (void **)
    &chartInstance->c1_pose_speed_address, &chartInstance->c1_pose_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_twitch", (void **)
    &chartInstance->c1_pose_twitch_address, &chartInstance->c1_pose_twitch_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pr", (void **)
    &chartInstance->c1_pr_address, &chartInstance->c1_pr_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c1_r_address, &chartInstance->c1_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c1_randAvertGazeChance_address,
    &chartInstance->c1_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randGazeDur", (void **)
    &chartInstance->c1_randGazeDur_address, &chartInstance->c1_randGazeDur_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c1_randPoseChance_address,
    &chartInstance->c1_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSlowPose", (void **)
    &chartInstance->c1_randSlowPose_address,
    &chartInstance->c1_randSlowPose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSmile", (void **)
    &chartInstance->c1_randSmile_address, &chartInstance->c1_randSmile_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c1_s_address, &chartInstance->c1_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "t", (void **)
    &chartInstance->c1_t_address, &chartInstance->c1_t_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c1_temp_address, &chartInstance->c1_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c1_uHand_address, &chartInstance->c1_uHand_index);
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

void sf_c1_Expriment_All2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2723376754U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1848619756U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(515757006U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3302559484U);
}

mxArray *sf_c1_Expriment_All2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zBl7SfmbKKGPeCwLd79fiH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,21,3,dataFields);

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
      pr[1] = (double)(40);
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
      pr[1] = (double)(6);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,80,3,dataFields);

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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,22,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,23,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,24,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,24,"type",mxType);
    }

    mxSetField(mxData,24,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,25,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,25,"type",mxType);
    }

    mxSetField(mxData,25,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,26,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,26,"type",mxType);
    }

    mxSetField(mxData,26,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,27,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,27,"type",mxType);
    }

    mxSetField(mxData,27,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,28,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,28,"type",mxType);
    }

    mxSetField(mxData,28,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,29,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,29,"type",mxType);
    }

    mxSetField(mxData,29,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,30,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,30,"type",mxType);
    }

    mxSetField(mxData,30,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,31,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,31,"type",mxType);
    }

    mxSetField(mxData,31,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,32,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,32,"type",mxType);
    }

    mxSetField(mxData,32,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,33,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,33,"type",mxType);
    }

    mxSetField(mxData,33,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,34,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,34,"type",mxType);
    }

    mxSetField(mxData,34,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,35,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,35,"type",mxType);
    }

    mxSetField(mxData,35,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,36,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,36,"type",mxType);
    }

    mxSetField(mxData,36,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,37,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,37,"type",mxType);
    }

    mxSetField(mxData,37,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(1);
      mxSetField(mxData,38,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,38,"type",mxType);
    }

    mxSetField(mxData,38,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,39,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,39,"type",mxType);
    }

    mxSetField(mxData,39,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,40,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,40,"type",mxType);
    }

    mxSetField(mxData,40,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,41,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,41,"type",mxType);
    }

    mxSetField(mxData,41,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,42,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,42,"type",mxType);
    }

    mxSetField(mxData,42,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,43,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,43,"type",mxType);
    }

    mxSetField(mxData,43,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(1);
      mxSetField(mxData,44,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,44,"type",mxType);
    }

    mxSetField(mxData,44,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(1);
      mxSetField(mxData,45,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,45,"type",mxType);
    }

    mxSetField(mxData,45,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,46,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,46,"type",mxType);
    }

    mxSetField(mxData,46,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,47,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,47,"type",mxType);
    }

    mxSetField(mxData,47,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(1);
      mxSetField(mxData,48,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,48,"type",mxType);
    }

    mxSetField(mxData,48,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
      mxSetField(mxData,49,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,49,"type",mxType);
    }

    mxSetField(mxData,49,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,50,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,50,"type",mxType);
    }

    mxSetField(mxData,50,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
      mxSetField(mxData,51,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,51,"type",mxType);
    }

    mxSetField(mxData,51,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
      mxSetField(mxData,52,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,52,"type",mxType);
    }

    mxSetField(mxData,52,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
      mxSetField(mxData,53,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,53,"type",mxType);
    }

    mxSetField(mxData,53,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,54,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,54,"type",mxType);
    }

    mxSetField(mxData,54,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
      mxSetField(mxData,55,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,55,"type",mxType);
    }

    mxSetField(mxData,55,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
      mxSetField(mxData,56,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,56,"type",mxType);
    }

    mxSetField(mxData,56,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,57,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,57,"type",mxType);
    }

    mxSetField(mxData,57,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,58,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,58,"type",mxType);
    }

    mxSetField(mxData,58,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,59,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,59,"type",mxType);
    }

    mxSetField(mxData,59,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,60,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,60,"type",mxType);
    }

    mxSetField(mxData,60,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,61,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,61,"type",mxType);
    }

    mxSetField(mxData,61,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,62,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,62,"type",mxType);
    }

    mxSetField(mxData,62,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,63,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,63,"type",mxType);
    }

    mxSetField(mxData,63,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,64,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,64,"type",mxType);
    }

    mxSetField(mxData,64,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,65,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,65,"type",mxType);
    }

    mxSetField(mxData,65,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,66,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,66,"type",mxType);
    }

    mxSetField(mxData,66,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,67,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,67,"type",mxType);
    }

    mxSetField(mxData,67,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,68,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,68,"type",mxType);
    }

    mxSetField(mxData,68,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,69,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,69,"type",mxType);
    }

    mxSetField(mxData,69,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,70,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,70,"type",mxType);
    }

    mxSetField(mxData,70,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,71,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,71,"type",mxType);
    }

    mxSetField(mxData,71,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(11);
      mxSetField(mxData,72,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,72,"type",mxType);
    }

    mxSetField(mxData,72,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,73,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,73,"type",mxType);
    }

    mxSetField(mxData,73,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,74,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,74,"type",mxType);
    }

    mxSetField(mxData,74,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,75,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,75,"type",mxType);
    }

    mxSetField(mxData,75,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,76,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,76,"type",mxType);
    }

    mxSetField(mxData,76,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,77,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,77,"type",mxType);
    }

    mxSetField(mxData,77,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,78,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,78,"type",mxType);
    }

    mxSetField(mxData,78,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,79,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,79,"type",mxType);
    }

    mxSetField(mxData,79,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Expriment_All2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Expriment_All2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_Expriment_All2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[469],T\"bWinT\",},{M[1],M[390],T\"bradHand\",},{M[1],M[464],T\"gameState\",},{M[1],M[1118],T\"round\",},{M[1],M[470],T\"uWinT\",},{M[1],M[461],T\"userHand\",},{M[1],M[459],T\"win\",},{M[3],M[953],T\"BML\",},{M[3],M[1261],T\"BML1\",},{M[3],M[1260],T\"BML2\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[911],T\"BORED\",},{M[3],M[568],T\"BOREDOM_THRESHOLD\",},{M[3],M[910],T\"CONTEMPT\",},{M[3],M[915],T\"EXCITE\",},{M[3],M[913],T\"FEAR\",},{M[3],M[912],T\"FRUST\",},{M[3],M[837],T\"GAZE_GUI\",},{M[3],M[838],T\"GAZE_SOFTEYE\",},{M[3],M[839],T\"GAZE_USER_HAND\",},{M[3],M[845],T\"GAZE_WIN\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[908],T\"HAPPY\",},{M[3],M[914],T\"IDLE\",},{M[3],M[713],T\"P\",},{M[3],M[909],T\"SAD\",},{M[3],M[850],T\"STATE_BEFORE\",},{M[3],M[841],T\"STATE_GO\",},{M[3],M[842],T\"STATE_HAND\",},{M[3],M[843],T\"STATE_OVER\",},{M[3],M[840],T\"STATE_READY\",},{M[3],M[903],T\"STATE_RESULT\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[904],T\"STATE_WAIT\",},{M[3],M[756],T\"avert\",},{M[3],M[1359],T\"avertH\",},{M[3],M[1492],T\"avert_freq_factor\",},{M[3],M[1430],T\"avert_gaze_dirs_chance\",},{M[3],M[1427],T\"avert_gaze_duration_factor\",},{M[3],M[1428],T\"avert_head_frequency_factor\",},{M[3],M[1431],T\"avert_head_speed\",},{M[3],M[468],T\"bHand\",},{M[3],M[1501],T\"blink_flag\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[1504],T\"blinkperiod_max\",},{M[3],M[1502],T\"blinkperiod_min\",},{M[3],M[1296],T\"bmlsH\",},{M[3],M[1294],T\"bmlsL\",},{M[3],M[1312],T\"bmlsM\",},{M[3],M[1280],T\"bodyBusyFlag\",},{M[3],M[567],T\"boredom\",},{M[3],M[462],T\"diff\",},{M[3],M[1491],T\"emotion_amount_factor\",},{M[3],M[1391],T\"faceBusyFlag\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[1249],T\"fileID\",},{M[3],M[844],T\"gazing\",},{M[3],M[1295],T\"hEmpty\",},{M[3],M[641],T\"interest\",},{M[3],M[1307],T\"lEmpty\",},{M[3],M[1354],T\"mEmpty\",},{M[3],M[1493],T\"mut_freq_factor\",},{M[3],M[1426],T\"mutual_gaze_duration_factor\",},{M[3],M[1293],T\"n\",},{M[3],M[1138],T\"newBmlA\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[1297],T\"newBmlsH\",},{M[3],M[1305],T\"newBmlsL\",},{M[3],M[1311],T\"newBmlsM\",},{M[3],M[660],T\"pa\",},{M[3],M[1483],T\"pose_cat_chance\",},{M[3],M[1482],T\"pose_chance_factor\",},{M[3],M[1489],T\"pose_change_flag\",},{M[3],M[1484],T\"pose_frequency_factor\",},{M[3],M[1486],T\"pose_lean\",},{M[3],M[1488],T\"pose_lean_flag\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[1505],T\"pose_space\",},{M[3],M[1485],T\"pose_speed\",},{M[3],M[1494],T\"pose_twitch\",},{M[3],M[958],T\"pr\",},{M[3],M[659],T\"r\",},{M[3],M[596],T\"randAvertGazeChance\",},{M[3],M[688],T\"randGazeDur\",},{M[3],M[635],T\"randPoseChance\",},{M[3],M[847],T\"randSlowPose\",},{M[3],M[566],T\"randSmile\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[661],T\"s\",},{M[3],M[754],T\"smileN\",},{M[3],M[1262],T\"t\",},{M[3],M[1109],T\"t1\",},{M[3],M[1110],T\"t2\",},{M[3],M[460],T\"temp\",},{M[3],M[467],T\"uHand\",},{M[8],M[0],T\"is_active_c1_Expriment_All2\",},{M[8],M[879],T\"is_active_personalSpace_Controller\",},{M[8],M[1122],T\"is_active_sendBMLbyPriority\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[1246],T\"is_active_RPS_Scenario\",},{M[8],M[1259],T\"is_active_wave_Controller\",},{M[8],M[1279],T\"is_active_attention_Controller\",},{M[8],M[1433],T\"is_active_personality_Behavior_Factors\",},{M[8],M[1475],T\"is_active_custom_Behavior_Factors\",},{M[8],M[1496],T\"is_active_Gaze_Controller\",},{M[8],M[1499],T\"is_active_facialExpression_Controller\",},{M[8],M[1500],T\"is_active_idlePose_Controller\",},{M[8],M[1503],T\"is_active_emotion_Behavior_Factors\",},{M[9],M[1122],T\"is_sendBMLbyPriority\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[14],M[879],T\"subchartSimStateInfo\",},{M[14],M[1246],T\"subchartSimStateInfo\",},{M[14],M[1259],T\"subchartSimStateInfo\",},{M[14],M[1279],T\"subchartSimStateInfo\",},{M[14],M[1433],T\"subchartSimStateInfo\",},{M[14],M[1475],T\"subchartSimStateInfo\",},{M[14],M[1496],T\"subchartSimStateInfo\",},{M[14],M[1499],T\"subchartSimStateInfo\",},{M[14],M[1500],T\"subchartSimStateInfo\",},{M[14],M[1503],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 110, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Expriment_All2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Expriment_All2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_Expriment_All2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_All2MachineNumber_,
           1,
           21,
           18,
           0,
           113,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_All2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_All2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_All2MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,1,1,0,"emotion_amount_custom");
          _SFD_SET_DATA_PROPS(1,1,1,0,"randArray");
          _SFD_SET_DATA_PROPS(2,1,1,0,"poseArray");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gazeArray");
          _SFD_SET_DATA_PROPS(4,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(5,1,1,0,"inputUser");
          _SFD_SET_DATA_PROPS(6,2,0,1,"bradHand");
          _SFD_SET_DATA_PROPS(7,2,0,1,"userHand");
          _SFD_SET_DATA_PROPS(8,2,0,1,"win");
          _SFD_SET_DATA_PROPS(9,0,0,0,"temp");
          _SFD_SET_DATA_PROPS(10,0,0,0,"diff");
          _SFD_SET_DATA_PROPS(11,0,0,0,"uHand");
          _SFD_SET_DATA_PROPS(12,0,0,0,"bHand");
          _SFD_SET_DATA_PROPS(13,2,0,1,"bWinT");
          _SFD_SET_DATA_PROPS(14,2,0,1,"uWinT");
          _SFD_SET_DATA_PROPS(15,0,0,0,"randSmile");
          _SFD_SET_DATA_PROPS(16,0,0,0,"boredom");
          _SFD_SET_DATA_PROPS(17,0,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(18,0,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(19,0,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(20,0,0,0,"interest");
          _SFD_SET_DATA_PROPS(21,0,0,0,"r");
          _SFD_SET_DATA_PROPS(22,0,0,0,"pa");
          _SFD_SET_DATA_PROPS(23,0,0,0,"s");
          _SFD_SET_DATA_PROPS(24,0,0,0,"randGazeDur");
          _SFD_SET_DATA_PROPS(25,0,0,0,"P");
          _SFD_SET_DATA_PROPS(26,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(27,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(28,1,1,0,"body_isAttending");
          _SFD_SET_DATA_PROPS(29,1,1,0,"face_isAttending");
          _SFD_SET_DATA_PROPS(30,0,0,0,"avert");
          _SFD_SET_DATA_PROPS(31,0,0,0,"GAZE_GUI");
          _SFD_SET_DATA_PROPS(32,0,0,0,"GAZE_SOFTEYE");
          _SFD_SET_DATA_PROPS(33,0,0,0,"GAZE_USER_HAND");
          _SFD_SET_DATA_PROPS(34,0,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(35,0,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(36,0,0,0,"STATE_HAND");
          _SFD_SET_DATA_PROPS(37,0,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(38,0,0,0,"gazing");
          _SFD_SET_DATA_PROPS(39,0,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(40,0,0,0,"randSlowPose");
          _SFD_SET_DATA_PROPS(41,0,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(42,0,0,0,"STATE_RESULT");
          _SFD_SET_DATA_PROPS(43,0,0,0,"STATE_WAIT");
          _SFD_SET_DATA_PROPS(44,0,0,0,"HAPPY");
          _SFD_SET_DATA_PROPS(45,0,0,0,"SAD");
          _SFD_SET_DATA_PROPS(46,0,0,0,"CONTEMPT");
          _SFD_SET_DATA_PROPS(47,0,0,0,"BORED");
          _SFD_SET_DATA_PROPS(48,0,0,0,"FRUST");
          _SFD_SET_DATA_PROPS(49,0,0,0,"FEAR");
          _SFD_SET_DATA_PROPS(50,0,0,0,"IDLE");
          _SFD_SET_DATA_PROPS(51,0,0,0,"EXCITE");
          _SFD_SET_DATA_PROPS(52,0,0,0,"BML");
          _SFD_SET_DATA_PROPS(53,0,0,0,"pr");
          _SFD_SET_DATA_PROPS(54,0,0,0,"t1");
          _SFD_SET_DATA_PROPS(55,0,0,0,"t2");
          _SFD_SET_DATA_PROPS(56,2,0,1,"round");
          _SFD_SET_DATA_PROPS(57,0,0,0,"newBmlA");
          _SFD_SET_DATA_PROPS(58,0,0,0,"fileID");
          _SFD_SET_DATA_PROPS(59,1,1,0,"xChangeFlag");
          _SFD_SET_DATA_PROPS(60,1,1,0,"zChangeFlag");
          _SFD_SET_DATA_PROPS(61,1,1,0,"isInvading");
          _SFD_SET_DATA_PROPS(62,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(63,1,1,0,"handUp");
          _SFD_SET_DATA_PROPS(64,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(65,1,1,0,"internalE");
          _SFD_SET_DATA_PROPS(66,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(67,0,0,0,"BML2");
          _SFD_SET_DATA_PROPS(68,0,0,0,"BML1");
          _SFD_SET_DATA_PROPS(69,0,0,0,"t");
          _SFD_SET_DATA_PROPS(70,0,0,0,"bodyBusyFlag");
          _SFD_SET_DATA_PROPS(71,0,0,0,"n");
          _SFD_SET_DATA_PROPS(72,0,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(73,0,0,0,"hEmpty");
          _SFD_SET_DATA_PROPS(74,0,0,0,"bmlsH");
          _SFD_SET_DATA_PROPS(75,0,0,0,"newBmlsH");
          _SFD_SET_DATA_PROPS(76,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(77,0,0,0,"lEmpty");
          _SFD_SET_DATA_PROPS(78,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(79,0,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(80,0,0,0,"mEmpty");
          _SFD_SET_DATA_PROPS(81,0,0,0,"avertH");
          _SFD_SET_DATA_PROPS(82,1,1,0,"aChange");
          _SFD_SET_DATA_PROPS(83,1,1,0,"vChange");
          _SFD_SET_DATA_PROPS(84,1,1,0,"personalityChange");
          _SFD_SET_DATA_PROPS(85,0,0,0,"faceBusyFlag");
          _SFD_SET_DATA_PROPS(86,1,1,0,"personalityFlag");
          _SFD_SET_DATA_PROPS(87,1,1,0,"vaFlag");
          _SFD_SET_DATA_PROPS(88,0,0,0,"mutual_gaze_duration_factor");
          _SFD_SET_DATA_PROPS(89,0,0,0,"avert_gaze_duration_factor");
          _SFD_SET_DATA_PROPS(90,0,0,0,"avert_head_frequency_factor");
          _SFD_SET_DATA_PROPS(91,0,0,0,"avert_gaze_dirs_chance");
          _SFD_SET_DATA_PROPS(92,0,0,0,"avert_head_speed");
          _SFD_SET_DATA_PROPS(93,0,0,0,"pose_chance_factor");
          _SFD_SET_DATA_PROPS(94,0,0,0,"pose_cat_chance");
          _SFD_SET_DATA_PROPS(95,0,0,0,"pose_frequency_factor");
          _SFD_SET_DATA_PROPS(96,0,0,0,"pose_speed");
          _SFD_SET_DATA_PROPS(97,0,0,0,"pose_lean");
          _SFD_SET_DATA_PROPS(98,0,0,0,"pose_lean_flag");
          _SFD_SET_DATA_PROPS(99,0,0,0,"pose_change_flag");
          _SFD_SET_DATA_PROPS(100,0,0,0,"emotion_amount_factor");
          _SFD_SET_DATA_PROPS(101,0,0,0,"avert_freq_factor");
          _SFD_SET_DATA_PROPS(102,0,0,0,"mut_freq_factor");
          _SFD_SET_DATA_PROPS(103,0,0,0,"pose_twitch");
          _SFD_SET_DATA_PROPS(104,0,0,0,"blink_flag");
          _SFD_SET_DATA_PROPS(105,0,0,0,"blinkperiod_min");
          _SFD_SET_DATA_PROPS(106,0,0,0,"blinkperiod_max");
          _SFD_SET_DATA_PROPS(107,0,0,0,"pose_space");
          _SFD_SET_DATA_PROPS(108,8,0,0,"");
          _SFD_SET_DATA_PROPS(109,8,0,0,"");
          _SFD_SET_DATA_PROPS(110,9,0,0,"");
          _SFD_SET_DATA_PROPS(111,8,0,0,"");
          _SFD_SET_DATA_PROPS(112,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,1);
          _SFD_STATE_INFO(5,0,1);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,0,1);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,1);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,1);
          _SFD_STATE_INFO(13,0,2);
          _SFD_STATE_INFO(15,0,2);
          _SFD_STATE_INFO(16,0,2);
          _SFD_CH_SUBSTATE_COUNT(11);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,7);
          _SFD_CH_SUBSTATE_INDEX(2,9);
          _SFD_CH_SUBSTATE_INDEX(3,20);
          _SFD_CH_SUBSTATE_INDEX(4,2);
          _SFD_CH_SUBSTATE_INDEX(5,8);
          _SFD_CH_SUBSTATE_INDEX(6,3);
          _SFD_CH_SUBSTATE_INDEX(7,0);
          _SFD_CH_SUBSTATE_INDEX(8,5);
          _SFD_CH_SUBSTATE_INDEX(9,6);
          _SFD_CH_SUBSTATE_INDEX(10,4);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(9,7);
          _SFD_ST_SUBSTATE_INDEX(9,0,10);
          _SFD_ST_SUBSTATE_INDEX(9,1,11);
          _SFD_ST_SUBSTATE_INDEX(9,2,12);
          _SFD_ST_SUBSTATE_INDEX(9,3,14);
          _SFD_ST_SUBSTATE_INDEX(9,4,17);
          _SFD_ST_SUBSTATE_INDEX(9,5,18);
          _SFD_ST_SUBSTATE_INDEX(9,6,19);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(11,0,0,0);

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
          _SFD_CV_INIT_STATE(9,7,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(15,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(15,0,"removeQueue",0,-1,234);
        _SFD_CV_INIT_EML(13,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(13,0,"isEmptyQueue",0,-1,201);
        _SFD_CV_INIT_EML_IF(13,1,0,82,114,-1,-2);
        _SFD_CV_INIT_EML_FOR(13,1,0,66,78,200);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,10,1,10);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 40;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_j_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_k_sf_marshallOut,(MexInFcnForType)
            c1_h_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(60,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(61,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(62,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(63,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(64,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(65,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(66,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(67,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_k_sf_marshallOut,(MexInFcnForType)
            c1_h_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(68,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_k_sf_marshallOut,(MexInFcnForType)
            c1_h_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(70,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(71,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_k_sf_marshallOut,(MexInFcnForType)
            c1_h_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(72,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(73,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(74,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(75,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(76,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(77,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(78,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(79,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(80,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(81,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(82,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(83,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(84,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(85,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(86,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(87,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(88,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(89,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(90,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(91,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(92,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(93,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(94,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(95,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(96,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(97,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(98,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(99,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(100,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_l_sf_marshallOut,(MexInFcnForType)
            c1_i_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(101,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(102,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(103,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(104,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(105,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(106,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(107,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(108,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_k_sf_marshallOut,(MexInFcnForType)
            c1_h_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(109,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(110,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(111,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(112,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(108,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(109,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(110,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(111,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(112,(void *)(NULL));

        {
          real_T *c1_emotion_amount_custom;
          real_T *c1_gameState;
          real_T *c1_inputUser;
          real_T *c1_bradHand;
          real_T *c1_userHand;
          real_T *c1_win;
          real_T *c1_bWinT;
          real_T *c1_uWinT;
          real_T *c1_isSmiling;
          boolean_T *c1_body_isAttending;
          boolean_T *c1_face_isAttending;
          real_T *c1_round;
          boolean_T *c1_xChangeFlag;
          boolean_T *c1_zChangeFlag;
          real_T *c1_isInvading;
          real_T *c1_inA;
          real_T *c1_handUp;
          real_T *c1_inV;
          real_T *c1_internalE;
          real_T *c1_personality;
          boolean_T *c1_aChange;
          boolean_T *c1_vChange;
          boolean_T *c1_personalityChange;
          boolean_T *c1_personalityFlag;
          boolean_T *c1_vaFlag;
          real_T (*c1_randArray)[40];
          real_T (*c1_poseArray)[6];
          real_T (*c1_gazeArray)[6];
          c1_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 20);
          c1_personalityFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 19);
          c1_personalityChange = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 18);
          c1_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 17);
          c1_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 16);
          c1_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
          c1_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c1_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c1_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c1_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c1_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_zChangeFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_xChangeFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c1_face_isAttending = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 7);
          c1_body_isAttending = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 6);
          c1_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
          c1_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c1_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S,
            1);
          c1_emotion_amount_custom = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_emotion_amount_custom);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_randArray);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_poseArray);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_gazeArray);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_gameState);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_inputUser);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_bradHand);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_userHand);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_win);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c1_temp_address);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c1_diff_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c1_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c1_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_bWinT);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_uWinT);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c1_randSmile_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c1_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(17U,
            chartInstance->c1_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(18U,
            chartInstance->c1_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c1_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c1_interest_address);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c1_r_address);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c1_pa_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c1_s_address);
          _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c1_randGazeDur_address);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c1_P_address);
          _SFD_SET_DATA_VALUE_PTR(26U, &chartInstance->c1_smileN);
          _SFD_SET_DATA_VALUE_PTR(27U, c1_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(28U, c1_body_isAttending);
          _SFD_SET_DATA_VALUE_PTR(29U, c1_face_isAttending);
          _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c1_avert_address);
          _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c1_GAZE_GUI_address);
          _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c1_GAZE_SOFTEYE_address);
          _SFD_SET_DATA_VALUE_PTR(33U, chartInstance->c1_GAZE_USER_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c1_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c1_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(36U, chartInstance->c1_STATE_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(37U, chartInstance->c1_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(38U, chartInstance->c1_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(39U, chartInstance->c1_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(40U, chartInstance->c1_randSlowPose_address);
          _SFD_SET_DATA_VALUE_PTR(41U, chartInstance->c1_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(42U, chartInstance->c1_STATE_RESULT_address);
          _SFD_SET_DATA_VALUE_PTR(43U, chartInstance->c1_STATE_WAIT_address);
          _SFD_SET_DATA_VALUE_PTR(44U, chartInstance->c1_HAPPY_address);
          _SFD_SET_DATA_VALUE_PTR(45U, chartInstance->c1_SAD_address);
          _SFD_SET_DATA_VALUE_PTR(46U, chartInstance->c1_CONTEMPT_address);
          _SFD_SET_DATA_VALUE_PTR(47U, chartInstance->c1_BORED_address);
          _SFD_SET_DATA_VALUE_PTR(48U, chartInstance->c1_FRUST_address);
          _SFD_SET_DATA_VALUE_PTR(49U, chartInstance->c1_FEAR_address);
          _SFD_SET_DATA_VALUE_PTR(50U, chartInstance->c1_IDLE_address);
          _SFD_SET_DATA_VALUE_PTR(51U, chartInstance->c1_EXCITE_address);
          _SFD_SET_DATA_VALUE_PTR(52U, *chartInstance->c1_BML_address);
          _SFD_SET_DATA_VALUE_PTR(53U, chartInstance->c1_pr_address);
          _SFD_SET_DATA_VALUE_PTR(54U, &chartInstance->c1_t1);
          _SFD_SET_DATA_VALUE_PTR(55U, &chartInstance->c1_t2);
          _SFD_SET_DATA_VALUE_PTR(56U, c1_round);
          _SFD_SET_DATA_VALUE_PTR(57U, &chartInstance->c1_newBmlA);
          _SFD_SET_DATA_VALUE_PTR(58U, chartInstance->c1_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(59U, c1_xChangeFlag);
          _SFD_SET_DATA_VALUE_PTR(60U, c1_zChangeFlag);
          _SFD_SET_DATA_VALUE_PTR(61U, c1_isInvading);
          _SFD_SET_DATA_VALUE_PTR(62U, c1_inA);
          _SFD_SET_DATA_VALUE_PTR(63U, c1_handUp);
          _SFD_SET_DATA_VALUE_PTR(64U, c1_inV);
          _SFD_SET_DATA_VALUE_PTR(65U, c1_internalE);
          _SFD_SET_DATA_VALUE_PTR(66U, c1_personality);
          _SFD_SET_DATA_VALUE_PTR(67U, *chartInstance->c1_BML2_address);
          _SFD_SET_DATA_VALUE_PTR(68U, *chartInstance->c1_BML1_address);
          _SFD_SET_DATA_VALUE_PTR(69U, chartInstance->c1_t_address);
          _SFD_SET_DATA_VALUE_PTR(70U, chartInstance->c1_bodyBusyFlag_address);
          _SFD_SET_DATA_VALUE_PTR(71U, *chartInstance->c1_n_address);
          _SFD_SET_DATA_VALUE_PTR(72U, *chartInstance->c1_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(73U, &chartInstance->c1_hEmpty);
          _SFD_SET_DATA_VALUE_PTR(74U, *chartInstance->c1_bmlsH_address);
          _SFD_SET_DATA_VALUE_PTR(75U, chartInstance->c1_newBmlsH);
          _SFD_SET_DATA_VALUE_PTR(76U, chartInstance->c1_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(77U, &chartInstance->c1_lEmpty);
          _SFD_SET_DATA_VALUE_PTR(78U, chartInstance->c1_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(79U, *chartInstance->c1_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(80U, &chartInstance->c1_mEmpty);
          _SFD_SET_DATA_VALUE_PTR(81U, chartInstance->c1_avertH_address);
          _SFD_SET_DATA_VALUE_PTR(82U, c1_aChange);
          _SFD_SET_DATA_VALUE_PTR(83U, c1_vChange);
          _SFD_SET_DATA_VALUE_PTR(84U, c1_personalityChange);
          _SFD_SET_DATA_VALUE_PTR(85U, chartInstance->c1_faceBusyFlag_address);
          _SFD_SET_DATA_VALUE_PTR(86U, c1_personalityFlag);
          _SFD_SET_DATA_VALUE_PTR(87U, c1_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(88U,
            chartInstance->c1_mutual_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(89U,
            chartInstance->c1_avert_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(90U,
            chartInstance->c1_avert_head_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(91U,
            chartInstance->c1_avert_gaze_dirs_chance_address);
          _SFD_SET_DATA_VALUE_PTR(92U,
            chartInstance->c1_avert_head_speed_address);
          _SFD_SET_DATA_VALUE_PTR(93U,
            chartInstance->c1_pose_chance_factor_address);
          _SFD_SET_DATA_VALUE_PTR(94U, chartInstance->c1_pose_cat_chance_address);
          _SFD_SET_DATA_VALUE_PTR(95U,
            chartInstance->c1_pose_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(96U, chartInstance->c1_pose_speed_address);
          _SFD_SET_DATA_VALUE_PTR(97U, chartInstance->c1_pose_lean_address);
          _SFD_SET_DATA_VALUE_PTR(98U, chartInstance->c1_pose_lean_flag_address);
          _SFD_SET_DATA_VALUE_PTR(99U,
            chartInstance->c1_pose_change_flag_address);
          _SFD_SET_DATA_VALUE_PTR(100U,
            *chartInstance->c1_emotion_amount_factor_address);
          _SFD_SET_DATA_VALUE_PTR(101U,
            chartInstance->c1_avert_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(102U,
            chartInstance->c1_mut_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(103U, chartInstance->c1_pose_twitch_address);
          _SFD_SET_DATA_VALUE_PTR(104U, chartInstance->c1_blink_flag_address);
          _SFD_SET_DATA_VALUE_PTR(105U,
            chartInstance->c1_blinkperiod_min_address);
          _SFD_SET_DATA_VALUE_PTR(106U,
            chartInstance->c1_blinkperiod_max_address);
          _SFD_SET_DATA_VALUE_PTR(107U, chartInstance->c1_pose_space_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_All2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "XfdTsQd3qOEYW3xz06LzzF";
}

static void sf_opaque_initialize_c1_Expriment_All2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Expriment_All2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
    chartInstanceVar);
  initialize_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Expriment_All2(void *chartInstanceVar)
{
  enable_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Expriment_All2(void *chartInstanceVar)
{
  disable_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Expriment_All2(void *chartInstanceVar)
{
  sf_gateway_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Expriment_All2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Expriment_All2
    ((SFc1_Expriment_All2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Expriment_All2();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Expriment_All2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_Expriment_All2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Expriment_All2(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Expriment_All2(S);
}

static void sf_opaque_set_sim_state_c1_Expriment_All2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_Expriment_All2(S, st);
}

static void sf_opaque_terminate_c1_Expriment_All2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Expriment_All2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_All2_optimization_info();
    }

    finalize_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
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
  initSimStructsc1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Expriment_All2(SimStruct *S)
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
    initialize_params_c1_Expriment_All2((SFc1_Expriment_All2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Expriment_All2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_All2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,1,1);
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
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,21);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
    }

    ssSetInputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 21; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1691784084U));
  ssSetChecksum1(S,(889142659U));
  ssSetChecksum2(S,(2329265295U));
  ssSetChecksum3(S,(3618364662U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Expriment_All2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_Expriment_All2(SimStruct *S)
{
  SFc1_Expriment_All2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_Expriment_All2InstanceStruct *)utMalloc(sizeof
    (SFc1_Expriment_All2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Expriment_All2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Expriment_All2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Expriment_All2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Expriment_All2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Expriment_All2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Expriment_All2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Expriment_All2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Expriment_All2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Expriment_All2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Expriment_All2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Expriment_All2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Expriment_All2;
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

void c1_Expriment_All2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Expriment_All2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Expriment_All2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Expriment_All2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Expriment_All2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
