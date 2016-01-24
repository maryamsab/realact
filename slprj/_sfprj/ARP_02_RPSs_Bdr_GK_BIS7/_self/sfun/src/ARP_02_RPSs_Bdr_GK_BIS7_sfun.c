/* Include files */

#include "ARP_02_RPSs_Bdr_GK_BIS7_sfun.h"
#include "ARP_02_RPSs_Bdr_GK_BIS7_sfun_debug_macros.h"
#include "c1_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c2_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c4_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c5_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c6_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c8_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c9_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c10_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c11_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c12_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c13_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c14_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c15_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c16_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c19_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c20_ARP_02_RPSs_Bdr_GK_BIS7.h"
#include "c21_ARP_02_RPSs_Bdr_GK_BIS7.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ARP_02_RPSs_Bdr_GK_BIS7MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ARP_02_RPSs_Bdr_GK_BIS7_initializer(void)
{
}

void ARP_02_RPSs_Bdr_GK_BIS7_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_ARP_02_RPSs_Bdr_GK_BIS7_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS7_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1898450245U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(208926887U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(544116059U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3981040515U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(953800192U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3525559883U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4004334187U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3210924094U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *plhs[]);
          sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *plhs[]);
          sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *plhs[]);
          sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *plhs[]);
          sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *plhs[]);
          sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *plhs[]);
          sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *plhs[]);
          sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(mxArray *
            plhs[]);
          sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(412219365U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3161495252U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3455648913U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(184112178U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS7_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "o5g6GIVF5oOXQprzCtdZmH") == 0) {
          extern mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "VRPNH3X9wFgHuz4oG5wrPH") == 0) {
          extern mxArray *sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "kbS9XcqOEo4FfW56j1daDF") == 0) {
          extern mxArray *sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "q7zoKb2PYssm0FsycxJhm") == 0) {
          extern mxArray *sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "vdbxF3Y4vBPy13p3sYYa2G") == 0) {
          extern mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "eJ6lUyrzb9ClE0pzlCNEBB") == 0) {
          extern mxArray *sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "tERUYKkWJG6VM4uJ1dCQRH") == 0) {
          extern mxArray
            *sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "nGmPrg6xMbXRzUyN5gZwbB") == 0) {
          extern mxArray
            *sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "dXtFt1RUGkYOJjai4yBpiF") == 0) {
          extern mxArray
            *sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "yPPzDIGn5DPyGYnrHi4YC") == 0) {
          extern mxArray
            *sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "fbs1NXNu3p3DqJAjoWAIqB") == 0) {
          extern mxArray
            *sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "nXZRq3E4ZUB2RMzRpUECK") == 0) {
          extern mxArray
            *sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "QDf38tCVQgEG9LaXmTnA8B") == 0) {
          extern mxArray
            *sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "P1Nlcknnajj8uxt0Z0wMqF") == 0) {
          extern mxArray
            *sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "B4CQ9wS1oFxWBZOz6Uvdx") == 0) {
          extern mxArray
            *sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "Gc7VntGn8cYPPsAqjM8CnG") == 0) {
          extern mxArray
            *sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info(void);
          plhs[0] = sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_get_autoinheritance_info();
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

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info( int
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
          *sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_get_eml_resolved_functions_info();
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

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
          extern mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "ykvquPu9OdBFBVkmHjZN2B") == 0) {
          extern mxArray *sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "4eOi05p0NzZ1vFZkWpgf7") == 0) {
          extern mxArray *sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray *sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "tXTW5U46re7bXoLFU7I6h") == 0) {
          extern mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "fMp6JfQCSl13MP494T0i3D") == 0) {
          extern mxArray *sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "EjuzPTpxHL7hetyxY2aTIB") == 0) {
          extern mxArray *sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7Tjii6EYNdbRCJQAty8xHH") == 0) {
          extern mxArray *sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "4dHwkzLtkkbWwaqo8FpUpG") == 0) {
          extern mxArray *sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray *sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray *sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "UhzuqpsAzlsRfgj8i0QCiH") == 0) {
          extern mxArray *sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "17DFEai06KSaMfKXedga2D") == 0) {
          extern mxArray *sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "AlGocMr3QfHKX8uRlIaLKB") == 0) {
          extern mxArray *sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "TGPrkLJrq20FF0uBuwEBJH") == 0) {
          extern mxArray *sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "IrJx1HAbJxOP0GUtSY6MKC") == 0) {
          extern mxArray *sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info
            (void);
          plhs[0] = sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info( int nlhs,
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
        if (strcmp(tpChksum, "vtunm1bQfsejOkpcAplJs") == 0) {
          extern mxArray
            *sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray
            *sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "ykvquPu9OdBFBVkmHjZN2B") == 0) {
          extern mxArray
            *sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "4eOi05p0NzZ1vFZkWpgf7") == 0) {
          extern mxArray
            *sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "BJJ23zA4DpRgbGLiJ1zNAB") == 0) {
          extern mxArray
            *sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "tXTW5U46re7bXoLFU7I6h") == 0) {
          extern mxArray
            *sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "fMp6JfQCSl13MP494T0i3D") == 0) {
          extern mxArray
            *sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "EjuzPTpxHL7hetyxY2aTIB") == 0) {
          extern mxArray
            *sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7Tjii6EYNdbRCJQAty8xHH") == 0) {
          extern mxArray
            *sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "4dHwkzLtkkbWwaqo8FpUpG") == 0) {
          extern mxArray
            *sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray
            *sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray
            *sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "UhzuqpsAzlsRfgj8i0QCiH") == 0) {
          extern mxArray
            *sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "17DFEai06KSaMfKXedga2D") == 0) {
          extern mxArray
            *sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "AlGocMr3QfHKX8uRlIaLKB") == 0) {
          extern mxArray
            *sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "TGPrkLJrq20FF0uBuwEBJH") == 0) {
          extern mxArray
            *sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "IrJx1HAbJxOP0GUtSY6MKC") == 0) {
          extern mxArray
            *sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_ARP_02_RPSs_Bdr_GK_BIS7_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ARP_02_RPSs_Bdr_GK_BIS7_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _ARP_02_RPSs_Bdr_GK_BIS7MachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"ARP_02_RPSs_Bdr_GK_BIS7","sfun",0,17,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ARP_02_RPSs_Bdr_GK_BIS7MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ARP_02_RPSs_Bdr_GK_BIS7MachineNumber_,0);
}

void ARP_02_RPSs_Bdr_GK_BIS7_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ARP_02_RPSs_Bdr_GK_BIS7_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "ARP_02_RPSs_Bdr_GK_BIS7", "ARP_02_RPSs_Bdr_GK_BIS7");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ARP_02_RPSs_Bdr_GK_BIS7_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
