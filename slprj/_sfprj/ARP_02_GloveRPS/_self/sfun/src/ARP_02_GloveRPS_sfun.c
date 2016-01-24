/* Include files */

#include "ARP_02_GloveRPS_sfun.h"
#include "ARP_02_GloveRPS_sfun_debug_macros.h"
#include "c1_ARP_02_GloveRPS.h"
#include "c2_ARP_02_GloveRPS.h"
#include "c3_ARP_02_GloveRPS.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ARP_02_GloveRPSMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ARP_02_GloveRPS_initializer(void)
{
}

void ARP_02_GloveRPS_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ARP_02_GloveRPS_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_ARP_02_GloveRPS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_ARP_02_GloveRPS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_ARP_02_GloveRPS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ARP_02_GloveRPS_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(173692154U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2371338415U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1842238928U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2222755092U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3320639127U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2129564017U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3931394745U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3916111457U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_ARP_02_GloveRPS_get_check_sum(mxArray *plhs[]);
          sf_c1_ARP_02_GloveRPS_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_ARP_02_GloveRPS_get_check_sum(mxArray *plhs[]);
          sf_c2_ARP_02_GloveRPS_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_ARP_02_GloveRPS_get_check_sum(mxArray *plhs[]);
          sf_c3_ARP_02_GloveRPS_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1087891772U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1726446984U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1669444611U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2503911172U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ARP_02_GloveRPS_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "76yfD3eYSjcdtwEw0gbSzD") == 0) {
          extern mxArray *sf_c1_ARP_02_GloveRPS_get_autoinheritance_info(void);
          plhs[0] = sf_c1_ARP_02_GloveRPS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "5qrLGjGP1vIkrom2MMIbKD") == 0) {
          extern mxArray *sf_c2_ARP_02_GloveRPS_get_autoinheritance_info(void);
          plhs[0] = sf_c2_ARP_02_GloveRPS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "6ToljhSGzQbPoAkW7t0cfB") == 0) {
          extern mxArray *sf_c3_ARP_02_GloveRPS_get_autoinheritance_info(void);
          plhs[0] = sf_c3_ARP_02_GloveRPS_get_autoinheritance_info();
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

unsigned int sf_ARP_02_GloveRPS_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_ARP_02_GloveRPS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ARP_02_GloveRPS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_ARP_02_GloveRPS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_ARP_02_GloveRPS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_ARP_02_GloveRPS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_ARP_02_GloveRPS_get_eml_resolved_functions_info();
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

unsigned int sf_ARP_02_GloveRPS_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "WsBSVee3NEfEapS74B5WQE") == 0) {
          extern mxArray *sf_c1_ARP_02_GloveRPS_third_party_uses_info(void);
          plhs[0] = sf_c1_ARP_02_GloveRPS_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "0jGUY2zLfEmy84SXNG14QD") == 0) {
          extern mxArray *sf_c2_ARP_02_GloveRPS_third_party_uses_info(void);
          plhs[0] = sf_c2_ARP_02_GloveRPS_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray *sf_c3_ARP_02_GloveRPS_third_party_uses_info(void);
          plhs[0] = sf_c3_ARP_02_GloveRPS_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_ARP_02_GloveRPS_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "WsBSVee3NEfEapS74B5WQE") == 0) {
          extern mxArray *sf_c1_ARP_02_GloveRPS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_ARP_02_GloveRPS_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "0jGUY2zLfEmy84SXNG14QD") == 0) {
          extern mxArray *sf_c2_ARP_02_GloveRPS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_ARP_02_GloveRPS_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OOW2Tl6JPQYbKDKv7yiUm") == 0) {
          extern mxArray *sf_c3_ARP_02_GloveRPS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_ARP_02_GloveRPS_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ARP_02_GloveRPS_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _ARP_02_GloveRPSMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "ARP_02_GloveRPS","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ARP_02_GloveRPSMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ARP_02_GloveRPSMachineNumber_,0);
}

void ARP_02_GloveRPS_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ARP_02_GloveRPS_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("ARP_02_GloveRPS",
      "ARP_02_GloveRPS");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ARP_02_GloveRPS_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
