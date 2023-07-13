/*******************************************
Author : Bayu PRIAMBODO
Date   : July 2023
Desc   : Library to handle nutrimeter module
********************************************/

#include "nutrimeter.h"

NutriMeter::NutriMeter() 
{
  
}

void NutriMeter::init(Stream *softSerial)
{
  buffStream = softSerial;
  buffStream->write('!');
}

int NutriMeter::string2Hex(String dataIn, int iStart, int iEnd)
{
  char xx [iEnd - iStart + 1];
  dataIn.substring(iStart, iEnd).toCharArray(xx, iEnd - iStart + 1);
 
  return strtol(xx, NULL, 16);
}

float NutriMeter::getPH()
{
  if(flagDecode)
  {
    calc = string2Hex(buff, 2, 4) * 1.00;
    return string2Hex(buff, 4, 8) / calc;
  }

  return 0;
}

float NutriMeter::getTemp()
{
  if(flagDecode)
  {
    calc = string2Hex(buff, 8, 10) * 1.00;
    return string2Hex(buff, 10, 14) / calc;
  }

  return 0;
}

float NutriMeter::getTDS()
{
  if(flagDecode)
  {
    calc = string2Hex(buff, 14, 16) * 1.00;
    return string2Hex(buff, 16, 20) / calc;
  }

  return 0;
}

char* NutriMeter::getStatus()
{
  if(flagDecode)
  {
    if( buff.substring(20, 24).equals("000A") )
    {
      return "ON";
    }
    else if ( buff.substring(20, 24).equals("000B") )
    {
      return "OFF";
    }
    else
    {
      return "Error Status";
    }
  }

  return "ERR";
}

int NutriMeter::setON()
{
  buffStream->print("$$96!");
  if(buff.equals("OK"))
  {
    return 1;
  }
  return 0;
}
 
int NutriMeter::setON200()
{
  buffStream->print("$$96!");
  if(buff.equals("OK"))
  {
    return 1;
  }
  return 0;
}
 
int NutriMeter::setON300()
{
  buffStream->print("$$97!");
  if(buff.equals("OK"))
  {
    return 1;
  }
  return 0;
}
 
int NutriMeter::setON400()
{
  buffStream->print("$$98!");
  if(buff.equals("OK"))
  {
    return 1;
  }
  return 0;
}

int NutriMeter::reset()
{
  buffStream->write('!');
  if(buff.equals("RESET"))
  {
    return 1;
  }
  return 0;
}

char* NutriMeter::getStatusOnly()
{
  buffStream->print("$$22!");
  buff = buffStream->readString();
  if( buff.substring(0, 4).equals("000A") )
  {
    return "ON";
  }
  else if ( buff.substring(0, 4).equals("000B") )
  {
    return "OFF";
  }
  else
  {
    return "Error Status";
  }
  
  return "ERR";
}

char* NutriMeter::getVersion()
{
  buffStream->print("$$44!");
  return buffStream->readString();
}

void NutriMeter::decode(String inData)
{
  buffStream->print(inData);
}

int NutriMeter::available(bool printMode)
{
  buff = buffStream->readString();

  if(printMode)
  {
    Serial.println(buff);
  }

  if( (buff.length()) && (buff.substring(0,2).equals("12")) ) //check magic number
  {
    flagDecode = true;
    return 1;
  }

  return 0;
}

int NutriMeter::available()
{
  return available(false);
}
