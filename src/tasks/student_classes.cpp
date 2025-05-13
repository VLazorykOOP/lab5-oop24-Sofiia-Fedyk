#include "student_classes.h"
#include <iomanip>

// Student base class methods implementation
// =========================================

// Default constructor
Student::Student() : lastName(""), firstName(""), middleName(""), course(1), idNumber("") {
    std::cout << "Student created (default constructor)" << std::endl;
}

// Constructor with parameters
Student::Student(const std::string& lastName, const std::string& firstName, 
        const std::string& middleName, int course, const std::string& idNumber)
    : lastName(lastName), firstName(firstName), middleName(middleName), 
      course(course), idNumber(idNumber) {
    std::cout << "Student created: " << lastName << " " << firstName << std::endl;
}

// Copy constructor
Student::Student(const Student& other)
    : lastName(other.lastName), firstName(other.firstName), middleName(other.middleName),
      course(other.course), idNumber(other.idNumber) {
    std::cout << "Created copy of student: " << lastName << " " << firstName << std::endl;
}

// Destructor
Student::~Student() {
    std::cout << "Student deleted: " << lastName << " " << firstName << std::endl;
}

// Method for printing student information
void Student::print() const {
    std::cout << std::endl;
    std::cout << "Student:" << std::endl;
    std::cout << "Full name: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "ID number: " << idNumber << std::endl;
}

// Method for keyboard input
void Student::inputFromKeyboard() {
    std::cout << "Enter student's last name: ";
    std::cin >> lastName;
    
    std::cout << "Enter student's first name: ";
    std::cin >> firstName;
    
    std::cout << "Enter student's middle name: ";
    std::cin >> middleName;
    
    std::cout << "Enter course (1-6): ";
    std::cin >> course;
    
    std::cout << "Enter ID number: ";
    std::cin >> idNumber;
}

// Method for file input
void Student::inputFromFile(std::ifstream& fin) {
    if (fin.is_open()) {
        fin >> lastName >> firstName >> middleName >> course >> idNumber;
    }
}

// Generate random data
void Student::generateRandom() {
    // Arrays of examples for random data generation
    static const std::string lastNames[] = {"Smith", "Johnson", "Williams", "Jones", 
                                           "Brown", "Davis", "Miller", "Wilson"};
    static const std::string firstNames[] = {"John", "James", "Robert", "Michael", 
                                           "Mary", "Patricia", "Jennifer", "Linda"};
    static const std::string middleNames[] = {"Alexander", "Thomas", "Edward", "William", 
                                             "Marie", "Anne", "Elizabeth", "Jane"};
    
    // Create random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Distributions for different parameters
    std::uniform_int_distribution<> lastNameDist(0, sizeof(lastNames)/sizeof(lastNames[0])-1);
    std::uniform_int_distribution<> firstNameDist(0, sizeof(firstNames)/sizeof(firstNames[0])-1);
    std::uniform_int_distribution<> middleNameDist(0, sizeof(middleNames)/sizeof(middleNames[0])-1);
    std::uniform_int_distribution<> courseDist(1, 6);  // From 1 to 6 course
    
    // Generate random values
    lastName = lastNames[lastNameDist(gen)];
    firstName = firstNames[firstNameDist(gen)];
    middleName = middleNames[middleNameDist(gen)];
    course = courseDist(gen);
    idNumber = generateRandomId();
}

// Static method for generating random ID number
std::string Student::generateRandomId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1000000, 9999999);
    
    return "ID" + std::to_string(dist(gen));
}

// Implementation of GraduateStudent derived class methods
// ======================================================

// Default constructor
GraduateStudent::GraduateStudent() : Student(), thesisTitle("") {
    std::cout << "Graduate student created (default constructor)" << std::endl;
}

// Constructor with parameters
GraduateStudent::GraduateStudent(const std::string& lastName, const std::string& firstName, 
                           const std::string& middleName, int course, 
                           const std::string& idNumber, const std::string& thesisTitle)
    : Student(lastName, firstName, middleName, course, idNumber), thesisTitle(thesisTitle) {
    std::cout << "Graduate student created: " << lastName << " " << firstName << std::endl;
}

// Constructor based on Student object
GraduateStudent::GraduateStudent(const Student& student, const std::string& thesisTitle)
    : Student(student), thesisTitle(thesisTitle) {
    std::cout << "Graduate student created based on existing student: " 
              << lastName << " " << firstName << std::endl;
}

// Copy constructor
GraduateStudent::GraduateStudent(const GraduateStudent& other)
    : Student(other), thesisTitle(other.thesisTitle) {
    std::cout << "Created copy of graduate student: " << lastName << " " << firstName << std::endl;
}

// Destructor
GraduateStudent::~GraduateStudent() {
    std::cout << "Graduate student deleted: " << lastName << " " << firstName << std::endl;
}

// Overridden print method
void GraduateStudent::print() const {
    Student::print();  // Call base class method
    std::cout << "Thesis topic: " << thesisTitle << std::endl;
}

// Overridden keyboard input method
void GraduateStudent::inputFromKeyboard() {
    Student::inputFromKeyboard();  // Call base class method
    
    std::cout << "Enter thesis topic: ";
    std::cin.ignore();  // Ignore previous newline character in buffer
    std::getline(std::cin, thesisTitle);
}

// Overridden file input method
void GraduateStudent::inputFromFile(std::ifstream& fin) {
    Student::inputFromFile(fin);  // Call base class method
    
    // Read thesis topic as a string until end of line
    fin.ignore(); // Ignore previous newline character
    std::getline(fin, thesisTitle);
}

// Overridden random data generation method
void GraduateStudent::generateRandom() {
    Student::generateRandom();  // Call base class method
    
    // Array of thesis topic examples
    static const std::string thesisTitles[] = {
        "Development of distributed computing system based on Docker containers",
        "Analysis and optimization of machine learning algorithms for natural language processing",
        "Research on information protection methods in IoT devices",
        "Design of high-load web systems using microservice architecture",
        "Development of computer vision system for medical image analysis"
    };
    
    // Generate random index for thesis topic selection
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, sizeof(thesisTitles)/sizeof(thesisTitles[0])-1);
    
    thesisTitle = thesisTitles[dist(gen)];
}

// Method for changing thesis topic
void GraduateStudent::changeThesisTitle(const std::string& newTitle) {
    std::cout << "Changing thesis topic." << std::endl;
    std::cout << "Old topic: " << thesisTitle << std::endl;
    thesisTitle = newTitle;
    std::cout << "New topic: " << thesisTitle << std::endl;
}

// Method for changing ID number
void GraduateStudent::changeIdNumber(const std::string& newIdNumber) {
    std::cout << "Changing ID number." << std::endl;
    std::cout << "Old number: " << idNumber << std::endl;
    idNumber = newIdNumber;
    std::cout << "New number: " << idNumber << std::endl;
}