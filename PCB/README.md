# PCB Design of the 3D scanner

This repository contains the design and implementation of a 3D scanner using an ATmega328P microcontroller, NEMA 17 stepper motors, and stepper drivers. The project aims to capture a point cloud of a 3D object and transmit the data to a computer as serial data for mapping those points using software.

### Components

- **Microcontroller:** ATmega328P (SMD)
- **USB to Serial Chip:** CH340C
- **Stepper Motors:** NEMA 17
- **Stepper Drivers:** (Specify model, e.g., A4988 or DRV8825)
- **Distance Sensor:** ToF sensor (using SCL and SDA pins)
- **Mechanical Design:** Smooth and screw shafts for precision movement
- **PCB Layout:** Designed using SMD components
  
### Bill of Materials

| Comment       | Description                                                                 | Designator | Footprint                      | LibRef                       | Quantity |
|---------------|-----------------------------------------------------------------------------|------------|--------------------------------|------------------------------|----------|
| 0.1uF         | Multilayer Ceramic Capacitor 0.1uF 10V 10% SMD 0805 T/R                     | C1         | FP-0805-L_2_0_0_1-W_1_25-IPC_C | CMP-14477-004636-2          | 1        |
| 10uF          | Cap Ceramic 10uF 25V X7S 10% Pad SMD 0805 +125°C Automotive T/R             | C2, C3     | FP-CGA4J-IPC_C                | CMP-08246-001526-1          | 2        |
| 100nF         | Chip Capacitor, 100nF, +/-10%, 16V, -55 to 125 degC, 0402 (1005 Metric)     | C4, C11-C13| CAPC1050X55X23ML05T13         | CMP-2000-05439-1            | 4        |
| 10uF (Electrolytic)| Aluminum Electrolytic Capacitor, 10uF, +/-20%, 50V, -40 to 85 degC   | C7, C8     | CAPPR55-200-1100X500X1200     | CMP-001-00025-7             | 2        |
| Green LED     | Chip LED, Green, 2.2V, -40 to 85 degC, 2-Pin SMD, Pb-Free, Tape and Reel    | DS1, DS2   | AVAG-HSMX-C170_V              | CMP-2000-05062-1            | 2        |
| ATmega328P    | 8-bit AVR Microcontroller, 32KB Flash, 1KB EEPROM, 2KB SRAM, 32-pin TQFP    | IC1        | 32A_M                         | CMP-0095-00269-2            | 1        |
| Header 4-Pin  | Header, 4-Pin                                                               | J1, J2     | HDR1X4                        | Header 4                     | 2        |
| Header 6-Pin  | Header, 6-Pin                                                               | J3, J4     | HDR1X6                        | Header 6                     | 2        |
| Terminal Block| PC Terminal Block, Pitch 6.35 mm, 1 x 2 Position, Height 21.5 mm            | J5         | PHOE-1714955_V                | CMP-2000-05797-1            | 1        |
| USB Connector | USB 2.0 Interface, Type A                                                   | J6         | SAMTEC_USB-A-S-X-X-TH         | USB-A-S-X-X-TH               | 1        |
| 10k Resistor  | Chip Resistor, 10k Ohm, +/-1%, 125 mW, -55 to 155 degC, 0805 (2012 Metric)  | R1         | RESC2013X60X40LL15T20         | CMP-2001-04472-1            | 1        |
| 1k Resistor   | Chip Resistor, 1k Ohm, +/-1%, 125 mW, -55 to 155 degC, 0805 (2012 Metric)   | R2, R3, R4, R5 | RESC2013X60X35ML10T20     | CMP-2100-03671-1            | 4        |
| Switch        | Push Button Switch                                                         | SW1        | WS-TASV_L6W6H2.5_4304x30258x6 | CMP-1455-00007-2            | 1        |
| 5V Regulator  | Positive Voltage Regulator, 5V, 1A, 0 to 125 degC, 3-Pin TO-220, RoHS, Tube | T1         | FAIR-TO-220-3                 | CMP-2000-04937-1            | 1        |
| USB to Serial | USB to Serial Chip                                                          | U2         | SOIC127P600X180-16N           | CH340C                       | 1        |
| Crystal       | Quartz Crystal                                                             | Y1         | WE-XTAL_CFPX-180              | CMP-03913-116876469-1       | 1        |

### Block Diagrams and Schematics

![Functional Block Diagram](https://github.com/RPX2001/3D-Scanner/blob/main/PCB/blockdiagram.png)

### Microcontroller Unit

![microcontroller unit](https://github.com/RPX2001/3D-Scanner/blob/main/PCB/mcu.png)

### USB Connection

![USB](https://github.com/RPX2001/3D-Scanner/blob/main/PCB/usb.png)

### Power Regulation

![Power](https://github.com/RPX2001/3D-Scanner/blob/main/PCB/regulator.png)

## PCB Layout

![PCB Layout](https://github.com/RPX2001/3D-Scanner/blob/main/PCB/pcblayout.png)

## 3D Design

![3D design](https://github.com/RPX2001/3D-Scanner/blob/main/PCB/3D%20view.png)


## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

