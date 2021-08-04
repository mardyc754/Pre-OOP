#pragma once

#include <iostream>
#include <cmath>

class MapDistance;
#include "MapDistance.h"

class MapPoint
{
  public:
  /*
    * konstruktor MapPoint z trzema argumentami:
    * id - id punktu
    * longitude - szerokosc geograficzna
    * latitute - dlugosc geograficzna
  */
    MapPoint(std::string id, double longitude, double latitude);
  /*
    * konstruktor MapPoint z jednym argumentem:
    * id - id punktu
  */
    MapPoint(std::string id);
  /*
    * konstruktor domyslny MapPoint
  */
    MapPoint();
  /*
    * wypisuje punkt
  */
    void Print();
  /*
    * ustala dlugosc geograficzna
  */
    void Latitude(double);
    /*
      * ustala szerokosc geograficzna
    */
    void Longitude(double);
    /*
      * ustala wielkosci geograficzne
    */
    void Coordinates(double, double);
    /*
      * zwraca dlugosc geograficzna
    */
    double GetLatitude();
    /*
      * zwraca szerokosc geograficzna
    */
    double GetLongitude();
    /*
      * zwraca id punktu
    */
    std::string GetId();
    /*
      * ustala id
    */
    void SetId(std::string);
    /*
      * zwraca ten punkt podany jako argument funkcji, ktory lezy najdalej od punktu na ktorym jest wykonywana ta funkcja
    */
    MapPoint Farthest(MapPoint &first, MapPoint &second);
    /*
      * zwraca obiekt MapDistance, ktory zawiera informacje o odleglosci danego punktu od punktu p1
    */
    MapDistance Distance(MapPoint &pt);
  private:
    std::string _id;
    double _longitude, _latitude;

};

class MapDistance
{
  public:
  /*
    * konstruktor domyslny klasy MapDistance
  */
    MapDistance();
  /*
    * konstruktor dwuargumentowy klasy MapDistance, gdzie argumenty to punkty
      na mapie pomiedzy ktorymi bedzie obliczana odleglosc
  */
    MapDistance(MapPoint, MapPoint);
  /*
    * wypisuje odleglosc na ekran
  */
    void Print();
  /*
    * zwraca odleglosc
  */
    double GetDistance();
  private:
    MapPoint _start, _end;
    double _distanceCoordinates[2];
    double _distance;
};
