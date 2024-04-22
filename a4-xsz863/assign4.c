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
    int run = 1;
    while (run == 1){
        FILE *file;
        file = fopen("courses.dat", "rb+");
        if (file == NULL){
            file = fopen("courses.dat", "wb");
            if (file == NULL) {
                printf("Error creating file.\n");
                return 1;
            }
        }

        COURSE course;
        int courseNum;
        long recordOffset;
        char choice = 'a';
        int found = 0;
        int run = 1;
        
        printf("Enter one of the following actions or press CTRL-D to exit.\n");
        printf("C - create a new course record\n");
        printf("U - update an existing course record\n");
        printf("R - read an existing course record\n");
        printf("D - delete an existing course record\n");
        scanf("%c", &choice);

        
        switch(toupper(choice)){
            case 'C':
                found = 0;
                printf("Course number: ");
                scanf("%d", &courseNum);
                printf("Course name: ");
                scanf("%s", course.course_Name);
                printf("Course schedule: ");
                scanf("%s", course.course_Sched);
                printf("Course credit hours: ");
                scanf("%u", &course.course_Hours);
                printf("Course enrollment: ");
                scanf("%u", &course.course_Size);
                
                

                recordOffset = (long)(courseNum) * sizeof(COURSE);
                fseek(file, recordOffset, SEEK_SET);

                if (fread(&course, sizeof(COURSE), 1, file) == 1){
                    if (course.course_Hours != 0){
                        found = 1;
                    }
                    
                }
                fseek(file, recordOffset, SEEK_SET);
                if (found == 0){
                    fwrite(&course, sizeof(COURSE), 1, file);
                }else {
                    printf("ERROR: Course already exists.\n");
                }
                
                break;
            case 'U':
                found = 1;
                
                printf("Course number: ");
                scanf("%d", &courseNum);
                printf("Course name: ");
                scanf("%s", course.course_Name);
                printf("Course schedule: ");
                scanf("%s", course.course_Sched);
                printf("Course credit hours: ");
                scanf("%u", course.course_Hours);
                printf("Course enrollment: ");
                scanf("%u", course.course_Size);
                
                recordOffset = (long)(courseNum) * sizeof(COURSE);
                fseek(file, recordOffset, SEEK_SET);

                if (fread(&course, sizeof(COURSE), 1, file) == 1){
                    if (course.course_Hours != 0){
                        found = 1;
                    }
                    
                }

                if (found == 1){
                    fseek(file, recordOffset, SEEK_SET);
                    fwrite(&course, sizeof(COURSE), 1, file);
                }else {
                    printf("ERROR: Course not Found\n");
                }
                break;
            case 'R':
                while (getchar() != '\n');
                printf("Enter a CS course number: ");
                scanf("%d", &courseNum);
                
                recordOffset = (long)(courseNum) * sizeof(COURSE);
                fseek(file, recordOffset, SEEK_SET);

                if (fread(&course, sizeof(COURSE), 1, file) == 1){
                    if (course.course_Hours != 0){
                        
                        printf("Course number: %d\n", courseNum);
                        printf("Course name: %s\n", course.course_Name);
                        printf("Course schedule: %s\n", course.course_Sched);
                        printf("Course credit hours: %u\n", course.course_Hours);
                        printf("Course enrollment: %u\n", course.course_Size);
                    }
                }else{
                    printf("ERROR: Course Not found\n");
                }

                break;
            case 'D':
                printf("Enter a course number: ");
                scanf("%d", &courseNum);
                recordOffset = (long)(courseNum) * sizeof(COURSE);
                fseek(file, recordOffset, SEEK_SET);
                if (fread(&course, sizeof(COURSE), 1, file) == 1){
                    course.course_Hours = 0;
                    fseek(file, recordOffset, SEEK_SET);
                    fwrite(&course, 1, 100, file);
                }

                break;
            default:
                printf("ERROR: Invalid Option\n");
        }
        fclose(file);
    }
    return 0;
}
