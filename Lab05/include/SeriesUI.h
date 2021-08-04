#pragma once

#include "SeriesStore.h"

/*
  * funkcja wypisujaca szereg na ekran
*/
void PrintSeries(SeriesPtr series, Size seriesSize);

/*
  * funkcja liczaca sume wszystkich wyrazow szeregu
*/
SeriesType SeriesSum(SeriesPtr series, Size seriesSize);

/*
  * funkcja liczaca iloczyn wszystkich wyrazow szeregu
*/
SeriesType SeriesProduct(SeriesPtr series, Size seriesSize);

/*
  * funkcja zwracajaca najwiekszy element szeregu
*/
SeriesType SeriesMax(SeriesPtr series, Size seriesSize);

/*
  * funkcja zwracajaca najmniejszy element szeregu
*/
SeriesType SeriesMin(SeriesPtr series, Size seriesSize);

/*
  * funkcja uruchamiajaca wskazana funkcje na podanym szeregu 
*/
void RunAndPrint (SeriesFunctionPtr funSeries, SeriesPtr series, Size seriesSize);

