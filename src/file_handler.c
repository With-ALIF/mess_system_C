#include <stdio.h>
#include "student.h"

void save_students() {
    FILE *fp = fopen("student.txt","w");
    for (int i=0;i<student_count;i++)
        fprintf(fp,"%s %s %d %.2lf\n",
            students[i].roll_no,
            students[i].name,
            students[i].room,
            students[i].balance);
    fclose(fp);
}

void load_students() {
    FILE *fp = fopen("student.txt","r");
    if (!fp) return;
    while (fscanf(fp,"%19s %49s %d %lf",
           students[student_count].roll_no,
           students[student_count].name,
           &students[student_count].room,
           &students[student_count].balance)==4) {
        students[student_count].log_count=0;
        student_count++;
    }
    fclose(fp);
}
