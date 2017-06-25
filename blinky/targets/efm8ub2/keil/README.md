blinky/efm8ub2/keil
==============

Blinks an LED at a 1 second interval.

Adjust the include path to the system location for the stdint.h
header file that comes with the Keil uVision 5 C51 package.

Standard
-----------

Open the standard blinky.uvopt project file in uVision and build.  
Flash using JLink adapter through JLinkExe or Simplicity Studio.

Bootload
-----------

Open the bootload blinky.uvopt project file in uVision and build.
Bootload using gflash.

Convert the hex file to binary and remove the first 0x0400 bytes
in the resulting binary image.

`srec_cat -Disable_Sequence_Warnings Objects/blinky.hex -Intel -offset -0x0400 -Output Objects/blinky.bin -Binary`

`gflash_cli Objects/blinky.bin`

`gflash_cli b`