#ifndef __c44_Expriment_Emotion_h__
#define __c44_Expriment_Emotion_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc44_Expriment_EmotionInstanceStruct
#define typedef_SFc44_Expriment_EmotionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c44_sfEvent;
  boolean_T c44_isStable;
  boolean_T c44_doneDoubleBufferReInit;
  uint8_T c44_is_active_c44_Expriment_Emotion;
} SFc44_Expriment_EmotionInstanceStruct;

#endif                                 /*typedef_SFc44_Expriment_EmotionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c44_Expriment_Emotion_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c44_Expriment_Emotion_get_check_sum(mxArray *plhs[]);
extern void c44_Expriment_Emotion_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
