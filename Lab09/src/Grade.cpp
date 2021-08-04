#include "Grade.h"

int Grade::_idCounter = 0;

Grade::Grade(): 
_value(0), 
_currentId(++_idCounter) {}

Grade::Grade(double grade): Grade()
{
  _value = grade;
}

void Grade::Print()
{
  std::cout << "Grade ID=" << _currentId 
            << " value=" << _value;
}

int Grade::getGradeId(){ return _currentId; }

void Grade::ResetIdCounter(){ _idCounter = 0; }
