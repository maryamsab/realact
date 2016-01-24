/* Include files */

#include "Demo_AU_VA_SBM_sfun.h"
#include "Demo_AU_VA_SBM_sfun_debug_macros.h"
#include "c3_Demo_AU_VA_SBM.h"
#include "c50_Demo_AU_VA_SBM.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Demo_AU_VA_SBMMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Demo_AU_VA_SBM_initializer(void)
{
}

void Demo_AU_VA_SBM_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Demo_AU_VA_SBM_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==3) {
    c3_Demo_AU_VA_SBM_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==50) {
    c50_Demo_AU_VA_SBM_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Demo_AU_VA_SBM_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3063124312U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3806327163U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(123533776U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(880454369U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1608820389U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(710517062U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(544430916U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3441292849U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 3:
        {
          extern void sf_c3_Demo_AU_VA_SBM_get_check_sum(mxArray *plhs[]);
          sf_c3_Demo_AU_VA_SBM_get_check_sum(plhs);
          break;
        }

       case 50:
        {
          extern void sf_c50_Demo_AU_VA_SBM_get_check_sum(mxArray *plhs[]);
          sf_c50_Demo_AU_VA_SBM_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3764593566U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4221370873U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(764667225U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2887751434U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Demo_AU_VA_SBM_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "08WMXCt1Uun4dW8X12ptr") == 0) {
          extern mxArray *sf_c3_Demo_AU_VA_SBM_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Demo_AU_VA_SBM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 50:
      {
        if (strcmp(aiChksum, "cte16HTySHfdVb6grwFn2C") == 0) {
          extern mxArray *sf_c50_Demo_AU_VA_SBM_get_autoinheritance_info(void);
          plhs[0] = sf_c50_Demo_AU_VA_SBM_get_autoinheritance_info();
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

unsigned int sf_Demo_AU_VA_SBM_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray
          *sf_c3_Demo_AU_VA_SBM_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Demo_AU_VA_SBM_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 50:
      {
        extern const mxArray
          *sf_c50_Demo_AU_VA_SBM_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c50_Demo_AU_VA_SBM_get_eml_resolved_functions_info();
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

unsigned int sf_Demo_AU_VA_SBM_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "16fFl8UvG7mEWU1IqNDdsE") == 0) {
          extern mxArray *sf_c3_Demo_AU_VA_SBM_third_party_uses_info(void);
          plhs[0] = sf_c3_Demo_AU_VA_SBM_third_party_uses_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "TMNWVoA3KIhTnXOH2yKUx") == 0) {
          extern mxArray *sf_c50_Demo_AU_VA_SBM_third_party_uses_info(void);
          plhs[0] = sf_c50_Demo_AU_VA_SBM_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Demo_AU_VA_SBM_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "16fFl8UvG7mEWU1IqNDdsE") == 0) {
          extern mxArray *sf_c3_Demo_AU_VA_SBM_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Demo_AU_VA_SBM_updateBuildInfo_args_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "TMNWVoA3KIhTnXOH2yKUx") == 0) {
          extern mxArray *sf_c50_Demo_AU_VA_SBM_updateBuildInfo_args_info(void);
          plhs[0] = sf_c50_Demo_AU_VA_SBM_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Demo_AU_VA_SBM_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Demo_AU_VA_SBMMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Demo_AU_VA_SBM","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Demo_AU_VA_SBMMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Demo_AU_VA_SBMMachineNumber_,0);
}

void Demo_AU_VA_SBM_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Demo_AU_VA_SBM_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Demo_AU_VA_SBM",
      "Demo_AU_VA_SBM");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Demo_AU_VA_SBM_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
