#!/bin/bash
aclocal
touch ./AUTHORS
touch ./ChangeLog
touch ./NEWS
touch ./README
automake --add-missing
autoreconf -fi
automake
./configure
make