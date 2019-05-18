#!/bin/sh

BUILD=./build.sh
BIN=./bin/frack

if [ ! -x $BIN ]; then
    echo "$BIN not found. Building..."
    $BUILD
fi

echo "Running $BIN..."
./bin/frack
