#pragma once

#include <iostream>
#include "Average.h"

class Grade;

class GradeBook
{
    public:
    /* 
        * konstruktor klasy GradeBook przypisujacy nazwe dziennikowi
    */
        GradeBook(const char *);
    /* 
        * przeladowany operator [] dla obiektow klasy GradeBook
    */
        Grade &operator[](unsigned i) const;
    /* 
        * wstawia ocene do dziennika
    */
        void Insert(Grade*);
    /* 
        * destruktor klasy Average
    */
        ~GradeBook();
    /* 
        * zaprzyjazniony przeladowany operator strumienia wyjscia dla obiektow klasy GradeBook
    */
        friend std::ostream &operator<<(std::ostream &, const GradeBook &);
    private:
        Grade **_grades;
        const char *_name;
        static int _numOfGrades;
};

std::ostream &operator<<(std::ostream &, const GradeBook &);