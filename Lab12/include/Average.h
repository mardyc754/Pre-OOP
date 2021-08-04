#pragma once

class Grade;

class Average
{
    public:
    /* 
        * konstruktor domyslny klasy Average
    */
        Average();
    /* 
        * przeladowany operator () dla obiektow klasy Average
    */
        double operator()(Grade &);
    /* 
        * zwraca wartosc sredniej
    */
        double GetValue();
    /* 
        * resetuje wartosc sredniej oraz liczbe ocen w niej uwzglednionej
    */
        void Reset();
    private:
        static int _sumOfGrades;
        double _value;
};
