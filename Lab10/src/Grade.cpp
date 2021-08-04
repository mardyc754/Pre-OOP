#include "Grade.h"

int Grade::_idCounter = 0;

Grade::Grade():
_id(++_idCounter), _value(0) {}

Grade::Grade(float grade): Grade()
{
  _value = grade;
}

void Grade::Print()
{
  std::cout << "Grade ID=" << _id 
            << " value=" << _value;
}

int Grade::getGradeId(){ return _id; }

void Grade::ResetIdCounter(){ _idCounter = 0; }

Grade::operator float(){ return _value; }