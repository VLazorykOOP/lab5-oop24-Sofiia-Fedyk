#ifndef STUDENT_CLASSES_H
#define STUDENT_CLASSES_H

#include <string>
#include <iostream>
#include <fstream>
#include <random>

// Базовий клас для представлення студента
class Student {
protected:
    std::string lastName;
    std::string firstName;
    std::string middleName;
    int course;
    std::string idNumber;

public:
    // Конструктори
    Student(); // Конструктор за замовчуванням
    Student(const std::string& lastName, const std::string& firstName, 
            const std::string& middleName, int course, const std::string& idNumber);
    Student(const Student& other); // Конструктор копіювання
    
    // Деструктор
    virtual ~Student();
    
    // Методи отримання даних
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getMiddleName() const { return middleName; }
    int getCourse() const { return course; }
    std::string getIdNumber() const { return idNumber; }
    
    // Методи встановлення даних
    void setLastName(const std::string& lastName) { this->lastName = lastName; }
    void setFirstName(const std::string& firstName) { this->firstName = firstName; }
    void setMiddleName(const std::string& middleName) { this->middleName = middleName; }
    void setCourse(int course) { this->course = course; }
    void setIdNumber(const std::string& idNumber) { this->idNumber = idNumber; }
    
    // Віртуальні методи
    virtual void print() const;
    virtual void inputFromKeyboard();
    virtual void inputFromFile(std::ifstream& fin);
    virtual void generateRandom();
    
    // Статичний метод для генерації випадкового ідентифікаційного номера
    static std::string generateRandomId();
};

// Похідний клас для представлення студента-дипломника
class GraduateStudent : public Student {
private:
    std::string thesisTitle;

public:
    // Конструктори
    GraduateStudent(); // Конструктор за замовчуванням
    GraduateStudent(const std::string& lastName, const std::string& firstName, 
                  const std::string& middleName, int course, 
                  const std::string& idNumber, const std::string& thesisTitle);
    GraduateStudent(const Student& student, const std::string& thesisTitle);
    GraduateStudent(const GraduateStudent& other); // Конструктор копіювання
    
    // Деструктор
    ~GraduateStudent() override;
    
    // Методи отримання та встановлення даних
    std::string getThesisTitle() const { return thesisTitle; }
    void setThesisTitle(const std::string& thesisTitle) { this->thesisTitle = thesisTitle; }
    
    // Перевизначені віртуальні методи
    void print() const override;
    void inputFromKeyboard() override;
    void inputFromFile(std::ifstream& fin) override;
    void generateRandom() override;
    
    // Специфічний метод для студента-дипломника - перепризначення теми диплома
    void changeThesisTitle(const std::string& newTitle);
    
    // Перепризначення ідентифікаційного номера
    void changeIdNumber(const std::string& newIdNumber);
};

#endif // STUDENT_CLASSES_H