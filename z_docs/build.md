# build commands to build project & upload to arduino
# run ./scripts/bld.sh

## see usb port:
`ls /dev/tty.*`
- should be like `/dev/tty.usbmodem2101`
## compile to object .o file
`avr-gcc -mmcu=atmega328p -Os -DF_CPU=16000000UL -c -o bld/main.o src/main.c`
## compile to binary
`c`
## compile to hex
`avr-objcopy -O  ihex -R .eeprom bin/main hex/main.hex`
## upload to chip
- uno (with usb-b):
    - `avrdude -c arduino -p m328p -P /dev/tty.usbmodem2101 -b 115200 -U flash:w:main.hex:i`
    - `avrdude -c arduino -p m328p -P /dev/tty.usbmodem2101 -b 115200 -U flash:w:hex/main.hex:i`
- nano (with usb-c)
    - `avrdude -c arduino -p m328p -P /dev/tty.usbserial-210 -b 115200 -U flash:w:main.hex:i`
