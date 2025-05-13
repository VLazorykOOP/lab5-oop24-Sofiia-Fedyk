#include "apartment_classes.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>

// Room class implementation
Room::Room() : area(0.0) {
    std::cout << "Default room created" << std::endl;
}

Room::Room(double roomArea) : area(roomArea > 0 ? roomArea : 0.0) {
    std::cout << "Room with area " << area << " m² created" << std::endl;
}

Room::Room(const Room& other) : area(other.area) {
    std::cout << "Room copy with area " << area << " m² created" << std::endl;
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {
        area = other.area;
    }
    return *this;
}

Room::~Room() {
    std::cout << "Room with area " << area << " m² deleted" << std::endl;
}

double Room::getArea() const {
    return area;
}

void Room::setArea(double roomArea) {
    if (roomArea >= 0) {
        area = roomArea;
    }
}

void Room::printInfo() const {
    std::cout << "Room: area = " << area << " m²" << std::endl;
}

double Room::calculateMinimumStandardArea() {
    // Standard minimum room area (conventionally)
    return 9.0; // m²
}

// OneRoomApartment class implementation
OneRoomApartment::OneRoomApartment() : room(), kitchenArea(0.0), floor(1) {
    std::cout << "Default one-room apartment created" << std::endl;
}

OneRoomApartment::OneRoomApartment(double roomArea, double kitArea, int flr) 
    : room(roomArea), kitchenArea(kitArea > 0 ? kitArea : 0.0), floor(flr > 0 ? flr : 1) {
    std::cout << "One-room apartment created (room: " << roomArea 
              << " m², kitchen: " << kitchenArea << " m², floor: " << floor << ")" << std::endl;
}

OneRoomApartment::OneRoomApartment(const Room& rm, double kitArea, int flr) 
    : room(rm), kitchenArea(kitArea > 0 ? kitArea : 0.0), floor(flr > 0 ? flr : 1) {
    std::cout << "One-room apartment created with existing room" << std::endl;
}

OneRoomApartment::OneRoomApartment(const OneRoomApartment& other) 
    : room(other.room), kitchenArea(other.kitchenArea), floor(other.floor) {
    std::cout << "One-room apartment copy created" << std::endl;
}

OneRoomApartment& OneRoomApartment::operator=(const OneRoomApartment& other) {
    if (this != &other) {
        room = other.room;
        kitchenArea = other.kitchenArea;
        floor = other.floor;
    }
    return *this;
}

OneRoomApartment::~OneRoomApartment() {
    std::cout << "One-room apartment on floor " << floor << " deleted" << std::endl;
}

Room OneRoomApartment::getRoom() const {
    return room;
}

void OneRoomApartment::setRoom(const Room& rm) {
    room = rm;
}

double OneRoomApartment::getKitchenArea() const {
    return kitchenArea;
}

void OneRoomApartment::setKitchenArea(double kitArea) {
    if (kitArea >= 0) {
        kitchenArea = kitArea;
    }
}

int OneRoomApartment::getFloor() const {
    return floor;
}

void OneRoomApartment::setFloor(int flr) {
    if (flr > 0) {
        floor = flr;
    }
}

double OneRoomApartment::getTotalArea() const {
    return room.getArea() + kitchenArea;
}

void OneRoomApartment::printInfo() const {
    std::cout << "One-room apartment:" << std::endl;
    room.printInfo();
    std::cout << "Kitchen: area = " << kitchenArea << " m²" << std::endl;
    std::cout << "Floor: " << floor << std::endl;
    std::cout << "Total area: " << getTotalArea() << " m²" << std::endl;
}

double OneRoomApartment::calculateMinimumKitchenArea() {
    // Standard minimum kitchen area (conventionally)
    return 6.0; // m²
}

// CityOneRoomApartment class implementation
CityOneRoomApartment::CityOneRoomApartment() : OneRoomApartment(), cityName("Unknown city") {
    std::cout << "Default city one-room apartment created" << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(double roomArea, double kitchenArea, int floor, const std::string& city)
    : OneRoomApartment(roomArea, kitchenArea, floor), cityName(city) {
    std::cout << "One-room apartment created in " << cityName << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(const Room& room, double kitchenArea, int floor, const std::string& city)
    : OneRoomApartment(room, kitchenArea, floor), cityName(city) {
    std::cout << "One-room apartment created in " << cityName << " with existing room" << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(const OneRoomApartment& apartment, const std::string& city)
    : OneRoomApartment(apartment), cityName(city) {
    std::cout << "One-room apartment created in " << cityName << " from existing apartment" << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(const CityOneRoomApartment& other)
    : OneRoomApartment(other), cityName(other.cityName) {
    std::cout << "One-room apartment copy created in " << cityName << std::endl;
}

CityOneRoomApartment& CityOneRoomApartment::operator=(const CityOneRoomApartment& other) {
    if (this != &other) {
        OneRoomApartment::operator=(other);
        cityName = other.cityName;
    }
    return *this;
}

CityOneRoomApartment::~CityOneRoomApartment() {
    std::cout << "One-room apartment in " << cityName << " deleted" << std::endl;
}

std::string CityOneRoomApartment::getCityName() const {
    return cityName;
}

void CityOneRoomApartment::setCityName(const std::string& city) {
    cityName = city;
}

void CityOneRoomApartment::printInfo() const {
    std::cout << "One-room apartment in " << cityName << ":" << std::endl;
    OneRoomApartment::printInfo(); // Call base class method
}

std::string CityOneRoomApartment::getPopularCity() {
    // Static method returns the most popular city for one-room apartments
    static const std::vector<std::string> popularCities = {"Kyiv", "Lviv", "Odesa", "Kharkiv", "Dnipro"};
    return popularCities[0]; // Return the first city as the most popular
}

// Input functions implementation
void inputFromKeyboard(Room& room) {
    double area;
    std::cout << "Enter room area (m²): ";
    std::cin >> area;
    room.setArea(area);
}

void inputFromKeyboard(OneRoomApartment& apartment) {
    Room room;
    inputFromKeyboard(room);
    
    double kitchenArea;
    std::cout << "Enter kitchen area (m²): ";
    std::cin >> kitchenArea;
    
    int floor;
    std::cout << "Enter floor: ";
    std::cin >> floor;
    
    apartment.setRoom(room);
    apartment.setKitchenArea(kitchenArea);
    apartment.setFloor(floor);
}

void inputFromKeyboard(CityOneRoomApartment& cityApartment) {
    OneRoomApartment apartment;
    inputFromKeyboard(apartment);
    
    std::string city;
    std::cout << "Enter city name: ";
    std::cin.ignore(); // Clear buffer
    std::getline(std::cin, city);
    
    cityApartment = CityOneRoomApartment(apartment, city);
}

void inputFromFile(Room& room, const std::string& filename) {
    std::ifstream file(filename);
    
    if (file.is_open()) {
        double area;
        file >> area;
        room.setArea(area);
        file.close();
    } else {
        std::cerr << "Error opening file " << filename << std::endl;
    }
}

void inputFromFile(OneRoomApartment& apartment, const std::string& filename) {
    std::ifstream file(filename);
    
    if (file.is_open()) {
        double roomArea, kitchenArea;
        int floor;
        
        file >> roomArea >> kitchenArea >> floor;
        
        Room room(roomArea);
        apartment.setRoom(room);
        apartment.setKitchenArea(kitchenArea);
        apartment.setFloor(floor);
        
        file.close();
    } else {
        std::cerr << "Error opening file " << filename << std::endl;
    }
}

void inputFromFile(CityOneRoomApartment& cityApartment, const std::string& filename) {
    std::ifstream file(filename);
    
    if (file.is_open()) {
        double roomArea, kitchenArea;
        int floor;
        std::string city;
        
        file >> roomArea >> kitchenArea >> floor;
        file.ignore(); // Skip newline character
        std::getline(file, city);
        
        Room room(roomArea);
        OneRoomApartment apartment(room, kitchenArea, floor);
        cityApartment = CityOneRoomApartment(apartment, city);
        
        file.close();
    } else {
        std::cerr << "Error opening file " << filename << std::endl;
    }
}

void generateRandom(Room& room, double minArea, double maxArea) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distArea(minArea, maxArea);
    
    room.setArea(distArea(gen));
}

void generateRandom(OneRoomApartment& apartment, double minRoomArea, double maxRoomArea, 
                   double minKitchenArea, double maxKitchenArea, 
                   int minFloor, int maxFloor) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distRoomArea(minRoomArea, maxRoomArea);
    std::uniform_real_distribution<> distKitchenArea(minKitchenArea, maxKitchenArea);
    std::uniform_int_distribution<> distFloor(minFloor, maxFloor);
    
    Room room(distRoomArea(gen));
    apartment.setRoom(room);
    apartment.setKitchenArea(distKitchenArea(gen));
    apartment.setFloor(distFloor(gen));
}

void generateRandom(CityOneRoomApartment& cityApartment, double minRoomArea, double maxRoomArea, 
                   double minKitchenArea, double maxKitchenArea, 
                   int minFloor, int maxFloor) {
    OneRoomApartment apartment;
    generateRandom(apartment, minRoomArea, maxRoomArea, minKitchenArea, maxKitchenArea, minFloor, maxFloor);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<std::string> cities = {"Kyiv", "Lviv", "Odesa", "Kharkiv", "Dnipro", "Zaporizhzhia", "Vinnytsia"};
    std::uniform_int_distribution<> distCity(0, cities.size() - 1);
    
    cityApartment = CityOneRoomApartment(apartment, cities[distCity(gen)]);
}