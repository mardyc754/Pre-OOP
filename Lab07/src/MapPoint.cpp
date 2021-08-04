#include "MapPoint.h"

void MapPoint::Print()
{
  std::cout << "Point: " << _label << " (" << _longitude << ", " << _latitude << ")" << std::endl;
}

void MapPoint::Label(std::string label){ _label = label; }

void MapPoint::Longitude(double longitude){ _longitude = longitude; }

void MapPoint::Latitude(double latitude){ _latitude = latitude; }

void MapPoint::Coordinates(double longitude, double latitude)
{
  _longitude = longitude;
  _latitude = latitude;
}

double MapPoint::GetLatitude(){ return _latitude; }

double MapPoint::GetLongitude(){ return _longitude; }

std::string MapPoint::GetLabel(){ return _label; }

MapDistance MapPoint::Distance(MapPoint &point)
{
  MapDistance distance = MapDistance(*this, point);
  return distance;
}

MapPoint MapPoint::Farthest(MapPoint &first, MapPoint &second)
{
  double firstDistance = MapDistance(*this, first).GetDistance();
  double secondDistance = MapDistance(*this, second).GetDistance();
  return firstDistance > secondDistance ? first : second; 
}


MapDistance::MapDistance(): 
_distanceLongitude(0.), _distanceLatitude(0.) {}

MapDistance::MapDistance(MapPoint first, MapPoint second):
_start(first), _end(second), 
_distanceLongitude(_end.GetLongitude() - _start.GetLongitude()),
_distanceLatitude(_end.GetLatitude() - _start.GetLatitude()) {}

double MapDistance::GetDistance()
{
  return sqrt(_distanceLongitude * _distanceLongitude + 
              _distanceLatitude * _distanceLatitude);
}

void MapDistance::Print()
{
  double distance = GetDistance();
  std::cout << "Distance : "; 
  if(distance==0)
  {
    std::cout << "None";  
  }
  else
  {
    std::cout << _start.GetLabel() << "-" << _end.GetLabel();
  }
  std::cout << " (" << _distanceLongitude << ", " << _distanceLatitude << ")" << std::endl;
}
