///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// Prosze zwrocic uwage czy CMakeLists.txt jest kompletny w zastosowaniu
// do tego zadania.
// UWAGA: Program zawiera okreslona strukture katalogow dla ktorej zdefiniowany jest 
// CMakeLists.txt - proszę zastosowac taka strukture w projekcie!
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla (np. z katalogu build/)
//
// Prosze zaimplementowac klasy: 
// - Grade, ktora reprezentuje ocene (kazda ocena ma przypisany unikatowy numer ID, 
//   inicjalizowany w momencie tworzenia danej oceny.)
//   W definicji tej klasy ma byc wykorzystany mechanizm konstruktora delegowanego.
// - GradeBook, ktora reprezentuje dziennik ocen (uwzgledniajac nieobligatoryjny 
//   opis tekstowy kazdej oceny)
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
  Grade dummyGrade;
  dummyGrade.Print();
  std::cout<<"\n";
  Grade::ResetIdCounter();
  Grade* firstGrade = new Grade (4.5);
  firstGrade->Print();
  std::cout<<"\n";
  GradeBook gradeBook;
  gradeBook.Insert(firstGrade);
  gradeBook.Insert(new Grade(4),"Unix system test");
  gradeBook.GetGrade(2)->Print(); // get grade ptr by its ID number
  std::cout<<"\n";
  gradeBook.Print(2);             // print grade from grade book by its ID number
  return 0;
}
/**
[brachwal@vmate build]$ ./lab09 
Grade ID=1 value=0
Grade ID=1 value=4.5
Grade ID=2 value=4
[GradeBook]: Grade ID=2 value=4 "Unix system test"
*/
