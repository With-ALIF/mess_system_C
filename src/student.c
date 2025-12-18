#include <stdio.h>
#include <string.h>
#include "student.h"
#include "file_handler.h"

Student students[MAX_STUDENTS];
int student_count = 0;

int find_student_index(char roll[]) {
    for (int i = 0; i < student_count; i++)
        if (strcmp(students[i].roll_no, roll) == 0)
            return i;
    return -1;
}

void register_student() {
    Student s;

    printf("Enter Roll No: ");
    scanf(" %19s", s.roll_no);

    printf("Enter Name: ");
    scanf(" %49s", s.name);

    printf("Enter Room No: ");
    scanf("%d", &s.room);

    printf("Enter Initial Balance: ");
    scanf("%lf", &s.balance);

    s.log_count = 0;
    students[student_count++] = s;
    save_students();
}

void view_all_students() {
    for (int i = 0; i < student_count; i++)
        printf("%s %s %.2lf\n",
               students[i].roll_no,
               students[i].name,
               students[i].balance);
}
