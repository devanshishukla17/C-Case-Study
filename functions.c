#include <stdio.h>
#include <string.h>
#include "header.h"


int get_student_details(struct Student *student) {
    printf("Enter student name: ");
    scanf("%99s", student->name);

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

    return total_credit_weighted_points / (total_credits);
}



void display_grade_card(struct Student *student) {
    printf("\nGrade Card for Student: %s\n", student->name);
    printf("Subject\tCredits\tISA1\tISA2\tESA\tInternal\tTotal\tGrade\n");
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
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%c\n", j + 1, student->s[j].credits[j], student->s[j].exams.ISA1[j], student->s[j].exams.ISA2[j], student->s[j].exams.ESA[j], student->s[j].exams.Assignment[j], total_marks, grade_points,grade);
    }
}

