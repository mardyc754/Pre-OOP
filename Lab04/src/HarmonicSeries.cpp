#include "HarmonicSeries.h"


SeriesPtr InitializeHarmonicSeries(Size seriesSize)
{
  SeriesPtr hSeries = (SeriesPtr) malloc(seriesSize*sizeof(SeriesType));  
  
  AddSeries(hSeries);
  
  for(int i=0; i<seriesSize; i++)
    hSeries[i] = 1./(i+1);
  
  return hSeries;
}


