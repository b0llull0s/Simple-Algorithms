#include <iostream>

bool isLeapYear(int year) {
    // Decompose problem into conditions
    bool divisibleBy4 = year % 4 == 0;
    bool divisibleBy100 = year % 100 == 0;
    bool divisibleBy400 = year % 400 == 0;

    // Apply conditions with clear logic
    if (divisibleBy4 && (!divisibleBy100 || divisibleBy400)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    if (isLeapYear(year)) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }

    return 0;
}
