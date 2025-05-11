#ifndef APARTMENT_CLASSES_H
#define APARTMENT_CLASSES_H

#include <iostream>
#include <string>
#include <fstream>
#include <random>

// Клас "Кімната"
class Room {
private:
    double area; // площа кімнати в м²

public:
    // Конструктори
    Room(); // конструктор за замовчуванням
    Room(double roomArea); // конструктор з параметром
    Room(const Room& other); // конструктор копіювання
    
    // Оператор присвоєння
    Room& operator=(const Room& other);
    
    // Деструктор
    virtual ~Room();
    
    // Методи доступу
    double getArea() const;
    void setArea(double roomArea);
    
    // Інші методи
    virtual void printInfo() const;
    static double calculateMinimumStandardArea(); // статичний метод, що повертає мінімальну стандартну площу
};

// Клас "Однокімнатна квартира"
class OneRoomApartment {
private:
    Room room; // кімната
    double kitchenArea; // площа кухні в м²
    int floor; // поверх

public:
    // Конструктори
    OneRoomApartment(); // конструктор за замовчуванням
    OneRoomApartment(double roomArea, double kitchenArea, int floor); // конструктор з параметрами
    OneRoomApartment(const Room& room, double kitchenArea, int floor); // конструктор з об'єктом Room
    OneRoomApartment(const OneRoomApartment& other); // конструктор копіювання
    
    // Оператор присвоєння
    OneRoomApartment& operator=(const OneRoomApartment& other);
    
    // Деструктор
    virtual ~OneRoomApartment();
    
    // Методи доступу
    Room getRoom() const;
    void setRoom(const Room& room);
    
    double getKitchenArea() const;
    void setKitchenArea(double kitchenArea);
    
    int getFloor() const;
    void setFloor(int floor);
    
    // Інші методи
    double getTotalArea() const; // отримати загальну площу квартири
    virtual void printInfo() const;
    static double calculateMinimumKitchenArea(); // статичний метод
};

// Клас "Однокімнатна квартира у місті" (похідний від OneRoomApartment)
class CityOneRoomApartment : public OneRoomApartment {
private:
    std::string cityName; // назва міста

public:
    // Конструктори
    CityOneRoomApartment(); // конструктор за замовчуванням
    CityOneRoomApartment(double roomArea, double kitchenArea, int floor, const std::string& city);
    CityOneRoomApartment(const Room& room, double kitchenArea, int floor, const std::string& city);
    CityOneRoomApartment(const OneRoomApartment& apartment, const std::string& city);
    CityOneRoomApartment(const CityOneRoomApartment& other); // конструктор копіювання
    
    // Оператор присвоєння
    CityOneRoomApartment& operator=(const CityOneRoomApartment& other);
    
    // Деструктор
    virtual ~CityOneRoomApartment();
    
    // Методи доступу
    std::string getCityName() const;
    void setCityName(const std::string& city);
    
    // Перевизначений метод виведення інформації
    virtual void printInfo() const override;
    
    // Статичний метод
    static std::string getPopularCity();
};

// Функції для введення даних
void inputFromKeyboard(Room& room);
void inputFromKeyboard(OneRoomApartment& apartment);
void inputFromKeyboard(CityOneRoomApartment& cityApartment);

void inputFromFile(Room& room, const std::string& filename);
void inputFromFile(OneRoomApartment& apartment, const std::string& filename);
void inputFromFile(CityOneRoomApartment& cityApartment, const std::string& filename);

void generateRandom(Room& room, double minArea = 5.0, double maxArea = 30.0);
void generateRandom(OneRoomApartment& apartment, double minRoomArea = 5.0, double maxRoomArea = 30.0, 
                   double minKitchenArea = 4.0, double maxKitchenArea = 15.0, 
                   int minFloor = 1, int maxFloor = 20);
void generateRandom(CityOneRoomApartment& cityApartment, double minRoomArea = 5.0, double maxRoomArea = 30.0, 
                   double minKitchenArea = 4.0, double maxKitchenArea = 15.0, 
                   int minFloor = 1, int maxFloor = 20);

#endif // APARTMENT_CLASSES_H