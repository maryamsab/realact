/* Include files */

#include "EP_IdleRand_K_sfun.h"
#include "EP_IdleRand_K_sfun_debug_macros.h"
#include "c1_EP_IdleRand_K.h"
#include "c2_EP_IdleRand_K.h"
#include "c4_EP_IdleRand_K.h"
#include "c5_EP_IdleRand_K.h"
#include "c8_EP_IdleRand_K.h"
#include "c9_EP_IdleRand_K.h"
#include "c10_EP_IdleRand_K.h"
#include "c11_EP_IdleRand_K.h"
#include "c12_EP_IdleRand_K.h"
#include "c13_EP_IdleRand_K.h"
#include "c14_EP_IdleRand_K.h"
#include "c17_EP_IdleRand_K.h"
#include "c20_EP_IdleRand_K.h"
#include "c35_EP_IdleRand_K.h"
#include "c37_EP_IdleRand_K.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _EP_IdleRand_KMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void EP_IdleRand_K_initializer(void)
{
}

void EP_IdleRand_K_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_EP_IdleRand_K_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_EP_IdleRand_K_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_EP_IdleRand_K_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(77115894U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1506812709U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2204047950U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1194550564U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3197226534U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(537698133U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1844530734U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3654256676U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c1_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c2_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c4_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c5_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c8_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c9_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c10_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c11_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c12_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c13_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c14_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c17_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c20_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c35_EP_IdleRand_K_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
          sf_c37_EP_IdleRand_K_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3839186423U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2719457945U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1522381613U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1913923147U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EP_IdleRand_K_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "2Dw5M0a1o6K90MYXMrxSQF") == 0) {
          extern mxArray *sf_c1_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c1_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c2_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "WkkcJzD96rfQxhbitAGsUD") == 0) {
          extern mxArray *sf_c4_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c4_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "N73ZAj8pGLVy5PshkMhHME") == 0) {
          extern mxArray *sf_c5_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c5_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "bFtOYAGdW8j9BxoPpEuxKC") == 0) {
          extern mxArray *sf_c8_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c8_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "WGPtqIdVrpKzwRlTSQs9GG") == 0) {
          extern mxArray *sf_c9_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c9_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "dnQZ3y1AFtJmjgTcIQUmr") == 0) {
          extern mxArray *sf_c10_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c10_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "nTMvNUkutCAieCgyZ3kVbE") == 0) {
          extern mxArray *sf_c11_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c11_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "fYXLlKgzW7uVNW4Lri9cRH") == 0) {
          extern mxArray *sf_c12_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c12_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "yPPzDIGn5DPyGYnrHi4YC") == 0) {
          extern mxArray *sf_c13_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c13_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "fbs1NXNu3p3DqJAjoWAIqB") == 0) {
          extern mxArray *sf_c14_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c14_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "VpuJLrkkZFJktQtxLkPKvE") == 0) {
          extern mxArray *sf_c17_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c17_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "6AOa2CHeDSlW1ttLfc2KIC") == 0) {
          extern mxArray *sf_c20_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c20_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 35:
      {
        if (strcmp(aiChksum, "rm17tte3C08PdN1kaNbNDF") == 0) {
          extern mxArray *sf_c35_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c35_EP_IdleRand_K_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "mvMGcuHSeH872pn0xeK8q") == 0) {
          extern mxArray *sf_c37_EP_IdleRand_K_get_autoinheritance_info(void);
          plhs[0] = sf_c37_EP_IdleRand_K_get_autoinheritance_info();
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

unsigned int sf_EP_IdleRand_K_get_eml_resolved_functions_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray
          *sf_c35_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_EP_IdleRand_K_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_EP_IdleRand_K_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_EP_IdleRand_K_get_eml_resolved_functions_info();
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

unsigned int sf_EP_IdleRand_K_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "vyerveepV0TM12Y5tRExdH") == 0) {
          extern mxArray *sf_c1_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c1_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c2_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "tZRaI7fy6Usm17ySSrOoOC") == 0) {
          extern mxArray *sf_c4_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c4_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "KJd81AnleqwcRjXGFfCGf") == 0) {
          extern mxArray *sf_c5_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c5_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray *sf_c8_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c8_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "BnmDJ8cpkBwrJiPYK5BNKD") == 0) {
          extern mxArray *sf_c9_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c9_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "0IiBbrK91QMWhM8gTYN5HD") == 0) {
          extern mxArray *sf_c10_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c10_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "O0CATq6ZL656CCzSstgHK") == 0) {
          extern mxArray *sf_c11_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c11_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "s2QRGfXQoPh1qktycBKyJH") == 0) {
          extern mxArray *sf_c12_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c12_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray *sf_c13_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c13_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray *sf_c14_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c14_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c17_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "9RrbXQ1HzHmxAkSYCVpxEF") == 0) {
          extern mxArray *sf_c20_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c20_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "i8BiCvJGkgztdHYzLrK4TD") == 0) {
          extern mxArray *sf_c35_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c35_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_EP_IdleRand_K_third_party_uses_info(void);
          plhs[0] = sf_c37_EP_IdleRand_K_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_EP_IdleRand_K_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "vyerveepV0TM12Y5tRExdH") == 0) {
          extern mxArray *sf_c1_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "tZRaI7fy6Usm17ySSrOoOC") == 0) {
          extern mxArray *sf_c4_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "KJd81AnleqwcRjXGFfCGf") == 0) {
          extern mxArray *sf_c5_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray *sf_c8_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "BnmDJ8cpkBwrJiPYK5BNKD") == 0) {
          extern mxArray *sf_c9_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "0IiBbrK91QMWhM8gTYN5HD") == 0) {
          extern mxArray *sf_c10_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "O0CATq6ZL656CCzSstgHK") == 0) {
          extern mxArray *sf_c11_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "s2QRGfXQoPh1qktycBKyJH") == 0) {
          extern mxArray *sf_c12_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray *sf_c13_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray *sf_c14_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "9RrbXQ1HzHmxAkSYCVpxEF") == 0) {
          extern mxArray *sf_c20_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "i8BiCvJGkgztdHYzLrK4TD") == 0) {
          extern mxArray *sf_c35_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c35_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_EP_IdleRand_K_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_EP_IdleRand_K_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void EP_IdleRand_K_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _EP_IdleRand_KMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "EP_IdleRand_K","sfun",0,15,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _EP_IdleRand_KMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _EP_IdleRand_KMachineNumber_,0);
}

void EP_IdleRand_K_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_EP_IdleRand_K_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("EP_IdleRand_K",
      "EP_IdleRand_K");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_EP_IdleRand_K_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
