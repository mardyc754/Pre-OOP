///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal sie,
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// UWAGA: Program zawiera okreslona strukture katalogow dla ktorej zdefiniowany jest 
// CMakeLists.txt - proszę zastosowac taka strukture w projekcie!
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla (np. z katalogu build/)
//
// Prosze zaimplementowac klasy Grade oraz GradeBook
// (mozna wykorzystac kod z poprzednich zajec).
// Funkcjonalnosc klas nalezy wywnioskowac z ponizszej funkcji main().
// Dodatkowo, prosze zaimplementowac klase Average ktora w biezacej 
// instacji przechowuje informacje o sredniej arytmetycznej wszystkich
// dotychczas przekazanych do niej ocen (Grade) za pomoca operatora ()
// - Average jest tzw. funktorem. 
// Dla klasy GradeBook prosze wprowadzic prosty mechanizm dziedziczenia!
// GradeBook dziedziczy po klasie Named ktora przechowuje jedynie informacje
// na temat nazwy obiektu.
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
// Ukonczone zadanie nalezy wyslac na UPEL w formie wczesniej pobranego archiwum zip
// calej zawartosci indywidualnego repl'a.

#include "Grade.h"
#include "GradeBook.h"

#define SIZE 5
int main() {

  GradeBook gradeBook("PPO-Inheritance-Lab-L1");
  std::cout<< gradeBook << std::endl;

  Average average;
  for(int i=0;i<SIZE;++i){
    gradeBook.Insert(new Grade(i%4 + 1));
    ++gradeBook[i]; // simply add +1 to the Grade value
    std::cout << gradeBook[i];
    std::cout <<", current average: " << average(gradeBook[i]) << "\n";
  }
  std::cout <<"Current average: " << average.GetValue() << "\n";
  average.Reset();
  std::cout <<"Current average: " << average.GetValue() << "\n";
  std::cout<< gradeBook << std::endl;
  return 0;
}
/**
[brachwal@vmate build]$ ./lab13 
[PPO-Inheritance-Lab-L1]: The GradeBook is empty
Grade ID=1 value=2, current average: 2
Grade ID=2 value=3, current average: 2.5
Grade ID=3 value=4, current average: 3
Grade ID=4 value=5, current average: 3.5
Grade ID=5 value=2, current average: 3.2
Current average: 3.2
Current average: 0
[PPO-Inheritance-Lab-L1]: Grade ID=1 value=2
[PPO-Inheritance-Lab-L1]: Grade ID=2 value=3
[PPO-Inheritance-Lab-L1]: Grade ID=3 value=4
[PPO-Inheritance-Lab-L1]: Grade ID=4 value=5
[PPO-Inheritance-Lab-L1]: Grade ID=5 value=22
*/