#include <iostream>
#include <string>
#include <limits>

// Включаємо всі необхідні заголовочні файли
#include "apartment_classes.h"
#include "student_classes.h"
#include "sport/football.h"

// Функція для очищення буфера введення
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Функції для тестування класів апартаментів
void testRoom() {
    std::cout << "\n===== TESTING ROOM CLASS =====\n";
    
    std::cout << "\n-- Testing constructors and basic methods\n";
    Room room1;
    Room room2(25.5);
    Room room3(room2);
    
    std::cout << "\n-- Testing getters and setters\n";
    std::cout << "Room 1 area: " << room1.getArea() << " m²\n";
    std::cout << "Room 2 area: " << room2.getArea() << " m²\n";
    room1.setArea(15.3);
    std::cout << "Room 1 area after update: " << room1.getArea() << " m²\n";
    
    std::cout << "\n-- Testing print method\n";
    room1.printInfo();
    
    std::cout << "\n-- Testing static method\n";
    std::cout << "Minimum standard room area: " << Room::calculateMinimumStandardArea() << " m²\n";
    
    std::cout << "\n-- Testing input methods\n";
    Room inputRoom;
    int inputChoice;
    std::cout << "Choose input method:\n";
    std::cout << "1. Keyboard\n";
    std::cout << "2. File\n";
    std::cout << "3. Random generation\n";
    std::cout << "Your choice: ";
    std::cin >> inputChoice;
    
    switch (inputChoice) {
        case 1:
            inputFromKeyboard(inputRoom);
            break;
        case 2: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            inputFromFile(inputRoom, filename);
            break;
        }
        case 3:
            generateRandom(inputRoom, 10.0, 50.0);
            break;
        default:
            std::cout << "Invalid choice. Using random generation.\n";
            generateRandom(inputRoom, 10.0, 50.0);
    }
    
    std::cout << "\n-- Room from input:\n";
    inputRoom.printInfo();
}

void testOneRoomApartment() {
    std::cout << "\n===== TESTING ONE-ROOM APARTMENT CLASS =====\n";
    
    std::cout << "\n-- Testing constructors and basic methods\n";
    OneRoomApartment apt1;
    OneRoomApartment apt2(24.0, 8.0, 3);
    Room room(18.5);
    OneRoomApartment apt3(room, 7.5, 5);
    OneRoomApartment apt4(apt2);
    
    std::cout << "\n-- Testing getters and setters\n";
    std::cout << "Apartment 2 room area: " << apt2.getRoom().getArea() << " m²\n";
    std::cout << "Apartment 2 kitchen area: " << apt2.getKitchenArea() << " m²\n";
    std::cout << "Apartment 2 floor: " << apt2.getFloor() << "\n";
    std::cout << "Apartment 2 total area: " << apt2.getTotalArea() << " m²\n";
    
    Room newRoom(30.0);
    apt1.setRoom(newRoom);
    apt1.setKitchenArea(10.0);
    apt1.setFloor(2);
    
    std::cout << "\n-- Testing print method\n";
    apt1.printInfo();
    
    std::cout << "\n-- Testing static method\n";
    std::cout << "Minimum standard kitchen area: " << OneRoomApartment::calculateMinimumKitchenArea() << " m²\n";
    
    std::cout << "\n-- Testing input methods\n";
    OneRoomApartment inputApt;
    int inputChoice;
    std::cout << "Choose input method:\n";
    std::cout << "1. Keyboard\n";
    std::cout << "2. File\n";
    std::cout << "3. Random generation\n";
    std::cout << "Your choice: ";
    std::cin >> inputChoice;
    
    switch (inputChoice) {
        case 1:
            inputFromKeyboard(inputApt);
            break;
        case 2: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            inputFromFile(inputApt, filename);
            break;
        }
        case 3:
            generateRandom(inputApt, 15.0, 40.0, 5.0, 15.0, 1, 9);
            break;
        default:
            std::cout << "Invalid choice. Using random generation.\n";
            generateRandom(inputApt, 15.0, 40.0, 5.0, 15.0, 1, 9);
    }
    
    std::cout << "\n-- Apartment from input:\n";
    inputApt.printInfo();
}

void testCityOneRoomApartment() {
    std::cout << "\n===== TESTING CITY ONE-ROOM APARTMENT CLASS =====\n";
    
    std::cout << "\n-- Testing constructors and basic methods\n";
    CityOneRoomApartment cityApt1;
    CityOneRoomApartment cityApt2(28.0, 9.0, 4, "Kyiv");
    Room room(20.0);
    CityOneRoomApartment cityApt3(room, 8.0, 2, "Lviv");
    OneRoomApartment apt(22.0, 7.0, 3);
    CityOneRoomApartment cityApt4(apt, "Odesa");
    CityOneRoomApartment cityApt5(cityApt2);
    
    std::cout << "\n-- Testing getters and setters\n";
    std::cout << "City apartment 2 city: " << cityApt2.getCityName() << "\n";
    cityApt1.setCityName("Kharkiv");
    std::cout << "City apartment 1 city after update: " << cityApt1.getCityName() << "\n";
    
    std::cout << "\n-- Testing print method\n";
    cityApt2.printInfo();
    
    std::cout << "\n-- Testing static method\n";
    std::cout << "Most popular city: " << CityOneRoomApartment::getPopularCity() << "\n";
    
    std::cout << "\n-- Testing input methods\n";
    CityOneRoomApartment inputCityApt;
    int inputChoice;
    std::cout << "Choose input method:\n";
    std::cout << "1. Keyboard\n";
    std::cout << "2. File\n";
    std::cout << "3. Random generation\n";
    std::cout << "Your choice: ";
    std::cin >> inputChoice;
    
    switch (inputChoice) {
        case 1:
            inputFromKeyboard(inputCityApt);
            break;
        case 2: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            inputFromFile(inputCityApt, filename);
            break;
        }
        case 3:
            generateRandom(inputCityApt, 15.0, 40.0, 5.0, 15.0, 1, 9);
            break;
        default:
            std::cout << "Invalid choice. Using random generation.\n";
            generateRandom(inputCityApt, 15.0, 40.0, 5.0, 15.0, 1, 9);
    }
    
    std::cout << "\n-- City apartment from input:\n";
    inputCityApt.printInfo();
}

// Функції для тестування класів студентів
void testStudent() {
    std::cout << "\n===== TESTING STUDENT CLASS =====\n";
    
    std::cout << "\n-- Testing constructors and basic methods\n";
    Student student1;
    Student student2("Shevchenko", "Taras", "Hryhorovych", 2, "ID123456");
    Student student3(student2);
    
    std::cout << "\n-- Testing print method\n";
    student2.print();
    
    std::cout << "\n-- Testing static method\n";
    std::cout << "Random ID: " << Student::generateRandomId() << "\n";
    
    std::cout << "\n-- Testing input methods\n";
    Student inputStudent;
    int inputChoice;
    std::cout << "Choose input method:\n";
    std::cout << "1. Keyboard\n";
    std::cout << "2. File\n";
    std::cout << "3. Random generation\n";
    std::cout << "Your choice: ";
    std::cin >> inputChoice;
    
    switch (inputChoice) {
        case 1:
            inputStudent.inputFromKeyboard();
            break;
        case 2: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            std::ifstream fin(filename);
            if (fin.is_open()) {
                inputStudent.inputFromFile(fin);
                fin.close();
            } else {
                std::cout << "Error opening file. Using random generation.\n";
                inputStudent.generateRandom();
            }
            break;
        }
        case 3:
            inputStudent.generateRandom();
            break;
        default:
            std::cout << "Invalid choice. Using random generation.\n";
            inputStudent.generateRandom();
    }
    
    std::cout << "\n-- Student from input:\n";
    inputStudent.print();
}

void testGraduateStudent() {
    std::cout << "\n===== TESTING GRADUATE STUDENT CLASS =====\n";
    
    std::cout << "\n-- Testing constructors and basic methods\n";
    GraduateStudent gradStudent1;
    GraduateStudent gradStudent2("Kovalenko", "Ivan", "Petrovych", 4, "ID789012", "Machine Learning Applications");
    Student student("Melnyk", "Olena", "Ivanivna", 5, "ID345678");
    GraduateStudent gradStudent3(student, "Computer Vision Systems");
    GraduateStudent gradStudent4(gradStudent2);
    
    std::cout << "\n-- Testing specialized methods\n";
    gradStudent2.changeThesisTitle("Advanced Neural Networks");
    gradStudent2.changeIdNumber("ID999999");
    
    std::cout << "\n-- Testing print method\n";
    gradStudent2.print();
    
    std::cout << "\n-- Testing input methods\n";
    GraduateStudent inputGradStudent;
    int inputChoice;
    std::cout << "Choose input method:\n";
    std::cout << "1. Keyboard\n";
    std::cout << "2. File\n";
    std::cout << "3. Random generation\n";
    std::cout << "Your choice: ";
    std::cin >> inputChoice;
    
    switch (inputChoice) {
        case 1:
            inputGradStudent.inputFromKeyboard();
            break;
        case 2: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            std::ifstream fin(filename);
            if (fin.is_open()) {
                inputGradStudent.inputFromFile(fin);
                fin.close();
            } else {
                std::cout << "Error opening file. Using random generation.\n";
                inputGradStudent.generateRandom();
            }
            break;
        }
        case 3:
            inputGradStudent.generateRandom();
            break;
        default:
            std::cout << "Invalid choice. Using random generation.\n";
            inputGradStudent.generateRandom();
    }
    
    std::cout << "\n-- Graduate student from input:\n";
    inputGradStudent.print();
}

// Функції для тестування класів спортивних ігор
void testSportGame() {
    std::cout << "\n===== TESTING SPORT GAME CLASS =====\n";
    
    std::cout << "\n-- Testing constructors and basic methods\n";
    SportGame game1;
    SportGame game2("Basketball", 10, 48);
    SportGame game3(game2);
    SportGame game4 = std::move(SportGame("Chess", 2, 180));
    
    std::cout << "\n-- Testing rule methods\n";
    game2.addRule("No stepping on the lines");
    game2.addRule("Ball must be dribbled when moving");
    
    std::cout << "\n-- Testing static method\n";
    std::cout << "Current object count: " << SportGame::getObjectCount() << "\n";
    
    std::cout << "\n-- Testing methods\n";
    std::cout << "Energy expenditure: " << game2.calculateEnergyExpenditure() << " calories\n";
    
    std::cout << "\n-- Testing display method\n";
    game2.displayInfo();
    
    std::cout << "\n-- Testing input methods\n";
    SportGame inputGame;
    int inputChoice;
    std::cout << "Choose input method:\n";
    std::cout << "1. Keyboard\n";
    std::cout << "2. File\n";
    std::cout << "3. Random generation\n";
    std::cout << "Your choice: ";
    std::cin >> inputChoice;
    
    switch (inputChoice) {
        case 1:
            inputGame.inputFromKeyboard();
            break;
        case 2: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            inputGame.inputFromFile(filename);
            break;
        }
        case 3:
            inputGame.generateRandom();
            break;
        default:
            std::cout << "Invalid choice. Using random generation.\n";
            inputGame.generateRandom();
    }
    
    std::cout << "\n-- Sport game from input:\n";
    inputGame.displayInfo();
}

void testFootball() {
    std::cout << "\n===== TESTING FOOTBALL CLASS =====\n";
    
    std::cout << "\n-- Testing constructors and basic methods\n";
    Football football1;
    Football football2("European Football", 22, 90, "Premier League Ball", 105, 68);
    Football football3(football2);
    Football football4 = std::move(Football("Indoor Football", 10, 40, "Small Ball", 40, 20));
    
    std::cout << "\n-- Testing team methods\n";
    football2.addTeam("Manchester United");
    football2.addTeam("Liverpool");
    
    std::cout << "\n-- Testing static method\n";
    std::cout << "Football object count: " << Football::getFootballObjectCount() << "\n";
    
    std::cout << "\n-- Testing specialized methods\n";
    std::cout << "Field area: " << football2.calculateFieldArea() << " m²\n";
    std::cout << "Average goals per game: " << football2.calculateAverageGoalsPerGame() << "\n";
    std::cout << "Energy expenditure: " << football2.calculateEnergyExpenditure() << " calories\n";
    
    std::cout << "\n-- Testing match simulation\n";
    football2.simulateMatch();
    
    std::cout << "\n-- Testing display method\n";
    football2.displayInfo();
    
    std::cout << "\n-- Testing input methods\n";
    Football inputFootball;
    int inputChoice;
    std::cout << "Choose input method:\n";
    std::cout << "1. Keyboard\n";
    std::cout << "2. File\n";
    std::cout << "3. Random generation\n";
    std::cout << "Your choice: ";
    std::cin >> inputChoice;
    
    switch (inputChoice) {
        case 1:
            inputFootball.inputFromKeyboard();
            break;
        case 2: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            inputFootball.inputFromFile(filename);
            break;
        }
        case 3:
            inputFootball.generateRandom();
            break;
        default:
            std::cout << "Invalid choice. Using random generation.\n";
            inputFootball.generateRandom();
    }
    
    std::cout << "\n-- Football from input:\n";
    inputFootball.displayInfo();
}

// Головне меню
void displayMainMenu() {
    std::cout << "\n======= MAIN MENU =======\n";
    std::cout << "1. Test Room class\n";
    std::cout << "2. Test OneRoomApartment class\n";
    std::cout << "3. Test CityOneRoomApartment class\n";
    std::cout << "4. Test Student class\n";
    std::cout << "5. Test GraduateStudent class\n";
    std::cout << "6. Test SportGame class\n";
    std::cout << "7. Test Football class\n";
    std::cout << "8. Exit\n";
    std::cout << "========================\n";
    std::cout << "Enter your choice: ";
}

void clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pauseConsole()
{
	std::cout << "\nPress any key to continue...\n";
	getchar();
	getchar();
	clearConsole();
}

int main() {
    int choice = 0;
    
    while (choice != 8) {
        clearConsole();

        displayMainMenu();
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                testRoom();
                break;
            case 2:
                testOneRoomApartment();
                break;
            case 3:
                testCityOneRoomApartment();
                break;
            case 4:
                testStudent();
                break;
            case 5:
                testGraduateStudent();
                break;
            case 6:
                testSportGame();
                break;
            case 7:
                testFootball();
                break;
            case 8:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        pauseConsole();
    }
    
    return 0;
}
