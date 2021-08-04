#pragma once

class Grade;

class GradeBook{
  public:
  /*
    * konstruktor domyslny klasy GradeBook
  */
    GradeBook();
  /*
    * wstawia ocene oraz jej opis do dziennika
  */
    void Insert(Grade *grade, const char *description="");
  /*
    * zwraca ocene o id podanym jako argument funkcji
  */
    Grade *GetGrade(int);
  /*
    * wypisuje zawartosc dziennika na ekran
  */
    void Print(int);
  /*
    * destruktor klasy GradeBook, 
      zwalnia pamiec po ocenach oraz ich opisach
  */
    ~GradeBook();
  private:
    Grade **_gradeBook;
    const char **_descriptions;
    static int _numOfStudents;
};
