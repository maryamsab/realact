/*
 * File: ert_main.c
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

#include "testArduino_send_serial.h"
#include "Arduino.h"
#define STEP_SIZE                      (unsigned long) (10000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();
  testArduino_send_serial_initialize();

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 9600);

#endif

  /* The main step loop */
  while (rtmGetErrorStatus(testArduino_send_serial_M) == (NULL)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;
      testArduino_send_serial_output();

      /* Get model outputs here */
      testArduino_send_serial_update();
    }
  }

  testArduino_send_serial_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
