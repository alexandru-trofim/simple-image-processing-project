#include "./bmp_header.h"





int main() {
    int quit_parser = 1;
    char* command = malloc(BUFFER_SIZE);
    bmp_image *edit_image= malloc(sizeof(*edit_image));
    brush my_brush;
   
   
    long ltime, stime;
    ltime = time(NULL);
    stime = (unsigned) ltime/2;
    srand(stime);

    while (quit_parser) {

        scanf("%s", command);

        if (!strcmp(command, "edit")) {

            //read the path of the image 
            scanf("%s", command);
            edit(command, edit_image);

        } else if (!strcmp(command, "save")) {

            //read the path of the image that'll be created 
            scanf("%s", command);
            save(command, edit_image);

        } else if (!strcmp(command, "quit")) {

            quit_parser = 0; 
            free(command);
            quit(edit_image);

        } else if (!strcmp(command, "insert")) { 

            int32_t y, x;
            bmp_image *image_to_insert = malloc(sizeof(*image_to_insert));
            
            // insert command look like this: insert <path> y x
            scanf("%s", command);
            scanf("%d", &y);
            scanf("%d", &x);

            //read a new image from the "path"            
            edit(command, image_to_insert);
            //insert the new image into the image from the edit mode   
            insert_image(image_to_insert, edit_image, y, x); 
            quit(image_to_insert);
        } else if(!strcmp(command, "set")) {

            scanf("%s", command);
            //we have three types of commands that starts with "set"

            if (!strcmp(command, "line_width")) {
                int32_t width;
                scanf("%d", &width);
                set_brush_width(&my_brush, (uint8_t)width);
            } 
            if (!strcmp(command, "draw_color")) {
                int32_t R, G, B;
                scanf("%d", &R);
                scanf("%d", &G);
                scanf("%d", &B);
                set_brush_color(&my_brush, (uint8_t)R, (uint8_t)G, (uint8_t)B);
            
            } 


        } else if(!strcmp(command, "draw")) {
            scanf("%s", command);

            if (!strcmp(command, "line")) {
                int32_t x1, y1, x2, y2;

                scanf("%d", &y1);
                scanf("%d", &x1);
                scanf("%d", &y2);
                scanf("%d", &x2);

                draw_line(edit_image, my_brush, y1, y2, x1, x2);
            } else if (!strcmp(command, "circle")) {
                int32_t x, y, r;

                scanf("%d", &y);
                scanf("%d", &x);
                scanf("%d", &r);

                draw_circle(edit_image, my_brush, y, x, r);
            }
        }

    }
    




    return 0;
}













































