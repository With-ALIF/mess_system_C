#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_LOGS 100

typedef struct {
    char date[11];
    int breakfast;
    int lunch;
    int dinner;
} MealLog;

typedef struct {
    char roll_no[20];
    char name[50];
    int room;
    double balance;
    MealLog logs[MAX_LOGS];
    int log_count;
} Student;

extern Student students[MAX_STUDENTS];
extern int student_count;

void register_student();
void view_all_students();
int find_student_index(char roll[]);

#endif
