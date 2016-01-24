/* Include files */

#include "EP_IdleRandMerg_sfun.h"
#include "EP_IdleRandMerg_sfun_debug_macros.h"
#include "c1_EP_IdleRandMerg.h"
#include "c2_EP_IdleRandMerg.h"
#include "c4_EP_IdleRandMerg.h"
#include "c5_EP_IdleRandMerg.h"
#include "c8_EP_IdleRandMerg.h"
#include "c9_EP_IdleRandMerg.h"
#include "c10_EP_IdleRandMerg.h"
#include "c11_EP_IdleRandMerg.h"
#include "c12_EP_IdleRandMerg.h"
#include "c13_EP_IdleRandMerg.h"
#include "c14_EP_IdleRandMerg.h"
#include "c15_EP_IdleRandMerg.h"
#include "c16_EP_IdleRandMerg.h"
#include "c17_EP_IdleRandMerg.h"
#include "c20_EP_IdleRandMerg.h"
#include "c21_EP_IdleRandMerg.h"
#include "c37_EP_IdleRandMerg.h"
#include "c38_EP_IdleRandMerg.h"
#include "c39_EP_IdleRandMerg.h"
#include "c41_EP_IdleRandMerg.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _EP_IdleRandMergMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void EP_IdleRandMerg_initializer(void)
{
}

void EP_IdleRandMerg_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_EP_IdleRandMerg_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_EP_IdleRandMerg_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_EP_IdleRandMerg_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2519468155U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(103864817U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(311637207U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2022774871U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(681924143U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3675411097U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3289807854U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1399907901U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c1_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c2_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c4_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c5_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c8_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c9_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c10_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c11_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c12_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c13_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c14_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c15_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c16_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c17_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c20_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c21_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c37_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c38_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c39_EP_IdleRandMerg_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
          sf_c41_EP_IdleRandMerg_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3213625U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3325100252U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1758301947U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3398189697U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EP_IdleRandMerg_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "b8XBKFGw72jzDaGYS853oE") == 0) {
          extern mxArray *sf_c1_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c1_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c2_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "KZbYoVcXbMszgbAEqi2qs") == 0) {
          extern mxArray *sf_c4_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c4_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "cDa6KVPLrBdyJCAtBR8ilF") == 0) {
          extern mxArray *sf_c5_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c5_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "nswGzgFNL2GoBMnLEybgL") == 0) {
          extern mxArray *sf_c8_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c8_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "HC4ttVigXgF3QwFuxZTckF") == 0) {
          extern mxArray *sf_c9_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c9_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "5KJ3dWRtzkidAc7VPBtlLF") == 0) {
          extern mxArray *sf_c10_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c10_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "cLw1bwxGfhUUQxCanOFL1F") == 0) {
          extern mxArray *sf_c11_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c11_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "WKTB2CbkBm1dCdjFlE90P") == 0) {
          extern mxArray *sf_c12_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c12_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "TsggD4ImQouqmANQNMdalE") == 0) {
          extern mxArray *sf_c13_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c13_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "tqm83fUVasSnQPhC8yNNTG") == 0) {
          extern mxArray *sf_c14_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c14_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "gBg2zmus4QIe1mlUyi0CLG") == 0) {
          extern mxArray *sf_c15_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c15_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "e33uQC3qcj4cOwFIj0zQwG") == 0) {
          extern mxArray *sf_c16_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c16_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "VpuJLrkkZFJktQtxLkPKvE") == 0) {
          extern mxArray *sf_c17_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c17_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "XYMr0JVG6vuwbjsHbENJAC") == 0) {
          extern mxArray *sf_c20_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c20_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "XFQhRbw3X53oJvICkXhK9D") == 0) {
          extern mxArray *sf_c21_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c21_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "mvMGcuHSeH872pn0xeK8q") == 0) {
          extern mxArray *sf_c37_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c37_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 38:
      {
        if (strcmp(aiChksum, "WKTB2CbkBm1dCdjFlE90P") == 0) {
          extern mxArray *sf_c38_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c38_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "owiJaNyyUF6NPDrFrFjQvH") == 0) {
          extern mxArray *sf_c39_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c39_EP_IdleRandMerg_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "owiJaNyyUF6NPDrFrFjQvH") == 0) {
          extern mxArray *sf_c41_EP_IdleRandMerg_get_autoinheritance_info(void);
          plhs[0] = sf_c41_EP_IdleRandMerg_get_autoinheritance_info();
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

unsigned int sf_EP_IdleRandMerg_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray
          *sf_c38_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray
          *sf_c39_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_EP_IdleRandMerg_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray
          *sf_c41_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_EP_IdleRandMerg_get_eml_resolved_functions_info();
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

unsigned int sf_EP_IdleRandMerg_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "9yfCQ2HmivjCvMOT8LrII") == 0) {
          extern mxArray *sf_c1_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c1_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c2_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "gfNZNW83TDgWcI80qJtRLD") == 0) {
          extern mxArray *sf_c4_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c4_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "3XuvKRVgNig8OhWfKD5AEF") == 0) {
          extern mxArray *sf_c5_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c5_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "3DyNmt5ldcq9Ws9RMQZ08B") == 0) {
          extern mxArray *sf_c8_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c8_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "MxxpndvJgPhVe3X7Q78IF") == 0) {
          extern mxArray *sf_c9_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c9_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "wapMF7Ohohblv6qoWvt84F") == 0) {
          extern mxArray *sf_c10_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c10_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sysZIcBoTMG1kKkuKwqCFF") == 0) {
          extern mxArray *sf_c11_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c11_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c12_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c12_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "G1wshu4n2GJ9JOVqNyVD0F") == 0) {
          extern mxArray *sf_c13_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c13_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "1l8cmGlAYERLWs9KBrY8h") == 0) {
          extern mxArray *sf_c14_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c14_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c15_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "JpdAvRt1QKpMB3RavCoxXE") == 0) {
          extern mxArray *sf_c16_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c16_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c17_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c20_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c21_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c37_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c38_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c38_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c39_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c39_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c41_EP_IdleRandMerg_third_party_uses_info(void);
          plhs[0] = sf_c41_EP_IdleRandMerg_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_EP_IdleRandMerg_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "9yfCQ2HmivjCvMOT8LrII") == 0) {
          extern mxArray *sf_c1_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "gfNZNW83TDgWcI80qJtRLD") == 0) {
          extern mxArray *sf_c4_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "3XuvKRVgNig8OhWfKD5AEF") == 0) {
          extern mxArray *sf_c5_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "3DyNmt5ldcq9Ws9RMQZ08B") == 0) {
          extern mxArray *sf_c8_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "MxxpndvJgPhVe3X7Q78IF") == 0) {
          extern mxArray *sf_c9_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "wapMF7Ohohblv6qoWvt84F") == 0) {
          extern mxArray *sf_c10_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sysZIcBoTMG1kKkuKwqCFF") == 0) {
          extern mxArray *sf_c11_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c12_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "G1wshu4n2GJ9JOVqNyVD0F") == 0) {
          extern mxArray *sf_c13_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "1l8cmGlAYERLWs9KBrY8h") == 0) {
          extern mxArray *sf_c14_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "JpdAvRt1QKpMB3RavCoxXE") == 0) {
          extern mxArray *sf_c16_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "yxLFsPfYw4vYDLUXD0ZBgG") == 0) {
          extern mxArray *sf_c38_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c38_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c39_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c39_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "xTMlZ5mBpyfqtyxaTKwSTD") == 0) {
          extern mxArray *sf_c41_EP_IdleRandMerg_updateBuildInfo_args_info(void);
          plhs[0] = sf_c41_EP_IdleRandMerg_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void EP_IdleRandMerg_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _EP_IdleRandMergMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "EP_IdleRandMerg","sfun",0,20,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _EP_IdleRandMergMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _EP_IdleRandMergMachineNumber_,0);
}

void EP_IdleRandMerg_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_EP_IdleRandMerg_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("EP_IdleRandMerg",
      "EP_IdleRandMerg");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_EP_IdleRandMerg_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
