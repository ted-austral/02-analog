/*
 *     main.cpp - Project 03-analog
 *      IntroCom - Austral - 2022 - EAM
 *
 *          Shows converted value and voltage of a
 *          potentiometer connected to A/D converter
 *
 *          Output from 0 to 3.3 volt is printed to serial monitor
 */

#include <Arduino.h>

/*
 *     Definitions
 */

/*
 *  Definitions in platformio.ini
 *  ANAIN       Input to A/D converter
 *  DIVISOR     Divisor that depends of the number of bits of converter
 *  SERIAL_BAUD Baud rate of serial monitor
 */

//  Other definitions

const uint32_t loop_delay = 250;
const double pote_voltage = 3.3;

void
setup()
{
    Serial.begin(SERIAL_BAUD);
}

void
loop()
{
    int sensorValue;
    float voltage;

    sensorValue = analogRead(ANAIN);
    voltage = sensorValue * pote_voltage / DIVISOR;
    Serial.println( "Digital value = " +String(sensorValue) + " Voltage = " + String(voltage) );
    delay(loop_delay);
}
