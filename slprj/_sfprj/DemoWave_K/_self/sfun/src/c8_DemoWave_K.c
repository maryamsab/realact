/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DemoWave_K_sfun.h"
#include "c8_DemoWave_K.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DemoWave_K_sfun_debug_macros.h"
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
#define c8_IN_wait2                    ((uint8_T)11U)
#define c8_IN_walkFW                   ((uint8_T)12U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c8_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_c_debug_family_names[4] = { "nargin", "nargout",
  "myarr256", "mystr" };

static const char * c8_d_debug_family_names[13] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "p", "poseBML" };

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

static const char * c8_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_m_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c8_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_v_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c8_ib_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c8_xb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_yb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ac_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_bc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_cc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_dc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ec_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ic_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c8_dataWrittenToVector[17];

/* Function Declarations */
static void initialize_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void initialize_params_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void enable_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void disable_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *
  chartInstance);
static void set_sim_state_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void c8_set_sim_state_side_effects_c8_DemoWave_K
  (SFc8_DemoWave_KInstanceStruct *chartInstance);
static void finalize_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void sf_gateway_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_enter_atomic_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_enter_internal_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_exit_internal_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_initc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void initSimStructsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_enter_atomic_gazeSurprized(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_gazeSurprized(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_enter_atomic_stateWalkBack(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_enter_atomic_headNeuralGazeCamera(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_headNeuralGazeCamera(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_enter_atomic_browUp(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_browUp(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_checkUserCoord(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_enter_atomic_idle(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_enter_atomic_leanFW(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_enter_atomic_walkFW(SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_enter_atomic_leanNeutral(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_decArr2Str(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256], char_T c8_mystr_data[], int32_T c8_mystr_sizes[2]);
static void c8_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256]);
static void c8_b_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256]);
static void c8_c_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256]);
static void c8_d_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256]);
static void c8_e_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256]);
static void c8_f_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256]);
static void c8_g_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256]);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_newBmls, const char_T *c8_identifier, real_T c8_y[1280]);
static void c8_b_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[1280]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_c_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[256]);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_d_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_nargout, const char_T *c8_identifier);
static real_T c8_e_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_f_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_myarr256, const char_T *c8_identifier, real_T c8_y[256]);
static void c8_g_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[256]);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, char_T
  c8_inData_data[], int32_T c8_inData_sizes[2]);
static void c8_h_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, char_T c8_y_data[],
  int32_T c8_y_sizes[2]);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, char_T c8_outData_data[], int32_T
  c8_outData_sizes[2]);
static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static boolean_T c8_i_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
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
static const mxArray *c8_s_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_t_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_u_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(const char * c8_u);
static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u);
static void c8_activate_secsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_deactivate_secsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_increment_counters_secsc8_DemoWave_K
  (SFc8_DemoWave_KInstanceStruct *chartInstance);
static void c8_reset_counters_secsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance);
static void c8_insertQueueLowc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, real_T c8_bmls[1280], real_T c8_myBML[256], real_T c8_newBmls
  [1280]);
static void c8_walkInvadingTablec8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, real_T c8_bmlID, real_T *c8_p, real_T c8_poseBML[256]);
static void c8_insertQueuec8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, real_T c8_bmls[1280], real_T c8_myBML[256], real_T c8_newBmls
  [1280]);
static boolean_T c8_isequal(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_varargin_1[256], real_T c8_varargin_2[256]);
static const mxArray *c8_v_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int8_T c8_j_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_w_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_k_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_x_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static uint8_T c8_l_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_b_tp_stateInit, const char_T *c8_identifier);
static uint8_T c8_m_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_y_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_n_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_b_BMLM, const char_T *c8_identifier, creal_T c8_y[256]);
static void c8_o_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, creal_T c8_y[256]);
static void c8_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_p_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier);
static const mxArray *c8_q_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_updateDataWrittenToVector(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_vectorIndex);
static void c8_errorIfDataNotWrittenToFcn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_vectorIndex, uint32_T c8_dataNumber);
static real_T c8_get_BML1(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b);
static void c8_set_BML1(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c);
static real_T *c8_access_BML1(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static real_T c8_get_P(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b);
static void c8_set_P(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T c8_b,
                     real_T c8_c);
static real_T *c8_access_P(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static real_T c8_get_STATE_BEFORE(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_STATE_BEFORE(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_BEFORE(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_STATE_OVER(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_STATE_OVER(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_OVER(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static real_T c8_get_STATE_READY(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_STATE_READY(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_READY(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_avert(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_avert(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c);
static real_T *c8_access_avert(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static real_T c8_get_bmlsL(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_bmlsL(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c);
static real_T *c8_access_bmlsL(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static real_T c8_get_bmlsM(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_bmlsM(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c);
static real_T *c8_access_bmlsM(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static real_T c8_get_fileID(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void c8_set_fileID(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c);
static real_T *c8_access_fileID(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static real_T c8_get_pr(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b);
static void c8_set_pr(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
                      c8_b, real_T c8_c);
static real_T *c8_access_pr(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b);
static void init_dsm_address_info(SFc8_DemoWave_KInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_update_debugger_state_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  uint32_T c8_prevAniVal;
  c8_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c8_is_active_c8_DemoWave_K == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_gazeSurprized) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_stateWalkBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_headNeuralGazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_browUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_checkUserCoord) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_wait2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_leanFW) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_walkFW) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_leanNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
  }

  _SFD_SET_ANIMATION(c8_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *
  chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  int32_T c8_i0;
  creal_T c8_b_u[256];
  const mxArray *c8_c_y = NULL;
  int32_T c8_i1;
  creal_T c8_c_u[256];
  const mxArray *c8_d_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  real_T c8_c_hoistedGlobal;
  real_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  real_T c8_d_hoistedGlobal;
  real_T c8_f_u;
  const mxArray *c8_g_y = NULL;
  real_T c8_e_hoistedGlobal;
  real_T c8_g_u;
  const mxArray *c8_h_y = NULL;
  real_T c8_f_hoistedGlobal;
  real_T c8_h_u;
  const mxArray *c8_i_y = NULL;
  int32_T c8_i2;
  real_T c8_i_u[256];
  const mxArray *c8_j_y = NULL;
  real_T c8_g_hoistedGlobal;
  real_T c8_j_u;
  const mxArray *c8_k_y = NULL;
  int32_T c8_i3;
  real_T c8_k_u[1280];
  const mxArray *c8_l_y = NULL;
  int32_T c8_i4;
  real_T c8_l_u[1280];
  const mxArray *c8_m_y = NULL;
  real_T c8_h_hoistedGlobal;
  real_T c8_m_u;
  const mxArray *c8_n_y = NULL;
  uint8_T c8_i_hoistedGlobal;
  uint8_T c8_n_u;
  const mxArray *c8_o_y = NULL;
  uint8_T c8_j_hoistedGlobal;
  uint8_T c8_o_u;
  const mxArray *c8_p_y = NULL;
  uint8_T c8_k_hoistedGlobal;
  uint8_T c8_p_u;
  const mxArray *c8_q_y = NULL;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(16, 1), false);
  c8_hoistedGlobal = *c8_gameState;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  for (c8_i0 = 0; c8_i0 < 256; c8_i0++) {
    c8_b_u[c8_i0] = chartInstance->c8_BMLL[c8_i0];
  }

  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_b_u, 0, 1U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  for (c8_i1 = 0; c8_i1 < 256; c8_i1++) {
    c8_c_u[c8_i1] = chartInstance->c8_BMLM[c8_i1];
  }

  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", c8_c_u, 0, 1U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_b_hoistedGlobal = chartInstance->c8_NEUTRAL;
  c8_d_u = c8_b_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_c_hoistedGlobal = chartInstance->c8_TOO_CLOSE;
  c8_e_u = c8_c_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  c8_d_hoistedGlobal = chartInstance->c8_TOO_FAR;
  c8_f_u = c8_d_hoistedGlobal;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 5, c8_g_y);
  c8_e_hoistedGlobal = chartInstance->c8_closeBuffer;
  c8_g_u = c8_e_hoistedGlobal;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 6, c8_h_y);
  c8_f_hoistedGlobal = chartInstance->c8_farBuffer;
  c8_h_u = c8_f_hoistedGlobal;
  c8_i_y = NULL;
  sf_mex_assign(&c8_i_y, sf_mex_create("y", &c8_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 7, c8_i_y);
  for (c8_i2 = 0; c8_i2 < 256; c8_i2++) {
    c8_i_u[c8_i2] = chartInstance->c8_n[c8_i2];
  }

  c8_j_y = NULL;
  sf_mex_assign(&c8_j_y, sf_mex_create("y", c8_i_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c8_y, 8, c8_j_y);
  c8_g_hoistedGlobal = chartInstance->c8_neutralBuffer;
  c8_j_u = c8_g_hoistedGlobal;
  c8_k_y = NULL;
  sf_mex_assign(&c8_k_y, sf_mex_create("y", &c8_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 9, c8_k_y);
  for (c8_i3 = 0; c8_i3 < 1280; c8_i3++) {
    c8_k_u[c8_i3] = chartInstance->c8_newBmlsL[c8_i3];
  }

  c8_l_y = NULL;
  sf_mex_assign(&c8_l_y, sf_mex_create("y", c8_k_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c8_y, 10, c8_l_y);
  for (c8_i4 = 0; c8_i4 < 1280; c8_i4++) {
    c8_l_u[c8_i4] = chartInstance->c8_newBmlsM[c8_i4];
  }

  c8_m_y = NULL;
  sf_mex_assign(&c8_m_y, sf_mex_create("y", c8_l_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c8_y, 11, c8_m_y);
  c8_h_hoistedGlobal = chartInstance->c8_position;
  c8_m_u = c8_h_hoistedGlobal;
  c8_n_y = NULL;
  sf_mex_assign(&c8_n_y, sf_mex_create("y", &c8_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 12, c8_n_y);
  c8_i_hoistedGlobal = chartInstance->c8_is_active_c8_DemoWave_K;
  c8_n_u = c8_i_hoistedGlobal;
  c8_o_y = NULL;
  sf_mex_assign(&c8_o_y, sf_mex_create("y", &c8_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 13, c8_o_y);
  c8_j_hoistedGlobal = chartInstance->c8_is_c8_DemoWave_K;
  c8_o_u = c8_j_hoistedGlobal;
  c8_p_y = NULL;
  sf_mex_assign(&c8_p_y, sf_mex_create("y", &c8_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 14, c8_p_y);
  c8_k_hoistedGlobal = chartInstance->c8_temporalCounter_i1;
  c8_p_u = c8_k_hoistedGlobal;
  c8_q_y = NULL;
  sf_mex_assign(&c8_q_y, sf_mex_create("y", &c8_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 15, c8_q_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  creal_T c8_dcv0[256];
  int32_T c8_i5;
  creal_T c8_dcv1[256];
  int32_T c8_i6;
  real_T c8_dv0[256];
  int32_T c8_i7;
  real_T c8_dv1[1280];
  int32_T c8_i8;
  real_T c8_dv2[1280];
  int32_T c8_i9;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_u = sf_mex_dup(c8_st);
  *c8_gameState = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 0)), "gameState");
  c8_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
                        "BMLL", c8_dcv0);
  for (c8_i5 = 0; c8_i5 < 256; c8_i5++) {
    chartInstance->c8_BMLL[c8_i5] = c8_dcv0[c8_i5];
  }

  c8_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 2)),
                        "BMLM", c8_dcv1);
  for (c8_i6 = 0; c8_i6 < 256; c8_i6++) {
    chartInstance->c8_BMLM[c8_i6] = c8_dcv1[c8_i6];
  }

  chartInstance->c8_NEUTRAL = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 3)), "NEUTRAL");
  chartInstance->c8_TOO_CLOSE = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 4)), "TOO_CLOSE");
  chartInstance->c8_TOO_FAR = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 5)), "TOO_FAR");
  chartInstance->c8_closeBuffer = c8_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 6)), "closeBuffer");
  chartInstance->c8_farBuffer = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 7)), "farBuffer");
  c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 8)), "n",
                        c8_dv0);
  for (c8_i7 = 0; c8_i7 < 256; c8_i7++) {
    chartInstance->c8_n[c8_i7] = c8_dv0[c8_i7];
  }

  chartInstance->c8_neutralBuffer = c8_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 9)), "neutralBuffer");
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 10)),
                      "newBmlsL", c8_dv1);
  for (c8_i8 = 0; c8_i8 < 1280; c8_i8++) {
    chartInstance->c8_newBmlsL[c8_i8] = c8_dv1[c8_i8];
  }

  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 11)),
                      "newBmlsM", c8_dv2);
  for (c8_i9 = 0; c8_i9 < 1280; c8_i9++) {
    chartInstance->c8_newBmlsM[c8_i9] = c8_dv2[c8_i9];
  }

  chartInstance->c8_position = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 12)), "position");
  chartInstance->c8_is_active_c8_DemoWave_K = c8_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 13)),
     "is_active_c8_DemoWave_K");
  chartInstance->c8_is_c8_DemoWave_K = c8_l_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 14)), "is_c8_DemoWave_K");
  chartInstance->c8_temporalCounter_i1 = c8_l_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 15)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c8_setSimStateSideEffectsInfo,
                c8_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 16)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c8_u);
  chartInstance->c8_doSetSimStateSideEffects = 1U;
  c8_update_debugger_state_c8_DemoWave_K(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void c8_set_sim_state_side_effects_c8_DemoWave_K
  (SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  if (chartInstance->c8_doSetSimStateSideEffects != 0) {
    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_browUp) {
      chartInstance->c8_tp_browUp = 1U;
    } else {
      chartInstance->c8_tp_browUp = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_checkUserCoord) {
      chartInstance->c8_tp_checkUserCoord = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_checkUserCoord = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_gazeSurprized) {
      chartInstance->c8_tp_gazeSurprized = 1U;
    } else {
      chartInstance->c8_tp_gazeSurprized = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_headNeuralGazeCamera) {
      chartInstance->c8_tp_headNeuralGazeCamera = 1U;
    } else {
      chartInstance->c8_tp_headNeuralGazeCamera = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_idle) {
      chartInstance->c8_tp_idle = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_idle = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_leanFW) {
      chartInstance->c8_tp_leanFW = 1U;
    } else {
      chartInstance->c8_tp_leanFW = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_leanNeutral) {
      chartInstance->c8_tp_leanNeutral = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_leanNeutral = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_stateInit) {
      chartInstance->c8_tp_stateInit = 1U;
    } else {
      chartInstance->c8_tp_stateInit = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_stateWalkBack) {
      chartInstance->c8_tp_stateWalkBack = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateWalkBack = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_wait) {
      chartInstance->c8_tp_wait = 1U;
    } else {
      chartInstance->c8_tp_wait = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_wait2) {
      chartInstance->c8_tp_wait2 = 1U;
    } else {
      chartInstance->c8_tp_wait2 = 0U;
    }

    if (chartInstance->c8_is_c8_DemoWave_K == c8_IN_walkFW) {
      chartInstance->c8_tp_walkFW = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_walkFW = 0U;
    }

    chartInstance->c8_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c8_setSimStateSideEffectsInfo);
}

static void sf_gateway_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  c8_set_sim_state_side_effects_c8_DemoWave_K(chartInstance);
}

static void c8_enter_atomic_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  chartInstance->c8_is_active_c8_DemoWave_K = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
}

static void c8_enter_internal_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  uint32_T c8_b_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr;
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr;
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_myarr256[256];
  int32_T c8_i10;
  int32_T c8_i11;
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  int32_T c8_i23;
  int32_T c8_i24;
  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i27;
  int32_T c8_i28;
  int32_T c8_i29;
  int32_T c8_i30;
  int32_T c8_i31;
  int32_T c8_i32;
  int32_T c8_i33;
  int32_T c8_i34;
  int32_T c8_i35;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_DemoWave_K = c8_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_n_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  *c8_gameState = c8_get_STATE_READY(chartInstance, 0);
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
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_b_debug_family_names,
    c8_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_arr, 1U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_mystr, 5U, c8_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  c8_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  c8_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 255.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i10 = 0; c8_i10 < 256; c8_i10++) {
    c8_tt[c8_i10] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  c8_tt[0] = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i11 = 0; c8_i11 < 256; c8_i11++) {
    c8_myarr256[c8_i11] = c8_tt[c8_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_i12 = 0; c8_i12 < 256; c8_i12++) {
    chartInstance->c8_n[c8_i12] = c8_myarr256[c8_i12];
  }

  c8_updateDataWrittenToVector(chartInstance, 12U);
  for (c8_i13 = 0; c8_i13 < 256; c8_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_n[c8_i13], 25U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 12U, 25U);
  for (c8_i14 = 0; c8_i14 < 256; c8_i14++) {
    c8_set_bmlsM(chartInstance, c8_i14, chartInstance->c8_n[c8_i14]);
  }

  for (c8_i15 = 0; c8_i15 < 256; c8_i15++) {
    c8_set_bmlsM(chartInstance, c8_i15 + 256, chartInstance->c8_n[c8_i15]);
  }

  for (c8_i16 = 0; c8_i16 < 256; c8_i16++) {
    c8_set_bmlsM(chartInstance, c8_i16 + 512, chartInstance->c8_n[c8_i16]);
  }

  for (c8_i17 = 0; c8_i17 < 256; c8_i17++) {
    c8_set_bmlsM(chartInstance, c8_i17 + 768, chartInstance->c8_n[c8_i17]);
  }

  for (c8_i18 = 0; c8_i18 < 256; c8_i18++) {
    c8_set_bmlsM(chartInstance, c8_i18 + 1024, chartInstance->c8_n[c8_i18]);
  }

  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 12U, 25U);
  for (c8_i19 = 0; c8_i19 < 256; c8_i19++) {
    chartInstance->c8_newBmlsM[c8_i19] = chartInstance->c8_n[c8_i19];
  }

  for (c8_i20 = 0; c8_i20 < 256; c8_i20++) {
    chartInstance->c8_newBmlsM[c8_i20 + 256] = chartInstance->c8_n[c8_i20];
  }

  for (c8_i21 = 0; c8_i21 < 256; c8_i21++) {
    chartInstance->c8_newBmlsM[c8_i21 + 512] = chartInstance->c8_n[c8_i21];
  }

  for (c8_i22 = 0; c8_i22 < 256; c8_i22++) {
    chartInstance->c8_newBmlsM[c8_i22 + 768] = chartInstance->c8_n[c8_i22];
  }

  for (c8_i23 = 0; c8_i23 < 256; c8_i23++) {
    chartInstance->c8_newBmlsM[c8_i23 + 1024] = chartInstance->c8_n[c8_i23];
  }

  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i24 = 0; c8_i24 < 1280; c8_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i24], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 12U, 25U);
  for (c8_i25 = 0; c8_i25 < 256; c8_i25++) {
    c8_set_bmlsL(chartInstance, c8_i25, chartInstance->c8_n[c8_i25]);
  }

  for (c8_i26 = 0; c8_i26 < 256; c8_i26++) {
    c8_set_bmlsL(chartInstance, c8_i26 + 256, chartInstance->c8_n[c8_i26]);
  }

  for (c8_i27 = 0; c8_i27 < 256; c8_i27++) {
    c8_set_bmlsL(chartInstance, c8_i27 + 512, chartInstance->c8_n[c8_i27]);
  }

  for (c8_i28 = 0; c8_i28 < 256; c8_i28++) {
    c8_set_bmlsL(chartInstance, c8_i28 + 768, chartInstance->c8_n[c8_i28]);
  }

  for (c8_i29 = 0; c8_i29 < 256; c8_i29++) {
    c8_set_bmlsL(chartInstance, c8_i29 + 1024, chartInstance->c8_n[c8_i29]);
  }

  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 12U, 25U);
  for (c8_i30 = 0; c8_i30 < 256; c8_i30++) {
    chartInstance->c8_newBmlsL[c8_i30] = chartInstance->c8_n[c8_i30];
  }

  for (c8_i31 = 0; c8_i31 < 256; c8_i31++) {
    chartInstance->c8_newBmlsL[c8_i31 + 256] = chartInstance->c8_n[c8_i31];
  }

  for (c8_i32 = 0; c8_i32 < 256; c8_i32++) {
    chartInstance->c8_newBmlsL[c8_i32 + 512] = chartInstance->c8_n[c8_i32];
  }

  for (c8_i33 = 0; c8_i33 < 256; c8_i33++) {
    chartInstance->c8_newBmlsL[c8_i33 + 768] = chartInstance->c8_n[c8_i33];
  }

  for (c8_i34 = 0; c8_i34 < 256; c8_i34++) {
    chartInstance->c8_newBmlsL[c8_i34 + 1024] = chartInstance->c8_n[c8_i34];
  }

  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 12U);
  c8_updateDataWrittenToVector(chartInstance, 11U);
  for (c8_i35 = 0; c8_i35 < 1280; c8_i35++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsL[c8_i35], 23U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance)
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
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_h_nargin = 0.0;
  real_T c8_h_nargout = 0.0;
  real_T c8_i_nargin = 0.0;
  real_T c8_i_nargout = 1.0;
  boolean_T c8_h_out;
  real_T c8_j_nargin = 0.0;
  real_T c8_j_nargout = 1.0;
  boolean_T c8_i_out;
  real_T *c8_gameState;
  boolean_T *c8_zChange;
  c8_zChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_isStable = true;
  switch (chartInstance->c8_is_c8_DemoWave_K) {
   case c8_IN_browUp:
    CV_CHART_EVAL(5, 0, 1);
    c8_browUp(chartInstance);
    break;

   case c8_IN_checkUserCoord:
    CV_CHART_EVAL(5, 0, 2);
    c8_checkUserCoord(chartInstance);
    break;

   case c8_IN_gazeSurprized:
    CV_CHART_EVAL(5, 0, 3);
    c8_gazeSurprized(chartInstance);
    break;

   case c8_IN_headNeuralGazeCamera:
    CV_CHART_EVAL(5, 0, 4);
    c8_headNeuralGazeCamera(chartInstance);
    break;

   case c8_IN_idle:
    CV_CHART_EVAL(5, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_ab_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_out = CV_EML_IF(2, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                       (chartInstance->c8_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_idle = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_checkUserCoord = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_leanNeutral:
    CV_CHART_EVAL(5, 0, 7);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_pb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_b_out = CV_EML_IF(16, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_leanNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_walkFW;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_walkFW = 1U;
      c8_enter_atomic_walkFW(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateInit:
    CV_CHART_EVAL(5, 0, 8);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_w_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    c8_c_out = CV_EML_IF(1, 0, 0, *c8_gameState == 10.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_x_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_c_sf_marshallOut, c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_g_sf_marshallOut,
        c8_f_sf_marshallIn);
      c8_d_out = CV_EML_IF(3, 0, 0, c8_get_avert(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateInit = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_DemoWave_K = c8_IN_headNeuralGazeCamera;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_headNeuralGazeCamera = 1U;
        c8_enter_atomic_headNeuralGazeCamera(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateInit = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_checkUserCoord = 1U;
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateWalkBack:
    CV_CHART_EVAL(5, 0, 9);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_bb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_e_out = CV_EML_IF(12, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateWalkBack = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_wait:
    CV_CHART_EVAL(5, 0, 10);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_x_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_f_out = CV_EML_IF(3, 0, 0, c8_get_avert(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_headNeuralGazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_headNeuralGazeCamera = 1U;
      c8_enter_atomic_headNeuralGazeCamera(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_checkUserCoord = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_wait2:
    CV_CHART_EVAL(5, 0, 11);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_hb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_g_out = CV_EML_IF(23, 0, 0, (real_T)*c8_zChange == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ib_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargin, 0U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargout, 1U,
        c8_c_sf_marshallOut, c8_c_sf_marshallIn);
      chartInstance->c8_position = 0.0;
      c8_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c8_tp_wait2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_checkUserCoord = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_kb_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargin, 0U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargout, 1U,
        c8_c_sf_marshallOut, c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_out, 2U, c8_g_sf_marshallOut,
        c8_f_sf_marshallIn);
      c8_h_out = CV_EML_IF(24, 0, 0, (real_T)*c8_zChange != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_wait2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_checkUserCoord = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                     chartInstance->c8_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_walkFW:
    CV_CHART_EVAL(5, 0, 12);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_y_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_i_out = CV_EML_IF(11, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_i_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_walkFW = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
}

static void c8_exit_internal_c8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c8_is_c8_DemoWave_K) {
   case c8_IN_browUp:
    CV_CHART_EVAL(5, 0, 1);
    chartInstance->c8_tp_browUp = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_checkUserCoord:
    CV_CHART_EVAL(5, 0, 2);
    chartInstance->c8_tp_checkUserCoord = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_gazeSurprized:
    CV_CHART_EVAL(5, 0, 3);
    chartInstance->c8_tp_gazeSurprized = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_headNeuralGazeCamera:
    CV_CHART_EVAL(5, 0, 4);
    chartInstance->c8_tp_headNeuralGazeCamera = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_idle:
    CV_CHART_EVAL(5, 0, 5);
    chartInstance->c8_tp_idle = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_leanFW:
    CV_CHART_EVAL(5, 0, 6);
    chartInstance->c8_tp_leanFW = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_leanNeutral:
    CV_CHART_EVAL(5, 0, 7);
    chartInstance->c8_tp_leanNeutral = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateInit:
    CV_CHART_EVAL(5, 0, 8);
    chartInstance->c8_tp_stateInit = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateWalkBack:
    CV_CHART_EVAL(5, 0, 9);
    chartInstance->c8_tp_stateWalkBack = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_wait:
    CV_CHART_EVAL(5, 0, 10);
    chartInstance->c8_tp_wait = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_wait2:
    CV_CHART_EVAL(5, 0, 11);
    chartInstance->c8_tp_wait2 = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_walkFW:
    CV_CHART_EVAL(5, 0, 12);
    chartInstance->c8_tp_walkFW = 0U;
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }
}

static void c8_initc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_doSetSimStateSideEffects = 0U;
  chartInstance->c8_setSimStateSideEffectsInfo = NULL;
  chartInstance->c8_tp_browUp = 0U;
  chartInstance->c8_tp_checkUserCoord = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
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
  chartInstance->c8_tp_wait2 = 0U;
  chartInstance->c8_tp_walkFW = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_is_active_c8_DemoWave_K = 0U;
  chartInstance->c8_is_c8_DemoWave_K = c8_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c8_enter_atomic_gazeSurprized(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i36;
  real_T c8_c_BMLM[256];
  int32_T c8_i37;
  int32_T c8_i38;
  real_T c8_dv3[1280];
  int32_T c8_i39;
  real_T c8_dv4[256];
  real_T c8_dv5[1280];
  int32_T c8_i40;
  int32_T c8_i41;
  int32_T c8_i42;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_o_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 5.0, &c8_P, c8_b_BMLM);
  for (c8_i36 = 0; c8_i36 < 256; c8_i36++) {
    c8_c_BMLM[c8_i36] = c8_b_BMLM[c8_i36];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i37 = 0; c8_i37 < 256; c8_i37++) {
    chartInstance->c8_BMLM[c8_i37].re = c8_c_BMLM[c8_i37];
    chartInstance->c8_BMLM[c8_i37].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 2U, 10U);
  chartInstance->c8_closeBuffer++;
  c8_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_closeBuffer, 10U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i38 = 0; c8_i38 < 1280; c8_i38++) {
    c8_dv3[c8_i38] = c8_get_bmlsM(chartInstance, c8_i38);
  }

  for (c8_i39 = 0; c8_i39 < 256; c8_i39++) {
    c8_dv4[c8_i39] = chartInstance->c8_BMLM[c8_i39].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv3, c8_dv4, c8_dv5);
  for (c8_i40 = 0; c8_i40 < 1280; c8_i40++) {
    chartInstance->c8_newBmlsM[c8_i40] = c8_dv5[c8_i40];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i41 = 0; c8_i41 < 1280; c8_i41++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i41], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i42 = 0; c8_i42 < 1280; c8_i42++) {
    c8_set_bmlsM(chartInstance, c8_i42, chartInstance->c8_newBmlsM[c8_i42]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_gazeSurprized(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_gazeSurprized = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_checkUserCoord = 1U;
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c8_sfEvent);
}

static void c8_enter_atomic_stateWalkBack(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i43;
  real_T c8_c_BMLM[256];
  int32_T c8_i44;
  int32_T c8_i45;
  real_T c8_dv6[1280];
  int32_T c8_i46;
  real_T c8_dv7[256];
  real_T c8_dv8[1280];
  int32_T c8_i47;
  int32_T c8_i48;
  int32_T c8_i49;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_p_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 2.0, &c8_P, c8_b_BMLM);
  for (c8_i43 = 0; c8_i43 < 256; c8_i43++) {
    c8_c_BMLM[c8_i43] = c8_b_BMLM[c8_i43];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i44 = 0; c8_i44 < 256; c8_i44++) {
    chartInstance->c8_BMLM[c8_i44].re = c8_c_BMLM[c8_i44];
    chartInstance->c8_BMLM[c8_i44].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  chartInstance->c8_closeBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_closeBuffer, 10U);
  chartInstance->c8_position = 2.0;
  c8_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i45 = 0; c8_i45 < 1280; c8_i45++) {
    c8_dv6[c8_i45] = c8_get_bmlsM(chartInstance, c8_i45);
  }

  for (c8_i46 = 0; c8_i46 < 256; c8_i46++) {
    c8_dv7[c8_i46] = chartInstance->c8_BMLM[c8_i46].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv6, c8_dv7, c8_dv8);
  for (c8_i47 = 0; c8_i47 < 1280; c8_i47++) {
    chartInstance->c8_newBmlsM[c8_i47] = c8_dv8[c8_i47];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i48 = 0; c8_i48 < 1280; c8_i48++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i48], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i49 = 0; c8_i49 < 1280; c8_i49++) {
    c8_set_bmlsM(chartInstance, c8_i49, chartInstance->c8_newBmlsM[c8_i49]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_enter_atomic_headNeuralGazeCamera(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i50;
  real_T c8_c_BMLM[256];
  int32_T c8_i51;
  int32_T c8_i52;
  real_T c8_dv9[1280];
  int32_T c8_i53;
  real_T c8_dv10[256];
  real_T c8_dv11[1280];
  int32_T c8_i54;
  int32_T c8_i55;
  int32_T c8_i56;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_q_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 4.0, &c8_P, c8_b_BMLM);
  for (c8_i50 = 0; c8_i50 < 256; c8_i50++) {
    c8_c_BMLM[c8_i50] = c8_b_BMLM[c8_i50];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i51 = 0; c8_i51 < 256; c8_i51++) {
    chartInstance->c8_BMLM[c8_i51].re = c8_c_BMLM[c8_i51];
    chartInstance->c8_BMLM[c8_i51].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i52 = 0; c8_i52 < 1280; c8_i52++) {
    c8_dv9[c8_i52] = c8_get_bmlsM(chartInstance, c8_i52);
  }

  for (c8_i53 = 0; c8_i53 < 256; c8_i53++) {
    c8_dv10[c8_i53] = chartInstance->c8_BMLM[c8_i53].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv9, c8_dv10, c8_dv11);
  for (c8_i54 = 0; c8_i54 < 1280; c8_i54++) {
    chartInstance->c8_newBmlsM[c8_i54] = c8_dv11[c8_i54];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i55 = 0; c8_i55 < 1280; c8_i55++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i55], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i56 = 0; c8_i56 < 1280; c8_i56++) {
    c8_set_bmlsM(chartInstance, c8_i56, chartInstance->c8_newBmlsM[c8_i56]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_headNeuralGazeCamera(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_headNeuralGazeCamera = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_checkUserCoord = 1U;
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
}

static void c8_enter_atomic_browUp(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i57;
  real_T c8_c_BMLM[256];
  int32_T c8_i58;
  int32_T c8_i59;
  real_T c8_dv12[1280];
  int32_T c8_i60;
  real_T c8_dv13[256];
  real_T c8_dv14[1280];
  int32_T c8_i61;
  int32_T c8_i62;
  int32_T c8_i63;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_r_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 8.0, &c8_P, c8_b_BMLM);
  for (c8_i57 = 0; c8_i57 < 256; c8_i57++) {
    c8_c_BMLM[c8_i57] = c8_b_BMLM[c8_i57];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i58 = 0; c8_i58 < 256; c8_i58++) {
    chartInstance->c8_BMLM[c8_i58].re = c8_c_BMLM[c8_i58];
    chartInstance->c8_BMLM[c8_i58].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 1U, 9U);
  chartInstance->c8_neutralBuffer++;
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_neutralBuffer, 9U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i59 = 0; c8_i59 < 1280; c8_i59++) {
    c8_dv12[c8_i59] = c8_get_bmlsM(chartInstance, c8_i59);
  }

  for (c8_i60 = 0; c8_i60 < 256; c8_i60++) {
    c8_dv13[c8_i60] = chartInstance->c8_BMLM[c8_i60].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv12, c8_dv13, c8_dv14);
  for (c8_i61 = 0; c8_i61 < 1280; c8_i61++) {
    chartInstance->c8_newBmlsM[c8_i61] = c8_dv14[c8_i61];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i62 = 0; c8_i62 < 1280; c8_i62++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i62], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i63 = 0; c8_i63 < 1280; c8_i63++) {
    c8_set_bmlsM(chartInstance, c8_i63, chartInstance->c8_newBmlsM[c8_i63]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_browUp(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_browUp = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_DemoWave_K = c8_IN_checkUserCoord;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_checkUserCoord = 1U;
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
}

static void c8_checkUserCoord(SFc8_DemoWave_KInstanceStruct *chartInstance)
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
  real_T c8_j_nargin = 0.0;
  real_T c8_j_nargout = 1.0;
  boolean_T c8_j_out;
  real_T *c8_distance;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  c8_distance = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_mb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_g_sf_marshallOut,
    c8_f_sf_marshallIn);
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
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_ob_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 14U);
    c8_b_out = CV_EML_IF(5, 0, 0, chartInstance->c8_farBuffer >= 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_checkUserCoord = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_leanNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_leanNeutral = 1U;
      c8_enter_atomic_leanNeutral(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_nb_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
        c8_c_sf_marshallOut, c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_g_sf_marshallOut,
        c8_f_sf_marshallIn);
      c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 14U);
      c8_c_out = CV_EML_IF(6, 0, 0, chartInstance->c8_farBuffer < 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_checkUserCoord = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_DemoWave_K = c8_IN_leanFW;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
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
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_fb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
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
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_gb_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_c_sf_marshallOut, c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_out, 2U, c8_g_sf_marshallOut,
        c8_f_sf_marshallIn);
      c8_errorIfDataNotWrittenToFcn(chartInstance, 1U, 9U);
      c8_e_out = CV_EML_IF(20, 0, 0, chartInstance->c8_neutralBuffer < 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_checkUserCoord = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_DemoWave_K = c8_IN_browUp;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_browUp = 1U;
        c8_enter_atomic_browUp(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_jb_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
          c8_c_sf_marshallOut, c8_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
          c8_c_sf_marshallOut, c8_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_out, 2U, c8_g_sf_marshallOut,
          c8_f_sf_marshallIn);
        c8_errorIfDataNotWrittenToFcn(chartInstance, 1U, 9U);
        c8_f_out = CV_EML_IF(21, 0, 0, chartInstance->c8_neutralBuffer >= 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c8_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_checkUserCoord = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_DemoWave_K = c8_IN_idle;
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
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_cb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
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
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargin, 0U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargout, 1U,
        c8_c_sf_marshallOut, c8_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_out, 2U, c8_g_sf_marshallOut,
        c8_f_sf_marshallIn);
      c8_errorIfDataNotWrittenToFcn(chartInstance, 2U, 10U);
      c8_h_out = CV_EML_IF(19, 0, 0, chartInstance->c8_closeBuffer >= 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_checkUserCoord = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_DemoWave_K = c8_IN_stateWalkBack;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_stateWalkBack = 1U;
        c8_enter_atomic_stateWalkBack(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_db_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargin, 0U,
          c8_c_sf_marshallOut, c8_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargout, 1U,
          c8_c_sf_marshallOut, c8_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_out, 2U, c8_g_sf_marshallOut,
          c8_f_sf_marshallIn);
        c8_errorIfDataNotWrittenToFcn(chartInstance, 2U, 10U);
        c8_i_out = CV_EML_IF(18, 0, 0, chartInstance->c8_closeBuffer < 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c8_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_checkUserCoord = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_DemoWave_K = c8_IN_gazeSurprized;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_gazeSurprized = 1U;
          c8_enter_atomic_gazeSurprized(chartInstance);
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_lb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargin, 0U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargout, 1U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_out, 2U, c8_g_sf_marshallOut,
      c8_f_sf_marshallIn);
    c8_j_out = CV_EML_IF(22, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 10));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_j_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_checkUserCoord = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_DemoWave_K = c8_IN_wait2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_wait2 = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c8_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c8_sfEvent);
}

static void c8_enter_atomic_idle(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i64;
  real_T c8_c_BMLM[256];
  int32_T c8_i65;
  int32_T c8_i66;
  real_T c8_dv15[1280];
  int32_T c8_i67;
  real_T c8_dv16[256];
  real_T c8_dv17[1280];
  int32_T c8_i68;
  int32_T c8_i69;
  int32_T c8_i70;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_s_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 1.0, &c8_P, c8_b_BMLM);
  for (c8_i64 = 0; c8_i64 < 256; c8_i64++) {
    c8_c_BMLM[c8_i64] = c8_b_BMLM[c8_i64];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i65 = 0; c8_i65 < 256; c8_i65++) {
    chartInstance->c8_BMLM[c8_i65].re = c8_c_BMLM[c8_i65];
    chartInstance->c8_BMLM[c8_i65].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  chartInstance->c8_neutralBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_neutralBuffer, 9U);
  chartInstance->c8_position = 1.0;
  c8_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i66 = 0; c8_i66 < 1280; c8_i66++) {
    c8_dv15[c8_i66] = c8_get_bmlsM(chartInstance, c8_i66);
  }

  for (c8_i67 = 0; c8_i67 < 256; c8_i67++) {
    c8_dv16[c8_i67] = chartInstance->c8_BMLM[c8_i67].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv15, c8_dv16, c8_dv17);
  for (c8_i68 = 0; c8_i68 < 1280; c8_i68++) {
    chartInstance->c8_newBmlsM[c8_i68] = c8_dv17[c8_i68];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i69 = 0; c8_i69 < 1280; c8_i69++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i69], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i70 = 0; c8_i70 < 1280; c8_i70++) {
    c8_set_bmlsM(chartInstance, c8_i70, chartInstance->c8_newBmlsM[c8_i70]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_enter_atomic_leanFW(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i71;
  real_T c8_c_BMLM[256];
  int32_T c8_i72;
  int32_T c8_i73;
  real_T c8_dv18[1280];
  int32_T c8_i74;
  real_T c8_dv19[256];
  real_T c8_dv20[1280];
  int32_T c8_i75;
  int32_T c8_i76;
  int32_T c8_i77;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_t_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 6.0, &c8_P, c8_b_BMLM);
  for (c8_i71 = 0; c8_i71 < 256; c8_i71++) {
    c8_c_BMLM[c8_i71] = c8_b_BMLM[c8_i71];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i72 = 0; c8_i72 < 256; c8_i72++) {
    chartInstance->c8_BMLM[c8_i72].re = c8_c_BMLM[c8_i72];
    chartInstance->c8_BMLM[c8_i72].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 14U);
  chartInstance->c8_farBuffer++;
  c8_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_farBuffer, 14U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i73 = 0; c8_i73 < 1280; c8_i73++) {
    c8_dv18[c8_i73] = c8_get_bmlsM(chartInstance, c8_i73);
  }

  for (c8_i74 = 0; c8_i74 < 256; c8_i74++) {
    c8_dv19[c8_i74] = chartInstance->c8_BMLM[c8_i74].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv18, c8_dv19, c8_dv20);
  for (c8_i75 = 0; c8_i75 < 1280; c8_i75++) {
    chartInstance->c8_newBmlsM[c8_i75] = c8_dv20[c8_i75];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i76 = 0; c8_i76 < 1280; c8_i76++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i76], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i77 = 0; c8_i77 < 1280; c8_i77++) {
    c8_set_bmlsM(chartInstance, c8_i77, chartInstance->c8_newBmlsM[c8_i77]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_enter_atomic_walkFW(SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i78;
  real_T c8_c_BMLM[256];
  int32_T c8_i79;
  int32_T c8_i80;
  real_T c8_dv21[1280];
  int32_T c8_i81;
  real_T c8_dv22[256];
  real_T c8_dv23[1280];
  int32_T c8_i82;
  int32_T c8_i83;
  int32_T c8_i84;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_u_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 3.0, &c8_P, c8_b_BMLM);
  for (c8_i78 = 0; c8_i78 < 256; c8_i78++) {
    c8_c_BMLM[c8_i78] = c8_b_BMLM[c8_i78];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i79 = 0; c8_i79 < 256; c8_i79++) {
    chartInstance->c8_BMLM[c8_i79].re = c8_c_BMLM[c8_i79];
    chartInstance->c8_BMLM[c8_i79].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  chartInstance->c8_farBuffer = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_farBuffer, 14U);
  chartInstance->c8_position = 3.0;
  c8_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_position, 16U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i80 = 0; c8_i80 < 1280; c8_i80++) {
    c8_dv21[c8_i80] = c8_get_bmlsM(chartInstance, c8_i80);
  }

  for (c8_i81 = 0; c8_i81 < 256; c8_i81++) {
    c8_dv22[c8_i81] = chartInstance->c8_BMLM[c8_i81].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv21, c8_dv22, c8_dv23);
  for (c8_i82 = 0; c8_i82 < 1280; c8_i82++) {
    chartInstance->c8_newBmlsM[c8_i82] = c8_dv23[c8_i82];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i83 = 0; c8_i83 < 1280; c8_i83++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i83], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i84 = 0; c8_i84 < 1280; c8_i84++) {
    c8_set_bmlsM(chartInstance, c8_i84, chartInstance->c8_newBmlsM[c8_i84]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_enter_atomic_leanNeutral(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_b_BMLM[256];
  real_T c8_P;
  int32_T c8_i85;
  real_T c8_c_BMLM[256];
  int32_T c8_i86;
  int32_T c8_i87;
  real_T c8_dv24[1280];
  int32_T c8_i88;
  real_T c8_dv25[256];
  real_T c8_dv26[1280];
  int32_T c8_i89;
  int32_T c8_i90;
  int32_T c8_i91;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_v_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, 7.0, &c8_P, c8_b_BMLM);
  for (c8_i85 = 0; c8_i85 < 256; c8_i85++) {
    c8_c_BMLM[c8_i85] = c8_b_BMLM[c8_i85];
  }

  c8_set_P(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c8_i86 = 0; c8_i86 < 256; c8_i86++) {
    chartInstance->c8_BMLM[c8_i86].re = c8_c_BMLM[c8_i86];
    chartInstance->c8_BMLM[c8_i86].im = 0.0;
  }

  c8_updateDataWrittenToVector(chartInstance, 9U);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 9U, 20U);
  for (c8_i87 = 0; c8_i87 < 1280; c8_i87++) {
    c8_dv24[c8_i87] = c8_get_bmlsM(chartInstance, c8_i87);
  }

  for (c8_i88 = 0; c8_i88 < 256; c8_i88++) {
    c8_dv25[c8_i88] = chartInstance->c8_BMLM[c8_i88].re;
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_dv24, c8_dv25, c8_dv26);
  for (c8_i89 = 0; c8_i89 < 1280; c8_i89++) {
    chartInstance->c8_newBmlsM[c8_i89] = c8_dv26[c8_i89];
  }

  c8_updateDataWrittenToVector(chartInstance, 8U);
  for (c8_i90 = 0; c8_i90 < 1280; c8_i90++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_newBmlsM[c8_i90], 18U);
  }

  c8_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U);
  for (c8_i91 = 0; c8_i91 < 1280; c8_i91++) {
    c8_set_bmlsM(chartInstance, c8_i91, chartInstance->c8_newBmlsM[c8_i91]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_decArr2Str(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256], char_T c8_mystr_data[], int32_T c8_mystr_sizes[2])
{
  uint32_T c8_debug_family_var_map[4];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i92;
  boolean_T c8_x[256];
  int32_T c8_k;
  int32_T c8_i;
  int32_T c8_b_i;
  int32_T c8_a;
  int32_T c8_b_a;
  const mxArray *c8_y = NULL;
  int32_T c8_tmp_sizes;
  int32_T c8_loop_ub;
  int32_T c8_i93;
  int32_T c8_tmp_data[256];
  int32_T c8_y_sizes;
  int32_T c8_j;
  int32_T c8_c_i;
  int32_T c8_d_i;
  int32_T c8_y_data[256];
  int32_T c8_c_a;
  int32_T c8_d_a;
  int32_T c8_s_sizes[2];
  int32_T c8_b_loop_ub;
  int32_T c8_i94;
  real_T c8_s_data[256];
  int32_T c8_i95;
  real_T c8_dv27[2];
  int32_T c8_b_tmp_sizes[2];
  int32_T c8_iv0[2];
  int32_T c8_i96;
  int32_T c8_i97;
  int32_T c8_c_loop_ub;
  int32_T c8_i98;
  char_T c8_b_tmp_data[256];
  int32_T c8_i99;
  int32_T c8_c_tmp_sizes;
  int32_T c8_d_loop_ub;
  int32_T c8_i100;
  char_T c8_c_tmp_data[256];
  int32_T c8_i101;
  int32_T c8_mystr[2];
  int32_T c8_e_loop_ub;
  int32_T c8_i102;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c8_c_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 2U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c8_mystr_data, (const int32_T *)
    c8_mystr_sizes, NULL, 0, 3, (void *)c8_f_sf_marshallOut, (void *)
    c8_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c8_sfEvent, 3);
  for (c8_i92 = 0; c8_i92 < 256; c8_i92++) {
    c8_x[c8_i92] = (c8_myarr256[c8_i92] != 0.0);
  }

  c8_k = 0;
  for (c8_i = 1; c8_i < 257; c8_i++) {
    c8_b_i = c8_i - 1;
    if (c8_x[c8_b_i]) {
      c8_a = c8_k;
      c8_b_a = c8_a + 1;
      c8_k = c8_b_a;
    }
  }

  if (c8_k <= 256) {
  } else {
    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c8_y);
  }

  c8_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c8_k);
  c8_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c8_k) - 1;
  for (c8_i93 = 0; c8_i93 <= c8_loop_ub; c8_i93++) {
    c8_tmp_data[c8_i93] = 0;
  }

  c8_y_sizes = c8_tmp_sizes;
  c8_j = 1;
  for (c8_c_i = 1; c8_c_i < 257; c8_c_i++) {
    c8_d_i = c8_c_i;
    if (c8_x[c8_d_i - 1]) {
      c8_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c8_j, 1, c8_y_sizes, 1, 0) - 1] =
        c8_d_i;
      c8_c_a = c8_j;
      c8_d_a = c8_c_a + 1;
      c8_j = c8_d_a;
    }
  }

  c8_s_sizes[0] = 1;
  c8_s_sizes[1] = c8_y_sizes;
  c8_b_loop_ub = c8_y_sizes - 1;
  for (c8_i94 = 0; c8_i94 <= c8_b_loop_ub; c8_i94++) {
    c8_s_data[c8_s_sizes[0] * c8_i94] = c8_myarr256[c8_y_data[c8_i94] - 1];
  }

  for (c8_i95 = 0; c8_i95 < 2; c8_i95++) {
    c8_dv27[c8_i95] = (real_T)c8_s_sizes[c8_i95];
  }

  c8_b_tmp_sizes[0] = 1;
  c8_iv0[0] = 1;
  c8_iv0[1] = (int32_T)c8_dv27[1];
  c8_b_tmp_sizes[1] = c8_iv0[1];
  c8_i96 = c8_b_tmp_sizes[0];
  c8_i97 = c8_b_tmp_sizes[1];
  c8_c_loop_ub = (int32_T)c8_dv27[1] - 1;
  for (c8_i98 = 0; c8_i98 <= c8_c_loop_ub; c8_i98++) {
    c8_b_tmp_data[c8_i98] = ' ';
  }

  for (c8_i99 = 0; c8_i99 < 2; c8_i99++) {
    c8_mystr_sizes[c8_i99] = c8_b_tmp_sizes[c8_i99];
  }

  c8_c_tmp_sizes = c8_s_sizes[1];
  c8_d_loop_ub = c8_s_sizes[1] - 1;
  for (c8_i100 = 0; c8_i100 <= c8_d_loop_ub; c8_i100++) {
    c8_c_tmp_data[c8_i100] = (char_T)(int8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("char",
      (int32_T)_SFD_INTEGER_CHECK("", c8_s_data[c8_i100]), 0, 255, 0, 2);
  }

  _SFD_SIZE_EQ_CHECK_1D(c8_mystr_sizes[1], c8_c_tmp_sizes);
  for (c8_i101 = 0; c8_i101 < 2; c8_i101++) {
    c8_mystr[c8_i101] = c8_mystr_sizes[c8_i101];
  }

  c8_mystr_sizes[0] = 1;
  c8_mystr_sizes[1] = c8_mystr[1];
  c8_e_loop_ub = c8_mystr[1] - 1;
  for (c8_i102 = 0; c8_i102 <= c8_e_loop_ub; c8_i102++) {
    c8_mystr_data[c8_mystr_sizes[0] * c8_i102] = c8_c_tmp_data[c8_mystr[0] *
      c8_i102];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c8_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256])
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
  int32_T c8_i103;
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

  int32_T c8_i104;
  static real_T c8_dv28[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i105;
  int32_T c8_i106;
  int32_T c8_i107;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_e_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i103 = 0; c8_i103 < 137; c8_i103++) {
    c8_mystr[c8_i103] = c8_cv0[c8_i103];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i104 = 0; c8_i104 < 137; c8_i104++) {
    c8_arr[c8_i104] = c8_dv28[c8_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i105 = 0; c8_i105 < 256; c8_i105++) {
    c8_tt[c8_i105] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i106 = 0; c8_i106 < 137; c8_i106++) {
    c8_tt[c8_i106] = c8_arr[c8_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i107 = 0; c8_i107 < 256; c8_i107++) {
    c8_myarr256[c8_i107] = c8_tt[c8_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_b_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256])
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
  int32_T c8_i108;
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

  int32_T c8_i109;
  static real_T c8_dv29[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i110;
  int32_T c8_i111;
  int32_T c8_i112;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_f_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i108 = 0; c8_i108 < 140; c8_i108++) {
    c8_mystr[c8_i108] = c8_cv1[c8_i108];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i109 = 0; c8_i109 < 140; c8_i109++) {
    c8_arr[c8_i109] = c8_dv29[c8_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i110 = 0; c8_i110 < 256; c8_i110++) {
    c8_tt[c8_i110] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i111 = 0; c8_i111 < 140; c8_i111++) {
    c8_tt[c8_i111] = c8_arr[c8_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i112 = 0; c8_i112 < 256; c8_i112++) {
    c8_myarr256[c8_i112] = c8_tt[c8_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256])
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
  int32_T c8_i113;
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

  int32_T c8_i114;
  static real_T c8_dv30[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i115;
  int32_T c8_i116;
  int32_T c8_i117;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_g_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i113 = 0; c8_i113 < 139; c8_i113++) {
    c8_mystr[c8_i113] = c8_cv2[c8_i113];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i114 = 0; c8_i114 < 139; c8_i114++) {
    c8_arr[c8_i114] = c8_dv30[c8_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 117.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i115 = 0; c8_i115 < 256; c8_i115++) {
    c8_tt[c8_i115] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i116 = 0; c8_i116 < 139; c8_i116++) {
    c8_tt[c8_i116] = c8_arr[c8_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i117 = 0; c8_i117 < 256; c8_i117++) {
    c8_myarr256[c8_i117] = c8_tt[c8_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_d_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256])
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
  int32_T c8_i118;
  static char_T c8_cv3[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i119;
  static real_T c8_dv31[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i120;
  int32_T c8_i121;
  int32_T c8_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_h_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i118 = 0; c8_i118 < 115; c8_i118++) {
    c8_mystr[c8_i118] = c8_cv3[c8_i118];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i119 = 0; c8_i119 < 115; c8_i119++) {
    c8_arr[c8_i119] = c8_dv31[c8_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 115.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 141.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i120 = 0; c8_i120 < 256; c8_i120++) {
    c8_tt[c8_i120] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i121 = 0; c8_i121 < 115; c8_i121++) {
    c8_tt[c8_i121] = c8_arr[c8_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i122 = 0; c8_i122 < 256; c8_i122++) {
    c8_myarr256[c8_i122] = c8_tt[c8_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_e_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256])
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
  int32_T c8_i123;
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

  int32_T c8_i124;
  static real_T c8_dv32[202] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i125;
  int32_T c8_i126;
  int32_T c8_i127;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_i_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i123 = 0; c8_i123 < 202; c8_i123++) {
    c8_mystr[c8_i123] = c8_cv4[c8_i123];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i124 = 0; c8_i124 < 202; c8_i124++) {
    c8_arr[c8_i124] = c8_dv32[c8_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 202.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 54.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i125 = 0; c8_i125 < 256; c8_i125++) {
    c8_tt[c8_i125] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i126 = 0; c8_i126 < 202; c8_i126++) {
    c8_tt[c8_i126] = c8_arr[c8_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i127 = 0; c8_i127 < 256; c8_i127++) {
    c8_myarr256[c8_i127] = c8_tt[c8_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_f_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256])
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
  int32_T c8_i128;
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

  int32_T c8_i129;
  static real_T c8_dv33[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i130;
  int32_T c8_i131;
  int32_T c8_i132;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_j_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i128 = 0; c8_i128 < 140; c8_i128++) {
    c8_mystr[c8_i128] = c8_cv5[c8_i128];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i129 = 0; c8_i129 < 140; c8_i129++) {
    c8_arr[c8_i129] = c8_dv33[c8_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i130 = 0; c8_i130 < 256; c8_i130++) {
    c8_tt[c8_i130] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i131 = 0; c8_i131 < 140; c8_i131++) {
    c8_tt[c8_i131] = c8_arr[c8_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i132 = 0; c8_i132 < 256; c8_i132++) {
    c8_myarr256[c8_i132] = c8_tt[c8_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_g_encStr2Arr(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_myarr256[256])
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
  int32_T c8_i133;
  static char_T c8_cv6[85] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i134;
  static real_T c8_dv34[85] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i135;
  int32_T c8_i136;
  int32_T c8_i137;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_k_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i133 = 0; c8_i133 < 85; c8_i133++) {
    c8_mystr[c8_i133] = c8_cv6[c8_i133];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i134 = 0; c8_i134 < 85; c8_i134++) {
    c8_arr[c8_i134] = c8_dv34[c8_i134];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 85.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = 171.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i135 = 0; c8_i135 < 256; c8_i135++) {
    c8_tt[c8_i135] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i136 = 0; c8_i136 < 85; c8_i136++) {
    c8_tt[c8_i136] = c8_arr[c8_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i137 = 0; c8_i137 < 256; c8_i137++) {
    c8_myarr256[c8_i137] = c8_tt[c8_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, c8_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\18-9-2015-v2-Matlab-prior-M+M\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, c8_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\18-9-2015-v2-Matlab-prior-M+M\\decArr2Str.m"));
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i138;
  int32_T c8_i139;
  int32_T c8_i140;
  real_T c8_b_inData[1280];
  int32_T c8_i141;
  int32_T c8_i142;
  int32_T c8_i143;
  real_T c8_u[1280];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i138 = 0;
  for (c8_i139 = 0; c8_i139 < 5; c8_i139++) {
    for (c8_i140 = 0; c8_i140 < 256; c8_i140++) {
      c8_b_inData[c8_i140 + c8_i138] = (*(real_T (*)[1280])c8_inData)[c8_i140 +
        c8_i138];
    }

    c8_i138 += 256;
  }

  c8_i141 = 0;
  for (c8_i142 = 0; c8_i142 < 5; c8_i142++) {
    for (c8_i143 = 0; c8_i143 < 256; c8_i143++) {
      c8_u[c8_i143 + c8_i141] = c8_b_inData[c8_i143 + c8_i141];
    }

    c8_i141 += 256;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 256, 5), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_newBmls, const char_T *c8_identifier, real_T c8_y[1280])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_newBmls), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_newBmls);
}

static void c8_b_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[1280])
{
  real_T c8_dv35[1280];
  int32_T c8_i144;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv35, 1, 0, 0U, 1, 0U, 2, 256,
                5);
  for (c8_i144 = 0; c8_i144 < 1280; c8_i144++) {
    c8_y[c8_i144] = c8_dv35[c8_i144];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_newBmls;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[1280];
  int32_T c8_i145;
  int32_T c8_i146;
  int32_T c8_i147;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_newBmls = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_newBmls), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_newBmls);
  c8_i145 = 0;
  for (c8_i146 = 0; c8_i146 < 5; c8_i146++) {
    for (c8_i147 = 0; c8_i147 < 256; c8_i147++) {
      (*(real_T (*)[1280])c8_outData)[c8_i147 + c8_i145] = c8_y[c8_i147 +
        c8_i145];
    }

    c8_i145 += 256;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i148;
  real_T c8_b_inData[256];
  int32_T c8_i149;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i148 = 0; c8_i148 < 256; c8_i148++) {
    c8_b_inData[c8_i148] = (*(real_T (*)[256])c8_inData)[c8_i148];
  }

  for (c8_i149 = 0; c8_i149 < 256; c8_i149++) {
    c8_u[c8_i149] = c8_b_inData[c8_i149];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_c_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[256])
{
  real_T c8_dv36[256];
  int32_T c8_i150;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv36, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c8_i150 = 0; c8_i150 < 256; c8_i150++) {
    c8_y[c8_i150] = c8_dv36[c8_i150];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_myBML;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[256];
  int32_T c8_i151;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_myBML = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_myBML), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_myBML);
  for (c8_i151 = 0; c8_i151 < 256; c8_i151++) {
    (*(real_T (*)[256])c8_outData)[c8_i151] = c8_y[c8_i151];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_d_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_nargout, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  return c8_y;
}

static real_T c8_e_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i152;
  real_T c8_b_inData[256];
  int32_T c8_i153;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i152 = 0; c8_i152 < 256; c8_i152++) {
    c8_b_inData[c8_i152] = (*(real_T (*)[256])c8_inData)[c8_i152];
  }

  for (c8_i153 = 0; c8_i153 < 256; c8_i153++) {
    c8_u[c8_i153] = c8_b_inData[c8_i153];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_f_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_myarr256, const char_T *c8_identifier, real_T c8_y[256])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_myarr256), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_myarr256);
}

static void c8_g_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[256])
{
  real_T c8_dv37[256];
  int32_T c8_i154;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv37, 1, 0, 0U, 1, 0U, 1, 256);
  for (c8_i154 = 0; c8_i154 < 256; c8_i154++) {
    c8_y[c8_i154] = c8_dv37[c8_i154];
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
  int32_T c8_i155;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_myarr256 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_myarr256), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_myarr256);
  for (c8_i155 = 0; c8_i155 < 256; c8_i155++) {
    (*(real_T (*)[256])c8_outData)[c8_i155] = c8_y[c8_i155];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  char_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(char_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, char_T
  c8_inData_data[], int32_T c8_inData_sizes[2])
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_b_inData_sizes[2];
  int32_T c8_loop_ub;
  int32_T c8_i156;
  char_T c8_b_inData_data[256];
  int32_T c8_u_sizes[2];
  int32_T c8_b_loop_ub;
  int32_T c8_i157;
  char_T c8_u_data[256];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_b_inData_sizes[0] = 1;
  c8_b_inData_sizes[1] = c8_inData_sizes[1];
  c8_loop_ub = c8_inData_sizes[1] - 1;
  for (c8_i156 = 0; c8_i156 <= c8_loop_ub; c8_i156++) {
    c8_b_inData_data[c8_b_inData_sizes[0] * c8_i156] =
      c8_inData_data[c8_inData_sizes[0] * c8_i156];
  }

  c8_u_sizes[0] = 1;
  c8_u_sizes[1] = c8_b_inData_sizes[1];
  c8_b_loop_ub = c8_b_inData_sizes[1] - 1;
  for (c8_i157 = 0; c8_i157 <= c8_b_loop_ub; c8_i157++) {
    c8_u_data[c8_u_sizes[0] * c8_i157] = c8_b_inData_data[c8_b_inData_sizes[0] *
      c8_i157];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u_data, 10, 0U, 1U, 0U, 2,
    c8_u_sizes[0], c8_u_sizes[1]), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_h_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, char_T c8_y_data[],
  int32_T c8_y_sizes[2])
{
  int32_T c8_i158;
  uint32_T c8_uv0[2];
  int32_T c8_i159;
  static boolean_T c8_bv0[2] = { false, true };

  boolean_T c8_bv1[2];
  int32_T c8_tmp_sizes[2];
  char_T c8_tmp_data[256];
  int32_T c8_y;
  int32_T c8_b_y;
  int32_T c8_loop_ub;
  int32_T c8_i160;
  (void)chartInstance;
  for (c8_i158 = 0; c8_i158 < 2; c8_i158++) {
    c8_uv0[c8_i158] = 1U + 255U * (uint32_T)c8_i158;
  }

  for (c8_i159 = 0; c8_i159 < 2; c8_i159++) {
    c8_bv1[c8_i159] = c8_bv0[c8_i159];
  }

  sf_mex_import_vs(c8_parentId, sf_mex_dup(c8_u), c8_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c8_bv1, c8_uv0, c8_tmp_sizes);
  c8_y_sizes[0] = 1;
  c8_y_sizes[1] = c8_tmp_sizes[1];
  c8_y = c8_y_sizes[0];
  c8_b_y = c8_y_sizes[1];
  c8_loop_ub = c8_tmp_sizes[0] * c8_tmp_sizes[1] - 1;
  for (c8_i160 = 0; c8_i160 <= c8_loop_ub; c8_i160++) {
    c8_y_data[c8_i160] = c8_tmp_data[c8_i160];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, char_T c8_outData_data[], int32_T
  c8_outData_sizes[2])
{
  const mxArray *c8_mystr;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y_sizes[2];
  char_T c8_y_data[256];
  int32_T c8_loop_ub;
  int32_T c8_i161;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mystr = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_mystr), &c8_thisId,
                        c8_y_data, c8_y_sizes);
  sf_mex_destroy(&c8_mystr);
  c8_outData_sizes[0] = 1;
  c8_outData_sizes[1] = c8_y_sizes[1];
  c8_loop_ub = c8_y_sizes[1] - 1;
  for (c8_i161 = 0; c8_i161 <= c8_loop_ub; c8_i161++) {
    c8_outData_data[c8_outData_sizes[0] * c8_i161] = c8_y_data[c8_y_sizes[0] *
      c8_i161];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  boolean_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(boolean_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static boolean_T c8_i_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  boolean_T c8_y;
  boolean_T c8_b0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b0, 1, 11, 0U, 0, 0U, 0);
  c8_y = c8_b0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_aVarTruthTableCondition_8;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  boolean_T c8_y;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_aVarTruthTableCondition_8 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_aVarTruthTableCondition_8), &c8_thisId);
  sf_mex_destroy(&c8_aVarTruthTableCondition_8);
  *(boolean_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i162;
  char_T c8_b_inData[137];
  int32_T c8_i163;
  char_T c8_u[137];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i162 = 0; c8_i162 < 137; c8_i162++) {
    c8_b_inData[c8_i162] = (*(char_T (*)[137])c8_inData)[c8_i162];
  }

  for (c8_i163 = 0; c8_i163 < 137; c8_i163++) {
    c8_u[c8_i163] = c8_b_inData[c8_i163];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_i_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i164;
  real_T c8_b_inData[137];
  int32_T c8_i165;
  real_T c8_u[137];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i164 = 0; c8_i164 < 137; c8_i164++) {
    c8_b_inData[c8_i164] = (*(real_T (*)[137])c8_inData)[c8_i164];
  }

  for (c8_i165 = 0; c8_i165 < 137; c8_i165++) {
    c8_u[c8_i165] = c8_b_inData[c8_i165];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_j_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i166;
  char_T c8_b_inData[140];
  int32_T c8_i167;
  char_T c8_u[140];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i166 = 0; c8_i166 < 140; c8_i166++) {
    c8_b_inData[c8_i166] = (*(char_T (*)[140])c8_inData)[c8_i166];
  }

  for (c8_i167 = 0; c8_i167 < 140; c8_i167++) {
    c8_u[c8_i167] = c8_b_inData[c8_i167];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_k_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i168;
  real_T c8_b_inData[140];
  int32_T c8_i169;
  real_T c8_u[140];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i168 = 0; c8_i168 < 140; c8_i168++) {
    c8_b_inData[c8_i168] = (*(real_T (*)[140])c8_inData)[c8_i168];
  }

  for (c8_i169 = 0; c8_i169 < 140; c8_i169++) {
    c8_u[c8_i169] = c8_b_inData[c8_i169];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_l_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i170;
  char_T c8_b_inData[139];
  int32_T c8_i171;
  char_T c8_u[139];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i170 = 0; c8_i170 < 139; c8_i170++) {
    c8_b_inData[c8_i170] = (*(char_T (*)[139])c8_inData)[c8_i170];
  }

  for (c8_i171 = 0; c8_i171 < 139; c8_i171++) {
    c8_u[c8_i171] = c8_b_inData[c8_i171];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_m_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i172;
  real_T c8_b_inData[139];
  int32_T c8_i173;
  real_T c8_u[139];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i172 = 0; c8_i172 < 139; c8_i172++) {
    c8_b_inData[c8_i172] = (*(real_T (*)[139])c8_inData)[c8_i172];
  }

  for (c8_i173 = 0; c8_i173 < 139; c8_i173++) {
    c8_u[c8_i173] = c8_b_inData[c8_i173];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_n_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i174;
  char_T c8_b_inData[115];
  int32_T c8_i175;
  char_T c8_u[115];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i174 = 0; c8_i174 < 115; c8_i174++) {
    c8_b_inData[c8_i174] = (*(char_T (*)[115])c8_inData)[c8_i174];
  }

  for (c8_i175 = 0; c8_i175 < 115; c8_i175++) {
    c8_u[c8_i175] = c8_b_inData[c8_i175];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_o_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i176;
  real_T c8_b_inData[115];
  int32_T c8_i177;
  real_T c8_u[115];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i176 = 0; c8_i176 < 115; c8_i176++) {
    c8_b_inData[c8_i176] = (*(real_T (*)[115])c8_inData)[c8_i176];
  }

  for (c8_i177 = 0; c8_i177 < 115; c8_i177++) {
    c8_u[c8_i177] = c8_b_inData[c8_i177];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_p_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i178;
  char_T c8_b_inData[202];
  int32_T c8_i179;
  char_T c8_u[202];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i178 = 0; c8_i178 < 202; c8_i178++) {
    c8_b_inData[c8_i178] = (*(char_T (*)[202])c8_inData)[c8_i178];
  }

  for (c8_i179 = 0; c8_i179 < 202; c8_i179++) {
    c8_u[c8_i179] = c8_b_inData[c8_i179];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 202),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_q_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i180;
  real_T c8_b_inData[202];
  int32_T c8_i181;
  real_T c8_u[202];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i180 = 0; c8_i180 < 202; c8_i180++) {
    c8_b_inData[c8_i180] = (*(real_T (*)[202])c8_inData)[c8_i180];
  }

  for (c8_i181 = 0; c8_i181 < 202; c8_i181++) {
    c8_u[c8_i181] = c8_b_inData[c8_i181];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 202), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_r_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i182;
  char_T c8_b_inData[85];
  int32_T c8_i183;
  char_T c8_u[85];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i182 = 0; c8_i182 < 85; c8_i182++) {
    c8_b_inData[c8_i182] = (*(char_T (*)[85])c8_inData)[c8_i182];
  }

  for (c8_i183 = 0; c8_i183 < 85; c8_i183++) {
    c8_u[c8_i183] = c8_b_inData[c8_i183];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 85), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_s_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i184;
  real_T c8_b_inData[85];
  int32_T c8_i185;
  real_T c8_u[85];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i184 = 0; c8_i184 < 85; c8_i184++) {
    c8_b_inData[c8_i184] = (*(real_T (*)[85])c8_inData)[c8_i184];
  }

  for (c8_i185 = 0; c8_i185 < 85; c8_i185++) {
    c8_u[c8_i185] = c8_b_inData[c8_i185];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 85), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_t_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i186;
  char_T c8_b_inData[131];
  int32_T c8_i187;
  char_T c8_u[131];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i186 = 0; c8_i186 < 131; c8_i186++) {
    c8_b_inData[c8_i186] = (*(char_T (*)[131])c8_inData)[c8_i186];
  }

  for (c8_i187 = 0; c8_i187 < 131; c8_i187++) {
    c8_u[c8_i187] = c8_b_inData[c8_i187];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_u_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i188;
  real_T c8_b_inData[131];
  int32_T c8_i189;
  real_T c8_u[131];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i188 = 0; c8_i188 < 131; c8_i188++) {
    c8_b_inData[c8_i188] = (*(real_T (*)[131])c8_inData)[c8_i188];
  }

  for (c8_i189 = 0; c8_i189 < 131; c8_i189++) {
    c8_u[c8_i189] = c8_b_inData[c8_i189];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

const mxArray *sf_c8_DemoWave_K_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 19, 1),
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
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/encStr2Arr.m"),
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
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("disp"), "name", "name", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c8_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("decArr2Str"), "name", "name",
                  6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/decArr2Str.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1403644012U), "fileTimeLo",
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
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/decArr2Str.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_li_find"), "name", "name",
                  7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 11);
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
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
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/decArr2Str.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "name", "name", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
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
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("disp"), "name", "name", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c8_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs18), "lhs", "lhs",
                  18);
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

static void c8_activate_secsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = c8_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_deactivate_secsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_increment_counters_secsc8_DemoWave_K
  (SFc8_DemoWave_KInstanceStruct *chartInstance)
{
  if (chartInstance->c8_temporalCounter_i1 < 15U) {
    chartInstance->c8_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c8_temporalCounter_i1 + 1);
  }
}

static void c8_reset_counters_secsc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c8_DemoWave_K_secs(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_activate_secsc8_DemoWave_K(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c8_DemoWave_K_secs(SimStruct
  *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_increment_counters_secsc8_DemoWave_K(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c8_DemoWave_K_secs(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_reset_counters_secsc8_DemoWave_K(chartInstance);
}

void sf_exported_auto_deactivate_c8_DemoWave_K_secs(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_deactivate_secsc8_DemoWave_K(chartInstance);
}

boolean_T sf_exported_auto_isStablec8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  return chartInstance->c8_isStable;
}

void sf_exported_auto_duringc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_c8_DemoWave_K(chartInstance);
}

void sf_exported_auto_enterc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_enter_atomic_c8_DemoWave_K(chartInstance);
  c8_enter_internal_c8_DemoWave_K(chartInstance);
}

void sf_exported_auto_exitc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_exit_internal_c8_DemoWave_K(chartInstance);
}

void sf_exported_auto_gatewayc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  chartInstance->c8_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_initc8_DemoWave_K(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec8_DemoWave_K(SimStruct *c8_S)
{
  const mxArray *c8_out = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_out = NULL;
  sf_mex_assign(&c8_out, sf_internal_get_sim_state_c8_DemoWave_K(c8_S), false);
  return c8_out;
}

void sf_exported_auto_setSimstatec8_DemoWave_K(SimStruct *c8_S, const mxArray
  *c8_in)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c8_DemoWave_K(c8_S, sf_mex_dup(c8_in));
  sf_mex_destroy(&c8_in);
}

void sf_exported_auto_check_state_inconsistency_c8_DemoWave_K(SimStruct *c8_S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DemoWave_KMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_insertQueueLowc8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, real_T c8_bmls[1280], real_T c8_myBML[256], real_T c8_newBmls
  [1280])
{
  uint32_T c8_debug_family_var_map[8];
  real_T c8_full;
  real_T c8_t[256];
  real_T c8_i;
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i190;
  static real_T c8_dv38[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c8_i191;
  int32_T c8_i192;
  int32_T c8_i193;
  int32_T c8_i194;
  int32_T c8_i195;
  int32_T c8_b_i;
  int32_T c8_c_i;
  int32_T c8_i196;
  real_T c8_b_bmls[256];
  int32_T c8_i197;
  real_T c8_dv39[256];
  int32_T c8_d_i;
  int32_T c8_i198;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  int32_T c8_i199;
  real_T c8_b_myBML[256];
  int32_T c8_tmp_sizes[2];
  char_T c8_tmp_data[256];
  int32_T c8_u_sizes[2];
  int32_T c8_b_u;
  int32_T c8_c_u;
  int32_T c8_loop_ub;
  int32_T c8_i200;
  char_T c8_u_data[256];
  const mxArray *c8_b_y = NULL;
  int32_T c8_i201;
  static char_T c8_cv7[20] = { 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'a', 'd', 'd',
    ' ', 'w', 'h', 'e', 'n', ' ', 'f', 'u', 'l', 'l' };

  char_T c8_d_u[20];
  const mxArray *c8_c_y = NULL;
  int32_T c8_i202;
  real_T c8_c_myBML[256];
  int32_T c8_b_tmp_sizes[2];
  char_T c8_b_tmp_data[256];
  int32_T c8_b_u_sizes[2];
  int32_T c8_e_u;
  int32_T c8_f_u;
  int32_T c8_b_loop_ub;
  int32_T c8_i203;
  char_T c8_b_u_data[256];
  const mxArray *c8_d_y = NULL;
  int32_T c8_i204;
  real_T c8_c_bmls[256];
  int32_T c8_i205;
  int32_T c8_i206;
  real_T c8_d_bmls[256];
  int32_T c8_i207;
  int32_T c8_i208;
  real_T c8_e_bmls[256];
  int32_T c8_i209;
  int32_T c8_i210;
  int32_T c8_i211;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_full, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_t, 1U, c8_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 4U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_bmls, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myBML, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_newBmls, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 2);
  c8_full = 1.0;
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 3);
  for (c8_i190 = 0; c8_i190 < 256; c8_i190++) {
    c8_t[c8_i190] = c8_dv38[c8_i190];
  }

  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 4);
  for (c8_i191 = 0; c8_i191 < 256; c8_i191++) {
    c8_newBmls[c8_i191] = c8_t[c8_i191];
  }

  for (c8_i192 = 0; c8_i192 < 256; c8_i192++) {
    c8_newBmls[c8_i192 + 256] = c8_t[c8_i192];
  }

  for (c8_i193 = 0; c8_i193 < 256; c8_i193++) {
    c8_newBmls[c8_i193 + 512] = c8_t[c8_i193];
  }

  for (c8_i194 = 0; c8_i194 < 256; c8_i194++) {
    c8_newBmls[c8_i194 + 768] = c8_t[c8_i194];
  }

  for (c8_i195 = 0; c8_i195 < 256; c8_i195++) {
    c8_newBmls[c8_i195 + 1024] = c8_t[c8_i195];
  }

  c8_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 5);
  c8_i = 1.0;
  c8_b_i = 0;
  do {
    exitg1 = 0;
    if (c8_b_i < 5) {
      c8_i = 1.0 + (real_T)c8_b_i;
      CV_EML_FOR(6, 1, 0, 1);
      _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 6);
      c8_c_i = (int32_T)c8_i - 1;
      for (c8_i196 = 0; c8_i196 < 256; c8_i196++) {
        c8_b_bmls[c8_i196] = c8_bmls[c8_i196 + (c8_c_i << 8)];
      }

      for (c8_i197 = 0; c8_i197 < 256; c8_i197++) {
        c8_dv39[c8_i197] = c8_dv38[c8_i197];
      }

      if (CV_EML_IF(6, 1, 0, c8_isequal(chartInstance, c8_b_bmls, c8_dv39))) {
        _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 8);
        c8_d_i = (int32_T)c8_i - 1;
        for (c8_i198 = 0; c8_i198 < 256; c8_i198++) {
          c8_bmls[c8_i198 + (c8_d_i << 8)] = c8_myBML[c8_i198];
        }

        _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 9);
        c8_full = 0.0;
        _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 10);
        c8_u = c8_i;
        c8_y = NULL;
        sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c8_y);
        _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 10);
        for (c8_i199 = 0; c8_i199 < 256; c8_i199++) {
          c8_b_myBML[c8_i199] = c8_myBML[c8_i199];
        }

        c8_decArr2Str(chartInstance, c8_b_myBML, c8_tmp_data, c8_tmp_sizes);
        c8_u_sizes[0] = 1;
        c8_u_sizes[1] = c8_tmp_sizes[1];
        c8_b_u = c8_u_sizes[0];
        c8_c_u = c8_u_sizes[1];
        c8_loop_ub = c8_tmp_sizes[0] * c8_tmp_sizes[1] - 1;
        for (c8_i200 = 0; c8_i200 <= c8_loop_ub; c8_i200++) {
          c8_u_data[c8_i200] = c8_tmp_data[c8_i200];
        }

        c8_b_y = NULL;
        sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u_data, 10, 0U, 1U, 0U, 2,
          c8_u_sizes[0], c8_u_sizes[1]), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c8_b_y);
        _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 11);
        exitg1 = 1;
      } else {
        c8_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(6, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 14);
  if (CV_EML_IF(6, 1, 1, c8_full != 0.0)) {
    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 16);
    for (c8_i201 = 0; c8_i201 < 20; c8_i201++) {
      c8_d_u[c8_i201] = c8_cv7[c8_i201];
    }

    c8_c_y = NULL;
    sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_d_u, 10, 0U, 1U, 0U, 2, 1, 20),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c8_c_y);
    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 16);
    for (c8_i202 = 0; c8_i202 < 256; c8_i202++) {
      c8_c_myBML[c8_i202] = c8_myBML[c8_i202];
    }

    c8_decArr2Str(chartInstance, c8_c_myBML, c8_b_tmp_data, c8_b_tmp_sizes);
    c8_b_u_sizes[0] = 1;
    c8_b_u_sizes[1] = c8_b_tmp_sizes[1];
    c8_e_u = c8_b_u_sizes[0];
    c8_f_u = c8_b_u_sizes[1];
    c8_b_loop_ub = c8_b_tmp_sizes[0] * c8_b_tmp_sizes[1] - 1;
    for (c8_i203 = 0; c8_i203 <= c8_b_loop_ub; c8_i203++) {
      c8_b_u_data[c8_i203] = c8_b_tmp_data[c8_i203];
    }

    c8_d_y = NULL;
    sf_mex_assign(&c8_d_y, sf_mex_create("y", c8_b_u_data, 10, 0U, 1U, 0U, 2,
      c8_b_u_sizes[0], c8_b_u_sizes[1]), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c8_d_y);
    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 17);
    for (c8_i204 = 0; c8_i204 < 256; c8_i204++) {
      c8_c_bmls[c8_i204] = c8_bmls[c8_i204 + 256];
    }

    for (c8_i205 = 0; c8_i205 < 256; c8_i205++) {
      c8_bmls[c8_i205] = c8_c_bmls[c8_i205];
    }

    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 18);
    for (c8_i206 = 0; c8_i206 < 256; c8_i206++) {
      c8_d_bmls[c8_i206] = c8_bmls[c8_i206 + 512];
    }

    for (c8_i207 = 0; c8_i207 < 256; c8_i207++) {
      c8_bmls[c8_i207 + 256] = c8_d_bmls[c8_i207];
    }

    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 19);
    for (c8_i208 = 0; c8_i208 < 256; c8_i208++) {
      c8_e_bmls[c8_i208] = c8_bmls[c8_i208 + 768];
    }

    for (c8_i209 = 0; c8_i209 < 256; c8_i209++) {
      c8_bmls[c8_i209 + 512] = c8_e_bmls[c8_i209];
    }

    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 20);
    for (c8_i210 = 0; c8_i210 < 256; c8_i210++) {
      c8_bmls[c8_i210 + 1024] = c8_myBML[c8_i210];
    }
  }

  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 22);
  for (c8_i211 = 0; c8_i211 < 1280; c8_i211++) {
    c8_newBmls[c8_i211] = c8_bmls[c8_i211];
  }

  c8_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_walkInvadingTablec8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, real_T c8_bmlID, real_T *c8_p, real_T c8_poseBML[256])
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
  real_T c8_dv40[256];
  int32_T c8_i212;
  int32_T c8_i213;
  int32_T c8_i214;
  int32_T c8_i215;
  int32_T c8_i216;
  int32_T c8_i217;
  int32_T c8_i218;
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
  int32_T c8_i219;
  static char_T c8_cv8[131] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'u',
    '=', '\"', '2', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"', ' ', 'r',
    'e', 'a', 'd', 'y', '=', '\"', '1', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=',
    '\"', '4', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c8_i220;
  static real_T c8_dv41[131] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i221;
  int32_T c8_i222;
  int32_T c8_i223;
  int32_T c8_i224;
  int32_T c8_i225;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c8_d_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_3, 2U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_4, 3U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_5, 4U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_6, 5U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_7, 6U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_8, 7U,
    c8_g_sf_marshallOut, c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 8U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 9U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 10U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_p, 11U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 12U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  CV_EML_FCN(14, 0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 5);
  c8_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 6);
  c8_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 7);
  c8_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 8);
  c8_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 9);
  c8_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 10);
  c8_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 15);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 19);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 23);
  c8_aVarTruthTableCondition_3 = (c8_bmlID == 3.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 27);
  c8_aVarTruthTableCondition_4 = (c8_bmlID == 4.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 31);
  c8_aVarTruthTableCondition_5 = (c8_bmlID == 5.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 35);
  c8_aVarTruthTableCondition_6 = (c8_bmlID == 6.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 39);
  c8_aVarTruthTableCondition_7 = (c8_bmlID == 7.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 43);
  c8_aVarTruthTableCondition_8 = (c8_bmlID == 8.0);
  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 45);
  if (CV_EML_IF(14, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 46);
    CV_EML_FCN(14, 1);
    _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 69);
    c8_encStr2Arr(chartInstance, c8_dv40);
    for (c8_i212 = 0; c8_i212 < 256; c8_i212++) {
      c8_poseBML[c8_i212] = c8_dv40[c8_i212];
    }

    c8_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 69);
    *c8_p = 1.0;
    c8_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -69);
  } else {
    _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 47);
    if (CV_EML_IF(14, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 48);
      CV_EML_FCN(14, 2);
      _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 75);
      c8_b_encStr2Arr(chartInstance, c8_dv40);
      for (c8_i213 = 0; c8_i213 < 256; c8_i213++) {
        c8_poseBML[c8_i213] = c8_dv40[c8_i213];
      }

      c8_updateDataWrittenToVector(chartInstance, 15U);
      _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 75);
      *c8_p = 1.0;
      c8_updateDataWrittenToVector(chartInstance, 14U);
      _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -75);
    } else {
      _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 49);
      if (CV_EML_IF(14, 1, 2, c8_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 50);
        CV_EML_FCN(14, 3);
        _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 81);
        c8_c_encStr2Arr(chartInstance, c8_dv40);
        for (c8_i214 = 0; c8_i214 < 256; c8_i214++) {
          c8_poseBML[c8_i214] = c8_dv40[c8_i214];
        }

        c8_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 81);
        *c8_p = 1.0;
        c8_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -81);
      } else {
        _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 51);
        if (CV_EML_IF(14, 1, 3, c8_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 52);
          CV_EML_FCN(14, 4);
          _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 87);
          c8_d_encStr2Arr(chartInstance, c8_dv40);
          for (c8_i215 = 0; c8_i215 < 256; c8_i215++) {
            c8_poseBML[c8_i215] = c8_dv40[c8_i215];
          }

          c8_updateDataWrittenToVector(chartInstance, 15U);
          _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 87);
          *c8_p = 1.0;
          c8_updateDataWrittenToVector(chartInstance, 14U);
          _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -87);
        } else {
          _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 53);
          if (CV_EML_IF(14, 1, 4, c8_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 54);
            CV_EML_FCN(14, 5);
            _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 93);
            c8_e_encStr2Arr(chartInstance, c8_dv40);
            for (c8_i216 = 0; c8_i216 < 256; c8_i216++) {
              c8_poseBML[c8_i216] = c8_dv40[c8_i216];
            }

            c8_updateDataWrittenToVector(chartInstance, 15U);
            _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 93);
            *c8_p = 1.0;
            c8_updateDataWrittenToVector(chartInstance, 14U);
            _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -93);
          } else {
            _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 55);
            if (CV_EML_IF(14, 1, 5, c8_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 56);
              CV_EML_FCN(14, 6);
              _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 99);
              c8_f_encStr2Arr(chartInstance, c8_dv40);
              for (c8_i217 = 0; c8_i217 < 256; c8_i217++) {
                c8_poseBML[c8_i217] = c8_dv40[c8_i217];
              }

              c8_updateDataWrittenToVector(chartInstance, 15U);
              _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 99);
              *c8_p = 1.0;
              c8_updateDataWrittenToVector(chartInstance, 14U);
              _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -99);
            } else {
              _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 57);
              if (CV_EML_IF(14, 1, 6, c8_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 58);
                CV_EML_FCN(14, 7);
                _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 105);
                c8_g_encStr2Arr(chartInstance, c8_dv40);
                for (c8_i218 = 0; c8_i218 < 256; c8_i218++) {
                  c8_poseBML[c8_i218] = c8_dv40[c8_i218];
                }

                c8_updateDataWrittenToVector(chartInstance, 15U);
                _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 105);
                *c8_p = 1.0;
                c8_updateDataWrittenToVector(chartInstance, 14U);
                _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -105);
              } else {
                _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 59);
                if (CV_EML_IF(14, 1, 7, c8_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 60);
                  CV_EML_FCN(14, 8);
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 111);
                  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_l_debug_family_names,
                    c8_b_debug_family_var_map);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U,
                    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_u_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_c_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U,
                    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U,
                    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_t_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U,
                    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U,
                    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U,
                    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
                  for (c8_i219 = 0; c8_i219 < 131; c8_i219++) {
                    c8_mystr[c8_i219] = c8_cv8[c8_i219];
                  }

                  CV_SCRIPT_FCN(0, 0);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
                  c8_maxarrsize = 256.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
                  for (c8_i220 = 0; c8_i220 < 131; c8_i220++) {
                    c8_arr[c8_i220] = c8_dv41[c8_i220];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
                  c8_ss = 131.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
                  c8_padsize = 125.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
                  for (c8_i221 = 0; c8_i221 < 256; c8_i221++) {
                    c8_tt[c8_i221] = 0.0;
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
                  for (c8_i222 = 0; c8_i222 < 131; c8_i222++) {
                    c8_tt[c8_i222] = c8_arr[c8_i222];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
                  for (c8_i223 = 0; c8_i223 < 256; c8_i223++) {
                    c8_myarr256[c8_i223] = c8_tt[c8_i223];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
                  _SFD_SYMBOL_SCOPE_POP();
                  for (c8_i224 = 0; c8_i224 < 256; c8_i224++) {
                    c8_poseBML[c8_i224] = c8_myarr256[c8_i224];
                  }

                  c8_updateDataWrittenToVector(chartInstance, 15U);
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 111);
                  *c8_p = 1.0;
                  c8_updateDataWrittenToVector(chartInstance, 14U);
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 62);
                  CV_EML_FCN(14, 1);
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 69);
                  c8_encStr2Arr(chartInstance, c8_dv40);
                  for (c8_i225 = 0; c8_i225 < 256; c8_i225++) {
                    c8_poseBML[c8_i225] = c8_dv40[c8_i225];
                  }

                  c8_updateDataWrittenToVector(chartInstance, 15U);
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, 69);
                  *c8_p = 1.0;
                  c8_updateDataWrittenToVector(chartInstance, 14U);
                  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -69);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(14U, chartInstance->c8_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_insertQueuec8_DemoWave_K(SFc8_DemoWave_KInstanceStruct
  *chartInstance, real_T c8_bmls[1280], real_T c8_myBML[256], real_T c8_newBmls
  [1280])
{
  uint32_T c8_debug_family_var_map[8];
  real_T c8_full;
  real_T c8_t[256];
  real_T c8_i;
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i226;
  static real_T c8_dv42[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c8_i227;
  int32_T c8_i228;
  int32_T c8_i229;
  int32_T c8_i230;
  int32_T c8_i231;
  int32_T c8_b_i;
  int32_T c8_c_i;
  int32_T c8_i232;
  real_T c8_b_bmls[256];
  int32_T c8_i233;
  real_T c8_dv43[256];
  int32_T c8_d_i;
  int32_T c8_i234;
  int32_T c8_i235;
  real_T c8_c_bmls[256];
  int32_T c8_i236;
  int32_T c8_i237;
  real_T c8_d_bmls[256];
  int32_T c8_i238;
  int32_T c8_i239;
  real_T c8_e_bmls[256];
  int32_T c8_i240;
  int32_T c8_i241;
  int32_T c8_i242;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c8_m_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_full, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_t, 1U, c8_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 4U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_bmls, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myBML, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_newBmls, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 2);
  c8_full = 1.0;
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 3);
  for (c8_i226 = 0; c8_i226 < 256; c8_i226++) {
    c8_t[c8_i226] = c8_dv42[c8_i226];
  }

  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 4);
  for (c8_i227 = 0; c8_i227 < 256; c8_i227++) {
    c8_newBmls[c8_i227] = c8_t[c8_i227];
  }

  for (c8_i228 = 0; c8_i228 < 256; c8_i228++) {
    c8_newBmls[c8_i228 + 256] = c8_t[c8_i228];
  }

  for (c8_i229 = 0; c8_i229 < 256; c8_i229++) {
    c8_newBmls[c8_i229 + 512] = c8_t[c8_i229];
  }

  for (c8_i230 = 0; c8_i230 < 256; c8_i230++) {
    c8_newBmls[c8_i230 + 768] = c8_t[c8_i230];
  }

  for (c8_i231 = 0; c8_i231 < 256; c8_i231++) {
    c8_newBmls[c8_i231 + 1024] = c8_t[c8_i231];
  }

  c8_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 5);
  c8_i = 1.0;
  c8_b_i = 0;
  do {
    exitg1 = 0;
    if (c8_b_i < 5) {
      c8_i = 1.0 + (real_T)c8_b_i;
      CV_EML_FOR(5, 1, 0, 1);
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 6);
      c8_c_i = (int32_T)c8_i - 1;
      for (c8_i232 = 0; c8_i232 < 256; c8_i232++) {
        c8_b_bmls[c8_i232] = c8_bmls[c8_i232 + (c8_c_i << 8)];
      }

      for (c8_i233 = 0; c8_i233 < 256; c8_i233++) {
        c8_dv43[c8_i233] = c8_dv42[c8_i233];
      }

      if (CV_EML_IF(5, 1, 0, c8_isequal(chartInstance, c8_b_bmls, c8_dv43))) {
        _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 8);
        c8_d_i = (int32_T)c8_i - 1;
        for (c8_i234 = 0; c8_i234 < 256; c8_i234++) {
          c8_bmls[c8_i234 + (c8_d_i << 8)] = c8_myBML[c8_i234];
        }

        _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 9);
        c8_full = 0.0;
        _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 10);
        exitg1 = 1;
      } else {
        c8_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(5, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 13);
  if (CV_EML_IF(5, 1, 1, c8_full != 0.0)) {
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 15);
    for (c8_i235 = 0; c8_i235 < 256; c8_i235++) {
      c8_c_bmls[c8_i235] = c8_bmls[c8_i235 + 256];
    }

    for (c8_i236 = 0; c8_i236 < 256; c8_i236++) {
      c8_bmls[c8_i236] = c8_c_bmls[c8_i236];
    }

    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 16);
    for (c8_i237 = 0; c8_i237 < 256; c8_i237++) {
      c8_d_bmls[c8_i237] = c8_bmls[c8_i237 + 512];
    }

    for (c8_i238 = 0; c8_i238 < 256; c8_i238++) {
      c8_bmls[c8_i238 + 256] = c8_d_bmls[c8_i238];
    }

    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 17);
    for (c8_i239 = 0; c8_i239 < 256; c8_i239++) {
      c8_e_bmls[c8_i239] = c8_bmls[c8_i239 + 768];
    }

    for (c8_i240 = 0; c8_i240 < 256; c8_i240++) {
      c8_bmls[c8_i240 + 512] = c8_e_bmls[c8_i240];
    }

    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 18);
    for (c8_i241 = 0; c8_i241 < 256; c8_i241++) {
      c8_bmls[c8_i241 + 1024] = c8_myBML[c8_i241];
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 20);
  for (c8_i242 = 0; c8_i242 < 1280; c8_i242++) {
    c8_newBmls[c8_i242] = c8_bmls[c8_i242];
  }

  c8_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c8_isequal(SFc8_DemoWave_KInstanceStruct *chartInstance, real_T
  c8_varargin_1[256], real_T c8_varargin_2[256])
{
  boolean_T c8_p;
  boolean_T c8_b_p;
  int32_T c8_k;
  real_T c8_b_k;
  real_T c8_x1;
  real_T c8_x2;
  boolean_T c8_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c8_p = false;
  c8_b_p = true;
  c8_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c8_k < 256)) {
    c8_b_k = 1.0 + (real_T)c8_k;
    c8_x1 = c8_varargin_1[(int32_T)c8_b_k - 1];
    c8_x2 = c8_varargin_2[(int32_T)c8_b_k - 1];
    c8_c_p = (c8_x1 == c8_x2);
    if (!c8_c_p) {
      c8_b_p = false;
      exitg1 = true;
    } else {
      c8_k++;
    }
  }

  if (!c8_b_p) {
  } else {
    c8_p = true;
  }

  return c8_p;
}

void sf_exported_user_c8_DemoWave_K_insertQueue(SimStruct *c8_S, real_T c8_bmls
  [1280], real_T c8_myBML[256], real_T c8_newBmls[1280])
{
  int32_T c8_i243;
  real_T c8_b_bmls[1280];
  int32_T c8_i244;
  real_T c8_b_myBML[256];
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  for (c8_i243 = 0; c8_i243 < 1280; c8_i243++) {
    c8_b_bmls[c8_i243] = c8_bmls[c8_i243];
  }

  for (c8_i244 = 0; c8_i244 < 256; c8_i244++) {
    c8_b_myBML[c8_i244] = c8_myBML[c8_i244];
  }

  c8_insertQueuec8_DemoWave_K(chartInstance, c8_b_bmls, c8_b_myBML, c8_newBmls);
}

void sf_exported_user_c8_DemoWave_K_insertQueueLow(SimStruct *c8_S, real_T
  c8_bmls[1280], real_T c8_myBML[256], real_T c8_newBmls[1280])
{
  int32_T c8_i245;
  real_T c8_b_bmls[1280];
  int32_T c8_i246;
  real_T c8_b_myBML[256];
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  for (c8_i245 = 0; c8_i245 < 1280; c8_i245++) {
    c8_b_bmls[c8_i245] = c8_bmls[c8_i245];
  }

  for (c8_i246 = 0; c8_i246 < 256; c8_i246++) {
    c8_b_myBML[c8_i246] = c8_myBML[c8_i246];
  }

  c8_insertQueueLowc8_DemoWave_K(chartInstance, c8_b_bmls, c8_b_myBML,
    c8_newBmls);
}

void sf_exported_user_c8_DemoWave_K_walkInvadingTable(SimStruct *c8_S, real_T
  c8_bmlID, real_T *c8_p, real_T c8_poseBML[256])
{
  real_T c8_b_p;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo)->chartInstance;
  c8_walkInvadingTablec8_DemoWave_K(chartInstance, c8_bmlID, &c8_b_p, c8_poseBML);
  *c8_p = c8_b_p;
}

static const mxArray *c8_v_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int8_T c8_j_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int8_T c8_y;
  int8_T c8_i247;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i247, 1, 2, 0U, 0, 0U, 0);
  c8_y = c8_i247;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_secs;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int8_T c8_y;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_secs = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_secs), &c8_thisId);
  sf_mex_destroy(&c8_secs);
  *(int8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_w_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_k_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i248;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i248, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i248;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_x_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  uint8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static uint8_T c8_l_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_b_tp_stateInit, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateInit),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateInit);
  return c8_y;
}

static uint8_T c8_m_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_tp_stateInit;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_b_tp_stateInit = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateInit),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateInit);
  *(uint8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_y_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i249;
  creal_T c8_b_inData[256];
  int32_T c8_i250;
  creal_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i249 = 0; c8_i249 < 256; c8_i249++) {
    c8_b_inData[c8_i249] = (*(creal_T (*)[256])c8_inData)[c8_i249];
  }

  for (c8_i250 = 0; c8_i250 < 256; c8_i250++) {
    c8_u[c8_i250] = c8_b_inData[c8_i250];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 1U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_n_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_b_BMLM, const char_T *c8_identifier, creal_T c8_y[256])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_BMLM), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_b_BMLM);
}

static void c8_o_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, creal_T c8_y[256])
{
  creal_T c8_dcv2[256];
  int32_T c8_i251;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dcv2, 1, 0, 1U, 1, 0U, 2, 256,
                1);
  for (c8_i251 = 0; c8_i251 < 256; c8_i251++) {
    c8_y[c8_i251] = c8_dcv2[c8_i251];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_BMLM;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  creal_T c8_y[256];
  int32_T c8_i252;
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)chartInstanceVoid;
  c8_b_BMLM = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_BMLM), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_b_BMLM);
  for (c8_i252 = 0; c8_i252 < 256; c8_i252++) {
    (*(creal_T (*)[256])c8_outData)[c8_i252] = c8_y[c8_i252];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_p_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier)
{
  const mxArray *c8_y = NULL;
  emlrtMsgIdentifier c8_thisId;
  c8_y = NULL;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  sf_mex_assign(&c8_y, c8_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_setSimStateSideEffectsInfo), &c8_thisId), false);
  sf_mex_destroy(&c8_b_setSimStateSideEffectsInfo);
  return c8_y;
}

static const mxArray *c8_q_emlrt_marshallIn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  (void)c8_parentId;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_duplicatearraysafe(&c8_u), false);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_updateDataWrittenToVector(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_vectorIndex)
{
  (void)chartInstance;
  c8_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c8_vectorIndex, 0, 16, 1, 0)] = true;
}

static void c8_errorIfDataNotWrittenToFcn(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_vectorIndex, uint32_T c8_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c8_dataNumber, c8_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c8_vectorIndex, 0, 16, 1,
    0)]);
}

static real_T c8_get_BML1(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#78) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c8_BML1_address)[c8_b];
}

static void c8_set_BML1(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#78) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c8_BML1_address)[c8_b] = c8_c;
}

static real_T *c8_access_BML1(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c8_BML1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML1\' (#78) in the initialization routine of the chart.\n");
  }

  c8_c = *chartInstance->c8_BML1_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c8_c;
}

static real_T c8_get_P(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#79) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_P_address;
}

static void c8_set_P(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T c8_b,
                     real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#79) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_P_address = c8_c;
}

static real_T *c8_access_P(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c8_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#79) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_P_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_BEFORE(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#77) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_BEFORE_address;
}

static void c8_set_STATE_BEFORE(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#77) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_BEFORE_address = c8_c;
}

static real_T *c8_access_STATE_BEFORE(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#77) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_BEFORE_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_OVER(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#75) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_OVER_address;
}

static void c8_set_STATE_OVER(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#75) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_OVER_address = c8_c;
}

static real_T *c8_access_STATE_OVER(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#75) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_OVER_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_READY(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#74) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_READY_address;
}

static void c8_set_STATE_READY(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#74) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_READY_address = c8_c;
}

static real_T *c8_access_STATE_READY(SFc8_DemoWave_KInstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#74) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_READY_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c8_c;
}

static real_T c8_get_avert(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c8_b);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#90) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_avert_address;
}

static void c8_set_avert(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c8_b);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#90) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_avert_address = c8_c;
}

static real_T *c8_access_avert(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#90) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_avert_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c8_c;
}

static real_T c8_get_bmlsL(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c8_b);
  if (chartInstance->c8_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#97) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c8_bmlsL_address)[c8_b];
}

static void c8_set_bmlsL(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c8_b);
  if (chartInstance->c8_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#97) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c8_bmlsL_address)[c8_b] = c8_c;
}

static real_T *c8_access_bmlsL(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c8_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#97) in the initialization routine of the chart.\n");
  }

  c8_c = *chartInstance->c8_bmlsL_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c8_c;
}

static real_T c8_get_bmlsM(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c8_b);
  if (chartInstance->c8_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#92) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c8_bmlsM_address)[c8_b];
}

static void c8_set_bmlsM(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c8_b);
  if (chartInstance->c8_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#92) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c8_bmlsM_address)[c8_b] = c8_c;
}

static real_T *c8_access_bmlsM(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c8_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#92) in the initialization routine of the chart.\n");
  }

  c8_c = *chartInstance->c8_bmlsM_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c8_c;
}

static real_T c8_get_fileID(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c8_b);
  if (chartInstance->c8_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#81) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_fileID_address;
}

static void c8_set_fileID(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c8_b);
  if (chartInstance->c8_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#81) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_fileID_address = c8_c;
}

static real_T *c8_access_fileID(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c8_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#81) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_fileID_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c8_c;
}

static real_T c8_get_pr(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
  c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c8_b);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#80) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_pr_address;
}

static void c8_set_pr(SFc8_DemoWave_KInstanceStruct *chartInstance, uint32_T
                      c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c8_b);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#80) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_pr_address = c8_c;
}

static real_T *c8_access_pr(SFc8_DemoWave_KInstanceStruct *chartInstance,
  uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#80) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_pr_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c8_c;
}

static void init_dsm_address_info(SFc8_DemoWave_KInstanceStruct *chartInstance)
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
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c8_bmlsL_address, &chartInstance->c8_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c8_bmlsM_address, &chartInstance->c8_bmlsM_index);
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

void sf_c8_DemoWave_K_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1915834119U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3638218808U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2859771711U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(437658099U);
}

mxArray *sf_c8_DemoWave_K_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vdbxF3Y4vBPy13p3sYYa2G");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

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
      pr[0] = (double)(256);
      pr[1] = (double)(5);
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
      pr[0] = (double)(256);
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

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(256);
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

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_DemoWave_K_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_DemoWave_K_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_DemoWave_K(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[27],T\"gameState\",},{M[3],M[110],T\"BMLL\",},{M[3],M[102],T\"BMLM\",},{M[3],M[53],T\"NEUTRAL\",},{M[3],M[55],T\"TOO_CLOSE\",},{M[3],M[54],T\"TOO_FAR\",},{M[3],M[52],T\"closeBuffer\",},{M[3],M[56],T\"farBuffer\",},{M[3],M[113],T\"n\",},{M[3],M[51],T\"neutralBuffer\",}}",
    "100 S1x6'type','srcId','name','auxInfo'{{M[3],M[111],T\"newBmlsL\",},{M[3],M[100],T\"newBmlsM\",},{M[3],M[75],T\"position\",},{M[8],M[0],T\"is_active_c8_DemoWave_K\",},{M[9],M[0],T\"is_c8_DemoWave_K\",},{M[11],M[33],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x5[26 23 24 50 84],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 16, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_DemoWave_K_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_DemoWave_KInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc8_DemoWave_KInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DemoWave_KMachineNumber_,
           8,
           15,
           25,
           0,
           35,
           1,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_DemoWave_KMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DemoWave_KMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DemoWave_KMachineNumber_,
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
          _SFD_SET_DATA_PROPS(18,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(19,11,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(20,0,0,0,"BMLM");
          _SFD_SET_DATA_PROPS(21,1,1,0,"inputChangeFlag");
          _SFD_SET_DATA_PROPS(22,0,0,0,"BMLL");
          _SFD_SET_DATA_PROPS(23,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(24,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(25,0,0,0,"n");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,9,0,0,"");
          _SFD_SET_DATA_PROPS(30,8,0,0,"");
          _SFD_SET_DATA_PROPS(31,9,0,0,"");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
          _SFD_SET_DATA_PROPS(33,8,0,0,"");
          _SFD_SET_DATA_PROPS(34,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(14,0,2);
          _SFD_CH_SUBSTATE_COUNT(12);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,7);
          _SFD_CH_SUBSTATE_INDEX(6,8);
          _SFD_CH_SUBSTATE_INDEX(7,9);
          _SFD_CH_SUBSTATE_INDEX(8,10);
          _SFD_CH_SUBSTATE_INDEX(9,11);
          _SFD_CH_SUBSTATE_INDEX(10,12);
          _SFD_CH_SUBSTATE_INDEX(11,13);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
        }

        _SFD_CV_INIT_CHART(12,1,0,0);

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
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(6,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"insertQueueLowc8_DemoWave_K",0,-1,679);
        _SFD_CV_INIT_EML_IF(6,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(6,1,1,344,355,-1,660);
        _SFD_CV_INIT_EML_FOR(6,1,0,109,121,339);
        _SFD_CV_INIT_EML(14,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(14,0,"walkInvadingTablec8_DemoWave_K",0,-1,1351);
        _SFD_CV_INIT_EML_FCN(14,1,"aFcnTruthTableAction_1",1351,-1,1564);
        _SFD_CV_INIT_EML_FCN(14,2,"aFcnTruthTableAction_2",1564,-1,1777);
        _SFD_CV_INIT_EML_FCN(14,3,"aFcnTruthTableAction_3",1777,-1,1992);
        _SFD_CV_INIT_EML_FCN(14,4,"aFcnTruthTableAction_4",1992,-1,2186);
        _SFD_CV_INIT_EML_FCN(14,5,"aFcnTruthTableAction_5",2186,-1,2469);
        _SFD_CV_INIT_EML_FCN(14,6,"aFcnTruthTableAction_6",2469,-1,2683);
        _SFD_CV_INIT_EML_FCN(14,7,"aFcnTruthTableAction_7",2683,-1,2847);
        _SFD_CV_INIT_EML_FCN(14,8,"aFcnTruthTableAction_8",2847,-1,3051);
        _SFD_CV_INIT_EML_IF(14,1,0,785,815,846,1349);
        _SFD_CV_INIT_EML_IF(14,1,1,846,880,911,1349);
        _SFD_CV_INIT_EML_IF(14,1,2,911,945,976,1349);
        _SFD_CV_INIT_EML_IF(14,1,3,976,1010,1041,1349);
        _SFD_CV_INIT_EML_IF(14,1,4,1041,1075,1106,1349);
        _SFD_CV_INIT_EML_IF(14,1,5,1106,1140,1171,1349);
        _SFD_CV_INIT_EML_IF(14,1,6,1171,1205,1236,1349);
        _SFD_CV_INIT_EML_IF(14,1,7,1236,1270,1301,1349);
        _SFD_CV_INIT_EML(5,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"insertQueuec8_DemoWave_K",0,-1,565);
        _SFD_CV_INIT_EML_IF(5,1,0,126,151,-1,-2);
        _SFD_CV_INIT_EML_IF(5,1,1,296,307,-1,546);
        _SFD_CV_INIT_EML_FOR(5,1,0,106,118,291);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"decArr2Str",0,-1,97);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,36,1,36);

        {
          static int condStart[] = { 1, 23 };

          static int condEnd[] = { 22, 36 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,36,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 21 };

          static int condEnd[] = { 20, 34 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(24,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,0,14,0,14);
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
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)
            c8_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c8_y_sf_marshallOut,(MexInFcnForType)
            c8_j_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c8_y_sf_marshallOut,(MexInFcnForType)
            c8_j_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)
            c8_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)
            c8_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)
            c8_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)
            c8_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));

        {
          real_T *c8_gameState;
          real_T *c8_distance;
          boolean_T *c8_zChange;
          boolean_T *c8_inputChangeFlag;
          c8_inputChangeFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 2);
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
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c8_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(19U, *chartInstance->c8_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c8_BMLM);
          _SFD_SET_DATA_VALUE_PTR(21U, c8_inputChangeFlag);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c8_BMLL);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c8_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(24U, *chartInstance->c8_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c8_n);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DemoWave_KMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tXTW5U46re7bXoLFU7I6h";
}

static void sf_opaque_initialize_c8_DemoWave_K(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*)
    chartInstanceVar);
  initialize_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_DemoWave_K(void *chartInstanceVar)
{
  enable_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_DemoWave_K(void *chartInstanceVar)
{
  disable_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_DemoWave_K(void *chartInstanceVar)
{
  sf_gateway_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_DemoWave_K(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_DemoWave_K
    ((SFc8_DemoWave_KInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_DemoWave_K();/* state var info */
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

extern void sf_internal_set_sim_state_c8_DemoWave_K(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c8_DemoWave_K();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_DemoWave_K(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c8_DemoWave_K(SimStruct* S, const mxArray
  *st)
{
}

static void sf_opaque_terminate_c8_DemoWave_K(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DemoWave_K_optimization_info();
    }

    finalize_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_DemoWave_K(SimStruct *S)
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
    initialize_params_c8_DemoWave_K((SFc8_DemoWave_KInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_DemoWave_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DemoWave_K_optimization_info();
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
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(160739953U));
  ssSetChecksum1(S,(1131388849U));
  ssSetChecksum2(S,(2348425510U));
  ssSetChecksum3(S,(569780924U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_DemoWave_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_DemoWave_K(SimStruct *S)
{
  SFc8_DemoWave_KInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc8_DemoWave_KInstanceStruct *)utMalloc(sizeof
    (SFc8_DemoWave_KInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_DemoWave_KInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_DemoWave_K;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_DemoWave_K;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_DemoWave_K;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_DemoWave_K;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_DemoWave_K;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_DemoWave_K;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_DemoWave_K;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c8_DemoWave_K;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_DemoWave_K;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_DemoWave_K;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_DemoWave_K;
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

void c8_DemoWave_K_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_DemoWave_K(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_DemoWave_K(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_DemoWave_K(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_DemoWave_K_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
