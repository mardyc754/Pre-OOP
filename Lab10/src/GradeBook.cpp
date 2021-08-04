#include "GradeBook.h"
#include "Grade.h"
#include <iostream>


GradeBook::GradeBook():
_gradeBook(new Grade *[1]),
_descriptions(new const char *[1]),
_numOfGrades(0)
{
  _gradeBook[0] = nullptr;
  _descriptions[0] = nullptr;
}

GradeBook::GradeBook(const GradeBook &obj): GradeBook()
{
  std::cout << "Copy constructor called!" << std::endl;
  int initialLength = obj._numOfGrades;
  for(int i=0; i<initialLength; i++)
  {
    Insert(obj._gradeBook[i], obj._descriptions[i]);
  }
}

void GradeBook::Insert(Grade *grade, const char *description)
{
  int initialLength = _numOfGrades;
  _numOfGrades = grade->getGradeId();

  Grade **tempGrades = new Grade *[_numOfGrades];
  const char **tempDescriptions = new const char *[_numOfGrades];

  std::copy(_gradeBook, _gradeBook+initialLength, tempGrades);
  std::copy(_descriptions, _descriptions+initialLength, tempDescriptions);

  tempGrades[initialLength] = grade;
  tempDescriptions[initialLength] = description;

  delete [] _gradeBook;
  delete [] _descriptions;

  _gradeBook = tempGrades;
  _descriptions = tempDescriptions;
}

void GradeBook::Print()
{
  std::cout << "[GradeBook]: ";
  if(_numOfGrades == 0)
  {
    std::cout << "EMPTY" << std::endl;
  }
  else 
  {
    std::cout << "Grades in the book:" << std::endl;
    for(int i=0; i<_numOfGrades; i++)
    {
      _gradeBook[i]->Print();
      
      if(_descriptions[i][0] != '\0')
      {
        std::cout << " \"" << _descriptions[i] << "\"";
      }
      std::cout << std::endl;
    }
  }
}

void GradeBook::Reset()
{
  delete [] _gradeBook;
  delete [] _descriptions;
  _gradeBook = nullptr;
  _descriptions = nullptr;
  _numOfGrades = 0;
}

GradeBook::~GradeBook()
{
  for(int i=0; i<_numOfGrades; i++)
  {
    delete _gradeBook[i];
  }
  Reset();
}