#include "HarmonicSeries.h"

SeriesPtr DefineHarmonicSeriesArray(Size seriesSize)
{
  SeriesPtr series = (SeriesPtr) malloc(seriesSize*sizeof(SeriesType));
  
  for(int i=0; i<seriesSize; i++)
  {
    series[i] = 1./(i+1);
  }
  return series;
}

void PrintSeries(SeriesPtr series, Size seriesSize)
{
  for(int i=0; i<seriesSize; i++)
  {
    printf("%.2f ", series[i]);
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
  printf("Sum: ");
  return sum;
}

SeriesType SeriesProduct(SeriesPtr series, Size seriesSize)
{
  SeriesType product = 1;
  for(int i=0; i<seriesSize; i++)
  {
    product *= series[i];
  }
  printf("Product: ");
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
  printf("Maximum: ");
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
  printf("Minimum: ");
  return *minEl;
}

void RunAndPrint (SeriesFunctionPtr funSeries, SeriesPtr series, Size seriesSize)
{
  printf("%.4f \n", funSeries(series, seriesSize));
}

void DeleteSeries(SeriesPtr series)
{
  free(series);
  series = nullptr; 
}