#pragma once

#include <iostream>

class Grade
{
    public:
    /*
        * konstruktor klasy Grade z argumentem typu int
    */
        Grade(int);
    /*
        * zwraca wartość oceny
    */
        int GetGradeValue() const;
    /*
        * zwraca id oceny
    */
        int GetId() const;
    /*
        * funkcja pomocnicza wypisująca parametry oceny
    */
        void Print();
    /*
        * przeładowany operator preinkrementacji dla klasy Grade
    */
        Grade &operator++();
        friend std::ostream &operator<<(std::ostream &, const Grade &);
    private:
        int _value;
        static int _idCounter;
        int _gradeId;
};

/*
    * przeładowany operator << dla obiektu klasy Grade
*/
std::ostream &operator<<(std::ostream &, const Grade &);
