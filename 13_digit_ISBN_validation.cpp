/*
Exercise 2-5:
Write a program that verifies or generates the check digit for a 13-digit ISBN

1. Identify the analogies:

    luhn_checksum_validation.cpp: Validates identification numbers using the Luhn algorithm.
    simple_checksum_validation.cpp: Validates identification numbers through a simpler checksum method.

2. Determine the operations:
    Verification:
        Extract the check digit from the 13th position.
        Calculate the expected check digit using the first 12 digits and the Luhn formula.
        Compare the calculated check digit with the extracted check digit to verify validity.
    Generation:
        Use the first 12 digits of the ISBN.
        Apply the Luhn formula to calculate the check digit.
        Append the calculated check digit to the 12-digit ISBN.

*/
#include <iostream>
#include <string>
using namespace std;

// Function to calculate the Luhn check digit for a 12-digit ISBN
int calculateCheckDigit(const string &isbn12) {
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        int digit = isbn12[i] - '0';
        if (i % 2 == 0) {
            sum += digit;
        } else {
            sum += 3 * digit;
        }
    }
    int checkDigit = 10 - (sum % 10);
    return (checkDigit == 10) ? 0 : checkDigit;
}

// Function to verify a 13-digit ISBN
bool verifyISBN13(const string &isbn13) {
    string isbn12 = isbn13.substr(0, 12);
    int providedCheckDigit = isbn13[12] - '0';
    int calculatedCheckDigit = calculateCheckDigit(isbn12);
    return providedCheckDigit == calculatedCheckDigit;
}

int main() {
    string option, isbn;
    cout << "Enter 1 to verify ISBN or 2 to generate check digit: ";
    cin >> option;
    if (option == "1") {
        cout << "Enter 13-digit ISBN: ";
        cin >> isbn;
        if (verifyISBN13(isbn)) {
            cout << "Valid ISBN\n";
        } else {
            cout << "Invalid ISBN\n";
        }
    } else if (option == "2") {
        cout << "Enter 12-digit ISBN: ";
        cin >> isbn;
        int checkDigit = calculateCheckDigit(isbn);
        cout << "Complete ISBN: " << isbn << checkDigit << "\n";
    } else {
        cout << "Invalid option\n";
    }
    return 0;
}