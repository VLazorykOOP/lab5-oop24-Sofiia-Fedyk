#include "apartment_classes.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>

// Реалізація класу Room
Room::Room() : area(0.0) {
    std::cout << "Створено кімнату за замовчуванням" << std::endl;
}

Room::Room(double roomArea) : area(roomArea > 0 ? roomArea : 0.0) {
    std::cout << "Створено кімнату площею " << area << " м²" << std::endl;
}

Room::Room(const Room& other) : area(other.area) {
    std::cout << "Створено копію кімнати площею " << area << " м²" << std::endl;
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {
        area = other.area;
    }
    return *this;
}

Room::~Room() {
    std::cout << "Видалено кімнату площею " << area << " м²" << std::endl;
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
    std::cout << "Кімната: площа = " << area << " м²" << std::endl;
}

double Room::calculateMinimumStandardArea() {
    // Стандартна мінімальна площа кімнати (умовно)
    return 9.0; // м²
}

// Реалізація класу OneRoomApartment
OneRoomApartment::OneRoomApartment() : room(), kitchenArea(0.0), floor(1) {
    std::cout << "Створено однокімнатну квартиру за замовчуванням" << std::endl;
}

OneRoomApartment::OneRoomApartment(double roomArea, double kitArea, int flr) 
    : room(roomArea), kitchenArea(kitArea > 0 ? kitArea : 0.0), floor(flr > 0 ? flr : 1) {
    std::cout << "Створено однокімнатну квартиру (кімната: " << roomArea 
              << " м², кухня: " << kitchenArea << " м², поверх: " << floor << ")" << std::endl;
}

OneRoomApartment::OneRoomApartment(const Room& rm, double kitArea, int flr) 
    : room(rm), kitchenArea(kitArea > 0 ? kitArea : 0.0), floor(flr > 0 ? flr : 1) {
    std::cout << "Створено однокімнатну квартиру з існуючою кімнатою" << std::endl;
}

OneRoomApartment::OneRoomApartment(const OneRoomApartment& other) 
    : room(other.room), kitchenArea(other.kitchenArea), floor(other.floor) {
    std::cout << "Створено копію однокімнатної квартири" << std::endl;
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
    std::cout << "Видалено однокімнатну квартиру на поверсі " << floor << std::endl;
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
    std::cout << "Однокімнатна квартира:" << std::endl;
    room.printInfo();
    std::cout << "Кухня: площа = " << kitchenArea << " м²" << std::endl;
    std::cout << "Поверх: " << floor << std::endl;
    std::cout << "Загальна площа: " << getTotalArea() << " м²" << std::endl;
}

double OneRoomApartment::calculateMinimumKitchenArea() {
    // Стандартна мінімальна площа кухні (умовно)
    return 6.0; // м²
}

// Реалізація класу CityOneRoomApartment
CityOneRoomApartment::CityOneRoomApartment() : OneRoomApartment(), cityName("Невідоме місто") {
    std::cout << "Створено однокімнатну квартиру в місті за замовчуванням" << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(double roomArea, double kitchenArea, int floor, const std::string& city)
    : OneRoomApartment(roomArea, kitchenArea, floor), cityName(city) {
    std::cout << "Створено однокімнатну квартиру в місті " << cityName << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(const Room& room, double kitchenArea, int floor, const std::string& city)
    : OneRoomApartment(room, kitchenArea, floor), cityName(city) {
    std::cout << "Створено однокімнатну квартиру в місті " << cityName << " з існуючою кімнатою" << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(const OneRoomApartment& apartment, const std::string& city)
    : OneRoomApartment(apartment), cityName(city) {
    std::cout << "Створено однокімнатну квартиру в місті " << cityName << " з існуючої квартири" << std::endl;
}

CityOneRoomApartment::CityOneRoomApartment(const CityOneRoomApartment& other)
    : OneRoomApartment(other), cityName(other.cityName) {
    std::cout << "Створено копію однокімнатної квартири в місті " << cityName << std::endl;
}

CityOneRoomApartment& CityOneRoomApartment::operator=(const CityOneRoomApartment& other) {
    if (this != &other) {
        OneRoomApartment::operator=(other);
        cityName = other.cityName;
    }
    return *this;
}

CityOneRoomApartment::~CityOneRoomApartment() {
    std::cout << "Видалено однокімнатну квартиру в місті " << cityName << std::endl;
}

std::string CityOneRoomApartment::getCityName() const {
    return cityName;
}

void CityOneRoomApartment::setCityName(const std::string& city) {
    cityName = city;
}

void CityOneRoomApartment::printInfo() const {
    std::cout << "Однокімнатна квартира в місті " << cityName << ":" << std::endl;
    OneRoomApartment::printInfo(); // Виклик методу базового класу
}

std::string CityOneRoomApartment::getPopularCity() {
    // Статичний метод повертає найпопулярніше місто для однокімнатних квартир
    static const std::vector<std::string> popularCities = {"Київ", "Львів", "Одеса", "Харків", "Дніпро"};
    return popularCities[0]; // Повертаємо перше місто як найпопулярніше
}

// Реалізація функцій введення даних
void inputFromKeyboard(Room& room) {
    double area;
    std::cout << "Введіть площу кімнати (м²): ";
    std::cin >> area;
    room.setArea(area);
}

void inputFromKeyboard(OneRoomApartment& apartment) {
    Room room;
    inputFromKeyboard(room);
    
    double kitchenArea;
    std::cout << "Введіть площу кухні (м²): ";
    std::cin >> kitchenArea;
    
    int floor;
    std::cout << "Введіть поверх: ";
    std::cin >> floor;
    
    apartment.setRoom(room);
    apartment.setKitchenArea(kitchenArea);
    apartment.setFloor(floor);
}

void inputFromKeyboard(CityOneRoomApartment& cityApartment) {
    OneRoomApartment apartment;
    inputFromKeyboard(apartment);
    
    std::string city;
    std::cout << "Введіть назву міста: ";
    std::cin.ignore(); // Очищення буфера
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
        std::cerr << "Помилка відкриття файлу " << filename << std::endl;
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
        std::cerr << "Помилка відкриття файлу " << filename << std::endl;
    }
}

void inputFromFile(CityOneRoomApartment& cityApartment, const std::string& filename) {
    std::ifstream file(filename);
    
    if (file.is_open()) {
        double roomArea, kitchenArea;
        int floor;
        std::string city;
        
        file >> roomArea >> kitchenArea >> floor;
        file.ignore(); // Пропуск символу нового рядка
        std::getline(file, city);
        
        Room room(roomArea);
        OneRoomApartment apartment(room, kitchenArea, floor);
        cityApartment = CityOneRoomApartment(apartment, city);
        
        file.close();
    } else {
        std::cerr << "Помилка відкриття файлу " << filename << std::endl;
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
    std::vector<std::string> cities = {"Київ", "Львів", "Одеса", "Харків", "Дніпро", "Запоріжжя", "Вінниця"};
    std::uniform_int_distribution<> distCity(0, cities.size() - 1);
    
    cityApartment = CityOneRoomApartment(apartment, cities[distCity(gen)]);
}