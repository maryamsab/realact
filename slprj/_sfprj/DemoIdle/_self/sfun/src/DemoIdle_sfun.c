/* Include files */

#include "DemoIdle_sfun.h"
#include "DemoIdle_sfun_debug_macros.h"
#include "c1_DemoIdle.h"
#include "c2_DemoIdle.h"
#include "c4_DemoIdle.h"
#include "c5_DemoIdle.h"
#include "c8_DemoIdle.h"
#include "c9_DemoIdle.h"
#include "c10_DemoIdle.h"
#include "c11_DemoIdle.h"
#include "c20_DemoIdle.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DemoIdleMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DemoIdle_initializer(void)
{
}

void DemoIdle_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DemoIdle_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_DemoIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DemoIdle_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(676780526U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1612887858U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3205251461U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2150759845U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(850712906U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1739852699U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2045264881U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3100737810U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c1_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c2_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c4_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c5_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c8_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c9_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c10_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c11_DemoIdle_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_DemoIdle_get_check_sum(mxArray *plhs[]);
          sf_c20_DemoIdle_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1390688128U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3279081909U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3882886900U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1190552240U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DemoIdle_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "o5g6GIVF5oOXQprzCtdZmH") == 0) {
          extern mxArray *sf_c1_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c1_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c2_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "GhknfgHd0osuX3CubCHC2F") == 0) {
          extern mxArray *sf_c4_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c4_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "zmGi5j7BVxLp2QNzOklOiD") == 0) {
          extern mxArray *sf_c5_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c5_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "R9vZjgx2VgS2fFoZTpoX9C") == 0) {
          extern mxArray *sf_c8_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c8_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "8e12yyAHB8iW5NtEEZRcpC") == 0) {
          extern mxArray *sf_c9_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c9_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "tERUYKkWJG6VM4uJ1dCQRH") == 0) {
          extern mxArray *sf_c10_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c10_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "nGmPrg6xMbXRzUyN5gZwbB") == 0) {
          extern mxArray *sf_c11_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c11_DemoIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "iFsGdxEBf37MFtb84KlJOB") == 0) {
          extern mxArray *sf_c20_DemoIdle_get_autoinheritance_info(void);
          plhs[0] = sf_c20_DemoIdle_get_autoinheritance_info();
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

unsigned int sf_DemoIdle_get_eml_resolved_functions_info( int nlhs, mxArray *
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
     case 1:
      {
        extern const mxArray *sf_c1_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DemoIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_DemoIdle_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_DemoIdle_get_eml_resolved_functions_info();
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

unsigned int sf_DemoIdle_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "vtunm1bQfsejOkpcAplJs") == 0) {
          extern mxArray *sf_c1_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c1_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c2_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "2kGX0j9WzD5y7kC8vSv3f") == 0) {
          extern mxArray *sf_c4_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c4_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "oHy3OsTNIWPNVlS35XmRNC") == 0) {
          extern mxArray *sf_c5_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c5_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "26UwCRaxb0oH8gqfvEKqVG") == 0) {
          extern mxArray *sf_c8_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c8_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "ik1LKLjDHbqK7slh2MBefC") == 0) {
          extern mxArray *sf_c9_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c9_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "EjuzPTpxHL7hetyxY2aTIB") == 0) {
          extern mxArray *sf_c10_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c10_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7Tjii6EYNdbRCJQAty8xHH") == 0) {
          extern mxArray *sf_c11_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c11_DemoIdle_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "HNBaQgV92kOFMmrijhlljC") == 0) {
          extern mxArray *sf_c20_DemoIdle_third_party_uses_info(void);
          plhs[0] = sf_c20_DemoIdle_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DemoIdle_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        if (strcmp(tpChksum, "vtunm1bQfsejOkpcAplJs") == 0) {
          extern mxArray *sf_c1_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "2kGX0j9WzD5y7kC8vSv3f") == 0) {
          extern mxArray *sf_c4_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "oHy3OsTNIWPNVlS35XmRNC") == 0) {
          extern mxArray *sf_c5_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "26UwCRaxb0oH8gqfvEKqVG") == 0) {
          extern mxArray *sf_c8_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "ik1LKLjDHbqK7slh2MBefC") == 0) {
          extern mxArray *sf_c9_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "EjuzPTpxHL7hetyxY2aTIB") == 0) {
          extern mxArray *sf_c10_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7Tjii6EYNdbRCJQAty8xHH") == 0) {
          extern mxArray *sf_c11_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "HNBaQgV92kOFMmrijhlljC") == 0) {
          extern mxArray *sf_c20_DemoIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_DemoIdle_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void DemoIdle_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _DemoIdleMachineNumber_ = sf_debug_initialize_machine(debugInstance,"DemoIdle",
    "sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_DemoIdleMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_DemoIdleMachineNumber_,0);
}

void DemoIdle_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DemoIdle_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("DemoIdle",
      "DemoIdle");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DemoIdle_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
