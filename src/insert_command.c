#include "./bmp_header.h"


void insert_image(bmp_image* image_to_insert, bmp_image* edit_image, int y, int x) {
    
    int32_t x_limit, y_limit;

    if (x > edit_image->infoheader.height || y > edit_image->infoheader.width) {
        printf("\nERROR: WRONG COORDINATES!!!\n");
    }

    //check if insert image is bigger than the space left in edit_image
    if (edit_image->infoheader.height - x < image_to_insert->infoheader.height) {
        x_limit = edit_image->infoheader.height;
    } else {
        x_limit = x + image_to_insert->infoheader.height;
    }


    if (edit_image->infoheader.width - y < image_to_insert->infoheader.width) {
        y_limit = edit_image->infoheader.width;
    } else {
        y_limit = y + image_to_insert->infoheader.width;
    }

    for (int32_t i = x; i < x_limit; ++i) {

        for (int32_t j = y; j < y_limit; ++j) { 

            int32_t offset = i * edit_image->infoheader.width + j;
            int32_t offset_insert = (i - x) * image_to_insert->infoheader.width + (j - y);

            edit_image->pixel_map[offset].B = image_to_insert->pixel_map[offset_insert].B;
            edit_image->pixel_map[offset].G = image_to_insert->pixel_map[offset_insert].G;
            edit_image->pixel_map[offset].R = image_to_insert->pixel_map[offset_insert].R;
            


        }
        
    }

}