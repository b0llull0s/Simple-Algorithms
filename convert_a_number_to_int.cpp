/* Write a program to read a number character by character and convert it to an integer. */
#include <iostream>
using std::cin;
using std::cout;

int main() {
    cout << "Enter a number: ";
    char digitChar = cin.get();
    int number = (digitChar - '0');

    digitChar = cin.get();
    while (digitChar != 10) {
        number = number * 10 + (digitChar - '0');
        digitChar = cin.get();
    }
    cout << "Number entered: " << number << "\n";
}