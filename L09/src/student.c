#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void add_grade(Student* student, double grade)
{
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  student->grades[student->num_grades - 1] = grade;
}

double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}

void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));

  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}
