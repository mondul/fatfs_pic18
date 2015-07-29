# FatFs implementation on PIC18

**Compiler Used:** XC8 v1.34 (free mode)

**PIC Used:** PIC18F25K20

**PIC Requirements:**
* SPI (MSSP)
* 1K RAM or greater
* 32K ROM or greater

**FatFs Version:** R0.11 with patch 1

**How To Build:** Create a standalone PIC18 project on MPLABX using the XC8 compiler, copy these files to the project's folder, add the existing files to the project, edit the configuration files according to your needs and build

**Configuration Files:**
* config.h, hardware.c, hardware.h: device specific files
* ffconf.h: FatFs configuration options
* diskio.c: SPI port configuration. If your device only has one master synchronous serial port (MSSP) module, set the `_SD_SPI` definition to `0`, else set it to `1` or `2` according to the SPI port you are using

**FatFs Homepage:** [http://elm-chan.org/fsw/ff/00index_e.html](http://elm-chan.org/fsw/ff/00index_e.html)

All credits to ChaN for this amazing library. If for some reason you need to contact me send me an e-mail to [mondul@huyzona.com](mailto:mondul@huyzona.com)
