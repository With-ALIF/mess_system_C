#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "student.h"
#include "meal.h"
#include "billing.h"

 
int admin_login() {

    char inputUser[20], inputPass[20];
    char fileUser[20], filePass[20];
    FILE *fp;
    int ch;

    fp = fopen("auth.txt", "r");
    if (fp == NULL) {
        printf("\nError: auth.txt file not found!\n");
        return 0;
    }

    fscanf(fp, "%19s %19s", fileUser, filePass);
    fclose(fp);

    printf("\n========================================\n");
    printf("              ADMIN LOGIN              \n");
    printf("========================================\n");
    printf("Username: ");
    scanf("%19s", inputUser);
    printf("Password: ");
    scanf("%19s", inputPass);

    if (strcmp(inputUser, fileUser) != 0 ||
        strcmp(inputPass, filePass) != 0) {
        printf("\nLogin failed! Invalid credentials.\n");
        return 0;
    }

    printf("\nLogin successful!\n\n");

    while (1) {
        printf("\n----------------------------------------\n");
        printf("               ADMIN MENU               \n");
        printf("----------------------------------------\n");
        printf("  1. Register Student\n");
        printf("  2. View All Students\n");
        printf("  3. Generate Billing\n");
        printf("  4. Logout\n");
        printf("----------------------------------------\n");
        printf("Enter choice: ");

        scanf("%d", &ch);

        if (ch == 1) {
            register_student();
        }
        else if (ch == 2) {
            view_all_students();
        }
        else if (ch == 3) {
            generate_billing_for_all();
        }
        else if (ch == 4) {
            printf("\nLogged out from admin panel.\n");
            return 0;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}

 
int student_login(char roll_no[]) {

    int ch;

    if (find_student_index(roll_no) == -1) {
        printf("\nStudent not registered!\n");
        return 0;
    }

    while (1) {
        printf("\n----------------------------------------\n");
        printf("              STUDENT MENU              \n");
        printf("----------------------------------------\n");
        printf("  1. Book Meal\n");
        printf("  2. Cancel Meal\n");
        printf("  3. Meal Status\n");
        printf("  4. Monthly Report\n");
        printf("  5. Logout\n");
        printf("----------------------------------------\n");
        printf("Enter choice: ");

        scanf("%d", &ch);

        if (ch == 1) {
            book_meal_ui(roll_no);
        }
        else if (ch == 2) {
            cancel_meal_ui(roll_no);
        }
        else if (ch == 3) {
            overall_meal_report(roll_no);
        }
        else if (ch == 4) {
            monthly_report(roll_no);
        }
        else if (ch == 5) {
            printf("\nLogged out from student panel.\n");
            return 0;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}
