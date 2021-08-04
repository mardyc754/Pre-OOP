#include "SeriesStore.h"


SeriesPtr *arrayOfAllocatedSeries = new SeriesPtr[1];
Size numOfSeries = 0;

SeriesPtr InitializeGeometricSeries(Size seriesSize, float ratio)
{
  SeriesPtr geoSeries = new SeriesType[seriesSize];
  AddSeries(geoSeries);

  geoSeries[0] = 1.;
  
  for(int i=1; i<seriesSize; i++)
    geoSeries[i] = geoSeries[i-1]*ratio;

  return geoSeries;
  
}

SeriesPtr InitializeHarmonicSeries(Size seriesSize)
{ 
  SeriesPtr hSeries = new SeriesType[seriesSize];
  AddSeries(hSeries);

  for(int i=0; i<seriesSize; i++)
    hSeries[i] = 1./(i+1);
  
  return hSeries;
}

void AddSeries(SeriesPtr series)
{
  numOfSeries++;
  if(arrayOfAllocatedSeries)
  {
    SeriesPtr *tempSeries = new SeriesPtr[numOfSeries];
    for(int i=0; i<numOfSeries-1; i++)
    {
      tempSeries[i] = arrayOfAllocatedSeries[i];
    }
    delete [] arrayOfAllocatedSeries;
    arrayOfAllocatedSeries = tempSeries;
  }
  else
  {
    arrayOfAllocatedSeries = new SeriesPtr[numOfSeries]; 
  }
  arrayOfAllocatedSeries[numOfSeries-1] = series;
}

void DeleteSeries()
{
  printf("Deleting %d series...\n", numOfSeries);
  for(int i=0; i<numOfSeries; i++)
  {
    delete [] arrayOfAllocatedSeries[i];
    arrayOfAllocatedSeries[i] = nullptr;
  }
  delete [] arrayOfAllocatedSeries;
  arrayOfAllocatedSeries = nullptr;
  numOfSeries = 0;
  printf("*** Memory cleanded up ***\n");
}
