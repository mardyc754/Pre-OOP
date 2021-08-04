#include "GradeBook.h"
#include "Grade.h"

int GradeBook::_numOfStudents = 0;

GradeBook::GradeBook():
_gradeBook(new Grade *[1]), 
_descriptions(new const char *[1]) 
{
  _gradeBook[0] = nullptr;
  _descriptions[0] = nullptr;
}

void GradeBook::Insert(Grade *grade, const char *description)
{
  int initialLength = _numOfStudents;
  _numOfStudents += 1;
  Grade **tempGrades = new Grade *[_numOfStudents];
  const char **tempDescriprions = new const char *[_numOfStudents];
  
  for(int i=0; i<initialLength; i++)
  {
    tempGrades[i] = _gradeBook[i];
    tempDescriprions[i] = _descriptions[i];
  }

  tempGrades[initialLength] = grade;
  tempDescriprions[initialLength] = description;
  delete [] _gradeBook;
  delete [] _descriptions;
  _gradeBook = tempGrades;
  _descriptions = tempDescriprions;

}

Grade *GradeBook::GetGrade(int id)
{
  for(int i=0; i<_numOfStudents; i++)
  {
    if(_gradeBook[i]->getGradeId() == id)
    {
      return _gradeBook[i];
    }
  }
  return nullptr;
}

void GradeBook::Print(int id)
{
  std::cout << "[GradeBook]: ";
  for(int i=0; i<_numOfStudents; i++)
  {
    if(id == _gradeBook[i]->getGradeId())
    {
      _gradeBook[i]->Print();
      std::cout << " \"" << _descriptions[i] << "\"\n";
      return;
    }
  }
}

GradeBook::~GradeBook()
{
  for(int i=0; i<_numOfStudents; i++)
  {
    delete _gradeBook[i];
  }

  delete [] _gradeBook;
  _gradeBook = nullptr;
  delete [] _descriptions;
  _descriptions = nullptr;
}
