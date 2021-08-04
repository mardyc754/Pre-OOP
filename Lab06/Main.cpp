///////////////////////////////////////////////////////////////////////////
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku..
//
// Prosze zwrocic uwage czy CMakeLists.txt jest kompletny w zastosowaniu
// do tego zadania.
//
// Prosze zaimplementowac klase MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z dlugosci (longitude) i szerokosci
// (latitude) geograficznej bez oznaczania polkol.

// Prosze napisac klase MapDistance która reprezentuje odleglosc pomiedzy dwoma
// punktami. Odleglosc wzdloz poludnikow lub rownoleznikow nalezy
// obliczyc po prostu odejmujac od siebie wspolrzedne punktow
// poczatkowego i koncowego.

// Implementację i działanie metody poszczególnych klas proszę wywnioskować
// z treści main().

// Metoda MapDistance::Print() wypisuje na ekran informacje o odleglosci
// (przechowaywanej w zmiennych badacych skladowymi tej klasy)

// Metoda MapPoint::Farthest() zwraca punkt (typ MapPoint) bedacy najdalej punktu 
// na rzecz ktorego zostala wywolana metoda. Odleglosc pomiedzy punktami nalezy
// obliczyc jako pierwiastek sumy kwadratow roznic, czyli
// r = sqrt(delta_dlugosc*delta_dlugosc + delta_szerokosc*delta_szerokosc)
// Funkcja obliczajaca pierwiastek nazywa sie: 
// sqrt(double) i znajduje sie w bibliotece "cmath".
// 
// UWAGA: Prosze zadbac o dobre zarzadzanie pamiecia oraz niepowtarzajacy sie kod 
// Alokacja i dealokacja pamieci (jesli potrzebna) ma byc zaimplementowana 
// z wykorzystaniem new i delete
//
// Plik Main.cpp, w ostatecznej wersji programu nie powinien być zmodyfikowany!
//
// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod, uwzgledniajac definiowanie metod poza klasa)
//
// UWAGA: Program zawiera okreslona strukture katalogow dla ktorej zdefiniowany jest 
// CMakeLists.txt - proszę zastosowac taka strukture w projekcie!
// Przypomnienie: cmake i kompilacje wykonujemy spoza zrodla 
// (np. z katalogu build/)
//
// Ukonczone zadanie nalezy wyslac na UPEL w formie wczesniej pobranego archiwum zip
// calej zawartosci indywidualnego repl'a.


#ifdef MAPCALC              // defined by the CMakeLists
    #include "MapPoint.h"
#endif

int main() {

  //========== KRK ========================
  MapPoint krk("KRK",19.938333,50.061389);
  krk.Print();

  //========== NYC ========================
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  MapPoint nyc("NYC");
  nyc.Longitude(nyc_latitude);
  nyc.Latitude(nyc_longitude);
  nyc.Print();

  //========== PORTO ======================
  MapPoint porto;
  porto.SetId("PRT");
  porto.Coordinates(41.162142, -8.621953);
  porto.Print();

  //========== IRKUTSK ====================
  MapPoint irkutsk("IRK");
  irkutsk.Coordinates(52.283333, 104.283333);
  irkutsk.Print();

  //========== DISTANCE ===================
  MapDistance nyc_porto;
  nyc_porto.Print();
  nyc_porto = nyc.Distance(porto);
  nyc_porto.Print();

  //========== FARTHEST ===================
  krk.Farthest(porto, irkutsk).Print();

  return 0;
}

/*
[brachwal@vmate build]$ ./lab06 
Point: KRK (19.9383, 50.0614)
Point: NYC (-74.0059, 40.7127)
Point: PRT (41.1621, -8.62195)
Point: IRK (52.2833, 104.283)
Distance : None (0, 0)
Distance : NYC-PRT (115.168, -49.3347)
Point: IRK (52.2833, 104.283)
*/
