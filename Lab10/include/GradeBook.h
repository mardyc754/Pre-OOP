#pragma once

class Grade;

class GradeBook
{
  public:
  /*
    * konstruktor domyslny klasy GradeBook
  */
    GradeBook();
  /*
    * konstruktor kopiujacy klasy GradeBook
      wykorzystujacy delegacje konstruktora domyslnego 
  */
    GradeBook(const GradeBook &obj);
  /*
    * wstawia ocene wraz z jej opisem do dziennika
  */
    void Insert(Grade *grade, const char *description="");
  /*
    * wypisuje zawartosc dziennika na ekran
  */
    void Print();
  /*
    * usuwa zawartosc dziennika
  */
    void Reset();
  /*
    * destruktor klasy GradeBook, usuwa zawartosc dziennika
  */
    ~GradeBook();
  private:
    Grade **_gradeBook;
    const char **_descriptions;
    int _numOfGrades;
};
