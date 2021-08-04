///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// Prosze napisac funkcje tworzace i operaujace na ciagach. Nalezy
// utworzyc ciag harmoniczny o pierwszym wyrazie 1 i zadanym
// rozmiarze. Oprocz tego nalezy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy i najmniejszy element.
// Uwaga: odpowiednie komentarze/podpowiedzi są również w kodzie źródłowym funkcji main()
//
// Prosze zadbac o dobre zarzadzanie pamiecia.
//
// Plik Main.cpp, w ostatecznej wersji programu nie powinien być zmodyfikowany!
//
// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 
//
// UWAGA: Program zawiera okreslona strukture katalogow dla
// ktorej zdefiniowany jest CMakeLists.txt (gotowy do uzycia!)
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla 
// (np. z katalogu build/)
//
// Ukonczone zadanie nalezy wyslac na UPEL w formie wczesniej pobranego archiwum zip
// calej zawartosci indywidualnego repl'a.
// UWAGA: Prosze usunac domyslny main.cpp z repl'a (z poziomu drzewa struktury plikow)

#include "HarmonicSeries.h"

int main ()
{
  const Size hSize = 5;      // rozmiar ciagu harmonicznego
  
  // uwaga: pierwszy element ciagu to 1:
  //        a_1 = 1
  //        a_2 = 1 / 2
  //        a_3 = 1 / 3
  //        ...
  //        a_size = 1 / size; // size > 0

  const SeriesPtr hSeriesPtr = DefineHarmonicSeriesArray (hSize);

  // prosze zadbac o odpowiednie formatowanie wyjścia:
  printf("Harmonic series:\n");
  PrintSeries(hSeriesPtr, hSize);
  
  printf("Series single operation:\n");
  SeriesType sumVal = SeriesSum(hSeriesPtr, hSize);
  printf("%2.4f\n",sumVal);
  
  
  // PRZYPOMNIENIE: SeriesFunctionPtr jest wskaznikiem na funkcje:
  // - z odpowiednim typem zwracanym
  // - o odpowiednich parametrach formalnych
  // - wskaźnik tego typu definiujemy poprzez typedef ...

  SeriesFunctionPtr hSeriesFunContainer [] = { SeriesProduct  // funkcja zwraca iloczyn wszystkich elementów ciągu
                                              ,SeriesSum      // funkcja zwraca suma wszystkich elementów ciągu
                                              ,SeriesMax      // funkcja zwraca element o wartości maksymalanej 
                                              ,SeriesMin };   // funkcja zwraca element o wartości maksymalanej 
  
  const int nOperations = sizeof(hSeriesFunContainer)/sizeof(SeriesFunctionPtr);
  
  printf("Series set of operations:\n");
  for (int i = 0; i < nOperations; ++i){
    // prosze zadbac o odpowiednie formatowanie wyjscia!
    RunAndPrint (hSeriesFunContainer[i], hSeriesPtr, hSize); 
  }

  DeleteSeries(hSeriesPtr);
}
/* wynik dzialania programu:
[brachwal@vmate build]$ ./lab03 
Harmonic series:
1.00 0.50 0.33 0.25 0.20 
Series single operation:
Sum: 2.2833
Series set of operations:
Product: 0.0083
Sum: 2.2833
Maximum: 1.0000
Minimum: 0.2000
*/
