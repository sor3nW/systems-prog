#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
 char course_Name [84];
 char course_Sched [4];
 unsigned course_Size ;
 unsigned course_Hours ;
 char padding [20];
} COURSE ;

int main() {
    FILE *file = fopen("courses.dat", "rb+");
    if (file == NULL){
        file = fopen("courses.dat", "wb");
        if (file == NULL) {
            printf("Error creating file.\n");
            return 1;
        }
        
    }
    fclose(file);
    char buffer[4096];
    long recordOffset;
    char choice;
    
    int run = 1;
    while (run == 1){

        printf("Enter one of the following actions or press CTRL-D to exit.\n");
        printf("C - create a new course record\n");
        printf("U - update an existing course record\n");
        printf("R - read an existing course record\n");
        printf("D - delete an existing course record\n");

        
        unsigned courseNum;

        fopen("courses.dat", "rb+");
        fflush(stdin);

        fgets(buffer, sizeof(buffer), stdin);
        strcpy(choice, buffer[0] );
        strcpy(buffer, "");
        choice = toupper(choice);


        if (feof(stdin)){
            run = 0;
            break;
        }
        

        switch(choice){
            case 'C':
                COURSE course;


                break;

            case 'U':
                

            case 'R':
                
                break;
            case 'D':
                
            
            default:
                printf("ERROR: invalid option\n");
                
                break;
        }
        if(run == 0){
            break;
        }
        
        
    }
    return 0;
}
