# Project Overiview

This project is an implementation of a bmp image editor with a few commands.
The editor is implemented as an interactive console where it receives commands
while quit command is not entered.

## Interactive console commands

save \<path\> <br />
edit \<path\> <br />
insert \<\path\> y x<br />
set draw_color R G B<br />
set line_width x<br />
draw line y1 x1 y2 x2<br />
draw circle y x r<br />
quit<br />

\<path\> - path to bmp image


# Build 

You can run this project on linux or macOS. There is a Makefile with two rules:
build - generates an executable named build<br />
clean - deletes all the object files and the executable<br />

To build the project and to run a test run this command:

```
make build
./build < ./tests/testname
```
When running a test the image will be created in current directory.
