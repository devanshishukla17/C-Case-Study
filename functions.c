#include <stdio.h>
#include <string.h>
#include "header.h"
#include<stdlib.h>


int get_student_details(struct Student *student) {

    printf("Enter the SRN of the student:");
    scanf("%13s",student->SRN);
    
    printf("Enter student name: ");
    scanf("%s", student->name);
    

    for (int j = 0; j < MAX_SUBJECTS; j++) {
        printf("Enter marks for Subject %d - ISA1: ", j + 1);
        scanf("%d", &(student->s[j].exams.ISA1[j]));
        if(student->s[j].exams.ISA1[j]<=20)
        ;
        else{ 
            printf("Please enter correct details.");
            return 1;}

        printf("Enter marks for Subject %d - ISA2: ", j + 1);
        scanf("%d", &(student->s[j].exams.ISA2[j]));
        if(student->s[j].exams.ISA2[j]<=20)
        ;
        else{ 
            printf("Please enter correct details.");
            return 1;}

        printf("Enter marks for Subject %d - ESA: ", j + 1);
        scanf("%d", &(student->s[j].exams.ESA[j]));
        if(student->s[j].exams.ESA[j]<=50)
        ;
        else{ 
            printf("Please enter correct details.");
            return 1;}

        printf("Enter internal marks for Subject %d: ", j + 1);
        scanf("%d", &(student->s[j].exams.Assignment[j]));
        if(student->s[j].exams.Assignment[j]<=10)
        ;
        else{ 
            printf("Please enter correct details.");
            return 1;}

        printf("Enter credits for Subject %d: ", j + 1);
        scanf("%d", &(student->s[j].credits[j]));
        if(student->s[j].credits[j]<=5)
        ;
        else{ 
            printf("Please enter correct details.");
            return 1;}
            
    }
    
}



float calculate_sgpa(struct Student *student) {
    float total_credit_weighted_points = 0.0f;
    float total_credits = 0.0f;

        float total_points = 0.0f;
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            
            int total_marks = student->s[j].exams.ISA1[j] + student->s[j].exams.ISA2[j] + student->s[j].exams.ESA[j] + student->s[j].exams.Assignment[j];
            
            
            int grade_points = 0;
            if (total_marks >= 91 && total_marks <= 100) {
                grade_points = 10;
            } else if (total_marks >= 81 && total_marks <= 90) {
                grade_points = 9;
            } else if (total_marks >= 71 && total_marks <= 80) {
                grade_points = 8;
            } else if (total_marks >= 61 && total_marks <= 70) {
                grade_points = 7;
            } else if (total_marks >= 51 && total_marks <= 60) {
                grade_points = 6;
            } else if (total_marks >= 41 && total_marks <= 50) {
                grade_points = 5;
            } else {
                grade_points = 0;
            }

            
            total_points += grade_points * student->s[j].credits[j];
        }

        
        total_credit_weighted_points += total_points;


        for (int j = 0; j < MAX_SUBJECTS; j++) {
            total_credits += student->s[j].credits[j];
        }

    
    if (total_credits == 0.0f) {
        return -1.0f; // Indicate error
    }
        student->sgpa=total_credit_weighted_points / (total_credits);
    return student->sgpa;
}



void display_grade_card(struct Student *student) {
    // writing in file:
    FILE *file;
    file=fopen("details.csv","a");
    
    printf("\nGrade Card for Student: %s\t%s\n", student->name,student->SRN);
    fprintf(file,"%s,%s,",
                student->SRN,
                student->name);
    printf("Subject\tCredits\tISA1\tISA2\tESA\tInternal\tTotal\tGrade Points\tGrade\n");
    printf("----------------------------------------------------------------------------------------------\n");
    for (int j = 0; j < MAX_SUBJECTS; j++) {
        int total_marks = student->s[j].exams.ISA1[j] + student->s[j].exams.Assignment[j] + student->s[j].exams.ISA2[j] + student->s[j].exams.ESA[j];
        int grade_points = 0;
        char grade;
        if (total_marks >= 91 && total_marks <= 100) {
            grade_points = 10;
            grade='S';
        } else if (total_marks >= 81 && total_marks <= 90) {
            grade_points = 9;
            grade='A';
        } else if (total_marks >= 71 && total_marks <= 80) {
            grade_points = 8;
            grade='B';
        } else if (total_marks >= 61 && total_marks <= 70) {
            grade_points = 7;
            grade='C';
        } else if (total_marks >= 51 && total_marks <= 60) {
            grade_points = 6;
            grade='D';
        } else if (total_marks >= 41 && total_marks <= 50) {
            grade_points = 5;
            grade='E';
        } else {
            grade_points = 0;
            grade='F';
        }
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%c\n\n\n", j + 1, student->s[j].credits[j], student->s[j].exams.ISA1[j], student->s[j].exams.ISA2[j], student->s[j].exams.ESA[j], student->s[j].exams.Assignment[j], total_marks, grade_points,grade);
    fprintf(file,
                "%d,%d,%d,%d,%d,%d,%d,%d,%c,",
                j + 1, student->s[j].credits[j], student->s[j].exams.ISA1[j], student->s[j].exams.ISA2[j], student->s[j].exams.ESA[j], student->s[j].exams.Assignment[j], total_marks, grade_points,grade);
    }
    fprintf(file,"%f,\n",student->sgpa);
    fclose(file);
    
}



void print_data(void) {

    int total_marks[MAX_SUBJECTS];
    int grade_points[MAX_SUBJECTS];
    char grade[MAX_SUBJECTS];
    FILE *file = fopen("details.csv", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    struct Student student[100];
    int records = 0;
    int sub_no[MAX_SUBJECTS];
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        // Read the SRN and name
        char *token = strtok(line, ",");
        if (token == NULL) continue;
        strncpy(student[records].SRN, token, sizeof(student[records].SRN));

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(student[records].name, token, sizeof(student[records].name));

        // Read subjects data
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            token = strtok(NULL, ",");
            if (token == NULL) break;
            sub_no[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            student[records].s[j].credits[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            student[records].s[j].exams.ISA1[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            student[records].s[j].exams.ISA2[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            student[records].s[j].exams.ESA[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            student[records].s[j].exams.Assignment[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            total_marks[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            grade_points[j] = atoi(token);

            token = strtok(NULL, ",");
            if (token == NULL) break;
            grade[j] = token[0];
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            student[records].sgpa = atof(token);
        }

        // Printing student data
        printf("\nGrade Card for Student: %s\t%s\n", student[records].name, student[records].SRN);
        printf("Subject\tCredits\tISA1\tISA2\tESA\tInternal\tTotal\tGrade Points\tGrade\n");
        printf("----------------------------------------------------------------------------------------------\n");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            total_marks[j] = student[records].s[j].exams.ISA1[j] + student[records].s[j].exams.Assignment[j] + student[records].s[j].exams.ISA2[j] + student[records].s[j].exams.ESA[j];
            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%c\n",
                    sub_no[j],
                    student[records].s[j].credits[j],
                    student[records].s[j].exams.ISA1[j],
                    student[records].s[j].exams.ISA2[j],
                    student[records].s[j].exams.ESA[j],
                    student[records].s[j].exams.Assignment[j],
                    total_marks[j],
                    grade_points[j],
                    grade[j]);
        }
        printf("%.2f\n", student[records].sgpa);
        records++;
    }

    fclose(file);
    printf("%d record(s) read\n\n\n", records);
}


void print_student_result(const char *srn) {
    FILE *file = fopen("details.csv", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    struct Student student[MAX_STUDENTS];
    int records = 0;
    char line[1024];
    int total_marks[MAX_SUBJECTS];
    int grade_points[MAX_SUBJECTS];
    char grade[MAX_SUBJECTS];
    int sub_no[MAX_SUBJECTS];


    
    while (fgets(line, sizeof(line), file)) {
        // Split the line into tokens using strtok
        char *token = strtok(line, ",");
        if (token != NULL && strcmp(token, srn) == 0) // Found the student with the matching SRN
        {
            strncpy(student[records].SRN, token, sizeof(student[records].SRN));

            token = strtok(NULL, ",");
            if (token != NULL) {
                strncpy(student[records].name, token, sizeof(student[records].name));
            }

            // Read subjects data
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                for (int k = 0; k < 9; k++) {
                    token = strtok(NULL, ",");
                    if (token == NULL) break;
                    if(k==0)sub_no[j] = atoi(token);
                    else if (k == 1) student[records].s[j].credits[j] = atoi(token);
                    else if (k == 2) student[records].s[j].exams.ISA1[j] = atoi(token);
                    else if (k == 3) student[records].s[j].exams.ISA2[j] = atoi(token);
                    else if (k == 4) student[records].s[j].exams.ESA[j] = atoi(token);
                    else if (k == 5) student[records].s[j].exams.Assignment[j] = atoi(token);
                    else if (k == 6) total_marks[j]= atoi(token); // total marks
                    else if (k == 7) grade_points[j]= atoi(token); // grade points
                    else if (k == 8) grade[j]= token[0]; // grade
                }
            }

            token = strtok(NULL, ",");
            if (token != NULL) {
                student[records].sgpa = atof(token);
            }

            // Printing student data
            printf("\nGrade Card for Student: %s\t%s\n", student[records].name, student[records].SRN);
            printf("Subject\tCredits\tISA1\tISA2\tESA\tAssignment\tTotal\tGrade Points\tGrade\n");
            printf("-----------------------------------------------------------------------------------\n");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%c\n",
                        sub_no[j],
                        student[records].s[j].credits[j],
                        student[records].s[j].exams.ISA1[j],
                        student[records].s[j].exams.ISA2[j],
                        student[records].s[j].exams.ESA[j],
                        student[records].s[j].exams.Assignment[j],
                        total_marks[j],
                        grade_points[j],
                        grade[j]);
            }
            printf("\nSGPA: %.2f\n\n\n", student[records].sgpa);

            records++;
            break; // Exit the loop once the student is found
        }
    }

    fclose(file);

    if (records == 0) {
        printf("Student with SRN %s not found.\n", srn);
    }
}
