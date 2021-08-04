#pragma once

#include <iostream>

class Grade
{
  public:
  /*
    * konstruktor klasy Grade, 
    na ktorym nie moze byc dokonana niejawna konwersja
  */
    explicit Grade(double);
  /*
    * metoda statyczna, ktora tworzy obiekt klasy Grade
  */
    static Grade NewGrade(double);
  /*
    * przeladowany operator + dla dwoch obiektow klasy Grade
  */
    Grade operator+(const Grade &) const;
  /*
    * przeladowany operator / dla dwoch obiektow klasy Grade
  */
    Grade operator/(const double &) const;
  /*
    * zwraca wartość oceny
  */
    double GetValue();
  /*
    * zwraca ID oceny
  */
    int GetID();
  /*
    * przeladowany operator > dla dwoch obiektow Grade
  */
    bool operator>(const Grade &) const;
  /*
    * przeladowany i zaprzyjazniony operator + dla obiektu Grade i double
  */
    friend Grade operator +(const double&, const Grade&);
  private:
    int _id;
    static int _idCounter;
    double _value;
};

Grade operator +(const double&, const Grade&);