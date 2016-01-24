/* Include files */

#include "testWalkStepWorldSim_sfun.h"
#include "testWalkStepWorldSim_sfun_debug_macros.h"
#include "c1_testWalkStepWorldSim.h"
#include "c2_testWalkStepWorldSim.h"
#include "c4_testWalkStepWorldSim.h"
#include "c5_testWalkStepWorldSim.h"
#include "c8_testWalkStepWorldSim.h"
#include "c9_testWalkStepWorldSim.h"
#include "c10_testWalkStepWorldSim.h"
#include "c11_testWalkStepWorldSim.h"
#include "c17_testWalkStepWorldSim.h"
#include "c18_testWalkStepWorldSim.h"
#include "c20_testWalkStepWorldSim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _testWalkStepWorldSimMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void testWalkStepWorldSim_initializer(void)
{
}

void testWalkStepWorldSim_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_testWalkStepWorldSim_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_testWalkStepWorldSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_testWalkStepWorldSim_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1564225575U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1160231821U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1252560287U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4046461223U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(743016302U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(360072330U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3890238112U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1847877528U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c1_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c2_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c4_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c5_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c8_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c9_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c10_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c11_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c17_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c18_testWalkStepWorldSim_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_testWalkStepWorldSim_get_check_sum(mxArray *plhs[]);
          sf_c20_testWalkStepWorldSim_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1261708028U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2710368974U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2777228835U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(810715281U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_testWalkStepWorldSim_autoinheritance_info( int nlhs, mxArray *
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
          extern mxArray *sf_c1_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "wrM5H8R7xniY0vcAIvJMbC") == 0) {
          extern mxArray *sf_c4_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "STYvhzdlCUcb4w0Hk7qYsF") == 0) {
          extern mxArray *sf_c5_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "rPw986iWUb9zH2dGflTroF") == 0) {
          extern mxArray *sf_c8_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "x0jy9vgY6PqerdTDYBOtl") == 0) {
          extern mxArray *sf_c9_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "xxkNGChDflDrWWfbQBqRE") == 0) {
          extern mxArray *sf_c10_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "LMaw6Foqj8VwBeBsFx1sQH") == 0) {
          extern mxArray *sf_c11_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "NXVeltQjg4PvjVsETVb4WE") == 0) {
          extern mxArray *sf_c17_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c17_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "q7zoKb2PYssm0FsycxJhm") == 0) {
          extern mxArray *sf_c18_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c18_testWalkStepWorldSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "yeRDJ7gwXhKRz6v00P54HF") == 0) {
          extern mxArray *sf_c20_testWalkStepWorldSim_get_autoinheritance_info
            (void);
          plhs[0] = sf_c20_testWalkStepWorldSim_get_autoinheritance_info();
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

unsigned int sf_testWalkStepWorldSim_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_testWalkStepWorldSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_testWalkStepWorldSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_testWalkStepWorldSim_get_eml_resolved_functions_info();
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

unsigned int sf_testWalkStepWorldSim_third_party_uses_info( int nlhs, mxArray *
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
          extern mxArray *sf_c1_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c1_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c2_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "bQybm8wmY781OpH7vA5q7G") == 0) {
          extern mxArray *sf_c4_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c4_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "kk4t0Q4v90rfCMF5Dnnh1C") == 0) {
          extern mxArray *sf_c5_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c5_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "MRJ0fJNOs7xIaGnFUpaXeF") == 0) {
          extern mxArray *sf_c8_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c8_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "ohYkifhfcTx279QMd86fhF") == 0) {
          extern mxArray *sf_c9_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c9_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "x4XoHyulE6A6JDEmygUxxF") == 0) {
          extern mxArray *sf_c10_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c10_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bxsvd4uU17MMyI9AvQ68rH") == 0) {
          extern mxArray *sf_c11_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c11_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "CX0smq9DsvPN01F4gVOgo") == 0) {
          extern mxArray *sf_c17_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c17_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray *sf_c18_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c18_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "1MgLDOtHxNYpRPXqx5mle") == 0) {
          extern mxArray *sf_c20_testWalkStepWorldSim_third_party_uses_info(void);
          plhs[0] = sf_c20_testWalkStepWorldSim_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_testWalkStepWorldSim_updateBuildInfo_args_info( int nlhs,
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
          extern mxArray *sf_c1_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "bQybm8wmY781OpH7vA5q7G") == 0) {
          extern mxArray *sf_c4_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "kk4t0Q4v90rfCMF5Dnnh1C") == 0) {
          extern mxArray *sf_c5_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "MRJ0fJNOs7xIaGnFUpaXeF") == 0) {
          extern mxArray *sf_c8_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c8_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "ohYkifhfcTx279QMd86fhF") == 0) {
          extern mxArray *sf_c9_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c9_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "x4XoHyulE6A6JDEmygUxxF") == 0) {
          extern mxArray *sf_c10_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c10_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bxsvd4uU17MMyI9AvQ68rH") == 0) {
          extern mxArray *sf_c11_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c11_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "CX0smq9DsvPN01F4gVOgo") == 0) {
          extern mxArray *sf_c17_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c17_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray *sf_c18_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c18_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "1MgLDOtHxNYpRPXqx5mle") == 0) {
          extern mxArray *sf_c20_testWalkStepWorldSim_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c20_testWalkStepWorldSim_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void testWalkStepWorldSim_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _testWalkStepWorldSimMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"testWalkStepWorldSim","sfun",0,11,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _testWalkStepWorldSimMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _testWalkStepWorldSimMachineNumber_,0);
}

void testWalkStepWorldSim_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_testWalkStepWorldSim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "testWalkStepWorldSim", "testWalkStepWorldSim");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_testWalkStepWorldSim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
