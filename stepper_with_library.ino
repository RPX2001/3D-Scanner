#include <AccelStepper.h>

// Define stepper motor connections:
#define dirPin 2
#define stepPin 3

// Create a new instance of the AccelStepper class:
AccelStepper stepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(1000);     // Adjust the speed as needed
  stepper.setAcceleration(500);  // Adjust the acceleration as needed

  // Set the spinning direction CW/CCW:
  stepper.setDirection(HIGH);

  // Set initial speed and position:
  stepper.setSpeed(500);  // Adjust the speed as needed
  stepper.setCurrentPosition(0);
}

void loop() {
  // Run the stepper motor continuously:
  stepper.runSpeed();
}
