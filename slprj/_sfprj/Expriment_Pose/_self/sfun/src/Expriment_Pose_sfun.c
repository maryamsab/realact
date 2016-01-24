/* Include files */

#include "Expriment_Pose_sfun.h"
#include "Expriment_Pose_sfun_debug_macros.h"
#include "c1_Expriment_Pose.h"
#include "c2_Expriment_Pose.h"
#include "c4_Expriment_Pose.h"
#include "c5_Expriment_Pose.h"
#include "c8_Expriment_Pose.h"
#include "c9_Expriment_Pose.h"
#include "c10_Expriment_Pose.h"
#include "c11_Expriment_Pose.h"
#include "c12_Expriment_Pose.h"
#include "c13_Expriment_Pose.h"
#include "c14_Expriment_Pose.h"
#include "c15_Expriment_Pose.h"
#include "c16_Expriment_Pose.h"
#include "c17_Expriment_Pose.h"
#include "c20_Expriment_Pose.h"
#include "c21_Expriment_Pose.h"
#include "c35_Expriment_Pose.h"
#include "c37_Expriment_Pose.h"
#include "c38_Expriment_Pose.h"
#include "c39_Expriment_Pose.h"
#include "c40_Expriment_Pose.h"
#include "c41_Expriment_Pose.h"
#include "c42_Expriment_Pose.h"
#include "c43_Expriment_Pose.h"
#include "c44_Expriment_Pose.h"
#include "c45_Expriment_Pose.h"
#include "c50_Expriment_Pose.h"
#include "c51_Expriment_Pose.h"
#include "c52_Expriment_Pose.h"
#include "c53_Expriment_Pose.h"
#include "c54_Expriment_Pose.h"
#include "c55_Expriment_Pose.h"
#include "c56_Expriment_Pose.h"
#include "c57_Expriment_Pose.h"
#include "c58_Expriment_Pose.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Expriment_PoseMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Expriment_Pose_initializer(void)
{
}

void Expriment_Pose_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Expriment_Pose_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==40) {
    c40_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==42) {
    c42_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==44) {
    c44_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==45) {
    c45_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==50) {
    c50_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==51) {
    c51_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==52) {
    c52_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==53) {
    c53_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==54) {
    c54_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==55) {
    c55_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==56) {
    c56_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==57) {
    c57_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==58) {
    c58_Expriment_Pose_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Expriment_Pose_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3961933143U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1320248210U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1702520205U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(217445812U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3258232315U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(444439281U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2785340849U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(810126441U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c1_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c2_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c4_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c5_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c8_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c9_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c10_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c11_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c12_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c13_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c14_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c15_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c16_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c17_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c20_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c21_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c35_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c37_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c38_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c39_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 40:
        {
          extern void sf_c40_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c40_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c41_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 42:
        {
          extern void sf_c42_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c42_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c43_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 44:
        {
          extern void sf_c44_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c44_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 45:
        {
          extern void sf_c45_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c45_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 50:
        {
          extern void sf_c50_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c50_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 51:
        {
          extern void sf_c51_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c51_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 52:
        {
          extern void sf_c52_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c52_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 53:
        {
          extern void sf_c53_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c53_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 54:
        {
          extern void sf_c54_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c54_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 55:
        {
          extern void sf_c55_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c55_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 56:
        {
          extern void sf_c56_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c56_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 57:
        {
          extern void sf_c57_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c57_Expriment_Pose_get_check_sum(plhs);
          break;
        }

       case 58:
        {
          extern void sf_c58_Expriment_Pose_get_check_sum(mxArray *plhs[]);
          sf_c58_Expriment_Pose_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2359097082U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3796390101U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1715688013U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1394626621U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Expriment_Pose_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "ULotPrFHTgKhnRzKjJmig") == 0) {
          extern mxArray *sf_c1_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "8bHhZunCj25HPmAsvraoWB") == 0) {
          extern mxArray *sf_c4_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "WdToWhQ1o1aRqVKbPAqsMH") == 0) {
          extern mxArray *sf_c5_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "sugYXALnGR1TONbTbCwvhD") == 0) {
          extern mxArray *sf_c8_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c8_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "5cmJkGcL7kKbEWuA4wMehE") == 0) {
          extern mxArray *sf_c9_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c9_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Psqi8ilzBpGHBiSNif5PoE") == 0) {
          extern mxArray *sf_c10_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c10_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "s1oeJOY4xY9kyRm5c3Q1I") == 0) {
          extern mxArray *sf_c11_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c11_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "DhoVYgIDduzaygrqenV8YH") == 0) {
          extern mxArray *sf_c12_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c12_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "DhoVYgIDduzaygrqenV8YH") == 0) {
          extern mxArray *sf_c13_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c13_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "j76GD0s4Ca7L2Wh8C1DBCG") == 0) {
          extern mxArray *sf_c14_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c14_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "gBg2zmus4QIe1mlUyi0CLG") == 0) {
          extern mxArray *sf_c15_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c15_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "1ZHcZ9HuksFRgnQ5yLbgsG") == 0) {
          extern mxArray *sf_c16_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c16_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "VpuJLrkkZFJktQtxLkPKvE") == 0) {
          extern mxArray *sf_c17_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c17_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "OBARG9Lt1IZw8WhenTJ2zF") == 0) {
          extern mxArray *sf_c20_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c20_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "XFQhRbw3X53oJvICkXhK9D") == 0) {
          extern mxArray *sf_c21_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c21_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 35:
      {
        if (strcmp(aiChksum, "gmHZYixc2ddsg0UFuGrrHC") == 0) {
          extern mxArray *sf_c35_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c35_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "mvMGcuHSeH872pn0xeK8q") == 0) {
          extern mxArray *sf_c37_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c37_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 38:
      {
        if (strcmp(aiChksum, "DsGiFVf3BSSsPxOzqVwzkE") == 0) {
          extern mxArray *sf_c38_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c38_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "zW6NXDTShv8JiUhNTzhYcD") == 0) {
          extern mxArray *sf_c39_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c39_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 40:
      {
        if (strcmp(aiChksum, "PBOOE2ONCJlr45MWsYJj7G") == 0) {
          extern mxArray *sf_c40_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c40_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "wV3dApGy4UjoUifsNOiIRE") == 0) {
          extern mxArray *sf_c41_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c41_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 42:
      {
        if (strcmp(aiChksum, "hjYKfAatEuC2c3x7oJD87B") == 0) {
          extern mxArray *sf_c42_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c42_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "OyIZ4INnb2VrYIt5UCJNU") == 0) {
          extern mxArray *sf_c43_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c43_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 44:
      {
        if (strcmp(aiChksum, "it3IJwiChHzZthFdSexajD") == 0) {
          extern mxArray *sf_c44_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c44_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 45:
      {
        if (strcmp(aiChksum, "PBOOE2ONCJlr45MWsYJj7G") == 0) {
          extern mxArray *sf_c45_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c45_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 50:
      {
        if (strcmp(aiChksum, "KRq2LRephOappHkB1touEE") == 0) {
          extern mxArray *sf_c50_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c50_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 51:
      {
        if (strcmp(aiChksum, "DFtrIDSgrdi2jiSGnkZtlD") == 0) {
          extern mxArray *sf_c51_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c51_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 52:
      {
        if (strcmp(aiChksum, "EuZRnyhPFvbAKeV9Xs3xlD") == 0) {
          extern mxArray *sf_c52_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c52_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 53:
      {
        if (strcmp(aiChksum, "DFtrIDSgrdi2jiSGnkZtlD") == 0) {
          extern mxArray *sf_c53_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c53_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 54:
      {
        if (strcmp(aiChksum, "OyIZ4INnb2VrYIt5UCJNU") == 0) {
          extern mxArray *sf_c54_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c54_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 55:
      {
        if (strcmp(aiChksum, "EuZRnyhPFvbAKeV9Xs3xlD") == 0) {
          extern mxArray *sf_c55_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c55_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 56:
      {
        if (strcmp(aiChksum, "wV3dApGy4UjoUifsNOiIRE") == 0) {
          extern mxArray *sf_c56_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c56_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 57:
      {
        if (strcmp(aiChksum, "BjT4YKkcreBAmpbQuEItFF") == 0) {
          extern mxArray *sf_c57_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c57_Expriment_Pose_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 58:
      {
        if (strcmp(aiChksum, "S954SW2RZeFUPsEwVaqQHC") == 0) {
          extern mxArray *sf_c58_Expriment_Pose_get_autoinheritance_info(void);
          plhs[0] = sf_c58_Expriment_Pose_get_autoinheritance_info();
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

unsigned int sf_Expriment_Pose_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray
          *sf_c35_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray
          *sf_c38_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray
          *sf_c39_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 40:
      {
        extern const mxArray
          *sf_c40_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c40_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray
          *sf_c41_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 42:
      {
        extern const mxArray
          *sf_c42_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c42_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 44:
      {
        extern const mxArray
          *sf_c44_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c44_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 45:
      {
        extern const mxArray
          *sf_c45_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c45_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 50:
      {
        extern const mxArray
          *sf_c50_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c50_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 51:
      {
        extern const mxArray
          *sf_c51_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c51_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 52:
      {
        extern const mxArray
          *sf_c52_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c52_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 53:
      {
        extern const mxArray
          *sf_c53_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c53_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 54:
      {
        extern const mxArray
          *sf_c54_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c54_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 55:
      {
        extern const mxArray
          *sf_c55_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c55_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 56:
      {
        extern const mxArray
          *sf_c56_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c56_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 57:
      {
        extern const mxArray
          *sf_c57_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c57_Expriment_Pose_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 58:
      {
        extern const mxArray
          *sf_c58_Expriment_Pose_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c58_Expriment_Pose_get_eml_resolved_functions_info();
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

unsigned int sf_Expriment_Pose_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "Y4uiLWpskex5syR9q8ny8B") == 0) {
          extern mxArray *sf_c1_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c1_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c2_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "dOEuLbRIhBnoWg6hQMu0sD") == 0) {
          extern mxArray *sf_c4_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c4_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "9r6dOo1C7vSvBUqRkGsLYG") == 0) {
          extern mxArray *sf_c5_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c5_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "r1oBQlcwAu6P5EDjTzX8hC") == 0) {
          extern mxArray *sf_c8_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c8_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "Et6HTWa0s0HbnNBJ5cQaN") == 0) {
          extern mxArray *sf_c9_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c9_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a9oTrvWOrOFZTRixUhix2D") == 0) {
          extern mxArray *sf_c10_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c10_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bi1UvSLMdL51l56dLnoKWF") == 0) {
          extern mxArray *sf_c11_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c11_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "5u7Cw7rrbDyE00DesPxmND") == 0) {
          extern mxArray *sf_c12_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c12_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "5u7Cw7rrbDyE00DesPxmND") == 0) {
          extern mxArray *sf_c13_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c13_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "vg3aMI7s6vwSZMdEdNfo5D") == 0) {
          extern mxArray *sf_c14_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c14_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c15_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "QvGt3tBWcy7cZIQEwILXMG") == 0) {
          extern mxArray *sf_c16_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c16_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c17_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c20_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c21_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "tJuDfgpll5BrF182OjlB8E") == 0) {
          extern mxArray *sf_c35_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c35_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c37_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "94EHSMjC42UJTIOKUCRIaE") == 0) {
          extern mxArray *sf_c38_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c38_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "GQRRxK26Fo9W78HGbrQvAB") == 0) {
          extern mxArray *sf_c39_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c39_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "7M3xs6TX5bpbbfWKpdDrXE") == 0) {
          extern mxArray *sf_c40_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c40_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c41_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c41_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "9ZuQPV6vWam1fXX1qKZM0C") == 0) {
          extern mxArray *sf_c42_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c42_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "LTvX8lll5piFXxb8H1s43") == 0) {
          extern mxArray *sf_c43_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c43_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "FtbliyM4V3UAb35sLOw0Z") == 0) {
          extern mxArray *sf_c44_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c44_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "TYRfK1GKG3nJxBPOVXmiwG") == 0) {
          extern mxArray *sf_c45_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c45_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "a4qMZRIqLdmT1S9dgaqlWB") == 0) {
          extern mxArray *sf_c50_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c50_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 51:
      {
        if (strcmp(tpChksum, "oytKHzSsRYL5CIZCW78XOC") == 0) {
          extern mxArray *sf_c51_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c51_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 52:
      {
        if (strcmp(tpChksum, "G8dVEy14Q9jhJKpvmXcxPD") == 0) {
          extern mxArray *sf_c52_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c52_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 53:
      {
        if (strcmp(tpChksum, "oytKHzSsRYL5CIZCW78XOC") == 0) {
          extern mxArray *sf_c53_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c53_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 54:
      {
        if (strcmp(tpChksum, "LTvX8lll5piFXxb8H1s43") == 0) {
          extern mxArray *sf_c54_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c54_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 55:
      {
        if (strcmp(tpChksum, "G8dVEy14Q9jhJKpvmXcxPD") == 0) {
          extern mxArray *sf_c55_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c55_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 56:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c56_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c56_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 57:
      {
        if (strcmp(tpChksum, "1Dtbk04wVvJHS1DpRCSd6F") == 0) {
          extern mxArray *sf_c57_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c57_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     case 58:
      {
        if (strcmp(tpChksum, "57O7vadCeH0X7PHMa1NeqF") == 0) {
          extern mxArray *sf_c58_Expriment_Pose_third_party_uses_info(void);
          plhs[0] = sf_c58_Expriment_Pose_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Expriment_Pose_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "Y4uiLWpskex5syR9q8ny8B") == 0) {
          extern mxArray *sf_c1_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "dOEuLbRIhBnoWg6hQMu0sD") == 0) {
          extern mxArray *sf_c4_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "9r6dOo1C7vSvBUqRkGsLYG") == 0) {
          extern mxArray *sf_c5_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "r1oBQlcwAu6P5EDjTzX8hC") == 0) {
          extern mxArray *sf_c8_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "Et6HTWa0s0HbnNBJ5cQaN") == 0) {
          extern mxArray *sf_c9_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "a9oTrvWOrOFZTRixUhix2D") == 0) {
          extern mxArray *sf_c10_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Bi1UvSLMdL51l56dLnoKWF") == 0) {
          extern mxArray *sf_c11_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "5u7Cw7rrbDyE00DesPxmND") == 0) {
          extern mxArray *sf_c12_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "5u7Cw7rrbDyE00DesPxmND") == 0) {
          extern mxArray *sf_c13_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "vg3aMI7s6vwSZMdEdNfo5D") == 0) {
          extern mxArray *sf_c14_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "qwIbBC2oblP3Re0wu76IvF") == 0) {
          extern mxArray *sf_c15_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "QvGt3tBWcy7cZIQEwILXMG") == 0) {
          extern mxArray *sf_c16_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "5eBYl8Ef1qpoEitlDh9wl") == 0) {
          extern mxArray *sf_c17_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "6OMVqaV91894wFHVDApi3E") == 0) {
          extern mxArray *sf_c20_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "XYEmHzzCV7F5PmY21Ga2VF") == 0) {
          extern mxArray *sf_c21_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "tJuDfgpll5BrF182OjlB8E") == 0) {
          extern mxArray *sf_c35_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c35_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "mgNqmw8cvZcbuXmBbTrp9") == 0) {
          extern mxArray *sf_c37_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "94EHSMjC42UJTIOKUCRIaE") == 0) {
          extern mxArray *sf_c38_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c38_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "GQRRxK26Fo9W78HGbrQvAB") == 0) {
          extern mxArray *sf_c39_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c39_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "7M3xs6TX5bpbbfWKpdDrXE") == 0) {
          extern mxArray *sf_c40_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c40_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c41_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c41_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "9ZuQPV6vWam1fXX1qKZM0C") == 0) {
          extern mxArray *sf_c42_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c42_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "LTvX8lll5piFXxb8H1s43") == 0) {
          extern mxArray *sf_c43_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "FtbliyM4V3UAb35sLOw0Z") == 0) {
          extern mxArray *sf_c44_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c44_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "TYRfK1GKG3nJxBPOVXmiwG") == 0) {
          extern mxArray *sf_c45_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c45_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "a4qMZRIqLdmT1S9dgaqlWB") == 0) {
          extern mxArray *sf_c50_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c50_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 51:
      {
        if (strcmp(tpChksum, "oytKHzSsRYL5CIZCW78XOC") == 0) {
          extern mxArray *sf_c51_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c51_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 52:
      {
        if (strcmp(tpChksum, "G8dVEy14Q9jhJKpvmXcxPD") == 0) {
          extern mxArray *sf_c52_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c52_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 53:
      {
        if (strcmp(tpChksum, "oytKHzSsRYL5CIZCW78XOC") == 0) {
          extern mxArray *sf_c53_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c53_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 54:
      {
        if (strcmp(tpChksum, "LTvX8lll5piFXxb8H1s43") == 0) {
          extern mxArray *sf_c54_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c54_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 55:
      {
        if (strcmp(tpChksum, "G8dVEy14Q9jhJKpvmXcxPD") == 0) {
          extern mxArray *sf_c55_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c55_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 56:
      {
        if (strcmp(tpChksum, "cZMQbQbePgDFjmQXwdlDSC") == 0) {
          extern mxArray *sf_c56_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c56_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 57:
      {
        if (strcmp(tpChksum, "1Dtbk04wVvJHS1DpRCSd6F") == 0) {
          extern mxArray *sf_c57_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c57_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     case 58:
      {
        if (strcmp(tpChksum, "57O7vadCeH0X7PHMa1NeqF") == 0) {
          extern mxArray *sf_c58_Expriment_Pose_updateBuildInfo_args_info(void);
          plhs[0] = sf_c58_Expriment_Pose_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Expriment_Pose_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Expriment_PoseMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Expriment_Pose","sfun",0,35,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Expriment_PoseMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Expriment_PoseMachineNumber_,0);
}

void Expriment_Pose_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Expriment_Pose_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Expriment_Pose",
      "Expriment_Pose");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Expriment_Pose_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
