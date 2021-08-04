#include "Grade.h"
#include <iostream>

int Grade::_gradeIdCounter = 0;

Grade::Grade(double grade):
  _grade(grade) 
{  
  ++_gradeIdCounter;
    _gradeId = _gradeIdCounter;
}

int Grade::getGradeId() const { return _gradeId; }

double Grade::getGrade() const { return _grade; }

void Grade::Print() const 
{
  std::cout << "Grade ID=" << _gradeId << " value=" <<
  _grade << " ";

}


