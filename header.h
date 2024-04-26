#ifndef HEADER_H
#define HEADER_H


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
  char name[100];
  struct Subject s[MAX_SUBJECTS];
  int total_credits;
};

int get_student_details(struct Student *student);
float calculate_sgpa(struct Student *student);
void display_grade_card(struct Student *student);

#endif
