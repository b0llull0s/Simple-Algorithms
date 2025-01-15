/*
Exercise 2-6:
Write a program to convert numbers from decimal to binary and reverse:

1. Identify the analogies:
    convert_a_number_to_int.cpp: Likely contains number conversion implementations.
    convert_char_digit_to_int.cpp: Likely contains character to digit conversion implementations.

2. Determine the operations:
    Decimal to Binary Conversion:
        Continuously divide the decimal number by 2.
        Collect the remainders in reverse order.
    Binary to Decimal Conversion:
        Multiply each binary digit by 2 raised to the power of its position.
        Sum the results.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary += to_string(decimal % 2);
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(const string &binary) {
    int decimal = 0;
    int power = 1;
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

int main() {
    string option, binary;
    int decimal;
    cout << "Enter 1 for Decimal to Binary conversion or 2 for Binary to Decimal conversion: ";
    cin >> option;
    if (option == "1") {
        cout << "Enter decimal number: ";
        cin >> decimal;
        cout << "Binary: " << decimalToBinary(decimal) << "\n";
    } else if (option == "2") {
        cout << "Enter binary number: ";
        cin >> binary;
        cout << "Decimal: " << binaryToDecimal(binary) << "\n";
    } else {
        cout << "Invalid option\n";
    }
    return 0;
}