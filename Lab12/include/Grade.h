#pragma once

#include <iostream>

class Grade
{
    public:
    /* 
        * konstruktor klasy Grade 
          z wartoscia oceny jako argumentem
    */
        Grade(int);
    /* 
        * wypisuje informacje o ocenie na ekran
    */
        void Print();
    /* 
        * zwraca ID oceny
    */
        int GetId();
    /* 
        * zwraca wartosc oceny
    */
        int GetGradeValue();
    /* 
        * przeladowany operator preinkrementacji 
          dla obiektow klasy Grade
    */
        Grade operator++();
    /* 
        * przeladowany operator strumienia wyjscia 
          dla obiektow klasy Grade
    */
        friend std::ostream &operator<<(std::ostream &, const Grade &);
    private:
        int _value;
        static int _idCounter;
        int _gradeId;
};

std::ostream &operator<<(std::ostream &, const Grade &);
