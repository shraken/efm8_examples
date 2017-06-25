blinky/efm8ub2/simplicity
==============

Blinks an LED at a 1 second interval.

Standard
-----------

Import the standard project into Simplicity Studio and build.  
Flash using JLink adapter through JLinkExe or Simplicity Studio.

Bootload
-----------

Import the bootload project into Simplicity Studio and build. 

Convert the hex file to binary and remove the first 0x0400 bytes
in the resulting binary image.

`srec_cat -Disable_Sequence_Warnings Objects/blinky.hex -Intel -offset -0x0400 -Output Objects/blinky.bin -Binary`

`gflash_cli blinky.bin`

`gflash_cli b`