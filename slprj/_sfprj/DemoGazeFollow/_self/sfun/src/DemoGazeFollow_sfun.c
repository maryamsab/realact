/* Include files */

#include "DemoGazeFollow_sfun.h"
#include "DemoGazeFollow_sfun_debug_macros.h"
#include "c1_DemoGazeFollow.h"
#include "c2_DemoGazeFollow.h"
#include "c4_DemoGazeFollow.h"
#include "c5_DemoGazeFollow.h"
#include "c6_DemoGazeFollow.h"
#include "c8_DemoGazeFollow.h"
#include "c9_DemoGazeFollow.h"
#include "c10_DemoGazeFollow.h"
#include "c11_DemoGazeFollow.h"
#include "c15_DemoGazeFollow.h"
#include "c16_DemoGazeFollow.h"
#include "c19_DemoGazeFollow.h"
#include "c20_DemoGazeFollow.h"
#include "c21_DemoGazeFollow.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DemoGazeFollowMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DemoGazeFollow_initializer(void)
{
}

void DemoGazeFollow_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DemoGazeFollow_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_DemoGazeFollow_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DemoGazeFollow_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3821272030U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1824191980U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2815444094U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3744344601U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4054026364U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2315611562U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(92893663U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4027904739U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c1_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c2_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c4_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c5_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c6_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c8_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c9_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c10_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c11_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c15_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c16_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c19_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c20_DemoGazeFollow_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
          sf_c21_DemoGazeFollow_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2756343245U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2606311165U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(390919581U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2521435926U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DemoGazeFollow_autoinheritance_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        if (strcmp(aiChksum, "o5g6GIVF5oOXQprzCtdZmH") == 0) {
          extern mxArray *sf_c1_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c1_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c2_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "GhknfgHd0osuX3CubCHC2F") == 0) {
          extern mxArray *sf_c4_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c4_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "zmGi5j7BVxLp2QNzOklOiD") == 0) {
          extern mxArray *sf_c5_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c5_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "q7zoKb2PYssm0FsycxJhm") == 0) {
          extern mxArray *sf_c6_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c6_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "R9vZjgx2VgS2fFoZTpoX9C") == 0) {
          extern mxArray *sf_c8_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c8_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "uF58Kdwk7GdbkcZmRKQCZE") == 0) {
          extern mxArray *sf_c9_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c9_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "4CyxNDpiNO5Tc3XwdccAUC") == 0) {
          extern mxArray *sf_c10_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c10_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "uHxvM0lVpa7Exw2UfbQNCB") == 0) {
          extern mxArray *sf_c11_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c11_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "nXZRq3E4ZUB2RMzRpUECK") == 0) {
          extern mxArray *sf_c15_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c15_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "e33uQC3qcj4cOwFIj0zQwG") == 0) {
          extern mxArray *sf_c16_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c16_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "P1Nlcknnajj8uxt0Z0wMqF") == 0) {
          extern mxArray *sf_c19_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c19_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "iFsGdxEBf37MFtb84KlJOB") == 0) {
          extern mxArray *sf_c20_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c20_DemoGazeFollow_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "Gc7VntGn8cYPPsAqjM8CnG") == 0) {
          extern mxArray *sf_c21_DemoGazeFollow_get_autoinheritance_info(void);
          plhs[0] = sf_c21_DemoGazeFollow_get_autoinheritance_info();
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

unsigned int sf_DemoGazeFollow_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_DemoGazeFollow_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_DemoGazeFollow_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_DemoGazeFollow_get_eml_resolved_functions_info();
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

unsigned int sf_DemoGazeFollow_third_party_uses_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        if (strcmp(tpChksum, "vtunm1bQfsejOkpcAplJs") == 0) {
          extern mxArray *sf_c1_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c1_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c2_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "2kGX0j9WzD5y7kC8vSv3f") == 0) {
          extern mxArray *sf_c4_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c4_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "oHy3OsTNIWPNVlS35XmRNC") == 0) {
          extern mxArray *sf_c5_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c5_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray *sf_c6_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c6_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "26UwCRaxb0oH8gqfvEKqVG") == 0) {
          extern mxArray *sf_c8_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c8_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "m6ja8O2TXHsAASQa3slejG") == 0) {
          extern mxArray *sf_c9_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c9_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "x4XoHyulE6A6JDEmygUxxF") == 0) {
          extern mxArray *sf_c10_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c10_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "6URMiqk6YLA45e152L678F") == 0) {
          extern mxArray *sf_c11_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c11_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "UhzuqpsAzlsRfgj8i0QCiH") == 0) {
          extern mxArray *sf_c15_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c15_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OPOgCUcYOgC76AebRWn6OC") == 0) {
          extern mxArray *sf_c16_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c16_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "AlGocMr3QfHKX8uRlIaLKB") == 0) {
          extern mxArray *sf_c19_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c19_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "HNBaQgV92kOFMmrijhlljC") == 0) {
          extern mxArray *sf_c20_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c20_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "IrJx1HAbJxOP0GUtSY6MKC") == 0) {
          extern mxArray *sf_c21_DemoGazeFollow_third_party_uses_info(void);
          plhs[0] = sf_c21_DemoGazeFollow_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DemoGazeFollow_updateBuildInfo_args_info( int nlhs, mxArray *
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
     case 1:
      {
        if (strcmp(tpChksum, "vtunm1bQfsejOkpcAplJs") == 0) {
          extern mxArray *sf_c1_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "2kGX0j9WzD5y7kC8vSv3f") == 0) {
          extern mxArray *sf_c4_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "oHy3OsTNIWPNVlS35XmRNC") == 0) {
          extern mxArray *sf_c5_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray *sf_c6_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "26UwCRaxb0oH8gqfvEKqVG") == 0) {
          extern mxArray *sf_c8_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "m6ja8O2TXHsAASQa3slejG") == 0) {
          extern mxArray *sf_c9_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "x4XoHyulE6A6JDEmygUxxF") == 0) {
          extern mxArray *sf_c10_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "6URMiqk6YLA45e152L678F") == 0) {
          extern mxArray *sf_c11_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "UhzuqpsAzlsRfgj8i0QCiH") == 0) {
          extern mxArray *sf_c15_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OPOgCUcYOgC76AebRWn6OC") == 0) {
          extern mxArray *sf_c16_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "AlGocMr3QfHKX8uRlIaLKB") == 0) {
          extern mxArray *sf_c19_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "HNBaQgV92kOFMmrijhlljC") == 0) {
          extern mxArray *sf_c20_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "IrJx1HAbJxOP0GUtSY6MKC") == 0) {
          extern mxArray *sf_c21_DemoGazeFollow_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_DemoGazeFollow_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void DemoGazeFollow_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _DemoGazeFollowMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "DemoGazeFollow","sfun",0,14,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _DemoGazeFollowMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _DemoGazeFollowMachineNumber_,0);
}

void DemoGazeFollow_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DemoGazeFollow_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("DemoGazeFollow",
      "DemoGazeFollow");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DemoGazeFollow_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
