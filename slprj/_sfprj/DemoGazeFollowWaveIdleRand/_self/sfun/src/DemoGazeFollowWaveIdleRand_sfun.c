/* Include files */

#include "DemoGazeFollowWaveIdleRand_sfun.h"
#include "DemoGazeFollowWaveIdleRand_sfun_debug_macros.h"
#include "c1_DemoGazeFollowWaveIdleRand.h"
#include "c2_DemoGazeFollowWaveIdleRand.h"
#include "c4_DemoGazeFollowWaveIdleRand.h"
#include "c5_DemoGazeFollowWaveIdleRand.h"
#include "c6_DemoGazeFollowWaveIdleRand.h"
#include "c8_DemoGazeFollowWaveIdleRand.h"
#include "c9_DemoGazeFollowWaveIdleRand.h"
#include "c10_DemoGazeFollowWaveIdleRand.h"
#include "c11_DemoGazeFollowWaveIdleRand.h"
#include "c15_DemoGazeFollowWaveIdleRand.h"
#include "c16_DemoGazeFollowWaveIdleRand.h"
#include "c17_DemoGazeFollowWaveIdleRand.h"
#include "c19_DemoGazeFollowWaveIdleRand.h"
#include "c20_DemoGazeFollowWaveIdleRand.h"
#include "c21_DemoGazeFollowWaveIdleRand.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DemoGazeFollowWaveIdleRandMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DemoGazeFollowWaveIdleRand_initializer(void)
{
}

void DemoGazeFollowWaveIdleRand_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DemoGazeFollowWaveIdleRand_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_DemoGazeFollowWaveIdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DemoGazeFollowWaveIdleRand_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1184715255U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3618218777U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2473523015U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3850929555U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1962439011U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3790470514U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1570554848U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2862135733U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c1_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c2_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c4_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c5_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c6_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c8_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c9_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c10_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c11_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c15_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c16_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c17_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c19_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c20_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray
            *plhs[]);
          sf_c21_DemoGazeFollowWaveIdleRand_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1973276084U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(290091765U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2667792411U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2739425996U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DemoGazeFollowWaveIdleRand_autoinheritance_info( int nlhs,
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
        if (strcmp(aiChksum, "XEfbo21zVQOn91Kb6PnqHD") == 0) {
          extern mxArray
            *sf_c1_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c1_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray
            *sf_c2_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c2_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "wrM5H8R7xniY0vcAIvJMbC") == 0) {
          extern mxArray
            *sf_c4_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c4_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "STYvhzdlCUcb4w0Hk7qYsF") == 0) {
          extern mxArray
            *sf_c5_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c5_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "q7zoKb2PYssm0FsycxJhm") == 0) {
          extern mxArray
            *sf_c6_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c6_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "bFtOYAGdW8j9BxoPpEuxKC") == 0) {
          extern mxArray
            *sf_c8_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c8_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "6KbpQaiXCPjoYdSZc7WEXH") == 0) {
          extern mxArray
            *sf_c9_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c9_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "gol3CArZQO7XbK4XL3kFbH") == 0) {
          extern mxArray
            *sf_c10_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c10_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "LMaw6Foqj8VwBeBsFx1sQH") == 0) {
          extern mxArray
            *sf_c11_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c11_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "nXZRq3E4ZUB2RMzRpUECK") == 0) {
          extern mxArray
            *sf_c15_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c15_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "e33uQC3qcj4cOwFIj0zQwG") == 0) {
          extern mxArray
            *sf_c16_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c16_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "NXVeltQjg4PvjVsETVb4WE") == 0) {
          extern mxArray
            *sf_c17_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c17_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "P1Nlcknnajj8uxt0Z0wMqF") == 0) {
          extern mxArray
            *sf_c19_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c19_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "yeRDJ7gwXhKRz6v00P54HF") == 0) {
          extern mxArray
            *sf_c20_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c20_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "Gc7VntGn8cYPPsAqjM8CnG") == 0) {
          extern mxArray
            *sf_c21_DemoGazeFollowWaveIdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c21_DemoGazeFollowWaveIdleRand_get_autoinheritance_info();
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

unsigned int sf_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info( int
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
          *sf_c1_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info();
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

unsigned int sf_DemoGazeFollowWaveIdleRand_third_party_uses_info( int nlhs,
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
        if (strcmp(tpChksum, "4ZTCwAmMOsGP9y8sTH8pxE") == 0) {
          extern mxArray *sf_c1_DemoGazeFollowWaveIdleRand_third_party_uses_info
            (void);
          plhs[0] = sf_c1_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_DemoGazeFollowWaveIdleRand_third_party_uses_info
            (void);
          plhs[0] = sf_c2_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "bQybm8wmY781OpH7vA5q7G") == 0) {
          extern mxArray *sf_c4_DemoGazeFollowWaveIdleRand_third_party_uses_info
            (void);
          plhs[0] = sf_c4_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "kk4t0Q4v90rfCMF5Dnnh1C") == 0) {
          extern mxArray *sf_c5_DemoGazeFollowWaveIdleRand_third_party_uses_info
            (void);
          plhs[0] = sf_c5_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray *sf_c6_DemoGazeFollowWaveIdleRand_third_party_uses_info
            (void);
          plhs[0] = sf_c6_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray *sf_c8_DemoGazeFollowWaveIdleRand_third_party_uses_info
            (void);
          plhs[0] = sf_c8_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "n4JD33Jgz8sUcsNNscEdRF") == 0) {
          extern mxArray *sf_c9_DemoGazeFollowWaveIdleRand_third_party_uses_info
            (void);
          plhs[0] = sf_c9_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a3lfIi16aq97CuUTFB0ncC") == 0) {
          extern mxArray
            *sf_c10_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c10_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bxsvd4uU17MMyI9AvQ68rH") == 0) {
          extern mxArray
            *sf_c11_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c11_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "UhzuqpsAzlsRfgj8i0QCiH") == 0) {
          extern mxArray
            *sf_c15_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c15_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OPOgCUcYOgC76AebRWn6OC") == 0) {
          extern mxArray
            *sf_c16_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c16_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "CX0smq9DsvPN01F4gVOgo") == 0) {
          extern mxArray
            *sf_c17_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c17_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "AlGocMr3QfHKX8uRlIaLKB") == 0) {
          extern mxArray
            *sf_c19_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c19_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "1MgLDOtHxNYpRPXqx5mle") == 0) {
          extern mxArray
            *sf_c20_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c20_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "IrJx1HAbJxOP0GUtSY6MKC") == 0) {
          extern mxArray
            *sf_c21_DemoGazeFollowWaveIdleRand_third_party_uses_info(void);
          plhs[0] = sf_c21_DemoGazeFollowWaveIdleRand_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info( int nlhs,
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
          extern mxArray
            *sf_c1_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray
            *sf_c2_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "bQybm8wmY781OpH7vA5q7G") == 0) {
          extern mxArray
            *sf_c4_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "kk4t0Q4v90rfCMF5Dnnh1C") == 0) {
          extern mxArray
            *sf_c5_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray
            *sf_c6_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray
            *sf_c8_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "n4JD33Jgz8sUcsNNscEdRF") == 0) {
          extern mxArray
            *sf_c9_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a3lfIi16aq97CuUTFB0ncC") == 0) {
          extern mxArray
            *sf_c10_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bxsvd4uU17MMyI9AvQ68rH") == 0) {
          extern mxArray
            *sf_c11_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "UhzuqpsAzlsRfgj8i0QCiH") == 0) {
          extern mxArray
            *sf_c15_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OPOgCUcYOgC76AebRWn6OC") == 0) {
          extern mxArray
            *sf_c16_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "CX0smq9DsvPN01F4gVOgo") == 0) {
          extern mxArray
            *sf_c17_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "AlGocMr3QfHKX8uRlIaLKB") == 0) {
          extern mxArray
            *sf_c19_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "1MgLDOtHxNYpRPXqx5mle") == 0) {
          extern mxArray
            *sf_c20_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "IrJx1HAbJxOP0GUtSY6MKC") == 0) {
          extern mxArray
            *sf_c21_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_DemoGazeFollowWaveIdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void DemoGazeFollowWaveIdleRand_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _DemoGazeFollowWaveIdleRandMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"DemoGazeFollowWaveIdleRand","sfun",0,15,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _DemoGazeFollowWaveIdleRandMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _DemoGazeFollowWaveIdleRandMachineNumber_,0);
}

void DemoGazeFollowWaveIdleRand_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DemoGazeFollowWaveIdleRand_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "DemoGazeFollowWaveIdleRand", "DemoGazeFollowWaveIdleRand");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DemoGazeFollowWaveIdleRand_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
