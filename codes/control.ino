#include <Adafruit_VL53L0X.h>

//#include <vl53l0x_api.h>
// #include <vl53l0x_api_calibration.h>
// #include <vl53l0x_api_core.h>
// #include <vl53l0x_api_ranging.h>
// #include <vl53l0x_api_strings.h>
// #include <vl53l0x_def.h>
// #include <vl53l0x_device.h>
// #include <vl53l0x_i2c_platform.h>
// //#include <vl53l0x_interrupt_threshold_settings.h>
// #include <vl53l0x_platform.h>
// #include <vl53l0x_platform_log.h>
// //#include <vl53l0x_tuning.h>
// #include <vl53l0x_types.h>

int tenable = 6;
int tpulse = 3;
int tdir = 2;

int zenable = 7;
int zpulse = 5;
int zdir = 4;

#define pb_start 8


Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  // put your setup code here, to run once:
  pinMode(tenable,OUTPUT);
  pinMode(tpulse,OUTPUT);
  pinMode(tdir,OUTPUT);

  pinMode(zenable,OUTPUT);
  pinMode(zpulse,OUTPUT);
  pinMode(zdir,OUTPUT);

  pinMode(pb_start,INPUT);

  Serial.begin(9600);

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }

  digitalWrite(tenable,LOW);
  digitalWrite(zenable,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  int vertDistance=10; //Total desired z-axis travel
  int noZSteps=200; //No of z-steps per rotation.  Distance = noSteps*0.05mm/step  20 default
  int zCounts=(200/1*vertDistance)/noZSteps; //Total number of zCounts until z-axis returns home
  //int thetaCounts=400;
  int thetaCounts=200;

  // Scan object
  digitalWrite(zdir,LOW); 
  for (int j=0; j<zCounts; j++) //Rotate z axis loop
  {
    for (int i=0; i<thetaCounts; i++)   //Rotate theta motor for one revolution, read sensor and store
    {
      rotateMotor(tpulse, 1); //Rotate theta motor one step
      //delay(200);
      double senseDistance=0; //Reset senseDistanceVariable;
      senseDistance=readingDistance(); //Read IR sensor, calculate distance
      // writeToSD(senseDistance); //Write distance to SD
      Serial.println(senseDistance);
    }
  
    rotateMotor(zpulse, noZSteps); //Move z carriage up one step
    delay(1000);
    Serial.println(9999); //Write dummy value to SD for later parsing
  }

  // Scan complete.  Rotate z-axis back to home and pause.
  digitalWrite(zdir,HIGH);
  delay(10);  
  for (int j=0; j<zCounts; j++)
  {
    rotateMotor(zpulse, noZSteps);
    delay(10);
  }

  for (int k=0; k<3600; k++) //Pause for one hour (3600 seconds), i.e. freeze until power off because scan is complete.
  {
    delay(100); 
  }


}


// get readings from ToF

double readingDistance(){
  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    // Serial.print(F("Distance (mm): "));
    double x =(measure.RangeMilliMeter);
    return x;
  } 
  else {
    return 28;
  }

  //delay(100);
}

void rotateMotor(int pinNo, int steps)
{
  
  for (int i=0; i<steps; i++)
  {
    digitalWrite(pinNo, LOW); //LOW to HIGH changes creates the
    delayMicroseconds(1000);
    digitalWrite(pinNo, HIGH); //"Rising Edge" so that the EasyDriver knows when to step.
    delayMicroseconds(1000);
    //delayMicroseconds(500); // Delay so that motor has time to move
    //delay(100); // Delay so that motor has time to move
  }
}