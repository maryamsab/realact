/* Include files */

#include "ARP_02_RPSs_Bdr_GK_BIS2_sfun.h"
#include "ARP_02_RPSs_Bdr_GK_BIS2_sfun_debug_macros.h"
#include "c1_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c2_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c4_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c5_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c8_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c9_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c10_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c11_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c12_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c13_ARP_02_RPSs_Bdr_GK_BIS2.h"
#include "c14_ARP_02_RPSs_Bdr_GK_BIS2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ARP_02_RPSs_Bdr_GK_BIS2_initializer(void)
{
}

void ARP_02_RPSs_Bdr_GK_BIS2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS2_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(234584191U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3947376799U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(117772956U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4240032476U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(172309982U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(606344759U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(899037997U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4281230281U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *plhs[]);
          sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *plhs[]);
          sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *plhs[]);
          sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *plhs[]);
          sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *plhs[]);
          sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *plhs[]);
          sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *
            plhs[]);
          sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *
            plhs[]);
          sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *
            plhs[]);
          sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *
            plhs[]);
          sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *
            plhs[]);
          sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(42450688U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(779729243U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4057494930U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3878656065U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS2_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "EMEshIdcT0SKae3tFmqpYD") == 0) {
          extern mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ytkMaZ3LJMwsAy7iUSYW1D") == 0) {
          extern mxArray *sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "iW2CyKObIKVRpTOipF50dH") == 0) {
          extern mxArray *sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "waH5BHQ1ouhQgLLLqTglO") == 0) {
          extern mxArray *sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "CUtaesdz1RW2ur4fqzTDdD") == 0) {
          extern mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "H7us5heVagtFoWlGDwN0FG") == 0) {
          extern mxArray *sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "WlNE5pVIKznzaso1mHbuTC") == 0) {
          extern mxArray
            *sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info(void);
          plhs[0] = sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "is6AU9kPSkQghKDz8S9VNB") == 0) {
          extern mxArray
            *sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info(void);
          plhs[0] = sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "CxSZl1m0ZFmftPhrCfiEtC") == 0) {
          extern mxArray
            *sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info(void);
          plhs[0] = sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "yPPzDIGn5DPyGYnrHi4YC") == 0) {
          extern mxArray
            *sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info(void);
          plhs[0] = sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "fbs1NXNu3p3DqJAjoWAIqB") == 0) {
          extern mxArray
            *sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info(void);
          plhs[0] = sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info();
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

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info( int
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
          *sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info();
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

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info( int nlhs, mxArray
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
        if (strcmp(tpChksum, "5alC3G4oQqNVyUJ8kq9eVG") == 0) {
          extern mxArray *sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray *sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "ubOV4XSUWIMcfFhacoMCDB") == 0) {
          extern mxArray *sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "E3sBX58bsGBJDMYHN2hRmB") == 0) {
          extern mxArray *sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "L11bSfQay4wwlal1upqKvH") == 0) {
          extern mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "BmClPqAeAB26Q03RaXR0CD") == 0) {
          extern mxArray *sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "nOHyJhmBcYDb8m3o7mZRUH") == 0) {
          extern mxArray *sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "g3rGzsND5Abp8z6QbCe7IE") == 0) {
          extern mxArray *sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "J9fOV5ZumkphtzE3119zt") == 0) {
          extern mxArray *sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray *sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray *sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info
            (void);
          plhs[0] = sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info( int nlhs,
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
        if (strcmp(tpChksum, "5alC3G4oQqNVyUJ8kq9eVG") == 0) {
          extern mxArray
            *sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NSK499r8cFPIhmkqjLQ4b") == 0) {
          extern mxArray
            *sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "ubOV4XSUWIMcfFhacoMCDB") == 0) {
          extern mxArray
            *sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "E3sBX58bsGBJDMYHN2hRmB") == 0) {
          extern mxArray
            *sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "L11bSfQay4wwlal1upqKvH") == 0) {
          extern mxArray
            *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "BmClPqAeAB26Q03RaXR0CD") == 0) {
          extern mxArray
            *sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "nOHyJhmBcYDb8m3o7mZRUH") == 0) {
          extern mxArray
            *sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "g3rGzsND5Abp8z6QbCe7IE") == 0) {
          extern mxArray
            *sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "J9fOV5ZumkphtzE3119zt") == 0) {
          extern mxArray
            *sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "VZfXNM4KOIJnHIJQbCXPV") == 0) {
          extern mxArray
            *sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "0SPQndq0eBfRnwfWVNvXT") == 0) {
          extern mxArray
            *sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ARP_02_RPSs_Bdr_GK_BIS2_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"ARP_02_RPSs_Bdr_GK_BIS2","sfun",0,11,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,0);
}

void ARP_02_RPSs_Bdr_GK_BIS2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ARP_02_RPSs_Bdr_GK_BIS2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "ARP_02_RPSs_Bdr_GK_BIS2", "ARP_02_RPSs_Bdr_GK_BIS2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ARP_02_RPSs_Bdr_GK_BIS2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
