#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {


    struct Student student;

    int a= get_student_details(&student);

if (a=1)
    return 0;
    
    float sgpa = calculate_sgpa(&student);

    display_grade_card(&student);

    if (sgpa == -1.0f) {
        printf("Error: No credits entered.\n");
    } else {
        printf("SGPA: %.2f\n", sgpa);
    }

    return 0;
}
