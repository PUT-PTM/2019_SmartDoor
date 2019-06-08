# 2019_SmartDoor

## Overview
The goal of the project was to create a smart door that warns of unauthorized passage by persons/ entering the room.

## Description

After switching on, the system is activated in neutral mode - the LED strip performs animations, but the operation of the motion sensor is deactivated. In order to activate the system, enter the correct code on the keyboard connected to the microcontroller.
In the case of motion detection by a motion sensor, the system signals using a sound and visual effect using a LED strip.
In order to turn off the alarm and restore the strip to the neutral state, you must enter the correct code again.

The display shows the current system enable status: ON / OFF and the display shows the entered numbers when entering the code.

The LEDs having the WS2811 controller were programmed using PWM (Pulse Width Modulation) with a suitably configured timer (**Period:** 209, **Prescaler:** 0).

The physical elements that have been used:

 - A motion sensor (**PIR HC-SR501**) was used to detect motion.
 - Led Strip (**WS2811**)
 - Module with loudspeaker for A/C and C/A converter (**WSR-04489**)
 - Keyboard - 2x4 tact switch matrix (**WSR-04499**)
 - 4 x 8-segment display (**MOD-02896**)
 - Power supply for LED strip (**AC/DC 12V 5A**)


## Tools

### Software:

 - STM32CubeMX v5.2.0
 - System Workbench for STM32 (Neon.3 Release v4.6.3)
 - STMStudio v3.6.0 (for debugging)
 - HxD Hex Editor v2.2.1.0 (for .wav to .c convert)

## How to run

After connecting all the components in a physical way, run the CubeMX file and then generate the code. Then the generated code should be transfered to the microcontroller using System Workbench for STM32.

### Connection between the controller and components:

 - Motion sensor

Motion sensor PIN|STM32 PIN  |
|--|--|
| VCC | 5V |
| GND | GND |
| OUT | PB4 (GPIO_Input) |

 - LED Strip
 
|LED Strip| STM32 PIN |
|--|--|
|White wire  | GND |
|Green wire  | PB6 (TIM4_CH1)  |

- Module with loudspeaker for A/C and C/A converter

| Module with loudspeaker PIN | STM32 PIN |
|--|--|
| VCC | 3V |
| +5V | 5V |
| GND | GND |
| ADC1 | PA1 (ADC1_IN1) |
| AIN | PA4 (DAC_OUT1) |

- Module with loudspeaker for A/C and C/A converter

|Keyboard PIN| STM32 PIN |
|--|--|
| G |3V  |
| K0 |PE7 (GPIO_Input)  |
| K1 |PE8 (GPIO_Input)  |
| K2 |PE9 (GPIO_Input)  |
| K3 |PE10 (GPIO_Input)  |
| K4 |PE11 (GPIO_Input)  |
| K5 |PE12 (GPIO_Input)  |
| K6 |PE13 (GPIO_Input)  |
| K7 |PE14 (GPIO_Input)  |

- 4 x 8-segment display

|Display PIN|  STM32 PIN|
|--|--|
| VCC | 3V |
| a | PD0 (GPIO_Output) |
| b | PD1 (GPIO_Output) |
| c | PD2 (GPIO_Output) |
| d | PD3 (GPIO_Output) |
| e | PD4 (GPIO_Output) |
| f | PD5 (GPIO_Output) |
| g | PD6 (GPIO_Output) |
| h | PD7 (GPIO_Output) |
| 1 | PB12 (GPIO_Output) |
| 2 | PB13 (GPIO_Output) |
| 3 | PB14 (GPIO_Output) |
| 4 | PB15 (GPIO_Output) |

## How to compile

No additional steps are required to compile the project.

## Future improvements

In further development of the project brightness of the led strip LEDs can be improve also the way of entering the code on the keyboard could have additional options (eg removing the wrong digit).

The LED strip's signal cable is very susceptible to interference, which should be "separated" from other wires.

## Export a file

You can export the current file by clicking **Export to disk** in the menu. You can choose to export the file as plain Markdown, as HTML using a Handlebars template or as a PDF.


## Attributions

Audio sound used from: youtube.com/watch?v=IpyingiCwV8

## License

**MIT**

## Credits

Created by:
 - Konrad Tarnacki
 - Mateusz Galan
 - Kacper Wleklak
---
The project was conducted during the Microprocessor Lab course held by the
Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Adam Bondyra
