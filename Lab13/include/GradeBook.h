#pragma once

#include <iostream>
#include "Average.h"
#include "Named.h"

class Grade;

class GradeBook: public Named
{
    public:
    /*
        * konstruktor klasy GradeBook z argumentem typu const char*
    */
        GradeBook(const char *);
    /*
        * wstawia ocene do dziennika (obiekt klasy Grade do tablicy _grades)
    */
        void Insert(Grade*);
    /*
        * przeladowany operator [] dla klasy GradeBook
    */
        Grade &operator[](const unsigned i);
    /*
        * destruktor klasy GradeBook
    */
        ~GradeBook();
        friend std::ostream &operator<<(std::ostream &, const GradeBook &);
    private:
        const char *_name;
        Grade **_grades;
        int _numOfGrades;
};

/*
    * przeładowany operator << (strumienia wyjscia) dla klasy GradeBook
*/
std::ostream &operator<<(std::ostream &, const GradeBook &);