#include <AccelStepper.h>
#include <Wire.h>
//#include <Adafruit_VL53L0X.h>

// Define stepper motor connections
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

//define tof object
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

float measurements[STEPS_PER_REVOLUTION][2];
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
    // initialize tof sensor
    Serial.begin(9600);
    Wire.begin();
    
    lox.setTimeout(500);
    
    if (!lox.init())
    {
        while (1);
    }

    lox.setMeasurementTimingBudget(20000);  // Set measurement time to 20ms
    lox.startContinuous();
}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(startpin) == HIGH){     // when push start button and process
        if(stepper1.currentPosition() == 0 && stepper2.currentPosition() == 0){
            runZmotor();
            runturnabletable();
            float dist = readDistance();
            Serial.println(dist);
        }
        else if(stepper1.currentPosition() != 0){
            Gotozero(0);
        }
        else{
            Gotozero(1);
        }

    }
    else if(digitalRead(reset) == HIGH){
        // when push reset button to set initial positions
        Gotozero(0);
        Gotozero(1);
    }
}

void runZmotor(){
    // check current position of the stepper
    stepper1.enableOutputs();
    stepper1.run();
}

void runturnabletable(){
    stepper2.enableOutputs();
    stepper2.run();

    // stepper2.setMaxSpeed(400); //set speed manually to 400 step/sec = 1 rev/sec.
    // stepper2.moveTo(0); 
    
}

void stopMotors(){
    stepper1.stop(); //stop motor 1
    stepper1.disableOutputs(); //disable power
    stepper2.stop(); //stop motor 2
    stepper2.disableOutputs(); //disable power
}

void Gotozero(int x){
    if(stepper1.currentPosition() != 0 && x == 0){
        stepper1.setMaxSpeed(400);
        stepper1.moveTo(0);
    }

    if(stepper2.currentPosition() != 0 && x == 1){
        stepper2.setMaxSpeed(400);
        stepper2.moveTo(0);
    }
}

float readDistance(){
    uint16_t distance_mm = sensor.readRangeContinuousMillimeters();
  
    if (sensor.timeoutOccurred()) 
    {
        // Serial.println(100);   // if timed out set distance to 10cm
        return 100;
    }
    else 
    {
        // Serial.print(distance_mm);
        return distance_mm;
    }
    
    //delay(100); // delay for 100ms
}

void process(){
    
}
