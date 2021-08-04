#pragma once

class Grade;

class Average
{
    public:
    /*
        * konstruktor klasy Average
    */
        Average();
    /* 
        * przeladowany operator () dla klasy Average zwracajacy
            zmienna typu double
    */
        double operator()(const Grade &);
    /*
        * zwraca wartosc sredniej
    */
        double GetValue();
    /*
        * resetuje wartosc sredniej i sumy ocen
    */
        void Reset();
    private:
        double _sumOfGrades;
        double _average;
};
