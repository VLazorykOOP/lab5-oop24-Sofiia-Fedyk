#pragma once

#ifndef SPORT_GAME_H
#define SPORT_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

/**
 * @brief Base class representing a sport game
 */
class SportGame
{
protected:
    std::string name;               // Game name
    int playersCount;               // Number of players
    int duration;                   // Game duration in minutes
    std::vector<std::string> rules; // Game rules

    // Static counter for class objects
    static int objectCount;

public:
    // Constructors
    SportGame();
    SportGame(const std::string &name, int playersCount, int duration);
    SportGame(const SportGame &other);     // Copy constructor
    SportGame(SportGame &&other) noexcept; // Move constructor

    // Destructor
    virtual ~SportGame();

    // Getters
    std::string getName() const { return name; }
    int getPlayersCount() const { return playersCount; }
    int getDuration() const { return duration; }
    const std::vector<std::string> &getRules() const { return rules; }

    // Setters
    void setName(const std::string &newName) { name = newName; }
    void setPlayersCount(int count) { playersCount = count; }
    void setDuration(int mins) { duration = mins; }

    // Methods for working with rules
    void addRule(const std::string &rule);
    void clearRules();

    // Data input methods
    virtual void inputFromKeyboard();
    virtual void inputFromFile(const std::string &filename);
    virtual void generateRandom();

    // Information output
    virtual void displayInfo() const;

    // Static methods
    static int getObjectCount() { return objectCount; }
    static void resetObjectCount() { objectCount = 0; }

    // Virtual method for calculating energy expenditure
    virtual double calculateEnergyExpenditure() const;

    // Overloaded input/output operators
    friend std::ostream &operator<<(std::ostream &os, const SportGame &game);
    friend std::istream &operator>>(std::istream &is, SportGame &game);

    // Assignment operators
    SportGame &operator=(const SportGame &other);
    SportGame &operator=(SportGame &&other) noexcept;
};

#endif // SPORT_GAME_H