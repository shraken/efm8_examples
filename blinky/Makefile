main: directories init.rel gpio.rel
	sdcc -Iinc --model-large src\main.c build\init.rel build\gpio.rel -o build/

directories: 
	mkdir build

gpio.rel: src\gpio.c inc\gpio.h
	sdcc -Iinc --model-large -c src\gpio.c -o build/

init.rel: src\init.c inc\init.h
	sdcc -Iinc --model-large -c src\init.c -o build/

.PHONY: clean

clean:
	rm -rf flash.jlink
	rm -rf build
	
JLINK_OPTS = -device EFM8UB20F64G -if c2 -speed 4000
# flashing windows vs. posix
ifeq ($(OS),Windows_NT)
JLINK = JLink $(JLINK_OPTS)
else
JLINK = JLinkExe $(JLINK_OPTS)
endif # flashing windows vs. posix

flash: flash.jlink
	packihx build\main.ihx > build\main.hex
	$(JLINK) flash.jlink

flash.jlink:
	printf "erase\nloadbin build\main.hex,0\nexit\n" > flash.jlink