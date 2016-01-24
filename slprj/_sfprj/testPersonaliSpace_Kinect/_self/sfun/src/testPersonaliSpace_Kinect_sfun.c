/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "testPersonaliSpace_Kinect_sfun.h"
#include "testPersonaliSpace_Kinect_sfun_debug_macros.h"
#include "c1_testPersonaliSpace_Kinect.h"
#include "c2_testPersonaliSpace_Kinect.h"
#include "c3_testPersonaliSpace_Kinect.h"
#include "c4_testPersonaliSpace_Kinect.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _testPersonaliSpace_KinectMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void testPersonaliSpace_Kinect_initializer(void)
{
}

void testPersonaliSpace_Kinect_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_testPersonaliSpace_Kinect_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_testPersonaliSpace_Kinect_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_testPersonaliSpace_Kinect_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_testPersonaliSpace_Kinect_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_testPersonaliSpace_Kinect_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_testPersonaliSpace_Kinect_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(194496518U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(264356546U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3877536850U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3796532054U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(330187664U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2991431681U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(865998152U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2532610442U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_testPersonaliSpace_Kinect_get_check_sum(mxArray
            *plhs[]);
          sf_c1_testPersonaliSpace_Kinect_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_testPersonaliSpace_Kinect_get_check_sum(mxArray
            *plhs[]);
          sf_c2_testPersonaliSpace_Kinect_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_testPersonaliSpace_Kinect_get_check_sum(mxArray
            *plhs[]);
          sf_c3_testPersonaliSpace_Kinect_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_testPersonaliSpace_Kinect_get_check_sum(mxArray
            *plhs[]);
          sf_c4_testPersonaliSpace_Kinect_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1872854756U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(781210148U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(355781382U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1759258564U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3385502230U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1760476977U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2205476728U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(308209825U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_testPersonaliSpace_Kinect_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "20ZwQJqDcglDBcFuxEfG2D") == 0) {
          extern mxArray
            *sf_c1_testPersonaliSpace_Kinect_get_autoinheritance_info(void);
          plhs[0] = sf_c1_testPersonaliSpace_Kinect_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "q7zoKb2PYssm0FsycxJhm") == 0) {
          extern mxArray
            *sf_c2_testPersonaliSpace_Kinect_get_autoinheritance_info(void);
          plhs[0] = sf_c2_testPersonaliSpace_Kinect_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "G8MQi7KKfpwgD5BZDBuMJG") == 0) {
          extern mxArray
            *sf_c3_testPersonaliSpace_Kinect_get_autoinheritance_info(void);
          plhs[0] = sf_c3_testPersonaliSpace_Kinect_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "1sDlQUoTMwGBRp1rM4IFk") == 0) {
          extern mxArray
            *sf_c4_testPersonaliSpace_Kinect_get_autoinheritance_info(void);
          plhs[0] = sf_c4_testPersonaliSpace_Kinect_get_autoinheritance_info();
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

unsigned int sf_testPersonaliSpace_Kinect_get_eml_resolved_functions_info( int
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
          *sf_c1_testPersonaliSpace_Kinect_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_testPersonaliSpace_Kinect_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_testPersonaliSpace_Kinect_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_testPersonaliSpace_Kinect_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_testPersonaliSpace_Kinect_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_testPersonaliSpace_Kinect_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_testPersonaliSpace_Kinect_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_testPersonaliSpace_Kinect_get_eml_resolved_functions_info();
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

unsigned int sf_testPersonaliSpace_Kinect_third_party_uses_info( int nlhs,
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
     case 1:
      {
        if (strcmp(tpChksum, "qRzlKPBYSqB3KYmTjRUHDF") == 0) {
          extern mxArray *sf_c1_testPersonaliSpace_Kinect_third_party_uses_info
            (void);
          plhs[0] = sf_c1_testPersonaliSpace_Kinect_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray *sf_c2_testPersonaliSpace_Kinect_third_party_uses_info
            (void);
          plhs[0] = sf_c2_testPersonaliSpace_Kinect_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "SgJRddNap3xCREnB5UCpDG") == 0) {
          extern mxArray *sf_c3_testPersonaliSpace_Kinect_third_party_uses_info
            (void);
          plhs[0] = sf_c3_testPersonaliSpace_Kinect_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "zC38CYojUa54HLCXr4BmkG") == 0) {
          extern mxArray *sf_c4_testPersonaliSpace_Kinect_third_party_uses_info
            (void);
          plhs[0] = sf_c4_testPersonaliSpace_Kinect_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_testPersonaliSpace_Kinect_updateBuildInfo_args_info( int nlhs,
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
        if (strcmp(tpChksum, "qRzlKPBYSqB3KYmTjRUHDF") == 0) {
          extern mxArray
            *sf_c1_testPersonaliSpace_Kinect_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_testPersonaliSpace_Kinect_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray
            *sf_c2_testPersonaliSpace_Kinect_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_testPersonaliSpace_Kinect_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "SgJRddNap3xCREnB5UCpDG") == 0) {
          extern mxArray
            *sf_c3_testPersonaliSpace_Kinect_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_testPersonaliSpace_Kinect_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "zC38CYojUa54HLCXr4BmkG") == 0) {
          extern mxArray
            *sf_c4_testPersonaliSpace_Kinect_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_testPersonaliSpace_Kinect_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void testPersonaliSpace_Kinect_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _testPersonaliSpace_KinectMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"testPersonaliSpace_Kinect","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _testPersonaliSpace_KinectMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _testPersonaliSpace_KinectMachineNumber_,0);
}

void testPersonaliSpace_Kinect_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_testPersonaliSpace_Kinect_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "testPersonaliSpace_Kinect", "testPersonaliSpace_Kinect");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_testPersonaliSpace_Kinect_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
