#include <stdio.h>
#include <string.h>
#include "header.h"

const char *ascii_art = 
    ".  . .-. .-. .-.   .-. . . |   .-. . . .-. . . .-. .-.   . . .-. . . .   .-. . . .-. \n"
    "|\\/| |-| |  )|-    |(   |      |-| |<  `-. |-| |-|  |    |\\| |-| | | |   |-| |\\|  |  \n"
    "'  ` ` ' `-' `-'   `-'  `  |   ` ' ' ` `-' ' ` ` '  '    ' ` ` ' `.' `-' ` ' ' ` `-' \n\n";

const char *ascii_art2 = 
    "  .--.            .--.\n"
    " ( (`\\\\.\"--``--\".//`) )\n"
    "  '-.   __   __    .-'\n"
    "   /   /__\\ /__\\   \\\n"
    "  |    \\ 0/ \\ 0/    |\n"
    "  \\     `/   \\`     /\n"
    "   `-.  /-\"\"\"-\\  .-`\n"
    "     /  '.___.'  \\\n"
    "     \\     I     /\n"
    "      `;--'`'--;`\n"
    "        '.___.'\n\n";

const char *ascii_art3 = 
    ".-. . . .-. . . . .   . . .-. . .   .-. .-. .-.   . . .-. .-. . . .-.   .-. . . .-.   .-. .-. .-. .   .-. .-. .-. .-. .-. .-. . .   \n"
    " |  |-| |-| |\\| |<     |  | | | |   |-  | | |(    | | `-.  |  |\\| |..    |  |-| |-    |-| |-' |-' |    |  |   |-|  |   |  | | |\\|   \n"
    " '  ' ` ` ' ' ` ' `    `  `-' `-'   '   `-' ' '   `-' `-' `-' ' ` `-'    '  ' ` `-'   ` ' '   '   `-' `-' `-' ` '  '  `-' `-' ' ` . \n\n";


int main() {
    int option;
    do {
        printf("Enter 1 to add a new student\nEnter 2 to read all student results\nEnter 3 to search for a student's result\nAny other number to exit\nPlease enter your input: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                struct Student student;
                int a = get_student_details(&student);
                if (a != 1) {
                    float sgpa = calculate_sgpa(&student);
                    display_grade_card(&student);
                    if (sgpa == -1.0f) {
                        printf("Error: No credits entered.\n");
                    } else {
                        printf("SGPA: %.2f\n", sgpa);
                    }
                }
                break;
                // new comment
            }
            case 2:
                print_data();
                break;
            case 3: {
                char srn[14];
                printf("Enter SRN of the student: ");
                scanf("%13s", srn);
                print_student_result(srn);
                break;
            }
            default:
                printf("Thank you for using the application.\n");
                printf("%s",ascii_art3);
                printf("%s",ascii_art);
                printf("%s",ascii_art2);
                return 0;
        }
    } while (1);
    return 0;
}