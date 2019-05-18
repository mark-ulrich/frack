#!/bin/sh

BIN=./bin/frack

if [ -f $BIN ]; then
    echo "Cleaning $BIN..."
    rm $BIN
else
    echo "$BIN not found"
fi

