#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE *file = fopen("gpa.dat", "rb");
    if (file == NULL){
        perror("Error opening file");
        return 1;
    }
    fseek(file, 2 * sizeof(struct StudentRecord), SEEK_SET);

    struct StudentRecord *student1 = (struct StudentRecord *)malloc(sizeof(struct StudentRecord));
    fread(&student1, sizeof(struct StudentRecord), 1, file);
    fclose(file);
    return 0;
}