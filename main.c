#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    int num_students = get_num_students();

    if (num_students == -1) {
        return 1; // Exit with error
    }

    char student_names[MAX_STUDENTS][100];
    int isa1[MAX_STUDENTS][MAX_SUBJECTS], isa2[MAX_STUDENTS][MAX_SUBJECTS];
    int esa[MAX_STUDENTS][MAX_SUBJECTS], internal[MAX_STUDENTS][MAX_SUBJECTS];
    int credits[MAX_STUDENTS][MAX_SUBJECTS];

    get_student_details(student_names, isa1, isa2, esa, internal, credits, num_students);

    float sgpa = calculate_sgpa(isa1, isa2, esa, internal, credits, num_students);

    if (sgpa == -1.0f) {
        printf("Error: No credits entered.\n");
    } else {
        printf("SGPA: %.2f\n", sgpa);
    }

    return 0;
}
