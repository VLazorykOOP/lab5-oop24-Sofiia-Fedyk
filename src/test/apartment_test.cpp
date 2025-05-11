#include "apartment_classes.h"
#include <iostream>
#include <string>

void testRoom();
void testOneRoomApartment();
void testCityOneRoomApartment();
void testAllClasses();

int main() {
    std::cout << "===== Тестування ієрархії класів для керування квартирами =====" << std::endl;
    
    testRoom();
    testOneRoomApartment();
    testCityOneRoomApartment();
    testAllClasses();
    
    std::cout << "\nПрограма успішно завершила роботу!" << std::endl;
    return 0;
}