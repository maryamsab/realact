/* Include files */

#include "Demo_AUV_VA_sfun.h"
#include "Demo_AUV_VA_sfun_debug_macros.h"
#include "c3_Demo_AUV_VA.h"
#include "c5_Demo_AUV_VA.h"
#include "c50_Demo_AUV_VA.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Demo_AUV_VAMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Demo_AUV_VA_initializer(void)
{
}

void Demo_AUV_VA_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Demo_AUV_VA_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==3) {
    c3_Demo_AUV_VA_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Demo_AUV_VA_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==50) {
    c50_Demo_AUV_VA_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Demo_AUV_VA_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2391726798U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1956375919U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1926795072U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4211707671U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3648835393U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(914642215U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2839931668U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4148528630U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 3:
        {
          extern void sf_c3_Demo_AUV_VA_get_check_sum(mxArray *plhs[]);
          sf_c3_Demo_AUV_VA_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Demo_AUV_VA_get_check_sum(mxArray *plhs[]);
          sf_c5_Demo_AUV_VA_get_check_sum(plhs);
          break;
        }

       case 50:
        {
          extern void sf_c50_Demo_AUV_VA_get_check_sum(mxArray *plhs[]);
          sf_c50_Demo_AUV_VA_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(814460797U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(400623215U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1072597456U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1176453921U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1006424037U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1415672765U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2558822506U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3932457238U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Demo_AUV_VA_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        if (strcmp(aiChksum, "W2QAnd1V0oLORJHN6SXouF") == 0) {
          extern mxArray *sf_c3_Demo_AUV_VA_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Demo_AUV_VA_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "DsGiFVf3BSSsPxOzqVwzkE") == 0) {
          extern mxArray *sf_c5_Demo_AUV_VA_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Demo_AUV_VA_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 50:
      {
        if (strcmp(aiChksum, "SEoRvwdStvlMvt7ojSiHxE") == 0) {
          extern mxArray *sf_c50_Demo_AUV_VA_get_autoinheritance_info(void);
          plhs[0] = sf_c50_Demo_AUV_VA_get_autoinheritance_info();
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

unsigned int sf_Demo_AUV_VA_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        extern const mxArray *sf_c3_Demo_AUV_VA_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Demo_AUV_VA_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_Demo_AUV_VA_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Demo_AUV_VA_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 50:
      {
        extern const mxArray *sf_c50_Demo_AUV_VA_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c50_Demo_AUV_VA_get_eml_resolved_functions_info();
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

unsigned int sf_Demo_AUV_VA_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        if (strcmp(tpChksum, "WSYnY9tUn40gspSVZIYotC") == 0) {
          extern mxArray *sf_c3_Demo_AUV_VA_third_party_uses_info(void);
          plhs[0] = sf_c3_Demo_AUV_VA_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "94EHSMjC42UJTIOKUCRIaE") == 0) {
          extern mxArray *sf_c5_Demo_AUV_VA_third_party_uses_info(void);
          plhs[0] = sf_c5_Demo_AUV_VA_third_party_uses_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "6DtY0OqpqXQhFzePhHANIF") == 0) {
          extern mxArray *sf_c50_Demo_AUV_VA_third_party_uses_info(void);
          plhs[0] = sf_c50_Demo_AUV_VA_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Demo_AUV_VA_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        if (strcmp(tpChksum, "WSYnY9tUn40gspSVZIYotC") == 0) {
          extern mxArray *sf_c3_Demo_AUV_VA_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Demo_AUV_VA_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "94EHSMjC42UJTIOKUCRIaE") == 0) {
          extern mxArray *sf_c5_Demo_AUV_VA_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Demo_AUV_VA_updateBuildInfo_args_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "6DtY0OqpqXQhFzePhHANIF") == 0) {
          extern mxArray *sf_c50_Demo_AUV_VA_updateBuildInfo_args_info(void);
          plhs[0] = sf_c50_Demo_AUV_VA_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Demo_AUV_VA_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Demo_AUV_VAMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Demo_AUV_VA","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_Demo_AUV_VAMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_Demo_AUV_VAMachineNumber_,
    0);
}

void Demo_AUV_VA_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Demo_AUV_VA_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Demo_AUV_VA",
      "Demo_AUV_VA");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Demo_AUV_VA_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
