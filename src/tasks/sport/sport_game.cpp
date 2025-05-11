#include "sport_game.h"
#include <iostream>
#include <fstream>
#include <random>
#include <limits>

// Ініціалізація статичного лічильника об'єктів
int SportGame::objectCount = 0;

// Конструктор за замовчуванням
SportGame::SportGame() : name("Невідома гра"), playersCount(0), duration(0) {
    objectCount++;
    std::cout << "SportGame: Створено об'єкт за замовчуванням" << std::endl;
}

// Конструктор з параметрами
SportGame::SportGame(const std::string& name, int playersCount, int duration)
    : name(name), playersCount(playersCount), duration(duration) {
    objectCount++;
    std::cout << "SportGame: Створено об'єкт з назвою " << name << std::endl;
}

// Конструктор копіювання
SportGame::SportGame(const SportGame& other)
    : name(other.name), playersCount(other.playersCount), 
      duration(other.duration), rules(other.rules) {
    objectCount++;
    std::cout << "SportGame: Створено копію об'єкта " << name << std::endl;
}

// Конструктор перенесення
SportGame::SportGame(SportGame&& other) noexcept
    : name(std::move(other.name)), 
      playersCount(other.playersCount),
      duration(other.duration),
      rules(std::move(other.rules)) {
    other.playersCount = 0;
    other.duration = 0;
    objectCount++;
    std::cout << "SportGame: Створено об'єкт через перенесення " << name << std::endl;
}

// Деструктор
SportGame::~SportGame() {
    objectCount--;
    std::cout << "SportGame: Знищено об'єкт " << name << std::endl;
}

// Додавання правила
void SportGame::addRule(const std::string& rule) {
    rules.push_back(rule);
}

// Очищення правил
void SportGame::clearRules() {
    rules.clear();
}

// Ввід з клавіатури
void SportGame::inputFromKeyboard() {
    std::cout << "Введіть назву гри: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "Введіть кількість гравців: ";
    std::cin >> playersCount;
    
    std::cout << "Введіть тривалість гри (хв): ";
    std::cin >> duration;
    
    int rulesCount;
    std::cout << "Введіть кількість правил: ";
    std::cin >> rulesCount;
    std::cin.ignore();
    
    rules.clear();
    for (int i = 0; i < rulesCount; i++) {
        std::string rule;
        std::cout << "Правило " << (i + 1) << ": ";
        std::getline(std::cin, rule);
        rules.push_back(rule);
    }
}

// Ввід з файлу
void SportGame::inputFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу " << filename << std::endl;
        return;
    }
    
    std::getline(file, name);
    file >> playersCount;
    file >> duration;
    
    int rulesCount;
    file >> rulesCount;
    file.ignore();
    
    rules.clear();
    for (int i = 0; i < rulesCount; i++) {
        std::string rule;
        std::getline(file, rule);
        rules.push_back(rule);
    }
    
    file.close();
}

// Генерація випадкових даних
void SportGame::generateRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr_players(2, 30);
    std::uniform_int_distribution<> distr_duration(10, 180);
    
    std::vector<std::string> possibleNames = {
        "Баскетбол", "Волейбол", "Гандбол", "Теніс", "Бадмінтон",
        "Хокей", "Регбі", "Бейсбол", "Крикет", "Водне поло"
    };
    
    std::uniform_int_distribution<> distr_name(0, possibleNames.size() - 1);
    name = possibleNames[distr_name(gen)];
    
    playersCount = distr_players(gen);
    duration = distr_duration(gen);
    
    std::vector<std::string> possibleRules = {
        "Грати чесно", "Поважати арбітра", "Не вживати допінг",
        "Не допускати фізичної агресії", "Дотримуватись спортивного етикету"
    };
    
    std::uniform_int_distribution<> distr_rules_count(1, 3);
    int rulesCount = distr_rules_count(gen);
    
    rules.clear();
    for (int i = 0; i < rulesCount; i++) {
        std::uniform_int_distribution<> distr_rule(0, possibleRules.size() - 1);
        rules.push_back(possibleRules[distr_rule(gen)]);
    }
}

// Вивід інформації
void SportGame::displayInfo() const {
    std::cout << "=== Спортивна гра ===" << std::endl;
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Кількість гравців: " << playersCount << std::endl;
    std::cout << "Тривалість (хв): " << duration << std::endl;
    std::cout << "Правила:" << std::endl;
    
    if (rules.empty()) {
        std::cout << "  (Правила не визначені)" << std::endl;
    } else {
        for (size_t i = 0; i < rules.size(); i++) {
            std::cout << "  " << (i + 1) << ". " << rules[i] << std::endl;
        }
    }
}

// Розрахунок енергетичних витрат (базова формула)
double SportGame::calculateEnergyExpenditure() const {
    // Спрощена формула: тривалість гри * 5 калорій за хвилину
    return duration * 5.0;
}

// Оператор виводу
std::ostream& operator<<(std::ostream& os, const SportGame& game) {
    os << game.name << "\n";
    os << game.playersCount << "\n";
    os << game.duration << "\n";
    os << game.rules.size() << "\n";
    
    for (const auto& rule : game.rules) {
        os << rule << "\n";
    }
    
    return os;
}

// Оператор вводу
std::istream& operator>>(std::istream& is, SportGame& game) {
    std::getline(is, game.name);
    is >> game.playersCount;
    is >> game.duration;
    
    int rulesCount;
    is >> rulesCount;
    is.ignore();
    
    game.rules.clear();
    for (int i = 0; i < rulesCount; i++) {
        std::string rule;
        std::getline(is, rule);
        game.rules.push_back(rule);
    }
    
    return is;
}

// Оператор присвоювання копіюванням
SportGame& SportGame::operator=(const SportGame& other) {
    if (this != &other) {
        name = other.name;
        playersCount = other.playersCount;
        duration = other.duration;
        rules = other.rules;
        std::cout << "SportGame: Викликано оператор присвоювання для " << name << std::endl;
    }
    return *this;
}

// Оператор присвоювання перенесенням
SportGame& SportGame::operator=(SportGame&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        playersCount = other.playersCount;
        duration = other.duration;
        rules = std::move(other.rules);
        
        other.playersCount = 0;
        other.duration = 0;
        
        std::cout << "SportGame: Викликано оператор перенесення для " << name << std::endl;
    }
    return *this;
}