#include <AccelStepper.h>

#define step1 2
#define dir1 3
#define step2 4
#define dir2 5

#define startpin 8
#define reset 9

#define STEPS_PER_REVOLUTION 200
#define ANGLE_INCREMENT 1.8

// Create a stepper object
AccelStepper stepper1(AccelStepper::DRIVER, step1, dir1);  //Z axis
AccelStepper stepper2(AccelStepper::DRIVER,step2, dir2);  //turnable table

void setup() {
  // put your setup code here, to run once:
  stepper1.setMaxSpeed(2000); //SPEED = Steps / second
  stepper1.setAcceleration(1000); //ACCELERATION = Steps /(second)^2
  stepper1.disableOutputs();
  stepper1.setCurrentPosition(0);

  stepper1.setMaxSpeed(2000); //SPEED = Steps / second
  stepper1.setAcceleration(1000); //ACCELERATION = Steps /(second)^2
  stepper1.disableOutputs();
  stepper1.setCurrentPosition(0);

  pinMode(startpin,INPUT);
  pinMode(reset,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper1.enableOutputs();
  stepper1.run();

  stepper2.enableOutputs();
  stepper2.run();
}
