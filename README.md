#Project Overiview
This project is an implementation of a bmp image editor with a few commands.
The editor is implemented as an interactive console where it receives commands
while quit command is not entered.

##Interactive console commands
save <path>
edit <path>
insert <path> y x
set draw_color R G B
set line_width x
draw line y1 x1 y2 x2
draw circle y x r
quit

<path> - path to bmp image


#Build 
You can run this project on linux or macOS. There is a Makefile with two rules:
build - generates an executable named build
clean - deletes all the object files and the executable
