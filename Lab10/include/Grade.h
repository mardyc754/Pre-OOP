#pragma once

#include <iostream>

class Grade
{
  public:
  /*
    * konstruktor domyslny klasy Grade
  */
    Grade();
  /*
    * konstruktor jedoragumentowy klasy Grade
      wykorzystujacy delegacje kostruktora domyslnego
  */
    Grade(float );
  /*
    * wypisuje informacje o ocenie na ekran
  */
    void Print();
  /*
    * zwraca id oceny
  */
    int getGradeId();
  /*
    * resetuje licznik odpowiedzialny za przydzielanie id
  */
    static void ResetIdCounter();
  /*
    * operator konwersji na float dla obiektow klasy Grade
  */
    operator float();
  private:
    int _id;
    static int _idCounter;
    float _value;
};
