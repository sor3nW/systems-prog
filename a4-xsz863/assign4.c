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

FILE *file;
int main() {

    file = fopen("courses.dat", "rb+");
    if (file == NULL){
        file = fopen("courses.dat", "wb");
        if (file == NULL) {
            printf("Error creating file.\n");
            return 1;
        }
    }
    fclose(file);
    fopen("courses.dat", "rb+");
    
    long recordOffset;
    char choice;
    int run = 1;
    while (run == 1){
        
        printf("Enter one of the following actions or press CTRL-D to exit.\n");
        printf("C - create a new course record\n");
        printf("U - update an existing course record\n");
        printf("R - read an existing course record\n");
        printf("D - delete an existing course record\n");

        COURSE course;
        int courseNum = 0;

        fflush(stdin);

        scanf("%c", &choice);
        choice = toupper(choice);

        if (feof(stdin)){
            run = 0;
            break;
        }
        
        //fopen("courses.dat", "rb+");
        
        switch(choice){
            case 'C':
                createCourse();

            case 'U':

                updateCourse();
            case 'R':
                readCourse();
            case 'D':
                deleteCourse();
            default:
                printf("ERROR: invalid option\n");
                
                break;
        }        if(run == 0){
            break;
        }
        
        
    }
    fclose(file);
    return 0;
}
void createCourse(){
    printf("Course number: ");
    scanf("%d", &courseNum);

    while (getchar() != '\n');

    printf("Enter course name: ");
    fgets(course.course_Name, sizeof(course.course_Name), stdin);
    course.course_Name[strcspn(course.course_Name, "\n")] = '\0'; 

    printf("Enter course schedule: ");
    fgets(course.course_Sched, sizeof(course.course_Sched), stdin);
    course.course_Sched[strcspn(course.course_Sched, "\n")] = '\0'; 

    printf("Enter course hours: ");
    scanf("%u", &course.course_Hours);

    printf("Enter course size: ");
    scanf("%u", &course.course_Size);
                
    recordOffset = (long)(courseNum); 
    fseek(file, recordOffset, SEEK_SET);
    printf("%ld", ftell(file));

    COURSE oldcourse;

    if (fread(&oldcourse, sizeof(COURSE), 1, file) != 1) {
        fseek(file, recordOffset, SEEK_SET);
        fwrite(&course, sizeof(COURSE), 1, file);
        printf("Course record created 1.\n");
        fflush(file);
        break;
    }

    fseek(file, recordOffset, SEEK_SET);
    if (fread(&course, sizeof(COURSE), 1, file) == 1 && oldcourse.course_Hours == 0) {
        fseek(file, recordOffset, SEEK_SET);
        fwrite(&course, sizeof(COURSE), 1, file);
        printf("Course record created successfully 2.\n");
        fflush(file);
        break;
    } else {
        printf("ERROR: Course already exists.\n");
    }
    fflush(file);
    while (getchar() != '\n');
    break;

}
void updateCourse(){
    printf("Course number: ");
    scanf("%d", &courseNum);
    
    while (getchar() != '\n');
    
    printf("Enter course name: ");
    fgets(course.course_Name, sizeof(course.course_Name), stdin);
    course.course_Name[strcspn(course.course_Name, "\n")] = '\0'; 

    printf("Enter course schedule: ");
    fgets(course.course_Sched, sizeof(course.course_Sched), stdin);
    course.course_Sched[strcspn(course.course_Sched, "\n")] = '\0'; 

    printf("Enter course hours: ");
    scanf("%u", &course.course_Hours);

    printf("Enter course size: ");
    scanf("%u", &course.course_Size);
    
    recordOffset = (long)(courseNum);
    fseek(file, recordOffset, SEEK_SET);

    if (fread(&course, sizeof(COURSE), 1, file) == 1 && course.course_Hours != 0){
        fseek(file, recordOffset, SEEK_SET);
        fwrite(&course, sizeof(COURSE), 1, file);
        fflush(file);
        printf("Course record updated successfully.\n");
    }else{
        printf("ERROR: course not found\n");
    }

    while (getchar() != '\n');
    break;
}
void readCourse(){
    printf("Enter a CS course number: ");
    scanf("%d", &courseNum);   
    while (getchar() != '\n');

    recordOffset = (long)(courseNum);
    fseek(file, recordOffset, SEEK_SET);
    printf("%ld\n", ftell(file));

    if (fread(&course, sizeof(COURSE), 1, file) != 1 ){
        printf("ERROR: course not found 1\n");
        break;
    }
    fseek(file, recordOffset, SEEK_SET);
    if (fread(&course, sizeof(COURSE), 1, file) == 1 && course.course_Hours == 0){
        printf("ERROR: course not found 2\n");
        break;
    }else{
        fseek(file, recordOffset, SEEK_SET);
        printf("Course number: %d\n", courseNum);
        printf("Course name: %s\n", course.course_Name);
        printf("Course schedule: %s\n", course.course_Sched);
        printf("Course credit hours: %u\n", course.course_Hours);
        printf("Course enrollment: %u\n", course.course_Size);
        
    }
    break;
}
void deleteCourse(){
    printf("Enter a course number: ");
    scanf("%d", &courseNum);
    
    while (getchar() != '\n');
    recordOffset = (long)(courseNum);
    fseek(file, recordOffset, SEEK_SET);
    if (fread(&course, sizeof(COURSE), 1, file)){
        fseek(file, recordOffset, SEEK_SET);
        course.course_Hours = 0;
        printf("Course number: %d\n", courseNum);
        printf("Course name: %s\n", course.course_Name);
        printf("Course schedule: %s\n", course.course_Sched);
        printf("Course credit hours: %u\n", course.course_Hours);
        printf("Course enrollment: %u\n", course.course_Size);
        printf("%ld\n", ftell(file));
        fseek(file, recordOffset, SEEK_SET);
        printf("%ld\n", ftell(file));
        fwrite(&course, sizeof(COURSE), 1, file);
        fflush(file);
    }else{
        printf("ERROR: course not found\n");
    }
    break;
}
