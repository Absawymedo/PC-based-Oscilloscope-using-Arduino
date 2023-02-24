# PC-based-Oscilloscope-using-Arduino

Discription

 This code is for an Arduino-based project called "EFY PC OsciloScope". The goal of the project is to read analog voltages from pin A0 and send them to the computer via serial communication, as fast as possible. The project is intended to function as a simple oscilloscope that can be used for basic electronics experimentation.

The setup function initializes the serial communication at a baud rate of 115200 bits per second, sets the pinMode of pin 13 to OUTPUT, and configures the ADC (analog-to-digital converter) for reading voltages from pin A0. The ADC is configured to use a 16x prescaler for a sampling rate of approximately 76.9 kHz, which is faster than the Arduino's default ADC configuration.

The loop function continuously reads the voltage from A0 using the ADC, and writes the 8-bit value to the serial port using the Serial.write() function. Additionally, the code includes a block of code to generate a 50 Hz reference signal at pin 13, which can be observed with an oscilloscope.

Overall, this project demonstrates how to use the ADC on an Arduino to read analog voltages and send them to a computer via serial communication. It is a useful starting point for anyone interested in building their own simple oscilloscope or experimenting with analog electronics.
