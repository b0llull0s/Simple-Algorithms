/*
Exercise 2-8:
Write a program that convert from any number base-16 or less to amy other number base:

1. Identify the analogies:
    - convert_a_number_to_int.cpp: Demonstrates converting a character sequence to an integer.
    - decode_message.cpp: Shows handling of character sequences and their conversion to numbers.
    - convert_char_digit_to_int.cpp: Simple conversion of character digits to integers.
    - decimal_binary_hex_converter.cpp: Provides methods for converting between decimal, binary, and hexadecimal.

2. Determine the operations:
    - Any Base to Decimal Conversion:
        Multiply each digit by the base raised to the power of its position.
        Sum the results.
    - Decimal to Any Base Conversion:
        Continuously divide the decimal number by the target base.
        Collect the remainders in reverse order.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to convert any base to decimal
int anyBaseToDecimal(const string &number, int base) {
    int decimal = 0;
    int power = 1;
    for (int i = number.size() - 1; i >= 0; --i) {
        char digit = number[i];
        if (digit >= '0' && digit <= '9') {
            decimal += (digit - '0') * power;
        } else if (digit >= 'A' && digit <= 'F') {
            decimal += (digit - 'A' + 10) * power;
        }
        power *= base;
    }
    return decimal;
}

// Function to convert decimal to any base
string decimalToAnyBase(int decimal, int base) {
    if (decimal == 0) return "0";
    string result = "";
    char digits[] = "0123456789ABCDEF";
    while (decimal > 0) {
        result += digits[decimal % base];
        decimal /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string sourceBaseStr, targetBaseStr, number;
    int sourceBase, targetBase;
    
    cout << "Enter source base (2-16): ";
    cin >> sourceBaseStr;
    sourceBase = stoi(sourceBaseStr);
    if (sourceBase < 2 || sourceBase > 16) {
        cout << "Invalid source base\n";
        return 1;
    }

    cout << "Enter target base (2-16): ";
    cin >> targetBaseStr;
    targetBase = stoi(targetBaseStr);
    if (targetBase < 2 || targetBase > 16) {
        cout << "Invalid target base\n";
        return 1;
    }

    cout << "Enter number in base " << sourceBase << ": ";
    cin >> number;

    int decimal = anyBaseToDecimal(number, sourceBase);
    string result = decimalToAnyBase(decimal, targetBase);

    cout << "Number in base " << targetBase << ": " << result << "\n";

    return 0;
}