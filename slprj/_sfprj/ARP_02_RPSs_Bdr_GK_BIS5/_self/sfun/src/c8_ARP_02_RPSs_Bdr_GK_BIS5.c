/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSs_Bdr_GK_BIS5_sfun.h"
#include "c8_ARP_02_RPSs_Bdr_GK_BIS5.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSs_Bdr_GK_BIS5_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c8_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c8_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c8_IN_browUp                   ((uint8_T)1U)
#define c8_IN_checkUserCoord           ((uint8_T)2U)
#define c8_IN_gazeSurprized            ((uint8_T)3U)
#define c8_IN_headNeuralGazeCamera     ((uint8_T)4U)
#define c8_IN_idle                     ((uint8_T)5U)
#define c8_IN_leanFW                   ((uint8_T)6U)
#define c8_IN_leanNeutral              ((uint8_T)7U)
#define c8_IN_stateInit                ((uint8_T)8U)
#define c8_IN_stateWalkBack            ((uint8_T)9U)
#define c8_IN_wait                     ((uint8_T)10U)
#define c8_IN_walkFW                   ((uint8_T)11U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[13] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c8_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_wb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c8_dataWrittenToVector[10];

/* Function Declarations */
static void initialize_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void enable_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void disable_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_st);
static void c8_set_sim_state_side_effects_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void finalize_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void sf_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_enter_atomic_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_enter_internal_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_exit_internal_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_initc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void initSimStructsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_stateInit(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c8_enter_atomic_idle(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c8_enter_atomic_leanFW(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c8_enter_atomic_browUp(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c8_checkUserCoord(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c8_enter_atomic_stateWalkBack
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_enter_atomic_leanNeutral
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_leanNeutral(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c8_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_b_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_c_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_d_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_e_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_f_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_g_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_fprintf(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
  real_T c8_fileID);
static void c8_isequal(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_eml_switch_helper(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c8_b_fprintf(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_fileID);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static real_T c8_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_feval, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_c_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static boolean_T c8_d_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_e_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256]);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_i_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_j_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_k_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_l_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_m_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_n_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_o_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_p_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_q_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_r_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(const char * c8_u);
static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u);
static void c8_activate_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_deactivate_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_increment_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_reset_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, real_T c8_bmlID,
   real_T *c8_p, real_T c8_poseBML[256]);
static const mxArray *c8_s_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int8_T c8_f_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_t_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_g_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_u_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static uint8_T c8_h_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, const mxArray *c8_b_tp_stateInit, const char_T *c8_identifier);
static uint8_T c8_i_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_j_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_b_setSimStateSideEffectsInfo, const char_T *c8_identifier);
static const mxArray *c8_k_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_updateDataWrittenToVector
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex);
static void c8_errorIfDataNotWrittenToFcn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex, uint32_T c8_dataNumber);
static real_T c8_get_BML1(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_BML1(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_BML1(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_P(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_P(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                     uint32_T c8_b, real_T c8_c);
static real_T *c8_access_P(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, uint32_T c8_b);
static real_T c8_get_avert(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_avert(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_avert(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_fileID(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_fileID(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_fileID(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                      uint32_T c8_b, real_T c8_c);
static real_T *c8_access_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b);
static void init_dsm_address_info(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_update_debugger_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c8_prevAniVal;
  c8_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS5 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 ==
      c8_IN_headNeuralGazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_leanFW) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_browUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_checkUserCoord) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_stateWalkBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_gazeSurprized) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_walkFW) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_leanNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
  }

  _SFD_SET_ANIMATION(c8_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_hoistedGlobal;
  real_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real_T c8_d_hoistedGlobal;
  real_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  real_T c8_e_hoistedGlobal;
  real_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  real_T c8_f_hoistedGlobal;
  real_T c8_f_u;
  const mxArray *c8_g_y = NULL;
  real_T c8_g_hoistedGlobal;
  real_T c8_g_u;
  const mxArray *c8_h_y = NULL;
  real_T c8_h_hoistedGlobal;
  real_T c8_h_u;
  const mxArray *c8_i_y = NULL;
  uint8_T c8_i_hoistedGlobal;
  uint8_T c8_i_u;
  const mxArray *c8_j_y = NULL;
  uint8_T c8_j_hoistedGlobal;
  uint8_T c8_j_u;
  const mxArray *c8_k_y = NULL;
  uint8_T c8_k_hoistedGlobal;
  uint8_T c8_k_u;
  const mxArray *c8_l_y = NULL;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(11, 1), false);
  c8_hoistedGlobal = *c8_gameState;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = chartInstance->c8_NEUTRAL;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = chartInstance->c8_TOO_CLOSE;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = chartInstance->c8_TOO_FAR;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_e_hoistedGlobal = chartInstance->c8_closeBuffer;
  c8_e_u = c8_e_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  c8_f_hoistedGlobal = chartInstance->c8_farBuffer;
  c8_f_u = c8_f_hoistedGlobal;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 5, c8_g_y);
  c8_g_hoistedGlobal = chartInstance->c8_neutralBuffer;
  c8_g_u = c8_g_hoistedGlobal;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 6, c8_h_y);
  c8_h_hoistedGlobal = chartInstance->c8_position;
  c8_h_u = c8_h_hoistedGlobal;
  c8_i_y = NULL;
  sf_mex_assign(&c8_i_y, sf_mex_create("y", &c8_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 7, c8_i_y);
  c8_i_hoistedGlobal = chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  c8_i_u = c8_i_hoistedGlobal;
  c8_j_y = NULL;
  sf_mex_assign(&c8_j_y, sf_mex_create("y", &c8_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 8, c8_j_y);
  c8_j_hoistedGlobal = chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  c8_j_u = c8_j_hoistedGlobal;
  c8_k_y = NULL;
  sf_mex_assign(&c8_k_y, sf_mex_create("y", &c8_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 9, c8_k_y);
  c8_k_hoistedGlobal = chartInstance->c8_temporalCounter_i1;
  c8_k_u = c8_k_hoistedGlobal;
  c8_l_y = NULL;
  sf_mex_assign(&c8_l_y, sf_mex_create("y", &c8_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 10, c8_l_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_u = sf_mex_dup(c8_st);
  *c8_gameState = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 0)), "gameState");
  chartInstance->c8_NEUTRAL = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 1)), "NEUTRAL");
  chartInstance->c8_TOO_CLOSE = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 2)), "TOO_CLOSE");
  chartInstance->c8_TOO_FAR = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 3)), "TOO_FAR");
  chartInstance->c8_closeBuffer = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 4)), "closeBuffer");
  chartInstance->c8_farBuffer = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 5)), "farBuffer");
  chartInstance->c8_neutralBuffer = c8_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 6)), "neutralBuffer");
  chartInstance->c8_position = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 7)), "position");
  chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 8)),
     "is_active_c8_ARP_02_RPSs_Bdr_GK_BIS5");
  chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 9)),
     "is_c8_ARP_02_RPSs_Bdr_GK_BIS5");
  chartInstance->c8_temporalCounter_i1 = c8_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 10)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c8_setSimStateSideEffectsInfo,
                c8_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 11)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c8_u);
  chartInstance->c8_doSetSimStateSideEffects = 1U;
  c8_update_debugger_state_c8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void c8_set_sim_state_side_effects_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  if (chartInstance->c8_doSetSimStateSideEffects != 0) {
    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_browUp) {
      chartInstance->c8_tp_browUp = 1U;
    } else {
      chartInstance->c8_tp_browUp = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_checkUserCoord)
    {
      chartInstance->c8_tp_checkUserCoord = 1U;
    } else {
      chartInstance->c8_tp_checkUserCoord = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_gazeSurprized)
    {
      chartInstance->c8_tp_gazeSurprized = 1U;
    } else {
      chartInstance->c8_tp_gazeSurprized = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 ==
        c8_IN_headNeuralGazeCamera) {
      chartInstance->c8_tp_headNeuralGazeCamera = 1U;
    } else {
      chartInstance->c8_tp_headNeuralGazeCamera = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_idle) {
      chartInstance->c8_tp_idle = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_idle = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_leanFW) {
      chartInstance->c8_tp_leanFW = 1U;
    } else {
      chartInstance->c8_tp_leanFW = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_leanNeutral) {
      chartInstance->c8_tp_leanNeutral = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_leanNeutral = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_stateInit) {
      chartInstance->c8_tp_stateInit = 1U;
    } else {
      chartInstance->c8_tp_stateInit = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_stateWalkBack)
    {
      chartInstance->c8_tp_stateWalkBack = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateWalkBack = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_wait) {
      chartInstance->c8_tp_wait = 1U;
    } else {
      chartInstance->c8_tp_wait = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 == c8_IN_walkFW) {
      chartInstance->c8_tp_walkFW = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_walkFW = 0U;
    }

    chartInstance->c8_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c8_setSimStateSideEffectsInfo);
}

static void sf_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  c8_set_sim_state_side_effects_c8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

static void c8_enter_atomic_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS5 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
}

static void c8_enter_internal_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_j_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  *c8_gameState = c8_get_STATE_BEFORE(chartInstance, 0);
  c8_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_gameState, 0U);
  chartInstance->c8_TOO_CLOSE = 1.0;
  c8_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_TOO_CLOSE, 13U);
  chartInstance->c8_TOO_FAR = 2.0;
  c8_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_TOO_FAR, 12U);
  chartInstance->c8_NEUTRAL = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_NEUTRAL, 11U);
  chartInstance->c8_farBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_farBuffer, 14U);
  chartInstance->c8_closeBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_closeBuffer, 10U);
  chartInstance->c8_neutralBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_neutralBuffer, 9U);
  chartInstance->c8_position = 1.0;
  c8_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_c_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i0;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_d_out;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_isStable = true;
  switch (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5) {
   case c8_IN_browUp:
    CV_CHART_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_browUp = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_checkUserCoord;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_checkUserCoord = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_checkUserCoord:
    CV_CHART_EVAL(5, 0, 2);
    c8_checkUserCoord(chartInstance);
    break;

   case c8_IN_gazeSurprized:
    CV_CHART_EVAL(5, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_gazeSurprized = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_checkUserCoord;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_checkUserCoord = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_headNeuralGazeCamera:
    CV_CHART_EVAL(5, 0, 4);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_headNeuralGazeCamera = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_checkUserCoord;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_checkUserCoord = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_idle:
    CV_CHART_EVAL(5, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_t_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_out = CV_EML_IF(2, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                       (chartInstance->c8_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_idle = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_leanFW:
    CV_CHART_EVAL(5, 0, 6);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_leanFW = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_checkUserCoord;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_checkUserCoord = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_leanNeutral:
    CV_CHART_EVAL(5, 0, 7);
    c8_leanNeutral(chartInstance);
    break;

   case c8_IN_stateInit:
    CV_CHART_EVAL(5, 0, 8);
    c8_stateInit(chartInstance);
    break;

   case c8_IN_stateWalkBack:
    CV_CHART_EVAL(5, 0, 9);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_u_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(12, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateWalkBack = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_wait:
    CV_CHART_EVAL(5, 0, 10);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_w_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_c_out = CV_EML_IF(3, 0, 0, c8_get_avert(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 =
        c8_IN_headNeuralGazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_headNeuralGazeCamera = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_k_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 4.0, &c8_P,
        c8_BML1);
      c8_set_P(chartInstance, 0, c8_P);
      ssUpdateDataStoreLog(chartInstance->S, 1);
      for (c8_i0 = 0; c8_i0 < 256; c8_i0++) {
        c8_set_BML1(chartInstance, c8_i0, c8_BML1[c8_i0]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_checkUserCoord;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_checkUserCoord = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_walkFW:
    CV_CHART_EVAL(5, 0, 11);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_v_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_d_out = CV_EML_IF(11, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_walkFW = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
}

static void c8_exit_internal_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  switch (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5) {
   case c8_IN_browUp:
    CV_CHART_EVAL(5, 0, 1);
    chartInstance->c8_tp_browUp = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_checkUserCoord:
    CV_CHART_EVAL(5, 0, 2);
    chartInstance->c8_tp_checkUserCoord = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_gazeSurprized:
    CV_CHART_EVAL(5, 0, 3);
    chartInstance->c8_tp_gazeSurprized = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_headNeuralGazeCamera:
    CV_CHART_EVAL(5, 0, 4);
    chartInstance->c8_tp_headNeuralGazeCamera = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_idle:
    CV_CHART_EVAL(5, 0, 5);
    chartInstance->c8_tp_idle = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_leanFW:
    CV_CHART_EVAL(5, 0, 6);
    chartInstance->c8_tp_leanFW = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_leanNeutral:
    CV_CHART_EVAL(5, 0, 7);
    chartInstance->c8_tp_leanNeutral = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateInit:
    CV_CHART_EVAL(5, 0, 8);
    chartInstance->c8_tp_stateInit = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateWalkBack:
    CV_CHART_EVAL(5, 0, 9);
    chartInstance->c8_tp_stateWalkBack = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_wait:
    CV_CHART_EVAL(5, 0, 10);
    chartInstance->c8_tp_wait = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_walkFW:
    CV_CHART_EVAL(5, 0, 11);
    chartInstance->c8_tp_walkFW = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }
}

static void c8_initc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_doSetSimStateSideEffects = 0U;
  chartInstance->c8_setSimStateSideEffectsInfo = NULL;
  chartInstance->c8_tp_browUp = 0U;
  chartInstance->c8_tp_checkUserCoord = 0U;
  chartInstance->c8_tp_gazeSurprized = 0U;
  chartInstance->c8_tp_headNeuralGazeCamera = 0U;
  chartInstance->c8_tp_idle = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_leanFW = 0U;
  chartInstance->c8_tp_leanNeutral = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateInit = 0U;
  chartInstance->c8_tp_stateWalkBack = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_wait = 0U;
  chartInstance->c8_tp_walkFW = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS5 = 0U;
  chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_stateInit(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 1.0;
  boolean_T c8_b_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i1;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_s_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
  c8_out = CV_EML_IF(1, 0, 0, *c8_gameState == c8_get_STATE_OVER(chartInstance,
    0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_w_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(3, 0, 0, c8_get_avert(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 =
        c8_IN_headNeuralGazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_headNeuralGazeCamera = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_k_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 4.0, &c8_P,
        c8_BML1);
      c8_set_P(chartInstance, 0, c8_P);
      ssUpdateDataStoreLog(chartInstance->S, 1);
      for (c8_i1 = 0; c8_i1 < 256; c8_i1++) {
        c8_set_BML1(chartInstance, c8_i1, c8_BML1[c8_i1]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_checkUserCoord;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_checkUserCoord = 1U;
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void c8_enter_atomic_idle(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i2;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_l_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_fprintf(chartInstance, c8_get_fileID(chartInstance, 0));
  c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 1.0, &c8_P,
    c8_BML1);
  c8_set_P(chartInstance, 0, c8_P);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i2 = 0; c8_i2 < 256; c8_i2++) {
    c8_set_BML1(chartInstance, c8_i2, c8_BML1[c8_i2]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  chartInstance->c8_neutralBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_neutralBuffer, 9U);
  chartInstance->c8_position = 1.0;
  c8_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_enter_atomic_leanFW(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i3;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_m_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 6.0, &c8_P,
    c8_BML1);
  c8_set_P(chartInstance, 0, c8_P);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i3 = 0; c8_i3 < 256; c8_i3++) {
    c8_set_BML1(chartInstance, c8_i3, c8_BML1[c8_i3]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 14U);
  chartInstance->c8_farBuffer++;
  c8_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_farBuffer, 14U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_enter_atomic_browUp(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i4;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_n_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 8.0, &c8_P,
    c8_BML1);
  c8_set_P(chartInstance, 0, c8_P);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i4 = 0; c8_i4 < 256; c8_i4++) {
    c8_set_BML1(chartInstance, c8_i4, c8_BML1[c8_i4]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 1U, 9U);
  chartInstance->c8_neutralBuffer++;
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_neutralBuffer, 9U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_checkUserCoord(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_c_out;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 1.0;
  boolean_T c8_d_out;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_e_out;
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 1.0;
  boolean_T c8_f_out;
  real_T c8_g_nargin = 0.0;
  real_T c8_g_nargout = 1.0;
  boolean_T c8_g_out;
  real_T c8_h_nargin = 0.0;
  real_T c8_h_nargout = 1.0;
  boolean_T c8_h_out;
  real_T c8_i_nargin = 0.0;
  real_T c8_i_nargout = 1.0;
  boolean_T c8_i_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_j_nargin = 0.0;
  real_T c8_j_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i5;
  real_T *c8_distance;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  c8_distance = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_cb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
  guard6 = false;
  if (CV_EML_COND(4, 0, 0, *c8_distance == chartInstance->c8_TOO_FAR)) {
    if (CV_EML_COND(4, 0, 1, chartInstance->c8_position != 3.0)) {
      CV_EML_MCDC(4, 0, 0, true);
      CV_EML_IF(4, 0, 0, true);
      c8_out = true;
    } else {
      guard6 = true;
    }
  } else {
    c8_errorIfDataNotWrittenToFcn(chartInstance, 7U, 16U);
    guard6 = true;
  }

  if (guard6 == true) {
    CV_EML_MCDC(4, 0, 0, false);
    CV_EML_IF(4, 0, 0, false);
    c8_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_fb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 14U);
    c8_b_out = CV_EML_IF(5, 0, 0, chartInstance->c8_farBuffer >= 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_checkUserCoord = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_leanNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_leanNeutral = 1U;
      c8_enter_atomic_leanNeutral(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_db_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 14U);
      c8_c_out = CV_EML_IF(6, 0, 0, chartInstance->c8_farBuffer < 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_checkUserCoord = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_leanFW;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_leanFW = 1U;
        c8_enter_atomic_leanFW(chartInstance);
      } else {
        guard3 = true;
      }
    }
  } else {
    guard3 = true;
  }

  if (guard3 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_x_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 3U, 11U);
    guard5 = false;
    if (CV_EML_COND(9, 0, 0, *c8_distance == chartInstance->c8_NEUTRAL)) {
      if (CV_EML_COND(9, 0, 1, chartInstance->c8_position != 1.0)) {
        CV_EML_MCDC(9, 0, 0, true);
        CV_EML_IF(9, 0, 0, true);
        c8_d_out = true;
      } else {
        guard5 = true;
      }
    } else {
      c8_errorIfDataNotWrittenToFcn(chartInstance, 7U, 16U);
      guard5 = true;
    }

    if (guard5 == true) {
      CV_EML_MCDC(9, 0, 0, false);
      CV_EML_IF(9, 0, 0, false);
      c8_d_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c8_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_hb_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_errorIfDataNotWrittenToFcn(chartInstance, 1U, 9U);
      c8_e_out = CV_EML_IF(20, 0, 0, chartInstance->c8_neutralBuffer < 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_checkUserCoord = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_browUp;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_browUp = 1U;
        c8_enter_atomic_browUp(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_y_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_out, 2U, c8_c_sf_marshallOut,
          c8_c_sf_marshallIn);
        c8_errorIfDataNotWrittenToFcn(chartInstance, 1U, 9U);
        c8_f_out = CV_EML_IF(21, 0, 0, chartInstance->c8_neutralBuffer >= 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c8_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_checkUserCoord = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
          chartInstance->c8_temporalCounter_i1 = 0U;
          chartInstance->c8_tp_idle = 1U;
          c8_enter_atomic_idle(chartInstance);
        } else {
          guard2 = true;
        }
      }
    } else {
      guard2 = true;
    }
  }

  if (guard2 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_bb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
    guard4 = false;
    if (CV_EML_COND(7, 0, 0, *c8_distance == chartInstance->c8_TOO_CLOSE)) {
      if (CV_EML_COND(7, 0, 1, chartInstance->c8_position != 2.0)) {
        CV_EML_MCDC(7, 0, 0, true);
        CV_EML_IF(7, 0, 0, true);
        c8_g_out = true;
      } else {
        guard4 = true;
      }
    } else {
      c8_errorIfDataNotWrittenToFcn(chartInstance, 7U, 16U);
      guard4 = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c8_g_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c8_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_eb_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_errorIfDataNotWrittenToFcn(chartInstance, 2U, 10U);
      c8_h_out = CV_EML_IF(19, 0, 0, chartInstance->c8_closeBuffer >= 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_checkUserCoord = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_stateWalkBack;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_stateWalkBack = 1U;
        c8_enter_atomic_stateWalkBack(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_ab_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_out, 2U, c8_c_sf_marshallOut,
          c8_c_sf_marshallIn);
        c8_errorIfDataNotWrittenToFcn(chartInstance, 2U, 10U);
        c8_i_out = CV_EML_IF(18, 0, 0, chartInstance->c8_closeBuffer < 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c8_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_checkUserCoord = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_gazeSurprized;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_gazeSurprized = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_p_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 5.0,
            &c8_P, c8_BML1);
          c8_set_P(chartInstance, 0, c8_P);
          ssUpdateDataStoreLog(chartInstance->S, 1);
          for (c8_i5 = 0; c8_i5 < 256; c8_i5++) {
            c8_set_BML1(chartInstance, c8_i5, c8_BML1[c8_i5]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 0);
          c8_errorIfDataNotWrittenToFcn(chartInstance, 2U, 10U);
          chartInstance->c8_closeBuffer++;
          c8_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c8_closeBuffer, 10U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c8_sfEvent);
}

static void c8_enter_atomic_stateWalkBack
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i6;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_o_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_fprintf(chartInstance, c8_get_fileID(chartInstance, 0));
  c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 2.0, &c8_P,
    c8_BML1);
  c8_set_P(chartInstance, 0, c8_P);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i6 = 0; c8_i6 < 256; c8_i6++) {
    c8_set_BML1(chartInstance, c8_i6, c8_BML1[c8_i6]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  chartInstance->c8_closeBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_closeBuffer, 10U);
  chartInstance->c8_position = 2.0;
  c8_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_enter_atomic_leanNeutral
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i7;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_r_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 7.0, &c8_P,
    c8_BML1);
  c8_set_P(chartInstance, 0, c8_P);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i7 = 0; c8_i7 < 256; c8_i7++) {
    c8_set_BML1(chartInstance, c8_i7, c8_BML1[c8_i7]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_leanNeutral(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_BML1[256];
  real_T c8_P;
  int32_T c8_i8;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_gb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(16, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                     (chartInstance->c8_temporalCounter_i1 >= 2));
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_leanNeutral = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS5 = c8_IN_walkFW;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_walkFW = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_q_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_b_fprintf(chartInstance, c8_get_fileID(chartInstance, 0));
    c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 3.0, &c8_P,
      c8_BML1);
    c8_set_P(chartInstance, 0, c8_P);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    for (c8_i8 = 0; c8_i8 < 256; c8_i8++) {
      c8_set_BML1(chartInstance, c8_i8, c8_BML1[c8_i8]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 0);
    chartInstance->c8_farBuffer = 0.0;
    c8_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_farBuffer, 14U);
    chartInstance->c8_position = 3.0;
    c8_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
}

static void c8_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[137];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[137];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i9;
  static char_T c8_cv0[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=',
    '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't',
    'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '0', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i10;
  static real_T c8_dv0[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i11;
  int32_T c8_i12;
  int32_T c8_i13;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_b_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i9 = 0; c8_i9 < 137; c8_i9++) {
    c8_mystr[c8_i9] = c8_cv0[c8_i9];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i10 = 0; c8_i10 < 137; c8_i10++) {
    c8_arr[c8_i10] = c8_dv0[c8_i10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i11 = 0; c8_i11 < 256; c8_i11++) {
    c8_tt[c8_i11] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i12 = 0; c8_i12 < 137; c8_i12++) {
    c8_tt[c8_i12] = c8_arr[c8_i12];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i13 = 0; c8_i13 < 256; c8_i13++) {
    c8_myarr256[c8_i13] = c8_tt[c8_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_b_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[140];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[140];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i14;
  static char_T c8_cv1[140] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=', '\"',
    '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't', 'a',
    'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 'f', 'a', 'c', 'i', 'n',
    'g', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '-', '0', '.', '6', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i15;
  static real_T c8_dv1[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 32.0, 115.0, 98.0, 109.0, 58.0, 97.0, 99.0,
    99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0, 99.0, 99.0, 101.0,
    108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0,
    103.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 45.0, 48.0, 46.0,
    54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_c_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i14 = 0; c8_i14 < 140; c8_i14++) {
    c8_mystr[c8_i14] = c8_cv1[c8_i14];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i15 = 0; c8_i15 < 140; c8_i15++) {
    c8_arr[c8_i15] = c8_dv1[c8_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i16 = 0; c8_i16 < 256; c8_i16++) {
    c8_tt[c8_i16] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i17 = 0; c8_i17 < 140; c8_i17++) {
    c8_tt[c8_i17] = c8_arr[c8_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i18 = 0; c8_i18 < 256; c8_i18++) {
    c8_myarr256[c8_i18] = c8_tt[c8_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[139];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[139];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i19;
  static char_T c8_cv2[139] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=',
    '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't',
    'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '0', '.', '6', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i20;
  static real_T c8_dv2[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 46.0, 54.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c8_i21;
  int32_T c8_i22;
  int32_T c8_i23;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_d_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i19 = 0; c8_i19 < 139; c8_i19++) {
    c8_mystr[c8_i19] = c8_cv2[c8_i19];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i20 = 0; c8_i20 < 139; c8_i20++) {
    c8_arr[c8_i20] = c8_dv2[c8_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i21 = 0; c8_i21 < 256; c8_i21++) {
    c8_tt[c8_i21] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i22 = 0; c8_i22 < 139; c8_i22++) {
    c8_tt[c8_i22] = c8_arr[c8_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i23 = 0; c8_i23 < 256; c8_i23++) {
    c8_myarr256[c8_i23] = c8_tt[c8_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_d_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[115];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[115];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i24;
  static char_T c8_cv3[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i25;
  static real_T c8_dv3[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c8_i26;
  int32_T c8_i27;
  int32_T c8_i28;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_e_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i24 = 0; c8_i24 < 115; c8_i24++) {
    c8_mystr[c8_i24] = c8_cv3[c8_i24];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i25 = 0; c8_i25 < 115; c8_i25++) {
    c8_arr[c8_i25] = c8_dv3[c8_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 115.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i26 = 0; c8_i26 < 256; c8_i26++) {
    c8_tt[c8_i26] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i27 = 0; c8_i27 < 115; c8_i27++) {
    c8_tt[c8_i27] = c8_arr[c8_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i28 = 0; c8_i28 < 256; c8_i28++) {
    c8_myarr256[c8_i28] = c8_tt[c8_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_e_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[202];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[202];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i29;
  static char_T c8_cv4[202] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 't', 'a', 'r', 't',
    '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"', ' ', 's',
    'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"',
    '5', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '3', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', '/', '>', '<', 'f', 'a',
    'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"',
    '5', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ',
    'a', 'u', '=', '\"', '2', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '3',
    '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i30;
  static real_T c8_dv4[202] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0,
    61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0,
    32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0,
    32.0, 97.0, 117.0, 61.0, 34.0, 53.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0,
    120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0,
    61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0,
    34.0, 50.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0,
    34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0,
    53.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i31;
  int32_T c8_i32;
  int32_T c8_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_f_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i29 = 0; c8_i29 < 202; c8_i29++) {
    c8_mystr[c8_i29] = c8_cv4[c8_i29];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i30 = 0; c8_i30 < 202; c8_i30++) {
    c8_arr[c8_i30] = c8_dv4[c8_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 202.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i31 = 0; c8_i31 < 256; c8_i31++) {
    c8_tt[c8_i31] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i32 = 0; c8_i32 < 202; c8_i32++) {
    c8_tt[c8_i32] = c8_arr[c8_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i33 = 0; c8_i33 < 256; c8_i33++) {
    c8_myarr256[c8_i33] = c8_tt[c8_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_f_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[140];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[140];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i34;
  static char_T c8_cv5[140] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm',
    'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i35;
  static real_T c8_dv5[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 66.0, 65.0,
    67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0,
    97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i36;
  int32_T c8_i37;
  int32_T c8_i38;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_g_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i34 = 0; c8_i34 < 140; c8_i34++) {
    c8_mystr[c8_i34] = c8_cv5[c8_i34];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i35 = 0; c8_i35 < 140; c8_i35++) {
    c8_arr[c8_i35] = c8_dv5[c8_i35];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i36 = 0; c8_i36 < 256; c8_i36++) {
    c8_tt[c8_i36] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i37 = 0; c8_i37 < 140; c8_i37++) {
    c8_tt[c8_i37] = c8_arr[c8_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i38 = 0; c8_i38 < 256; c8_i38++) {
    c8_myarr256[c8_i38] = c8_tt[c8_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_g_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[85];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[85];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i39;
  static char_T c8_cv6[85] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i40;
  static real_T c8_dv6[85] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i41;
  int32_T c8_i42;
  int32_T c8_i43;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_h_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i39 = 0; c8_i39 < 85; c8_i39++) {
    c8_mystr[c8_i39] = c8_cv6[c8_i39];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i40 = 0; c8_i40 < 85; c8_i40++) {
    c8_arr[c8_i40] = c8_dv6[c8_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 85.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i41 = 0; c8_i41 < 256; c8_i41++) {
    c8_tt[c8_i41] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i42 = 0; c8_i42 < 85; c8_i42++) {
    c8_tt[c8_i42] = c8_arr[c8_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i43 = 0; c8_i43 < 256; c8_i43++) {
    c8_myarr256[c8_i43] = c8_tt[c8_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_fprintf(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
  real_T c8_fileID)
{
  boolean_T c8_cond;
  int32_T c8_i44;
  static char_T c8_cv7[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 't',
    'i', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't', 'e', 'd', '_', 'm', 'x' };

  char_T c8_u[24];
  const mxArray *c8_y = NULL;
  boolean_T c8_b_cond;
  int32_T c8_i45;
  static char_T c8_cv8[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'F', 'i', 'l',
    'e', 'I', 'O', ':', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'F', 'i', 'd' };

  char_T c8_b_u[24];
  const mxArray *c8_b_y = NULL;
  int32_T c8_i46;
  static char_T c8_cv9[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c8_c_u[7];
  const mxArray *c8_c_y = NULL;
  real_T c8_d_u;
  const mxArray *c8_d_y = NULL;
  int32_T c8_i47;
  static char_T c8_formatSpec[6] = { '%', 's', '\\', 'r', '\\', 'n' };

  char_T c8_e_u[6];
  const mxArray *c8_e_y = NULL;
  int32_T c8_i48;
  static char_T c8_arg[17] = { 'd', 'i', 's', 't', 'a', 'n', 'c', 'e', 'U', 's',
    'e', 'r', 'M', 'o', 'v', 'e', ':' };

  char_T c8_f_u[17];
  const mxArray *c8_f_y = NULL;
  const mxArray *c8_cfmt = NULL;
  const mxArray *c8_convs = NULL;
  c8_isequal(chartInstance);
  c8_cond = (c8_fileID != 0.0);
  if (c8_cond) {
  } else {
    for (c8_i44 = 0; c8_i44 < 24; c8_i44++) {
      c8_u[c8_i44] = c8_cv7[c8_i44];
    }

    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c8_y));
  }

  c8_b_cond = (c8_fileID > -1.0);
  if (c8_b_cond) {
  } else {
    for (c8_i45 = 0; c8_i45 < 24; c8_i45++) {
      c8_b_u[c8_i45] = c8_cv8[c8_i45];
    }

    c8_b_y = NULL;
    sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c8_b_y));
  }

  c8_eml_switch_helper(chartInstance);
  for (c8_i46 = 0; c8_i46 < 7; c8_i46++) {
    c8_c_u[c8_i46] = c8_cv9[c8_i46];
  }

  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c8_d_u = c8_fileID;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0), false);
  for (c8_i47 = 0; c8_i47 < 6; c8_i47++) {
    c8_e_u[c8_i47] = c8_formatSpec[c8_i47];
  }

  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", c8_e_u, 10, 0U, 1U, 0U, 2, 1, 6),
                false);
  for (c8_i48 = 0; c8_i48 < 17; c8_i48++) {
    c8_f_u[c8_i48] = c8_arg[c8_i48];
  }

  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", c8_f_u, 10, 0U, 1U, 0U, 2, 1, 17),
                false);
  c8_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14, c8_c_y,
                       14, c8_d_y, 14, c8_e_y, 14, c8_f_y), "feval");
  sf_mex_destroy(&c8_cfmt);
  sf_mex_destroy(&c8_convs);
}

static void c8_isequal(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_eml_switch_helper(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c8_b_fprintf(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c8_fileID)
{
  boolean_T c8_cond;
  int32_T c8_i49;
  static char_T c8_cv10[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 't',
    'i', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't', 'e', 'd', '_', 'm', 'x' };

  char_T c8_u[24];
  const mxArray *c8_y = NULL;
  boolean_T c8_b_cond;
  int32_T c8_i50;
  static char_T c8_cv11[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'F', 'i', 'l',
    'e', 'I', 'O', ':', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'F', 'i', 'd' };

  char_T c8_b_u[24];
  const mxArray *c8_b_y = NULL;
  int32_T c8_i51;
  static char_T c8_cv12[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c8_c_u[7];
  const mxArray *c8_c_y = NULL;
  real_T c8_d_u;
  const mxArray *c8_d_y = NULL;
  int32_T c8_i52;
  static char_T c8_formatSpec[6] = { '%', 's', '\\', 'r', '\\', 'n' };

  char_T c8_e_u[6];
  const mxArray *c8_e_y = NULL;
  int32_T c8_i53;
  static char_T c8_arg[16] = { 'd', 'i', 's', 't', 'a', 'n', 'c', 'e', 'U', 's',
    'e', 'r', 'M', 'o', 'v', 'e' };

  char_T c8_f_u[16];
  const mxArray *c8_f_y = NULL;
  const mxArray *c8_cfmt = NULL;
  const mxArray *c8_convs = NULL;
  c8_isequal(chartInstance);
  c8_cond = (c8_fileID != 0.0);
  if (c8_cond) {
  } else {
    for (c8_i49 = 0; c8_i49 < 24; c8_i49++) {
      c8_u[c8_i49] = c8_cv10[c8_i49];
    }

    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c8_y));
  }

  c8_b_cond = (c8_fileID > -1.0);
  if (c8_b_cond) {
  } else {
    for (c8_i50 = 0; c8_i50 < 24; c8_i50++) {
      c8_b_u[c8_i50] = c8_cv11[c8_i50];
    }

    c8_b_y = NULL;
    sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c8_b_y));
  }

  c8_eml_switch_helper(chartInstance);
  for (c8_i51 = 0; c8_i51 < 7; c8_i51++) {
    c8_c_u[c8_i51] = c8_cv12[c8_i51];
  }

  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c8_d_u = c8_fileID;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0), false);
  for (c8_i52 = 0; c8_i52 < 6; c8_i52++) {
    c8_e_u[c8_i52] = c8_formatSpec[c8_i52];
  }

  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", c8_e_u, 10, 0U, 1U, 0U, 2, 1, 6),
                false);
  for (c8_i53 = 0; c8_i53 < 16; c8_i53++) {
    c8_f_u[c8_i53] = c8_arg[c8_i53];
  }

  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", c8_f_u, 10, 0U, 1U, 0U, 2, 1, 16),
                false);
  c8_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14, c8_c_y,
                       14, c8_d_y, 14, c8_e_y, 14, c8_f_y), "feval");
  sf_mex_destroy(&c8_cfmt);
  sf_mex_destroy(&c8_convs);
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, c8_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\12-9-2015-Matlab-prior-M+M\\encStr2Arr.m"));
}

static real_T c8_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_feval, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_feval), &c8_thisId);
  sf_mex_destroy(&c8_feval);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i54;
  real_T c8_b_inData[256];
  int32_T c8_i55;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i54 = 0; c8_i54 < 256; c8_i54++) {
    c8_b_inData[c8_i54] = (*(real_T (*)[256])c8_inData)[c8_i54];
  }

  for (c8_i55 = 0; c8_i55 < 256; c8_i55++) {
    c8_u[c8_i55] = c8_b_inData[c8_i55];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_c_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256])
{
  real_T c8_dv7[256];
  int32_T c8_i56;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv7, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c8_i56 = 0; c8_i56 < 256; c8_i56++) {
    c8_y[c8_i56] = c8_dv7[c8_i56];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_poseBML;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[256];
  int32_T c8_i57;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_poseBML = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_poseBML), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_poseBML);
  for (c8_i57 = 0; c8_i57 < 256; c8_i57++) {
    (*(real_T (*)[256])c8_outData)[c8_i57] = c8_y[c8_i57];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_feval;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_feval = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_feval), &c8_thisId);
  sf_mex_destroy(&c8_feval);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  boolean_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(boolean_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static boolean_T c8_d_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  boolean_T c8_y;
  boolean_T c8_b0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b0, 1, 11, 0U, 0, 0U, 0);
  c8_y = c8_b0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_aVarTruthTableCondition_8;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  boolean_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_aVarTruthTableCondition_8 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_aVarTruthTableCondition_8), &c8_thisId);
  sf_mex_destroy(&c8_aVarTruthTableCondition_8);
  *(boolean_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i58;
  real_T c8_b_inData[256];
  int32_T c8_i59;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i58 = 0; c8_i58 < 256; c8_i58++) {
    c8_b_inData[c8_i58] = (*(real_T (*)[256])c8_inData)[c8_i58];
  }

  for (c8_i59 = 0; c8_i59 < 256; c8_i59++) {
    c8_u[c8_i59] = c8_b_inData[c8_i59];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_e_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256])
{
  real_T c8_dv8[256];
  int32_T c8_i60;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv8, 1, 0, 0U, 1, 0U, 1, 256);
  for (c8_i60 = 0; c8_i60 < 256; c8_i60++) {
    c8_y[c8_i60] = c8_dv8[c8_i60];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_myarr256;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[256];
  int32_T c8_i61;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_myarr256 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_myarr256), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_myarr256);
  for (c8_i61 = 0; c8_i61 < 256; c8_i61++) {
    (*(real_T (*)[256])c8_outData)[c8_i61] = c8_y[c8_i61];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i62;
  char_T c8_b_inData[137];
  int32_T c8_i63;
  char_T c8_u[137];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i62 = 0; c8_i62 < 137; c8_i62++) {
    c8_b_inData[c8_i62] = (*(char_T (*)[137])c8_inData)[c8_i62];
  }

  for (c8_i63 = 0; c8_i63 < 137; c8_i63++) {
    c8_u[c8_i63] = c8_b_inData[c8_i63];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i64;
  real_T c8_b_inData[137];
  int32_T c8_i65;
  real_T c8_u[137];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i64 = 0; c8_i64 < 137; c8_i64++) {
    c8_b_inData[c8_i64] = (*(real_T (*)[137])c8_inData)[c8_i64];
  }

  for (c8_i65 = 0; c8_i65 < 137; c8_i65++) {
    c8_u[c8_i65] = c8_b_inData[c8_i65];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i66;
  char_T c8_b_inData[140];
  int32_T c8_i67;
  char_T c8_u[140];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i66 = 0; c8_i66 < 140; c8_i66++) {
    c8_b_inData[c8_i66] = (*(char_T (*)[140])c8_inData)[c8_i66];
  }

  for (c8_i67 = 0; c8_i67 < 140; c8_i67++) {
    c8_u[c8_i67] = c8_b_inData[c8_i67];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i68;
  real_T c8_b_inData[140];
  int32_T c8_i69;
  real_T c8_u[140];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i68 = 0; c8_i68 < 140; c8_i68++) {
    c8_b_inData[c8_i68] = (*(real_T (*)[140])c8_inData)[c8_i68];
  }

  for (c8_i69 = 0; c8_i69 < 140; c8_i69++) {
    c8_u[c8_i69] = c8_b_inData[c8_i69];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_i_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i70;
  char_T c8_b_inData[139];
  int32_T c8_i71;
  char_T c8_u[139];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i70 = 0; c8_i70 < 139; c8_i70++) {
    c8_b_inData[c8_i70] = (*(char_T (*)[139])c8_inData)[c8_i70];
  }

  for (c8_i71 = 0; c8_i71 < 139; c8_i71++) {
    c8_u[c8_i71] = c8_b_inData[c8_i71];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_j_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i72;
  real_T c8_b_inData[139];
  int32_T c8_i73;
  real_T c8_u[139];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i72 = 0; c8_i72 < 139; c8_i72++) {
    c8_b_inData[c8_i72] = (*(real_T (*)[139])c8_inData)[c8_i72];
  }

  for (c8_i73 = 0; c8_i73 < 139; c8_i73++) {
    c8_u[c8_i73] = c8_b_inData[c8_i73];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_k_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i74;
  char_T c8_b_inData[115];
  int32_T c8_i75;
  char_T c8_u[115];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i74 = 0; c8_i74 < 115; c8_i74++) {
    c8_b_inData[c8_i74] = (*(char_T (*)[115])c8_inData)[c8_i74];
  }

  for (c8_i75 = 0; c8_i75 < 115; c8_i75++) {
    c8_u[c8_i75] = c8_b_inData[c8_i75];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_l_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i76;
  real_T c8_b_inData[115];
  int32_T c8_i77;
  real_T c8_u[115];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i76 = 0; c8_i76 < 115; c8_i76++) {
    c8_b_inData[c8_i76] = (*(real_T (*)[115])c8_inData)[c8_i76];
  }

  for (c8_i77 = 0; c8_i77 < 115; c8_i77++) {
    c8_u[c8_i77] = c8_b_inData[c8_i77];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_m_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i78;
  char_T c8_b_inData[202];
  int32_T c8_i79;
  char_T c8_u[202];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i78 = 0; c8_i78 < 202; c8_i78++) {
    c8_b_inData[c8_i78] = (*(char_T (*)[202])c8_inData)[c8_i78];
  }

  for (c8_i79 = 0; c8_i79 < 202; c8_i79++) {
    c8_u[c8_i79] = c8_b_inData[c8_i79];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 202),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_n_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i80;
  real_T c8_b_inData[202];
  int32_T c8_i81;
  real_T c8_u[202];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i80 = 0; c8_i80 < 202; c8_i80++) {
    c8_b_inData[c8_i80] = (*(real_T (*)[202])c8_inData)[c8_i80];
  }

  for (c8_i81 = 0; c8_i81 < 202; c8_i81++) {
    c8_u[c8_i81] = c8_b_inData[c8_i81];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 202), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_o_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i82;
  char_T c8_b_inData[85];
  int32_T c8_i83;
  char_T c8_u[85];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i82 = 0; c8_i82 < 85; c8_i82++) {
    c8_b_inData[c8_i82] = (*(char_T (*)[85])c8_inData)[c8_i82];
  }

  for (c8_i83 = 0; c8_i83 < 85; c8_i83++) {
    c8_u[c8_i83] = c8_b_inData[c8_i83];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 85), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_p_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i84;
  real_T c8_b_inData[85];
  int32_T c8_i85;
  real_T c8_u[85];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i84 = 0; c8_i84 < 85; c8_i84++) {
    c8_b_inData[c8_i84] = (*(real_T (*)[85])c8_inData)[c8_i84];
  }

  for (c8_i85 = 0; c8_i85 < 85; c8_i85++) {
    c8_u[c8_i85] = c8_b_inData[c8_i85];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 85), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_q_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i86;
  char_T c8_b_inData[131];
  int32_T c8_i87;
  char_T c8_u[131];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i86 = 0; c8_i86 < 131; c8_i86++) {
    c8_b_inData[c8_i86] = (*(char_T (*)[131])c8_inData)[c8_i86];
  }

  for (c8_i87 = 0; c8_i87 < 131; c8_i87++) {
    c8_u[c8_i87] = c8_b_inData[c8_i87];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_r_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i88;
  real_T c8_b_inData[131];
  int32_T c8_i89;
  real_T c8_u[131];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i88 = 0; c8_i88 < 131; c8_i88++) {
    c8_b_inData[c8_i88] = (*(real_T (*)[131])c8_inData)[c8_i88];
  }

  for (c8_i89 = 0; c8_i89 < 131; c8_i89++) {
    c8_u[c8_i89] = c8_b_inData[c8_i89];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

const mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS5_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 45, 1),
                false);
  c8_info_helper(&c8_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs0 = NULL;
  const mxArray *c8_lhs0 = NULL;
  const mxArray *c8_rhs1 = NULL;
  const mxArray *c8_lhs1 = NULL;
  const mxArray *c8_rhs2 = NULL;
  const mxArray *c8_lhs2 = NULL;
  const mxArray *c8_rhs3 = NULL;
  const mxArray *c8_lhs3 = NULL;
  const mxArray *c8_rhs4 = NULL;
  const mxArray *c8_lhs4 = NULL;
  const mxArray *c8_rhs5 = NULL;
  const mxArray *c8_lhs5 = NULL;
  const mxArray *c8_rhs6 = NULL;
  const mxArray *c8_lhs6 = NULL;
  const mxArray *c8_rhs7 = NULL;
  const mxArray *c8_lhs7 = NULL;
  const mxArray *c8_rhs8 = NULL;
  const mxArray *c8_lhs8 = NULL;
  const mxArray *c8_rhs9 = NULL;
  const mxArray *c8_lhs9 = NULL;
  const mxArray *c8_rhs10 = NULL;
  const mxArray *c8_lhs10 = NULL;
  const mxArray *c8_rhs11 = NULL;
  const mxArray *c8_lhs11 = NULL;
  const mxArray *c8_rhs12 = NULL;
  const mxArray *c8_lhs12 = NULL;
  const mxArray *c8_rhs13 = NULL;
  const mxArray *c8_lhs13 = NULL;
  const mxArray *c8_rhs14 = NULL;
  const mxArray *c8_lhs14 = NULL;
  const mxArray *c8_rhs15 = NULL;
  const mxArray *c8_lhs15 = NULL;
  const mxArray *c8_rhs16 = NULL;
  const mxArray *c8_lhs16 = NULL;
  const mxArray *c8_rhs17 = NULL;
  const mxArray *c8_lhs17 = NULL;
  const mxArray *c8_rhs18 = NULL;
  const mxArray *c8_lhs18 = NULL;
  const mxArray *c8_rhs19 = NULL;
  const mxArray *c8_lhs19 = NULL;
  const mxArray *c8_rhs20 = NULL;
  const mxArray *c8_lhs20 = NULL;
  const mxArray *c8_rhs21 = NULL;
  const mxArray *c8_lhs21 = NULL;
  const mxArray *c8_rhs22 = NULL;
  const mxArray *c8_lhs22 = NULL;
  const mxArray *c8_rhs23 = NULL;
  const mxArray *c8_lhs23 = NULL;
  const mxArray *c8_rhs24 = NULL;
  const mxArray *c8_lhs24 = NULL;
  const mxArray *c8_rhs25 = NULL;
  const mxArray *c8_lhs25 = NULL;
  const mxArray *c8_rhs26 = NULL;
  const mxArray *c8_lhs26 = NULL;
  const mxArray *c8_rhs27 = NULL;
  const mxArray *c8_lhs27 = NULL;
  const mxArray *c8_rhs28 = NULL;
  const mxArray *c8_lhs28 = NULL;
  const mxArray *c8_rhs29 = NULL;
  const mxArray *c8_lhs29 = NULL;
  const mxArray *c8_rhs30 = NULL;
  const mxArray *c8_lhs30 = NULL;
  const mxArray *c8_rhs31 = NULL;
  const mxArray *c8_lhs31 = NULL;
  const mxArray *c8_rhs32 = NULL;
  const mxArray *c8_lhs32 = NULL;
  const mxArray *c8_rhs33 = NULL;
  const mxArray *c8_lhs33 = NULL;
  const mxArray *c8_rhs34 = NULL;
  const mxArray *c8_lhs34 = NULL;
  const mxArray *c8_rhs35 = NULL;
  const mxArray *c8_lhs35 = NULL;
  const mxArray *c8_rhs36 = NULL;
  const mxArray *c8_lhs36 = NULL;
  const mxArray *c8_rhs37 = NULL;
  const mxArray *c8_lhs37 = NULL;
  const mxArray *c8_rhs38 = NULL;
  const mxArray *c8_lhs38 = NULL;
  const mxArray *c8_rhs39 = NULL;
  const mxArray *c8_lhs39 = NULL;
  const mxArray *c8_rhs40 = NULL;
  const mxArray *c8_lhs40 = NULL;
  const mxArray *c8_rhs41 = NULL;
  const mxArray *c8_lhs41 = NULL;
  const mxArray *c8_rhs42 = NULL;
  const mxArray *c8_lhs42 = NULL;
  const mxArray *c8_rhs43 = NULL;
  const mxArray *c8_lhs43 = NULL;
  const mxArray *c8_rhs44 = NULL;
  const mxArray *c8_lhs44 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/12-9-2015-Matlab-prior-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c8_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("fprintf"), "name", "name", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c8_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isequal"), "name", "name", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c8_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c8_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnan"), "name", "name", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c8_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c8_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c8_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("upper"), "name", "name", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c8_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_string_transform"), "name",
                  "name", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c8_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c8_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_charmax"), "name", "name",
                  10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c8_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c8_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c8_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_charmax"), "name", "name",
                  13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c8_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("colon"), "name", "name", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c8_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("colon"), "name", "name", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c8_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c8_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c8_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("floor"), "name", "name", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c8_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c8_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c8_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmin"), "name", "name", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c8_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c8_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c8_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmin"), "name", "name", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c8_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c8_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c8_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c8_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c8_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.unsignedClass"),
                  "name", "name", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c8_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c8_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c8_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c8_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c8_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c8_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c8_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c8_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c8_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "name", "name", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c8_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("fidCheck"), "name", "name", 39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c8_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("upper"), "name", "name", 40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c8_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c8_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c8_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c8_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 44);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 44);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c8_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs44), "lhs", "lhs",
                  44);
  sf_mex_destroy(&c8_rhs0);
  sf_mex_destroy(&c8_lhs0);
  sf_mex_destroy(&c8_rhs1);
  sf_mex_destroy(&c8_lhs1);
  sf_mex_destroy(&c8_rhs2);
  sf_mex_destroy(&c8_lhs2);
  sf_mex_destroy(&c8_rhs3);
  sf_mex_destroy(&c8_lhs3);
  sf_mex_destroy(&c8_rhs4);
  sf_mex_destroy(&c8_lhs4);
  sf_mex_destroy(&c8_rhs5);
  sf_mex_destroy(&c8_lhs5);
  sf_mex_destroy(&c8_rhs6);
  sf_mex_destroy(&c8_lhs6);
  sf_mex_destroy(&c8_rhs7);
  sf_mex_destroy(&c8_lhs7);
  sf_mex_destroy(&c8_rhs8);
  sf_mex_destroy(&c8_lhs8);
  sf_mex_destroy(&c8_rhs9);
  sf_mex_destroy(&c8_lhs9);
  sf_mex_destroy(&c8_rhs10);
  sf_mex_destroy(&c8_lhs10);
  sf_mex_destroy(&c8_rhs11);
  sf_mex_destroy(&c8_lhs11);
  sf_mex_destroy(&c8_rhs12);
  sf_mex_destroy(&c8_lhs12);
  sf_mex_destroy(&c8_rhs13);
  sf_mex_destroy(&c8_lhs13);
  sf_mex_destroy(&c8_rhs14);
  sf_mex_destroy(&c8_lhs14);
  sf_mex_destroy(&c8_rhs15);
  sf_mex_destroy(&c8_lhs15);
  sf_mex_destroy(&c8_rhs16);
  sf_mex_destroy(&c8_lhs16);
  sf_mex_destroy(&c8_rhs17);
  sf_mex_destroy(&c8_lhs17);
  sf_mex_destroy(&c8_rhs18);
  sf_mex_destroy(&c8_lhs18);
  sf_mex_destroy(&c8_rhs19);
  sf_mex_destroy(&c8_lhs19);
  sf_mex_destroy(&c8_rhs20);
  sf_mex_destroy(&c8_lhs20);
  sf_mex_destroy(&c8_rhs21);
  sf_mex_destroy(&c8_lhs21);
  sf_mex_destroy(&c8_rhs22);
  sf_mex_destroy(&c8_lhs22);
  sf_mex_destroy(&c8_rhs23);
  sf_mex_destroy(&c8_lhs23);
  sf_mex_destroy(&c8_rhs24);
  sf_mex_destroy(&c8_lhs24);
  sf_mex_destroy(&c8_rhs25);
  sf_mex_destroy(&c8_lhs25);
  sf_mex_destroy(&c8_rhs26);
  sf_mex_destroy(&c8_lhs26);
  sf_mex_destroy(&c8_rhs27);
  sf_mex_destroy(&c8_lhs27);
  sf_mex_destroy(&c8_rhs28);
  sf_mex_destroy(&c8_lhs28);
  sf_mex_destroy(&c8_rhs29);
  sf_mex_destroy(&c8_lhs29);
  sf_mex_destroy(&c8_rhs30);
  sf_mex_destroy(&c8_lhs30);
  sf_mex_destroy(&c8_rhs31);
  sf_mex_destroy(&c8_lhs31);
  sf_mex_destroy(&c8_rhs32);
  sf_mex_destroy(&c8_lhs32);
  sf_mex_destroy(&c8_rhs33);
  sf_mex_destroy(&c8_lhs33);
  sf_mex_destroy(&c8_rhs34);
  sf_mex_destroy(&c8_lhs34);
  sf_mex_destroy(&c8_rhs35);
  sf_mex_destroy(&c8_lhs35);
  sf_mex_destroy(&c8_rhs36);
  sf_mex_destroy(&c8_lhs36);
  sf_mex_destroy(&c8_rhs37);
  sf_mex_destroy(&c8_lhs37);
  sf_mex_destroy(&c8_rhs38);
  sf_mex_destroy(&c8_lhs38);
  sf_mex_destroy(&c8_rhs39);
  sf_mex_destroy(&c8_lhs39);
  sf_mex_destroy(&c8_rhs40);
  sf_mex_destroy(&c8_lhs40);
  sf_mex_destroy(&c8_rhs41);
  sf_mex_destroy(&c8_lhs41);
  sf_mex_destroy(&c8_rhs42);
  sf_mex_destroy(&c8_lhs42);
  sf_mex_destroy(&c8_rhs43);
  sf_mex_destroy(&c8_lhs43);
  sf_mex_destroy(&c8_rhs44);
  sf_mex_destroy(&c8_lhs44);
}

static const mxArray *c8_emlrt_marshallOut(const char * c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c8_u)), false);
  return c8_y;
}

static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 7, 0U, 0U, 0U, 0), false);
  return c8_y;
}

static void c8_activate_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = c8_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_deactivate_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_increment_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  if (chartInstance->c8_temporalCounter_i1 < 3U) {
    chartInstance->c8_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c8_temporalCounter_i1 + 1);
  }
}

static void c8_reset_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c8_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_activate_secsc8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_increment_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_reset_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_deactivate_c8_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_deactivate_secsc8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

boolean_T sf_exported_auto_isStablec8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c8_isStable;
}

void sf_exported_auto_duringc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_c8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_enterc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_enter_atomic_c8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
  c8_enter_internal_c8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_exitc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_exit_internal_c8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_gatewayc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  chartInstance->c8_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_initc8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *
  c8_S)
{
  const mxArray *c8_out = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_out = NULL;
  sf_mex_assign(&c8_out, sf_internal_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
                (c8_S), false);
  return c8_out;
}

void sf_exported_auto_setSimstatec8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c8_S,
  const mxArray *c8_in)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5(c8_S, sf_mex_dup(c8_in));
  sf_mex_destroy(&c8_in);
}

void sf_exported_auto_check_state_inconsistency_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, real_T c8_bmlID,
   real_T *c8_p, real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[13];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  boolean_T c8_aVarTruthTableCondition_3;
  boolean_T c8_aVarTruthTableCondition_4;
  boolean_T c8_aVarTruthTableCondition_5;
  boolean_T c8_aVarTruthTableCondition_6;
  boolean_T c8_aVarTruthTableCondition_7;
  boolean_T c8_aVarTruthTableCondition_8;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 2.0;
  real_T c8_dv9[256];
  int32_T c8_i90;
  int32_T c8_i91;
  int32_T c8_i92;
  int32_T c8_i93;
  int32_T c8_i94;
  int32_T c8_i95;
  int32_T c8_i96;
  uint32_T c8_b_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[131];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[131];
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_myarr256[256];
  int32_T c8_i97;
  static char_T c8_cv13[131] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'u', '=', '\"', '2', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"', ' ',
    'r', 'e', 'a', 'd', 'y', '=', '\"', '1', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '4', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c8_i98;
  static real_T c8_dv10[131] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 117.0, 61.0, 34.0, 50.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 114.0, 101.0,
    97.0, 100.0, 121.0, 61.0, 34.0, 49.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0,
    120.0, 61.0, 34.0, 52.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0,
    66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0,
    34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0,
    51.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0,
    115.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i99;
  int32_T c8_i100;
  int32_T c8_i101;
  int32_T c8_i102;
  int32_T c8_i103;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_3, 2U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_4, 3U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_5, 4U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_6, 5U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_7, 6U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_8, 7U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 8U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 9U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 10U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_p, 11U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 12U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(11, 0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 5);
  c8_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 6);
  c8_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 7);
  c8_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 8);
  c8_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 9);
  c8_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 10);
  c8_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 15);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 19);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 23);
  c8_aVarTruthTableCondition_3 = (c8_bmlID == 3.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 27);
  c8_aVarTruthTableCondition_4 = (c8_bmlID == 4.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 31);
  c8_aVarTruthTableCondition_5 = (c8_bmlID == 5.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 35);
  c8_aVarTruthTableCondition_6 = (c8_bmlID == 6.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 39);
  c8_aVarTruthTableCondition_7 = (c8_bmlID == 7.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 43);
  c8_aVarTruthTableCondition_8 = (c8_bmlID == 8.0);
  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 45);
  if (CV_EML_IF(11, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 46);
    CV_EML_FCN(11, 1);
    _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 69);
    c8_encStr2Arr(chartInstance, c8_dv9);
    for (c8_i90 = 0; c8_i90 < 256; c8_i90++) {
      c8_poseBML[c8_i90] = c8_dv9[c8_i90];
    }

    c8_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 69);
    *c8_p = 1.0;
    c8_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -69);
  } else {
    _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 47);
    if (CV_EML_IF(11, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 48);
      CV_EML_FCN(11, 2);
      _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 75);
      c8_b_encStr2Arr(chartInstance, c8_dv9);
      for (c8_i91 = 0; c8_i91 < 256; c8_i91++) {
        c8_poseBML[c8_i91] = c8_dv9[c8_i91];
      }

      c8_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 75);
      *c8_p = 1.0;
      c8_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -75);
    } else {
      _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 49);
      if (CV_EML_IF(11, 1, 2, c8_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 50);
        CV_EML_FCN(11, 3);
        _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 81);
        c8_c_encStr2Arr(chartInstance, c8_dv9);
        for (c8_i92 = 0; c8_i92 < 256; c8_i92++) {
          c8_poseBML[c8_i92] = c8_dv9[c8_i92];
        }

        c8_updateDataWrittenToVector(chartInstance, 9U);
        _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 81);
        *c8_p = 1.0;
        c8_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -81);
      } else {
        _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 51);
        if (CV_EML_IF(11, 1, 3, c8_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 52);
          CV_EML_FCN(11, 4);
          _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 87);
          c8_d_encStr2Arr(chartInstance, c8_dv9);
          for (c8_i93 = 0; c8_i93 < 256; c8_i93++) {
            c8_poseBML[c8_i93] = c8_dv9[c8_i93];
          }

          c8_updateDataWrittenToVector(chartInstance, 9U);
          _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 87);
          *c8_p = 1.0;
          c8_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -87);
        } else {
          _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 53);
          if (CV_EML_IF(11, 1, 4, c8_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 54);
            CV_EML_FCN(11, 5);
            _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 93);
            c8_e_encStr2Arr(chartInstance, c8_dv9);
            for (c8_i94 = 0; c8_i94 < 256; c8_i94++) {
              c8_poseBML[c8_i94] = c8_dv9[c8_i94];
            }

            c8_updateDataWrittenToVector(chartInstance, 9U);
            _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 93);
            *c8_p = 1.0;
            c8_updateDataWrittenToVector(chartInstance, 8U);
            _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -93);
          } else {
            _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 55);
            if (CV_EML_IF(11, 1, 5, c8_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 56);
              CV_EML_FCN(11, 6);
              _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 99);
              c8_f_encStr2Arr(chartInstance, c8_dv9);
              for (c8_i95 = 0; c8_i95 < 256; c8_i95++) {
                c8_poseBML[c8_i95] = c8_dv9[c8_i95];
              }

              c8_updateDataWrittenToVector(chartInstance, 9U);
              _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 99);
              *c8_p = 1.0;
              c8_updateDataWrittenToVector(chartInstance, 8U);
              _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -99);
            } else {
              _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 57);
              if (CV_EML_IF(11, 1, 6, c8_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 58);
                CV_EML_FCN(11, 7);
                _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 105);
                c8_g_encStr2Arr(chartInstance, c8_dv9);
                for (c8_i96 = 0; c8_i96 < 256; c8_i96++) {
                  c8_poseBML[c8_i96] = c8_dv9[c8_i96];
                }

                c8_updateDataWrittenToVector(chartInstance, 9U);
                _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 105);
                *c8_p = 1.0;
                c8_updateDataWrittenToVector(chartInstance, 8U);
                _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -105);
              } else {
                _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 59);
                if (CV_EML_IF(11, 1, 7, c8_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 60);
                  CV_EML_FCN(11, 8);
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 111);
                  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_i_debug_family_names,
                    c8_b_debug_family_var_map);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U,
                    c8_b_sf_marshallOut, c8_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_r_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U,
                    c8_b_sf_marshallOut, c8_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U,
                    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_q_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U,
                    c8_b_sf_marshallOut, c8_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U,
                    c8_b_sf_marshallOut, c8_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U,
                    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
                  for (c8_i97 = 0; c8_i97 < 131; c8_i97++) {
                    c8_mystr[c8_i97] = c8_cv13[c8_i97];
                  }

                  CV_SCRIPT_FCN(0, 0);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
                  c8_maxarrsize = 256.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
                  for (c8_i98 = 0; c8_i98 < 131; c8_i98++) {
                    c8_arr[c8_i98] = c8_dv10[c8_i98];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
                  c8_ss = 131.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
                  c8_padsize = c8_maxarrsize - c8_ss;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
                  for (c8_i99 = 0; c8_i99 < 256; c8_i99++) {
                    c8_tt[c8_i99] = 0.0;
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
                  for (c8_i100 = 0; c8_i100 < 131; c8_i100++) {
                    c8_tt[c8_i100] = c8_arr[c8_i100];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
                  for (c8_i101 = 0; c8_i101 < 256; c8_i101++) {
                    c8_myarr256[c8_i101] = c8_tt[c8_i101];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
                  _SFD_SYMBOL_SCOPE_POP();
                  for (c8_i102 = 0; c8_i102 < 256; c8_i102++) {
                    c8_poseBML[c8_i102] = c8_myarr256[c8_i102];
                  }

                  c8_updateDataWrittenToVector(chartInstance, 9U);
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 111);
                  *c8_p = 1.0;
                  c8_updateDataWrittenToVector(chartInstance, 8U);
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 62);
                  CV_EML_FCN(11, 1);
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 69);
                  c8_encStr2Arr(chartInstance, c8_dv9);
                  for (c8_i103 = 0; c8_i103 < 256; c8_i103++) {
                    c8_poseBML[c8_i103] = c8_dv9[c8_i103];
                  }

                  c8_updateDataWrittenToVector(chartInstance, 9U);
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, 69);
                  *c8_p = 1.0;
                  c8_updateDataWrittenToVector(chartInstance, 8U);
                  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -69);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(11U, chartInstance->c8_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c8_ARP_02_RPSs_Bdr_GK_BIS5_walkInvadingTable(SimStruct
  *c8_S, real_T c8_bmlID, real_T *c8_p, real_T c8_poseBML[256])
{
  real_T c8_b_p;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, c8_bmlID,
    &c8_b_p, c8_poseBML);
  *c8_p = c8_b_p;
}

static const mxArray *c8_s_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int8_T c8_f_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int8_T c8_y;
  int8_T c8_i104;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i104, 1, 2, 0U, 0, 0U, 0);
  c8_y = c8_i104;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_secs;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int8_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_secs = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_secs), &c8_thisId);
  sf_mex_destroy(&c8_secs);
  *(int8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_t_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_g_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i105;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i105, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i105;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_u_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  uint8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static uint8_T c8_h_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, const mxArray *c8_b_tp_stateInit, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateInit),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateInit);
  return c8_y;
}

static uint8_T c8_i_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_tp_stateInit;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c8_b_tp_stateInit = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateInit),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateInit);
  *(uint8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_j_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_b_setSimStateSideEffectsInfo, const char_T *c8_identifier)
{
  const mxArray *c8_y = NULL;
  emlrtMsgIdentifier c8_thisId;
  c8_y = NULL;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  sf_mex_assign(&c8_y, c8_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_setSimStateSideEffectsInfo), &c8_thisId), false);
  sf_mex_destroy(&c8_b_setSimStateSideEffectsInfo);
  return c8_y;
}

static const mxArray *c8_k_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  (void)c8_parentId;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_duplicatearraysafe(&c8_u), false);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_updateDataWrittenToVector
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex)
{
  (void)chartInstance;
  c8_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c8_vectorIndex, 0, 9, 1, 0)] = true;
}

static void c8_errorIfDataNotWrittenToFcn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex, uint32_T c8_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c8_dataNumber, c8_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c8_vectorIndex, 0, 9, 1,
    0)]);
}

static real_T c8_get_BML1(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#379) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c8_BML1_address)[c8_b];
}

static void c8_set_BML1(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#379) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c8_BML1_address)[c8_b] = c8_c;
}

static real_T *c8_access_BML1(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c8_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#379) in the initialization routine of the chart.\n");
  }

  c8_c = *chartInstance->c8_BML1_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c8_c;
}

static real_T c8_get_P(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#380) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_P_address;
}

static void c8_set_P(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                     uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#380) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_P_address = c8_c;
}

static real_T *c8_access_P(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c8_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#380) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_P_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#378) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_BEFORE_address;
}

static void c8_set_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#378) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_BEFORE_address = c8_c;
}

static real_T *c8_access_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#378) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_BEFORE_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#376) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_OVER_address;
}

static void c8_set_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#376) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_OVER_address = c8_c;
}

static real_T *c8_access_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#376) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_OVER_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#375) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_READY_address;
}

static void c8_set_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#375) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_READY_address = c8_c;
}

static real_T *c8_access_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *
  chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#375) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_READY_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c8_c;
}

static real_T c8_get_avert(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c8_b);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#847) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_avert_address;
}

static void c8_set_avert(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c8_b);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#847) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_avert_address = c8_c;
}

static real_T *c8_access_avert(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#847) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_avert_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c8_c;
}

static real_T c8_get_fileID(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c8_b);
  if (chartInstance->c8_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#382) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_fileID_address;
}

static void c8_set_fileID(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c8_b);
  if (chartInstance->c8_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#382) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_fileID_address = c8_c;
}

static real_T *c8_access_fileID(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c8_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#382) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_fileID_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c8_c;
}

static real_T c8_get_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c8_b);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#381) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_pr_address;
}

static void c8_set_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                      uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c8_b);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#381) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_pr_address = c8_c;
}

static real_T *c8_access_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#381) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_pr_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c8_c;
}

static void init_dsm_address_info(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML1", (void **)
    &chartInstance->c8_BML1_address, &chartInstance->c8_BML1_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c8_P_address, &chartInstance->c8_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c8_STATE_BEFORE_address,
    &chartInstance->c8_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c8_STATE_OVER_address, &chartInstance->c8_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c8_STATE_READY_address, &chartInstance->c8_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c8_avert_address, &chartInstance->c8_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c8_fileID_address, &chartInstance->c8_fileID_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pr", (void **)
    &chartInstance->c8_pr_address, &chartInstance->c8_pr_index);
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

void sf_c8_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4030717332U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3590688177U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2341192276U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3586259956U);
}

mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS5_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JAsZyXAkRR2BPyCLcNFhzG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS5_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS5_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[27],T\"gameState\",},{M[3],M[53],T\"NEUTRAL\",},{M[3],M[55],T\"TOO_CLOSE\",},{M[3],M[54],T\"TOO_FAR\",},{M[3],M[52],T\"closeBuffer\",},{M[3],M[56],T\"farBuffer\",},{M[3],M[51],T\"neutralBuffer\",},{M[3],M[75],T\"position\",},{M[8],M[0],T\"is_active_c8_ARP_02_RPSs_Bdr_GK_BIS5\",},{M[9],M[0],T\"is_c8_ARP_02_RPSs_Bdr_GK_BIS5\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[11],M[33],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x4[23 24 26 84],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
           8,
           12,
           22,
           0,
           21,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(1,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(2,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(3,1,1,0,"distance");
          _SFD_SET_DATA_PROPS(4,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(5,11,0,0,"BML1");
          _SFD_SET_DATA_PROPS(6,11,0,0,"P");
          _SFD_SET_DATA_PROPS(7,11,0,0,"pr");
          _SFD_SET_DATA_PROPS(8,11,0,0,"fileID");
          _SFD_SET_DATA_PROPS(9,0,0,0,"neutralBuffer");
          _SFD_SET_DATA_PROPS(10,0,0,0,"closeBuffer");
          _SFD_SET_DATA_PROPS(11,0,0,0,"NEUTRAL");
          _SFD_SET_DATA_PROPS(12,0,0,0,"TOO_FAR");
          _SFD_SET_DATA_PROPS(13,0,0,0,"TOO_CLOSE");
          _SFD_SET_DATA_PROPS(14,0,0,0,"farBuffer");
          _SFD_SET_DATA_PROPS(15,1,1,0,"zChange");
          _SFD_SET_DATA_PROPS(16,0,0,0,"position");
          _SFD_SET_DATA_PROPS(17,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(18,9,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,2);
          _SFD_CH_SUBSTATE_COUNT(11);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,5);
          _SFD_CH_SUBSTATE_INDEX(6,6);
          _SFD_CH_SUBSTATE_INDEX(7,7);
          _SFD_CH_SUBSTATE_INDEX(8,8);
          _SFD_CH_SUBSTATE_INDEX(9,9);
          _SFD_CH_SUBSTATE_INDEX(10,10);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
        }

        _SFD_CV_INIT_CHART(11,1,0,0);

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
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(11,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(11,0,"walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS5",
                             0,-1,1351);
        _SFD_CV_INIT_EML_FCN(11,1,"aFcnTruthTableAction_1",1351,-1,1564);
        _SFD_CV_INIT_EML_FCN(11,2,"aFcnTruthTableAction_2",1564,-1,1777);
        _SFD_CV_INIT_EML_FCN(11,3,"aFcnTruthTableAction_3",1777,-1,1992);
        _SFD_CV_INIT_EML_FCN(11,4,"aFcnTruthTableAction_4",1992,-1,2186);
        _SFD_CV_INIT_EML_FCN(11,5,"aFcnTruthTableAction_5",2186,-1,2469);
        _SFD_CV_INIT_EML_FCN(11,6,"aFcnTruthTableAction_6",2469,-1,2683);
        _SFD_CV_INIT_EML_FCN(11,7,"aFcnTruthTableAction_7",2683,-1,2847);
        _SFD_CV_INIT_EML_FCN(11,8,"aFcnTruthTableAction_8",2847,-1,3051);
        _SFD_CV_INIT_EML_IF(11,1,0,785,815,846,1349);
        _SFD_CV_INIT_EML_IF(11,1,1,846,880,911,1349);
        _SFD_CV_INIT_EML_IF(11,1,2,911,945,976,1349);
        _SFD_CV_INIT_EML_IF(11,1,3,976,1010,1041,1349);
        _SFD_CV_INIT_EML_IF(11,1,4,1041,1075,1106,1349);
        _SFD_CV_INIT_EML_IF(11,1,5,1106,1140,1171,1349);
        _SFD_CV_INIT_EML_IF(11,1,6,1171,1205,1236,1349);
        _SFD_CV_INIT_EML_IF(11,1,7,1236,1270,1301,1349);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,22,1,22);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 21 };

          static int condEnd[] = { 20, 34 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,36,1,36);

        {
          static int condStart[] = { 1, 23 };

          static int condEnd[] = { 22, 36 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,36,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 21 };

          static int condEnd[] = { 20, 34 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,1,16,1,16);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));

        {
          real_T *c8_gameState;
          real_T *c8_distance;
          boolean_T *c8_zChange;
          c8_zChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_distance = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c8_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c8_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_distance);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c8_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c8_BML1_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c8_P_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c8_pr_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c8_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c8_neutralBuffer);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c8_closeBuffer);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c8_NEUTRAL);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c8_TOO_FAR);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c8_TOO_CLOSE);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c8_farBuffer);
          _SFD_SET_DATA_VALUE_PTR(15U, c8_zChange);
          _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c8_position);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c8_avert_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Fa4TBPgvLbXOw9cqATUblB";
}

static void sf_opaque_initialize_c8_ARP_02_RPSs_Bdr_GK_BIS5(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
  initialize_c8_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  enable_c8_ARP_02_RPSs_Bdr_GK_BIS5((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  disable_c8_ARP_02_RPSs_Bdr_GK_BIS5((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  sf_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS5();/* state var info */
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

extern void sf_internal_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS5();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c8_ARP_02_RPSs_Bdr_GK_BIS5(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSs_Bdr_GK_BIS5_optimization_info();
    }

    finalize_c8_ARP_02_RPSs_Bdr_GK_BIS5
      ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
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
    initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS5
      ((SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSs_Bdr_GK_BIS5_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2580263097U));
  ssSetChecksum1(S,(2185746551U));
  ssSetChecksum2(S,(1420485700U));
  ssSetChecksum3(S,(400898916U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)utMalloc(sizeof
    (SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_ARP_02_RPSs_Bdr_GK_BIS5;
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

void c8_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
