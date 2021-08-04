///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// UWAGA: Program zawiera okreslona strukture katalogow dla ktorej zdefiniowany jest 
// CMakeLists.txt - proszę zastosowac taka strukture w projekcie!
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla (np. z katalogu build/)
//
// Prosze rozszerzyc definicje klas (z poprzednich zajec) o funkcjonalnosc
// wykorzystana w ponizszej funkcji main().
//
// UWAGA!!!
// Tablice powinny dostosowywac swoj rozmiar do liczby przechowywanych
// elementow. Nie wolno używać std::vector, std::list
// 
// UWAGA: Prosze zadbac o dobre zarzadzanie pamiecia oraz niepowtarzajacy sie kod 
// Alokacja i dealokacja pamieci (jesli potrzebna) ma byc zaimplementowana 
// z wykorzystaniem new i delete.
// Prosze zadbac o odpowiednie stosowanie modyfikatora const wszedzie tam
// gdzie jest to zasadne!
//
// Plik Main.cpp, w ostatecznej wersji programu nie powinien być zmodyfikowany!
//
// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod, uwzgledniajac implementacje metod poza definicja klasy)
//
//
// Ukonczone zadanie nalezy wyslac na UPEL w formie wczesniej pobranego archiwum zip
// calej zawartosci indywidualnego repl'a.

#include "Grade.h"
#include "GradeBook.h"

int main() {
  GradeBook gradeBook;
  gradeBook.Insert(new Grade (4.5));
  gradeBook.Insert(new Grade(4),"Unix system test");
  gradeBook.Print();
  std::cout<<"\n";
  GradeBook gradeBookBackup = gradeBook;
  std::cout<<"\n";
  gradeBook.Reset();
  gradeBook.Print();
  gradeBookBackup.Print();
  std::cout<<"\n";
  Grade::ResetIdCounter();
  Grade gradeArray[3] = {Grade(2.0), 3.0, Grade(4.0)};
  gradeArray[1].Print();
  std::cout<<"\n";
  float gradeValue = gradeArray[0];
  std::cout<<"gradeArray[0] = " << gradeValue << std::endl;

  return 0;
}
/**
[brachwal@vmate build]$ ./lab10 
[GradeBook]: Grades in the book:
Grade ID=1 value=4.5
Grade ID=2 value=4 "Unix system test"

Copy constructor called!

[GradeBook]: EMPTY
[GradeBook]: Grades in the book:
Grade ID=1 value=4.5
Grade ID=2 value=4 "Unix system test"

Grade ID=2 value=3
gradeArray[0] = 2
*/
