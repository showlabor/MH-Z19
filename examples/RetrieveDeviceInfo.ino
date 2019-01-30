#include "MHZ19.h"                                                                                                 
#include <Arduino.h>
#include <SoftwareSerial.h>                                // Remove if using HardwareSerial

#define RX_PIN 10                                          // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 11                                          // Tx pin which the MHZ19 Rx pin is attached to
#define BAUDRATE 9600                                      // Native to the sensor (do not change)

MHZ19 myMHZ19;                                             // Constructor for MH-Z19 class
SoftwareSerial mySerial(RX_PIN, TX_PIN);                   // Constructor for Stream class *change for HardwareSerial, i.e. ESP32 ***

//HardwareSerial mySerial(1);                              // ESP32 Example 

void setup()
{
  Serial.begin(9600);

  mySerial.begin(BAUDRATE);                               // Begin Stream with MHZ19 baudrate

  //mySerial.begin(BAUDRATE, SERIAL_8N1, RX_PIN, TX_PIN); // ESP32 Example 

  myMHZ19.begin(mySerial);                                // *Imporant, Pass your Stream reference here

  /*
    getVersion(char array[]) returns version number to the argument. The first 2 char are the major 
    version, and second 2 bytes the minor version. e.g 02.11
  */

  char myVersion[4];          
  myMHZ19.getVersion(myVersion);

  Serial.print("\nFirmware Version: ");
  for(byte i = 0; i < 4; i++)
  {
    Serial.print(myVersion[i]);
    if(i == 1)
      Serial.print(".");    
  }
   Serial.println("");

   Serial.print("Range: ");
   Serial.println(myMHZ19.getRange());   
   Serial.print("Background CO2: ");
   Serial.println(myMHZ19.getBackgroundCO2());
   Serial.print("Temperature Cal: ");
   Serial.println(myMHZ19.getTempAdjustment());
}

void loop()
{
while(1==1);
}