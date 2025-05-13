#pragma once

#ifndef FOOTBALL_H
#define FOOTBALL_H

#include "sport_game.h"
#include <string>
#include <vector>

/**
 * @brief Class representing football as a type of sport game
 */
class Football : public SportGame
{
private:
    std::string ballType;           // Ball type
    int fieldLength;                // Field length (meters)
    int fieldWidth;                 // Field width (meters)
    std::vector<std::string> teams; // Team names
    int goalCount;                  // Number of scored goals

    // Static counter for class objects
    static int footballObjectCount;

public:
    // Constructors
    Football();
    Football(const std::string &name, int playersCount, int duration,
             const std::string &ballType, int fieldLength, int fieldWidth);
    Football(const Football &other);     // Copy constructor
    Football(Football &&other) noexcept; // Move constructor

    // Destructor
    ~Football() override;

    // Getters
    std::string getBallType() const { return ballType; }
    int getFieldLength() const { return fieldLength; }
    int getFieldWidth() const { return fieldWidth; }
    int getGoalCount() const { return goalCount; }
    const std::vector<std::string> &getTeams() const { return teams; }

    // Setters
    void setBallType(const std::string &type) { ballType = type; }
    void setFieldLength(int length) { fieldLength = length; }
    void setFieldWidth(int width) { fieldWidth = width; }
    void setGoalCount(int count) { goalCount = count; }

    // Methods for working with teams
    void addTeam(const std::string &team);
    void clearTeams();

    // Overridden data input methods
    void inputFromKeyboard() override;
    void inputFromFile(const std::string &filename) override;
    void generateRandom() override;

    // Overridden information output method
    void displayInfo() const override;

    // Overridden method for calculating energy expenditure
    double calculateEnergyExpenditure() const override;

    // Static methods
    static int getFootballObjectCount() { return footballObjectCount; }
    static void resetFootballObjectCount() { footballObjectCount = 0; }

    // Specific methods for football
    int calculateFieldArea() const;
    double calculateAverageGoalsPerGame() const;
    void simulateMatch();

    // Overloaded input/output operators
    friend std::ostream &operator<<(std::ostream &os, const Football &football);
    friend std::istream &operator>>(std::istream &is, Football &football);

    // Assignment operators
    Football &operator=(const Football &other);
    Football &operator=(Football &&other) noexcept;
};

#endif // FOOTBALL_H