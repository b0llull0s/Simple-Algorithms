/* Write a program to read a number character by character and convert it to an integer, using just one char variable and two int variable.
The number will have either three or four digits. */
#include <iostream>
using std::cin;
using std::cout;

int main() {
    cout << "Enter a three-digit or four-digit number: ";
    char digitChar = cin.get();
    int number = (digitChar - '0') * 100;

    digitChar = cin.get();
    number += (digitChar - '0') * 10;

    digitChar = cin.get();
    number += (digitChar - '0');

    digitChar = cin.get();
    if (digitChar == '\n') {
        cout << "Number entered: " << number << "\n";
    } else {
        number = number * 10 + (digitChar - '0');
        cout << "Number entered: " << number << "\n";
    }

    return 0;
}