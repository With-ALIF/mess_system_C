#include <stdio.h>
#include "auth.h"
#include "student.h"
#include "meal.h"
#include "file_handler.h"

int main() {

    int choice;
    char roll[20];

    load_students();
    load_meal_log();

    while (1) {
        printf("\n========================================\n");
        printf("        STUDENT HALL MESS SYSTEM        \n");
        printf("========================================\n");
        printf("  1. Admin Login\n");
        printf("  2. Student Login\n");
        printf("  3. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\nInvalid input! Try again.\n");
            continue;
        }

        if (choice == 1) {
            admin_login();
        }
        else if (choice == 2) {
            printf("Enter Roll Number: ");
            scanf(" %19s", roll);
            student_login(roll);
        }
        else if (choice == 3) {
            save_students();
            save_meal_log();
            printf("\n========================================\n");
            printf("  Thank you for using Mess System\n");
            printf("  Data saved successfully\n");
            printf("  Goodbye!\n");
            printf("========================================\n");
            break;
        }
        else {
            printf("\nInvalid choice! Please select 1–3.\n");
        }
    }

    return 0;
}
