#import <iostream>
using std::cin;
using std::cout;
/* Write a program that reads a character from the user representing a digit, 0 through 9.
Convert the character to the equivalent integer in the range of 0-9, and then output the integer to demostrate the result. */
char digit;
cout << "Enter a one-digit number: ";
cin >> digit;
int sum = digit - '0';
cout << "Is the sum of digits " << sum << "? \n";