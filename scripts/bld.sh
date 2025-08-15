#!/usr/bin/env bash

# compile to binary & hex, upload to arduino at connected port

USBPORT=/dev/tty.usbmodem2101
CHIP=atmega328p

# compile to object
avr-gcc -mmcu=$CHIP -Os -DF_CPU=16000000UL -c -o bld/main.o src/main.c

# executable
avr-gcc -mmcu=$CHIP bld/main.o -o bin/main 

# hex
avr-objcopy -O  ihex -R .eeprom bin/main hex/main.hex

# upload to arduino
avrdude -c arduino -p m328p -P $USBPORT -b 115200 -U flash:w:hex/main.hex:i