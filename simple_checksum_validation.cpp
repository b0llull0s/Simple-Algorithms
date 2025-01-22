#import <iostream>
using std::cin;
using std::cout;
/* Write a program that takes an identification number (including its check digit)
of lenght six and determines whether the number is valid under a simple formula where
the values if each digit are summed and the result checked to see whether it is divisible by 10.
The program must process each chracter before reading the next one. */
char digit;
int checksum = 0;
cout << "Enter a six-digit number: ";
for (int position = 1; position <= 6; position ++) {
    cin >> digit;
    checksum += digit - '0';
}
cout << "Checksum is " << checksum << ". \n";
if (checksum % 10 == 0) {
    cout << "Checksum is divisible by 10. Valid. \n";
} else {
    cout << "Checksum is not divisible by 10. Invalid. \n";
}