/*
Exercise 3-4:
Write a program for creating a substitution cipher problem. In a substitution problem all messages are made of uppercase letters and punctuation.
The original message is called the plaintext, and you create the ciphertext by substituting each letter with another letter.
For this problem hard-code a const array of 26 chararcters elements for the cipher, and have your program read a plaintext message and output the equivalent ciphertext.

Exercise 3-5:
Have the previous program convert the cipher text back to the plain text to verify the encoding and decoding.

1. Identify the analogies:
    Student Sorter: This program uses sorting algorithms and comparison functions, which can be helpful in understanding array operations and comparisons.
    Sales Agent Sorter: This program includes functions to calculate averages and medians, which involve array processing and sorting.
    Leap Years: This program demonstrates the use of a bool function with clear logic and conditions.

2. Determine the operations:
    - Define a const array for the substitution cipher with 26 characters.
    - Read a plaintext message.
    - For each character in the message, find its corresponding character in the cipher array.
    - Handle punctuation and space characters appropriately.
    - Output the resulting ciphertext.
    - Create a function to decrypt the ciphertext back to plaintext.
    - For each character in the ciphertext, find its corresponding character in the original alphabet.
    - Verify the encoding and decoding by comparing the original plaintext with the decoded text.
*/

#include <iostream>
#include <string>
using namespace std;

const char cipher[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
const char punctuation[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};

string encryptMessage(const string &plaintext) {
    string ciphertext = "";
    for (char ch : plaintext) {
        if (isupper(ch)) {
            ciphertext += cipher[ch - 'A'];
        } else {
            // Preserve punctuation and spaces as they are
            bool isPunctuation = false;
            for (char punc : punctuation) {
                if (ch == punc) {
                    ciphertext += ch;
                    isPunctuation = true;
                    break;
                }
            }
            if (!isPunctuation) {
                // Handle any non-uppercase, non-punctuation characters (optional)
                ciphertext += ch; // or any other handling logic
            }
        }
    }
    return ciphertext;
}

string decryptMessage(const string &ciphertext) {
    string plaintext = "";
    for (char ch : ciphertext) {
        if (isupper(ch)) {
            for (int i = 0; i < 26; ++i) {
                if (cipher[i] == ch) {
                    plaintext += ('A' + i);
                    break;
                }
            }
        } else {
            // Preserve punctuation and spaces as they are
            bool isPunctuation = false;
            for (char punc : punctuation) {
                if (ch == punc) {
                    plaintext += ch;
                    isPunctuation = true;
                    break;
                }
            }
            if (!isPunctuation) {
                // Handle any non-uppercase, non-punctuation characters (optional)
                plaintext += ch; // or any other handling logic
            }
        }
    }
    return plaintext;
}

int main() {
    string plaintext;
    cout << "Enter a plaintext message: ";
    getline(cin, plaintext);

    string ciphertext = encryptMessage(plaintext);
    cout << "Ciphertext: " << ciphertext << endl;

    string decodedText = decryptMessage(ciphertext);
    cout << "Decoded Text: " << decodedText << endl;

    return 0;
}