/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSs_Bdr_GK_BIS5_sfun.h"
#include "c20_ARP_02_RPSs_Bdr_GK_BIS5.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSs_Bdr_GK_BIS5_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c20_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c20_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c20_IN_gazeCamera              ((uint8_T)1U)
#define c20_IN_gazeCamera1             ((uint8_T)2U)
#define c20_IN_gazeCamera2             ((uint8_T)3U)
#define c20_IN_init                    ((uint8_T)4U)
#define c20_IN_wave                    ((uint8_T)5U)
#define c20_IN_waveBothHands           ((uint8_T)6U)
#define c20_IN_waveLeftHand            ((uint8_T)7U)
#define c20_IN_waveRightHand           ((uint8_T)8U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c20_debug_family_names[11] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "nargin", "nargout", "bmlID", "pr", "poseBML" };

static const char * c20_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c20_dataWrittenToVector[6];

/* Function Declarations */
static void initialize_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void initialize_params_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void enable_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void disable_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_st);
static void c20_set_sim_state_side_effects_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void finalize_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void sf_gateway_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_enter_atomic_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_enter_internal_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_exit_internal_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_initc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void initSimStructsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_enter_atomic_waveLeftHand
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_wave(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_enter_atomic_waveBothHands
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_enter_atomic_gazeCamera2
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_enter_atomic_gazeCamera
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_gazeCamera(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c20_enter_atomic_gazeCamera1
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_gazeCamera1(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c20_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256]);
static void c20_b_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256]);
static void c20_c_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256]);
static void c20_d_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256]);
static void c20_fprintf(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_fileID);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static real_T c20_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_feval, const char_T *c20_identifier);
static real_T c20_b_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_c_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static boolean_T c20_d_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_e_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256]);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_h_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_i_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_j_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_k_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_l_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_m_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_n_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_info_helper(const mxArray **c20_info);
static const mxArray *c20_emlrt_marshallOut(const char * c20_u);
static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u);
static void c20_activate_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_deactivate_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_increment_counters_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_reset_counters_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, real_T c20_bmlID,
   real_T *c20_pr, real_T c20_poseBML[256]);
static const mxArray *c20_o_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int8_T c20_f_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_p_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_g_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_q_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static uint8_T c20_h_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_b_tp_waveRightHand, const char_T *c20_identifier);
static uint8_T c20_i_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_j_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier);
static const mxArray *c20_k_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_updateDataWrittenToVector
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c20_vectorIndex);
static void c20_errorIfDataNotWrittenToFcn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c20_vectorIndex, uint32_T c20_dataNumber);
static real_T c20_get_BML(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_BML(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_BML(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static real_T c20_get_BML2(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_BML2(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_BML2(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static real_T c20_get_P(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_P(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                      uint32_T c20_b, real_T c20_c);
static real_T *c20_access_P(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static real_T c20_get_STATE_BEFORE(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_STATE_BEFORE(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_STATE_BEFORE
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T c20_b);
static real_T c20_get_STATE_OVER(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_STATE_OVER(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_STATE_OVER(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static real_T c20_get_avert(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_avert(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_avert(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static real_T c20_get_fileID(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_fileID(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_fileID(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b);
static void init_dsm_address_info(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c20_update_debugger_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_prevAniVal;
  c20_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c20_is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_waveRightHand)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_waveLeftHand)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_wave) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_waveBothHands)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_gazeCamera2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_gazeCamera1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  }

  _SFD_SET_ANIMATION(c20_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  real_T c20_hoistedGlobal;
  real_T c20_u;
  const mxArray *c20_b_y = NULL;
  real_T c20_b_hoistedGlobal;
  real_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T c20_c_hoistedGlobal;
  real_T c20_c_u;
  const mxArray *c20_d_y = NULL;
  real_T c20_d_hoistedGlobal;
  real_T c20_d_u;
  const mxArray *c20_e_y = NULL;
  uint8_T c20_e_hoistedGlobal;
  uint8_T c20_e_u;
  const mxArray *c20_f_y = NULL;
  uint8_T c20_f_hoistedGlobal;
  uint8_T c20_f_u;
  const mxArray *c20_g_y = NULL;
  uint8_T c20_g_hoistedGlobal;
  uint8_T c20_g_u;
  const mxArray *c20_h_y = NULL;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(7, 1), false);
  c20_hoistedGlobal = *c20_gameState;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = chartInstance->c20_bFlag;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  c20_c_hoistedGlobal = chartInstance->c20_lFlag;
  c20_c_u = c20_c_hoistedGlobal;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  c20_d_hoistedGlobal = chartInstance->c20_rFlag;
  c20_d_u = c20_d_hoistedGlobal;
  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  c20_e_hoistedGlobal = chartInstance->c20_is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  c20_e_u = c20_e_hoistedGlobal;
  c20_f_y = NULL;
  sf_mex_assign(&c20_f_y, sf_mex_create("y", &c20_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 4, c20_f_y);
  c20_f_hoistedGlobal = chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  c20_f_u = c20_f_hoistedGlobal;
  c20_g_y = NULL;
  sf_mex_assign(&c20_g_y, sf_mex_create("y", &c20_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 5, c20_g_y);
  c20_g_hoistedGlobal = chartInstance->c20_temporalCounter_i1;
  c20_g_u = c20_g_hoistedGlobal;
  c20_h_y = NULL;
  sf_mex_assign(&c20_h_y, sf_mex_create("y", &c20_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 6, c20_h_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_st)
{
  const mxArray *c20_u;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_u = sf_mex_dup(c20_st);
  *c20_gameState = c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 0)), "gameState");
  chartInstance->c20_bFlag = c20_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 1)), "bFlag");
  chartInstance->c20_lFlag = c20_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 2)), "lFlag");
  chartInstance->c20_rFlag = c20_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 3)), "rFlag");
  chartInstance->c20_is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5 =
    c20_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 4)),
    "is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5");
  chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 5)),
     "is_c20_ARP_02_RPSs_Bdr_GK_BIS5");
  chartInstance->c20_temporalCounter_i1 = c20_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c20_setSimStateSideEffectsInfo,
                c20_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c20_u);
  chartInstance->c20_doSetSimStateSideEffects = 1U;
  c20_update_debugger_state_c20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void c20_set_sim_state_side_effects_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  if (chartInstance->c20_doSetSimStateSideEffects != 0) {
    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_gazeCamera)
    {
      chartInstance->c20_tp_gazeCamera = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_gazeCamera = 0U;
    }

    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_gazeCamera1)
    {
      chartInstance->c20_tp_gazeCamera1 = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_gazeCamera1 = 0U;
    }

    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_gazeCamera2)
    {
      chartInstance->c20_tp_gazeCamera2 = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_gazeCamera2 = 0U;
    }

    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_init) {
      chartInstance->c20_tp_init = 1U;
    } else {
      chartInstance->c20_tp_init = 0U;
    }

    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_wave) {
      chartInstance->c20_tp_wave = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_wave = 0U;
    }

    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 ==
        c20_IN_waveBothHands) {
      chartInstance->c20_tp_waveBothHands = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_waveBothHands = 0U;
    }

    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 == c20_IN_waveLeftHand)
    {
      chartInstance->c20_tp_waveLeftHand = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_waveLeftHand = 0U;
    }

    if (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 ==
        c20_IN_waveRightHand) {
      chartInstance->c20_tp_waveRightHand = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_waveRightHand = 0U;
    }

    chartInstance->c20_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c20_setSimStateSideEffectsInfo);
}

static void sf_gateway_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  c20_set_sim_state_side_effects_c20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

static void c20_enter_atomic_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 15U, chartInstance->c20_sfEvent);
  chartInstance->c20_is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c20_sfEvent);
}

static void c20_enter_internal_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c20_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  chartInstance->c20_isStable = false;
  chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  chartInstance->c20_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_h_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_set_STATE_OVER(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c20_set_STATE_BEFORE(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  *c20_gameState = c20_get_STATE_BEFORE(chartInstance, 0);
  c20_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c20_gameState, 2U);
  chartInstance->c20_rFlag = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
  chartInstance->c20_lFlag = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
  chartInstance->c20_bFlag = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i0;
  real_T c20_c_nargin = 0.0;
  real_T c20_c_nargout = 1.0;
  boolean_T c20_b_out;
  real_T c20_d_nargin = 0.0;
  real_T c20_d_nargout = 1.0;
  boolean_T c20_c_out;
  real_T c20_e_nargin = 0.0;
  real_T c20_e_nargout = 1.0;
  boolean_T c20_d_out;
  real_T c20_f_nargin = 0.0;
  real_T c20_f_nargout = 1.0;
  boolean_T c20_e_out;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c20_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_isStable = true;
  switch (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5) {
   case c20_IN_gazeCamera:
    CV_CHART_EVAL(15, 0, 1);
    c20_gazeCamera(chartInstance);
    break;

   case c20_IN_gazeCamera1:
    CV_CHART_EVAL(15, 0, 2);
    c20_gazeCamera1(chartInstance);
    break;

   case c20_IN_gazeCamera2:
    CV_CHART_EVAL(15, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_ab_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_out = CV_EML_IF(9, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs) &&
                        (chartInstance->c20_temporalCounter_i1 >= 4));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_gazeCamera2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_waveBothHands;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_waveBothHands = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_j_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      c20_fprintf(chartInstance, c20_get_fileID(chartInstance, 0));
      c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 3.0,
        &c20_P, c20_BML2);
      c20_set_P(chartInstance, 0, c20_P);
      ssUpdateDataStoreLog(chartInstance->S, 2);
      for (c20_i0 = 0; c20_i0 < 256; c20_i0++) {
        c20_set_BML2(chartInstance, c20_i0, c20_BML2[c20_i0]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 1);
      chartInstance->c20_bFlag = 1.0;
      c20_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_init:
    CV_CHART_EVAL(15, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_t_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
    c20_b_out = CV_EML_IF(7, 0, 0, *c20_gameState == c20_get_STATE_OVER
                          (chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_wave:
    CV_CHART_EVAL(15, 0, 5);
    c20_wave(chartInstance);
    break;

   case c20_IN_waveBothHands:
    CV_CHART_EVAL(15, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_w_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_c_out = CV_EML_IF(6, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs)
                          && (chartInstance->c20_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_waveBothHands = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveLeftHand:
    CV_CHART_EVAL(15, 0, 7);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_s_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_d_out = CV_EML_IF(5, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs)
                          && (chartInstance->c20_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_waveLeftHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveRightHand:
    CV_CHART_EVAL(15, 0, 8);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_p_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_e_out = CV_EML_IF(4, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs)
                          && (chartInstance->c20_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_waveRightHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_CHART_EVAL(15, 0, 0);
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c20_sfEvent);
}

static void c20_exit_internal_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  switch (chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5) {
   case c20_IN_gazeCamera:
    CV_CHART_EVAL(15, 0, 1);
    chartInstance->c20_tp_gazeCamera = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_gazeCamera1:
    CV_CHART_EVAL(15, 0, 2);
    chartInstance->c20_tp_gazeCamera1 = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_gazeCamera2:
    CV_CHART_EVAL(15, 0, 3);
    chartInstance->c20_tp_gazeCamera2 = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_init:
    CV_CHART_EVAL(15, 0, 4);
    chartInstance->c20_tp_init = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_wave:
    CV_CHART_EVAL(15, 0, 5);
    chartInstance->c20_tp_wave = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveBothHands:
    CV_CHART_EVAL(15, 0, 6);
    chartInstance->c20_tp_waveBothHands = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveLeftHand:
    CV_CHART_EVAL(15, 0, 7);
    chartInstance->c20_tp_waveLeftHand = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveRightHand:
    CV_CHART_EVAL(15, 0, 8);
    chartInstance->c20_tp_waveRightHand = 0U;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_CHART_EVAL(15, 0, 0);
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_initc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_doSetSimStateSideEffects = 0U;
  chartInstance->c20_setSimStateSideEffectsInfo = NULL;
  chartInstance->c20_tp_gazeCamera = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_gazeCamera1 = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_gazeCamera2 = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_init = 0U;
  chartInstance->c20_tp_wave = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_waveBothHands = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_waveLeftHand = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_waveRightHand = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5 = 0U;
  chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c20_enter_atomic_waveLeftHand
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_i_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_fprintf(chartInstance, c20_get_fileID(chartInstance, 0));
  c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 2.0, &c20_P,
    c20_BML2);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i1 = 0; c20_i1 < 256; c20_i1++) {
    c20_set_BML2(chartInstance, c20_i1, c20_BML2[c20_i1]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  chartInstance->c20_lFlag = 1.0;
  c20_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_wave(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_c_nargin = 0.0;
  real_T c20_c_nargout = 1.0;
  boolean_T c20_b_out;
  real_T c20_d_nargin = 0.0;
  real_T c20_d_nargout = 1.0;
  boolean_T c20_c_out;
  real_T c20_e_nargin = 0.0;
  real_T c20_e_nargout = 0.0;
  real_T c20_f_nargin = 0.0;
  real_T c20_f_nargout = 1.0;
  boolean_T c20_d_out;
  real_T c20_g_nargin = 0.0;
  real_T c20_g_nargout = 1.0;
  boolean_T c20_e_out;
  real_T c20_h_nargin = 0.0;
  real_T c20_h_nargout = 0.0;
  real_T c20_i_nargin = 0.0;
  real_T c20_i_nargout = 1.0;
  boolean_T c20_f_out;
  real_T c20_j_nargin = 0.0;
  real_T c20_j_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i2;
  real_T c20_k_nargin = 0.0;
  real_T c20_k_nargout = 1.0;
  boolean_T c20_g_out;
  real_T c20_l_nargin = 0.0;
  real_T c20_l_nargout = 0.0;
  real_T *c20_handUp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c20_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_q_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  guard3 = false;
  if (CV_EML_COND(2, 0, 0, *c20_handUp == 2.0)) {
    if (CV_EML_COND(2, 0, 1, chartInstance->c20_lFlag == 0.0)) {
      CV_EML_MCDC(2, 0, 0, true);
      CV_EML_IF(2, 0, 0, true);
      c20_out = true;
    } else {
      guard3 = true;
    }
  } else {
    c20_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
    guard3 = true;
  }

  if (guard3 == true) {
    CV_EML_MCDC(2, 0, 0, false);
    CV_EML_IF(2, 0, 0, false);
    c20_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_r_debug_family_names,
      c20_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    chartInstance->c20_rFlag = 0.0;
    c20_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
    chartInstance->c20_bFlag = 0.0;
    c20_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_eb_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_b_out = CV_EML_IF(14, 0, 0, c20_get_avert(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_wave = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_gazeCamera1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_gazeCamera1 = 1U;
      c20_enter_atomic_gazeCamera1(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_wave = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_waveLeftHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_waveLeftHand = 1U;
      c20_enter_atomic_waveLeftHand(chartInstance);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_x_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(3, 0, 0, *c20_handUp == 3.0)) {
      if (CV_EML_COND(3, 0, 1, chartInstance->c20_bFlag == 0.0)) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c20_c_out = true;
      } else {
        guard2 = true;
      }
    } else {
      c20_errorIfDataNotWrittenToFcn(chartInstance, 3U, 9U);
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c20_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c20_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_y_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      chartInstance->c20_rFlag = 0.0;
      c20_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
      chartInstance->c20_lFlag = 0.0;
      c20_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                   chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_fb_debug_family_names,
        c20_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_out, 2U, c20_c_sf_marshallOut,
        c20_c_sf_marshallIn);
      c20_d_out = CV_EML_IF(15, 0, 0, c20_get_avert(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_wave = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
        chartInstance->c20_isStable = false;
        chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_gazeCamera2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
        chartInstance->c20_temporalCounter_i1 = 0U;
        chartInstance->c20_tp_gazeCamera2 = 1U;
        c20_enter_atomic_gazeCamera2(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_wave = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
        chartInstance->c20_isStable = false;
        chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_waveBothHands;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
        chartInstance->c20_temporalCounter_i1 = 0U;
        chartInstance->c20_tp_waveBothHands = 1U;
        c20_enter_atomic_waveBothHands(chartInstance);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_n_debug_family_names,
        c20_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_out, 2U, c20_c_sf_marshallOut,
        c20_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(1, 0, 0, *c20_handUp == 1.0)) {
        if (CV_EML_COND(1, 0, 1, chartInstance->c20_rFlag == 0.0)) {
          CV_EML_MCDC(1, 0, 0, true);
          CV_EML_IF(1, 0, 0, true);
          c20_e_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c20_errorIfDataNotWrittenToFcn(chartInstance, 1U, 7U);
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c20_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c20_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_o_debug_family_names,
          c20_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_h_nargin, 0U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_h_nargout, 1U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        chartInstance->c20_lFlag = 0.0;
        c20_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
        chartInstance->c20_bFlag = 0.0;
        c20_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_db_debug_family_names,
          c20_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i_nargin, 0U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i_nargout, 1U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_out, 2U,
          c20_c_sf_marshallOut, c20_c_sf_marshallIn);
        c20_f_out = CV_EML_IF(12, 0, 0, c20_get_avert(chartInstance, 0) == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_wave = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
          chartInstance->c20_isStable = false;
          chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_gazeCamera;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
          chartInstance->c20_temporalCounter_i1 = 0U;
          chartInstance->c20_tp_gazeCamera = 1U;
          c20_enter_atomic_gazeCamera(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_wave = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
          chartInstance->c20_isStable = false;
          chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 =
            c20_IN_waveRightHand;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
          chartInstance->c20_temporalCounter_i1 = 0U;
          chartInstance->c20_tp_waveRightHand = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_g_debug_family_names,
            c20_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_j_nargin, 0U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_j_nargout, 1U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          c20_fprintf(chartInstance, c20_get_fileID(chartInstance, 0));
          c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 1.0,
            &c20_P, c20_BML2);
          c20_set_P(chartInstance, 0, c20_P);
          ssUpdateDataStoreLog(chartInstance->S, 2);
          for (c20_i2 = 0; c20_i2 < 256; c20_i2++) {
            c20_set_BML2(chartInstance, c20_i2, c20_BML2[c20_i2]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 1);
          chartInstance->c20_rFlag = 1.0;
          c20_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_u_debug_family_names,
          c20_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_k_nargin, 0U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_k_nargout, 1U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_out, 2U,
          c20_c_sf_marshallOut, c20_c_sf_marshallIn);
        c20_g_out = CV_EML_IF(8, 0, 0, (chartInstance->c20_sfEvent ==
          c20_event_secs) && (chartInstance->c20_temporalCounter_i1 >= 2));
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_v_debug_family_names,
            c20_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_l_nargin, 0U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_l_nargout, 1U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          chartInstance->c20_rFlag = 0.0;
          c20_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
          chartInstance->c20_lFlag = 0.0;
          c20_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
          chartInstance->c20_bFlag = 0.0;
          c20_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c20_tp_wave = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
          chartInstance->c20_isStable = false;
          chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_wave;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
          chartInstance->c20_temporalCounter_i1 = 0U;
          chartInstance->c20_tp_wave = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       chartInstance->c20_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c20_sfEvent);
}

static void c20_enter_atomic_waveBothHands
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i3;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_j_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_fprintf(chartInstance, c20_get_fileID(chartInstance, 0));
  c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 3.0, &c20_P,
    c20_BML2);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i3 = 0; c20_i3 < 256; c20_i3++) {
    c20_set_BML2(chartInstance, c20_i3, c20_BML2[c20_i3]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  chartInstance->c20_bFlag = 1.0;
  c20_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_enter_atomic_gazeCamera2
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i4;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_k_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 6.0, &c20_P,
    c20_BML2);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i4 = 0; c20_i4 < 256; c20_i4++) {
    c20_set_BML2(chartInstance, c20_i4, c20_BML2[c20_i4]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  c20_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_enter_atomic_gazeCamera
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i5;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_l_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 6.0, &c20_P,
    c20_BML2);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i5 = 0; c20_i5 < 256; c20_i5++) {
    c20_set_BML2(chartInstance, c20_i5, c20_BML2[c20_i5]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  c20_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_gazeCamera(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i6;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_cb_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  c20_out = CV_EML_IF(11, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs) &&
                      (chartInstance->c20_temporalCounter_i1 >= 4));
  _SFD_SYMBOL_SCOPE_POP();
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_gazeCamera = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    chartInstance->c20_isStable = false;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_waveRightHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
    chartInstance->c20_temporalCounter_i1 = 0U;
    chartInstance->c20_tp_waveRightHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_g_debug_family_names,
      c20_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    c20_fprintf(chartInstance, c20_get_fileID(chartInstance, 0));
    c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 1.0, &c20_P,
      c20_BML2);
    c20_set_P(chartInstance, 0, c20_P);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    for (c20_i6 = 0; c20_i6 < 256; c20_i6++) {
      c20_set_BML2(chartInstance, c20_i6, c20_BML2[c20_i6]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 1);
    chartInstance->c20_rFlag = 1.0;
    c20_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c20_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c20_sfEvent);
}

static void c20_enter_atomic_gazeCamera1
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i7;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_m_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 6.0, &c20_P,
    c20_BML2);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i7 = 0; c20_i7 < 256; c20_i7++) {
    c20_set_BML2(chartInstance, c20_i7, c20_BML2[c20_i7]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  c20_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_gazeCamera1(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_BML2[256];
  real_T c20_P;
  int32_T c20_i8;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_bb_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  c20_out = CV_EML_IF(10, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs) &&
                      (chartInstance->c20_temporalCounter_i1 >= 4));
  _SFD_SYMBOL_SCOPE_POP();
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_gazeCamera1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
    chartInstance->c20_isStable = false;
    chartInstance->c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5 = c20_IN_waveLeftHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
    chartInstance->c20_temporalCounter_i1 = 0U;
    chartInstance->c20_tp_waveLeftHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_i_debug_family_names,
      c20_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    c20_fprintf(chartInstance, c20_get_fileID(chartInstance, 0));
    c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 2.0, &c20_P,
      c20_BML2);
    c20_set_P(chartInstance, 0, c20_P);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    for (c20_i8 = 0; c20_i8 < 256; c20_i8++) {
      c20_set_BML2(chartInstance, c20_i8, c20_BML2[c20_i8]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 1);
    chartInstance->c20_lFlag = 1.0;
    c20_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c20_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c20_sfEvent);
}

static void c20_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[110];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[110];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i9;
  static char_T c20_cv0[110] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a',
    't', 'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't',
    '_', 'w', 'a', 'v', 'e', '_', 'l', 'e', 'f', 't', '.', 's', 'k', 'm', '\"',
    ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '0', '.', '5', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c20_i10;
  static real_T c20_dv0[110] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 119.0, 97.0, 118.0, 101.0, 95.0, 108.0, 101.0,
    102.0, 116.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0, 101.0,
    101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c20_i11;
  int32_T c20_i12;
  int32_T c20_i13;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_b_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i9 = 0; c20_i9 < 110; c20_i9++) {
    c20_mystr[c20_i9] = c20_cv0[c20_i9];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i10 = 0; c20_i10 < 110; c20_i10++) {
    c20_arr[c20_i10] = c20_dv0[c20_i10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 110.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i11 = 0; c20_i11 < 256; c20_i11++) {
    c20_tt[c20_i11] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i12 = 0; c20_i12 < 110; c20_i12++) {
    c20_tt[c20_i12] = c20_arr[c20_i12];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i13 = 0; c20_i13 < 256; c20_i13++) {
    c20_myarr256[c20_i13] = c20_tt[c20_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_b_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[111];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[111];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i14;
  static char_T c20_cv1[111] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a',
    't', 'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't',
    '_', 'w', 'a', 'v', 'e', '_', 'r', 'i', 'g', 'h', 't', '.', 's', 'k', 'm',
    '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '0', '.', '5', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c20_i15;
  static real_T c20_dv1[111] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 119.0, 97.0, 118.0, 101.0, 95.0, 114.0, 105.0,
    103.0, 104.0, 116.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0,
    101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c20_i16;
  int32_T c20_i17;
  int32_T c20_i18;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_c_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i14 = 0; c20_i14 < 111; c20_i14++) {
    c20_mystr[c20_i14] = c20_cv1[c20_i14];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i15 = 0; c20_i15 < 111; c20_i15++) {
    c20_arr[c20_i15] = c20_dv1[c20_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 111.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i16 = 0; c20_i16 < 256; c20_i16++) {
    c20_tt[c20_i16] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i17 = 0; c20_i17 < 111; c20_i17++) {
    c20_tt[c20_i17] = c20_arr[c20_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i18 = 0; c20_i18 < 256; c20_i18++) {
    c20_myarr256[c20_i18] = c20_tt[c20_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_c_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[103];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[103];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i19;
  static char_T c20_cv2[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'H',
    'i', 'g', 'h', 'B', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '0', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c20_i20;
  static real_T c20_dv2[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 72.0, 105.0, 103.0, 104.0, 66.0, 116.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c20_i21;
  int32_T c20_i22;
  int32_T c20_i23;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_d_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i19 = 0; c20_i19 < 103; c20_i19++) {
    c20_mystr[c20_i19] = c20_cv2[c20_i19];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i20 = 0; c20_i20 < 103; c20_i20++) {
    c20_arr[c20_i20] = c20_dv2[c20_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i21 = 0; c20_i21 < 256; c20_i21++) {
    c20_tt[c20_i21] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i22 = 0; c20_i22 < 103; c20_i22++) {
    c20_tt[c20_i22] = c20_arr[c20_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i23 = 0; c20_i23 < 256; c20_i23++) {
    c20_myarr256[c20_i23] = c20_tt[c20_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_d_encStr2Arr(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[91];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[91];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i24;
  static char_T c20_cv3[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'H', 'i',
    'g', 'h', 'R', 't', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c20_i25;
  static real_T c20_dv3[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 72.0, 105.0, 103.0, 104.0, 82.0, 116.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c20_i26;
  int32_T c20_i27;
  int32_T c20_i28;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_e_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i24 = 0; c20_i24 < 91; c20_i24++) {
    c20_mystr[c20_i24] = c20_cv3[c20_i24];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i25 = 0; c20_i25 < 91; c20_i25++) {
    c20_arr[c20_i25] = c20_dv3[c20_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i26 = 0; c20_i26 < 256; c20_i26++) {
    c20_tt[c20_i26] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i27 = 0; c20_i27 < 91; c20_i27++) {
    c20_tt[c20_i27] = c20_arr[c20_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i28 = 0; c20_i28 < 256; c20_i28++) {
    c20_myarr256[c20_i28] = c20_tt[c20_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_fprintf(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c20_fileID)
{
  boolean_T c20_cond;
  int32_T c20_i29;
  static char_T c20_cv4[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 't',
    'i', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't', 'e', 'd', '_', 'm', 'x' };

  char_T c20_u[24];
  const mxArray *c20_y = NULL;
  boolean_T c20_b_cond;
  int32_T c20_i30;
  static char_T c20_cv5[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'F', 'i', 'l',
    'e', 'I', 'O', ':', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'F', 'i', 'd' };

  char_T c20_b_u[24];
  const mxArray *c20_b_y = NULL;
  int32_T c20_i31;
  static char_T c20_cv6[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c20_c_u[7];
  const mxArray *c20_c_y = NULL;
  real_T c20_d_u;
  const mxArray *c20_d_y = NULL;
  int32_T c20_i32;
  static char_T c20_formatSpec[6] = { '%', 's', '\\', 'r', '\\', 'n' };

  char_T c20_e_u[6];
  const mxArray *c20_e_y = NULL;
  int32_T c20_i33;
  static char_T c20_arg[5] = { 'W', 'a', 'v', 'e', ':' };

  char_T c20_f_u[5];
  const mxArray *c20_f_y = NULL;
  const mxArray *c20_cfmt = NULL;
  const mxArray *c20_convs = NULL;
  c20_cond = (c20_fileID != 0.0);
  if (c20_cond) {
  } else {
    for (c20_i29 = 0; c20_i29 < 24; c20_i29++) {
      c20_u[c20_i29] = c20_cv4[c20_i29];
    }

    c20_y = NULL;
    sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c20_y));
  }

  c20_b_cond = (c20_fileID > -1.0);
  if (c20_b_cond) {
  } else {
    for (c20_i30 = 0; c20_i30 < 24; c20_i30++) {
      c20_b_u[c20_i30] = c20_cv5[c20_i30];
    }

    c20_b_y = NULL;
    sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c20_b_y));
  }

  for (c20_i31 = 0; c20_i31 < 7; c20_i31++) {
    c20_c_u[c20_i31] = c20_cv6[c20_i31];
  }

  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", c20_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c20_d_u = c20_fileID;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_d_u, 0, 0U, 0U, 0U, 0), false);
  for (c20_i32 = 0; c20_i32 < 6; c20_i32++) {
    c20_e_u[c20_i32] = c20_formatSpec[c20_i32];
  }

  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", c20_e_u, 10, 0U, 1U, 0U, 2, 1, 6),
                false);
  for (c20_i33 = 0; c20_i33 < 5; c20_i33++) {
    c20_f_u[c20_i33] = c20_arg[c20_i33];
  }

  c20_f_y = NULL;
  sf_mex_assign(&c20_f_y, sf_mex_create("y", c20_f_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c20_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                       (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14,
                        c20_c_y, 14, c20_d_y, 14, c20_e_y, 14, c20_f_y), "feval");
  sf_mex_destroy(&c20_cfmt);
  sf_mex_destroy(&c20_convs);
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, c20_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\12-9-2015-Matlab-prior-M+M\\encStr2Arr.m"));
}

static real_T c20_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_feval, const char_T *c20_identifier)
{
  real_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_feval),
    &c20_thisId);
  sf_mex_destroy(&c20_feval);
  return c20_y;
}

static real_T c20_b_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i34;
  real_T c20_b_inData[256];
  int32_T c20_i35;
  real_T c20_u[256];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i34 = 0; c20_i34 < 256; c20_i34++) {
    c20_b_inData[c20_i34] = (*(real_T (*)[256])c20_inData)[c20_i34];
  }

  for (c20_i35 = 0; c20_i35 < 256; c20_i35++) {
    c20_u[c20_i35] = c20_b_inData[c20_i35];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_c_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256])
{
  real_T c20_dv4[256];
  int32_T c20_i36;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv4, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c20_i36 = 0; c20_i36 < 256; c20_i36++) {
    c20_y[c20_i36] = c20_dv4[c20_i36];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_poseBML;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[256];
  int32_T c20_i37;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_poseBML = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_poseBML), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_poseBML);
  for (c20_i37 = 0; c20_i37 < 256; c20_i37++) {
    (*(real_T (*)[256])c20_outData)[c20_i37] = c20_y[c20_i37];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_feval;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_feval = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_feval),
    &c20_thisId);
  sf_mex_destroy(&c20_feval);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  boolean_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(boolean_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static boolean_T c20_d_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  boolean_T c20_y;
  boolean_T c20_b0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_b0, 1, 11, 0U, 0, 0U, 0);
  c20_y = c20_b0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_aVarTruthTableCondition_6;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  boolean_T c20_y;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_aVarTruthTableCondition_6 = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_aVarTruthTableCondition_6), &c20_thisId);
  sf_mex_destroy(&c20_aVarTruthTableCondition_6);
  *(boolean_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i38;
  real_T c20_b_inData[256];
  int32_T c20_i39;
  real_T c20_u[256];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i38 = 0; c20_i38 < 256; c20_i38++) {
    c20_b_inData[c20_i38] = (*(real_T (*)[256])c20_inData)[c20_i38];
  }

  for (c20_i39 = 0; c20_i39 < 256; c20_i39++) {
    c20_u[c20_i39] = c20_b_inData[c20_i39];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_e_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256])
{
  real_T c20_dv5[256];
  int32_T c20_i40;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv5, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c20_i40 = 0; c20_i40 < 256; c20_i40++) {
    c20_y[c20_i40] = c20_dv5[c20_i40];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_myarr256;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[256];
  int32_T c20_i41;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_myarr256 = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_myarr256), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_myarr256);
  for (c20_i41 = 0; c20_i41 < 256; c20_i41++) {
    (*(real_T (*)[256])c20_outData)[c20_i41] = c20_y[c20_i41];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i42;
  char_T c20_b_inData[110];
  int32_T c20_i43;
  char_T c20_u[110];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i42 = 0; c20_i42 < 110; c20_i42++) {
    c20_b_inData[c20_i42] = (*(char_T (*)[110])c20_inData)[c20_i42];
  }

  for (c20_i43 = 0; c20_i43 < 110; c20_i43++) {
    c20_u[c20_i43] = c20_b_inData[c20_i43];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 110),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i44;
  real_T c20_b_inData[110];
  int32_T c20_i45;
  real_T c20_u[110];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i44 = 0; c20_i44 < 110; c20_i44++) {
    c20_b_inData[c20_i44] = (*(real_T (*)[110])c20_inData)[c20_i44];
  }

  for (c20_i45 = 0; c20_i45 < 110; c20_i45++) {
    c20_u[c20_i45] = c20_b_inData[c20_i45];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 110), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i46;
  char_T c20_b_inData[111];
  int32_T c20_i47;
  char_T c20_u[111];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i46 = 0; c20_i46 < 111; c20_i46++) {
    c20_b_inData[c20_i46] = (*(char_T (*)[111])c20_inData)[c20_i46];
  }

  for (c20_i47 = 0; c20_i47 < 111; c20_i47++) {
    c20_u[c20_i47] = c20_b_inData[c20_i47];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 111),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_h_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i48;
  real_T c20_b_inData[111];
  int32_T c20_i49;
  real_T c20_u[111];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i48 = 0; c20_i48 < 111; c20_i48++) {
    c20_b_inData[c20_i48] = (*(real_T (*)[111])c20_inData)[c20_i48];
  }

  for (c20_i49 = 0; c20_i49 < 111; c20_i49++) {
    c20_u[c20_i49] = c20_b_inData[c20_i49];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 111), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_i_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i50;
  char_T c20_b_inData[103];
  int32_T c20_i51;
  char_T c20_u[103];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i50 = 0; c20_i50 < 103; c20_i50++) {
    c20_b_inData[c20_i50] = (*(char_T (*)[103])c20_inData)[c20_i50];
  }

  for (c20_i51 = 0; c20_i51 < 103; c20_i51++) {
    c20_u[c20_i51] = c20_b_inData[c20_i51];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_j_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i52;
  real_T c20_b_inData[103];
  int32_T c20_i53;
  real_T c20_u[103];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i52 = 0; c20_i52 < 103; c20_i52++) {
    c20_b_inData[c20_i52] = (*(real_T (*)[103])c20_inData)[c20_i52];
  }

  for (c20_i53 = 0; c20_i53 < 103; c20_i53++) {
    c20_u[c20_i53] = c20_b_inData[c20_i53];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 103), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_k_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i54;
  char_T c20_b_inData[91];
  int32_T c20_i55;
  char_T c20_u[91];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i54 = 0; c20_i54 < 91; c20_i54++) {
    c20_b_inData[c20_i54] = (*(char_T (*)[91])c20_inData)[c20_i54];
  }

  for (c20_i55 = 0; c20_i55 < 91; c20_i55++) {
    c20_u[c20_i55] = c20_b_inData[c20_i55];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 91),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_l_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i56;
  real_T c20_b_inData[91];
  int32_T c20_i57;
  real_T c20_u[91];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i56 = 0; c20_i56 < 91; c20_i56++) {
    c20_b_inData[c20_i56] = (*(real_T (*)[91])c20_inData)[c20_i56];
  }

  for (c20_i57 = 0; c20_i57 < 91; c20_i57++) {
    c20_u[c20_i57] = c20_b_inData[c20_i57];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_m_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i58;
  char_T c20_b_inData[115];
  int32_T c20_i59;
  char_T c20_u[115];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i58 = 0; c20_i58 < 115; c20_i58++) {
    c20_b_inData[c20_i58] = (*(char_T (*)[115])c20_inData)[c20_i58];
  }

  for (c20_i59 = 0; c20_i59 < 115; c20_i59++) {
    c20_u[c20_i59] = c20_b_inData[c20_i59];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_n_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i60;
  real_T c20_b_inData[115];
  int32_T c20_i61;
  real_T c20_u[115];
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i60 = 0; c20_i60 < 115; c20_i60++) {
    c20_b_inData[c20_i60] = (*(real_T (*)[115])c20_inData)[c20_i60];
  }

  for (c20_i61 = 0; c20_i61 < 115; c20_i61++) {
    c20_u[c20_i61] = c20_b_inData[c20_i61];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

const mxArray *sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_createstruct("structure", 2, 45, 1),
                false);
  c20_info_helper(&c20_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(const mxArray **c20_info)
{
  const mxArray *c20_rhs0 = NULL;
  const mxArray *c20_lhs0 = NULL;
  const mxArray *c20_rhs1 = NULL;
  const mxArray *c20_lhs1 = NULL;
  const mxArray *c20_rhs2 = NULL;
  const mxArray *c20_lhs2 = NULL;
  const mxArray *c20_rhs3 = NULL;
  const mxArray *c20_lhs3 = NULL;
  const mxArray *c20_rhs4 = NULL;
  const mxArray *c20_lhs4 = NULL;
  const mxArray *c20_rhs5 = NULL;
  const mxArray *c20_lhs5 = NULL;
  const mxArray *c20_rhs6 = NULL;
  const mxArray *c20_lhs6 = NULL;
  const mxArray *c20_rhs7 = NULL;
  const mxArray *c20_lhs7 = NULL;
  const mxArray *c20_rhs8 = NULL;
  const mxArray *c20_lhs8 = NULL;
  const mxArray *c20_rhs9 = NULL;
  const mxArray *c20_lhs9 = NULL;
  const mxArray *c20_rhs10 = NULL;
  const mxArray *c20_lhs10 = NULL;
  const mxArray *c20_rhs11 = NULL;
  const mxArray *c20_lhs11 = NULL;
  const mxArray *c20_rhs12 = NULL;
  const mxArray *c20_lhs12 = NULL;
  const mxArray *c20_rhs13 = NULL;
  const mxArray *c20_lhs13 = NULL;
  const mxArray *c20_rhs14 = NULL;
  const mxArray *c20_lhs14 = NULL;
  const mxArray *c20_rhs15 = NULL;
  const mxArray *c20_lhs15 = NULL;
  const mxArray *c20_rhs16 = NULL;
  const mxArray *c20_lhs16 = NULL;
  const mxArray *c20_rhs17 = NULL;
  const mxArray *c20_lhs17 = NULL;
  const mxArray *c20_rhs18 = NULL;
  const mxArray *c20_lhs18 = NULL;
  const mxArray *c20_rhs19 = NULL;
  const mxArray *c20_lhs19 = NULL;
  const mxArray *c20_rhs20 = NULL;
  const mxArray *c20_lhs20 = NULL;
  const mxArray *c20_rhs21 = NULL;
  const mxArray *c20_lhs21 = NULL;
  const mxArray *c20_rhs22 = NULL;
  const mxArray *c20_lhs22 = NULL;
  const mxArray *c20_rhs23 = NULL;
  const mxArray *c20_lhs23 = NULL;
  const mxArray *c20_rhs24 = NULL;
  const mxArray *c20_lhs24 = NULL;
  const mxArray *c20_rhs25 = NULL;
  const mxArray *c20_lhs25 = NULL;
  const mxArray *c20_rhs26 = NULL;
  const mxArray *c20_lhs26 = NULL;
  const mxArray *c20_rhs27 = NULL;
  const mxArray *c20_lhs27 = NULL;
  const mxArray *c20_rhs28 = NULL;
  const mxArray *c20_lhs28 = NULL;
  const mxArray *c20_rhs29 = NULL;
  const mxArray *c20_lhs29 = NULL;
  const mxArray *c20_rhs30 = NULL;
  const mxArray *c20_lhs30 = NULL;
  const mxArray *c20_rhs31 = NULL;
  const mxArray *c20_lhs31 = NULL;
  const mxArray *c20_rhs32 = NULL;
  const mxArray *c20_lhs32 = NULL;
  const mxArray *c20_rhs33 = NULL;
  const mxArray *c20_lhs33 = NULL;
  const mxArray *c20_rhs34 = NULL;
  const mxArray *c20_lhs34 = NULL;
  const mxArray *c20_rhs35 = NULL;
  const mxArray *c20_lhs35 = NULL;
  const mxArray *c20_rhs36 = NULL;
  const mxArray *c20_lhs36 = NULL;
  const mxArray *c20_rhs37 = NULL;
  const mxArray *c20_lhs37 = NULL;
  const mxArray *c20_rhs38 = NULL;
  const mxArray *c20_lhs38 = NULL;
  const mxArray *c20_rhs39 = NULL;
  const mxArray *c20_lhs39 = NULL;
  const mxArray *c20_rhs40 = NULL;
  const mxArray *c20_lhs40 = NULL;
  const mxArray *c20_rhs41 = NULL;
  const mxArray *c20_lhs41 = NULL;
  const mxArray *c20_rhs42 = NULL;
  const mxArray *c20_lhs42 = NULL;
  const mxArray *c20_rhs43 = NULL;
  const mxArray *c20_lhs43 = NULL;
  const mxArray *c20_rhs44 = NULL;
  const mxArray *c20_lhs44 = NULL;
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/12-9-2015-Matlab-prior-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c20_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("fprintf"), "name", "name", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c20_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("isequal"), "name", "name", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c20_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c20_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("isnan"), "name", "name", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c20_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c20_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c20_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("upper"), "name", "name", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c20_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c20_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c20_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c20_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("intmax"), "name", "name", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c20_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c20_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c20_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("colon"), "name", "name", 14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c20_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("colon"), "name", "name", 15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c20_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c20_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c20_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("floor"), "name", "name", 18);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c20_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c20_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 20);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c20_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 21);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("intmin"), "name", "name", 21);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c20_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c20_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 23);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("intmax"), "name", "name", 23);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c20_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 24);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("intmin"), "name", "name", 24);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c20_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 25);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("intmax"), "name", "name", 25);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c20_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 26);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 26);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c20_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 27);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c20_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 28);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 28);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c20_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 29);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c20_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 30);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 30);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c20_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 31);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c20_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 32);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("intmax"), "name", "name", 32);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c20_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 33);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 33);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c20_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 34);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 34);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c20_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 35);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c20_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 36);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 36);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c20_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 37);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("intmax"), "name", "name", 37);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c20_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "name", "name", 38);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c20_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("fidCheck"), "name", "name",
                  39);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c20_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("upper"), "name", "name", 40);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c20_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 41);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c20_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 42);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 42);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c20_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 43);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 43);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c20_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 44);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 44);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c20_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs44), "lhs", "lhs",
                  44);
  sf_mex_destroy(&c20_rhs0);
  sf_mex_destroy(&c20_lhs0);
  sf_mex_destroy(&c20_rhs1);
  sf_mex_destroy(&c20_lhs1);
  sf_mex_destroy(&c20_rhs2);
  sf_mex_destroy(&c20_lhs2);
  sf_mex_destroy(&c20_rhs3);
  sf_mex_destroy(&c20_lhs3);
  sf_mex_destroy(&c20_rhs4);
  sf_mex_destroy(&c20_lhs4);
  sf_mex_destroy(&c20_rhs5);
  sf_mex_destroy(&c20_lhs5);
  sf_mex_destroy(&c20_rhs6);
  sf_mex_destroy(&c20_lhs6);
  sf_mex_destroy(&c20_rhs7);
  sf_mex_destroy(&c20_lhs7);
  sf_mex_destroy(&c20_rhs8);
  sf_mex_destroy(&c20_lhs8);
  sf_mex_destroy(&c20_rhs9);
  sf_mex_destroy(&c20_lhs9);
  sf_mex_destroy(&c20_rhs10);
  sf_mex_destroy(&c20_lhs10);
  sf_mex_destroy(&c20_rhs11);
  sf_mex_destroy(&c20_lhs11);
  sf_mex_destroy(&c20_rhs12);
  sf_mex_destroy(&c20_lhs12);
  sf_mex_destroy(&c20_rhs13);
  sf_mex_destroy(&c20_lhs13);
  sf_mex_destroy(&c20_rhs14);
  sf_mex_destroy(&c20_lhs14);
  sf_mex_destroy(&c20_rhs15);
  sf_mex_destroy(&c20_lhs15);
  sf_mex_destroy(&c20_rhs16);
  sf_mex_destroy(&c20_lhs16);
  sf_mex_destroy(&c20_rhs17);
  sf_mex_destroy(&c20_lhs17);
  sf_mex_destroy(&c20_rhs18);
  sf_mex_destroy(&c20_lhs18);
  sf_mex_destroy(&c20_rhs19);
  sf_mex_destroy(&c20_lhs19);
  sf_mex_destroy(&c20_rhs20);
  sf_mex_destroy(&c20_lhs20);
  sf_mex_destroy(&c20_rhs21);
  sf_mex_destroy(&c20_lhs21);
  sf_mex_destroy(&c20_rhs22);
  sf_mex_destroy(&c20_lhs22);
  sf_mex_destroy(&c20_rhs23);
  sf_mex_destroy(&c20_lhs23);
  sf_mex_destroy(&c20_rhs24);
  sf_mex_destroy(&c20_lhs24);
  sf_mex_destroy(&c20_rhs25);
  sf_mex_destroy(&c20_lhs25);
  sf_mex_destroy(&c20_rhs26);
  sf_mex_destroy(&c20_lhs26);
  sf_mex_destroy(&c20_rhs27);
  sf_mex_destroy(&c20_lhs27);
  sf_mex_destroy(&c20_rhs28);
  sf_mex_destroy(&c20_lhs28);
  sf_mex_destroy(&c20_rhs29);
  sf_mex_destroy(&c20_lhs29);
  sf_mex_destroy(&c20_rhs30);
  sf_mex_destroy(&c20_lhs30);
  sf_mex_destroy(&c20_rhs31);
  sf_mex_destroy(&c20_lhs31);
  sf_mex_destroy(&c20_rhs32);
  sf_mex_destroy(&c20_lhs32);
  sf_mex_destroy(&c20_rhs33);
  sf_mex_destroy(&c20_lhs33);
  sf_mex_destroy(&c20_rhs34);
  sf_mex_destroy(&c20_lhs34);
  sf_mex_destroy(&c20_rhs35);
  sf_mex_destroy(&c20_lhs35);
  sf_mex_destroy(&c20_rhs36);
  sf_mex_destroy(&c20_lhs36);
  sf_mex_destroy(&c20_rhs37);
  sf_mex_destroy(&c20_lhs37);
  sf_mex_destroy(&c20_rhs38);
  sf_mex_destroy(&c20_lhs38);
  sf_mex_destroy(&c20_rhs39);
  sf_mex_destroy(&c20_lhs39);
  sf_mex_destroy(&c20_rhs40);
  sf_mex_destroy(&c20_lhs40);
  sf_mex_destroy(&c20_rhs41);
  sf_mex_destroy(&c20_lhs41);
  sf_mex_destroy(&c20_rhs42);
  sf_mex_destroy(&c20_lhs42);
  sf_mex_destroy(&c20_rhs43);
  sf_mex_destroy(&c20_lhs43);
  sf_mex_destroy(&c20_rhs44);
  sf_mex_destroy(&c20_lhs44);
}

static const mxArray *c20_emlrt_marshallOut(const char * c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c20_u)), false);
  return c20_y;
}

static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), false);
  return c20_y;
}

static void c20_activate_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = c20_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c20_event_secs,
               chartInstance->c20_sfEvent);
}

static void c20_deactivate_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c20_event_secs,
               chartInstance->c20_sfEvent);
}

static void c20_increment_counters_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  if (chartInstance->c20_temporalCounter_i1 < 7U) {
    chartInstance->c20_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c20_temporalCounter_i1 + 1);
  }
}

static void c20_reset_counters_secsc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_activate_secsc20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_increment_counters_secsc20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_reset_counters_secsc20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_deactivate_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct
  *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_deactivate_secsc20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

boolean_T sf_exported_auto_isStablec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  return chartInstance->c20_isStable;
}

void sf_exported_auto_duringc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_c20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_enterc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c20_enter_atomic_c20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
  c20_enter_internal_c20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_exitc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c20_exit_internal_c20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_gatewayc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c20_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_initc20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c20_S)
{
  const mxArray *c20_out = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_out = NULL;
  sf_mex_assign(&c20_out, sf_internal_get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
                (c20_S), false);
  return c20_out;
}

void sf_exported_auto_setSimstatec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S,
  const mxArray *c20_in)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5(c20_S, sf_mex_dup(c20_in));
  sf_mex_destroy(&c20_in);
}

void sf_exported_auto_check_state_inconsistency_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, real_T c20_bmlID,
   real_T *c20_pr, real_T c20_poseBML[256])
{
  uint32_T c20_debug_family_var_map[11];
  boolean_T c20_aVarTruthTableCondition_1;
  boolean_T c20_aVarTruthTableCondition_2;
  boolean_T c20_aVarTruthTableCondition_3;
  boolean_T c20_aVarTruthTableCondition_4;
  boolean_T c20_aVarTruthTableCondition_5;
  boolean_T c20_aVarTruthTableCondition_6;
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 2.0;
  real_T c20_dv6[256];
  int32_T c20_i62;
  int32_T c20_i63;
  int32_T c20_i64;
  int32_T c20_i65;
  int32_T c20_i66;
  uint32_T c20_b_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[115];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[115];
  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_myarr256[256];
  int32_T c20_i67;
  static char_T c20_cv7[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c20_i68;
  static real_T c20_dv7[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c20_i69;
  int32_T c20_i70;
  int32_T c20_i71;
  int32_T c20_i72;
  int32_T c20_i73;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_1, 0U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_2, 1U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_3, 2U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_4, 3U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_5, 4U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_6, 5U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_bmlID, 8U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_pr, 9U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_poseBML, 10U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 3);
  c20_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 4);
  c20_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 5);
  c20_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 6);
  c20_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 7);
  c20_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 8);
  c20_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 12);
  c20_aVarTruthTableCondition_1 = (c20_bmlID == 1.0);
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 15);
  c20_aVarTruthTableCondition_2 = (c20_bmlID == 2.0);
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 18);
  c20_aVarTruthTableCondition_3 = (c20_bmlID == 3.0);
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 21);
  c20_aVarTruthTableCondition_4 = (c20_bmlID == 4.0);
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 24);
  c20_aVarTruthTableCondition_5 = (c20_bmlID == 5.0);
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 27);
  c20_aVarTruthTableCondition_6 = (c20_bmlID == 6.0);
  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 29);
  if (CV_EML_IF(7, 1, 0, c20_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 30);
    CV_EML_FCN(7, 1);
    _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 49);
    c20_encStr2Arr(chartInstance, c20_dv6);
    for (c20_i62 = 0; c20_i62 < 256; c20_i62++) {
      c20_poseBML[c20_i62] = c20_dv6[c20_i62];
    }

    c20_updateDataWrittenToVector(chartInstance, 5U);
    _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 49);
    *c20_pr = 2.0;
    c20_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -49);
  } else {
    _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 31);
    if (CV_EML_IF(7, 1, 1, c20_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 32);
      CV_EML_FCN(7, 2);
      _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 55);
      c20_b_encStr2Arr(chartInstance, c20_dv6);
      for (c20_i63 = 0; c20_i63 < 256; c20_i63++) {
        c20_poseBML[c20_i63] = c20_dv6[c20_i63];
      }

      c20_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 55);
      *c20_pr = 2.0;
      c20_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -55);
    } else {
      _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 33);
      if (CV_EML_IF(7, 1, 2, c20_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 34);
        CV_EML_FCN(7, 3);
        _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 61);
        c20_c_encStr2Arr(chartInstance, c20_dv6);
        for (c20_i64 = 0; c20_i64 < 256; c20_i64++) {
          c20_poseBML[c20_i64] = c20_dv6[c20_i64];
        }

        c20_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 61);
        *c20_pr = 2.0;
        c20_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -61);
      } else {
        _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 35);
        if (CV_EML_IF(7, 1, 3, c20_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 36);
          CV_EML_FCN(7, 4);
          _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 67);
          c20_d_encStr2Arr(chartInstance, c20_dv6);
          for (c20_i65 = 0; c20_i65 < 256; c20_i65++) {
            c20_poseBML[c20_i65] = c20_dv6[c20_i65];
          }

          c20_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 67);
          *c20_pr = 2.0;
          c20_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -67);
        } else {
          _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 37);
          if (CV_EML_IF(7, 1, 4, c20_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 38);
            CV_EML_FCN(7, 5);
            _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 73);
            c20_d_encStr2Arr(chartInstance, c20_dv6);
            for (c20_i66 = 0; c20_i66 < 256; c20_i66++) {
              c20_poseBML[c20_i66] = c20_dv6[c20_i66];
            }

            c20_updateDataWrittenToVector(chartInstance, 5U);
            _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 73);
            *c20_pr = 2.0;
            c20_updateDataWrittenToVector(chartInstance, 4U);
            _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -73);
          } else {
            _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 39);
            if (CV_EML_IF(7, 1, 5, c20_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 40);
              CV_EML_FCN(7, 6);
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 79);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_f_debug_family_names,
                c20_b_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_n_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U,
                c20_d_sf_marshallOut, c20_d_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_m_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 6U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 7U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U,
                c20_d_sf_marshallOut, c20_d_sf_marshallIn);
              for (c20_i67 = 0; c20_i67 < 115; c20_i67++) {
                c20_mystr[c20_i67] = c20_cv7[c20_i67];
              }

              CV_SCRIPT_FCN(0, 0);
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
              c20_maxarrsize = 256.0;
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
              for (c20_i68 = 0; c20_i68 < 115; c20_i68++) {
                c20_arr[c20_i68] = c20_dv7[c20_i68];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
              c20_ss = 115.0;
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
              c20_padsize = c20_maxarrsize - c20_ss;
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
              for (c20_i69 = 0; c20_i69 < 256; c20_i69++) {
                c20_tt[c20_i69] = 0.0;
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
              for (c20_i70 = 0; c20_i70 < 115; c20_i70++) {
                c20_tt[c20_i70] = c20_arr[c20_i70];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
              for (c20_i71 = 0; c20_i71 < 256; c20_i71++) {
                c20_myarr256[c20_i71] = c20_tt[c20_i71];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
              _SFD_SYMBOL_SCOPE_POP();
              for (c20_i72 = 0; c20_i72 < 256; c20_i72++) {
                c20_poseBML[c20_i72] = c20_myarr256[c20_i72];
              }

              c20_updateDataWrittenToVector(chartInstance, 5U);
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 79);
              *c20_pr = 2.0;
              c20_updateDataWrittenToVector(chartInstance, 4U);
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -79);
            } else {
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 42);
              CV_EML_FCN(7, 1);
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 49);
              c20_encStr2Arr(chartInstance, c20_dv6);
              for (c20_i73 = 0; c20_i73 < 256; c20_i73++) {
                c20_poseBML[c20_i73] = c20_dv6[c20_i73];
              }

              c20_updateDataWrittenToVector(chartInstance, 5U);
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, 49);
              *c20_pr = 2.0;
              c20_updateDataWrittenToVector(chartInstance, 4U);
              _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -49);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(7U, chartInstance->c20_sfEvent, -42);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c20_ARP_02_RPSs_Bdr_GK_BIS5_wavePoseBradTable(SimStruct
  *c20_S, real_T c20_bmlID, real_T *c20_pr, real_T c20_poseBML[256])
{
  real_T c20_b_pr;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)
    ->chartInstance;
  c20_wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, c20_bmlID,
    &c20_b_pr, c20_poseBML);
  *c20_pr = c20_b_pr;
}

static const mxArray *c20_o_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int8_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int8_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int8_T c20_f_emlrt_marshallIn(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int8_T c20_y;
  int8_T c20_i74;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i74, 1, 2, 0U, 0, 0U, 0);
  c20_y = c20_i74;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_secs;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int8_T c20_y;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_secs = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_secs),
    &c20_thisId);
  sf_mex_destroy(&c20_secs);
  *(int8_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_p_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_g_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i75;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i75, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i75;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_q_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  uint8_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(uint8_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static uint8_T c20_h_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_b_tp_waveRightHand, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_tp_waveRightHand), &c20_thisId);
  sf_mex_destroy(&c20_b_tp_waveRightHand);
  return c20_y;
}

static uint8_T c20_i_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_tp_waveRightHand;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint8_T c20_y;
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c20_b_tp_waveRightHand = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_tp_waveRightHand), &c20_thisId);
  sf_mex_destroy(&c20_b_tp_waveRightHand);
  *(uint8_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_j_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier)
{
  const mxArray *c20_y = NULL;
  emlrtMsgIdentifier c20_thisId;
  c20_y = NULL;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  sf_mex_assign(&c20_y, c20_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_setSimStateSideEffectsInfo), &c20_thisId), false);
  sf_mex_destroy(&c20_b_setSimStateSideEffectsInfo);
  return c20_y;
}

static const mxArray *c20_k_emlrt_marshallIn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  const mxArray *c20_y = NULL;
  (void)chartInstance;
  (void)c20_parentId;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_duplicatearraysafe(&c20_u), false);
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_updateDataWrittenToVector
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c20_vectorIndex)
{
  (void)chartInstance;
  c20_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c20_vectorIndex, 0, 5, 1, 0)] = true;
}

static void c20_errorIfDataNotWrittenToFcn
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c20_vectorIndex, uint32_T c20_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c20_dataNumber, c20_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c20_vectorIndex, 0, 5, 1,
    0)]);
}

static real_T c20_get_BML(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c20_b);
  if (chartInstance->c20_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#643) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c20_BML_address)[c20_b];
}

static void c20_set_BML(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c20_b);
  if (chartInstance->c20_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#643) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c20_BML_address)[c20_b] = c20_c;
}

static real_T *c20_access_BML(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c20_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#643) in the initialization routine of the chart.\n");
  }

  c20_c = *chartInstance->c20_BML_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c20_c;
}

static real_T c20_get_BML2(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c20_b);
  if (chartInstance->c20_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#650) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c20_BML2_address)[c20_b];
}

static void c20_set_BML2(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c20_b);
  if (chartInstance->c20_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#650) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c20_BML2_address)[c20_b] = c20_c;
}

static real_T *c20_access_BML2(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c20_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#650) in the initialization routine of the chart.\n");
  }

  c20_c = *chartInstance->c20_BML2_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c20_c;
}

static real_T c20_get_P(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c20_b);
  if (chartInstance->c20_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#644) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_P_address;
}

static void c20_set_P(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                      uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c20_b);
  if (chartInstance->c20_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#644) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_P_address = c20_c;
}

static real_T *c20_access_P(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c20_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#644) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_P_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c20_c;
}

static real_T c20_get_STATE_BEFORE(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c20_b);
  if (chartInstance->c20_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#646) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_STATE_BEFORE_address;
}

static void c20_set_STATE_BEFORE(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c20_b);
  if (chartInstance->c20_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#646) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_STATE_BEFORE_address = c20_c;
}

static real_T *c20_access_STATE_BEFORE
  (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c20_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#646) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_STATE_BEFORE_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c20_c;
}

static real_T c20_get_STATE_OVER(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c20_b);
  if (chartInstance->c20_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#645) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_STATE_OVER_address;
}

static void c20_set_STATE_OVER(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c20_b);
  if (chartInstance->c20_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#645) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_STATE_OVER_address = c20_c;
}

static real_T *c20_access_STATE_OVER(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c20_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#645) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_STATE_OVER_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c20_c;
}

static real_T c20_get_avert(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c20_b);
  if (chartInstance->c20_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#848) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_avert_address;
}

static void c20_set_avert(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c20_b);
  if (chartInstance->c20_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#848) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_avert_address = c20_c;
}

static real_T *c20_access_avert(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c20_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#848) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_avert_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c20_c;
}

static real_T c20_get_fileID(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c20_b);
  if (chartInstance->c20_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#640) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_fileID_address;
}

static void c20_set_fileID(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c20_b);
  if (chartInstance->c20_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#640) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_fileID_address = c20_c;
}

static real_T *c20_access_fileID(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c20_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#640) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_fileID_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c20_c;
}

static void init_dsm_address_info(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c20_BML_address, &chartInstance->c20_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML2", (void **)
    &chartInstance->c20_BML2_address, &chartInstance->c20_BML2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c20_P_address, &chartInstance->c20_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c20_STATE_BEFORE_address,
    &chartInstance->c20_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c20_STATE_OVER_address, &chartInstance->c20_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c20_avert_address, &chartInstance->c20_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c20_fileID_address, &chartInstance->c20_fileID_index);
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

void sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1960360590U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(531122339U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1394594821U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2353462919U);
}

mxArray *sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WPcogFW9Rxhb5tNAzPa2KG");
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c20_ARP_02_RPSs_Bdr_GK_BIS5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[25],T\"gameState\",},{M[3],M[33],T\"bFlag\",},{M[3],M[32],T\"lFlag\",},{M[3],M[31],T\"rFlag\",},{M[8],M[0],T\"is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5\",},{M[9],M[0],T\"is_c20_ARP_02_RPSs_Bdr_GK_BIS5\",},{M[11],M[29],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x7[8 10 42 11 51 49 46],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
           20,
           9,
           18,
           0,
           15,
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
          _SFD_SET_DATA_PROPS(0,11,0,0,"fileID");
          _SFD_SET_DATA_PROPS(1,1,1,0,"handUp");
          _SFD_SET_DATA_PROPS(2,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(3,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(4,11,0,0,"P");
          _SFD_SET_DATA_PROPS(5,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(6,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(7,0,0,0,"rFlag");
          _SFD_SET_DATA_PROPS(8,0,0,0,"lFlag");
          _SFD_SET_DATA_PROPS(9,0,0,0,"bFlag");
          _SFD_SET_DATA_PROPS(10,11,0,0,"BML2");
          _SFD_SET_DATA_PROPS(11,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(12,9,0,0,"");
          _SFD_SET_DATA_PROPS(13,8,0,0,"");
          _SFD_SET_DATA_PROPS(14,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(7,0,2);
          _SFD_CH_SUBSTATE_COUNT(8);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,5);
          _SFD_CH_SUBSTATE_INDEX(6,6);
          _SFD_CH_SUBSTATE_INDEX(7,8);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
        }

        _SFD_CV_INIT_CHART(8,1,0,0);

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
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(7,1,7,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"wavePoseBradTablec20_ARP_02_RPSs_Bdr_GK_BIS5",
                             0,-1,990);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",990,-1,1182);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",1182,-1,1376);
        _SFD_CV_INIT_EML_FCN(7,3,"aFcnTruthTableAction_3",1376,-1,1557);
        _SFD_CV_INIT_EML_FCN(7,4,"aFcnTruthTableAction_4",1557,-1,1725);
        _SFD_CV_INIT_EML_FCN(7,5,"aFcnTruthTableAction_5",1725,-1,1894);
        _SFD_CV_INIT_EML_FCN(7,6,"aFcnTruthTableAction_6",1894,-1,2087);
        _SFD_CV_INIT_EML_IF(7,1,0,554,584,615,988);
        _SFD_CV_INIT_EML_IF(7,1,1,615,649,680,988);
        _SFD_CV_INIT_EML_IF(7,1,2,680,714,745,988);
        _SFD_CV_INIT_EML_IF(7,1,3,745,779,810,988);
        _SFD_CV_INIT_EML_IF(7,1,4,810,844,875,988);
        _SFD_CV_INIT_EML_IF(7,1,5,875,909,940,988);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 12, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 12, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,22,1,22);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 12, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,9,1,9);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(12,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));

        {
          real_T *c20_handUp;
          real_T *c20_gameState;
          c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c20_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c20_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(1U, c20_handUp);
          _SFD_SET_DATA_VALUE_PTR(2U, c20_gameState);
          _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c20_BML_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c20_P_address);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c20_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c20_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c20_rFlag);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c20_lFlag);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c20_bFlag);
          _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c20_BML2_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c20_avert_address);
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
  return "2DX7YpzcNsDXrShLw00aOF";
}

static void sf_opaque_initialize_c20_ARP_02_RPSs_Bdr_GK_BIS5(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
  initialize_c20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  enable_c20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  disable_c20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  sf_gateway_c20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_ARP_02_RPSs_Bdr_GK_BIS5();/* state var info */
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

extern void sf_internal_set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c20_ARP_02_RPSs_Bdr_GK_BIS5();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c20_ARP_02_RPSs_Bdr_GK_BIS5(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSs_Bdr_GK_BIS5_optimization_info();
    }

    finalize_c20_ARP_02_RPSs_Bdr_GK_BIS5
      ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
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
    initialize_params_c20_ARP_02_RPSs_Bdr_GK_BIS5
      ((SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSs_Bdr_GK_BIS5_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2691033097U));
  ssSetChecksum1(S,(248916415U));
  ssSetChecksum2(S,(4158151505U));
  ssSetChecksum3(S,(3748802872U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)utMalloc(sizeof
    (SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_ARP_02_RPSs_Bdr_GK_BIS5;
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

void c20_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
