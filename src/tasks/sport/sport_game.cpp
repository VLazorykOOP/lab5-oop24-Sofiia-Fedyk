#include "sport/football.h"
#include <iostream>
#include <fstream>
#include <random>
#include <limits>

// Initialization of static object counter
int SportGame::objectCount = 0;

// Default constructor
SportGame::SportGame() : name("Unknown game"), playersCount(0), duration(0)
{
    objectCount++;
    std::cout << "SportGame: Default object created" << std::endl;
}

// Constructor with parameters
SportGame::SportGame(const std::string &name, int playersCount, int duration)
    : name(name), playersCount(playersCount), duration(duration)
{
    objectCount++;
    std::cout << "SportGame: Object created with name " << name << std::endl;
}

// Copy constructor
SportGame::SportGame(const SportGame &other)
    : name(other.name), playersCount(other.playersCount),
      duration(other.duration), rules(other.rules)
{
    objectCount++;
    std::cout << "SportGame: Copy of object created " << name << std::endl;
}

// Move constructor
SportGame::SportGame(SportGame &&other) noexcept
    : name(std::move(other.name)),
      playersCount(other.playersCount),
      duration(other.duration),
      rules(std::move(other.rules))
{
    other.playersCount = 0;
    other.duration = 0;
    objectCount++;
    std::cout << "SportGame: Object created via move " << name << std::endl;
}

// Destructor
SportGame::~SportGame()
{
    objectCount--;
    std::cout << "SportGame: Object destroyed " << name << std::endl;
}

// Adding a rule
void SportGame::addRule(const std::string &rule)
{
    rules.push_back(rule);
}

// Clearing rules
void SportGame::clearRules()
{
    rules.clear();
}

// Input from keyboard
void SportGame::inputFromKeyboard()
{
    std::cout << "Enter game name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter number of players: ";
    std::cin >> playersCount;

    std::cout << "Enter game duration (min): ";
    std::cin >> duration;

    int rulesCount;
    std::cout << "Enter number of rules: ";
    std::cin >> rulesCount;
    std::cin.ignore();

    rules.clear();
    for (int i = 0; i < rulesCount; i++)
    {
        std::string rule;
        std::cout << "Rule " << (i + 1) << ": ";
        std::getline(std::cin, rule);
        rules.push_back(rule);
    }
}

// Input from file
void SportGame::inputFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    std::getline(file, name);
    file >> playersCount;
    file >> duration;

    int rulesCount;
    file >> rulesCount;
    file.ignore();

    rules.clear();
    for (int i = 0; i < rulesCount; i++)
    {
        std::string rule;
        std::getline(file, rule);
        rules.push_back(rule);
    }

    file.close();
}

// Generate random data
void SportGame::generateRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr_players(2, 30);
    std::uniform_int_distribution<> distr_duration(10, 180);

    std::vector<std::string> possibleNames = {
        "Basketball", "Volleyball", "Handball", "Tennis", "Badminton",
        "Hockey", "Rugby", "Baseball", "Cricket", "Water polo"};

    std::uniform_int_distribution<> distr_name(0, possibleNames.size() - 1);
    name = possibleNames[distr_name(gen)];

    playersCount = distr_players(gen);
    duration = distr_duration(gen);

    std::vector<std::string> possibleRules = {
        "Play fair", "Respect the referee", "No doping",
        "No physical aggression", "Follow sports ethics"};

    std::uniform_int_distribution<> distr_rules_count(1, 3);
    int rulesCount = distr_rules_count(gen);

    rules.clear();
    for (int i = 0; i < rulesCount; i++)
    {
        std::uniform_int_distribution<> distr_rule(0, possibleRules.size() - 1);
        rules.push_back(possibleRules[distr_rule(gen)]);
    }
}

// Display information
void SportGame::displayInfo() const
{
    std::cout << "=== Sport Game ===" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Number of players: " << playersCount << std::endl;
    std::cout << "Duration (min): " << duration << std::endl;
    std::cout << "Rules:" << std::endl;

    if (rules.empty())
    {
        std::cout << "  (Rules not defined)" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < rules.size(); i++)
        {
            std::cout << "  " << (i + 1) << ". " << rules[i] << std::endl;
        }
    }
}

// Calculate energy expenditure (base formula)
double SportGame::calculateEnergyExpenditure() const
{
    // Simplified formula: game duration * 5 calories per minute
    return duration * 5.0;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const SportGame &game)
{
    os << game.name << "\n";
    os << game.playersCount << "\n";
    os << game.duration << "\n";
    os << game.rules.size() << "\n";

    for (const auto &rule : game.rules)
    {
        os << rule << "\n";
    }

    return os;
}

// Input operator
std::istream &operator>>(std::istream &is, SportGame &game)
{
    std::getline(is, game.name);
    is >> game.playersCount;
    is >> game.duration;

    int rulesCount;
    is >> rulesCount;
    is.ignore();

    game.rules.clear();
    for (int i = 0; i < rulesCount; i++)
    {
        std::string rule;
        std::getline(is, rule);
        game.rules.push_back(rule);
    }

    return is;
}

// Copy assignment operator
SportGame &SportGame::operator=(const SportGame &other)
{
    if (this != &other)
    {
        name = other.name;
        playersCount = other.playersCount;
        duration = other.duration;
        rules = other.rules;
        std::cout << "SportGame: Assignment operator called for " << name << std::endl;
    }
    return *this;
}

// Move assignment operator
SportGame &SportGame::operator=(SportGame &&other) noexcept
{
    if (this != &other)
    {
        name = std::move(other.name);
        playersCount = other.playersCount;
        duration = other.duration;
        rules = std::move(other.rules);

        other.playersCount = 0;
        other.duration = 0;

        std::cout << "SportGame: Move operator called for " << name << std::endl;
    }
    return *this;
}