#include "Grade.h"

int Grade::_idCounter = 0;

Grade::Grade(int value):
_value(value), _gradeId(++_idCounter) {}

int Grade::GetGradeValue() const{ return _value; }

int Grade::GetId() const{ return _gradeId; }

void Grade::Print()
{
    std::cout << "Grade ID=" << _gradeId 
              << " value=" << _value;
}

Grade &Grade::operator++()
{
    ++_value;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Grade &grade)
{
   return out << "Grade ID=" << grade._gradeId 
             << " value=" << grade._value;
}