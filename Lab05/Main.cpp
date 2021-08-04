///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// Zadanie jest w znacznej części oparte o poprzednie zajecia. Polega
// na jego rozbudowaniu (byc moze refaktoryzacji). Punktem startowym moze byc
// wlasny kod z poprzednich zajec!
// Prosze napisac funkcje tworzace i operaujace na ciagach. Nalezy
// utworzyc ciagi geometryczne i harmoniczne zdefiniowane poniżej w kodzie 
// zrodlowym funkcji main(). Oprocz tego nalezy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy i najmniejszy element.
// 
// UWAGA: Prosze zadbac o dobre zarzadzanie pamiecia oraz niepowtarzajacy sie kod 
// (tzn. kod o tej samej funkcjonalności). Prosze uwazac na tzw. cirlular dependencies
// podczas include.
// Alokacja i dealokacja pamieci ma byc zaimplementowana z wykorzystaniem new i delete
//
// Plik Main.cpp, w ostatecznej wersji programu nie powinien być zmodyfikowany!
//
// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod). 
//
// UWAGA: Program zawiera okreslona strukture katalogow dla
// ktorej zdefiniowany jest CMakeLists.txt (gotowy do uzycia!)
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla 
// (np. z katalogu build/)
//
// Ukonczone zadanie nalezy wyslac na UPEL w formie wczesniej pobranego archiwum zip
// calej zawartosci indywidualnego repl'a.
// UWAGA: Prosze usunac domyslny main.cpp z repl'a (z poziomu drzewa struktury plikow)

#ifdef SERIES
  #include "SeriesUI.h"
#endif

int main ()
{
  const Size size = 4;      // rozmiar ciagu geometrycznego
  
  // GEOMETRIC SERIES
  // uwaga: pierwszy element ciagu to 1:
  //        a_0 = 1
  //        a_1 = a_0 * ratio
  //        a_2 = a_1 * ratio
  //        ...
  //        a_size-1 = a_size-2 * ratio

  const SeriesPtr gSeriesPtr = InitializeGeometricSeries (size); // ratio value is defaulted, equal to 2

  // HARMONIC SERIES
  // uwaga: pierwszy element ciagu to 1:
  //        a_1 = 1
  //        a_2 = 1 / 2
  //        a_3 = 1 / 3
  //        ...
  //        a_size = 1 / size; // size > 0

  const SeriesPtr hSeriesPtr = InitializeHarmonicSeries (size);

  // proszę zadbać o odpowiednie formatowanie wyjścia:
  std::cout<<"Geometric series: " << '\n';
  PrintSeries(gSeriesPtr, size);
  std::cout<<"Harmonic series: " << '\n';
  PrintSeries(hSeriesPtr, size); 
  
  SeriesType gSeriesSum = SeriesSum(gSeriesPtr, size);
  SeriesType hSeriesSum = SeriesSum(hSeriesPtr, size);
  
  printf("Sum of geometric series: %.2f\n",gSeriesSum);
  printf("Sum of harmonic series: %.2f\n",hSeriesSum);

  SeriesFunctionPtr seriesFunContainer [] = {  SeriesProduct
                                              ,SeriesSum    
                                              ,SeriesMax    
                                              ,SeriesMin }; 
  
  const int nOperations = sizeof(seriesFunContainer)/sizeof(SeriesFunctionPtr);
  
  printf("** Geometric series operations **\n");
  for (int i = 0; i < nOperations; ++i)
    RunAndPrint (seriesFunContainer[i], gSeriesPtr, size);

  printf("** Harmonic series operations **\n");
  for (const auto& functionPtr : seriesFunContainer)
    RunAndPrint (functionPtr, hSeriesPtr, size);

  DeleteSeries();

  for (int i = 0; i < 66; ++i){
   InitializeGeometricSeries(10, 2.4);
   InitializeHarmonicSeries(10);
  }

  DeleteSeries();
}
/* wynik dzialania programu:
[brachwal@vmate build]$ ./lab04 
Geometric series: 
 1.00 2.00 4.00 8.00
Harmonic series: 
 1.00 0.50 0.33 0.25
Sum of geometric series: 15.00
Sum of harmonic series: 2.08
** Geometric series operations **
Product: 64
Sum: 15
Maximum: 8
Minimum: 1
** Harmonic series operations **
Product: 0.0416667
Sum: 2.08333
Maximum: 1
Minimum: 0.25
Deleting 2 series...
 *** Memory cleanded up ***
Deleting 132 series...
 *** Memory cleanded up ***
*/
