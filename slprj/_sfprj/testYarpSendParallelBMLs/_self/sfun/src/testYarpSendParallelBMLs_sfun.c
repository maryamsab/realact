/* Include files */

#include "testYarpSendParallelBMLs_sfun.h"
#include "testYarpSendParallelBMLs_sfun_debug_macros.h"
#include "c2_testYarpSendParallelBMLs.h"
#include "c3_testYarpSendParallelBMLs.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _testYarpSendParallelBMLsMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void testYarpSendParallelBMLs_initializer(void)
{
}

void testYarpSendParallelBMLs_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_testYarpSendParallelBMLs_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==2) {
    c2_testYarpSendParallelBMLs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_testYarpSendParallelBMLs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_testYarpSendParallelBMLs_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2373668279U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4219353327U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(413530216U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3485363608U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1436668762U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4074034425U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(773195574U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1823757258U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_testYarpSendParallelBMLs_get_check_sum(mxArray *
            plhs[]);
          sf_c2_testYarpSendParallelBMLs_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_testYarpSendParallelBMLs_get_check_sum(mxArray *
            plhs[]);
          sf_c3_testYarpSendParallelBMLs_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3793818402U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1558528999U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(257974366U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3914132382U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_testYarpSendParallelBMLs_autoinheritance_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        if (strcmp(aiChksum, "eyxkF46ZvNOP9rySOlhuyC") == 0) {
          extern mxArray
            *sf_c2_testYarpSendParallelBMLs_get_autoinheritance_info(void);
          plhs[0] = sf_c2_testYarpSendParallelBMLs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "mzMqX9WaYtURB192DDAiDH") == 0) {
          extern mxArray
            *sf_c3_testYarpSendParallelBMLs_get_autoinheritance_info(void);
          plhs[0] = sf_c3_testYarpSendParallelBMLs_get_autoinheritance_info();
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

unsigned int sf_testYarpSendParallelBMLs_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        extern const mxArray
          *sf_c2_testYarpSendParallelBMLs_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_testYarpSendParallelBMLs_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_testYarpSendParallelBMLs_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_testYarpSendParallelBMLs_get_eml_resolved_functions_info();
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

unsigned int sf_testYarpSendParallelBMLs_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        if (strcmp(tpChksum, "JemGbqxiR1SQTAW4QEfxdD") == 0) {
          extern mxArray *sf_c2_testYarpSendParallelBMLs_third_party_uses_info
            (void);
          plhs[0] = sf_c2_testYarpSendParallelBMLs_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OuSErtZpbi5X9WVaWewqGE") == 0) {
          extern mxArray *sf_c3_testYarpSendParallelBMLs_third_party_uses_info
            (void);
          plhs[0] = sf_c3_testYarpSendParallelBMLs_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_testYarpSendParallelBMLs_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        if (strcmp(tpChksum, "JemGbqxiR1SQTAW4QEfxdD") == 0) {
          extern mxArray
            *sf_c2_testYarpSendParallelBMLs_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_testYarpSendParallelBMLs_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OuSErtZpbi5X9WVaWewqGE") == 0) {
          extern mxArray
            *sf_c3_testYarpSendParallelBMLs_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_testYarpSendParallelBMLs_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void testYarpSendParallelBMLs_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _testYarpSendParallelBMLsMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"testYarpSendParallelBMLs","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _testYarpSendParallelBMLsMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _testYarpSendParallelBMLsMachineNumber_,0);
}

void testYarpSendParallelBMLs_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_testYarpSendParallelBMLs_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "testYarpSendParallelBMLs", "testYarpSendParallelBMLs");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_testYarpSendParallelBMLs_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
