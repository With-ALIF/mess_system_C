#include <stdio.h>
#include <string.h>
#include <time.h>
#include "meal.h"
#include "student.h"

#define MEAL_FILE "meal_log.txt"

static int is_duplicate(int idx, char date[]) {
    for (int i = 0; i < students[idx].log_count; i++) {
        if (strcmp(students[idx].logs[i].date, date) == 0)
            return 1;
    }
    return 0;
}

void book_meal_ui(char roll[]) {
    int idx = find_student_index(roll);
    if (idx == -1) return;

    char date[11];
    int b, l, d;

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %10s", date);

    if (is_duplicate(idx, date)) {
        printf("Meal already booked for this date.\n");
        return;
    }

    printf("Breakfast (1=yes, 0=no): ");
    scanf("%d", &b);
    printf("Lunch (1=yes, 0=no): ");
    scanf("%d", &l);
    printf("Dinner (1=yes, 0=no): ");
    scanf("%d", &d);

    MealLog m;
    strcpy(m.date, date);
    m.breakfast = b;
    m.lunch = l;
    m.dinner = d;

    students[idx].logs[students[idx].log_count++] = m;

    printf("Meal booked successfully!\n");
}

void cancel_meal_ui(char roll[]) {
    int idx = find_student_index(roll);
    if (idx == -1) return;

    char date[11];
    printf("Enter date to cancel (YYYY-MM-DD): ");
    scanf(" %10s", date);

    for (int i = 0; i < students[idx].log_count; i++) {
        if (strcmp(students[idx].logs[i].date, date) == 0) {
            students[idx].logs[i] =
                students[idx].logs[students[idx].log_count - 1];
            students[idx].log_count--;
            printf("Meal cancelled successfully!\n");
            return;
        }
    }

    printf("No meal found for this date.\n");
}

void overall_meal_report(char roll[]) {
    int idx = find_student_index(roll);
    if (idx == -1) return;

    if (students[idx].log_count == 0) {
        printf("No meal records found.\n");
        return;
    }

    int total_meals = 0;

    printf("\n----------------------------------------\n");
    printf("        OVERALL MEAL DETAILS\n");
    printf("----------------------------------------\n");
    printf("Date         B  L  D\n");

    for (int i = 0; i < students[idx].log_count; i++) {
        MealLog m = students[idx].logs[i];
        printf("%s   %d  %d  %d\n",
               m.date, m.breakfast, m.lunch, m.dinner);
        total_meals += m.breakfast + m.lunch + m.dinner;
    }

    printf("----------------------------------------\n");
    printf("Total Days  : %d\n", students[idx].log_count);
    printf("Total Meals : %d\n", total_meals);
    printf("----------------------------------------\n");
}

void monthly_report(char roll[]) {
    int idx = find_student_index(roll);
    if (idx == -1) return;

    double total_cost = 0;

    for (int i = 0; i < students[idx].log_count; i++) {
        MealLog m = students[idx].logs[i];
        if (m.breakfast) total_cost += 20;
        if (m.lunch) total_cost += 30;
        if (m.dinner) total_cost += 30;
    }

    printf("Monthly Meal Cost: %.2lf\n", total_cost);
}

void save_meal_log() {
    FILE *fp = fopen(MEAL_FILE, "w");
    if (!fp) return;

    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < students[i].log_count; j++) {
            fprintf(fp, "%s %s %d %d %d\n",
                    students[i].roll_no,
                    students[i].logs[j].date,
                    students[i].logs[j].breakfast,
                    students[i].logs[j].lunch,
                    students[i].logs[j].dinner);
        }
    }
    fclose(fp);
}

void load_meal_log() {
    FILE *fp = fopen(MEAL_FILE, "r");
    if (!fp) return;

    char roll[20];
    MealLog m;

    while (fscanf(fp, "%19s %10s %d %d %d",
                  roll, m.date,
                  &m.breakfast, &m.lunch, &m.dinner) == 5) {

        int idx = find_student_index(roll);
        if (idx != -1 && students[idx].log_count < MAX_LOGS) {
            students[idx].logs[students[idx].log_count++] = m;
        }
    }
    fclose(fp);
}
