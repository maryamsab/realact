/* Include files */

#include "ARP_02_RPSsmile_GloveAtomicBradImitateSmile_sfun.h"
#include "ARP_02_RPSsmile_GloveAtomicBradImitateSmile_sfun_debug_macros.h"
#include "c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile.h"
#include "c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile.h"
#include "c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile.h"
#include "c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile.h"
#include "c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile.h"
#include "c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile.h"
#include "c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ARP_02_RPSsmile_GloveAtomicBradImitateSmileMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ARP_02_RPSsmile_GloveAtomicBradImitateSmile_initializer(void)
{
}

void ARP_02_RPSsmile_GloveAtomicBradImitateSmile_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
  (SimStruct *simstructPtr, unsigned int chartFileNumber, const char* specsCksum,
   int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int
  sf_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1979179510U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1179667143U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3348391930U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2387977130U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3956032059U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(460875120U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1732384384U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(442690949U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void
            sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
            (mxArray *plhs[]);
          sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void
            sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
            (mxArray *plhs[]);
          sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void
            sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
            (mxArray *plhs[]);
          sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void
            sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
            (mxArray *plhs[]);
          sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void
            sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
            (mxArray *plhs[]);
          sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void
            sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
            (mxArray *plhs[]);
          sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void
            sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
            (mxArray *plhs[]);
          sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1247483678U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3334872025U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(824812406U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2450356126U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_autoinheritance_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "aQJuBFb5WnChKvgBhJ8b9") == 0) {
          extern mxArray
            *sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray
            *sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "6ToljhSGzQbPoAkW7t0cfB") == 0) {
          extern mxArray
            *sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "pfe5LwE5nPb8e1tLENIgVG") == 0) {
          extern mxArray
            *sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "6ezM0WmKoQDRwGebJtes2F") == 0) {
          extern mxArray
            *sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "ukardT8rtp15uHdRO3THKD") == 0) {
          extern mxArray
            *sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "fQR6McJaf7aJFgTzB5I01G") == 0) {
          extern mxArray
            *sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_autoinheritance_info
            ();
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

unsigned int
  sf_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
          ();
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

unsigned int
  sf_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info( int nlhs,
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
        if (strcmp(tpChksum, "ydQOvLUQGQ8IMjQOYPGwqE") == 0) {
          extern mxArray
            *sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            ();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray
            *sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            (void);
          plhs[0] =
            sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            ();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray
            *sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            (void);
          plhs[0] =
            sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            ();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "dy3QAvooaS3SxoSkEoeqyB") == 0) {
          extern mxArray
            *sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            (void);
          plhs[0] =
            sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            ();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "vjvUdCmZDgTqlHe6Ig7wZF") == 0) {
          extern mxArray
            *sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            ();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "UjoScM5MWYrdPpVYbhl3UH") == 0) {
          extern mxArray
            *sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            (void);
          plhs[0] =
            sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            ();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "E2GR3O1W4AP0NW0RhmU4eH") == 0) {
          extern mxArray
            *sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            (void);
          plhs[0] =
            sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_third_party_uses_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int
  sf_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "ydQOvLUQGQ8IMjQOYPGwqE") == 0) {
          extern mxArray
            *sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c1_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray
            *sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray
            *sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c3_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "dy3QAvooaS3SxoSkEoeqyB") == 0) {
          extern mxArray
            *sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c4_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "vjvUdCmZDgTqlHe6Ig7wZF") == 0) {
          extern mxArray
            *sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "UjoScM5MWYrdPpVYbhl3UH") == 0) {
          extern mxArray
            *sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c9_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "E2GR3O1W4AP0NW0RhmU4eH") == 0) {
          extern mxArray
            *sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c11_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_updateBuildInfo_args_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ARP_02_RPSsmile_GloveAtomicBradImitateSmile_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _ARP_02_RPSsmile_GloveAtomicBradImitateSmileMachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "ARP_02_RPSsmile_GloveAtomicBradImitateSmile","sfun",0,7,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ARP_02_RPSsmile_GloveAtomicBradImitateSmileMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ARP_02_RPSsmile_GloveAtomicBradImitateSmileMachineNumber_,0);
}

void ARP_02_RPSsmile_GloveAtomicBradImitateSmile_register_exported_symbols
  (SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "ARP_02_RPSsmile_GloveAtomicBradImitateSmile",
      "ARP_02_RPSsmile_GloveAtomicBradImitateSmile");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
