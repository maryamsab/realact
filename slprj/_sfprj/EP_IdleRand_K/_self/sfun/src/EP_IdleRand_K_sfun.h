#ifndef __EP_IdleRand_K_sfun_h__
#define __EP_IdleRand_K_sfun_h__

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

/* Auxiliary Header Files */
#include <stdio.h>

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */
extern uint32_T _EP_IdleRand_KMachineNumber_;

/* Variable Definitions */

/* Function Declarations */
extern void EP_IdleRand_K_initializer(void);
extern void EP_IdleRand_K_terminator(void);

/* Function Definitions */

/* We load infoStruct for rtw_optimation_info on demand in mdlSetWorkWidths and
   free it immediately in mdlStart. Given that this is machine-wide as
   opposed to chart specific, we use NULL check to make sure it gets loaded
   and unloaded once per machine even though the  methods mdlSetWorkWidths/mdlStart
   are chart/instance specific. The following methods abstract this out. */
extern mxArray* load_EP_IdleRand_K_optimization_info(void);
extern void unload_EP_IdleRand_K_optimization_info(void);

#endif
