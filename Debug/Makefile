################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Tools


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.c \
../Tools/LCD.c \
../Tools/Tools.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
Tools/LCD.o \
Tools/Tools.o

OBJS_AS_ARGS +=  \
main.o \
Tools/LCD.o \
Tools/Tools.o

C_DEPS +=  \
main.d \
Tools/LCD.d \
Tools/Tools.d

C_DEPS_AS_ARGS +=  \
main.d \
Tools/LCD.d \
Tools/Tools.d

OUTPUT_FILE_PATH +=US_LCD_PRJ_Davy_Raitt.elf

OUTPUT_FILE_PATH_AS_ARGS +=US_LCD_PRJ_Davy_Raitt.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Tools/LCD.o: ../Tools/LCD.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Tools/Tools.o: ../Tools/Tools.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="US_LCD_PRJ_Davy_Raitt.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega128 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128"  
	@echo Finished building target: $@
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "US_LCD_PRJ_Davy_Raitt.elf" "US_LCD_PRJ_Davy_Raitt.hex"
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "US_LCD_PRJ_Davy_Raitt.elf" "US_LCD_PRJ_Davy_Raitt.eep" || exit 0
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "US_LCD_PRJ_Davy_Raitt.elf" > "US_LCD_PRJ_Davy_Raitt.lss"
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "US_LCD_PRJ_Davy_Raitt.elf" "US_LCD_PRJ_Davy_Raitt.srec"
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "US_LCD_PRJ_Davy_Raitt.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "US_LCD_PRJ_Davy_Raitt.elf" "US_LCD_PRJ_Davy_Raitt.a" "US_LCD_PRJ_Davy_Raitt.hex" "US_LCD_PRJ_Davy_Raitt.lss" "US_LCD_PRJ_Davy_Raitt.eep" "US_LCD_PRJ_Davy_Raitt.map" "US_LCD_PRJ_Davy_Raitt.srec" "US_LCD_PRJ_Davy_Raitt.usersignatures"
	