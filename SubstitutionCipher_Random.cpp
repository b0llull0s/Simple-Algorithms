/*
Exercise 3-6:
To make the cipertext problem even more challenging, have your program randomly generate the cipher array instead of a hard-coded const array.
Effectively, this means placing a random character in each element of the array ,but remenber that you can't substitute a letter for itself.
So the first element can't be A and you can't use the same letter for two substitutions.

1. Identify the analogies:
    Student Sorter: This program uses sorting algorithms and comparison functions, which can be helpful in understanding array operations and comparisons.
    Sales Agent Sorter: This program includes functions to calculate averages and medians, which involve array processing and sorting.
    Leap Years: This program demonstrates the use of a bool function with clear logic and conditions.
    Substitution Cipher

2. Determine the operations:
    - Define a const array for the substitution cipher with 26 characters.
    - Read a plaintext message.
    - For each character in the message, find its corresponding character in the cipher array.
    - Handle punctuation and space characters appropriately.
    - Output the resulting ciphertext.
    - Create a function to decrypt the ciphertext back to plaintext.
    - For each character in the ciphertext, find its corresponding character in the original alphabet.
    - Verify the encoding and decoding by comparing the original plaintext with the decoded text.
    - Randomly generate the cipher array ensuring no letter substitutes itself and no duplicate substitutions occur.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

const char punctuation[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};
char cipher[26];

void generateRandomCipher() {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_device rd;
    mt19937 g(rd());

    do {
        shuffle(alphabet.begin(), alphabet.end(), g);
    } while (any_of(alphabet.begin(), alphabet.end(), [i = 0](char c) mutable { return c == 'A' + i++; }));

    for (int i = 0; i < 26; ++i) {
        cipher[i] = alphabet[i];
    }
}

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
    generateRandomCipher();

    string plaintext;
    cout << "Enter a plaintext message: ";
    getline(cin, plaintext);

    string ciphertext = encryptMessage(plaintext);
    cout << "Ciphertext: " << ciphertext << endl;

    string decodedText = decryptMessage(ciphertext);
    cout << "Decoded Text: " << decodedText << endl;

    return 0;
}