#ifndef HEADER_H
#define HEADER_H

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5




struct Exams{
  int ISA1[MAX_SUBJECTS];
  int ISA2[MAX_SUBJECTS];
  int ESA[MAX_SUBJECTS];
  int Assignment[MAX_SUBJECTS];
};

struct Subject{
  int credits[MAX_SUBJECTS];
  struct Exams exams;
  int grade_points;
};


struct Student {
  char SRN[14];
  char name[100];
  struct Subject s[MAX_SUBJECTS];
  int total_credits;
  float sgpa;
};

int get_student_details(struct Student *student);
float calculate_sgpa(struct Student *student);
void display_grade_card(struct Student *student);
void print_data(void);
void print_student_result(const char *srn);

#endif
