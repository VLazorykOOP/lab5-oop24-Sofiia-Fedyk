#pragma once

#ifndef STUDENT_CLASSES_H
#define STUDENT_CLASSES_H

#include <string>
#include <iostream>
#include <fstream>
#include <random>

// Base class for representing a student
class Student
{
protected:
    std::string lastName;
    std::string firstName;
    std::string middleName;
    int course;
    std::string idNumber;

public:
    // Constructors
    Student(); // Default constructor
    Student(const std::string &lastName, const std::string &firstName,
            const std::string &middleName, int course, const std::string &idNumber);
    Student(const Student &other); // Copy constructor

    // Destructor
    virtual ~Student();

    // Data access methods
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getMiddleName() const { return middleName; }
    int getCourse() const { return course; }
    std::string getIdNumber() const { return idNumber; }

    // Data setting methods
    void setLastName(const std::string &lastName) { this->lastName = lastName; }
    void setFirstName(const std::string &firstName) { this->firstName = firstName; }
    void setMiddleName(const std::string &middleName) { this->middleName = middleName; }
    void setCourse(int course) { this->course = course; }
    void setIdNumber(const std::string &idNumber) { this->idNumber = idNumber; }

    // Virtual methods
    virtual void print() const;
    virtual void inputFromKeyboard();
    virtual void inputFromFile(std::ifstream &fin);
    virtual void generateRandom();

    // Static method for generating a random identification number
    static std::string generateRandomId();
};

// Derived class for representing a graduate student
class GraduateStudent : public Student
{
private:
    std::string thesisTitle;

public:
    // Constructors
    GraduateStudent(); // Default constructor
    GraduateStudent(const std::string &lastName, const std::string &firstName,
                    const std::string &middleName, int course,
                    const std::string &idNumber, const std::string &thesisTitle);
    GraduateStudent(const Student &student, const std::string &thesisTitle);
    GraduateStudent(const GraduateStudent &other); // Copy constructor

    // Destructor
    ~GraduateStudent() override;

    // Methods for getting and setting data
    std::string getThesisTitle() const { return thesisTitle; }
    void setThesisTitle(const std::string &thesisTitle) { this->thesisTitle = thesisTitle; }

    // Overridden virtual methods
    void print() const override;
    void inputFromKeyboard() override;
    void inputFromFile(std::ifstream &fin) override;
    void generateRandom() override;

    // Specific method for graduate student - changing thesis title
    void changeThesisTitle(const std::string &newTitle);

    // Reassignment of identification number
    void changeIdNumber(const std::string &newIdNumber);
};

#endif // STUDENT_CLASSES_H