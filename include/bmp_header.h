/* Tells the compiler not to add padding for these structs. This may
   be useful when reading/writing to binary files.
   http://stackoverflow.com/questions/3318410/pragma-pack-effect
*/
#pragma pack(1)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define BUFFER_SIZE 256 
#define PIXEL_SIZE 3
#define BMP_FILE_SIZE 54                        
#define NO_OF_COMMANDS 4
#define MAX_SIZE_COMMAND 50
#define MAX_LINE_WIDTH 18
#define MIN_LINE_WIDTH 1
#define randnum(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))


typedef struct 
{
    uint8_t     file_marker1; /* 'B' */
    uint8_t     file_marker2; /* 'M' */
    uint32_t    bf_size; /* File's size */
    uint16_t    unused1; /* Aplication specific */
    uint16_t    unused2; /* Aplication specific */
    uint32_t    image_data_offset; /* Offset to the start of image data */
} bmp_fileheader;

typedef struct 
{
    uint32_t    bi_size; /* Size of the info header - 40 bytes */
    int32_t     width; /* Width of the image */
    int32_t     height; /* Height of the image */
    uint16_t    planes;
    uint16_t    bit_pix; /* Number of bits per pixel = 3 * 8 (for each channel R, G, B we need 8 bits */
    uint32_t    bi_compression; /* Type of compression */
    uint32_t    bi_size_image; /* Size of the image data */
    int32_t     bi_xpels_per_meter;
    int32_t     bi_xpelsPerMeter;
    uint32_t    bi_clr_used;
    uint32_t    bi_clr_important;
} bmp_infoheader;



typedef struct 
{
    uint8_t B;
    uint8_t G;
    uint8_t R;

} pixel;

typedef struct 
{
    bmp_infoheader infoheader;
    pixel *pixel_map;


} bmp_image;

typedef struct 
{
    pixel color;
    uint8_t width;
    
} brush;


void    edit                 (char*, bmp_image*);
void    save                 (char* path, bmp_image*);
void    quit                 (bmp_image*);
void    insert_image         (bmp_image*, bmp_image*, int, int); 
void    set_brush_color      (brush*, uint8_t, uint8_t, uint8_t);
void    set_brush_width      (brush*, uint8_t);
void    draw_line            (bmp_image*, brush, int32_t, int32_t, int32_t, int32_t);
void    set_color_of_pixel   (bmp_image*, int32_t, brush);
void    draw_circle          (bmp_image*, brush, int32_t, int32_t, int32_t); 
void    set_pixel_width      (bmp_image*, brush, float, float);
char*   random_command       (void);


#pragma pack()
