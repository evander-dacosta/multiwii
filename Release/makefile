################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/subdir.mk
-include Libraries/Wire/utility/subdir.mk
-include Libraries/Wire/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
multiWii_controller.elf \

EEP += \
multiWii_controller.eep \

FLASH_IMAGE += \
multiWii_controller.hex \


# All Target
all: multiWii_controller

# Tool invocations
multiWii_controller: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/evander/Desktop/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-size" -A "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/multiWii_controller.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/evander/Desktop/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-ar" rcs  "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

multiWii_controller.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/evander/Desktop/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p  -o "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/multiWii_controller.elf"   $(LINK_OBJ) $(AR)  "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/arduino.ar" "-L/home/evander/Desktop/arduino sketches/multiWii_controller/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

multiWii_controller.eep: $(ELF)
	@echo 'Create eeprom image'
	"/home/evander/Desktop/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/multiWii_controller.elf" "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/multiWii_controller.eep"
	@echo 'Finished building: $@'
	@echo ' '

multiWii_controller.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/evander/Desktop/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/multiWii_controller.elf" "/home/evander/Desktop/arduino sketches/multiWii_controller/Release/multiWii_controller.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(AR)$(C_DEPS)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(ELF)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(INO_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(PDE_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) multiWii_controller
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
