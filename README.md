# 3D Scanner Project

This repository contains the design and implementation of a 3D scanner using an ATmega328P microcontroller, NEMA 17 stepper motors, and stepper drivers. The goal of this project is to capture a point cloud of a 3D object, transmit the data to a computer as serial data, and map those points using software.

## Project Overview
Our 3D scanner project aims to design and build a machine capable of scanning an object and generating a 3D map of it. The scanner primarily comprises two parts: a linear Z-axis motion slider and a turntable. The object to be scanned is placed on the turntable, which rotates during scanning. After each full rotation, the Z-axis slider raises the ToF sensor slightly, and the process repeats. Distance measurements from the ToF sensor are sent to a PC in real-time via serial communication, stored in a .txt file, and used to generate a 3D point cloud map of the scanned object.

## Project Components
- **Microcontroller**: ATmega328P
- **Stepper Motors**: NEMA 17
- **Stepper Motor Drivers**: TB6600
- **ToF Sensor**: VL53L0X
- **Voltage Regulator**: LM7805
- **USB to Serial Converter**: CH340C
- **Turntable and Z-axis Slider**: Custom mechanical parts designed in SolidWorks



## Electronic Design

### Component Selection

- **Microcontroller (ATmega328P)**: Chosen for its reliability, compact size, and capability to handle multiple inputs efficiently. It is programmed via a USB connection using the CH340C IC.
- **Stepper Motors (NEMA 17)**: Selected for their high torque and compatibility with 12V power supply. Specifications include 76 oz*in torque, 1.8° step angle, and 1.68A/phase peak current.
- **Stepper Motor Drivers (TB6600)**: Supports a wide range of power inputs (9-42VDC) and can output 4A peak current. Features include speed and direction control, microstep settings, and high-speed optocoupler isolation.
- **ToF Sensor (VL53L0X)**: Provides accurate distance measurements for scanning.
- **Voltage Regulator (LM7805)**: Converts 12V input to a stable 5V output to power the microcontroller and sensor.

### PCB Design
The PCB design integrates the microcontroller, voltage regulator, stepper motor drivers, and USB to serial converter. SMD components are used to minimize space. The design includes necessary capacitors for the LM7805, signal routing for stepper motor control, and connectors for the ToF sensor and stepper motors.

## Mechanical Design
The mechanical design includes a 14cm diameter turntable and a Z-axis slider mechanism. Components such as smooth shafts, screw shafts, and couplers ensure precise linear motion. The enclosure houses the PCB, stepper drivers, and motors, providing a compact and durable structure.

## Software Implementation
### Arduino Code
The Arduino code controls the stepper motors and reads distance values from the ToF sensor. It uses direct port manipulation and register-level programming for efficient motor control.


### Functionality

1. **Object Placement:** The object to be scanned is placed on a turntable.
2. **Rotation and Scanning:** The turntable rotates the object while the distance sensor captures measurements along the Z-axis.
3. **Data Transmission:** The ATmega328P microcontroller collects the distance measurements and transmits the data to a computer via serial communication.
4. **Point Cloud Mapping:** Software on the computer receives the serial data and maps the points to create a 3D representation of the object.



### PCB 

<img src="https://github.com/RPX2001/3D-Scanner/blob/main/WhatsApp%20Image%202024-06-05%20at%2019.54.27.jpeg" alt="PCB" width="800">


### Enclosure

<img src="https://github.com/RPX2001/3D-Scanner/blob/main/final.jpeg" alt="Enclosure" width="800">




## Contributors

- [Samudra Uduwaka](https://github.com/samudra-uduwaka)

## License

This project is licensed under the [MIT License](LICENSE).

