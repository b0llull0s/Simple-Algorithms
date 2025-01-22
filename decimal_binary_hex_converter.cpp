/*
Exercise 2-6 and 2-7:
Write a program to convert numbers from decimal, binary, hex and reverse:

1. Identify the analogies:   
    convert_a_number_to_int.cpp: Demonstrates converting a character sequence to an integer.
    decode_message.cpp: Shows handling of character sequences and their conversion to numbers.
    convert_char_digit_to_int.cpp: Simple conversion of character digits to integers.

2. Determine the operations:
    Decimal to Binary Conversion:
        Continuously divide the decimal number by 2.
        Collect the remainders in reverse order.
    Binary to Decimal Conversion:
        Multiply each binary digit by 2 raised to the power of its position.
        Sum the results.
    Decimal to Hexadecimal Conversion:
        Continuously divide the decimal number by 16.
        Collect the remainders, translating numbers greater than 9 to letters A-F.
    Hexadecimal to Decimal Conversion:
        Multiply each hexadecimal digit by 16 raised to the power of its position.
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

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimal) {
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";
    while (decimal > 0) {
        hex += hexDigits[decimal % 16];
        decimal /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex;
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(const string &hex) {
    int decimal = 0;
    int power = 1;
    for (int i = hex.size() - 1; i >= 0; --i) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * power;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * power;
        }
        power *= 16;
    }
    return decimal;
}

// Function to convert binary to hexadecimal
string binaryToHexadecimal(const string &binary) {
    int decimal = binaryToDecimal(binary);
    return decimalToHexadecimal(decimal);
}

// Function to convert hexadecimal to binary
string hexadecimalToBinary(const string &hex) {
    int decimal = hexadecimalToDecimal(hex);
    return decimalToBinary(decimal);
}

int main() {
    string option, value;
    int decimal;
    cout << "Choose an option: \n1. Decimal to Binary\n2. Binary to Decimal\n3. Decimal to Hexadecimal\n4. Hexadecimal to Decimal\n5. Binary to Hexadecimal\n6. Hexadecimal to Binary\n";
    cin >> option;
    if (option == "1") {
        cout << "Enter decimal number: ";
        cin >> decimal;
        cout << "Binary: " << decimalToBinary(decimal) << "\n";
    } else if (option == "2") {
        cout << "Enter binary number: ";
        cin >> value;
        cout << "Decimal: " << binaryToDecimal(value) << "\n";
    } else if (option == "3") {
        cout << "Enter decimal number: ";
        cin >> decimal;
        cout << "Hexadecimal: " << decimalToHexadecimal(decimal) << "\n";
    } else if (option == "4") {
        cout << "Enter hexadecimal number: ";
        cin >> value;
        cout << "Decimal: " << hexadecimalToDecimal(value) << "\n";
    } else if (option == "5") {
        cout << "Enter binary number: ";
        cin >> value;
        cout << "Hexadecimal: " << binaryToHexadecimal(value) << "\n";
    } else if (option == "6") {
        cout << "Enter hexadecimal number: ";
        cin >> value;
        cout << "Binary: " << hexadecimalToBinary(value) << "\n";
    } else {
        cout << "Invalid option\n";
    }
    return 0;
}