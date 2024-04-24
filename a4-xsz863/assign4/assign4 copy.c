#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
 char course_Name [84];
 char course_Sched [4];
 unsigned course_Size ;
 unsigned course_Hours ;
 char padding [20];
} COURSE ;

void printMenu();
void printCourse(COURSE *course);
void createCourse();
void readCourse();
void updateCourse();
void deleteCourse();

int main(int argc, char *argv[])
{
	char input[128];

	while (true)
	{
		printMenu();

		if (!fgets(input, 128, stdin))
		{
			break;
		}

		printf("\n");

		switch (input[0])
		{
		case 'C':
		case 'c':
			createCourse();
			break;
		case 'R':
		case 'r':
			readCourse();
			break;
		case 'U':
		case 'u':
			updateCourse();
			break;
		case 'D':
		case 'd':
			deleteCourse();
			break;
		default:
			printf("Invalid menu choice\n");
			break;
		}
		printf("\n");

		strcpy(input, "");
	}

	return 0;
}

void printMenu()
{
	printf("Enter one of the following actions or press CTRL-D to exit.\n");
	printf("C - create a new course record\n");
	printf("R - update an existing course record\n");
	printf("U - read an existing course record\n");
	printf("D - delete an existing course record\n");
}

void printCourse(COURSE *course)
{
	printf("Course name: %s\n", course->course_Name);
	printf("Scheduled days: %s\n", course->course_Sched);
	printf("Credit hours: %u\n", course->course_Hours);
	printf("Enrolled students: %u\n", course->course_Size);
}

void createCourse()
{
	int courseNumber;
	char buff[128];

	FILE *file = fopen("courses.dat", "wb+");

	COURSE course;
	printf("Course number: ");
	fgets(buff, 128, stdin);
	courseNumber = atoi(buff);
	strcpy(buff, "");

	printf("Course name: ");
	fgets(buff, 128, stdin);
	int nameLength = strlen(buff);
	strncpy(course.course_Name, buff, nameLength - 1);
	strcpy(buff, "");

	printf("Course schedule: ");
	fgets(buff, 128, stdin);
	sscanf(buff, "%4[^\n]", course.course_Sched);
	strcpy(buff, "");

	printf("Course size: ");
	fgets(buff, 128, stdin);
	course.course_Size = atoi(buff);
	strcpy(buff, "");

	printf("Course hours: ");
	fgets(buff, 128, stdin);
	course.course_Hours = (unsigned)atoi(buff);
	strcpy(buff, "");

	long status = fseek(file, sizeof(COURSE) * courseNumber, SEEK_SET);
	if (status != 0)
	{
		printf("ERROR: failed to seek to position");
	}
	fwrite(&course, sizeof(COURSE), 1L, file);
	fclose(file);
	printf("Course created\n");
}

void readCourse()
{
	int courseNumber;
	char buff[128];
	FILE *file = fopen("courses.dat", "rb");

	COURSE course;
	printf("Course number: ");
	fgets(buff, 128, stdin);
	courseNumber = atoi(buff);
	printf("%d\n", courseNumber);
	strcpy(buff, "");

	fseek(file, sizeof(COURSE) * courseNumber, SEEK_SET);
	long rc = fread(&course, sizeof(COURSE), 1L, file);

	if (rc != 1)
	{
		printf("ERROR: course not found\n");
		return;
	}
	// printf("Course number: %d\n", courseNumber);
	printCourse(&course);

	fclose(file);
}

void updateCourse()
{
	int courseNumber;
	char buff[128];
	strcpy(buff, "");
	FILE *file = fopen("courses.dat", "rb+");

	COURSE course;
	char newCourseName[83];
	char newCourseSched[4];
	unsigned newCourseSize, newCourseHours;

	printf("Course number: ");
	fgets(buff, 128, stdin);
	courseNumber = atoi(buff);
	strcpy(buff, "");

	fseek(file, sizeof(COURSE) * courseNumber, SEEK_SET);
	long rc = fread(&course, sizeof(COURSE), 1L, file);
	if (rc != 1)
	{
		printf("ERROR: course not found\n");
		return;
	}
	fseek(file, sizeof(COURSE) * courseNumber, SEEK_SET);

	printf("Course name: ");
	fgets(buff, 128, stdin);
	int nameLen = strlen(buff);
	strncpy(newCourseName, buff, nameLen - 1);
	if (strlen(newCourseName) != 0)
	{
		strcpy(course.course_Name, newCourseName);
	}
	strcpy(buff, "");

	printf("Course schedule: ");
	fgets(buff, 128, stdin);
	strncpy(newCourseSched, buff, 3);
	if (strlen(newCourseSched) != 0)
	{
		strcpy(course.course_Sched, newCourseSched);
	}
	strcpy(buff, "");

	printf("Course size: ");
	if (fgets(buff, 128, stdin) == NULL)
	{
		newCourseSize = atoi(buff);
		course.course_Size = newCourseSize;
	}
	strcpy(buff, "");

	printf("Course hours: ");
	if (fgets(buff, 128, stdin) == NULL)
	{
		newCourseHours = atoi(buff);
		course.course_Hours = newCourseHours;
	}
	strcpy(buff, "");

	if (rc != 1L)
	{
		printf("ERROR: course not found\n");
		return;
	}

	rc = fwrite(&course, sizeof(COURSE), 1L, file);
	if (rc != 1L)
	{
		printf("ERROR: failed to write course\n");
	}
	printf("Course updated\n");

	fclose(file);
}

void deleteCourse()
{
	int courseNumber;
	FILE *file = fopen("courses.dat", "rb+");

	char buff[5];
	printf("Course number: ");
	fgets(buff, 5, stdin);
	courseNumber = atoi(buff);

	COURSE *overwrite = calloc(1, sizeof(COURSE));

	int status = fseek(file, sizeof(COURSE) * courseNumber, SEEK_SET);

	if (status != 0)
	{
		printf("ERROR: course not found\n");
		return;
	}
	else
	{
		fwrite(overwrite, sizeof(COURSE), 1L, file);
	}
	fclose(file);
	printf("Course deleted\n");
}
