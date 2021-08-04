#include "Grade.h"

int Grade::_idCounter = 0;

Grade::Grade(int value):
_value(value), _gradeId(++_idCounter) {}

void Grade::Print()
{
    std::cout << "Grade ID=" << _gradeId 
              << " value=" << _value;
}

int Grade::GetId(){ return Grade::_gradeId; }

int Grade::GetGradeValue(){ return _value; }

Grade Grade::operator++()
{
    ++_value;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Grade &grade)
{
   return out << "Grade ID=" << grade._gradeId 
             << " value=" << grade._value;
}