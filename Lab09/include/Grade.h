#pragma once

#include <iostream>

class Grade{
  public:
  /*
    * konstruktor domyslny klasy Grade
  */
    Grade();
  /*
    * konstruktor jednoargumentowy w ktorym
      wykorzystano delegacje konstruktora domyslnego
  */
    Grade(double);
  /*
  * wypisuje informacje o ocenie na ekran
  */
    void Print();
  /*
    * zwraca id oceny
  */
    int getGradeId();
  /*
    * resetuje licznik na podstawie ktorego 
      przydzielane jest id do oceny
  */
    static void ResetIdCounter();
  private:
    double _value;
    static int _idCounter;
    int _currentId;
};

