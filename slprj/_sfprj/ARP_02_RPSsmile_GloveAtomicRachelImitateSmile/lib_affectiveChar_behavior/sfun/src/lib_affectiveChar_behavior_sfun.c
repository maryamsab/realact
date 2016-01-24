/* Include files */

#include "lib_affectiveChar_behavior_sfun.h"
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#include "c4_lib_affectiveChar_behavior.h"
#include "c9_lib_affectiveChar_behavior.h"
#include "c10_lib_affectiveChar_behavior.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _lib_affectiveChar_behaviorMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void lib_affectiveChar_behavior_initializer(void)
{
}

void lib_affectiveChar_behavior_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_lib_affectiveChar_behavior_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==4) {
    c4_lib_affectiveChar_behavior_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_lib_affectiveChar_behavior_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_lib_affectiveChar_behavior_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_lib_affectiveChar_behavior_process_check_sum_call( int nlhs,
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
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"lib_affectiveChar_behavior")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1141728185U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(613938785U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(332591040U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2994403004U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 4:
            {
              extern void sf_c4_lib_affectiveChar_behavior_get_check_sum(mxArray
                *plhs[]);
              sf_c4_lib_affectiveChar_behavior_get_check_sum(plhs);
              break;
            }

           case 9:
            {
              extern void sf_c9_lib_affectiveChar_behavior_get_check_sum(mxArray
                *plhs[]);
              sf_c9_lib_affectiveChar_behavior_get_check_sum(plhs);
              break;
            }

           case 10:
            {
              extern void sf_c10_lib_affectiveChar_behavior_get_check_sum
                (mxArray *plhs[]);
              sf_c10_lib_affectiveChar_behavior_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lib_affectiveChar_behavior_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 4:
      {
        if (strcmp(aiChksum, "nUXMIuadCFn7H5tBNxvITB") == 0) {
          extern mxArray
            *sf_c4_lib_affectiveChar_behavior_get_autoinheritance_info(void);
          plhs[0] = sf_c4_lib_affectiveChar_behavior_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "TiMFJpjNfXjVCr26RuBhtH") == 0) {
          extern mxArray
            *sf_c9_lib_affectiveChar_behavior_get_autoinheritance_info(void);
          plhs[0] = sf_c9_lib_affectiveChar_behavior_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "xeAdvcDfVS6AdmGYmsw1dF") == 0) {
          extern mxArray
            *sf_c10_lib_affectiveChar_behavior_get_autoinheritance_info(void);
          plhs[0] = sf_c10_lib_affectiveChar_behavior_get_autoinheritance_info();
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

unsigned int sf_lib_affectiveChar_behavior_get_eml_resolved_functions_info( int
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
     case 4:
      {
        extern const mxArray
          *sf_c4_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_lib_affectiveChar_behavior_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_lib_affectiveChar_behavior_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_lib_affectiveChar_behavior_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_lib_affectiveChar_behavior_get_eml_resolved_functions_info();
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

unsigned int sf_lib_affectiveChar_behavior_third_party_uses_info( int nlhs,
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
     case 4:
      {
        if (strcmp(tpChksum, "7FQEvg8ca4fQyPYEI54DBE") == 0) {
          extern mxArray *sf_c4_lib_affectiveChar_behavior_third_party_uses_info
            (void);
          plhs[0] = sf_c4_lib_affectiveChar_behavior_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "vYpGM9Ctc62mw24y8Axmi") == 0) {
          extern mxArray *sf_c9_lib_affectiveChar_behavior_third_party_uses_info
            (void);
          plhs[0] = sf_c9_lib_affectiveChar_behavior_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "DFaiVSEXBj6jcv7PEwIYkC") == 0) {
          extern mxArray
            *sf_c10_lib_affectiveChar_behavior_third_party_uses_info(void);
          plhs[0] = sf_c10_lib_affectiveChar_behavior_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_lib_affectiveChar_behavior_updateBuildInfo_args_info( int nlhs,
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
     case 4:
      {
        if (strcmp(tpChksum, "7FQEvg8ca4fQyPYEI54DBE") == 0) {
          extern mxArray
            *sf_c4_lib_affectiveChar_behavior_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_lib_affectiveChar_behavior_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "vYpGM9Ctc62mw24y8Axmi") == 0) {
          extern mxArray
            *sf_c9_lib_affectiveChar_behavior_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_lib_affectiveChar_behavior_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "DFaiVSEXBj6jcv7PEwIYkC") == 0) {
          extern mxArray
            *sf_c10_lib_affectiveChar_behavior_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_lib_affectiveChar_behavior_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void lib_affectiveChar_behavior_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _lib_affectiveChar_behaviorMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"lib_affectiveChar_behavior","sfun",1,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _lib_affectiveChar_behaviorMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _lib_affectiveChar_behaviorMachineNumber_,0);
}

void lib_affectiveChar_behavior_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_lib_affectiveChar_behavior_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "lib_affectiveChar_behavior",
      "ARP_02_RPSsmile_GloveAtomicRachelImitateSmile");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_lib_affectiveChar_behavior_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
