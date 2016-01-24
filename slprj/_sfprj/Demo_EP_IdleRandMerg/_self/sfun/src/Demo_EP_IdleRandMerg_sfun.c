/* Include files */

#include "Demo_EP_IdleRandMerg_sfun.h"
#include "Demo_EP_IdleRandMerg_sfun_debug_macros.h"
#include "c1_Demo_EP_IdleRandMerg.h"
#include "c2_Demo_EP_IdleRandMerg.h"
#include "c4_Demo_EP_IdleRandMerg.h"
#include "c5_Demo_EP_IdleRandMerg.h"
#include "c8_Demo_EP_IdleRandMerg.h"
#include "c9_Demo_EP_IdleRandMerg.h"
#include "c10_Demo_EP_IdleRandMerg.h"
#include "c11_Demo_EP_IdleRandMerg.h"
#include "c12_Demo_EP_IdleRandMerg.h"
#include "c13_Demo_EP_IdleRandMerg.h"
#include "c14_Demo_EP_IdleRandMerg.h"
#include "c15_Demo_EP_IdleRandMerg.h"
#include "c16_Demo_EP_IdleRandMerg.h"
#include "c17_Demo_EP_IdleRandMerg.h"
#include "c20_Demo_EP_IdleRandMerg.h"
#include "c21_Demo_EP_IdleRandMerg.h"
#include "c35_Demo_EP_IdleRandMerg.h"
#include "c37_Demo_EP_IdleRandMerg.h"
#include "c38_Demo_EP_IdleRandMerg.h"
#include "c39_Demo_EP_IdleRandMerg.h"
#include "c40_Demo_EP_IdleRandMerg.h"
#include "c41_Demo_EP_IdleRandMerg.h"
#include "c42_Demo_EP_IdleRandMerg.h"
#include "c43_Demo_EP_IdleRandMerg.h"
#include "c44_Demo_EP_IdleRandMerg.h"
#include "c45_Demo_EP_IdleRandMerg.h"
#include "c46_Demo_EP_IdleRandMerg.h"
#include "c47_Demo_EP_IdleRandMerg.h"
#include "c48_Demo_EP_IdleRandMerg.h"
#include "c49_Demo_EP_IdleRandMerg.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Demo_EP_IdleRandMergMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Demo_EP_IdleRandMerg_initializer(void)
{
}

void Demo_EP_IdleRandMerg_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Demo_EP_IdleRandMerg_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==40) {
    c40_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==42) {
    c42_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==44) {
    c44_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==45) {
    c45_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==46) {
    c46_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==47) {
    c47_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==48) {
    c48_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==49) {
    c49_Demo_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Demo_EP_IdleRandMerg_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2387520094U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(594281111U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2087755777U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1009226129U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2290224443U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1535577025U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3117096217U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1727489102U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c1_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c2_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c4_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c5_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c8_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c9_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c10_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c11_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c12_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c13_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c14_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c15_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c16_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c17_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c20_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c21_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c35_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c37_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c38_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c39_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 40:
        {
          extern void sf_c40_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c40_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c41_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 42:
        {
          extern void sf_c42_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c42_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c43_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 44:
        {
          extern void sf_c44_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c44_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 45:
        {
          extern void sf_c45_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c45_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 46:
        {
          extern void sf_c46_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c46_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 47:
        {
          extern void sf_c47_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c47_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 48:
        {
          extern void sf_c48_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c48_Demo_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 49:
        {
          extern void sf_c49_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c49_Demo_EP_IdleRandMerg_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2421501516U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1989082745U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2270715023U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1956849676U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Demo_EP_IdleRandMerg_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "XjOAFk4yoKUJmuKrhg3rgF") == 0) {
          extern mxArray *sf_c1_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "dGJqBWbUoq90gF0pG8EHiG") == 0) {
          extern mxArray *sf_c4_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "WdToWhQ1o1aRqVKbPAqsMH") == 0) {
          extern mxArray *sf_c5_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "sugYXALnGR1TONbTbCwvhD") == 0) {
          extern mxArray *sf_c8_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "XruFwOsz0KSHuLBsufuD9G") == 0) {
          extern mxArray *sf_c9_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Psqi8ilzBpGHBiSNif5PoE") == 0) {
          extern mxArray *sf_c10_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "zecKv8Et7UmYg1AgCMmnQE") == 0) {
          extern mxArray *sf_c11_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "wV3dApGy4UjoUifsNOiIRE") == 0) {
          extern mxArray *sf_c12_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c12_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "zWrtVS2BxvkXpDYdA5w9oE") == 0) {
          extern mxArray *sf_c13_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c13_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "4OXrhqwzt1bWB91QDOEPEC") == 0) {
          extern mxArray *sf_c14_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c14_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "gBg2zmus4QIe1mlUyi0CLG") == 0) {
          extern mxArray *sf_c15_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c15_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "1ZHcZ9HuksFRgnQ5yLbgsG") == 0) {
          extern mxArray *sf_c16_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c16_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "VpuJLrkkZFJktQtxLkPKvE") == 0) {
          extern mxArray *sf_c17_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c17_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "OBARG9Lt1IZw8WhenTJ2zF") == 0) {
          extern mxArray *sf_c20_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c20_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "XFQhRbw3X53oJvICkXhK9D") == 0) {
          extern mxArray *sf_c21_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c21_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 35:
      {
        if (strcmp(aiChksum, "gmHZYixc2ddsg0UFuGrrHC") == 0) {
          extern mxArray *sf_c35_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c35_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "mvMGcuHSeH872pn0xeK8q") == 0) {
          extern mxArray *sf_c37_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c37_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 38:
      {
        if (strcmp(aiChksum, "DsGiFVf3BSSsPxOzqVwzkE") == 0) {
          extern mxArray *sf_c38_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c38_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "zW6NXDTShv8JiUhNTzhYcD") == 0) {
          extern mxArray *sf_c39_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c39_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 40:
      {
        if (strcmp(aiChksum, "PBOOE2ONCJlr45MWsYJj7G") == 0) {
          extern mxArray *sf_c40_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c40_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "wV3dApGy4UjoUifsNOiIRE") == 0) {
          extern mxArray *sf_c41_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c41_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 42:
      {
        if (strcmp(aiChksum, "cRqnKixszRBhXBADNxyFkF") == 0) {
          extern mxArray *sf_c42_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c42_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "176zWFCdH2SLsYzqatfBVH") == 0) {
          extern mxArray *sf_c43_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c43_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 44:
      {
        if (strcmp(aiChksum, "JYmE0zFWwECFl12XwSHAzG") == 0) {
          extern mxArray *sf_c44_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c44_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 45:
      {
        if (strcmp(aiChksum, "PBOOE2ONCJlr45MWsYJj7G") == 0) {
          extern mxArray *sf_c45_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c45_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 46:
      {
        if (strcmp(aiChksum, "BWoaXZiYXDHXUQk106mDDB") == 0) {
          extern mxArray *sf_c46_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c46_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 47:
      {
        if (strcmp(aiChksum, "b2Y91KTB3TvHOkJtt5jhFD") == 0) {
          extern mxArray *sf_c47_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c47_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 48:
      {
        if (strcmp(aiChksum, "tX0lHBk87rKZvvGilKnEFD") == 0) {
          extern mxArray *sf_c48_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c48_Demo_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 49:
      {
        if (strcmp(aiChksum, "NOfsRIkFwz0Pf7RMuUn8m") == 0) {
          extern mxArray *sf_c49_Demo_EP_IdleRandMerg_get_autoinheritance_info
            (void);
          plhs[0] = sf_c49_Demo_EP_IdleRandMerg_get_autoinheritance_info();
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

unsigned int sf_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray
          *sf_c35_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray
          *sf_c38_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray
          *sf_c39_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 40:
      {
        extern const mxArray
          *sf_c40_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c40_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray
          *sf_c41_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 42:
      {
        extern const mxArray
          *sf_c42_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c42_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 44:
      {
        extern const mxArray
          *sf_c44_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c44_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 45:
      {
        extern const mxArray
          *sf_c45_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c45_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 46:
      {
        extern const mxArray
          *sf_c46_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c46_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 47:
      {
        extern const mxArray
          *sf_c47_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c47_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 48:
      {
        extern const mxArray
          *sf_c48_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c48_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 49:
      {
        extern const mxArray
          *sf_c49_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c49_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info();
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

unsigned int sf_Demo_EP_IdleRandMerg_third_party_uses_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "f4gyNg1AXlq2Gh31Fx2zn") == 0) {
          extern mxArray *sf_c1_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c1_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c2_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "xn7bISZktE8JRXWvy9Z3d") == 0) {
          extern mxArray *sf_c4_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c4_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "9r6dOo1C7vSvBUqRkGsLYG") == 0) {
          extern mxArray *sf_c5_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c5_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "r1oBQlcwAu6P5EDjTzX8hC") == 0) {
          extern mxArray *sf_c8_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c8_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "2zfNor6Vsh7BqpzT62bufE") == 0) {
          extern mxArray *sf_c9_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c9_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a9oTrvWOrOFZTRixUhix2D") == 0) {
          extern mxArray *sf_c10_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c10_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "JlhR2Cyz8cIGjzYYR8u2ZB") == 0) {
          extern mxArray *sf_c11_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c11_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c12_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c12_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "BCWB2dcpeExeMoPXkiwlND") == 0) {
          extern mxArray *sf_c13_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c13_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "mKaAFfUa9d6xgRXf4uQHPH") == 0) {
          extern mxArray *sf_c14_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c14_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c15_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "QvGt3tBWcy7cZIQEwILXMG") == 0) {
          extern mxArray *sf_c16_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c16_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c17_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c20_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c21_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "tJuDfgpll5BrF182OjlB8E") == 0) {
          extern mxArray *sf_c35_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c35_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c37_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "94EHSMjC42UJTIOKUCRIaE") == 0) {
          extern mxArray *sf_c38_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c38_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "GQRRxK26Fo9W78HGbrQvAB") == 0) {
          extern mxArray *sf_c39_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c39_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "7M3xs6TX5bpbbfWKpdDrXE") == 0) {
          extern mxArray *sf_c40_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c40_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c41_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c41_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "ffMcfPzqmlD5qxtTjUiPBC") == 0) {
          extern mxArray *sf_c42_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c42_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "HtXCKmkx3Cg9N5Ees5y3H") == 0) {
          extern mxArray *sf_c43_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c43_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "u21yliQXz4oqFBIqp3opJC") == 0) {
          extern mxArray *sf_c44_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c44_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "TYRfK1GKG3nJxBPOVXmiwG") == 0) {
          extern mxArray *sf_c45_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c45_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "FcrP1iUU0fWnqn2sznec2D") == 0) {
          extern mxArray *sf_c46_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c46_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "PaA98thoaIzT5nBolaJkr") == 0) {
          extern mxArray *sf_c47_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c47_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "lRTv3O8loLoeZPjndZwtuD") == 0) {
          extern mxArray *sf_c48_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c48_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "MoIVXLQ3nGfHwZ6270d3ZE") == 0) {
          extern mxArray *sf_c49_Demo_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c49_Demo_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Demo_EP_IdleRandMerg_updateBuildInfo_args_info( int nlhs,
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
        if (strcmp(tpChksum, "f4gyNg1AXlq2Gh31Fx2zn") == 0) {
          extern mxArray *sf_c1_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "xn7bISZktE8JRXWvy9Z3d") == 0) {
          extern mxArray *sf_c4_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "9r6dOo1C7vSvBUqRkGsLYG") == 0) {
          extern mxArray *sf_c5_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "r1oBQlcwAu6P5EDjTzX8hC") == 0) {
          extern mxArray *sf_c8_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c8_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "2zfNor6Vsh7BqpzT62bufE") == 0) {
          extern mxArray *sf_c9_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c9_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a9oTrvWOrOFZTRixUhix2D") == 0) {
          extern mxArray *sf_c10_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c10_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "JlhR2Cyz8cIGjzYYR8u2ZB") == 0) {
          extern mxArray *sf_c11_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c11_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c12_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c12_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "BCWB2dcpeExeMoPXkiwlND") == 0) {
          extern mxArray *sf_c13_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c13_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "mKaAFfUa9d6xgRXf4uQHPH") == 0) {
          extern mxArray *sf_c14_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c14_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c15_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "QvGt3tBWcy7cZIQEwILXMG") == 0) {
          extern mxArray *sf_c16_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c16_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c17_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c20_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c21_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "tJuDfgpll5BrF182OjlB8E") == 0) {
          extern mxArray *sf_c35_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c35_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c37_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "94EHSMjC42UJTIOKUCRIaE") == 0) {
          extern mxArray *sf_c38_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c38_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "GQRRxK26Fo9W78HGbrQvAB") == 0) {
          extern mxArray *sf_c39_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c39_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "7M3xs6TX5bpbbfWKpdDrXE") == 0) {
          extern mxArray *sf_c40_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c40_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c41_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c41_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "ffMcfPzqmlD5qxtTjUiPBC") == 0) {
          extern mxArray *sf_c42_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c42_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "HtXCKmkx3Cg9N5Ees5y3H") == 0) {
          extern mxArray *sf_c43_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c43_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "u21yliQXz4oqFBIqp3opJC") == 0) {
          extern mxArray *sf_c44_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c44_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "TYRfK1GKG3nJxBPOVXmiwG") == 0) {
          extern mxArray *sf_c45_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c45_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "FcrP1iUU0fWnqn2sznec2D") == 0) {
          extern mxArray *sf_c46_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c46_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "PaA98thoaIzT5nBolaJkr") == 0) {
          extern mxArray *sf_c47_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c47_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "lRTv3O8loLoeZPjndZwtuD") == 0) {
          extern mxArray *sf_c48_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c48_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "MoIVXLQ3nGfHwZ6270d3ZE") == 0) {
          extern mxArray *sf_c49_Demo_EP_IdleRandMerg_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c49_Demo_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Demo_EP_IdleRandMerg_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Demo_EP_IdleRandMergMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"Demo_EP_IdleRandMerg","sfun",0,30,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Demo_EP_IdleRandMergMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Demo_EP_IdleRandMergMachineNumber_,0);
}

void Demo_EP_IdleRandMerg_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Demo_EP_IdleRandMerg_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Demo_EP_IdleRandMerg", "Demo_EP_IdleRandMerg");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Demo_EP_IdleRandMerg_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
