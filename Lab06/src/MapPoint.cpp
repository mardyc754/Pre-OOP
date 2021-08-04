#include "MapPoint.h"

MapPoint::MapPoint(std::string id, double longitude, double latitude):
_id(id), _longitude(longitude), _latitude(latitude)
{}

MapPoint::MapPoint(std::string id): _id(id) {}

MapPoint::MapPoint() {}

void MapPoint::Print()
{
  std::cout << "Point: " << _id << " (" << _latitude << ", " 
            << _longitude << ")" << std::endl;
}

void MapPoint::Latitude(double latitude){ _latitude = latitude; }

void MapPoint::Longitude(double longitude){ _longitude = longitude; }

void MapPoint::Coordinates(double latitude, double longitude)
{
  _latitude = latitude;
  _longitude = longitude;
}

double MapPoint::GetLatitude(){ return _latitude; }

double MapPoint::GetLongitude(){ return _longitude; }

std::string MapPoint::GetId(){ return _id; }

void MapPoint::SetId(std::string id){ _id = id; }

MapPoint MapPoint::Farthest(MapPoint &first, MapPoint &second)
{
    double firstDistance = MapDistance(*this, first).GetDistance();  
    double secondDistance = MapDistance(*this, second).GetDistance();

    return firstDistance > secondDistance ? first : second;
}

MapDistance MapPoint::Distance(MapPoint &pt)
{
  return MapDistance(*this, pt);
}

MapDistance::MapDistance()
{
  for(int i=0; i<2; i++)
    _distanceCoordinates[i] =0.;
  _distance = sqrt(_distanceCoordinates[0] * _distanceCoordinates[0]
                  + _distanceCoordinates[1] * _distanceCoordinates[1]);
}

MapDistance::MapDistance(MapPoint start, MapPoint end):
_start(start), _end(end)
{
    _distanceCoordinates[0] = _end.GetLatitude() - _start.GetLatitude();
    _distanceCoordinates[1] = _end.GetLongitude() - _start.GetLongitude();
    _distance = sqrt( _distanceCoordinates[0] * _distanceCoordinates[0]
                    + _distanceCoordinates[1] * _distanceCoordinates[1]);
}

void MapDistance::Print()
{
  std::cout << "Distance : ";
  
  if (_distance == 0)
  {
    std::cout << "None";
  }
  else
  {
    std::cout << _start.GetId() << "-" << _end.GetId(); 
  }
    std::cout << " (" << _distanceCoordinates[0] << ", " 
              << _distanceCoordinates[1] << ")" << std::endl;
}

double MapDistance::GetDistance(){ return _distance; }



