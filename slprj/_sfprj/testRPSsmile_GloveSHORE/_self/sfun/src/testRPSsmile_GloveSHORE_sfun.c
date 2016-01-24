/* Include files */

#include "testRPSsmile_GloveSHORE_sfun.h"
#include "testRPSsmile_GloveSHORE_sfun_debug_macros.h"
#include "c1_testRPSsmile_GloveSHORE.h"
#include "c2_testRPSsmile_GloveSHORE.h"
#include "c3_testRPSsmile_GloveSHORE.h"
#include "c4_testRPSsmile_GloveSHORE.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _testRPSsmile_GloveSHOREMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void testRPSsmile_GloveSHORE_initializer(void)
{
}

void testRPSsmile_GloveSHORE_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_testRPSsmile_GloveSHORE_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_testRPSsmile_GloveSHORE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_testRPSsmile_GloveSHORE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_testRPSsmile_GloveSHORE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_testRPSsmile_GloveSHORE_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_testRPSsmile_GloveSHORE_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1338936183U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3341266707U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1905299535U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2072910404U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2021522809U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1233758946U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2264930924U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3237104993U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_testRPSsmile_GloveSHORE_get_check_sum(mxArray *plhs[]);
          sf_c1_testRPSsmile_GloveSHORE_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_testRPSsmile_GloveSHORE_get_check_sum(mxArray *plhs[]);
          sf_c2_testRPSsmile_GloveSHORE_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_testRPSsmile_GloveSHORE_get_check_sum(mxArray *plhs[]);
          sf_c3_testRPSsmile_GloveSHORE_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_testRPSsmile_GloveSHORE_get_check_sum(mxArray *plhs[]);
          sf_c4_testRPSsmile_GloveSHORE_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3631444906U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1375517235U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1750316125U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(284886239U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1180512304U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(659693359U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2963048254U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2321856220U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_testRPSsmile_GloveSHORE_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "UTtyFXPBdAWOYpj6X6peDD") == 0) {
          extern mxArray *sf_c1_testRPSsmile_GloveSHORE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_testRPSsmile_GloveSHORE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "5qrLGjGP1vIkrom2MMIbKD") == 0) {
          extern mxArray *sf_c2_testRPSsmile_GloveSHORE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_testRPSsmile_GloveSHORE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "6ToljhSGzQbPoAkW7t0cfB") == 0) {
          extern mxArray *sf_c3_testRPSsmile_GloveSHORE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_testRPSsmile_GloveSHORE_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "DtjMk7SqhwV5BFq0nnUQoE") == 0) {
          extern mxArray *sf_c4_testRPSsmile_GloveSHORE_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_testRPSsmile_GloveSHORE_get_autoinheritance_info();
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

unsigned int sf_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info( int
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
     case 1:
      {
        extern const mxArray
          *sf_c1_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_testRPSsmile_GloveSHORE_get_eml_resolved_functions_info();
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

unsigned int sf_testRPSsmile_GloveSHORE_third_party_uses_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "KLKedEhNXVORelPJMymwUH") == 0) {
          extern mxArray *sf_c1_testRPSsmile_GloveSHORE_third_party_uses_info
            (void);
          plhs[0] = sf_c1_testRPSsmile_GloveSHORE_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "0jGUY2zLfEmy84SXNG14QD") == 0) {
          extern mxArray *sf_c2_testRPSsmile_GloveSHORE_third_party_uses_info
            (void);
          plhs[0] = sf_c2_testRPSsmile_GloveSHORE_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray *sf_c3_testRPSsmile_GloveSHORE_third_party_uses_info
            (void);
          plhs[0] = sf_c3_testRPSsmile_GloveSHORE_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "PBF1XeoWbqG4ePndV3MmgF") == 0) {
          extern mxArray *sf_c4_testRPSsmile_GloveSHORE_third_party_uses_info
            (void);
          plhs[0] = sf_c4_testRPSsmile_GloveSHORE_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_testRPSsmile_GloveSHORE_updateBuildInfo_args_info( int nlhs,
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
     case 1:
      {
        if (strcmp(tpChksum, "KLKedEhNXVORelPJMymwUH") == 0) {
          extern mxArray
            *sf_c1_testRPSsmile_GloveSHORE_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_testRPSsmile_GloveSHORE_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "0jGUY2zLfEmy84SXNG14QD") == 0) {
          extern mxArray
            *sf_c2_testRPSsmile_GloveSHORE_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_testRPSsmile_GloveSHORE_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray
            *sf_c3_testRPSsmile_GloveSHORE_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_testRPSsmile_GloveSHORE_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "PBF1XeoWbqG4ePndV3MmgF") == 0) {
          extern mxArray
            *sf_c4_testRPSsmile_GloveSHORE_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_testRPSsmile_GloveSHORE_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void testRPSsmile_GloveSHORE_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _testRPSsmile_GloveSHOREMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"testRPSsmile_GloveSHORE","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _testRPSsmile_GloveSHOREMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _testRPSsmile_GloveSHOREMachineNumber_,0);
}

void testRPSsmile_GloveSHORE_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_testRPSsmile_GloveSHORE_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "testRPSsmile_GloveSHORE", "testRPSsmile_GloveSHORE");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_testRPSsmile_GloveSHORE_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
