#pragma once

#include <stdio.h>
#include <iostream>

typedef int Size;
typedef float* SeriesPtr;
typedef float SeriesType;
typedef float (*SeriesFunctionPtr)(SeriesPtr, Size);

extern SeriesPtr *arrayOfAllocatedSeries;
extern Size numOfSeries;


/*
  * funkcja tworzaca ciag geometryczny
*/
SeriesPtr InitializeGeometricSeries(Size size, float ratio=2.);

/*
  * funkcja tworzaca szereg harmoniczny
*/
SeriesPtr InitializeHarmonicSeries(Size seriesSize);

/*
  * funkcja dodajaca szereg do tablicy szeregow, tak aby mozliwe bylo ich zliczenie
*/
void AddSeries(SeriesPtr series);

/*
  * funkcja zwalniajaca pamiec po utworzonym szeregu
*/
void DeleteSeries();
