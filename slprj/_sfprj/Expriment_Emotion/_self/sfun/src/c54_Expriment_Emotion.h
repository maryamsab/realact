#ifndef __c54_Expriment_Emotion_h__
#define __c54_Expriment_Emotion_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc54_Expriment_EmotionInstanceStruct
#define typedef_SFc54_Expriment_EmotionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c54_sfEvent;
  boolean_T c54_isStable;
  boolean_T c54_doneDoubleBufferReInit;
  uint8_T c54_is_active_c54_Expriment_Emotion;
} SFc54_Expriment_EmotionInstanceStruct;

#endif                                 /*typedef_SFc54_Expriment_EmotionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c54_Expriment_Emotion_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c54_Expriment_Emotion_get_check_sum(mxArray *plhs[]);
extern void c54_Expriment_Emotion_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
