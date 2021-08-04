#include "Average.h"
#include "Grade.h"

Average::Average(): _sumOfGrades(0), _average(0) {}


double Average::operator()(const Grade &grade)
{
    _sumOfGrades += grade.GetGradeValue();
    int numOfGrades = grade.GetId();
    _average = _sumOfGrades / numOfGrades;
    return  _average;
}

double Average::GetValue(){ return  _average; }

void Average::Reset()
{
    _sumOfGrades = 0;
    _average = 0;
}


