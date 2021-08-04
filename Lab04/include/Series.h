#pragma once

#include <stdio.h>
#include <iostream>
#include <cstdlib>

typedef int Size;
typedef float* SeriesPtr;
typedef float SeriesType;
typedef float (*SeriesFunctionPtr)(SeriesPtr, Size);

extern SeriesPtr *arrayOfAllocatedSeries;
extern Size numOfSeries;

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

/*
  * funkcja dodajaca szereg do tablicy szeregow, tak aby mozliwe bylo pozniejsze ich zliczenie
*/
void AddSeries(SeriesPtr series);

/*
  * funkcja zwalniajaca pamiec po utworzonym szeregu
*/
void DeleteSeries();

