#include <stdio.h>
#include "billing.h"
#include "student.h"

void generate_billing_for_all() {
    for (int i = 0; i < student_count; i++) {
        double total = 0;
        for (int j = 0; j < students[i].log_count; j++) {
            if (students[i].logs[j].breakfast) total+=20;
            if (students[i].logs[j].lunch) total+=30;
            if (students[i].logs[j].dinner) total+=30;
        }
        students[i].balance -= total;
        printf("%s %.2lf\n", students[i].roll_no, total);
    }
}
