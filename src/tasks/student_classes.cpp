#include "student_classes.h"
#include <iomanip>

// Реалізація методів базового класу Student
// =========================================

// Конструктор за замовчуванням
Student::Student() : lastName(""), firstName(""), middleName(""), course(1), idNumber("") {
    std::cout << "Створено студента (конструктор за замовчуванням)" << std::endl;
}

// Конструктор з параметрами
Student::Student(const std::string& lastName, const std::string& firstName, 
        const std::string& middleName, int course, const std::string& idNumber)
    : lastName(lastName), firstName(firstName), middleName(middleName), 
      course(course), idNumber(idNumber) {
    std::cout << "Створено студента: " << lastName << " " << firstName << std::endl;
}

// Конструктор копіювання
Student::Student(const Student& other)
    : lastName(other.lastName), firstName(other.firstName), middleName(other.middleName),
      course(other.course), idNumber(other.idNumber) {
    std::cout << "Створено копію студента: " << lastName << " " << firstName << std::endl;
}

// Деструктор
Student::~Student() {
    std::cout << "Видалено студента: " << lastName << " " << firstName << std::endl;
}

// Метод друку інформації про студента
void Student::print() const {
    std::cout << std::endl;
    std::cout << "Студент:" << std::endl;
    std::cout << "ПІБ: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "Курс: " << course << std::endl;
    std::cout << "Ідентифікаційний номер: " << idNumber << std::endl;
}

// Метод введення даних з клавіатури
void Student::inputFromKeyboard() {
    std::cout << "Введіть прізвище студента: ";
    std::cin >> lastName;
    
    std::cout << "Введіть ім'я студента: ";
    std::cin >> firstName;
    
    std::cout << "Введіть по-батькові студента: ";
    std::cin >> middleName;
    
    std::cout << "Введіть курс (1-6): ";
    std::cin >> course;
    
    std::cout << "Введіть ідентифікаційний номер: ";
    std::cin >> idNumber;
}

// Метод введення даних з файлу
void Student::inputFromFile(std::ifstream& fin) {
    if (fin.is_open()) {
        fin >> lastName >> firstName >> middleName >> course >> idNumber;
    }
}

// Генерування випадкових даних
void Student::generateRandom() {
    // Масиви прикладів для генерації випадкових даних
    static const std::string lastNames[] = {"Іваненко", "Петренко", "Сидоренко", "Коваленко", 
                                           "Шевченко", "Бондаренко", "Ткаченко", "Мельник"};
    static const std::string firstNames[] = {"Іван", "Петро", "Олексій", "Андрій", 
                                           "Марія", "Олена", "Ірина", "Тетяна"};
    static const std::string middleNames[] = {"Іванович", "Петрович", "Олексійович", "Андрійович", 
                                             "Іванівна", "Петрівна", "Олексіївна", "Андріївна"};
    
    // Створюємо генератор випадкових чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Розподіли для різних параметрів
    std::uniform_int_distribution<> lastNameDist(0, sizeof(lastNames)/sizeof(lastNames[0])-1);
    std::uniform_int_distribution<> firstNameDist(0, sizeof(firstNames)/sizeof(firstNames[0])-1);
    std::uniform_int_distribution<> middleNameDist(0, sizeof(middleNames)/sizeof(middleNames[0])-1);
    std::uniform_int_distribution<> courseDist(1, 6);  // Від 1 до 6 курсу
    
    // Генеруємо випадкові значення
    lastName = lastNames[lastNameDist(gen)];
    firstName = firstNames[firstNameDist(gen)];
    middleName = middleNames[middleNameDist(gen)];
    course = courseDist(gen);
    idNumber = generateRandomId();
}

// Статичний метод для генерації випадкового ідентифікаційного номера
std::string Student::generateRandomId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1000000, 9999999);
    
    return "ID" + std::to_string(dist(gen));
}

// Реалізація методів похідного класу GraduateStudent
// =================================================

// Конструктор за замовчуванням
GraduateStudent::GraduateStudent() : Student(), thesisTitle("") {
    std::cout << "Створено студента-дипломника (конструктор за замовчуванням)" << std::endl;
}

// Конструктор з параметрами
GraduateStudent::GraduateStudent(const std::string& lastName, const std::string& firstName, 
                           const std::string& middleName, int course, 
                           const std::string& idNumber, const std::string& thesisTitle)
    : Student(lastName, firstName, middleName, course, idNumber), thesisTitle(thesisTitle) {
    std::cout << "Створено студента-дипломника: " << lastName << " " << firstName << std::endl;
}

// Конструктор на основі об'єкта класу Student
GraduateStudent::GraduateStudent(const Student& student, const std::string& thesisTitle)
    : Student(student), thesisTitle(thesisTitle) {
    std::cout << "Створено студента-дипломника на основі існуючого студента: " 
              << lastName << " " << firstName << std::endl;
}

// Конструктор копіювання
GraduateStudent::GraduateStudent(const GraduateStudent& other)
    : Student(other), thesisTitle(other.thesisTitle) {
    std::cout << "Створено копію студента-дипломника: " << lastName << " " << firstName << std::endl;
}

// Деструктор
GraduateStudent::~GraduateStudent() {
    std::cout << "Видалено студента-дипломника: " << lastName << " " << firstName << std::endl;
}

// Перевизначений метод друку
void GraduateStudent::print() const {
    Student::print();  // Викликаємо метод базового класу
    std::cout << "Тема диплома: " << thesisTitle << std::endl;
}

// Перевизначений метод введення з клавіатури
void GraduateStudent::inputFromKeyboard() {
    Student::inputFromKeyboard();  // Викликаємо метод базового класу
    
    std::cout << "Введіть тему диплома: ";
    std::cin.ignore();  // Ігноруємо попередній символ нового рядка в буфері
    std::getline(std::cin, thesisTitle);
}

// Перевизначений метод введення з файлу
void GraduateStudent::inputFromFile(std::ifstream& fin) {
    Student::inputFromFile(fin);  // Викликаємо метод базового класу
    
    // Читаємо тему диплома як рядок до кінця рядка
    fin.ignore(); // Ігноруємо попередній символ нового рядка
    std::getline(fin, thesisTitle);
}

// Перевизначений метод генерації випадкових даних
void GraduateStudent::generateRandom() {
    Student::generateRandom();  // Викликаємо метод базового класу
    
    // Масив прикладів тем дипломів
    static const std::string thesisTitles[] = {
        "Розробка системи розподіленого обчислення на базі контейнерів Docker",
        "Аналіз та оптимізація алгоритмів машинного навчання для обробки природної мови",
        "Дослідження методів захисту інформації в IoT пристроях",
        "Проектування високонавантажених веб-систем з використанням мікросервісної архітектури",
        "Розробка системи комп'ютерного зору для аналізу медичних зображень"
    };
    
    // Генеруємо випадковий індекс для вибору теми диплома
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, sizeof(thesisTitles)/sizeof(thesisTitles[0])-1);
    
    thesisTitle = thesisTitles[dist(gen)];
}

// Метод для перепризначення теми диплома
void GraduateStudent::changeThesisTitle(const std::string& newTitle) {
    std::cout << "Зміна теми диплома." << std::endl;
    std::cout << "Стара тема: " << thesisTitle << std::endl;
    thesisTitle = newTitle;
    std::cout << "Нова тема: " << thesisTitle << std::endl;
}

// Метод для перепризначення ідентифікаційного номера
void GraduateStudent::changeIdNumber(const std::string& newIdNumber) {
    std::cout << "Зміна ідентифікаційного номера." << std::endl;
    std::cout << "Старий номер: " << idNumber << std::endl;
    idNumber = newIdNumber;
    std::cout << "Новий номер: " << idNumber << std::endl;
}