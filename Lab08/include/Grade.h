#ifndef GRADE_H
#define GRADE_H


class Grade{
  public:
    /*
      * konstruktor klasy Grade, tworzy ocene o podanej wadze
    */
    Grade(double);
    /*
      * oblicza id oceny
    */
    int getGradeId() const;
    /*
      * zwraca ocene
    */
    double getGrade() const;
    /*
      * wypisuje ocene
    */
    void Print() const;
    private:
      double _grade;
      static int _gradeIdCounter;
      int _gradeId;
};


#endif
