#include "sport_game.h"
#include "football.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

// Функція для створення тестового файлу
void createTestFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка створення тестового файлу!" << std::endl;
        return;
    }
    
    // Дані для базового класу SportGame
    file << "Волейбол\n";
    file << "12\n";
    file << "60\n";
    file << "3\n";
    file << "Гра двома командами через сітку\n";
    file << "У кожній команді 6 гравців\n";
    file << "Очко зараховується, коли м'яч торкається поля суперника\n";
    
    // Дані для класу Football
    file << "М'яч Adidas\n";
    file << "105\n";
    file << "68\n";
    file << "3\n";
    file << "2\n";
    file << "Динамо Київ\n";
    file << "Шахтар Донецьк\n";
    
    file.close();
}

// Функція для тестування базового класу SportGame
void testSportGame() {
    std::cout << "\n----- Тестування класу SportGame -----\n" << std::endl;
    
    // Створення об'єкта за замовчуванням
    SportGame game1;
    assert(game1.getName() == "Невідома гра");
    assert(game1.getPlayersCount() == 0);
    assert(game1.getDuration() == 0);
    game1.displayInfo();
    
    // Створення об'єкта з параметрами
    SportGame game2("Баскетбол", 10, 48);
    assert(game2.getName() == "Баскетбол");
    assert(game2.getPlayersCount() == 10);
    assert(game2.getDuration() == 48);
    game2.displayInfo();
    
    // Тестування додавання правил
    game2.addRule("Гра м'ячем у кошик");
    game2.addRule("У кожній команді 5 гравців");
    game2.displayInfo();
    assert(game2.getRules().size() == 2);
    
    // Тестування копіювання
    SportGame game3 = game2;
    assert(game3.getName() == "Баскетбол");
    assert(game3.getPlayersCount() == 10);
    assert(game3.getDuration() == 48);
    assert(game3.getRules().size() == 2);
    
    // Тестування присвоювання
    SportGame game4;
    game4 = game2;
    assert(game4.getName() == "Баскетбол");
    assert(game4.getPlayersCount() == 10);
    assert(game4.getDuration() == 48);
    assert(game4.getRules().size() == 2);
    
    // Тестування очищення правил
    game4.clearRules();
    assert(game4.getRules().empty());
    
    // Тестування розрахунку енергетичних витрат
    double energy = game2.calculateEnergyExpenditure();
    std::cout << "Енергетичні витрати для " << game2.getName() << ": " << energy << " калорій" << std::endl;
    assert(energy == 48 * 5.0);
    
    // Тестування операторів введення/виведення через файл
    std::ofstream outFile("sport_game_test.txt");
    outFile << game2;
    outFile.close();
    
    SportGame game5;
    std::ifstream inFile("sport_game_test.txt");
    inFile >> game5;
    inFile.close();
    
    assert(game5.getName() == "Баскетбол");
    assert(game5.getPlayersCount() == 10);
    assert(game5.getDuration() == 48);
    assert(game5.getRules().size() == 2);
    
    // Тестування переміщення
    SportGame game6 = std::move(game5);
    assert(game6.getName() == "Баскетбол");
    assert(game6.getPlayersCount() == 10);
    assert(game6.getDuration() == 48);
    
    // Генерація випадкових даних
    SportGame game7;
    game7.generateRandom();
    game7.displayInfo();
    
    std::cout << "Загальна кількість об'єктів SportGame: " << SportGame::getObjectCount() << std::endl;
}

// Функція для тестування похідного класу Football
void testFootball() {
    std::cout << "\n----- Тестування класу Football -----\n" << std::endl;
    
    // Створення об'єкта за замовчуванням
    Football football1;
    assert(football1.getName() == "Футбол");
    assert(football1.getPlayersCount() == 22);
    assert(football1.getDuration() == 90);
    assert(football1.getBallType() == "Стандартний");
    assert(football1.getFieldLength() == 105);
    assert(football1.getFieldWidth() == 68);
    football1.displayInfo();
    
    // Створення об'єкта з параметрами
    Football football2("Міні-футбол", 10, 40, "Futsal", 40, 20);
    assert(football2.getName() == "Міні-футбол");
    assert(football2.getPlayersCount() == 10);
    assert(football2.getDuration() == 40);
    assert(football2.getBallType() == "Futsal");
    assert(football2.getFieldLength() == 40);
    assert(football2.getFieldWidth() == 20);
    football2.displayInfo();
    
    // Тестування додавання команд
    football2.addTeam("Команда A");
    football2.addTeam("Команда B");
    assert(football2.getTeams().size() == 2);
    
    // Тестування копіювання
    Football football3 = football2;
    assert(football3.getName() == "Міні-футбол");
    assert(football3.getPlayersCount() == 10);
    assert(football3.getDuration() == 40);
    assert(football3.getBallType() == "Futsal");
    assert(football3.getFieldLength() == 40);
    assert(football3.getFieldWidth() == 20);
    assert(football3.getTeams().size() == 2);
    
    // Тестування присвоювання
    Football football4;
    football4 = football2;
    assert(football4.getName() == "Міні-футбол");
    assert(football4.getPlayersCount() == 10);
    assert(football4.getDuration() == 40);
    assert(football4.getBallType() == "Futsal");
    assert(football4.getFieldLength() == 40);
    assert(football4.getFieldWidth() == 20);
    assert(football4.getTeams().size() == 2);
    
    // Тестування специфічних методів футболу
    int area = football2.calculateFieldArea();
    std::cout << "Площа поля: " << area << " м²" << std::endl;
    assert(area == 40 * 20);
    
    // Встановлення голів та тестування середньої кількості
    football2.setGoalCount(5);
    double avgGoals = football2.calculateAverageGoalsPerGame();
    std::cout << "Середня кількість голів за гру: " << avgGoals << std::endl;
    assert(avgGoals == 5.0);
    
    // Тестування симуляції матчу
    std::cout << "\nСимуляція матчу:" << std::endl;
    football2.simulateMatch();
    
    // Тестування перевизначеного методу розрахунку енергетичних витрат
    double energy = football2.calculateEnergyExpenditure();
    std::cout << "Енергетичні витрати для " << football2.getName() << ": " << energy << " калорій" << std::endl;
    assert(energy == 40 * 10.0);
    
    // Тестування операторів введення/виведення через файл
    std::ofstream outFile("football_test.txt");
    outFile << football2;
    outFile.close();
    
    Football football5;
    std::ifstream inFile("football_test.txt");
    inFile >> football5;
    inFile.close();
    
    assert(football5.getName() == "Міні-футбол");
    assert(football5.getPlayersCount() == 10);
    assert(football5.getDuration() == 40);
    assert(football5.getBallType() == "Futsal");
    assert(football5.getFieldLength() == 40);
    assert(football5.getFieldWidth() == 20);
    
    // Тестування переміщення
    Football football6 = std::move(football5);
    assert(football6.getName() == "Міні-футбол");
    assert(football6.getPlayersCount() == 10);
    assert(football6.getDuration() == 40);
    assert(football6.getBallType() == "Futsal");
    
    // Генерація випадкових даних
    Football football7;
    football7.generateRandom();
    football7.displayInfo();
    
    // Тестування введення з файлу
    createTestFile("football_data.txt");
    Football football8;
    football8.inputFromFile("football_data.txt");
    football8.displayInfo();
    
    std::cout << "Загальна кількість об'єктів Football: " << Football::getFootballObjectCount() << std::endl;
}

// Тестування ієрархії класів через поліморфізм
void testPolymorphism() {
    std::cout << "\n----- Тестування поліморфізму -----\n" << std::endl;
    
    // Створення об'єктів
    SportGame* baseGame = new SportGame("Гандбол", 14, 60);
    baseGame->addRule("Гра руками");
    baseGame->addRule("Можна блокувати суперника тілом");
    
    SportGame* footballGame = new Football("Чемпіонат світу з футболу", 22, 90, "Adidas", 105, 68);
    footballGame->addRule("Заборонено торкатися м'яча руками (крім воротаря)");
    
    // Виклик віртуальних методів
    std::cout << "Базова гра:" << std::endl;
    baseGame->displayInfo();
    double baseEnergy = baseGame->calculateEnergyExpenditure();
    std::cout << "Енергетичні витрати: " << baseEnergy << " калорій" << std::endl;
    
    std::cout << "\nФутбол (через вказівник на базовий клас):" << std::endl;
    footballGame->displayInfo();
    double footballEnergy = footballGame->calculateEnergyExpenditure();
    std::cout << "Енергетичні витрати: " << footballEnergy << " калорій" << std::endl;
    
    // Звільнення пам'яті
    delete baseGame;
    delete footballGame;
}

// Функція для демонстрації введення з клавіатури
void testKeyboardInput() {
    std::cout << "\n----- Тестування введення з клавіатури -----\n" << std::endl;
    std::cout << "Введення даних для спортивної гри:" << std::endl;
    
    SportGame game;
    game.inputFromKeyboard();
    game.displayInfo();
    
    std::cout << "\nВведення даних для футболу:" << std::endl;
    Football football;
    football.inputFromKeyboard();
    football.displayInfo();
}

// Основна функція для запуску всіх тестів
void runAllTests() {
    // Виводимо загальну інформацію перед тестуванням
    std::cout << "=== Тестування ієрархії класів спортивна гра та футбол ===" << std::endl;
    
    // Запускаємо тести для базового класу
    testSportGame();
    
    // Запускаємо тести для похідного класу
    testFootball();
    
    // Тестування поліморфізму
    testPolymorphism();
    
    // Для активного тестування можна розкоментувати цей виклик
    // testKeyboardInput();
    
    std::cout << "\n=== Всі тести успішно завершені ===" << std::endl;
}