#pragma once

#ifndef APARTMENT_CLASSES_H
#define APARTMENT_CLASSES_H

#include <iostream>
#include <string>
#include <fstream>
#include <random>

// Class "Room"
class Room
{
private:
    double area; // room area in m²

public:
    // Constructors
    Room();                  // default constructor
    Room(double roomArea);   // constructor with parameter
    Room(const Room &other); // copy constructor

    // Assignment operator
    Room &operator=(const Room &other);

    // Destructor
    virtual ~Room();

    // Access methods
    double getArea() const;
    void setArea(double roomArea);

    // Other methods
    virtual void printInfo() const;
    static double calculateMinimumStandardArea(); // static method that returns minimum standard area
};

// Class "One-room apartment"
class OneRoomApartment
{
private:
    Room room;          // room
    double kitchenArea; // kitchen area in m²
    int floor;          // floor

public:
    // Constructors
    OneRoomApartment();                                                // default constructor
    OneRoomApartment(double roomArea, double kitchenArea, int floor);  // constructor with parameters
    OneRoomApartment(const Room &room, double kitchenArea, int floor); // constructor with Room object
    OneRoomApartment(const OneRoomApartment &other);                   // copy constructor

    // Assignment operator
    OneRoomApartment &operator=(const OneRoomApartment &other);

    // Destructor
    virtual ~OneRoomApartment();

    // Access methods
    Room getRoom() const;
    void setRoom(const Room &room);

    double getKitchenArea() const;
    void setKitchenArea(double kitchenArea);

    int getFloor() const;
    void setFloor(int floor);

    // Other methods
    double getTotalArea() const; // get total apartment area
    virtual void printInfo() const;
    static double calculateMinimumKitchenArea(); // static method
};

// Class "City one-room apartment" (derived from OneRoomApartment)
class CityOneRoomApartment : public OneRoomApartment
{
private:
    std::string cityName; // city name

public:
    // Constructors
    CityOneRoomApartment(); // default constructor
    CityOneRoomApartment(double roomArea, double kitchenArea, int floor, const std::string &city);
    CityOneRoomApartment(const Room &room, double kitchenArea, int floor, const std::string &city);
    CityOneRoomApartment(const OneRoomApartment &apartment, const std::string &city);
    CityOneRoomApartment(const CityOneRoomApartment &other); // copy constructor

    // Assignment operator
    CityOneRoomApartment &operator=(const CityOneRoomApartment &other);

    // Destructor
    virtual ~CityOneRoomApartment();

    // Access methods
    std::string getCityName() const;
    void setCityName(const std::string &city);

    // Overridden information output method
    virtual void printInfo() const override;

    // Static method
    static std::string getPopularCity();
};

// Functions for data input
void inputFromKeyboard(Room &room);
void inputFromKeyboard(OneRoomApartment &apartment);
void inputFromKeyboard(CityOneRoomApartment &cityApartment);

void inputFromFile(Room &room, const std::string &filename);
void inputFromFile(OneRoomApartment &apartment, const std::string &filename);
void inputFromFile(CityOneRoomApartment &cityApartment, const std::string &filename);

void generateRandom(Room &room, double minArea = 5.0, double maxArea = 30.0);
void generateRandom(OneRoomApartment &apartment, double minRoomArea = 5.0, double maxRoomArea = 30.0,
                    double minKitchenArea = 4.0, double maxKitchenArea = 15.0,
                    int minFloor = 1, int maxFloor = 20);
void generateRandom(CityOneRoomApartment &cityApartment, double minRoomArea = 5.0, double maxRoomArea = 30.0,
                    double minKitchenArea = 4.0, double maxKitchenArea = 15.0,
                    int minFloor = 1, int maxFloor = 20);

#endif // APARTMENT_CLASSES_H