/*
 * File: arduinouno_gettingstarted.h
 *
 * Code generated for Simulink model 'arduinouno_gettingstarted'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Jan 22 20:39:39 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_arduinouno_gettingstarted_h_
#define RTW_HEADER_arduinouno_gettingstarted_h_
#include <stddef.h>
#include <string.h>
#ifndef arduinouno_gettingstarted_COMMON_INCLUDES_
# define arduinouno_gettingstarted_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* arduinouno_gettingstarted_COMMON_INCLUDES_ */

#include "arduinouno_gettingstarted_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} D_Work_arduinouno_gettingstarte;

/* Parameters (auto storage) */
struct Parameters_arduinouno_gettingst_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_arduinouno_gettingstart {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_arduinouno_gettingst arduinouno_gettingstarted_P;

/* Block states (auto storage) */
extern D_Work_arduinouno_gettingstarte arduinouno_gettingstarted_DWork;

/* Model entry point functions */
extern void arduinouno_gettingstarted_initialize(void);
extern void arduinouno_gettingstarted_output(void);
extern void arduinouno_gettingstarted_update(void);
extern void arduinouno_gettingstarted_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduinouno_gettingstar *const arduinouno_gettingstarted_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'arduinouno_gettingstarted'
 * '<S1>'   : 'arduinouno_gettingstarted/Digital Output'
 */
#endif                                 /* RTW_HEADER_arduinouno_gettingstarted_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
