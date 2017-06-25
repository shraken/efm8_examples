SRC_PATH=../../../src
INC_PATH=../../../inc
BUILD_DIR = build
BUILD_NORMAL_NAME = blinky
BUILD_BOOTL_NAME = blinky_bootload

main: directories init.rel gpio.rel
	sdcc -I$(INC_PATH) --model-large $(SRC_PATH)/main.c $(BUILD_DIR)/init.rel $(BUILD_DIR)/gpio.rel -o $(BUILD_DIR)/$(BUILD_NORMAL_NAME).ihx
	packihx $(BUILD_DIR)/$(BUILD_NORMAL_NAME).ihx > $(BUILD_DIR)/$(BUILD_NORMAL_NAME).hex

bootload: directories init.rel gpio.rel
	sdcc --code-loc 0x0400 -I$(INC_PATH) --model-large $(SRC_PATH)/main.c $(BUILD_DIR)/init.rel $(BUILD_DIR)/gpio.rel -o $(BUILD_DIR)/$(BUILD_BOOTL_NAME).ihx
	packihx $(BUILD_DIR)/$(BUILD_BOOTL_NAME).ihx > $(BUILD_DIR)/$(BUILD_BOOTL_NAME).hex
	srec_cat -Disable_Sequence_Warnings $(BUILD_DIR)/$(BUILD_BOOTL_NAME).hex -Intel -offset -0x0400 -Output $(BUILD_DIR)/$(BUILD_BOOTL_NAME).bin -Binary

directories: 
ifeq ($(OS),Windows_NT)
	if not exist "$(BUILD_DIR)" mkdir $(BUILD_DIR)
else
	mkdir -p $(BUILD_DIR)
endif

gpio.rel: $(SRC_PATH)/gpio.c $(INC_PATH)/gpio.h
	sdcc -I$(INC_PATH) --model-large -c $(SRC_PATH)/gpio.c -o $(BUILD_DIR)/

init.rel: $(SRC_PATH)/init.c $(INC_PATH)/init.h
	sdcc -I$(INC_PATH) --model-large -c $(SRC_PATH)/init.c -o $(BUILD_DIR)/

.PHONY: clean

clean:
	rm -rf flash.jlink
	rm -rf $(BUILD_DIR)
	
JLINK_OPTS = -device EFM8UB20F64G -if c2 -speed 4000
# flashing windows vs. posix
ifeq ($(OS),Windows_NT)
JLINK = JLink $(JLINK_OPTS)
else
JLINK = JLinkExe $(JLINK_OPTS)
endif # flashing windows vs. posix

flash: flash.jlink
	$(JLINK) flash.jlink

flash.jlink:
	printf "erase\nloadbin build/$(BUILD_NORMAL_NAME).hex,0\nexit\n" > flash.jlink