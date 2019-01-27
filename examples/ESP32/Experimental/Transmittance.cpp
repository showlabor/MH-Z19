/*
    *****Testing Function****

    Transmittance: 
    As Raw CO2 decreases with increasing CO2, a function has been created 
    named "transmittance". This uses a backwards projection to the zero 
    crossing of x to produce a 7-decimal place % value. (i.e. what % of 
    IR radiation was received of the amount sent).

    Below demonstrates transmittance, and the exponential equation from my 
    sensor under such conditions.
 */

#include <Arduino.h>
#include "MHZ19.h"

#define RX_PIN 16
#define TX_PIN 17

#define SERIAL_NUMBER 1

MHZ19 myMHZ19(RX_PIN, TX_PIN, SERIAL_NUMBER);

unsigned long getDataTimer = 0;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if (millis() - getDataTimer > 2000)
    {
        Serial.println("------------------------------");
        Serial.print("Transmittance: ");
        Serial.print(myMHZ19.getTransmittance(), 7);           // 7 decimals for float resolution
        Serial.println(" %");
        getDataTimer = millis();
    }
}