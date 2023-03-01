#include "./bmp_header.h" 



void set_brush_color(brush *my_brush, uint8_t R, uint8_t G, uint8_t B) 
{

    my_brush->color.R = R;
    my_brush->color.G = G;
    my_brush->color.B = B; 
}

void set_brush_width(brush *my_brush, uint8_t width) 
{
    my_brush->width = width;
}
void set_color_of_pixel(bmp_image* image, int32_t position, brush my_brush)
{
    image->pixel_map[position].B = my_brush.color.B;
    image->pixel_map[position].G = my_brush.color.G;
    image->pixel_map[position].R = my_brush.color.R;

}

void set_pixel_width(bmp_image* image, brush my_brush, float i, float j) 
{

    int32_t start_i = (int)i - my_brush.width/2;
    int32_t start_j = (int)j - my_brush.width/2;

    for (int32_t pos_y = start_i; pos_y < start_i + my_brush.width; ++pos_y) {
        for (int32_t pos_x = start_j; pos_x < start_j + my_brush.width; ++pos_x) {
                
            if (pos_x >= 0 && pos_y >= 0 && 
                pos_y < image->infoheader.height && start_j < image->infoheader.width){    
                   
                int32_t offset = pos_y * image->infoheader.width + pos_x;

                set_color_of_pixel(image, offset, my_brush);
            }
        }
    }
    
}


void draw_line (bmp_image* image, brush my_brush, int32_t y1, int32_t y2, int32_t x1, int32_t x2) 
{

    // y is the position on the line & x is the line number (it reversed from mathematical notation)
int32_t coord_min = 0, coord_max = 0;

    if (y1 > y2) { 
        coord_max = y1;
        coord_min = y2;
    } else if (y1 < y2) {
        coord_max = y2;
        coord_min = y1;
    } else if (y2 == y1) {
        //the case when the x coordinate is constant
        if (x1 > x2) { 
            coord_max = x1;
            coord_min = x2;
        } else if (x1 < x2) {
            coord_max = x2;
            coord_min = x1;
        } 
    }
    float i = 0;

    for (int32_t j = coord_min; j <= coord_max; ++j) {
        //goes through the image through the OX axis(like in maths) & finds the y coordinate for each point
        //not to forget to make te y1 = y2 || x1 = x2 cases         
         
        //i will be our y coordinate 
        if (x2 != x1 && y2 != y1) { // the equation line case
            i = (j-y1) * (x2-x1) / (y2-y1) + x1;
        } else if(x2 == x1) { // the y const case
            i = x1;
        } else if(y1 == y2) { // the x const case
            i = (float)y1;
        }
        // we calc the left upper corner then make a square that has the brush 
        // width from that point. We check if the pixel we want to colour is 
        //not out of bounds
        if (y1 != y2) {
            //in case of horizontal line or a normal line we keep the coordinates
            set_pixel_width(image, my_brush, i, (float)j); 
        } else {
            //invert the coordinates to draw a vertical line 
            set_pixel_width(image, my_brush, (float)j, i); 
        
        }

    }

    printf("\n !!DRAWING FINISHED!!\n");
   
}


void draw_circle(bmp_image *image, brush my_brush, int32_t y, int32_t x, int32_t r) 
{
    // y and x are reversed
    for (int32_t j = y - r; j <= y + r; ++j) {

        float delta = 4*x*x - 4*(j*j - 2*j*y + y*y + x*x - r*r);
        float i1 = (2*x + sqrt(delta))/2;
        float i2 = (2*x - sqrt(delta))/2;

        if (j >= 0 && i2 >= 0 && i1 >= 0 && j <= image->infoheader.width
            && i1 <= image->infoheader.height && i2 <= image->infoheader.height) {

                    int32_t offset;
                if (j == y-r || j == y+r) {

                    set_pixel_width(image, my_brush, i1 - my_brush.width, (float)j); 
                    set_pixel_width(image, my_brush, i1, (float)j); 
                    set_pixel_width(image, my_brush, i1 + my_brush.width, (float)j); 
                    
                } else {
                    set_pixel_width(image, my_brush, i1, (float)j); 
                    set_pixel_width(image, my_brush, i2, (float)j); 
                }
        }

    }
    printf("\n !!CIRCLE FINISHED!!");
}























