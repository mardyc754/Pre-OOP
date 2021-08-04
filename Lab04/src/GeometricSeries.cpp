#include "GeometricSeries.h"


SeriesPtr InitializeGeometricSeries(Size seriesSize, float ratio)
{
  SeriesPtr geoSeries = (SeriesPtr) malloc(seriesSize*sizeof(float));
  
  AddSeries(geoSeries);

  geoSeries[0] = 1;
  
  for(int i=1; i<seriesSize; i++)
    geoSeries[i] = geoSeries[i-1]*ratio;

  return geoSeries;
  
}
