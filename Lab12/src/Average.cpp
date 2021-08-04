#include "Average.h"
#include "Grade.h"


int Average::_sumOfGrades = 0;

Average::Average(){ _value = 0; }

double Average::operator()(Grade &grade)
{
    _sumOfGrades += grade.GetGradeValue();
    double numOfGrades = grade.GetId();
    _value = _sumOfGrades / numOfGrades;
    return _value;
}

double Average::GetValue(){ return _value; }

void Average::Reset()
{
    _sumOfGrades = 0;
    _value = 0;
}

