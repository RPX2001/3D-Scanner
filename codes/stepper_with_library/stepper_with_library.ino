#include <AccelStepper.h>

// Define stepper motor connections:
#define dirPin1 2
#define stepPin1 3
#define enapin1 6

// #define dirpin2 4
// #define steppin2 5
// #define enapin2 7

// Create a new instance of the AccelStepper class:
AccelStepper stepper1(AccelStepper::DRIVER, stepPin1, dirPin1);

void setup() {
  // Set the maximum speed and acceleration:
  stepper1.setMaxSpeed(2000); //SPEED = Steps / second
  stepper1.setAcceleration(1000); //ACCELERATION = Steps /(second)^2

  stepper1.disableOutputs();
  stepper1.setCurrentPosition(0);
  //stepper1.setSpeed(200);
}

void loop() {
  // Run the stepper motor continuously:
  stepper1.enableOutputs();
  stepper1.run();
}
