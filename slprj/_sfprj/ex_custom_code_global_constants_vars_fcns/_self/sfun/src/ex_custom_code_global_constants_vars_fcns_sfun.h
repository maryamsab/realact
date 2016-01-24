#ifndef __ex_custom_code_global_constants_vars_fcns_sfun_h__
#define __ex_custom_code_global_constants_vars_fcns_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                sf_sfun
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "sf_runtime/sfcdebug.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

struct SfDebugInstanceStruct;
extern struct SfDebugInstanceStruct* sfGlobalDebugInstanceStruct;

/* Custom Code from Simulation Target dialog*/
#include "ex_custom_code_global_constants_vars_fcns_hdr.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */
extern uint32_T _ex_custom_code_global_constants_vars_fcnsMachineNumber_;

/* Variable Definitions */

/* Function Declarations */
extern void ex_custom_code_global_constants_vars_fcns_initializer(void);
extern void ex_custom_code_global_constants_vars_fcns_terminator(void);

/* Function Definitions */

/* We load infoStruct for rtw_optimation_info on demand in mdlSetWorkWidths and
   free it immediately in mdlStart. Given that this is machine-wide as
   opposed to chart specific, we use NULL check to make sure it gets loaded
   and unloaded once per machine even though the  methods mdlSetWorkWidths/mdlStart
   are chart/instance specific. The following methods abstract this out. */
extern mxArray* load_ex_custom_code_global_constants_vars_fcns_optimization_info
  (void);
extern void unload_ex_custom_code_global_constants_vars_fcns_optimization_info
  (void);

#endif
