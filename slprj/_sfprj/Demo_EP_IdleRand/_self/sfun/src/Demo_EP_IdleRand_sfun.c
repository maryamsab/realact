/* Include files */

#include "Demo_EP_IdleRand_sfun.h"
#include "Demo_EP_IdleRand_sfun_debug_macros.h"
#include "c1_Demo_EP_IdleRand.h"
#include "c2_Demo_EP_IdleRand.h"
#include "c4_Demo_EP_IdleRand.h"
#include "c5_Demo_EP_IdleRand.h"
#include "c8_Demo_EP_IdleRand.h"
#include "c9_Demo_EP_IdleRand.h"
#include "c10_Demo_EP_IdleRand.h"
#include "c11_Demo_EP_IdleRand.h"
#include "c12_Demo_EP_IdleRand.h"
#include "c13_Demo_EP_IdleRand.h"
#include "c14_Demo_EP_IdleRand.h"
#include "c17_Demo_EP_IdleRand.h"
#include "c20_Demo_EP_IdleRand.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Demo_EP_IdleRandMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Demo_EP_IdleRand_initializer(void)
{
}

void Demo_EP_IdleRand_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Demo_EP_IdleRand_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Demo_EP_IdleRand_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Demo_EP_IdleRand_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1122981792U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2400119001U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1109719860U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2608471570U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1058983369U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2618325978U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3605742526U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(531177856U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c1_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c2_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c4_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c5_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c8_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c9_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c10_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c11_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c12_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c13_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c14_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c17_Demo_EP_IdleRand_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
          sf_c20_Demo_EP_IdleRand_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(111952429U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4111076263U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2990310076U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2956131843U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Demo_EP_IdleRand_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "TJU8FWeBLbkoq9sWmDbmxG") == 0) {
          extern mxArray *sf_c1_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "WkkcJzD96rfQxhbitAGsUD") == 0) {
          extern mxArray *sf_c4_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "DLW54M1ZNRS9BduaIHTtT") == 0) {
          extern mxArray *sf_c5_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "bFtOYAGdW8j9BxoPpEuxKC") == 0) {
          extern mxArray *sf_c8_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c8_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "0ZzzTjkjOlvsa9HSW7j8vB") == 0) {
          extern mxArray *sf_c9_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c9_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "dnQZ3y1AFtJmjgTcIQUmr") == 0) {
          extern mxArray *sf_c10_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c10_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "9lfG8RpUhy82CG8HiWVjDD") == 0) {
          extern mxArray *sf_c11_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c11_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "dXtFt1RUGkYOJjai4yBpiF") == 0) {
          extern mxArray *sf_c12_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c12_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "yPPzDIGn5DPyGYnrHi4YC") == 0) {
          extern mxArray *sf_c13_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c13_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "fbs1NXNu3p3DqJAjoWAIqB") == 0) {
          extern mxArray *sf_c14_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c14_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "VpuJLrkkZFJktQtxLkPKvE") == 0) {
          extern mxArray *sf_c17_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c17_Demo_EP_IdleRand_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "6AOa2CHeDSlW1ttLfc2KIC") == 0) {
          extern mxArray *sf_c20_Demo_EP_IdleRand_get_autoinheritance_info(void);
          plhs[0] = sf_c20_Demo_EP_IdleRand_get_autoinheritance_info();
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

unsigned int sf_Demo_EP_IdleRand_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Demo_EP_IdleRand_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_Demo_EP_IdleRand_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Demo_EP_IdleRand_get_eml_resolved_functions_info();
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

unsigned int sf_Demo_EP_IdleRand_third_party_uses_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "4Spk5QSF7RlVEqzgrUlQzE") == 0) {
          extern mxArray *sf_c1_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c1_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c2_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "tZRaI7fy6Usm17ySSrOoOC") == 0) {
          extern mxArray *sf_c4_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c4_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "DPC36VpSjsUjPa1cnFgoMG") == 0) {
          extern mxArray *sf_c5_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c5_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray *sf_c8_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c8_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "vKpaTxm86KyV5ICvvyu1sG") == 0) {
          extern mxArray *sf_c9_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c9_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "0IiBbrK91QMWhM8gTYN5HD") == 0) {
          extern mxArray *sf_c10_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c10_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "iaBvVnDLRpolOP7EMqZmY") == 0) {
          extern mxArray *sf_c11_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c11_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "4dHwkzLtkkbWwaqo8FpUpG") == 0) {
          extern mxArray *sf_c12_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c12_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray *sf_c13_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c13_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray *sf_c14_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c14_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c17_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "9RrbXQ1HzHmxAkSYCVpxEF") == 0) {
          extern mxArray *sf_c20_Demo_EP_IdleRand_third_party_uses_info(void);
          plhs[0] = sf_c20_Demo_EP_IdleRand_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Demo_EP_IdleRand_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "4Spk5QSF7RlVEqzgrUlQzE") == 0) {
          extern mxArray *sf_c1_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "tZRaI7fy6Usm17ySSrOoOC") == 0) {
          extern mxArray *sf_c4_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "DPC36VpSjsUjPa1cnFgoMG") == 0) {
          extern mxArray *sf_c5_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "CbDq9Qzq24djfXIGN8UDtD") == 0) {
          extern mxArray *sf_c8_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "vKpaTxm86KyV5ICvvyu1sG") == 0) {
          extern mxArray *sf_c9_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "0IiBbrK91QMWhM8gTYN5HD") == 0) {
          extern mxArray *sf_c10_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "iaBvVnDLRpolOP7EMqZmY") == 0) {
          extern mxArray *sf_c11_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "4dHwkzLtkkbWwaqo8FpUpG") == 0) {
          extern mxArray *sf_c12_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray *sf_c13_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray *sf_c14_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "9RrbXQ1HzHmxAkSYCVpxEF") == 0) {
          extern mxArray *sf_c20_Demo_EP_IdleRand_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_Demo_EP_IdleRand_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Demo_EP_IdleRand_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Demo_EP_IdleRandMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Demo_EP_IdleRand","sfun",0,13,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Demo_EP_IdleRandMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Demo_EP_IdleRandMachineNumber_,0);
}

void Demo_EP_IdleRand_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Demo_EP_IdleRand_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Demo_EP_IdleRand", "Demo_EP_IdleRand");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Demo_EP_IdleRand_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
