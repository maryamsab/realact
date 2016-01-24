/* Include files */

#include "Demo_Glove_sfun.h"
#include "Demo_Glove_sfun_debug_macros.h"
#include "c1_Demo_Glove.h"
#include "c2_Demo_Glove.h"
#include "c3_Demo_Glove.h"
#include "c4_Demo_Glove.h"
#include "c5_Demo_Glove.h"
#include "c8_Demo_Glove.h"
#include "c10_Demo_Glove.h"
#include "c11_Demo_Glove.h"
#include "c12_Demo_Glove.h"
#include "c13_Demo_Glove.h"
#include "c14_Demo_Glove.h"
#include "c15_Demo_Glove.h"
#include "c16_Demo_Glove.h"
#include "c17_Demo_Glove.h"
#include "c20_Demo_Glove.h"
#include "c21_Demo_Glove.h"
#include "c35_Demo_Glove.h"
#include "c37_Demo_Glove.h"
#include "c38_Demo_Glove.h"
#include "c39_Demo_Glove.h"
#include "c40_Demo_Glove.h"
#include "c41_Demo_Glove.h"
#include "c42_Demo_Glove.h"
#include "c43_Demo_Glove.h"
#include "c44_Demo_Glove.h"
#include "c45_Demo_Glove.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Demo_GloveMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Demo_Glove_initializer(void)
{
}

void Demo_Glove_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Demo_Glove_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==40) {
    c40_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==42) {
    c42_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==44) {
    c44_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==45) {
    c45_Demo_Glove_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Demo_Glove_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3875415085U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3060887495U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1675874204U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2929727244U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2660225221U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1195472130U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4077123542U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(209491940U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c1_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c2_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c3_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c4_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c5_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c8_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c10_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c11_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c12_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c13_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c14_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c15_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c16_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c17_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c20_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c21_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c35_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c37_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c38_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c39_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 40:
        {
          extern void sf_c40_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c40_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c41_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 42:
        {
          extern void sf_c42_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c42_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c43_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 44:
        {
          extern void sf_c44_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c44_Demo_Glove_get_check_sum(plhs);
          break;
        }

       case 45:
        {
          extern void sf_c45_Demo_Glove_get_check_sum(mxArray *plhs[]);
          sf_c45_Demo_Glove_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2111932290U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1563855759U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1761408932U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(750048319U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Demo_Glove_autoinheritance_info( int nlhs, mxArray * plhs[], int
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
        if (strcmp(aiChksum, "47RhXYEzCz1R4tPOW7loxG") == 0) {
          extern mxArray *sf_c1_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "6ToljhSGzQbPoAkW7t0cfB") == 0) {
          extern mxArray *sf_c3_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "judZw3QVOBjcJo1WcD8AJE") == 0) {
          extern mxArray *sf_c4_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "V87aGzXjvFZFCeSh4THjl") == 0) {
          extern mxArray *sf_c5_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "sugYXALnGR1TONbTbCwvhD") == 0) {
          extern mxArray *sf_c8_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c8_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Psqi8ilzBpGHBiSNif5PoE") == 0) {
          extern mxArray *sf_c10_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c10_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "rlB3oN0uGO1JriRQCNyWgC") == 0) {
          extern mxArray *sf_c11_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c11_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "WKTB2CbkBm1dCdjFlE90P") == 0) {
          extern mxArray *sf_c12_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c12_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "uKbhCnD9nrlook1KL8bKgC") == 0) {
          extern mxArray *sf_c13_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c13_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "OfIlok1z4DI3L5THAbHbcH") == 0) {
          extern mxArray *sf_c14_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c14_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "gBg2zmus4QIe1mlUyi0CLG") == 0) {
          extern mxArray *sf_c15_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c15_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "1ZHcZ9HuksFRgnQ5yLbgsG") == 0) {
          extern mxArray *sf_c16_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c16_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "VpuJLrkkZFJktQtxLkPKvE") == 0) {
          extern mxArray *sf_c17_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c17_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "OBARG9Lt1IZw8WhenTJ2zF") == 0) {
          extern mxArray *sf_c20_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c20_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "XFQhRbw3X53oJvICkXhK9D") == 0) {
          extern mxArray *sf_c21_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c21_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 35:
      {
        if (strcmp(aiChksum, "gmHZYixc2ddsg0UFuGrrHC") == 0) {
          extern mxArray *sf_c35_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c35_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "mvMGcuHSeH872pn0xeK8q") == 0) {
          extern mxArray *sf_c37_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c37_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 38:
      {
        if (strcmp(aiChksum, "WKTB2CbkBm1dCdjFlE90P") == 0) {
          extern mxArray *sf_c38_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c38_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "owiJaNyyUF6NPDrFrFjQvH") == 0) {
          extern mxArray *sf_c39_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c39_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 40:
      {
        if (strcmp(aiChksum, "PBOOE2ONCJlr45MWsYJj7G") == 0) {
          extern mxArray *sf_c40_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c40_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "owiJaNyyUF6NPDrFrFjQvH") == 0) {
          extern mxArray *sf_c41_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c41_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 42:
      {
        if (strcmp(aiChksum, "kvAXjDlvBZES7TdLIIuQGG") == 0) {
          extern mxArray *sf_c42_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c42_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "igkLZV55kAIWbKxYE5SKVC") == 0) {
          extern mxArray *sf_c43_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c43_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 44:
      {
        if (strcmp(aiChksum, "AsMvGDHrzfBUNsndVm0g1C") == 0) {
          extern mxArray *sf_c44_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c44_Demo_Glove_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 45:
      {
        if (strcmp(aiChksum, "PBOOE2ONCJlr45MWsYJj7G") == 0) {
          extern mxArray *sf_c45_Demo_Glove_get_autoinheritance_info(void);
          plhs[0] = sf_c45_Demo_Glove_get_autoinheritance_info();
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

unsigned int sf_Demo_Glove_get_eml_resolved_functions_info( int nlhs, mxArray *
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
        extern const mxArray *sf_c1_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray *sf_c16_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray *sf_c21_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray *sf_c35_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray *sf_c37_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray *sf_c38_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray *sf_c39_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 40:
      {
        extern const mxArray *sf_c40_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c40_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray *sf_c41_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 42:
      {
        extern const mxArray *sf_c42_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c42_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray *sf_c43_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 44:
      {
        extern const mxArray *sf_c44_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c44_Demo_Glove_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 45:
      {
        extern const mxArray *sf_c45_Demo_Glove_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c45_Demo_Glove_get_eml_resolved_functions_info();
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

unsigned int sf_Demo_Glove_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "5hsaBGstoRErN0A6ioSssF") == 0) {
          extern mxArray *sf_c1_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c1_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c2_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray *sf_c3_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c3_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "dR0ftyhUCxvNZVzas333IC") == 0) {
          extern mxArray *sf_c4_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c4_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "vm6zwHJItv0zktyil35psE") == 0) {
          extern mxArray *sf_c5_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c5_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "r1oBQlcwAu6P5EDjTzX8hC") == 0) {
          extern mxArray *sf_c8_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c8_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a9oTrvWOrOFZTRixUhix2D") == 0) {
          extern mxArray *sf_c10_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c10_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "houlKpqrjMrdL6VnPS8KuB") == 0) {
          extern mxArray *sf_c11_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c11_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c12_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c12_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "uUjGZN8cnr2Fra5Vn4RGsG") == 0) {
          extern mxArray *sf_c13_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c13_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "PoCaGBz2iEJtnTPkxyiukF") == 0) {
          extern mxArray *sf_c14_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c14_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c15_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "QvGt3tBWcy7cZIQEwILXMG") == 0) {
          extern mxArray *sf_c16_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c16_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c17_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c20_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c21_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "tJuDfgpll5BrF182OjlB8E") == 0) {
          extern mxArray *sf_c35_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c35_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c37_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c38_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c38_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c39_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c39_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "7M3xs6TX5bpbbfWKpdDrXE") == 0) {
          extern mxArray *sf_c40_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c40_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c41_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c41_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "UHJhXlK7BvMzCIabbWrv8D") == 0) {
          extern mxArray *sf_c42_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c42_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "py27Enma4o6YIZYys2hZ8G") == 0) {
          extern mxArray *sf_c43_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c43_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "l8Gl1A5I5zrcHAQ64AY4lB") == 0) {
          extern mxArray *sf_c44_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c44_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "TYRfK1GKG3nJxBPOVXmiwG") == 0) {
          extern mxArray *sf_c45_Demo_Glove_third_party_uses_info(void);
          plhs[0] = sf_c45_Demo_Glove_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Demo_Glove_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "5hsaBGstoRErN0A6ioSssF") == 0) {
          extern mxArray *sf_c1_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray *sf_c3_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "dR0ftyhUCxvNZVzas333IC") == 0) {
          extern mxArray *sf_c4_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "vm6zwHJItv0zktyil35psE") == 0) {
          extern mxArray *sf_c5_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "r1oBQlcwAu6P5EDjTzX8hC") == 0) {
          extern mxArray *sf_c8_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a9oTrvWOrOFZTRixUhix2D") == 0) {
          extern mxArray *sf_c10_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "houlKpqrjMrdL6VnPS8KuB") == 0) {
          extern mxArray *sf_c11_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c12_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "uUjGZN8cnr2Fra5Vn4RGsG") == 0) {
          extern mxArray *sf_c13_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "PoCaGBz2iEJtnTPkxyiukF") == 0) {
          extern mxArray *sf_c14_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "QvGt3tBWcy7cZIQEwILXMG") == 0) {
          extern mxArray *sf_c16_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "tJuDfgpll5BrF182OjlB8E") == 0) {
          extern mxArray *sf_c35_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c35_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c38_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c38_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c39_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c39_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "7M3xs6TX5bpbbfWKpdDrXE") == 0) {
          extern mxArray *sf_c40_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c40_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c41_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c41_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "UHJhXlK7BvMzCIabbWrv8D") == 0) {
          extern mxArray *sf_c42_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c42_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "py27Enma4o6YIZYys2hZ8G") == 0) {
          extern mxArray *sf_c43_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "l8Gl1A5I5zrcHAQ64AY4lB") == 0) {
          extern mxArray *sf_c44_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c44_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "TYRfK1GKG3nJxBPOVXmiwG") == 0) {
          extern mxArray *sf_c45_Demo_Glove_updateBuildInfo_args_info(void);
          plhs[0] = sf_c45_Demo_Glove_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Demo_Glove_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Demo_GloveMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Demo_Glove","sfun",0,26,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_Demo_GloveMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_Demo_GloveMachineNumber_,0);
}

void Demo_Glove_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Demo_Glove_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Demo_Glove",
      "Demo_Glove");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Demo_Glove_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
