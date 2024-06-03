#include <AccelStepper.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

// Define stepper motor connections
#define STEP_PIN 2
#define DIR_PIN 3

#define STEPS_PER_REVOLUTION 200
#define ANGLE_INCREMENT 1.8

// Create a stepper object
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

float measurements[STEPS_PER_REVOLUTION][2];

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor

  Set the maximum speed and acceleration
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(50);

  // Set the initial position
  stepper.setCurrentPosition(0);

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  pinMode(13, OUTPUT);  // Set pin 13 as an output

  Serial.println(F("VL53L0X test with Stepper Motor"));
}

void loop() {
  digitalWrite(13, HIGH);
  // Move the motor for one full rotation (200 steps for a 200-step motor)
  stepper.move(200);

  // VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      measurements[0][0] = 0 * ANGLE_INCREMENT;
      measurements[0][1] = measure.RangeMilliMeter;
    } else {
      measurements[0][0] = 0 * ANGLE_INCREMENT;
      measurements[0][1] = 10000;
    }



  // // Run the stepper until it reaches the target position
  while (stepper.run() != 0) {
    // Print the current position modulo 200 (ensuring numbers from 1 to 200)
    int this_step = stepper.currentPosition() % 200;
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      measurements[this_step][0] = this_step * ANGLE_INCREMENT;
      measurements[this_step][1] = measure.RangeMilliMeter;
    } else {
      measurements[this_step][0] = this_step * ANGLE_INCREMENT;
      measurements[this_step][1] = 10000;
    }

    
  // //Serial.println(arrayToString());
  }
  Serial.print("aaa[");
  for (int i = 0; i < STEPS_PER_REVOLUTION; i++) {
    Serial.print("[");
    Serial.print(measurements[i][0]);
    Serial.print(",");
    Serial.print(measurements[i][1]);
    Serial.print("],");
  }
  Serial.println("]");

  digitalWrite(13, LOW);

  // // Add a delay to observe the movement
  delay(5000);
}