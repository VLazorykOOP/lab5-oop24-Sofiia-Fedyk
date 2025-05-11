#ifndef FOOTBALL_H
#define FOOTBALL_H

#include "sport_game.h"
#include <string>
#include <vector>

/**
 * @brief Клас, що представляє футбол як різновид спортивної гри
 */
class Football : public SportGame {
private:
    std::string ballType;           // Тип м'яча
    int fieldLength;                // Довжина поля (метри)
    int fieldWidth;                 // Ширина поля (метри)
    std::vector<std::string> teams; // Назви команд
    int goalCount;                  // Кількість забитих голів

    // Статичний лічильник об'єктів класу
    static int footballObjectCount;

public:
    // Конструктори
    Football();
    Football(const std::string& name, int playersCount, int duration,
             const std::string& ballType, int fieldLength, int fieldWidth);
    Football(const Football& other); // Конструктор копіювання
    Football(Football&& other) noexcept; // Конструктор перенесення

    // Деструктор
    ~Football() override;

    // Геттери
    std::string getBallType() const { return ballType; }
    int getFieldLength() const { return fieldLength; }
    int getFieldWidth() const { return fieldWidth; }
    int getGoalCount() const { return goalCount; }
    const std::vector<std::string>& getTeams() const { return teams; }

    // Сеттери
    void setBallType(const std::string& type) { ballType = type; }
    void setFieldLength(int length) { fieldLength = length; }
    void setFieldWidth(int width) { fieldWidth = width; }
    void setGoalCount(int count) { goalCount = count; }

    // Методи для роботи з командами
    void addTeam(const std::string& team);
    void clearTeams();

    // Перевизначені методи введення даних
    void inputFromKeyboard() override;
    void inputFromFile(const std::string& filename) override;
    void generateRandom() override;

    // Перевизначений метод виведення інформації
    void displayInfo() const override;

    // Перевизначений метод розрахунку енергетичних витрат
    double calculateEnergyExpenditure() const override;

    // Статичні методи
    static int getFootballObjectCount() { return footballObjectCount; }
    static void resetFootballObjectCount() { footballObjectCount = 0; }

    // Специфічні методи для футболу
    int calculateFieldArea() const;
    double calculateAverageGoalsPerGame() const;
    void simulateMatch();

    // Перевантажені оператори введення/виведення
    friend std::ostream& operator<<(std::ostream& os, const Football& football);
    friend std::istream& operator>>(std::istream& is, Football& football);

    // Оператори присвоювання
    Football& operator=(const Football& other);
    Football& operator=(Football&& other) noexcept;
};

#endif // FOOTBALL_H