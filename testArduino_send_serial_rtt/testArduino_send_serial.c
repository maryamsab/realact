/*
 * File: testArduino_send_serial.c
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
#include "testArduino_send_serial_private.h"

/* Real-time model */
RT_MODEL_testArduino_send_ser_T testArduino_send_serial_M_;
RT_MODEL_testArduino_send_ser_T *const testArduino_send_serial_M =
  &testArduino_send_serial_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (testArduino_send_serial_M->Timing.TaskCounters.TID[1])++;
  if ((testArduino_send_serial_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    testArduino_send_serial_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function */
void testArduino_send_serial_output(void)
{
  uint16_T rtb_AnalogInput_0;
  uint16_T rtb_AnalogInput1_0;
  uint16_T rtb_AnalogInput2_0;
  uint8_T tmp[3];
  real_T u;
  real_T v;
  if (testArduino_send_serial_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
    rtb_AnalogInput_0 = MW_analogRead(testArduino_send_serial_P.AnalogInput_p1);

    /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input1' */
    rtb_AnalogInput1_0 = MW_analogRead(testArduino_send_serial_P.AnalogInput1_p1);

    /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input2' */
    rtb_AnalogInput2_0 = MW_analogRead(testArduino_send_serial_P.AnalogInput2_p1);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant2'
     *  Product: '<Root>/Product'
     *  S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input'
     *  Sum: '<Root>/Subtract'
     *  Sum: '<Root>/Subtract1'
     */
    u = testArduino_send_serial_P.Constant2_Value - ((real_T)rtb_AnalogInput_0 -
      testArduino_send_serial_P.Constant_Value) *
      testArduino_send_serial_P.Constant1_Value;
    v = fabs(u);
    if (v < 4.503599627370496E+15) {
      if (v >= 0.5) {
        u = floor(u + 0.5);
      } else {
        u *= 0.0;
      }
    }

    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = fmod(u, 256.0);
    }

    /* S-Function (arduinoserialwrite_sfcn): '<Root>/Serial Transmit' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Sum: '<Root>/Subtract'
     */
    tmp[0] = (uint8_T)(u < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-u :
                       (int16_T)(uint8_T)u);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant2'
     *  Product: '<Root>/Product'
     *  S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input1'
     *  Sum: '<Root>/Subtract'
     *  Sum: '<Root>/Subtract1'
     */
    u = testArduino_send_serial_P.Constant2_Value - ((real_T)rtb_AnalogInput1_0
      - testArduino_send_serial_P.Constant_Value) *
      testArduino_send_serial_P.Constant1_Value;
    v = fabs(u);
    if (v < 4.503599627370496E+15) {
      if (v >= 0.5) {
        u = floor(u + 0.5);
      } else {
        u *= 0.0;
      }
    }

    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = fmod(u, 256.0);
    }

    /* S-Function (arduinoserialwrite_sfcn): '<Root>/Serial Transmit' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Sum: '<Root>/Subtract'
     */
    tmp[1] = (uint8_T)(u < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-u :
                       (int16_T)(uint8_T)u);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant2'
     *  Product: '<Root>/Product'
     *  S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input2'
     *  Sum: '<Root>/Subtract'
     *  Sum: '<Root>/Subtract1'
     */
    u = testArduino_send_serial_P.Constant2_Value - ((real_T)rtb_AnalogInput2_0
      - testArduino_send_serial_P.Constant_Value) *
      testArduino_send_serial_P.Constant1_Value;
    v = fabs(u);
    if (v < 4.503599627370496E+15) {
      if (v >= 0.5) {
        u = floor(u + 0.5);
      } else {
        u *= 0.0;
      }
    }

    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = fmod(u, 256.0);
    }

    /* S-Function (arduinoserialwrite_sfcn): '<Root>/Serial Transmit' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Sum: '<Root>/Subtract'
     */
    tmp[2] = (uint8_T)(u < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-u :
                       (int16_T)(uint8_T)u);
    Serial_write(testArduino_send_serial_P.SerialTransmit_portNumber, tmp, 3UL);
  }
}

/* Model update function */
void testArduino_send_serial_update(void)
{
  rate_scheduler();
}

/* Model initialize function */
void testArduino_send_serial_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testArduino_send_serial_M, 0,
                sizeof(RT_MODEL_testArduino_send_ser_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  MW_pinModeAnalogInput(testArduino_send_serial_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input1' */
  MW_pinModeAnalogInput(testArduino_send_serial_P.AnalogInput1_p1);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input2' */
  MW_pinModeAnalogInput(testArduino_send_serial_P.AnalogInput2_p1);
}

/* Model terminate function */
void testArduino_send_serial_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
