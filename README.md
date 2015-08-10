# FatFs implementation on PIC18 / PIC24

**Compilers Used:** XC8 v1.35 and XC16 v1.24 (free mode) + MPLAB Code Configurator (MCC) plugin. For previous compiler versions check the project tags

**PICs Tested:** PIC18F25K20, PIC18F46K22, PIC18F87K90, PIC24FJ64GA002

**PIC Requirements:**
* SPI (MSSP)
* 1K RAM or greater
* 32K ROM or greater

**FatFs Version:** R0.11 with patch 1

**How To Build:** [*(View YouTube video)*](https://www.youtube.com/watch?v=4b3vXYBXhSQ)
* Create a standalone PIC18 / PIC24 project on MPLABX using the XC8 / XC16 compiler
* Open the MCC following the menu route Tools -> Embedded -> MPLAB Code Configurator
* On Project Resources click on System, configure the system clock and the device's configuration bits
* In the Device Resources, choose MSSP and pick the SPI port that will be used, double-click on SPI Master
* On Project Resources click on the MSSP SPI that was just added, change the SPI mode to 0 and choose a clock source that provides a SPI clock between 100-400KHz
* Click on the + sign right next to the *Initialize* combo box, another function named *InitializeNew* will be added, change that name to *Open* and change the SPI mode to 0
* In the Device Resources, choose GPIO and double click on GPIO::GPIO
* On Project Resources click on the GPIO that was just added, right-click on the pin that will be used as the SD chip select and click on the popup menu option.
* Set the pin to output, select it as Start High and change the custom name to `SD_CS`
* Click on the Generate Code button, when asked to create a main.c file choose No
* Copy the repo's files to the project's folder
* Select the Projects tab, right-click on Header Files, choose Add Existing Item, select all .h files and click on the Select button
* Right-click on Source Files, choose Add Existing Item, select all .c files and click on the Select button
* Open the mcc.c file on the MCC Generated Files and remove the SPI Initialize call from the SYSTEM_Initialize function
* Edit the configuration files according to your needs and build. For PIC24 remember to change the `main` function type from `void` to `int` and add a `return -1;` to the end of the function. Also on ffconf.h define `WORD_ACCESS` as 0 (byte-by-byte address)

**Configuration Files:**
* ffconf.h: FatFs configuration options
* diskio.c: SPI port configuration. If your device only has one master synchronous serial port (MSSP) module, set the `_SD_SPI` definition to `0`, else set it to `1` or `2` according to the SPI port you are using

**FatFs Homepage:** [http://elm-chan.org/fsw/ff/00index_e.html](http://elm-chan.org/fsw/ff/00index_e.html)

All credits to ChaN for this amazing library. If for some reason you need to contact me send me an e-mail to [mondul@huyzona.com](mailto:mondul@huyzona.com)
