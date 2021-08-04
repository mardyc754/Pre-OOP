///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// Prosze zwrocic uwage czy CMakeLists.txt jest kompletny w zastosowaniu
// do tego zadania.
//
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac klasy: 
// - Grade, ktora reprezentuje ocene (uwzgledniajac nieobligatoryjny jej opis tekstowy)
// - GradeBook, ktora reprezentuje dziennik ocen. 
// Kazda ocena ma przypisany unikatowy numer ID, inicjalizowany w momencie tworzenia
// danej oceny.

// UWAGA!!!
// Tablice powinny dostosowywac swoj rozmiar do liczby przechowywanych
// elementow. Nie wolno używać std::vector

// UWAGA!!!
// Nie wolno uzywac jawnego rzutowania. Uzycie jawnego rzutownia
// bedzie traktowane jak blad kompilacji, czyli 0 punktow.

// UWAGA!!!
// W tym zadaniu nie wolno uzywac mutable. Uzycie tego slowa
// kluczowego oznacza 0 punktow za zadanie.

// UWAGA!!!
// Uzycie const_cast z obiektem const powoduje niezdefiniowane
// dzialanie programu, dlatego w takiej sytuacji nie wolno uzyc
// const_cast.
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
// UWAGA: Program zawiera okreslona strukture katalogow dla ktorej zdefiniowany jest 
// CMakeLists.txt - proszę zastosowac taka strukture w projekcie!
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla 
// (np. z katalogu build/)
//
// Ukonczone zadanie nalezy wyslac na UPEL w formie wczesniej pobranego archiwum zip
// calej zawartosci indywidualnego repl'a.

#include "Grade.h"
#include "GradeBook.h"

int main() {

  Grade* firstGrade = new Grade (4.5);
  firstGrade->Print();

  std::cout<<"\n";
  GradeBook goodStudents;
  goodStudents.Insert(firstGrade);
  goodStudents.Print();

  goodStudents.Insert(new Grade(4),"Unix system test");

  goodStudents.AddGrade(3.5);

  const Grade* secondGrade = new const Grade (5);
  goodStudents.Insert(secondGrade,"Final exam");
  goodStudents.Print();
  goodStudents.Summary();

  return 0;
}
/**
[brachwal@vmate build]$ ./lab08 
Grade ID=1 value=4.5
[GradeBook]: Set of grades in the book:
Grade ID=1 value=4.5

[GradeBook]: Set of grades in the book:
Grade ID=1 value=4.5
Grade ID=2 value=4 "Unix system test"
Grade ID=3 value=3.5
Grade ID=4 value=5 "Final exam"

[GradeBook]: Summary: Number of grades in the book: 4
[GradeBook]: Summary: Average of grades: 4.25

*/
