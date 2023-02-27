#include "./bmp_header.h"


void edit(char* path, bmp_image *image) {

    FILE *fptr;
    bmp_fileheader file_header;
    int padding;

    fptr = fopen(path, "rb");

    if(fptr == NULL) {
        printf("\nERROR READING FILE!\n");
        return;
    }

    //read the fileheader of bmp image
    fread(&file_header, sizeof(file_header), 1, fptr);

    if (file_header.file_marker1 != 'B' || file_header.file_marker2 != 'M') {

        printf("\nERROR:FILE TYPE IS NOT BMP!!\n");
        return;
    }

    fread(&(image->infoheader), sizeof(image->infoheader), 1, fptr);

    //row padding based on width of the image 
    padding = (4 - (PIXEL_SIZE * image->infoheader.width)) % 4;

    uint32_t image_size = image->infoheader.width * image->infoheader.height;

    image->pixel_map = malloc(image_size * sizeof(pixel));


    for (int32_t i = 0; i < image->infoheader.height; ++i) {
        for (int32_t j = 0; j < image->infoheader.width; ++j) {
            int32_t offset = i * image->infoheader.width + j;

            fread(image->pixel_map + offset, sizeof(pixel), 1, fptr); 

        }
        //jump over the padding
        fseek(fptr, padding, SEEK_CUR);
    }

    fclose(fptr);
    return;

}


void save(char* path, bmp_image* image) {

    FILE* fout = NULL;

    if (path != NULL) {
        fout  = fopen(path, "wb");
    }
    bmp_fileheader fileheader;

    fileheader.file_marker1 = 'B';
    fileheader.file_marker2 = 'M';
    fileheader.unused1 = 0;
    fileheader.unused2 = 0;
    fileheader.bf_size = BMP_FILE_SIZE + image->infoheader.height * image->infoheader.width * PIXEL_SIZE;
    fileheader.image_data_offset = BMP_FILE_SIZE;

    //write the fileheader to the new file 
    fwrite(&fileheader, sizeof(fileheader), 1, fout);

    //write the infoheader of the image
    fwrite(&(image->infoheader), sizeof(image->infoheader), 1, fout);


    int padding = (4 - (PIXEL_SIZE * image->infoheader.width)) % 4;

    for (int32_t i = 0; i < image->infoheader.height; ++i) {
        for (int32_t j = 0; j < image->infoheader.width; ++j) {
            int32_t offset = i * image->infoheader.width + j;

            //we write the image to the new file pixel by pixel
            fwrite(image->pixel_map + offset, sizeof(pixel), 1, fout);

        }
        //jump over the padding
        fseek(fout, padding, SEEK_CUR);
    }
    fclose(fout);

}

void quit(bmp_image* image) {

    free(image->pixel_map);
    free(image);


}







