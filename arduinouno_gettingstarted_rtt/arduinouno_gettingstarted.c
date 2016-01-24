/*
 * File: arduinouno_gettingstarted.c
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
#include "arduinouno_gettingstarted_private.h"

/* Block states (auto storage) */
D_Work_arduinouno_gettingstarte arduinouno_gettingstarted_DWork;

/* Real-time model */
RT_MODEL_arduinouno_gettingstar arduinouno_gettingstarted_M_;
RT_MODEL_arduinouno_gettingstar *const arduinouno_gettingstarted_M =
  &arduinouno_gettingstarted_M_;

/* Model output function */
void arduinouno_gettingstarted_output(void)
{
  real_T rtb_PulseGenerator;
  uint8_T rtb_PulseGenerator_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (arduinouno_gettingstarted_DWork.clockTickCounter <
                        arduinouno_gettingstarted_P.PulseGenerator_Duty) &&
    (arduinouno_gettingstarted_DWork.clockTickCounter >= 0L) ?
    arduinouno_gettingstarted_P.PulseGenerator_Amp : 0.0;
  if (arduinouno_gettingstarted_DWork.clockTickCounter >=
      arduinouno_gettingstarted_P.PulseGenerator_Period - 1.0) {
    arduinouno_gettingstarted_DWork.clockTickCounter = 0L;
  } else {
    arduinouno_gettingstarted_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      rtb_PulseGenerator_0 = (uint8_T)rtb_PulseGenerator;
    } else {
      rtb_PulseGenerator_0 = 0U;
    }
  } else {
    rtb_PulseGenerator_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_digitalWrite(arduinouno_gettingstarted_P.DigitalOutput_pinNumber,
                  rtb_PulseGenerator_0);
}

/* Model update function */
void arduinouno_gettingstarted_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void arduinouno_gettingstarted_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(arduinouno_gettingstarted_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&arduinouno_gettingstarted_DWork, 0,
                sizeof(D_Work_arduinouno_gettingstarte));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  arduinouno_gettingstarted_DWork.clockTickCounter = 0L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(arduinouno_gettingstarted_P.DigitalOutput_pinNumber);
}

/* Model terminate function */
void arduinouno_gettingstarted_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
