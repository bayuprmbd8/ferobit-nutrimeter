/*******************************************
Author : Bayu PRIAMBODO
Date   : April 2023
Desc   : Library to handle nutrimeter module
********************************************/

#include <nutrimeter.h>
#include <SoftwareSerial.h>

SoftwareSerial NMserial(D1, D2); // RX | TX

NutriMeter nm;

void setup()
{
  NMserial.begin(115200);
  nm.init(&NMserial);

  Serial.begin(115200);
  Serial.println("\n\nInput a number...");
}

int serialState = -1;

void loop()
{
  if (Serial.available()) {
    // Read the User Input Data
    serialState = Serial.parseInt(); //Read the data the user has input
    Serial.println(serialState);

    switch(serialState)
    {
      case 1:
        nm.decode("FFA9FCF7FC7CFFC3FF87FFADFDF7FF7CFAE871FCA656FE55!"); //Correct Encrypted Data
        break;
      case 12:
        nm.decode("00A9FCF7FC7CFFC3FF87FFADFDF7FF7CFAE871FCA656FE55!"); //Wrong Encrypted Data
        break;
      case 13:
        nm.decode("FFEEFCF7FC7CFFC3FF87FFADFDF7FF7CFAE871FCA656FE55!"); //Wrong Encrypred Data
        break;
      case 2:
        nm.decode("$$99!"); //Wrong Command Data
        break;
      case 3:
        nm.setON(); //Correct Command Data
        break;
      case 4:
        nm.setOFF(); //Correct Command Data
        break;
      case 0:
        nm.reset(); //Correct Command Data
        break;
      default:
        Serial.println("Unregister Command");
        break;
    }
    
    serialState = -1; //Clear Buffer

  }

  if(nm.available()) //Checking data on buffer
  {
    Serial.println(nm.getStatus()); //get status of device

    Serial.println(nm.getPH());   //get pH
    Serial.println(nm.getTemp()); //get temperature
    Serial.println(nm.getTDS());  //get TDS
  }
    
  delay(100);
}