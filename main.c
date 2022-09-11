#include "./bmp_header.h"





int main() {


    //In main we create our parser 
    int quit_parser = 1;
    char* command = malloc(BUFFER_SIZE);

    
    while (quit_parser) {

        scanf("%s", command);

        if (!strcmp(command, "edit")) {

            //read the path of the image 
            scanf("%s", command);
            printf("%s edit zaibisi \n", command);

        } else if (!strcmp(command, "save")) {

            //read the path of the image that'll be created 
            scanf("%s", command);
            printf("%s save zaibisi \n", command);


        } else if (!strcmp(command, "quit")) {

            quit_parser = 0;
        }


    }
    


    






    





    return 0;
}













































