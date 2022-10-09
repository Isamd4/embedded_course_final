#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 
# Architectures Specific Flags
LINKER_FILE =msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
BASENAME=c1m2
TARGET=$(BASENAME).out
LDFLAGS =-Wl,-Map=$(BASENAME).map -T ../$(LINKER_FILE)
CPPFLAGs=-Wall -Werror -g -O0 -std=c99 $(INCLUDES) 
CFLAGS =-DMSP432 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(CPPFLAGs) -MD 

ifeq ($(PLATFORM),MSP)
	PLATFORM=MSP432
	CC=arm-none-eabi-gcc
	LD=arm-none-eabi-ld
endif
ifeq ($(PLATFORM),HOST)
	PLATFORM=HOST
	CC=gcc
	SOURCES = ./main.c\
		 	  ./memory.c
	LDFLAGS =-Wl,-Map=$(BASENAME).map 
	CFLAGS=$(CPPFLAGs) -DHOST -MD
endif

OBJS:=$(SOURCES:.c=.o)
ASMFLS:=$(SOURCES:.c=.asm)
DEPFLS:=$(SOURCES:.c=.d)
PREFLS:=$(SOURCES:.c=.i)
%.i:%.c
	$(CC) $(CPPFLAGs) $(INCLUDES) -D$(PLATFORM) -E -o $@ $<
%.asm:%.c
	$(CC) $(CPPFLAGs) $(INCLUDES) -D$(PLATFORM) -S -o $@  $<
	
%.d:%.c
	$(CC) $(CPPFLAGs) $(INCLUDES) -D$(PLATFORM) -M -o $@ $<
%.o:%.c
	$(CC) -c $< $(CFLAGS) -o $@
.PHONY:compile-all
compile-all:$(PREFLS) $(ASMFLS) $(DEPFLS) $(OBJS)
.PHONY:build
build:all
.PHONY:all
all:$(TARGET)
$(TARGET):$(OBJS) 
	$(CC)  $(CFLAGS) $(LDFLAGS) -o $@ $^ 
	size $(TARGET)
.PHONY:clean
clean:
	rm -f $(OBJS) $(TARGET) $(BASENAME).map $() $(PREFLS) $(ASMFLS) $(DEPFLS) 