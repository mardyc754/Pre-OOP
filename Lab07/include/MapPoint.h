#pragma once

#include <iostream>
#include <cmath>

class MapDistance;

class MapPoint{
  public:
  /*
    * wyswietla Punkt z jego id i wspolrzednymi geograficznymi
  */
    void Print();
  /*
    * przypisuje etykiete
  */
    void Label(std::string);
  /*
    * przypisuje szerokosc geograficzna
  */
    void Longitude(double);
  /*
    * przypisuje dlugosc geograficzna
  */
    void Latitude(double);
  /*
    * przypisuje obydwie wspolrzedne geograficzne
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
    * zwraca etykiete
  */
    std::string GetLabel();
  /*
    * zwraca obiekt typu MapDistance na postawie argumentu funkcji
  */
    MapDistance Distance(MapPoint &);
  /*
    * zwraca taki punkt, do ktorego odleglosc jest najdalsza
  */
    MapPoint Farthest(MapPoint &, MapPoint &);
  
  private:
    std::string _label;
    double _longitude, _latitude;

};

class MapDistance{
  public:
    /*
      * kostruktor domyslny klasy MapDistance
    */
    MapDistance();
    /*
      * kostruktor dwuargumentowy klasy MapDistance, gdzie argumenty
        to punkty, pomiedzy ktorymi obliczana jest odleglosc
    */
    MapDistance(MapPoint, MapPoint);
    /*
      * zwraca obliczony juz dystans
    */
    double GetDistance();
    /*
      * wyswietla wspolrzedne odleglosci
    */
    void Print();
  private:
    MapPoint _start, _end;
    double _distanceLongitude;
    double _distanceLatitude;
};

