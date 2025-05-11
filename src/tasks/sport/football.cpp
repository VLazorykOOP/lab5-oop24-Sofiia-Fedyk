#include "football.h"
#include <iostream>
#include <fstream>
#include <random>

// Ініціалізація статичного лічильника об'єктів
int Football::footballObjectCount = 0;

// Конструктор за замовчуванням
Football::Football() 
    : SportGame("Футбол", 22, 90), ballType("Стандартний"), 
      fieldLength(105), fieldWidth(68), goalCount(0) {
    footballObjectCount++;
    
    // Додавання основних правил футболу
    addRule("Гра триває 90 хвилин (два тайми по 45 хвилин)");
    addRule("У кожній команді 11 гравців");
    addRule("Гол зараховується, коли м'яч повністю перетнув лінію воріт");
    
    std::cout << "Football: Створено об'єкт за замовчуванням" << std::endl;
}

// Конструктор з параметрами
Football::Football(const std::string& name, int playersCount, int duration,
                   const std::string& ballType, int fieldLength, int fieldWidth)
    : SportGame(name, playersCount, duration), ballType(ballType),
      fieldLength(fieldLength), fieldWidth(fieldWidth), goalCount(0) {
    footballObjectCount++;
    std::cout << "Football: Створено об'єкт з назвою " << name << std::endl;
}

// Конструктор копіювання
Football::Football(const Football& other)
    : SportGame(other), ballType(other.ballType),
      fieldLength(other.fieldLength), fieldWidth(other.fieldWidth),
      teams(other.teams), goalCount(other.goalCount) {
    footballObjectCount++;
    std::cout << "Football: Створено копію об'єкта " << name << std::endl;
}

// Конструктор перенесення
Football::Football(Football&& other) noexcept
    : SportGame(std::move(other)), ballType(std::move(other.ballType)),
      fieldLength(other.fieldLength), fieldWidth(other.fieldWidth),
      teams(std::move(other.teams)), goalCount(other.goalCount) {
    other.fieldLength = 0;
    other.fieldWidth = 0;
    other.goalCount = 0;
    
    footballObjectCount++;
    std::cout << "Football: Створено об'єкт через перенесення " << name << std::endl;
}

// Деструктор
Football::~Football() {
    footballObjectCount--;
    std::cout << "Football: Знищено об'єкт " << name << std::endl;
}

// Додавання команди
void Football::addTeam(const std::string& team) {
    teams.push_back(team);
}

// Очищення команд
void Football::clearTeams() {
    teams.clear();
}

// Ввід з клавіатури
void Football::inputFromKeyboard() {
    SportGame::inputFromKeyboard();
    
    std::cout << "Введіть тип м'яча: ";
    std::cin.ignore();
    std::getline(std::cin, ballType);
    
    std::cout << "Введіть довжину поля (м): ";
    std::cin >> fieldLength;
    
    std::cout << "Введіть ширину поля (м): ";
    std::cin >> fieldWidth;
    
    std::cout << "Введіть кількість голів: ";
    std::cin >> goalCount;
    
    int teamCount;
    std::cout << "Введіть кількість команд: ";
    std::cin >> teamCount;
    std::cin.ignore();
    
    teams.clear();
    for (int i = 0; i < teamCount; i++) {
        std::string team;
        std::cout << "Команда " << (i + 1) << ": ";
        std::getline(std::cin, team);
        teams.push_back(team);
    }
}

// Ввід з файлу
void Football::inputFromFile(const std::string& filename) {
    SportGame::inputFromFile(filename);
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу " << filename << std::endl;
        return;
    }
    
    // Пропускаємо рядки, які вже були прочитані в базовому класі
    std::string line;
    for (int i = 0; i < 3 + rules.size() + 1; i++) {
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
    for (int i = 0; i < teamCount; i++) {
        std::string team;
        std::getline(file, team);
        teams.push_back(team);
    }
    
    file.close();
}

// Генерація випадкових даних
void Football::generateRandom() {
    // Викликаємо базовий метод для ініціалізації базових полів
    name = "Футбол"; // Перевизначаємо назву після базового методу
    playersCount = 22; // Стандартна кількість гравців у футболі
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Випадкова тривалість матчу (зазвичай 90 хвилин, але може бути продовження)
    std::uniform_int_distribution<> distr_duration(90, 120);
    duration = distr_duration(gen);
    
    // Типи м'ячів
    std::vector<std::string> ballTypes = {
        "Adidas Telstar", "Nike Flight", "Puma Final", "Mitre Delta",
        "Umbro Neo"
    };
    std::uniform_int_distribution<> distr_ball(0, ballTypes.size() - 1);
    ballType = ballTypes[distr_ball(gen)];
    
    // Розміри поля (за стандартами FIFA)
    std::uniform_int_distribution<> distr_length(90, 120);
    std::uniform_int_distribution<> distr_width(45, 90);
    fieldLength = distr_length(gen);
    fieldWidth = distr_width(gen);
    
    // Кількість голів
    std::uniform_int_distribution<> distr_goals(0, 7);
    goalCount = distr_goals(gen);
    
    // Можливі футбольні команди
    std::vector<std::string> possibleTeams = {
        "Реал Мадрид", "Барселона", "Манчестер Сіті", "Ліверпуль",
        "Баварія", "ПСЖ", "Ювентус", "Челсі", "Арсенал", "Атлетіко"
    };
    
    // Вибираємо дві випадкові команди
    std::uniform_int_distribution<> distr_team(0, possibleTeams.size() - 1);
    teams.clear();
    
    int team1Index = distr_team(gen);
    teams.push_back(possibleTeams[team1Index]);
    
    int team2Index;
    do {
        team2Index = distr_team(gen);
    } while (team1Index == team2Index);
    
    teams.push_back(possibleTeams[team2Index]);
    
    // Додаємо правила футболу
    rules.clear();
    addRule("Гра триває 90 хвилин (два тайми по 45 хвилин)");
    addRule("У кожній команді 11 гравців");
    addRule("Гол зараховується, коли м'яч повністю перетнув лінію воріт");
    addRule("Гра починається з центра поля");
}

// Вивід інформації
void Football::displayInfo() const {
    std::cout << "=== Футбол ===" << std::endl;
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Кількість гравців: " << playersCount << std::endl;
    std::cout << "Тривалість (хв): " << duration << std::endl;
    std::cout << "Тип м'яча: " << ballType << std::endl;
    std::cout << "Розміри поля: " << fieldLength << "x" << fieldWidth << " м" << std::endl;
    std::cout << "Площа поля: " << calculateFieldArea() << " м²" << std::endl;
    std::cout << "Кількість голів: " << goalCount << std::endl;
    
    std::cout << "Команди:" << std::endl;
    if (teams.empty()) {
        std::cout << "  (Команди не визначені)" << std::endl;
    } else {
        for (size_t i = 0; i < teams.size(); i++) {
            std::cout << "  " << (i + 1) << ". " << teams[i] << std::endl;
        }
    }
    
    std::cout << "Правила:" << std::endl;
    if (rules.empty()) {
        std::cout << "  (Правила не визначені)" << std::endl;
    } else {
        for (size_t i = 0; i < rules.size(); i++) {
            std::cout << "  " << (i + 1) << ". " << rules[i] << std::endl;
        }
    }
}

// Перевизначений метод розрахунку енергетичних витрат
double Football::calculateEnergyExpenditure() const {
    // Футбол має вищі енергетичні витрати
    // Базовий розрахунок: тривалість * 10 калорій за хвилину
    return duration * 10.0;
}

// Розрахунок площі поля
int Football::calculateFieldArea() const {
    return fieldLength * fieldWidth;
}

// Розрахунок середньої кількості голів за гру
double Football::calculateAverageGoalsPerGame() const {
    // Для простоти припустимо, що це середнє значення за одну гру
    return static_cast<double>(goalCount);
}

// Симуляція матчу
void Football::simulateMatch() {
    if (teams.size() < 2) {
        std::cout << "Для симуляції матчу потрібно щонайменше дві команди!" << std::endl;
        return;
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr_goals(0, 5);
    
    int team1Goals = distr_goals(gen);
    int team2Goals = distr_goals(gen);
    goalCount = team1Goals + team2Goals;
    
    std::cout << "Результат матчу:" << std::endl;
    std::cout << teams[0] << " " << team1Goals << " - " << team2Goals << " " << teams[1] << std::endl;
    
    if (team1Goals > team2Goals) {
        std::cout << "Перемогла команда " << teams[0] << "!" << std::endl;
    } else if (team2Goals > team1Goals) {
        std::cout << "Перемогла команда " << teams[1] << "!" << std::endl;
    } else {
        std::cout << "Матч завершився нічиєю!" << std::endl;
    }
}

// Оператор виводу
std::ostream& operator<<(std::ostream& os, const Football& football) {
    // Викликаємо оператор базового класу
    os << static_cast<const SportGame&>(football);
    
    // Додаємо специфічні поля футболу
    os << football.ballType << "\n";
    os << football.fieldLength << "\n";
    os << football.fieldWidth << "\n";
    os << football.goalCount << "\n";
    os << football.teams.size() << "\n";
    
    for (const auto& team : football.teams) {
        os << team << "\n";
    }
    
    return os;
}

// Оператор вводу
std::istream& operator>>(std::istream& is, Football& football) {
    // Викликаємо оператор базового класу
    is >> static_cast<SportGame&>(football);
    
    std::getline(is, football.ballType);
    is >> football.fieldLength;
    is >> football.fieldWidth;
    is >> football.goalCount;
    
    int teamCount;
    is >> teamCount;
    is.ignore();
    
    football.teams.clear();
    for (int i = 0; i < teamCount; i++) {
        std::string team;
        std::getline(is, team);
        football.teams.push_back(team);
    }
    
    return is;
}

// Оператор присвоювання копіюванням
Football& Football::operator=(const Football& other) {
    if (this != &other) {
        // Викликаємо оператор базового класу
        SportGame::operator=(other);
        
        // Копіюємо специфічні поля
        ballType = other.ballType;
        fieldLength = other.fieldLength;
        fieldWidth = other.fieldWidth;
        teams = other.teams;
        goalCount = other.goalCount;
        
        std::cout << "Football: Викликано оператор присвоювання для " << name << std::endl;
    }
    return *this;
}

// Оператор присвоювання перенесенням
Football& Football::operator=(Football&& other) noexcept {
    if (this != &other) {
        // Викликаємо оператор базового класу
        SportGame::operator=(std::move(other));
        
        // Переносимо специфічні поля
        ballType = std::move(other.ballType);
        fieldLength = other.fieldLength;
        fieldWidth = other.fieldWidth;
        teams = std::move(other.teams);
        goalCount = other.goalCount;
        
        // Очищаємо оригінальний об'єкт
        other.fieldLength = 0;
        other.fieldWidth = 0;
        other.goalCount = 0;
        
        std::cout << "Football: Викликано оператор перенесення для " << name << std::endl;
    }
    return *this;
}