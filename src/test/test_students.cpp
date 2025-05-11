#include "student_classes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

// Функція для тестування конструкторів і деструкторів
void testConstructorsAndDestructors() {
    std::cout << "\n=== Тестування конструкторів і деструкторів ===\n";
    
    // Тестування конструктора за замовчуванням
    std::cout << "\nСтворення студента за замовчуванням:\n";
    Student student1;
    student1.print();
    
    // Тестування конструктора з параметрами
    std::cout << "\nСтворення студента з параметрами:\n";
    Student student2("Петренко", "Петро", "Петрович", 3, "ID1234567");
    student2.print();
    
    // Тестування конструктора копіювання
    std::cout << "\nСтворення копії студента:\n";
    Student student3(student2);
    student3.print();
    
    // Тестування конструктора за замовчуванням для студента-дипломника
    std::cout << "\nСтворення студента-дипломника за замовчуванням:\n";
    GraduateStudent gradStudent1;
    gradStudent1.print();
    
    // Тестування конструктора з параметрами для студента-дипломника
    std::cout << "\nСтворення студента-дипломника з параметрами:\n";
    GraduateStudent gradStudent2("Іваненко", "Іван", "Іванович", 5, "ID7654321", 
                               "Розробка системи штучного інтелекту");
    gradStudent2.print();
    
    // Тестування конструктора на основі студента
    std::cout << "\nСтворення студента-дипломника на основі звичайного студента:\n";
    GraduateStudent gradStudent3(student2, "Аналіз великих даних");
    gradStudent3.print();
    
    // Тестування конструктора копіювання для студента-дипломника
    std::cout << "\nСтворення копії студента-дипломника:\n";
    GraduateStudent gradStudent4(gradStudent2);
    gradStudent4.print();
    
    std::cout << "\nВиклик деструкторів (при виході з функції)...\n";
    // Тут всі створені об'єкти будуть автоматично знищені при виході з функції
}

// Функція для тестування методів введення з клавіатури
void testInputFromKeyboard() {
    std::cout << "\n=== Тестування введення даних з клавіатури ===\n";
    
    std::cout << "\nВведення даних для звичайного студента:\n";
    Student student;
    student.inputFromKeyboard();
    std::cout << "\nВведені дані:\n";
    student.print();
    
    std::cout << "\nВведення даних для студента-дипломника:\n";
    GraduateStudent gradStudent;
    gradStudent.inputFromKeyboard();
    std::cout << "\nВведені дані:\n";
    gradStudent.print();
}

// Функція для тестування методів введення з файлу
void testInputFromFile() {
    std::cout << "\n=== Тестування введення даних з файлу ===\n";
    
    // Створення тестового файлу з даними
    {
        std::ofstream fout("student_data.txt");
        if (!fout.is_open()) {
            std::cerr << "Помилка створення файлу даних!" << std::endl;
            return;
        }
        
        // Записуємо дані для звичайного студента
        fout << "Коваленко Марія Олександрівна 2 ID2345678\n";
        
        // Записуємо дані для студента-дипломника
        fout << "Шевченко Тарас Григорович 6 ID8765432\n";
        fout << "Дослідження методів оптимізації роботи нейронних мереж\n";
        
        fout.close();
    }
    
    // Відкриваємо файл для читання
    std::ifstream fin("student_data.txt");
    if (!fin.is_open()) {
        std::cerr << "Помилка відкриття файлу даних!" << std::endl;
        return;
    }
    
    // Зчитуємо дані звичайного студента
    Student student;
    student.inputFromFile(fin);
    std::cout << "\nДані студента з файлу:\n";
    student.print();
    
    // Зчитуємо дані студента-дипломника
    GraduateStudent gradStudent;
    gradStudent.inputFromFile(fin);
    std::cout << "\nДані студента-дипломника з файлу:\n";
    gradStudent.print();
    
    fin.close();
}

// Функція для тестування генерації випадкових даних
void testRandomGeneration() {
    std::cout << "\n=== Тестування генерації випадкових даних ===\n";
    
    // Створюємо вектор студентів і заповнюємо випадковими даними
    std::vector<Student> students(3);
    for (int i = 0; i < 3; ++i) {
        students[i].generateRandom();
        std::cout << "\nСтудент #" << (i+1) << " (випадково згенерований):\n";
        students[i].print();
    }
    
    // Створюємо вектор студентів-дипломників і заповнюємо випадковими даними
    std::vector<GraduateStudent> gradStudents(3);
    for (int i = 0; i < 3; ++i) {
        gradStudents[i].generateRandom();
        std::cout << "\nСтудент-дипломник #" << (i+1) << " (випадково згенерований):\n";
        gradStudents[i].print();
    }
}

// Функція для тестування зміни даних
void testDataModification() {
    std::cout << "\n=== Тестування модифікації даних ===\n";
    
    // Створюємо студента-дипломника
    GraduateStudent gradStudent("Бондаренко", "Олег", "Васильович", 5, "ID3456789", 
                              "Розробка алгоритмів комп'ютерного зору");
    std::cout << "\nПочаткові дані студента-дипломника:\n";
    gradStudent.print();
    
    // Змінюємо тему диплома
    std::cout << "\nЗміна теми диплома:\n";
    gradStudent.changeThesisTitle("Методи глибокого навчання в комп'ютерному зорі");
    
    // Змінюємо ідентифікаційний номер
    std::cout << "\nЗміна ідентифікаційного номера:\n";
    gradStudent.changeIdNumber("ID9876543");
    
    // Виводимо оновлені дані
    std::cout << "\nОновлені дані студента-дипломника:\n";
    gradStudent.print();
}

// Функція для тестування поліморфізму
void testPolymorphism() {
    std::cout << "\n=== Тестування поліморфізму ===\n";
    
    // Створюємо вектор вказівників на базовий клас
    std::vector<std::unique_ptr<Student>> students;
    
    // Додаємо об'єкти різних класів
    students.push_back(std::make_unique<Student>("Мельник", "Олександр", "Сергійович", 2, "ID4567890"));
    students.push_back(std::make_unique<GraduateStudent>("Ткаченко", "Надія", "Павлівна", 6, "ID5678901", 
                                                      "Розробка системи розпізнавання мови"));
    
    // Викликаємо віртуальний метод print() для кожного об'єкта
    for (const auto& student : students) {
        student->print();  // Поліморфний виклик
    }
}

// Функція для запуску всіх тестів
void runAllTests() {
    std::cout << "\n========== ПРОГРАМА ТЕСТУВАННЯ КЛАСІВ ==========\n";
    
    int choice;
    do {
        std::cout << "\nОберіть тест для запуску:\n";
        std::cout << "1. Тестування конструкторів і деструкторів\n";
        std::cout << "2. Тестування введення даних з клавіатури\n";
        std::cout << "3. Тестування введення даних з файлу\n";
        std::cout << "4. Тестування генерації випадкових даних\n";
        std::cout << "5. Тестування модифікації даних\n";
        std::cout << "6. Тестування поліморфізму\n";
        std::cout << "0. Вихід\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                testConstructorsAndDestructors();
                break;
            case 2:
                testInputFromKeyboard();
                break;
            case 3:
                testInputFromFile();
                break;
            case 4:
                testRandomGeneration();
                break;
            case 5:
                testDataModification();
                break;
            case 6:
                testPolymorphism();
                break;
            case 0:
                std::cout << "Завершення роботи програми.\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);
}

// Головна функція для запуску тестів
int main() {
    // Встановлюємо кодування консолі для коректного відображення кирилиці
    #ifdef _WIN32
        system("chcp 65001");
    #endif
    
    runAllTests();
    return 0;
}