/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSs_Bdr_GK_BIS_sfun.h"
#include "c1_ARP_02_RPSs_Bdr_GK_BIS.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSs_Bdr_GK_BIS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_A1                       ((uint8_T)1U)
#define c1_IN_B1                       ((uint8_T)2U)
#define c1_IN_A2                       ((uint8_T)1U)
#define c1_IN_B2                       ((uint8_T)2U)
#define c1_IN_A3                       ((uint8_T)1U)
#define c1_IN_B3                       ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c1_subchartSimStateInfo;
static const mxArray *c1_b_subchartSimStateInfo;
static const mxArray *c1_c_subchartSimStateInfo;
static const mxArray *c1_d_subchartSimStateInfo;
static const mxArray *c1_e_subchartSimStateInfo;
static const mxArray *c1_f_subchartSimStateInfo;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[3];

/* Function Declarations */
static void initialize_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void initialize_params_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void enable_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void disable_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void set_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void c1_set_sim_state_side_effects_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void finalize_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void sf_gateway_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void initSimStructsc1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c1_sendBMLbyPriority(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_sendBML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  real_T c1_arg[256]);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int8_T c1_d_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_RPSGameImitateSmileBrad, const char_T
  *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_BML, const char_T *c1_identifier, real_T
  c1_y[256]);
static void c1_i_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_emlrt_marshallOut
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c1_g_subchartSimStateInfo, const char_T *c1_identifier);
static const mxArray *c1_k_emlrt_marshallIn
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber);
static real_T c1_get_BML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_BML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_BORED(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_BORED(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BORED(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_BOREDOM_THRESHOLD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_BOREDOM_THRESHOLD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BOREDOM_THRESHOLD
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_CONTEMPT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_CONTEMPT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_CONTEMPT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_EXCITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_EXCITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_EXCITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_FEAR(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_FEAR(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_FEAR(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_FRUST(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_FRUST(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_FRUST(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_GAZE_GUI(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_GAZE_GUI(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_GUI(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_GAZE_SHOFTEYE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_GAZE_SHOFTEYE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_SHOFTEYE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_GAZE_USER_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_GAZE_USER_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_USER_HAND
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_GAZE_WIN(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_GAZE_WIN(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_GAZE_WIN(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_HAPPY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_HAPPY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_HAPPY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_IDLE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_IDLE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_IDLE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_SAD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_SAD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_SAD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_BEFORE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_BEFORE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_BEFORE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_GO(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_GO(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_GO(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_OVER(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_OVER(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_OVER(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_READY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_READY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_READY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_RESULT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_RESULT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_RESULT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_STATE_WAITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_STATE_WAITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_STATE_WAITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_avert(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_avert(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_bHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_bHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_boredom(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_boredom(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_boredom(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_diff(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_diff(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_diff(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_gazing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_gazing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_gazing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_interest(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_interest(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_interest(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_isPosing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_isPosing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_isPosing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_p(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_p(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                     uint32_T c1_b, real_T c1_c);
static real_T *c1_access_p(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pr(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_pr(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                      uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pr(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_r(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_r(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                     uint32_T c1_b, real_T c1_c);
static real_T *c1_access_r(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_randAvertGazeChance
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b);
static void c1_set_randAvertGazeChance(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randAvertGazeChance
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_randGazeDur(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randGazeDur(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randGazeDur(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_randPoseChance(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randPoseChance(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randPoseChance
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b);
static real_T c1_get_randSlowPose(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randSlowPose(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randSlowPose(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_randSmile(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randSmile(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randSmile(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_s(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_s(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                     uint32_T c1_b, real_T c1_c);
static real_T *c1_access_s(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_temp(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_temp(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_temp(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_uHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_uHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_uHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b);
static void init_dsm_address_info(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  int32_T c1_i0;
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
  sf_exported_auto_initc5_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_initc9_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_initc4_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_initc11_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_initc8_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_initc10_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_f_subchartSimstruct);
  _sfTime_ = sf_get_time(chartInstance->S);
  c1_subchartSimStateInfo = NULL;
  c1_b_subchartSimStateInfo = NULL;
  c1_c_subchartSimStateInfo = NULL;
  c1_d_subchartSimStateInfo = NULL;
  c1_e_subchartSimStateInfo = NULL;
  c1_f_subchartSimStateInfo = NULL;
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_Gaze = 0U;
  chartInstance->c1_tp_Gaze = 0U;
  chartInstance->c1_is_active_RPSGameImitateSmileBrad = 0U;
  chartInstance->c1_tp_RPSGameImitateSmileBrad = 0U;
  chartInstance->c1_is_active_gazeIfUserMoves = 0U;
  chartInstance->c1_tp_gazeIfUserMoves = 0U;
  chartInstance->c1_is_active_idlePoseBrad = 0U;
  chartInstance->c1_tp_idlePoseBrad = 0U;
  chartInstance->c1_is_active_sendBMLbyPriority = 0U;
  chartInstance->c1_tp_sendBMLbyPriority = 0U;
  chartInstance->c1_is_active_pr1 = 0U;
  chartInstance->c1_is_pr1 = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_pr1 = 0U;
  chartInstance->c1_tp_A1 = 0U;
  chartInstance->c1_tp_B1 = 0U;
  chartInstance->c1_is_active_pr2 = 0U;
  chartInstance->c1_is_pr2 = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_pr2 = 0U;
  chartInstance->c1_tp_A2 = 0U;
  chartInstance->c1_tp_B2 = 0U;
  chartInstance->c1_is_active_pr3 = 0U;
  chartInstance->c1_is_pr3 = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_pr3 = 0U;
  chartInstance->c1_tp_A3 = 0U;
  chartInstance->c1_tp_B3 = 0U;
  chartInstance->c1_is_active_setDistanceIfUserMoves = 0U;
  chartInstance->c1_tp_setDistanceIfUserMoves = 0U;
  chartInstance->c1_is_active_smile = 0U;
  chartInstance->c1_tp_smile = 0U;
  chartInstance->c1_is_active_c1_ARP_02_RPSs_Bdr_GK_BIS = 0U;
  c1_set_temp(chartInstance, 0, 0.0);
  c1_set_diff(chartInstance, 0, 0.0);
  c1_set_uHand(chartInstance, 0, 0.0);
  c1_set_bHand(chartInstance, 0, 0.0);
  c1_set_randSmile(chartInstance, 0, 0.0);
  c1_set_boredom(chartInstance, 0, 0.0);
  c1_set_BOREDOM_THRESHOLD(chartInstance, 0, 0.0);
  c1_set_randAvertGazeChance(chartInstance, 0, 0.0);
  c1_set_randPoseChance(chartInstance, 0, 0.0);
  c1_set_isPosing(chartInstance, 0, 0.0);
  c1_set_interest(chartInstance, 0, 0.0);
  c1_set_r(chartInstance, 0, 0.0);
  c1_set_p(chartInstance, 0, 0.0);
  c1_set_s(chartInstance, 0, 0.0);
  c1_set_randGazeDur(chartInstance, 0, 0.0);
  c1_set_avert(chartInstance, 0, 0.0);
  c1_set_GAZE_GUI(chartInstance, 0, 0.0);
  c1_set_GAZE_SHOFTEYE(chartInstance, 0, 0.0);
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
  c1_set_STATE_WAITE(chartInstance, 0, 6.0);
  c1_set_HAPPY(chartInstance, 0, 4.0);
  c1_set_SAD(chartInstance, 0, 4.0);
  c1_set_CONTEMPT(chartInstance, 0, 4.0);
  c1_set_BORED(chartInstance, 0, 4.0);
  c1_set_FRUST(chartInstance, 0, 4.0);
  c1_set_FEAR(chartInstance, 0, 4.0);
  c1_set_IDLE(chartInstance, 0, 4.0);
  c1_set_EXCITE(chartInstance, 0, 4.0);
  for (c1_i0 = 0; c1_i0 < 256; c1_i0++) {
    c1_set_BML(chartInstance, c1_i0, 0.0);
  }

  c1_set_pr(chartInstance, 0, 0.0);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c1_gameState = 4.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c1_bradHand = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *c1_userHand = 3.0;
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

static void initialize_params_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "pr3", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "pr2", 0);
  sf_call_output_fcn_enable(chartInstance->S, 2, "pr1", 0);
  if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
    sf_call_output_fcn_enable(chartInstance->S, 3, "sendBML", 0);
  }

  if (chartInstance->c1_is_active_RPSGameImitateSmileBrad == 1U) {
    sf_exported_auto_enablec5_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_Gaze == 1U) {
    sf_exported_auto_enablec9_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    sf_exported_auto_enablec4_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_smile == 1U) {
    sf_exported_auto_enablec11_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_d_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_setDistanceIfUserMoves == 1U) {
    sf_exported_auto_enablec8_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_e_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_gazeIfUserMoves == 1U) {
    sf_exported_auto_enablec10_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_f_subchartSimstruct);
  }
}

static void disable_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "pr3", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "pr2", 0);
  sf_call_output_fcn_disable(chartInstance->S, 2, "pr1", 0);
  if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
    sf_call_output_fcn_disable(chartInstance->S, 3, "sendBML", 0);
  }

  if (chartInstance->c1_is_active_RPSGameImitateSmileBrad == 1U) {
    sf_exported_auto_disablec5_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_Gaze == 1U) {
    sf_exported_auto_disablec9_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    sf_exported_auto_disablec4_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_smile == 1U) {
    sf_exported_auto_disablec11_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_d_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_setDistanceIfUserMoves == 1U) {
    sf_exported_auto_disablec8_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_e_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_gazeIfUserMoves == 1U) {
    sf_exported_auto_disablec10_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_f_subchartSimstruct);
  }
}

static void c1_update_debugger_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSs_Bdr_GK_BIS == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_RPSGameImitateSmileBrad == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Gaze == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_smile == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_setDistanceIfUserMoves == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_gazeIfUserMoves == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_pr1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_pr1 == c1_IN_B1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_pr1 == c1_IN_A1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_pr2 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_pr2 == c1_IN_A2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_pr2 == c1_IN_B2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_pr3 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_pr3 == c1_IN_B3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_pr3 == c1_IN_A3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_subchartSimStateInfo,
                sf_exported_auto_getSimstatec5_ARP_02_RPSs_Bdr_GK_BIS
                (chartInstance->c1_subchartSimstruct), true);
  sf_mex_assign(&c1_b_subchartSimStateInfo,
                sf_exported_auto_getSimstatec9_ARP_02_RPSs_Bdr_GK_BIS
                (chartInstance->c1_b_subchartSimstruct), true);
  sf_mex_assign(&c1_c_subchartSimStateInfo,
                sf_exported_auto_getSimstatec4_ARP_02_RPSs_Bdr_GK_BIS
                (chartInstance->c1_c_subchartSimstruct), true);
  sf_mex_assign(&c1_d_subchartSimStateInfo,
                sf_exported_auto_getSimstatec11_ARP_02_RPSs_Bdr_GK_BIS
                (chartInstance->c1_d_subchartSimstruct), true);
  sf_mex_assign(&c1_e_subchartSimStateInfo,
                sf_exported_auto_getSimstatec8_ARP_02_RPSs_Bdr_GK_BIS
                (chartInstance->c1_e_subchartSimstruct), true);
  sf_mex_assign(&c1_f_subchartSimStateInfo,
                sf_exported_auto_getSimstatec10_ARP_02_RPSs_Bdr_GK_BIS
                (chartInstance->c1_f_subchartSimstruct), true);
  sf_mex_assign(&c1_st, c1_emlrt_marshallOut(chartInstance), false);
  return c1_st;
}

static void set_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[256];
  int32_T c1_i1;
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
  c1_u = sf_mex_dup(c1_st);
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
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
                        "BML", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    c1_set_BML(chartInstance, c1_i1, c1_dv0[c1_i1]);
  }

  c1_set_BORED(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 8)), "BORED"));
  c1_set_BOREDOM_THRESHOLD(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 9)), "BOREDOM_THRESHOLD"));
  c1_set_CONTEMPT(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 10)), "CONTEMPT"));
  c1_set_EXCITE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "EXCITE"));
  c1_set_FEAR(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 12)), "FEAR"));
  c1_set_FRUST(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 13)), "FRUST"));
  c1_set_GAZE_GUI(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 14)), "GAZE_GUI"));
  c1_set_GAZE_SHOFTEYE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 15)), "GAZE_SHOFTEYE"));
  c1_set_GAZE_USER_HAND(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 16)), "GAZE_USER_HAND"));
  c1_set_GAZE_WIN(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 17)), "GAZE_WIN"));
  c1_set_HAPPY(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 18)), "HAPPY"));
  c1_set_IDLE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 19)), "IDLE"));
  c1_set_SAD(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
              (sf_mex_getcell(c1_u, 20)), "SAD"));
  c1_set_STATE_BEFORE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 21)), "STATE_BEFORE"));
  c1_set_STATE_GO(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 22)), "STATE_GO"));
  c1_set_STATE_HAND(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 23)), "STATE_HAND"));
  c1_set_STATE_OVER(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 24)), "STATE_OVER"));
  c1_set_STATE_READY(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 25)), "STATE_READY"));
  c1_set_STATE_RESULT(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 26)), "STATE_RESULT"));
  c1_set_STATE_WAITE(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 27)), "STATE_WAITE"));
  c1_set_avert(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 28)), "avert"));
  c1_set_bHand(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 29)), "bHand"));
  c1_set_boredom(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
                  (sf_mex_getcell(c1_u, 30)), "boredom"));
  c1_set_diff(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 31)), "diff"));
  c1_set_gazing(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 32)), "gazing"));
  c1_set_interest(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 33)), "interest"));
  c1_set_isPosing(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 34)), "isPosing"));
  c1_set_p(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 35)), "p"));
  c1_set_pr(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
             (sf_mex_getcell(c1_u, 36)), "pr"));
  c1_set_r(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 37)), "r"));
  c1_set_randAvertGazeChance(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 38)), "randAvertGazeChance"));
  c1_set_randGazeDur(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 39)), "randGazeDur"));
  c1_set_randPoseChance(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 40)), "randPoseChance"));
  c1_set_randSlowPose(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 41)), "randSlowPose"));
  c1_set_randSmile(chartInstance, 0, c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 42)), "randSmile"));
  c1_set_s(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 43)), "s"));
  chartInstance->c1_smileN = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 44)), "smileN");
  chartInstance->c1_t1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 45)), "t1");
  chartInstance->c1_t2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 46)), "t2");
  c1_set_temp(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 47)), "temp"));
  c1_set_uHand(chartInstance, 0, c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 48)), "uHand"));
  chartInstance->c1_is_active_c1_ARP_02_RPSs_Bdr_GK_BIS = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 49)),
     "is_active_c1_ARP_02_RPSs_Bdr_GK_BIS");
  chartInstance->c1_is_active_Gaze = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 50)), "is_active_Gaze");
  chartInstance->c1_is_active_idlePoseBrad = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 51)), "is_active_idlePoseBrad");
  chartInstance->c1_is_active_smile = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 52)), "is_active_smile");
  chartInstance->c1_is_active_setDistanceIfUserMoves = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 53)),
     "is_active_setDistanceIfUserMoves");
  chartInstance->c1_is_active_gazeIfUserMoves = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 54)),
     "is_active_gazeIfUserMoves");
  chartInstance->c1_is_active_pr1 = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 55)), "is_active_pr1");
  chartInstance->c1_is_active_RPSGameImitateSmileBrad = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 56)),
     "is_active_RPSGameImitateSmileBrad");
  chartInstance->c1_is_active_pr2 = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 57)), "is_active_pr2");
  chartInstance->c1_is_active_pr3 = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 58)), "is_active_pr3");
  chartInstance->c1_is_active_sendBMLbyPriority = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 59)),
     "is_active_sendBMLbyPriority");
  chartInstance->c1_is_pr1 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 60)), "is_pr1");
  chartInstance->c1_is_pr2 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 61)), "is_pr2");
  chartInstance->c1_is_pr3 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 62)), "is_pr3");
  sf_mex_assign(&c1_b_subchartSimStateInfo, c1_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 63)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_c_subchartSimStateInfo, c1_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 64)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_d_subchartSimStateInfo, c1_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 65)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_e_subchartSimStateInfo, c1_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 66)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_f_subchartSimStateInfo, c1_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 67)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_subchartSimStateInfo, c1_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 68)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 69)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
  sf_exported_auto_setSimstatec5_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_subchartSimstruct, sf_mex_dup(c1_subchartSimStateInfo));
  sf_exported_auto_setSimstatec9_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_b_subchartSimstruct, sf_mex_dup(c1_b_subchartSimStateInfo));
  sf_exported_auto_setSimstatec4_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_c_subchartSimstruct, sf_mex_dup(c1_c_subchartSimStateInfo));
  sf_exported_auto_setSimstatec11_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_d_subchartSimstruct, sf_mex_dup(c1_d_subchartSimStateInfo));
  sf_exported_auto_setSimstatec8_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_e_subchartSimstruct, sf_mex_dup(c1_e_subchartSimStateInfo));
  sf_exported_auto_setSimstatec10_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_f_subchartSimstruct, sf_mex_dup(c1_f_subchartSimStateInfo));
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_gazeIfUserMoves == 1U) {
      chartInstance->c1_tp_gazeIfUserMoves = 1U;
    } else {
      chartInstance->c1_tp_gazeIfUserMoves = 0U;
    }

    if (chartInstance->c1_is_active_RPSGameImitateSmileBrad == 1U) {
      chartInstance->c1_tp_RPSGameImitateSmileBrad = 1U;
    } else {
      chartInstance->c1_tp_RPSGameImitateSmileBrad = 0U;
    }

    if (chartInstance->c1_is_active_Gaze == 1U) {
      chartInstance->c1_tp_Gaze = 1U;
    } else {
      chartInstance->c1_tp_Gaze = 0U;
    }

    if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
      chartInstance->c1_tp_idlePoseBrad = 1U;
    } else {
      chartInstance->c1_tp_idlePoseBrad = 0U;
    }

    if (chartInstance->c1_is_active_smile == 1U) {
      chartInstance->c1_tp_smile = 1U;
    } else {
      chartInstance->c1_tp_smile = 0U;
    }

    if (chartInstance->c1_is_active_setDistanceIfUserMoves == 1U) {
      chartInstance->c1_tp_setDistanceIfUserMoves = 1U;
    } else {
      chartInstance->c1_tp_setDistanceIfUserMoves = 0U;
    }

    if (chartInstance->c1_is_active_sendBMLbyPriority == 1U) {
      chartInstance->c1_tp_sendBMLbyPriority = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        sf_call_output_fcn_enable(chartInstance->S, 3, "sendBML", 0);
      }
    } else {
      chartInstance->c1_tp_sendBMLbyPriority = 0U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) > 0.0) {
        sf_call_output_fcn_disable(chartInstance->S, 3, "sendBML", 0);
      }
    }

    if (chartInstance->c1_is_active_pr1 == 1U) {
      chartInstance->c1_tp_pr1 = 1U;
    } else {
      chartInstance->c1_tp_pr1 = 0U;
    }

    if (chartInstance->c1_is_pr1 == c1_IN_A1) {
      chartInstance->c1_tp_A1 = 1U;
    } else {
      chartInstance->c1_tp_A1 = 0U;
    }

    if (chartInstance->c1_is_pr1 == c1_IN_B1) {
      chartInstance->c1_tp_B1 = 1U;
    } else {
      chartInstance->c1_tp_B1 = 0U;
    }

    if (chartInstance->c1_is_active_pr2 == 1U) {
      chartInstance->c1_tp_pr2 = 1U;
    } else {
      chartInstance->c1_tp_pr2 = 0U;
    }

    if (chartInstance->c1_is_pr2 == c1_IN_A2) {
      chartInstance->c1_tp_A2 = 1U;
    } else {
      chartInstance->c1_tp_A2 = 0U;
    }

    if (chartInstance->c1_is_pr2 == c1_IN_B2) {
      chartInstance->c1_tp_B2 = 1U;
    } else {
      chartInstance->c1_tp_B2 = 0U;
    }

    if (chartInstance->c1_is_active_pr3 == 1U) {
      chartInstance->c1_tp_pr3 = 1U;
    } else {
      chartInstance->c1_tp_pr3 = 0U;
    }

    if (chartInstance->c1_is_pr3 == c1_IN_A3) {
      chartInstance->c1_tp_A3 = 1U;
    } else {
      chartInstance->c1_tp_A3 = 0U;
    }

    if (chartInstance->c1_is_pr3 == c1_IN_B3) {
      chartInstance->c1_tp_B3 = 1U;
    } else {
      chartInstance->c1_tp_B3 = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  sf_mex_destroy(&c1_subchartSimStateInfo);
  sf_mex_destroy(&c1_b_subchartSimStateInfo);
  sf_mex_destroy(&c1_c_subchartSimStateInfo);
  sf_mex_destroy(&c1_d_subchartSimStateInfo);
  sf_mex_destroy(&c1_e_subchartSimStateInfo);
  sf_mex_destroy(&c1_f_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  real_T *c1_gameState;
  real_T *c1_inputUser;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  real_T *c1_round;
  real_T *c1_isSmiling;
  real_T *c1_isInvading;
  real_T *c1_isMoving;
  real_T *c1_internalE;
  real_T *c1_inV;
  real_T *c1_inA;
  c1_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc5_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_gatewayc9_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_gatewayc4_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_gatewayc11_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_gatewayc8_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_gatewayc10_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_f_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_inputUser, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
  _SFD_DATA_RANGE_CHECK(c1_get_temp(chartInstance, 0), 5U);
  _SFD_DATA_RANGE_CHECK(c1_get_diff(chartInstance, 0), 6U);
  _SFD_DATA_RANGE_CHECK(c1_get_uHand(chartInstance, 0), 7U);
  _SFD_DATA_RANGE_CHECK(c1_get_bHand(chartInstance, 0), 8U);
  _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
  _SFD_DATA_RANGE_CHECK(c1_get_randSmile(chartInstance, 0), 11U);
  _SFD_DATA_RANGE_CHECK(c1_get_boredom(chartInstance, 0), 12U);
  _SFD_DATA_RANGE_CHECK(c1_get_BOREDOM_THRESHOLD(chartInstance, 0), 13U);
  _SFD_DATA_RANGE_CHECK(c1_get_randAvertGazeChance(chartInstance, 0), 14U);
  _SFD_DATA_RANGE_CHECK(c1_get_randPoseChance(chartInstance, 0), 15U);
  _SFD_DATA_RANGE_CHECK(c1_get_isPosing(chartInstance, 0), 16U);
  _SFD_DATA_RANGE_CHECK(c1_get_interest(chartInstance, 0), 17U);
  _SFD_DATA_RANGE_CHECK(c1_get_r(chartInstance, 0), 18U);
  _SFD_DATA_RANGE_CHECK(c1_get_p(chartInstance, 0), 19U);
  _SFD_DATA_RANGE_CHECK(c1_get_s(chartInstance, 0), 20U);
  _SFD_DATA_RANGE_CHECK(c1_get_randGazeDur(chartInstance, 0), 21U);
  _SFD_DATA_RANGE_CHECK(*c1_round, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 23U);
  _SFD_DATA_RANGE_CHECK(*c1_isSmiling, 24U);
  _SFD_DATA_RANGE_CHECK(c1_get_avert(chartInstance, 0), 25U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_GUI(chartInstance, 0), 26U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_SHOFTEYE(chartInstance, 0), 27U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_USER_HAND(chartInstance, 0), 28U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_READY(chartInstance, 0), 29U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_GO(chartInstance, 0), 30U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_HAND(chartInstance, 0), 31U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_OVER(chartInstance, 0), 32U);
  _SFD_DATA_RANGE_CHECK(c1_get_gazing(chartInstance, 0), 33U);
  _SFD_DATA_RANGE_CHECK(c1_get_GAZE_WIN(chartInstance, 0), 34U);
  _SFD_DATA_RANGE_CHECK(c1_get_randSlowPose(chartInstance, 0), 35U);
  _SFD_DATA_RANGE_CHECK(*c1_isInvading, 36U);
  _SFD_DATA_RANGE_CHECK(*c1_isMoving, 37U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_BEFORE(chartInstance, 0), 38U);
  _SFD_DATA_RANGE_CHECK(*c1_internalE, 39U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_RESULT(chartInstance, 0), 40U);
  _SFD_DATA_RANGE_CHECK(c1_get_STATE_WAITE(chartInstance, 0), 41U);
  _SFD_DATA_RANGE_CHECK(*c1_inV, 42U);
  _SFD_DATA_RANGE_CHECK(*c1_inA, 43U);
  _SFD_DATA_RANGE_CHECK(c1_get_HAPPY(chartInstance, 0), 44U);
  _SFD_DATA_RANGE_CHECK(c1_get_SAD(chartInstance, 0), 45U);
  _SFD_DATA_RANGE_CHECK(c1_get_CONTEMPT(chartInstance, 0), 46U);
  _SFD_DATA_RANGE_CHECK(c1_get_BORED(chartInstance, 0), 47U);
  _SFD_DATA_RANGE_CHECK(c1_get_FRUST(chartInstance, 0), 48U);
  _SFD_DATA_RANGE_CHECK(c1_get_FEAR(chartInstance, 0), 49U);
  _SFD_DATA_RANGE_CHECK(c1_get_IDLE(chartInstance, 0), 50U);
  _SFD_DATA_RANGE_CHECK(c1_get_EXCITE(chartInstance, 0), 51U);
  for (c1_i2 = 0; c1_i2 < 256; c1_i2++) {
    _SFD_DATA_RANGE_CHECK(c1_get_BML(chartInstance, c1_i2), 52U);
  }

  _SFD_DATA_RANGE_CHECK(c1_get_pr(chartInstance, 0), 53U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_t1, 54U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_t2, 55U);
  sf_exported_auto_activate_c5_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_activate_c9_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_activate_c4_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_activate_c11_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_activate_c8_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_activate_c10_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c5_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c9_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c4_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c11_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c10_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_f_subchartSimstruct);
  chartInstance->c1_sfEvent = c1_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_stepBuffersc5_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_stepBuffersc9_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_stepBuffersc4_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_stepBuffersc11_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_stepBuffersc8_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_stepBuffersc10_ARP_02_RPSs_Bdr_GK_BIS
    (chartInstance->c1_f_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSs_Bdr_GK_BIS == 0U) {
    sf_exported_auto_initBuffersc5_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_subchartSimstruct);
    sf_exported_auto_initBuffersc9_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_b_subchartSimstruct);
    sf_exported_auto_initBuffersc4_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_c_subchartSimstruct);
    sf_exported_auto_initBuffersc11_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_d_subchartSimstruct);
    sf_exported_auto_initBuffersc8_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_e_subchartSimstruct);
    sf_exported_auto_initBuffersc10_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_f_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_ARP_02_RPSs_Bdr_GK_BIS = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_gazeIfUserMoves = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_gazeIfUserMoves = 1U;
    sf_exported_auto_enterc10_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_f_subchartSimstruct);
    chartInstance->c1_is_active_RPSGameImitateSmileBrad = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_RPSGameImitateSmileBrad = 1U;
    sf_exported_auto_enterc5_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_subchartSimstruct);
    chartInstance->c1_is_active_Gaze = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_Gaze = 1U;
    sf_exported_auto_enterc9_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_b_subchartSimstruct);
    chartInstance->c1_is_active_idlePoseBrad = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_idlePoseBrad = 1U;
    sf_exported_auto_enterc4_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_c_subchartSimstruct);
    chartInstance->c1_is_active_smile = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_smile = 1U;
    sf_exported_auto_enterc11_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_d_subchartSimstruct);
    chartInstance->c1_is_active_setDistanceIfUserMoves = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_setDistanceIfUserMoves = 1U;
    sf_exported_auto_enterc8_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_e_subchartSimstruct);
    chartInstance->c1_is_active_sendBMLbyPriority = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_sendBMLbyPriority = 1U;
    sf_call_output_fcn_enable(chartInstance->S, 3, "sendBML", 0);
    chartInstance->c1_is_active_pr1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_pr1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_pr1 = c1_IN_A1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_A1 = 1U;
    chartInstance->c1_is_active_pr2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_pr2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_pr2 = c1_IN_A2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_A2 = 1U;
    chartInstance->c1_is_active_pr3 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_pr3 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_pr3 = c1_IN_A3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_A3 = 1U;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc10_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_f_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc5_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc9_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_b_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc4_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_c_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc11_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_d_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc8_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_e_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
    c1_sendBMLbyPriority(chartInstance);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_resetTemporalCounter_c5_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c9_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c4_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c11_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c10_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_f_subchartSimstruct);
  sf_exported_auto_deactivate_c5_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_deactivate_c9_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_deactivate_c4_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_deactivate_c11_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_deactivate_c8_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_e_subchartSimstruct);
  sf_exported_auto_deactivate_c10_ARP_02_RPSs_Bdr_GK_BIS_secs
    (chartInstance->c1_f_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c1_is_active_RPSGameImitateSmileBrad == 1U) {
    sf_exported_auto_check_state_inconsistency_c5_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_Gaze == 1U) {
    sf_exported_auto_check_state_inconsistency_c9_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    sf_exported_auto_check_state_inconsistency_c4_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_smile == 1U) {
    sf_exported_auto_check_state_inconsistency_c11_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_d_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_setDistanceIfUserMoves == 1U) {
    sf_exported_auto_check_state_inconsistency_c8_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_e_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_gazeIfUserMoves == 1U) {
    sf_exported_auto_check_state_inconsistency_c10_ARP_02_RPSs_Bdr_GK_BIS
      (chartInstance->c1_f_subchartSimstruct);
  }
}

static void initSimStructsc1_ARP_02_RPSs_Bdr_GK_BIS
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  chartInstance->c1_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "RPSGameImitateSmileBrad");
  chartInstance->c1_b_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "Gaze");
  chartInstance->c1_c_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "idlePoseBrad");
  chartInstance->c1_d_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "smile");
  chartInstance->c1_e_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "setDistanceIfUserMoves");
  chartInstance->c1_f_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "gazeIfUserMoves");
}

static void c1_sendBMLbyPriority(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  int32_T c1_i3;
  real_T c1_dv1[256];
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  int32_T c1_i4;
  real_T c1_dv2[256];
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  int32_T c1_i5;
  real_T c1_dv3[256];
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_pr1) {
   case c1_IN_A1:
    CV_STATE_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_d_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_out = CV_EML_IF(0, 0, 0, c1_get_pr(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_A1 = 0U;
      chartInstance->c1_is_pr1 = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      sf_call_output_fcn_call(chartInstance->S, 2, "pr1", 0);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c1_is_pr1 = c1_IN_B1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_B1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      for (c1_i3 = 0; c1_i3 < 256; c1_i3++) {
        c1_dv1[c1_i3] = c1_get_BML(chartInstance, c1_i3);
      }

      c1_sendBML(chartInstance, c1_dv1);
      chartInstance->c1_t2 = c1_get_pr(chartInstance, 0);
      c1_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_t2, 55U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 2U, 55U);
      sf_mex_printf("%s =\\n", "t2");
      c1_hoistedGlobal = chartInstance->c1_t2;
      c1_u = c1_hoistedGlobal;
      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_B1:
    CV_STATE_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_f_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_set_pr(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pr(chartInstance, 0), 53U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_tp_B1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_pr1 = c1_IN_A1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_A1 = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 0, 0);
    chartInstance->c1_is_pr1 = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_pr2) {
   case c1_IN_A2:
    CV_STATE_EVAL(8, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_g_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(4, 0, 0, c1_get_pr(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_A2 = 0U;
      chartInstance->c1_is_pr2 = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_h_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      sf_call_output_fcn_call(chartInstance->S, 1, "pr2", 0);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c1_is_pr2 = c1_IN_B2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_B2 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
        c1_dv2[c1_i4] = c1_get_BML(chartInstance, c1_i4);
      }

      c1_sendBML(chartInstance, c1_dv2);
      chartInstance->c1_t2 = c1_get_pr(chartInstance, 0);
      c1_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_t2, 55U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 2U, 55U);
      sf_mex_printf("%s =\\n", "t2");
      c1_b_hoistedGlobal = chartInstance->c1_t2;
      c1_b_u = c1_b_hoistedGlobal;
      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_B2:
    CV_STATE_EVAL(8, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_i_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_set_pr(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pr(chartInstance, 0), 53U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_tp_B2 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_pr2 = c1_IN_A2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_A2 = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(8, 0, 0);
    chartInstance->c1_is_pr2 = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_pr3) {
   case c1_IN_A3:
    CV_STATE_EVAL(11, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_j_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_c_out = CV_EML_IF(7, 0, 0, c1_get_pr(chartInstance, 0) == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_A3 = 0U;
      chartInstance->c1_is_pr3 = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      sf_call_output_fcn_call(chartInstance->S, 0, "pr3", 0);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c1_is_pr3 = c1_IN_B3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_B3 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      for (c1_i5 = 0; c1_i5 < 256; c1_i5++) {
        c1_dv3[c1_i5] = c1_get_BML(chartInstance, c1_i5);
      }

      c1_sendBML(chartInstance, c1_dv3);
      chartInstance->c1_t2 = c1_get_pr(chartInstance, 0);
      c1_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_t2, 55U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 2U, 55U);
      sf_mex_printf("%s =\\n", "t2");
      c1_c_hoistedGlobal = chartInstance->c1_t2;
      c1_c_u = c1_c_hoistedGlobal;
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_c_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_B3:
    CV_STATE_EVAL(11, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_l_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    c1_set_pr(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pr(chartInstance, 0), 53U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_tp_B3 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_pr3 = c1_IN_A3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_A3 = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(11, 0, 0);
    chartInstance->c1_is_pr3 = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
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

static real_T c1_b_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
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
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
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
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
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

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sf_internal_predicateOutput;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_sf_internal_predicateOutput = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_sf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_sf_internal_predicateOutput);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_sendBML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  real_T c1_arg[256])
{
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 14);
  for (c1_i6 = 0; c1_i6 < 256; c1_i6++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i6], 56U);
  }

  _SFD_SET_DATA_VALUE_PTR(56U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
  for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
    (*c1_b_arg)[c1_i7] = c1_arg[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 256; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i8], 56U);
  }

  sf_call_output_fcn_call(chartInstance->S, 3, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(56U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int8_T c1_d_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i9;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i9, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i9;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_secs;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_secs = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_secs), &c1_thisId);
  sf_mex_destroy(&c1_secs);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i10;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i10, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i10;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_RPSGameImitateSmileBrad, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_tp_RPSGameImitateSmileBrad), &c1_thisId);
  sf_mex_destroy(&c1_b_tp_RPSGameImitateSmileBrad);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
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

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_RPSGameImitateSmileBrad;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_b_tp_RPSGameImitateSmileBrad = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_tp_RPSGameImitateSmileBrad), &c1_thisId);
  sf_mex_destroy(&c1_b_tp_RPSGameImitateSmileBrad);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i11;
  real_T c1_b_inData[256];
  int32_T c1_i12;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i11 = 0; c1_i11 < 256; c1_i11++) {
    c1_b_inData[c1_i11] = (*(real_T (*)[256])c1_inData)[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
    c1_u[c1_i12] = c1_b_inData[c1_i12];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_BML, const char_T *c1_identifier, real_T
  c1_y[256])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_BML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_BML);
}

static void c1_i_emlrt_marshallIn(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256])
{
  real_T c1_dv4[256];
  int32_T c1_i13;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c1_i13 = 0; c1_i13 < 256; c1_i13++) {
    c1_y[c1_i13] = c1_dv4[c1_i13];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_BML;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[256];
  int32_T c1_i14;
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)chartInstanceVoid;
  c1_BML = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_BML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_BML);
  for (c1_i14 = 0; c1_i14 < 256; c1_i14++) {
    (*(real_T (*)[256])c1_outData)[c1_i14] = c1_y[c1_i14];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_emlrt_marshallOut
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  const mxArray *c1_y;
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
  int32_T c1_i15;
  real_T c1_h_u[256];
  const mxArray *c1_i_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_l_hoistedGlobal;
  real_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_m_hoistedGlobal;
  real_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  real_T c1_n_hoistedGlobal;
  real_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_o_hoistedGlobal;
  real_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_p_hoistedGlobal;
  real_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_q_hoistedGlobal;
  real_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_r_hoistedGlobal;
  real_T c1_s_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_s_hoistedGlobal;
  real_T c1_t_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_t_hoistedGlobal;
  real_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_u_hoistedGlobal;
  real_T c1_v_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_v_hoistedGlobal;
  real_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_w_hoistedGlobal;
  real_T c1_x_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_x_hoistedGlobal;
  real_T c1_y_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_y_hoistedGlobal;
  real_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  real_T c1_ab_hoistedGlobal;
  real_T c1_bb_u;
  const mxArray *c1_cb_y = NULL;
  real_T c1_bb_hoistedGlobal;
  real_T c1_cb_u;
  const mxArray *c1_db_y = NULL;
  real_T c1_cb_hoistedGlobal;
  real_T c1_db_u;
  const mxArray *c1_eb_y = NULL;
  real_T c1_db_hoistedGlobal;
  real_T c1_eb_u;
  const mxArray *c1_fb_y = NULL;
  real_T c1_eb_hoistedGlobal;
  real_T c1_fb_u;
  const mxArray *c1_gb_y = NULL;
  real_T c1_fb_hoistedGlobal;
  real_T c1_gb_u;
  const mxArray *c1_hb_y = NULL;
  real_T c1_gb_hoistedGlobal;
  real_T c1_hb_u;
  const mxArray *c1_ib_y = NULL;
  real_T c1_hb_hoistedGlobal;
  real_T c1_ib_u;
  const mxArray *c1_jb_y = NULL;
  real_T c1_ib_hoistedGlobal;
  real_T c1_jb_u;
  const mxArray *c1_kb_y = NULL;
  real_T c1_jb_hoistedGlobal;
  real_T c1_kb_u;
  const mxArray *c1_lb_y = NULL;
  real_T c1_kb_hoistedGlobal;
  real_T c1_lb_u;
  const mxArray *c1_mb_y = NULL;
  real_T c1_lb_hoistedGlobal;
  real_T c1_mb_u;
  const mxArray *c1_nb_y = NULL;
  real_T c1_mb_hoistedGlobal;
  real_T c1_nb_u;
  const mxArray *c1_ob_y = NULL;
  real_T c1_nb_hoistedGlobal;
  real_T c1_ob_u;
  const mxArray *c1_pb_y = NULL;
  real_T c1_ob_hoistedGlobal;
  real_T c1_pb_u;
  const mxArray *c1_qb_y = NULL;
  real_T c1_pb_hoistedGlobal;
  real_T c1_qb_u;
  const mxArray *c1_rb_y = NULL;
  real_T c1_qb_hoistedGlobal;
  real_T c1_rb_u;
  const mxArray *c1_sb_y = NULL;
  real_T c1_rb_hoistedGlobal;
  real_T c1_sb_u;
  const mxArray *c1_tb_y = NULL;
  real_T c1_sb_hoistedGlobal;
  real_T c1_tb_u;
  const mxArray *c1_ub_y = NULL;
  real_T c1_tb_hoistedGlobal;
  real_T c1_ub_u;
  const mxArray *c1_vb_y = NULL;
  real_T c1_ub_hoistedGlobal;
  real_T c1_vb_u;
  const mxArray *c1_wb_y = NULL;
  real_T c1_vb_hoistedGlobal;
  real_T c1_wb_u;
  const mxArray *c1_xb_y = NULL;
  real_T c1_wb_hoistedGlobal;
  real_T c1_xb_u;
  const mxArray *c1_yb_y = NULL;
  uint8_T c1_xb_hoistedGlobal;
  uint8_T c1_yb_u;
  const mxArray *c1_ac_y = NULL;
  uint8_T c1_yb_hoistedGlobal;
  uint8_T c1_ac_u;
  const mxArray *c1_bc_y = NULL;
  uint8_T c1_ac_hoistedGlobal;
  uint8_T c1_bc_u;
  const mxArray *c1_cc_y = NULL;
  uint8_T c1_bc_hoistedGlobal;
  uint8_T c1_cc_u;
  const mxArray *c1_dc_y = NULL;
  uint8_T c1_cc_hoistedGlobal;
  uint8_T c1_dc_u;
  const mxArray *c1_ec_y = NULL;
  uint8_T c1_dc_hoistedGlobal;
  uint8_T c1_ec_u;
  const mxArray *c1_fc_y = NULL;
  uint8_T c1_ec_hoistedGlobal;
  uint8_T c1_fc_u;
  const mxArray *c1_gc_y = NULL;
  uint8_T c1_fc_hoistedGlobal;
  uint8_T c1_gc_u;
  const mxArray *c1_hc_y = NULL;
  uint8_T c1_gc_hoistedGlobal;
  uint8_T c1_hc_u;
  const mxArray *c1_ic_y = NULL;
  uint8_T c1_hc_hoistedGlobal;
  uint8_T c1_ic_u;
  const mxArray *c1_jc_y = NULL;
  uint8_T c1_ic_hoistedGlobal;
  uint8_T c1_jc_u;
  const mxArray *c1_kc_y = NULL;
  uint8_T c1_jc_hoistedGlobal;
  uint8_T c1_kc_u;
  const mxArray *c1_lc_y = NULL;
  uint8_T c1_kc_hoistedGlobal;
  uint8_T c1_lc_u;
  const mxArray *c1_mc_y = NULL;
  uint8_T c1_lc_hoistedGlobal;
  uint8_T c1_mc_u;
  const mxArray *c1_nc_y = NULL;
  const mxArray *c1_nc_u;
  const mxArray *c1_oc_y = NULL;
  const mxArray *c1_oc_u;
  const mxArray *c1_pc_y = NULL;
  const mxArray *c1_pc_u;
  const mxArray *c1_qc_y = NULL;
  const mxArray *c1_qc_u;
  const mxArray *c1_rc_y = NULL;
  const mxArray *c1_rc_u;
  const mxArray *c1_sc_y = NULL;
  const mxArray *c1_sc_u;
  const mxArray *c1_tc_y = NULL;
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
  c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(69, 1), false);
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
  for (c1_i15 = 0; c1_i15 < 256; c1_i15++) {
    c1_h_u[c1_i15] = c1_get_BML(chartInstance, c1_i15);
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_h_hoistedGlobal = c1_get_BORED(chartInstance, 0);
  c1_i_u = c1_h_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_i_hoistedGlobal = c1_get_BOREDOM_THRESHOLD(chartInstance, 0);
  c1_j_u = c1_i_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_j_hoistedGlobal = c1_get_CONTEMPT(chartInstance, 0);
  c1_k_u = c1_j_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_k_hoistedGlobal = c1_get_EXCITE(chartInstance, 0);
  c1_l_u = c1_k_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_l_hoistedGlobal = c1_get_FEAR(chartInstance, 0);
  c1_m_u = c1_l_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_m_hoistedGlobal = c1_get_FRUST(chartInstance, 0);
  c1_n_u = c1_m_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_n_hoistedGlobal = c1_get_GAZE_GUI(chartInstance, 0);
  c1_o_u = c1_n_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_o_hoistedGlobal = c1_get_GAZE_SHOFTEYE(chartInstance, 0);
  c1_p_u = c1_o_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_p_hoistedGlobal = c1_get_GAZE_USER_HAND(chartInstance, 0);
  c1_q_u = c1_p_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_q_hoistedGlobal = c1_get_GAZE_WIN(chartInstance, 0);
  c1_r_u = c1_q_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_r_hoistedGlobal = c1_get_HAPPY(chartInstance, 0);
  c1_s_u = c1_r_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_s_hoistedGlobal = c1_get_IDLE(chartInstance, 0);
  c1_t_u = c1_s_hoistedGlobal;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_t_hoistedGlobal = c1_get_SAD(chartInstance, 0);
  c1_u_u = c1_t_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_u_hoistedGlobal = c1_get_STATE_BEFORE(chartInstance, 0);
  c1_v_u = c1_u_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_v_hoistedGlobal = c1_get_STATE_GO(chartInstance, 0);
  c1_w_u = c1_v_hoistedGlobal;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_w_hoistedGlobal = c1_get_STATE_HAND(chartInstance, 0);
  c1_x_u = c1_w_hoistedGlobal;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_x_hoistedGlobal = c1_get_STATE_OVER(chartInstance, 0);
  c1_y_u = c1_x_hoistedGlobal;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_y_hoistedGlobal = c1_get_STATE_READY(chartInstance, 0);
  c1_ab_u = c1_y_hoistedGlobal;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_ab_hoistedGlobal = c1_get_STATE_RESULT(chartInstance, 0);
  c1_bb_u = c1_ab_hoistedGlobal;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 26, c1_cb_y);
  c1_bb_hoistedGlobal = c1_get_STATE_WAITE(chartInstance, 0);
  c1_cb_u = c1_bb_hoistedGlobal;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_cb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 27, c1_db_y);
  c1_cb_hoistedGlobal = c1_get_avert(chartInstance, 0);
  c1_db_u = c1_cb_hoistedGlobal;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_db_hoistedGlobal = c1_get_bHand(chartInstance, 0);
  c1_eb_u = c1_db_hoistedGlobal;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_eb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 29, c1_fb_y);
  c1_eb_hoistedGlobal = c1_get_boredom(chartInstance, 0);
  c1_fb_u = c1_eb_hoistedGlobal;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_fb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 30, c1_gb_y);
  c1_fb_hoistedGlobal = c1_get_diff(chartInstance, 0);
  c1_gb_u = c1_fb_hoistedGlobal;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_gb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 31, c1_hb_y);
  c1_gb_hoistedGlobal = c1_get_gazing(chartInstance, 0);
  c1_hb_u = c1_gb_hoistedGlobal;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_hb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 32, c1_ib_y);
  c1_hb_hoistedGlobal = c1_get_interest(chartInstance, 0);
  c1_ib_u = c1_hb_hoistedGlobal;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_ib_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 33, c1_jb_y);
  c1_ib_hoistedGlobal = c1_get_isPosing(chartInstance, 0);
  c1_jb_u = c1_ib_hoistedGlobal;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_jb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 34, c1_kb_y);
  c1_jb_hoistedGlobal = c1_get_p(chartInstance, 0);
  c1_kb_u = c1_jb_hoistedGlobal;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_kb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 35, c1_lb_y);
  c1_kb_hoistedGlobal = c1_get_pr(chartInstance, 0);
  c1_lb_u = c1_kb_hoistedGlobal;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_lb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 36, c1_mb_y);
  c1_lb_hoistedGlobal = c1_get_r(chartInstance, 0);
  c1_mb_u = c1_lb_hoistedGlobal;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", &c1_mb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 37, c1_nb_y);
  c1_mb_hoistedGlobal = c1_get_randAvertGazeChance(chartInstance, 0);
  c1_nb_u = c1_mb_hoistedGlobal;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_nb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 38, c1_ob_y);
  c1_nb_hoistedGlobal = c1_get_randGazeDur(chartInstance, 0);
  c1_ob_u = c1_nb_hoistedGlobal;
  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", &c1_ob_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 39, c1_pb_y);
  c1_ob_hoistedGlobal = c1_get_randPoseChance(chartInstance, 0);
  c1_pb_u = c1_ob_hoistedGlobal;
  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", &c1_pb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 40, c1_qb_y);
  c1_pb_hoistedGlobal = c1_get_randSlowPose(chartInstance, 0);
  c1_qb_u = c1_pb_hoistedGlobal;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_qb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 41, c1_rb_y);
  c1_qb_hoistedGlobal = c1_get_randSmile(chartInstance, 0);
  c1_rb_u = c1_qb_hoistedGlobal;
  c1_sb_y = NULL;
  sf_mex_assign(&c1_sb_y, sf_mex_create("y", &c1_rb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 42, c1_sb_y);
  c1_rb_hoistedGlobal = c1_get_s(chartInstance, 0);
  c1_sb_u = c1_rb_hoistedGlobal;
  c1_tb_y = NULL;
  sf_mex_assign(&c1_tb_y, sf_mex_create("y", &c1_sb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 43, c1_tb_y);
  c1_sb_hoistedGlobal = chartInstance->c1_smileN;
  c1_tb_u = c1_sb_hoistedGlobal;
  c1_ub_y = NULL;
  sf_mex_assign(&c1_ub_y, sf_mex_create("y", &c1_tb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 44, c1_ub_y);
  c1_tb_hoistedGlobal = chartInstance->c1_t1;
  c1_ub_u = c1_tb_hoistedGlobal;
  c1_vb_y = NULL;
  sf_mex_assign(&c1_vb_y, sf_mex_create("y", &c1_ub_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 45, c1_vb_y);
  c1_ub_hoistedGlobal = chartInstance->c1_t2;
  c1_vb_u = c1_ub_hoistedGlobal;
  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", &c1_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 46, c1_wb_y);
  c1_vb_hoistedGlobal = c1_get_temp(chartInstance, 0);
  c1_wb_u = c1_vb_hoistedGlobal;
  c1_xb_y = NULL;
  sf_mex_assign(&c1_xb_y, sf_mex_create("y", &c1_wb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 47, c1_xb_y);
  c1_wb_hoistedGlobal = c1_get_uHand(chartInstance, 0);
  c1_xb_u = c1_wb_hoistedGlobal;
  c1_yb_y = NULL;
  sf_mex_assign(&c1_yb_y, sf_mex_create("y", &c1_xb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 48, c1_yb_y);
  c1_xb_hoistedGlobal = chartInstance->c1_is_active_c1_ARP_02_RPSs_Bdr_GK_BIS;
  c1_yb_u = c1_xb_hoistedGlobal;
  c1_ac_y = NULL;
  sf_mex_assign(&c1_ac_y, sf_mex_create("y", &c1_yb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 49, c1_ac_y);
  c1_yb_hoistedGlobal = chartInstance->c1_is_active_Gaze;
  c1_ac_u = c1_yb_hoistedGlobal;
  c1_bc_y = NULL;
  sf_mex_assign(&c1_bc_y, sf_mex_create("y", &c1_ac_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 50, c1_bc_y);
  c1_ac_hoistedGlobal = chartInstance->c1_is_active_idlePoseBrad;
  c1_bc_u = c1_ac_hoistedGlobal;
  c1_cc_y = NULL;
  sf_mex_assign(&c1_cc_y, sf_mex_create("y", &c1_bc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 51, c1_cc_y);
  c1_bc_hoistedGlobal = chartInstance->c1_is_active_smile;
  c1_cc_u = c1_bc_hoistedGlobal;
  c1_dc_y = NULL;
  sf_mex_assign(&c1_dc_y, sf_mex_create("y", &c1_cc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 52, c1_dc_y);
  c1_cc_hoistedGlobal = chartInstance->c1_is_active_setDistanceIfUserMoves;
  c1_dc_u = c1_cc_hoistedGlobal;
  c1_ec_y = NULL;
  sf_mex_assign(&c1_ec_y, sf_mex_create("y", &c1_dc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 53, c1_ec_y);
  c1_dc_hoistedGlobal = chartInstance->c1_is_active_gazeIfUserMoves;
  c1_ec_u = c1_dc_hoistedGlobal;
  c1_fc_y = NULL;
  sf_mex_assign(&c1_fc_y, sf_mex_create("y", &c1_ec_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 54, c1_fc_y);
  c1_ec_hoistedGlobal = chartInstance->c1_is_active_pr1;
  c1_fc_u = c1_ec_hoistedGlobal;
  c1_gc_y = NULL;
  sf_mex_assign(&c1_gc_y, sf_mex_create("y", &c1_fc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 55, c1_gc_y);
  c1_fc_hoistedGlobal = chartInstance->c1_is_active_RPSGameImitateSmileBrad;
  c1_gc_u = c1_fc_hoistedGlobal;
  c1_hc_y = NULL;
  sf_mex_assign(&c1_hc_y, sf_mex_create("y", &c1_gc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 56, c1_hc_y);
  c1_gc_hoistedGlobal = chartInstance->c1_is_active_pr2;
  c1_hc_u = c1_gc_hoistedGlobal;
  c1_ic_y = NULL;
  sf_mex_assign(&c1_ic_y, sf_mex_create("y", &c1_hc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 57, c1_ic_y);
  c1_hc_hoistedGlobal = chartInstance->c1_is_active_pr3;
  c1_ic_u = c1_hc_hoistedGlobal;
  c1_jc_y = NULL;
  sf_mex_assign(&c1_jc_y, sf_mex_create("y", &c1_ic_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 58, c1_jc_y);
  c1_ic_hoistedGlobal = chartInstance->c1_is_active_sendBMLbyPriority;
  c1_jc_u = c1_ic_hoistedGlobal;
  c1_kc_y = NULL;
  sf_mex_assign(&c1_kc_y, sf_mex_create("y", &c1_jc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 59, c1_kc_y);
  c1_jc_hoistedGlobal = chartInstance->c1_is_pr1;
  c1_kc_u = c1_jc_hoistedGlobal;
  c1_lc_y = NULL;
  sf_mex_assign(&c1_lc_y, sf_mex_create("y", &c1_kc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 60, c1_lc_y);
  c1_kc_hoistedGlobal = chartInstance->c1_is_pr2;
  c1_lc_u = c1_kc_hoistedGlobal;
  c1_mc_y = NULL;
  sf_mex_assign(&c1_mc_y, sf_mex_create("y", &c1_lc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 61, c1_mc_y);
  c1_lc_hoistedGlobal = chartInstance->c1_is_pr3;
  c1_mc_u = c1_lc_hoistedGlobal;
  c1_nc_y = NULL;
  sf_mex_assign(&c1_nc_y, sf_mex_create("y", &c1_mc_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 62, c1_nc_y);
  c1_nc_u = sf_mex_dup(c1_b_subchartSimStateInfo);
  c1_oc_y = NULL;
  sf_mex_assign(&c1_oc_y, sf_mex_duplicatearraysafe(&c1_nc_u), false);
  sf_mex_destroy(&c1_nc_u);
  sf_mex_setcell(c1_y, 63, c1_oc_y);
  c1_oc_u = sf_mex_dup(c1_c_subchartSimStateInfo);
  c1_pc_y = NULL;
  sf_mex_assign(&c1_pc_y, sf_mex_duplicatearraysafe(&c1_oc_u), false);
  sf_mex_destroy(&c1_oc_u);
  sf_mex_setcell(c1_y, 64, c1_pc_y);
  c1_pc_u = sf_mex_dup(c1_d_subchartSimStateInfo);
  c1_qc_y = NULL;
  sf_mex_assign(&c1_qc_y, sf_mex_duplicatearraysafe(&c1_pc_u), false);
  sf_mex_destroy(&c1_pc_u);
  sf_mex_setcell(c1_y, 65, c1_qc_y);
  c1_qc_u = sf_mex_dup(c1_e_subchartSimStateInfo);
  c1_rc_y = NULL;
  sf_mex_assign(&c1_rc_y, sf_mex_duplicatearraysafe(&c1_qc_u), false);
  sf_mex_destroy(&c1_qc_u);
  sf_mex_setcell(c1_y, 66, c1_rc_y);
  c1_rc_u = sf_mex_dup(c1_f_subchartSimStateInfo);
  c1_sc_y = NULL;
  sf_mex_assign(&c1_sc_y, sf_mex_duplicatearraysafe(&c1_rc_u), false);
  sf_mex_destroy(&c1_rc_u);
  sf_mex_setcell(c1_y, 67, c1_sc_y);
  c1_sc_u = sf_mex_dup(c1_subchartSimStateInfo);
  c1_tc_y = NULL;
  sf_mex_assign(&c1_tc_y, sf_mex_duplicatearraysafe(&c1_sc_u), false);
  sf_mex_destroy(&c1_sc_u);
  sf_mex_setcell(c1_y, 68, c1_tc_y);
  return c1_y;
}

static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c1_g_subchartSimStateInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_g_subchartSimStateInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_g_subchartSimStateInfo);
  return c1_y;
}

static const mxArray *c1_k_emlrt_marshallIn
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 2, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 2, 1,
    0)]);
}

static real_T c1_get_BML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#105) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_BML_address)[c1_b];
}

static void c1_set_BML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#105) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_BML_address)[c1_b] = c1_c;
}

static real_T *c1_access_BML(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c1_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#105) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_BML_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c1_c;
}

static real_T c1_get_BORED(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#100) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_BORED_address;
}

static void c1_set_BORED(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#100) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_BORED_address = c1_c;
}

static real_T *c1_access_BORED(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c1_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#100) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_BORED_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c1_c;
}

static real_T c1_get_BOREDOM_THRESHOLD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#66) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_BOREDOM_THRESHOLD_address;
}

static void c1_set_BOREDOM_THRESHOLD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#66) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_BOREDOM_THRESHOLD_address = c1_c;
}

static real_T *c1_access_BOREDOM_THRESHOLD
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c1_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#66) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_BOREDOM_THRESHOLD_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c1_c;
}

static real_T c1_get_CONTEMPT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#99) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_CONTEMPT_address;
}

static void c1_set_CONTEMPT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#99) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_CONTEMPT_address = c1_c;
}

static real_T *c1_access_CONTEMPT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c1_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#99) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_CONTEMPT_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c1_c;
}

static real_T c1_get_EXCITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#104) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_EXCITE_address;
}

static void c1_set_EXCITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#104) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_EXCITE_address = c1_c;
}

static real_T *c1_access_EXCITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c1_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#104) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_EXCITE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c1_c;
}

static real_T c1_get_FEAR(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#102) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_FEAR_address;
}

static void c1_set_FEAR(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#102) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_FEAR_address = c1_c;
}

static real_T *c1_access_FEAR(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c1_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#102) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_FEAR_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c1_c;
}

static real_T c1_get_FRUST(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#101) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_FRUST_address;
}

static void c1_set_FRUST(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#101) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_FRUST_address = c1_c;
}

static real_T *c1_access_FRUST(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c1_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#101) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_FRUST_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_GUI(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c1_b);
  if (chartInstance->c1_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#79) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_GUI_address;
}

static void c1_set_GAZE_GUI(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c1_b);
  if (chartInstance->c1_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#79) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_GUI_address = c1_c;
}

static real_T *c1_access_GAZE_GUI(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c1_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#79) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_GUI_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_SHOFTEYE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c1_b);
  if (chartInstance->c1_GAZE_SHOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SHOFTEYE\' (#80) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_SHOFTEYE_address;
}

static void c1_set_GAZE_SHOFTEYE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c1_b);
  if (chartInstance->c1_GAZE_SHOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SHOFTEYE\' (#80) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_SHOFTEYE_address = c1_c;
}

static real_T *c1_access_GAZE_SHOFTEYE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c1_GAZE_SHOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SHOFTEYE\' (#80) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_SHOFTEYE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_USER_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c1_b);
  if (chartInstance->c1_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#81) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_USER_HAND_address;
}

static void c1_set_GAZE_USER_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c1_b);
  if (chartInstance->c1_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#81) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_USER_HAND_address = c1_c;
}

static real_T *c1_access_GAZE_USER_HAND
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c1_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#81) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_USER_HAND_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c1_c;
}

static real_T c1_get_GAZE_WIN(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c1_b);
  if (chartInstance->c1_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#87) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_GAZE_WIN_address;
}

static void c1_set_GAZE_WIN(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c1_b);
  if (chartInstance->c1_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#87) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_GAZE_WIN_address = c1_c;
}

static real_T *c1_access_GAZE_WIN(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c1_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#87) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_GAZE_WIN_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c1_c;
}

static real_T c1_get_HAPPY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c1_b);
  if (chartInstance->c1_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#97) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_HAPPY_address;
}

static void c1_set_HAPPY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c1_b);
  if (chartInstance->c1_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#97) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_HAPPY_address = c1_c;
}

static real_T *c1_access_HAPPY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c1_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#97) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_HAPPY_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c1_c;
}

static real_T c1_get_IDLE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c1_b);
  if (chartInstance->c1_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#103) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_IDLE_address;
}

static void c1_set_IDLE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c1_b);
  if (chartInstance->c1_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#103) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_IDLE_address = c1_c;
}

static real_T *c1_access_IDLE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c1_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#103) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_IDLE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c1_c;
}

static real_T c1_get_SAD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c1_b);
  if (chartInstance->c1_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#98) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_SAD_address;
}

static void c1_set_SAD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c1_b);
  if (chartInstance->c1_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#98) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_SAD_address = c1_c;
}

static real_T *c1_access_SAD(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c1_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#98) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_SAD_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_BEFORE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c1_b);
  if (chartInstance->c1_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#91) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_BEFORE_address;
}

static void c1_set_STATE_BEFORE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c1_b);
  if (chartInstance->c1_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#91) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_BEFORE_address = c1_c;
}

static real_T *c1_access_STATE_BEFORE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c1_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#91) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_BEFORE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_GO(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c1_b);
  if (chartInstance->c1_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#83) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_GO_address;
}

static void c1_set_STATE_GO(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c1_b);
  if (chartInstance->c1_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#83) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_GO_address = c1_c;
}

static real_T *c1_access_STATE_GO(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c1_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#83) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_GO_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c1_b);
  if (chartInstance->c1_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#84) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_HAND_address;
}

static void c1_set_STATE_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c1_b);
  if (chartInstance->c1_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#84) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_HAND_address = c1_c;
}

static real_T *c1_access_STATE_HAND(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c1_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#84) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_HAND_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_OVER(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c1_b);
  if (chartInstance->c1_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#85) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_OVER_address;
}

static void c1_set_STATE_OVER(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c1_b);
  if (chartInstance->c1_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#85) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_OVER_address = c1_c;
}

static real_T *c1_access_STATE_OVER(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c1_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#85) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_OVER_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_READY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c1_b);
  if (chartInstance->c1_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#82) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_READY_address;
}

static void c1_set_STATE_READY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c1_b);
  if (chartInstance->c1_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#82) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_READY_address = c1_c;
}

static real_T *c1_access_STATE_READY(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c1_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#82) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_READY_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_RESULT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 19, NULL, c1_b);
  if (chartInstance->c1_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#93) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_RESULT_address;
}

static void c1_set_STATE_RESULT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 19, NULL, c1_b);
  if (chartInstance->c1_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#93) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_RESULT_address = c1_c;
}

static real_T *c1_access_STATE_RESULT(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 19, NULL);
  if (chartInstance->c1_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#93) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_RESULT_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 19, NULL);
  }

  return c1_c;
}

static real_T c1_get_STATE_WAITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 20, NULL, c1_b);
  if (chartInstance->c1_STATE_WAITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAITE\' (#94) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_STATE_WAITE_address;
}

static void c1_set_STATE_WAITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 20, NULL, c1_b);
  if (chartInstance->c1_STATE_WAITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAITE\' (#94) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_STATE_WAITE_address = c1_c;
}

static real_T *c1_access_STATE_WAITE(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 20, NULL);
  if (chartInstance->c1_STATE_WAITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAITE\' (#94) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_STATE_WAITE_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 20, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 21, NULL, c1_b);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#78) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_address;
}

static void c1_set_avert(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 21, NULL, c1_b);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#78) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_address = c1_c;
}

static real_T *c1_access_avert(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 21, NULL);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#78) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 21, NULL);
  }

  return c1_c;
}

static real_T c1_get_bHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 22, NULL, c1_b);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#61) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_bHand_address;
}

static void c1_set_bHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 22, NULL, c1_b);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#61) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_bHand_address = c1_c;
}

static real_T *c1_access_bHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 22, NULL);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#61) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_bHand_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 22, NULL);
  }

  return c1_c;
}

static real_T c1_get_boredom(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 23, NULL, c1_b);
  if (chartInstance->c1_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#65) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_boredom_address;
}

static void c1_set_boredom(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 23, NULL, c1_b);
  if (chartInstance->c1_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#65) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_boredom_address = c1_c;
}

static real_T *c1_access_boredom(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 23, NULL);
  if (chartInstance->c1_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#65) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_boredom_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 23, NULL);
  }

  return c1_c;
}

static real_T c1_get_diff(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 24, NULL, c1_b);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#59) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_diff_address;
}

static void c1_set_diff(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 24, NULL, c1_b);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#59) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_diff_address = c1_c;
}

static real_T *c1_access_diff(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 24, NULL);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#59) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_diff_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 24, NULL);
  }

  return c1_c;
}

static real_T c1_get_gazing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 25, NULL, c1_b);
  if (chartInstance->c1_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#86) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_gazing_address;
}

static void c1_set_gazing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 25, NULL, c1_b);
  if (chartInstance->c1_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#86) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_gazing_address = c1_c;
}

static real_T *c1_access_gazing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 25, NULL);
  if (chartInstance->c1_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#86) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_gazing_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 25, NULL);
  }

  return c1_c;
}

static real_T c1_get_interest(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 26, NULL, c1_b);
  if (chartInstance->c1_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#70) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_interest_address;
}

static void c1_set_interest(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 26, NULL, c1_b);
  if (chartInstance->c1_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#70) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_interest_address = c1_c;
}

static real_T *c1_access_interest(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 26, NULL);
  if (chartInstance->c1_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#70) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_interest_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 26, NULL);
  }

  return c1_c;
}

static real_T c1_get_isPosing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 27, NULL, c1_b);
  if (chartInstance->c1_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#69) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_isPosing_address;
}

static void c1_set_isPosing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 27, NULL, c1_b);
  if (chartInstance->c1_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#69) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_isPosing_address = c1_c;
}

static real_T *c1_access_isPosing(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 27, NULL);
  if (chartInstance->c1_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#69) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_isPosing_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 27, NULL);
  }

  return c1_c;
}

static real_T c1_get_p(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 28, NULL, c1_b);
  if (chartInstance->c1_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#72) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_p_address;
}

static void c1_set_p(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                     uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 28, NULL, c1_b);
  if (chartInstance->c1_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#72) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_p_address = c1_c;
}

static real_T *c1_access_p(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 28, NULL);
  if (chartInstance->c1_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#72) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_p_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 28, NULL);
  }

  return c1_c;
}

static real_T c1_get_pr(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 29, NULL, c1_b);
  if (chartInstance->c1_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#106) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pr_address;
}

static void c1_set_pr(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                      uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 29, NULL, c1_b);
  if (chartInstance->c1_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#106) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pr_address = c1_c;
}

static real_T *c1_access_pr(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 29, NULL);
  if (chartInstance->c1_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#106) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pr_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 29, NULL);
  }

  return c1_c;
}

static real_T c1_get_r(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 30, NULL, c1_b);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#71) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_r_address;
}

static void c1_set_r(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                     uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 30, NULL, c1_b);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#71) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_r_address = c1_c;
}

static real_T *c1_access_r(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 30, NULL);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#71) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_r_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 30, NULL);
  }

  return c1_c;
}

static real_T c1_get_randAvertGazeChance
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 31, NULL, c1_b);
  if (chartInstance->c1_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#67) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randAvertGazeChance_address;
}

static void c1_set_randAvertGazeChance(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 31, NULL, c1_b);
  if (chartInstance->c1_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#67) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randAvertGazeChance_address = c1_c;
}

static real_T *c1_access_randAvertGazeChance
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 31, NULL);
  if (chartInstance->c1_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#67) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randAvertGazeChance_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 31, NULL);
  }

  return c1_c;
}

static real_T c1_get_randGazeDur(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 32, NULL, c1_b);
  if (chartInstance->c1_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#74) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randGazeDur_address;
}

static void c1_set_randGazeDur(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 32, NULL, c1_b);
  if (chartInstance->c1_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#74) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randGazeDur_address = c1_c;
}

static real_T *c1_access_randGazeDur(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 32, NULL);
  if (chartInstance->c1_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#74) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randGazeDur_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 32, NULL);
  }

  return c1_c;
}

static real_T c1_get_randPoseChance(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 33, NULL, c1_b);
  if (chartInstance->c1_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#68) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randPoseChance_address;
}

static void c1_set_randPoseChance(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 33, NULL, c1_b);
  if (chartInstance->c1_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#68) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randPoseChance_address = c1_c;
}

static real_T *c1_access_randPoseChance
  (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 33, NULL);
  if (chartInstance->c1_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#68) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randPoseChance_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 33, NULL);
  }

  return c1_c;
}

static real_T c1_get_randSlowPose(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 34, NULL, c1_b);
  if (chartInstance->c1_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#88) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randSlowPose_address;
}

static void c1_set_randSlowPose(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 34, NULL, c1_b);
  if (chartInstance->c1_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#88) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randSlowPose_address = c1_c;
}

static real_T *c1_access_randSlowPose(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 34, NULL);
  if (chartInstance->c1_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#88) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randSlowPose_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 34, NULL);
  }

  return c1_c;
}

static real_T c1_get_randSmile(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 35, NULL, c1_b);
  if (chartInstance->c1_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#64) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randSmile_address;
}

static void c1_set_randSmile(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 35, NULL, c1_b);
  if (chartInstance->c1_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#64) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randSmile_address = c1_c;
}

static real_T *c1_access_randSmile(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 35, NULL);
  if (chartInstance->c1_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#64) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randSmile_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 35, NULL);
  }

  return c1_c;
}

static real_T c1_get_s(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 36, NULL, c1_b);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#73) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_s_address;
}

static void c1_set_s(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
                     uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 36, NULL, c1_b);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#73) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_s_address = c1_c;
}

static real_T *c1_access_s(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 36, NULL);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#73) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_s_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 36, NULL);
  }

  return c1_c;
}

static real_T c1_get_temp(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 37, NULL, c1_b);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#58) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_temp_address;
}

static void c1_set_temp(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 37, NULL, c1_b);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#58) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_temp_address = c1_c;
}

static real_T *c1_access_temp(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 37, NULL);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#58) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_temp_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 37, NULL);
  }

  return c1_c;
}

static real_T c1_get_uHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 38, NULL, c1_b);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#60) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_uHand_address;
}

static void c1_set_uHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 38, NULL, c1_b);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#60) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_uHand_address = c1_c;
}

static real_T *c1_access_uHand(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 38, NULL);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#60) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_uHand_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 38, NULL);
  }

  return c1_c;
}

static void init_dsm_address_info(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c1_BML_address, &chartInstance->c1_BML_index);
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
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_SHOFTEYE", (void **)
    &chartInstance->c1_GAZE_SHOFTEYE_address,
    &chartInstance->c1_GAZE_SHOFTEYE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_USER_HAND", (void **)
    &chartInstance->c1_GAZE_USER_HAND_address,
    &chartInstance->c1_GAZE_USER_HAND_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c1_GAZE_WIN_address, &chartInstance->c1_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "HAPPY", (void **)
    &chartInstance->c1_HAPPY_address, &chartInstance->c1_HAPPY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "IDLE", (void **)
    &chartInstance->c1_IDLE_address, &chartInstance->c1_IDLE_index);
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
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_WAITE", (void **)
    &chartInstance->c1_STATE_WAITE_address, &chartInstance->c1_STATE_WAITE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c1_avert_address, &chartInstance->c1_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c1_bHand_address, &chartInstance->c1_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c1_boredom_address, &chartInstance->c1_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c1_diff_address, &chartInstance->c1_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c1_gazing_address, &chartInstance->c1_gazing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c1_interest_address, &chartInstance->c1_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c1_isPosing_address, &chartInstance->c1_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "p", (void **)
    &chartInstance->c1_p_address, &chartInstance->c1_p_index);
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

void sf_c1_ARP_02_RPSs_Bdr_GK_BIS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1788556108U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2712237161U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(458183874U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3086612301U);
}

mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kjo8YkWB0ipxq3awIElsnE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

    mxArray *mxData = mxCreateStructMatrix(1,42,3,dataFields);

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
      pr[0] = (double)(256);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_ARP_02_RPSs_Bdr_GK_BIS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[469],T\"bWinT\",},{M[1],M[390],T\"bradHand\",},{M[1],M[464],T\"gameState\",},{M[1],M[713],T\"round\",},{M[1],M[470],T\"uWinT\",},{M[1],M[461],T\"userHand\",},{M[1],M[459],T\"win\",},{M[3],M[953],T\"BML\",},{M[3],M[911],T\"BORED\",},{M[3],M[568],T\"BOREDOM_THRESHOLD\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[910],T\"CONTEMPT\",},{M[3],M[915],T\"EXCITE\",},{M[3],M[913],T\"FEAR\",},{M[3],M[912],T\"FRUST\",},{M[3],M[837],T\"GAZE_GUI\",},{M[3],M[838],T\"GAZE_SHOFTEYE\",},{M[3],M[839],T\"GAZE_USER_HAND\",},{M[3],M[845],T\"GAZE_WIN\",},{M[3],M[908],T\"HAPPY\",},{M[3],M[914],T\"IDLE\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[909],T\"SAD\",},{M[3],M[850],T\"STATE_BEFORE\",},{M[3],M[841],T\"STATE_GO\",},{M[3],M[842],T\"STATE_HAND\",},{M[3],M[843],T\"STATE_OVER\",},{M[3],M[840],T\"STATE_READY\",},{M[3],M[903],T\"STATE_RESULT\",},{M[3],M[904],T\"STATE_WAITE\",},{M[3],M[756],T\"avert\",},{M[3],M[468],T\"bHand\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[567],T\"boredom\",},{M[3],M[462],T\"diff\",},{M[3],M[844],T\"gazing\",},{M[3],M[641],T\"interest\",},{M[3],M[636],T\"isPosing\",},{M[3],M[660],T\"p\",},{M[3],M[958],T\"pr\",},{M[3],M[659],T\"r\",},{M[3],M[596],T\"randAvertGazeChance\",},{M[3],M[688],T\"randGazeDur\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[635],T\"randPoseChance\",},{M[3],M[847],T\"randSlowPose\",},{M[3],M[566],T\"randSmile\",},{M[3],M[661],T\"s\",},{M[3],M[754],T\"smileN\",},{M[3],M[1109],T\"t1\",},{M[3],M[1110],T\"t2\",},{M[3],M[460],T\"temp\",},{M[3],M[467],T\"uHand\",},{M[8],M[0],T\"is_active_c1_ARP_02_RPSs_Bdr_GK_BIS\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[831],T\"is_active_Gaze\",},{M[8],M[832],T\"is_active_idlePoseBrad\",},{M[8],M[835],T\"is_active_smile\",},{M[8],M[879],T\"is_active_setDistanceIfUserMoves\",},{M[8],M[901],T\"is_active_gazeIfUserMoves\",},{M[8],M[938],T\"is_active_pr1\",},{M[8],M[1061],T\"is_active_RPSGameImitateSmileBrad\",},{M[8],M[1063],T\"is_active_pr2\",},{M[8],M[1069],T\"is_active_pr3\",},{M[8],M[1078],T\"is_active_sendBMLbyPriority\",}}",
    "100 S1x9'type','srcId','name','auxInfo'{{M[9],M[938],T\"is_pr1\",},{M[9],M[1063],T\"is_pr2\",},{M[9],M[1069],T\"is_pr3\",},{M[14],M[831],T\"subchartSimStateInfo\",},{M[14],M[832],T\"subchartSimStateInfo\",},{M[14],M[835],T\"subchartSimStateInfo\",},{M[14],M[879],T\"subchartSimStateInfo\",},{M[14],M[901],T\"subchartSimStateInfo\",},{M[14],M[1061],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 69, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ARP_02_RPSs_Bdr_GK_BIS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
           1,
           17,
           9,
           0,
           57,
           4,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
            chartInstance->chartNumber,
            4,
            4,
            4);
          _SFD_SET_DATA_PROPS(0,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inputUser");
          _SFD_SET_DATA_PROPS(2,2,0,1,"bradHand");
          _SFD_SET_DATA_PROPS(3,2,0,1,"userHand");
          _SFD_SET_DATA_PROPS(4,2,0,1,"win");
          _SFD_SET_DATA_PROPS(5,0,0,0,"temp");
          _SFD_SET_DATA_PROPS(6,0,0,0,"diff");
          _SFD_SET_DATA_PROPS(7,0,0,0,"uHand");
          _SFD_SET_DATA_PROPS(8,0,0,0,"bHand");
          _SFD_SET_DATA_PROPS(9,2,0,1,"bWinT");
          _SFD_SET_DATA_PROPS(10,2,0,1,"uWinT");
          _SFD_SET_DATA_PROPS(11,0,0,0,"randSmile");
          _SFD_SET_DATA_PROPS(12,0,0,0,"boredom");
          _SFD_SET_DATA_PROPS(13,0,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(14,0,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(15,0,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(16,0,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(17,0,0,0,"interest");
          _SFD_SET_DATA_PROPS(18,0,0,0,"r");
          _SFD_SET_DATA_PROPS(19,0,0,0,"p");
          _SFD_SET_DATA_PROPS(20,0,0,0,"s");
          _SFD_SET_DATA_PROPS(21,0,0,0,"randGazeDur");
          _SFD_SET_DATA_PROPS(22,2,0,1,"round");
          _SFD_SET_DATA_PROPS(23,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(24,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(25,0,0,0,"avert");
          _SFD_SET_DATA_PROPS(26,0,0,0,"GAZE_GUI");
          _SFD_SET_DATA_PROPS(27,0,0,0,"GAZE_SHOFTEYE");
          _SFD_SET_DATA_PROPS(28,0,0,0,"GAZE_USER_HAND");
          _SFD_SET_DATA_PROPS(29,0,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(30,0,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(31,0,0,0,"STATE_HAND");
          _SFD_SET_DATA_PROPS(32,0,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(33,0,0,0,"gazing");
          _SFD_SET_DATA_PROPS(34,0,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(35,0,0,0,"randSlowPose");
          _SFD_SET_DATA_PROPS(36,1,1,0,"isInvading");
          _SFD_SET_DATA_PROPS(37,1,1,0,"isMoving");
          _SFD_SET_DATA_PROPS(38,0,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(39,1,1,0,"internalE");
          _SFD_SET_DATA_PROPS(40,0,0,0,"STATE_RESULT");
          _SFD_SET_DATA_PROPS(41,0,0,0,"STATE_WAITE");
          _SFD_SET_DATA_PROPS(42,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(43,1,1,0,"inA");
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
          _SFD_SET_DATA_PROPS(56,8,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,2);
          _SFD_EVENT_SCOPE(3,2);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,1,1);
          _SFD_STATE_INFO(5,0,1);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,1);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(15,0,1);
          _SFD_STATE_INFO(16,0,1);
          _SFD_STATE_INFO(14,0,2);
          _SFD_CH_SUBSTATE_COUNT(7);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,0);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,16);
          _SFD_CH_SUBSTATE_INDEX(5,15);
          _SFD_CH_SUBSTATE_INDEX(6,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(4,3);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,8);
          _SFD_ST_SUBSTATE_INDEX(4,2,11);
          _SFD_ST_SUBSTATE_COUNT(5,2);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,2);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,2);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
        }

        _SFD_CV_INIT_CHART(7,0,0,0);

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
          _SFD_CV_INIT_STATE(4,3,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,6,1,6);
        _SFD_CV_INIT_EML(1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,6,1,6);
        _SFD_CV_INIT_EML(5,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,6,1,6);
        _SFD_CV_INIT_EML(8,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
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
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
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
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
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
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(56,(void *)(NULL));

        {
          real_T *c1_gameState;
          real_T *c1_inputUser;
          real_T *c1_bradHand;
          real_T *c1_userHand;
          real_T *c1_win;
          real_T *c1_bWinT;
          real_T *c1_uWinT;
          real_T *c1_round;
          real_T *c1_isSmiling;
          real_T *c1_isInvading;
          real_T *c1_isMoving;
          real_T *c1_internalE;
          real_T *c1_inV;
          real_T *c1_inA;
          c1_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_win);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c1_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c1_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c1_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c1_randSmile_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c1_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(13U,
            chartInstance->c1_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(14U,
            chartInstance->c1_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c1_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c1_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c1_interest_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c1_r_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c1_p_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c1_s_address);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c1_randGazeDur_address);
          _SFD_SET_DATA_VALUE_PTR(22U, c1_round);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c1_smileN);
          _SFD_SET_DATA_VALUE_PTR(24U, c1_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c1_avert_address);
          _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c1_GAZE_GUI_address);
          _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c1_GAZE_SHOFTEYE_address);
          _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c1_GAZE_USER_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c1_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c1_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c1_STATE_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c1_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(33U, chartInstance->c1_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c1_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c1_randSlowPose_address);
          _SFD_SET_DATA_VALUE_PTR(36U, c1_isInvading);
          _SFD_SET_DATA_VALUE_PTR(37U, c1_isMoving);
          _SFD_SET_DATA_VALUE_PTR(38U, chartInstance->c1_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(39U, c1_internalE);
          _SFD_SET_DATA_VALUE_PTR(40U, chartInstance->c1_STATE_RESULT_address);
          _SFD_SET_DATA_VALUE_PTR(41U, chartInstance->c1_STATE_WAITE_address);
          _SFD_SET_DATA_VALUE_PTR(42U, c1_inV);
          _SFD_SET_DATA_VALUE_PTR(43U, c1_inA);
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
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSs_Bdr_GK_BISMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "IZIYkpyBM62Ct1mxx3SsYF";
}

static void sf_opaque_initialize_c1_ARP_02_RPSs_Bdr_GK_BIS(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
  initialize_c1_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ARP_02_RPSs_Bdr_GK_BIS(void *chartInstanceVar)
{
  enable_c1_ARP_02_RPSs_Bdr_GK_BIS((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_ARP_02_RPSs_Bdr_GK_BIS(void *chartInstanceVar)
{
  disable_c1_ARP_02_RPSs_Bdr_GK_BIS((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_ARP_02_RPSs_Bdr_GK_BIS(void *chartInstanceVar)
{
  sf_gateway_c1_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ARP_02_RPSs_Bdr_GK_BIS();/* state var info */
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

extern void sf_internal_set_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_ARP_02_RPSs_Bdr_GK_BIS();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS(S);
}

static void sf_opaque_set_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS(S, st);
}

static void sf_opaque_terminate_c1_ARP_02_RPSs_Bdr_GK_BIS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSs_Bdr_GK_BIS_optimization_info();
    }

    finalize_c1_ARP_02_RPSs_Bdr_GK_BIS
      ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
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
    initialize_params_c1_ARP_02_RPSs_Bdr_GK_BIS
      ((SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSs_Bdr_GK_BIS_optimization_info();
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
      (),infoStruct,1,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
    }

    ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1990620227U));
  ssSetChecksum1(S,(794551203U));
  ssSetChecksum2(S,(1160379712U));
  ssSetChecksum3(S,(47072391U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
{
  SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)utMalloc(sizeof
    (SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ARP_02_RPSs_Bdr_GK_BISInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ARP_02_RPSs_Bdr_GK_BIS;
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

void c1_ARP_02_RPSs_Bdr_GK_BIS_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ARP_02_RPSs_Bdr_GK_BIS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ARP_02_RPSs_Bdr_GK_BIS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ARP_02_RPSs_Bdr_GK_BIS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ARP_02_RPSs_Bdr_GK_BIS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
