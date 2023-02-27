#include "./bmp_header.h"

char* random_command(bmp_image* image)
{
    char* command = malloc(50 * sizeof(char));

    // len = snprintf(str, 16, "%s %d", "hello world", 1000);
    //we have three command
    int random = rand() % 4;
    
    printf("%d %s\n ", random, *(command_list + random) );

    switch (random)
    {
    case 0;
        // set draw_color 
        int32_t r, g, b; 
        r = randnum(0,255);
        g = randnum(0,255);
        b = randnum(0,255);

        snprintf(command, 50, "set draw_color %d %d %d", r, g, b);

        break;
    case 1;
        // set line_width
        int32_t width;
        width = rand(MIN_LINE_WIDTH, MAX_LINE_WIDTH);
        snprintf(command, 50, "set line_width %d\n", width);

        break;
    case 2;
        // draw line
        int32_t x1, y1, x2, y2;
        y1 = randnum(0, image->infoheader.width - 1);
        y2 = randnum(0, image->infoheader.width - 1);
        x1 = randnum(0, image->infoheader.height - 1);
        x2 = randnum(0, image->infoheader.height - 1);

        snprintf(command, 50, "draw line %d %d %d %d \n", y1, x1, y2, x2);

        break;
    case 3;
        // draw circle 
        int32_t x, y, r;
        y = randnum(0, image->infoheader.width - 1);
        x = randnum(0, image->infoheader.height - 1);
        r = randnum(5, 200);

        snprintf(command, 50, "draw circle %d %d %d", y, x, r);

        break;
    
    default:
        break;
    }

    return command;
}



void random_drawing(bmp_image* image) 
{



}