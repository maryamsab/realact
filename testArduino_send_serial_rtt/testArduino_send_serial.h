/*
 * File: testArduino_send_serial.h
 *
 * Code generated for Simulink model 'testArduino_send_serial'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Sat Jun 06 11:33:15 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testArduino_send_serial_h_
#define RTW_HEADER_testArduino_send_serial_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef testArduino_send_serial_COMMON_INCLUDES_
# define testArduino_send_serial_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_serialwrite_lct.h"
#endif                                 /* testArduino_send_serial_COMMON_INCLUDES_ */

#include "testArduino_send_serial_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_testArduino_send_serial_T_ {
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T Constant2_Value;              /* Expression: 255
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 300
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: .5
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  uint32_T AnalogInput1_p1;            /* Computed Parameter: AnalogInput1_p1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  uint32_T AnalogInput2_p1;            /* Computed Parameter: AnalogInput2_p1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testArduino_send_seri_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_testArduino_send_serial_T testArduino_send_serial_P;

/* Model entry point functions */
extern void testArduino_send_serial_initialize(void);
extern void testArduino_send_serial_output(void);
extern void testArduino_send_serial_update(void);
extern void testArduino_send_serial_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testArduino_send_ser_T *const testArduino_send_serial_M;

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
 * '<Root>' : 'testArduino_send_serial'
 */
#endif                                 /* RTW_HEADER_testArduino_send_serial_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
