/*******************************************
Author : Bayu PRIAMBODO
Date   : April 2023
Desc   : Library to handle nutrimeter module
********************************************/

#ifndef nutrimeter_h
#define nutrimeter_h

#include <Arduino.h>
#include <Stream.h>

class NutriMeter
{
  public:
    NutriMeter();       // Constructor
    float getPH();      // Method
    float getTemp();    // Method
    float getTDS();     // Method
    char* getStatus();  // Method
    int setON();        // Method
    int setOFF();       // Method
    int reset();        // Method
    int available();    // Method
    int available(bool printMode);    // Method
    void decode(String inData);      // Method
    void init(Stream *softSerial);      // Method
  private:
    int string2Hex(String dataIn, int iStart, int iEnd);

    float calc = 0;

    String buff = "";
    bool flagDecode = false;

    Stream* buffStream;
};

#endif