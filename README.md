# FEROBIT NUTRIMETER

Enables Bluetooth® Low Energy connectivity on the ESP8266 & ESP32 to YINMIK BLE-9901 via FEROBIT NUTRIMETER module.

This library supports decoding YINMIK BLE-9901 data via FEROBIT NUTRIMETER and BLE.

For the ESP8266 and ESP32.

## Usage

Import library
```arduino
#include <nutrimeter.h>

SoftwareSerial NMserial(D1, D2); // RX | TX
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
turning on YINMIK BLE-9901 device
```arduino
nm.setON();
```
turning off YINMIK BLE-9901 device
```arduino
nm.setOFF();
```
In case there is no response of the module. sending reset command to clear the cache.
```arduino
nm.reset();
```
check if any waiting data
```arduino
nm.available();
```
get status of YINMIK BLE-9901
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