//#include <Wire.h>
unsigned long int previousMillis = 0;
/* PWM vals vs output
 *  0 = 25
 *  1 = 43
 *  2 = 71
 *  3 = 99
 *  4 = 130
 *  5 = 162
 *  6 = 192
 */
const byte pwmMeterVals[] = { 0,   1,   2,   3,   4,   5,   6}; //array with all meter vals
const byte pwmVals[]      = {25,  43,  71,  99, 130, 162, 192}; //array with corresponding pwm values
const byte pwmLen = 7; //make sure BOTH arrays are same length!

/* ADC vals vs humidity:
 *  (0 - ) 300 = dry      = 0
 *         400 = damp     = 2
 *         568 = medium   = 4
 *         780 = flooded  = 6
 */
const unsigned int adcVals[]      = {300, 400, 568, 780}; //array with ADC values
const byte         adcMeterVals[] = {  0,   2,   4,   6}; //array with Corresponding meter values
const byte adcLen = 4; //make sure BOTH arrays are same length!
//                0   10  20  30  40  50  60  70  80  90   100

/*byte pwmvals[] = {25, 26, 32, 39, 47, 57, 67, 80, 95, 115, 155};
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int adc, adc_max,adc_min,adc_number;
unsigned long adc_total;
const int MIC = 0; //the microphone amplifier output is connected to pin A0
bool sval=false;

unsigned long previousMillis = 0;        //last time of stop
int fadeValue = 5;*/

const long interval = 400;           // refresh rate
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Plantmeter by TM van den Berg");
  //setup timer2
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20); //non-inverting phase correct 8bit pwm, enable a/b
  TCCR2B = _BV(CS20); //no prescaler (30khz)*/
  OCR2A = 0; //pin 15 D11
  pinMode(11, OUTPUT); //OC2A output is D11
}

void loop() {
 unsigned long int currentMillis = millis();
 if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    unsigned int adcDiff, pwmDiff, meterDiff, pwmOutput, i; //values we use for calculation
    float meterOutput,delta; //to store the meter output value (possibly could have sticked with integers here by multiplying meterVals with 10...)
    unsigned int adc = analogRead(A1); //read A1 for moisture reading
    Serial.print("Analog input: ");
    Serial.println(adc);

    /* Below we will determine the PWM value to write based on the ADC input and our "calibration values". 
     *  It is rather cumbersome, and could possibly be simpler since our current calibration vals are mostly linear,
     *  but this will work also with more non-linear sensors (in which case you should use much smaller spaced calibration values)
     *  I have even generated this in excel, but I since then got lazy and let the arduino do the hard work.
     */

    //Find and linear interpolate output value for this input
    for (i = 0; i < adcLen; i++) {
      if (adcVals[i] > adc) {// we reached our limit or end.
        break;
      }
    }
    if (i == 0) { //smalles value, use output zero
      meterOutput = adcMeterVals[0];;
    }
    else if (i == (sizeof adcVals -1)) { // biggest value, use max output
      meterOutput = adcMeterVals[i];
    }
    else {
      //bottom value, e.g. 400 for 425
      //top value, e.g. 568 for 428
      adcDiff = adcVals[i] - adcVals[i-1]; //difference, e.g. 568 - 400 = 168 for 425;
      meterDiff = adcMeterVals[i] - adcMeterVals[i-1]; //difference in meter output val, e.g. 2 for 426
      delta = (float)meterDiff/adcDiff;
      meterOutput = adcMeterVals[i-1] + delta*(adc - adcVals[i-1]); //2 + (2/168)*(425-400) = 2 + 0.011 * 25 = 2 + 0.297 + 2.297
    }
    Serial.print("Meter output: ");
    Serial.println(meterOutput);

    //Find and linear interpolate PWM value for this output
    for (i = 0; i < pwmLen; i++) {
      Serial.print(i);
      Serial.print(";");
      if (pwmMeterVals[i] > meterOutput) {// we reached our limit or end. 
        Serial.println("hold");
        break;
      }
    }
    if (i == 0) { //smalles value, use output zero
      pwmOutput = pwmVals[0];
    }
    else {
      //bottom value, e.g. 25 for 0.5
      //top value, e.g. 43 for 0.5
      pwmDiff = pwmVals[i] - pwmVals[i-1]; //difference in pwm output, e.g. 8 for 0.5;
      meterDiff = pwmMeterVals[i] - pwmMeterVals[i-1]; //difference in meter output, 1 for 0.5;
      delta = (float)pwmDiff/meterDiff;
      pwmOutput = pwmVals[i-1] + delta*(meterOutput - pwmMeterVals[i-1]); //25 + (the difference in meter value (1) / pwm difference (8) = ) 0.125 * (meter value - bottom meter value = ) 0.5 = 
    }
    Serial.print("PWM output: " );
    Serial.println(pwmOutput);   
    OCR2A = pwmOutput;
 }


}
