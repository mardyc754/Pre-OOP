#include "Series.h"

SeriesPtr *arrayOfAllocatedSeries = (SeriesPtr*) malloc(sizeof(SeriesPtr));
Size numOfSeries = 0;

void PrintSeries(SeriesPtr series, Size seriesSize)
{
  for(int i=0; i<seriesSize; i++)
  {
    printf(" %.2f", series[i]);
  }
  printf("\n");
}

SeriesType SeriesSum(SeriesPtr series, Size seriesSize)
{
  SeriesType sum = 0;
  for(int i=0; i<seriesSize; i++)
  {
    sum += series[i];
  }
  return sum;
}

SeriesType SeriesProduct(SeriesPtr series, Size seriesSize)
{
  SeriesType product = 1;
  for(int i=0; i<seriesSize; i++)
  {
    product *= series[i];
  }
  return product;
}

SeriesType SeriesMax(SeriesPtr series, Size seriesSize)
{
  SeriesPtr maxEl = series;
  for(int i=0; i<seriesSize; i++)
  {
    if(*maxEl<series[i])
    {
      maxEl = series + i;
    }
  }
  return *maxEl;
}

SeriesType SeriesMin(SeriesPtr series, Size seriesSize)
{
  SeriesPtr minEl = series;
  for(int i=0; i<seriesSize; i++)
  {
    if(*minEl>series[i])
    {
      minEl = series + i;
    }
  }
  return *minEl;
}

void RunAndPrint (SeriesFunctionPtr funSeries, SeriesPtr series, Size seriesSize)
{
  if(funSeries==SeriesSum)
    std::cout << "Sum: ";
  
  if(funSeries==SeriesProduct)
    std::cout << "Product: ";

  if(funSeries==SeriesMax)
    std::cout << "Maximum: ";

  if(funSeries==SeriesMin)
    std::cout << "Minimum: ";

  std::cout << funSeries(series, seriesSize) << std::endl;
}

void AddSeries(SeriesPtr series)
{
  numOfSeries++;
  if(arrayOfAllocatedSeries)
  {
    arrayOfAllocatedSeries = (SeriesPtr*) realloc(arrayOfAllocatedSeries, numOfSeries*sizeof(SeriesPtr));
  }
  else
  {
    arrayOfAllocatedSeries = (SeriesPtr*) malloc(numOfSeries*sizeof(SeriesPtr));
  }
  arrayOfAllocatedSeries[numOfSeries-1] = series;
}

void DeleteSeries(){
  printf("Deleting %d series...\n", numOfSeries);
  for(int i=0; i<numOfSeries; i++){
    free(arrayOfAllocatedSeries[i]);
    arrayOfAllocatedSeries[i] = nullptr;
  }
  numOfSeries = 0;
  free(arrayOfAllocatedSeries);
  arrayOfAllocatedSeries = nullptr;

  printf("*** Memory cleanded up ***\n");
}
