#!/bin/sh

# TODO: This should be a proper makefile, or a CMake project

DEBUG=-g
SRC="src/Args.cpp src/Util.cpp src/ConsoleLogger.cpp src/Vector2.cpp src/BoxCollider.cpp src/Transform.cpp src/GameObject.cpp src/Color.cpp src/Config.cpp src/Engine.cpp src/Field.cpp src/Paddle.cpp src/Ball.cpp src/frack.cpp"
LIBS="-lsfml-system -lsfml-window -lsfml-graphics"
INCDIR="include"
BIN="bin/frack"
MISCOPTS="-std=c++17"

# Rerun Ctags to stay current
ctags -R

rm bin/frack
clear&&clear
g++ -o $BIN -I$INCDIR  -Wall $SRC $LIBS $DEBUG $MISCOPTS

