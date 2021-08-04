#include "GradeBook.h"
#include "Grade.h"

int GradeBook::_numOfGrades = 0;

void GradeBook::Insert(const Grade* newGrade, const char* gradeType)
{
  int initialLength = _numOfGrades;
  _numOfGrades++;
  const Grade **tempGrades = new const Grade *[_numOfGrades];
  const char **tempDescriptions = new const char *[_numOfGrades];
  
  for(int i=0; i<initialLength; i++){
    tempGrades[i] = _grades[i];
    tempDescriptions[i] = _gradeDescriptions[i];
  }

/*
  mozna tez tak :) 
  nic nie bylo wspomniane w poleceniu, ze nie mozna uzywac std::copy xD
  std::copy(_grades, _grades+initialLength, tempGrades);
  std::copy(_gradeDescriptions, _gradeDescriptions+initialLength, tempDescriptions);
*/ 

  tempGrades[initialLength] = newGrade;
  tempDescriptions[initialLength] = gradeType;

  delete [] _grades;
  delete [] _gradeDescriptions;

  _grades = tempGrades;
  _gradeDescriptions = tempDescriptions;
}

void GradeBook::Print()
{
  std::cout << "[GradeBook]: Set of grades in the book:\n";

  for(int i=0; i<_numOfGrades; i++)
  {
    _grades[i]->Print();
    if(_gradeDescriptions[i][0]!='\0')
    {
        std::cout << "\"" << _gradeDescriptions[i] << "\"";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void GradeBook::AddGrade(double grade)
{
  Grade *newGrade = new Grade(grade);
  GradeBook::Insert(newGrade);
}

void GradeBook::Summary()
{
  double gradesAverage = 0.;
  for(int i=0; i<_numOfGrades; i++)
  {
    gradesAverage += _grades[i]->getGrade();
  }
  gradesAverage /= _numOfGrades;

  std::cout << "[GradeBook]: Summary: Number of grades in the book: " <<
  _numOfGrades << std::endl;
  std::cout << "[GradeBook]: Summary: Average of grades: "  << gradesAverage << std::endl;
}

GradeBook::~GradeBook()
{
    for(int i=0; i<_numOfGrades; i++)
    {
      delete _grades[i];
    }
    delete [] _grades;
    delete [] _gradeDescriptions;

    _numOfGrades = 0;
}

