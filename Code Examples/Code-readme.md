# AVR LED Blinking Example

This repository contains an example AVR code for blinking LEDs in three different colors (red, green, and blue) using the ATmega microcontroller. The code is written in C and utilizes AVR's I/O and delay functions to control the LEDs.

## Purpose

The purpose of this code is to demonstrate the basic usage of AVR microcontrollers for controlling LEDs and creating simple visual effects. By connecting LEDs to different pins on the microcontroller, we can create a visual display that cycles through the three primary colors: red, green, and blue.

## Getting Started

### Prerequisites

- AVR microcontroller (e.g., ATmega328P)
- AVR development environment (e.g., AVR-GCC, AVRDUDE)
- Appropriate hardware setup (LEDs, resistors, etc.)

### Setting Up

1. Clone this repository to your local machine using `git clone https://github.com/your-username/avr-led-blink.git`.
2. Open the project directory in your AVR development environment.

### Running the Code

1. Connect the LEDs to the AVR microcontroller's pins according to the code comments (PB1 for red, PB2 for green, PB3 for blue).
2. Compile the code using your AVR development environment.
3. Flash the compiled code onto your AVR microcontroller.
4. Observe the LEDs cycling through the colors: red, green, and blue.

## Code Explanation

The code initializes the AVR microcontroller's I/O pins for controlling the LEDs. Inside the main loop, it alternates turning on and off each LED in sequence, creating a blinking effect. The `_delay_ms` function is used to control the duration of LED on and off states.


## Example of code: Kick Tisch Snare

This code is a simple program for an AVR microcontroller that controls three LEDs (white, blue, and red) to create a basic drum pattern. The LEDs represent different percussion instruments, and the code cycles through a pattern simulating a drum rhythm.

### Hardware Setup
The code assumes that the LEDs are connected to specific pins on the AVR microcontroller. Here's the setup:

White LED (Hi-hat 1): Connected to pin PB2.
Blue LED (Kick): Connected to pin PB3.
Red LED (Snare): Connected to pin PB1.
Make sure to connect the LEDs to the correct pins on your microcontroller to see the intended drum pattern.

### Drum Pattern
The code follows a drum pattern with a tempo of 128 beats per minute (BPM). Here's a breakdown of the pattern:

Hi-hat 1 (white LED - PB2) blinks before the kick.
Kick (blue LED - PB3) blinks on every first beat.
Hi-hat 2 (white LED - PB2) blinks between the kick and snare.
Snare (red LED - PB1) blinks on every second beat.
Hi-hat 3 (white LED - PB2) blinks after the snare.
The code uses _delay_ms to control the timing of LED blinking to match the 128 BPM tempo.

### How to Use
Ensure your AVR microcontroller is properly connected to the LEDs as described above.
Compile and flash this code onto your microcontroller.
The LEDs will light up and follow the described drum pattern, creating a basic drum rhythm.
Feel free to modify the code, adjust the timing, or add more LEDs to create your own unique drum patterns using this as a starting point.


## Contributing

Contributions to enhance or extend the functionality of this code are welcome. Feel free to submit a pull request with your improvements.

## License

This project is licensed under the [MIT License](LICENSE).
