/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "ex_custom_code_global_constants_vars_fcns_sfun.h"
#include "ex_custom_code_global_constants_vars_fcns_sfun_debug_macros.h"
#include "c1_ex_custom_code_global_constants_vars_fcns.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ex_custom_code_global_constants_vars_fcnsMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ex_custom_code_global_constants_vars_fcns_initializer(void)
{
}

void ex_custom_code_global_constants_vars_fcns_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ex_custom_code_global_constants_vars_fcns_method_dispatcher
  (SimStruct *simstructPtr, unsigned int chartFileNumber, const char* specsCksum,
   int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_ex_custom_code_global_constants_vars_fcns_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ex_custom_code_global_constants_vars_fcns_process_check_sum_call
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3594036789U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3239894113U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3859836420U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(747162455U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1572477688U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3694918576U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3072845001U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1991956737U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void
            sf_c1_ex_custom_code_global_constants_vars_fcns_get_check_sum
            (mxArray *plhs[]);
          sf_c1_ex_custom_code_global_constants_vars_fcns_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3762447323U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3614520553U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2655866698U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3259769256U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2355928741U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3648784751U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(168227069U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2802848706U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ex_custom_code_global_constants_vars_fcns_autoinheritance_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "Cv7OszVsMlf8k21SUi1puB") == 0) {
          extern mxArray
            *sf_c1_ex_custom_code_global_constants_vars_fcns_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_ex_custom_code_global_constants_vars_fcns_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_ex_custom_code_global_constants_vars_fcns_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_ex_custom_code_global_constants_vars_fcns_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ex_custom_code_global_constants_vars_fcns_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ex_custom_code_global_constants_vars_fcns_third_party_uses_info(
  int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "X3KDP29REJDKSaLdkeT9TH") == 0) {
          extern mxArray
            *sf_c1_ex_custom_code_global_constants_vars_fcns_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_ex_custom_code_global_constants_vars_fcns_third_party_uses_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int
  sf_ex_custom_code_global_constants_vars_fcns_updateBuildInfo_args_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "X3KDP29REJDKSaLdkeT9TH") == 0) {
          extern mxArray
            *sf_c1_ex_custom_code_global_constants_vars_fcns_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c1_ex_custom_code_global_constants_vars_fcns_updateBuildInfo_args_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ex_custom_code_global_constants_vars_fcns_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _ex_custom_code_global_constants_vars_fcnsMachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "ex_custom_code_global_constants_vars_fcns","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ex_custom_code_global_constants_vars_fcnsMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ex_custom_code_global_constants_vars_fcnsMachineNumber_,0);
}

void ex_custom_code_global_constants_vars_fcns_register_exported_symbols
  (SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ex_custom_code_global_constants_vars_fcns_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "ex_custom_code_global_constants_vars_fcns",
      "ex_custom_code_global_constants_vars_fcns");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ex_custom_code_global_constants_vars_fcns_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
