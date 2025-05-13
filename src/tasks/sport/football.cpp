#include "sport/football.h"
#include <iostream>
#include <fstream>
#include <random>

// Initialization of static object counter
int Football::footballObjectCount = 0;

// Default constructor
Football::Football()
    : SportGame("Football", 22, 90), ballType("Standard"),
      fieldLength(105), fieldWidth(68), goalCount(0)
{
    footballObjectCount++;

    // Adding basic football rules
    addRule("Game lasts 90 minutes (two halves of 45 minutes each)");
    addRule("Each team has 11 players");
    addRule("A goal is scored when the ball completely crosses the goal line");

    std::cout << "Football: Default object created" << std::endl;
}

// Constructor with parameters
Football::Football(const std::string &name, int playersCount, int duration,
                   const std::string &ballType, int fieldLength, int fieldWidth)
    : SportGame(name, playersCount, duration), ballType(ballType),
      fieldLength(fieldLength), fieldWidth(fieldWidth), goalCount(0)
{
    footballObjectCount++;
    std::cout << "Football: Object created with name " << name << std::endl;
}

// Copy constructor
Football::Football(const Football &other)
    : SportGame(other), ballType(other.ballType),
      fieldLength(other.fieldLength), fieldWidth(other.fieldWidth),
      teams(other.teams), goalCount(other.goalCount)
{
    footballObjectCount++;
    std::cout << "Football: Copy of object created " << name << std::endl;
}

// Move constructor
Football::Football(Football &&other) noexcept
    : SportGame(std::move(other)), ballType(std::move(other.ballType)),
      fieldLength(other.fieldLength), fieldWidth(other.fieldWidth),
      teams(std::move(other.teams)), goalCount(other.goalCount)
{
    other.fieldLength = 0;
    other.fieldWidth = 0;
    other.goalCount = 0;

    footballObjectCount++;
    std::cout << "Football: Object created via move " << name << std::endl;
}

// Destructor
Football::~Football()
{
    footballObjectCount--;
    std::cout << "Football: Object destroyed " << name << std::endl;
}

// Adding a team
void Football::addTeam(const std::string &team)
{
    teams.push_back(team);
}

// Clearing teams
void Football::clearTeams()
{
    teams.clear();
}

// Input from keyboard
void Football::inputFromKeyboard()
{
    SportGame::inputFromKeyboard();

    std::cout << "Enter ball type: ";
    std::cin.ignore();
    std::getline(std::cin, ballType);

    std::cout << "Enter field length (m): ";
    std::cin >> fieldLength;

    std::cout << "Enter field width (m): ";
    std::cin >> fieldWidth;

    std::cout << "Enter number of goals: ";
    std::cin >> goalCount;

    int teamCount;
    std::cout << "Enter number of teams: ";
    std::cin >> teamCount;
    std::cin.ignore();

    teams.clear();
    for (int i = 0; i < teamCount; i++)
    {
        std::string team;
        std::cout << "Team " << (i + 1) << ": ";
        std::getline(std::cin, team);
        teams.push_back(team);
    }
}

// Input from file
void Football::inputFromFile(const std::string &filename)
{
    SportGame::inputFromFile(filename);

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    // Skip lines that were already read in the base class
    std::string line;
    for (int i = 0; i < 3 + rules.size() + 1; i++)
    {
        std::getline(file, line);
    }

    std::getline(file, ballType);
    file >> fieldLength;
    file >> fieldWidth;
    file >> goalCount;

    int teamCount;
    file >> teamCount;
    file.ignore();

    teams.clear();
    for (int i = 0; i < teamCount; i++)
    {
        std::string team;
        std::getline(file, team);
        teams.push_back(team);
    }

    file.close();
}

// Generate random data
void Football::generateRandom()
{
    // Call base method to initialize base fields
    name = "Football";   // Override name after base method
    playersCount = 22;   // Standard number of players in football

    std::random_device rd;
    std::mt19937 gen(rd());

    // Random match duration (usually 90 minutes, but can be extended)
    std::uniform_int_distribution<> distr_duration(90, 120);
    duration = distr_duration(gen);

    // Ball types
    std::vector<std::string> ballTypes = {
        "Adidas Telstar", "Nike Flight", "Puma Final", "Mitre Delta",
        "Umbro Neo"};
    std::uniform_int_distribution<> distr_ball(0, ballTypes.size() - 1);
    ballType = ballTypes[distr_ball(gen)];

    // Field dimensions (according to FIFA standards)
    std::uniform_int_distribution<> distr_length(90, 120);
    std::uniform_int_distribution<> distr_width(45, 90);
    fieldLength = distr_length(gen);
    fieldWidth = distr_width(gen);

    // Number of goals
    std::uniform_int_distribution<> distr_goals(0, 7);
    goalCount = distr_goals(gen);

    // Possible football teams
    std::vector<std::string> possibleTeams = {
        "Real Madrid", "Barcelona", "Manchester City", "Liverpool",
        "Bayern Munich", "PSG", "Juventus", "Chelsea", "Arsenal", "Atletico Madrid"};

    // Select two random teams
    std::uniform_int_distribution<> distr_team(0, possibleTeams.size() - 1);
    teams.clear();

    int team1Index = distr_team(gen);
    teams.push_back(possibleTeams[team1Index]);

    int team2Index;
    do
    {
        team2Index = distr_team(gen);
    } while (team1Index == team2Index);

    teams.push_back(possibleTeams[team2Index]);

    // Add football rules
    rules.clear();
    addRule("Game lasts 90 minutes (two halves of 45 minutes each)");
    addRule("Each team has 11 players");
    addRule("A goal is scored when the ball completely crosses the goal line");
    addRule("The game starts from the center of the field");
}

// Display information
void Football::displayInfo() const
{
    std::cout << "=== Football ===" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Number of players: " << playersCount << std::endl;
    std::cout << "Duration (min): " << duration << std::endl;
    std::cout << "Ball type: " << ballType << std::endl;
    std::cout << "Field dimensions: " << fieldLength << "x" << fieldWidth << " m" << std::endl;
    std::cout << "Field area: " << calculateFieldArea() << " m²" << std::endl;
    std::cout << "Number of goals: " << goalCount << std::endl;

    std::cout << "Teams:" << std::endl;
    if (teams.empty())
    {
        std::cout << "  (Teams not defined)" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < teams.size(); i++)
        {
            std::cout << "  " << (i + 1) << ". " << teams[i] << std::endl;
        }
    }

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

// Overridden method for calculating energy expenditure
double Football::calculateEnergyExpenditure() const
{
    // Football has higher energy expenditure
    // Base calculation: duration * 10 calories per minute
    return duration * 10.0;
}

// Calculate field area
int Football::calculateFieldArea() const
{
    return fieldLength * fieldWidth;
}

// Calculate average number of goals per game
double Football::calculateAverageGoalsPerGame() const
{
    // For simplicity, assume this is the average value for one game
    return static_cast<double>(goalCount);
}

// Simulate match
void Football::simulateMatch()
{
    if (teams.size() < 2)
    {
        std::cout << "At least two teams are needed to simulate a match!" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr_goals(0, 5);

    int team1Goals = distr_goals(gen);
    int team2Goals = distr_goals(gen);
    goalCount = team1Goals + team2Goals;

    std::cout << "Match result:" << std::endl;
    std::cout << teams[0] << " " << team1Goals << " - " << team2Goals << " " << teams[1] << std::endl;

    if (team1Goals > team2Goals)
    {
        std::cout << "Team " << teams[0] << " won!" << std::endl;
    }
    else if (team2Goals > team1Goals)
    {
        std::cout << "Team " << teams[1] << " won!" << std::endl;
    }
    else
    {
        std::cout << "The match ended in a draw!" << std::endl;
    }
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Football &football)
{
    // Call base class operator
    os << static_cast<const SportGame &>(football);

    // Add football-specific fields
    os << football.ballType << "\n";
    os << football.fieldLength << "\n";
    os << football.fieldWidth << "\n";
    os << football.goalCount << "\n";
    os << football.teams.size() << "\n";

    for (const auto &team : football.teams)
    {
        os << team << "\n";
    }

    return os;
}

// Input operator
std::istream &operator>>(std::istream &is, Football &football)
{
    // Call base class operator
    is >> static_cast<SportGame &>(football);

    std::getline(is, football.ballType);
    is >> football.fieldLength;
    is >> football.fieldWidth;
    is >> football.goalCount;

    int teamCount;
    is >> teamCount;
    is.ignore();

    football.teams.clear();
    for (int i = 0; i < teamCount; i++)
    {
        std::string team;
        std::getline(is, team);
        football.teams.push_back(team);
    }

    return is;
}

// Copy assignment operator
Football &Football::operator=(const Football &other)
{
    if (this != &other)
    {
        // Call base class operator
        SportGame::operator=(other);

        // Copy specific fields
        ballType = other.ballType;
        fieldLength = other.fieldLength;
        fieldWidth = other.fieldWidth;
        teams = other.teams;
        goalCount = other.goalCount;

        std::cout << "Football: Assignment operator called for " << name << std::endl;
    }
    return *this;
}

// Move assignment operator
Football &Football::operator=(Football &&other) noexcept
{
    if (this != &other)
    {
        // Call base class operator
        SportGame::operator=(std::move(other));

        // Move specific fields
        ballType = std::move(other.ballType);
        fieldLength = other.fieldLength;
        fieldWidth = other.fieldWidth;
        teams = std::move(other.teams);
        goalCount = other.goalCount;

        // Clear original object
        other.fieldLength = 0;
        other.fieldWidth = 0;
        other.goalCount = 0;

        std::cout << "Football: Move operator called for " << name << std::endl;
    }
    return *this;
}