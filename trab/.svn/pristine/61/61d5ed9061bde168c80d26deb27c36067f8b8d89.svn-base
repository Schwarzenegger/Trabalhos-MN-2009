#!/bin/bash

make clean
qmake -project
echo "QT += opengl" >> XTocator.pro
qmake XTocator.pro
make
make clean

