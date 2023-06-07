# FEROBIT NUTRIMETER

Enables Bluetooth® Low Energy connectivity on the ESP8266 & ESP32 to YINMIK BLE-9901 / YINMIK BLE-9909 via FEROBIT NUTRIMETER module.

This library supports decoding YINMIK BLE-9901 data via FEROBIT NUTRIMETER and BLE.

For the ESP8266 and ESP32.

## Usage

Import library
```arduino
#include <nutrimeter.h>

// uncomment the following if you are using software serial
// #define _SOFTWARESERIAL_

#ifndef _SOFTWARESERIAL_
  HardwareSerial NMserial(2); //UART2 (ESP32 GPIO16 || GPIO17)
#else
  #include <SoftwareSerial.h>
  SoftwareSerial NMserial(D1, D2); // RX | TX
#endif


NutriMeter nm;
```

Initiating function
```arduino
NMserial.begin(115200);
nm.init(&NMserial);
```

decoding encrypted data, make sure add '!' mark in the end of data.
```arduino
String encryptedData;
nm.decode(encryptedData + "!");
```
trigger YINMIK BLE-9901 / YINMIK BLE-9909 device
```arduino
nm.setON();
```
trigger with delay 200ms YINMIK BLE-9901 / YINMIK BLE-9909 device
```arduino
nm.setON200();
```
trigger with delay 300ms YINMIK BLE-9901 / YINMIK BLE-9909 device
```arduino
nm.setON300();
```
trigger with delay 400ms YINMIK BLE-9901 / YINMIK BLE-9909 device
```arduino
nm.setON400();
```
In case there is no response of the module. sending reset command to clear the cache.
```arduino
nm.reset();
```
check if any waiting data
```arduino
nm.available();
```
get status of YINMIK BLE-9901 / YINMIK BLE-9909
```arduino
nm.getStatus();
```
get result of pH measurement
```arduino
nm.getPH();
```
get result of temperature measurement
```arduino
nm.getTemp();
```
get result of TDS measurement
```arduino
nm.getTDS();
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[The Unlicense](https://choosealicense.com/licenses/unlicense/#)
