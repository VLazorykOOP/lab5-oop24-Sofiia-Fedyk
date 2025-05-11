#ifndef SPORT_GAME_H
#define SPORT_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

/**
 * @brief Базовий клас, що представляє спортивну гру
 */
class SportGame {
protected:
    std::string name;              // Назва гри
    int playersCount;              // Кількість гравців
    int duration;                  // Тривалість гри в хвилинах
    std::vector<std::string> rules;// Правила гри

    // Статичний лічильник об'єктів класу
    static int objectCount;

public:
    // Конструктори
    SportGame();
    SportGame(const std::string& name, int playersCount, int duration);
    SportGame(const SportGame& other); // Конструктор копіювання
    SportGame(SportGame&& other) noexcept; // Конструктор перенесення

    // Деструктор
    virtual ~SportGame();

    // Геттери
    std::string getName() const { return name; }
    int getPlayersCount() const { return playersCount; }
    int getDuration() const { return duration; }
    const std::vector<std::string>& getRules() const { return rules; }

    // Сеттери
    void setName(const std::string& newName) { name = newName; }
    void setPlayersCount(int count) { playersCount = count; }
    void setDuration(int mins) { duration = mins; }
    
    // Методи для роботи з правилами
    void addRule(const std::string& rule);
    void clearRules();

    // Введення даних різними способами
    virtual void inputFromKeyboard();
    virtual void inputFromFile(const std::string& filename);
    virtual void generateRandom();

    // Вивід інформації
    virtual void displayInfo() const;

    // Статичні методи
    static int getObjectCount() { return objectCount; }
    static void resetObjectCount() { objectCount = 0; }

    // Віртуальний метод для обчислення енергетичних витрат
    virtual double calculateEnergyExpenditure() const;

    // Перевантажені оператори введення/виведення
    friend std::ostream& operator<<(std::ostream& os, const SportGame& game);
    friend std::istream& operator>>(std::istream& is, SportGame& game);

    // Оператори присвоювання
    SportGame& operator=(const SportGame& other);
    SportGame& operator=(SportGame&& other) noexcept;
};

#endif // SPORT_GAME_H