/*
 * File: ert_main.c
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

#include "arduinouno_gettingstarted.h"
#include "Arduino.h"
#define STEP_SIZE                      (unsigned long) (100000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();
  arduinouno_gettingstarted_initialize();

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 9600);

#endif

  /* The main step loop */
  while (rtmGetErrorStatus(arduinouno_gettingstarted_M) == (NULL)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;
      arduinouno_gettingstarted_output();

      /* Get model outputs here */
      arduinouno_gettingstarted_update();
    }
  }

  arduinouno_gettingstarted_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
