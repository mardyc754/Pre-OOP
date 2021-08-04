///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal sie,
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// UWAGA: Program zawiera okreslona strukture katalogow dla ktorej zdefiniowany jest 
// CMakeLists.txt - proszę zastosowac taka strukture w projekcie!
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla (np. z katalogu build/)
//
// Prosze rozszerzyc definicje klasy Grade (z poprzednich zajec) o funkcjonalnosc
// wykorzystana w ponizszej funkcji main().
//
//        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// UWAGA: klasa Grade nie moze zawieraz zdefiniowanego operator double()  !!!
//        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

#define SIZE 3
int main() {

  //Grade average;  // make this not compilable!
  Grade average = Grade::NewGrade(0.);
  Grade grades[SIZE] = {Grade(4.0),Grade(4.5), Grade(3.5)};
  
  for(int i=0;i<SIZE;++i)
    average = average + grades[i];
  
  average = average / SIZE;
  std::cout<<"average = " << average.GetValue() << std::endl;
  std::cout<<"     ID = " << average.GetID() << std::endl;

  std::cout<<"  grade = " << (2.0 + grades[0]).GetValue() << std::endl;
  
  if(grades[1]>average)
    std::cout<< "second grade is higher than an average!" << std::endl;

  return 0;
}
/**
[brachwal@vmate build]$ ./lab11 
average = 4
     ID = 8
  grade = 6
second grade is higher than an average!
*/