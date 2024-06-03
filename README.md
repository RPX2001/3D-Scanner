# 3D Scanner Project

This repository contains the design and implementation of a 3D scanner using an ATmega328P microcontroller, NEMA 17 stepper motors, and stepper drivers. The goal of this project is to capture a point cloud of a 3D object, transmit the data to a computer as serial data, and map those points using software.

## Project Overview

### Components

- **Microcontroller:** ATmega328P
- **Stepper Motors:** NEMA 17
- **Stepper Drivers:** A4988 or similar
- **Distance Sensor:** (Specify the sensor if used, e.g., Ultrasonic sensor or LIDAR)
- **Mechanical Design:** Smooth and screw shafts for precision movement
- **PCB Layout:** Designed using SMD components
- **Turntable:** For rotating the object being scanned

### Functionality

1. **Object Placement:** The object to be scanned is placed on a turntable.
2. **Rotation and Scanning:** The turntable rotates the object while the distance sensor captures measurements along the Z-axis.
3. **Data Transmission:** The ATmega328P microcontroller collects the distance measurements and transmits the data to a computer via serial communication.
4. **Point Cloud Mapping:** Software on the computer receives the serial data and maps the points to create a 3D representation of the object.

### Mechanical Design

The mechanical design of the 3D scanner includes:
- **Smooth Shafts:** Used for linear motion to ensure precision.
- **Screw Shafts:** Used for controlled rotation and vertical movement.

### PCB Layout

The PCB layout is designed using SMD components for compactness and reliability. The layout includes:
- **Microcontroller Circuit:** Based on ATmega328P for controlling the stepper motors and handling data transmission.
- **Motor Drivers:** For driving the NEMA 17 stepper motors.
- **Power Supply Circuit:** To provide necessary power to the components.

## Getting Started

### Prerequisites

- **Hardware:**
  - ATmega328P microcontroller
  - NEMA 17 stepper motors
  - Stepper drivers (e.g., A4988)
  - Distance sensor (specify type)
  - Mechanical components (smooth and screw shafts, turntable)
  - Custom PCB

- **Software:**
  - Arduino IDE for programming the ATmega328P
  - Serial communication software (e.g., PuTTY, Arduino Serial Monitor)
  - 3D mapping software (e.g., PCL, Meshlab)

### Steps

1. **Assemble the Hardware:**
   - Connect the stepper motors to the stepper drivers.
   - Connect the stepper drivers to the ATmega328P microcontroller.
   - Set up the distance sensor and connect it to the microcontroller.
   - Assemble the mechanical parts, including the turntable, smooth shafts, and screw shafts.
   - Ensure the PCB is correctly assembled and connected.

2. **Upload the Code:**
   - Write the firmware for the ATmega328P to control the stepper motors and read data from the distance sensor.
   - Upload the code to the ATmega328P using the Arduino IDE.

3. **Calibrate the System:**
   - Ensure the stepper motors are correctly calibrated for precise movement.
   - Calibrate the distance sensor for accurate measurements.

4. **Run the Scanner:**
   - Place the object on the turntable.
   - Start the scanning process and collect the point cloud data via serial communication.

5. **Map the Point Cloud:**
   - Use 3D mapping software to visualize the point cloud data and create a 3D model of the object.


## Contributors

- [Samudra Uduwaka](https://github.com/samudra-uduwaka)

## License

This project is licensed under the [MIT License](LICENSE).

