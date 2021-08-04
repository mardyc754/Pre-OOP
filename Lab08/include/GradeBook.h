#ifndef GRADE_BOOK_H
#define GRADE_BOOK_H
#include <iostream>

class Grade;

class GradeBook
{
  public:
  /*
    * wstawia ocene do dziennika
  */
    void Insert(const Grade *, const char * gradeType = "\0");
  /*
    * wypisuje oceny
  */
    void Print();
  /*
    * dodaje ocene do dziennika
  */
    void AddGrade(double);
  /*
    * wypisuje liste ocen oraz ich srednia
  */
    void Summary();
  /*
    * destruktor klasy GradeBook, zwalnia pamiec po dzienniku i opisach ocen
  */
    ~GradeBook();
  private:
    const Grade **_grades = new const Grade* [1];
    const char **_gradeDescriptions = new const char* [1];
    static int _numOfGrades;
};

#endif
