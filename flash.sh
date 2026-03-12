#!/bin/bash
echo "Make sure you built in CubeIDE first (Cmd+B)"
echo ""

if [ ! -f "Debug/PRISM_STM32.bin" ]; then
    echo "Debug/PRISM_STM32.bin not found!"
    exit 1
fi

echo "Flashing..."
st-flash --reset write Debug/PRISM_STM32.bin 0x08000000
if [ $? -ne 0 ]; then
    echo "Flash failed!"
    exit 1
fi

echo "Flash complete!"
echo "Starting serial monitor (Ctrl+A then K to exit)..."
sleep 1
screen /dev/tty.usbmodem11403 115200
