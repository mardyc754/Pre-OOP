#include "Grade.h"

int Grade::_idCounter = 0;

Grade::Grade(double grade):
_id(++_idCounter), _value(grade) {}

Grade Grade::NewGrade(double grade)
{
  return Grade(grade); 
}

Grade Grade::operator+(const Grade &obj) const
{
  return NewGrade(_value + obj._value);
}

Grade Grade::operator/(const double &num) const
{
  return NewGrade(_value/num);
}

double Grade::GetValue(){ return _value; }

int Grade::GetID(){ return Grade::_id; }

bool Grade::operator>(const Grade &obj) const
{
  return _value > obj._value ? true : false;
}

Grade operator +(const double &left, const Grade &right)
{
  return Grade::NewGrade(left + right._value);
}



