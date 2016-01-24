/* Include files */

#include "DemoGazeFollowWaveIdle_sfun.h"
#include "DemoGazeFollowWaveIdle_sfun_debug_macros.h"
#include "c1_DemoGazeFollowWaveIdle.h"
#include "c2_DemoGazeFollowWaveIdle.h"
#include "c4_DemoGazeFollowWaveIdle.h"
#include "c5_DemoGazeFollowWaveIdle.h"
#include "c8_DemoGazeFollowWaveIdle.h"
#include "c9_DemoGazeFollowWaveIdle.h"
#include "c10_DemoGazeFollowWaveIdle.h"
#include "c11_DemoGazeFollowWaveIdle.h"
#include "c17_DemoGazeFollowWaveIdle.h"
#include "c20_DemoGazeFollowWaveIdle.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DemoGazeFollowWaveIdleMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DemoGazeFollowWaveIdle_initializer(void)
{
}

void DemoGazeFollowWaveIdle_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DemoGazeFollowWaveIdle_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_DemoGazeFollowWaveIdle_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DemoGazeFollowWaveIdle_process_check_sum_call( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(678997027U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(359700050U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2474638056U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(352808645U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2312545740U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2890452421U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2985884741U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3895426956U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c1_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c2_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c4_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c5_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c8_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c9_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c10_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c11_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c17_DemoGazeFollowWaveIdle_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
          sf_c20_DemoGazeFollowWaveIdle_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1121677353U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2943505421U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3489307995U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3916269187U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DemoGazeFollowWaveIdle_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "XEfbo21zVQOn91Kb6PnqHD") == 0) {
          extern mxArray *sf_c1_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "GhknfgHd0osuX3CubCHC2F") == 0) {
          extern mxArray *sf_c4_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "JXOCJGwHetEU0K1fn89Di") == 0) {
          extern mxArray *sf_c5_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "bFtOYAGdW8j9BxoPpEuxKC") == 0) {
          extern mxArray *sf_c8_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "WfUfYn0eiLEmOdXs8wmXb") == 0) {
          extern mxArray *sf_c9_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "xxkNGChDflDrWWfbQBqRE") == 0) {
          extern mxArray *sf_c10_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "LMaw6Foqj8VwBeBsFx1sQH") == 0) {
          extern mxArray *sf_c11_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "NXVeltQjg4PvjVsETVb4WE") == 0) {
          extern mxArray *sf_c17_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c17_DemoGazeFollowWaveIdle_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "yeRDJ7gwXhKRz6v00P54HF") == 0) {
          extern mxArray *sf_c20_DemoGazeFollowWaveIdle_get_autoinheritance_info
            (void);
          plhs[0] = sf_c20_DemoGazeFollowWaveIdle_get_autoinheritance_info();
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

unsigned int sf_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info( int nlhs,
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
     case 1:
      {
        extern const mxArray
          *sf_c1_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info();
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

unsigned int sf_DemoGazeFollowWaveIdle_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "4ZTCwAmMOsGP9y8sTH8pxE") == 0) {
          extern mxArray *sf_c1_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c1_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c2_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "2kGX0j9WzD5y7kC8vSv3f") == 0) {
          extern mxArray *sf_c4_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c4_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "xCtif4NLkQJSjuDDgN407G") == 0) {
          extern mxArray *sf_c5_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c5_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray *sf_c8_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c8_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "x0UbITq2NggXAVmvaX41HB") == 0) {
          extern mxArray *sf_c9_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c9_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "x4XoHyulE6A6JDEmygUxxF") == 0) {
          extern mxArray *sf_c10_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c10_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bxsvd4uU17MMyI9AvQ68rH") == 0) {
          extern mxArray *sf_c11_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c11_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "CX0smq9DsvPN01F4gVOgo") == 0) {
          extern mxArray *sf_c17_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c17_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "1MgLDOtHxNYpRPXqx5mle") == 0) {
          extern mxArray *sf_c20_DemoGazeFollowWaveIdle_third_party_uses_info
            (void);
          plhs[0] = sf_c20_DemoGazeFollowWaveIdle_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DemoGazeFollowWaveIdle_updateBuildInfo_args_info( int nlhs,
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
        if (strcmp(tpChksum, "4ZTCwAmMOsGP9y8sTH8pxE") == 0) {
          extern mxArray *sf_c1_DemoGazeFollowWaveIdle_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_DemoGazeFollowWaveIdle_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "2kGX0j9WzD5y7kC8vSv3f") == 0) {
          extern mxArray *sf_c4_DemoGazeFollowWaveIdle_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "xCtif4NLkQJSjuDDgN407G") == 0) {
          extern mxArray *sf_c5_DemoGazeFollowWaveIdle_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray *sf_c8_DemoGazeFollowWaveIdle_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c8_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "x0UbITq2NggXAVmvaX41HB") == 0) {
          extern mxArray *sf_c9_DemoGazeFollowWaveIdle_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c9_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "x4XoHyulE6A6JDEmygUxxF") == 0) {
          extern mxArray
            *sf_c10_DemoGazeFollowWaveIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bxsvd4uU17MMyI9AvQ68rH") == 0) {
          extern mxArray
            *sf_c11_DemoGazeFollowWaveIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "CX0smq9DsvPN01F4gVOgo") == 0) {
          extern mxArray
            *sf_c17_DemoGazeFollowWaveIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "1MgLDOtHxNYpRPXqx5mle") == 0) {
          extern mxArray
            *sf_c20_DemoGazeFollowWaveIdle_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_DemoGazeFollowWaveIdle_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void DemoGazeFollowWaveIdle_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _DemoGazeFollowWaveIdleMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"DemoGazeFollowWaveIdle","sfun",0,10,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _DemoGazeFollowWaveIdleMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _DemoGazeFollowWaveIdleMachineNumber_,0);
}

void DemoGazeFollowWaveIdle_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DemoGazeFollowWaveIdle_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "DemoGazeFollowWaveIdle", "DemoGazeFollowWaveIdle");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DemoGazeFollowWaveIdle_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
