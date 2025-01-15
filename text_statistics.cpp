/*
Exercise 2-9:
Write a program that reads a line of text, counting the number of words, identifying the length of the longest word, the greatest number of vowels in a word, and includes input sanitation.

1. Identify the analogies:
    - palindromes.cpp: Demonstrates string manipulation and normalization.
    - decode_message.cpp: Shows handling of character sequences.
    - convert_char_digit_to_int.cpp: Simple conversion of character digits to integers.
    
2. Determine the operations:
    - Read a line of text.
    - Sanitize input by removing non-alphanumeric characters.
    - Count the number of words.
    - Identify the length of the longest word.
    - Identify the greatest number of vowels in a word.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to sanitize input by removing non-alphanumeric characters
string sanitizeInput(const string &input) {
    string sanitized;
    for (char ch : input) {
        if (isalnum(ch) || isspace(ch)) {
            sanitized += ch;
        }
    }
    return sanitized;
}

// Function to count the number of vowels in a word
int countVowels(const string &word) {
    int count = 0;
    for (char ch : word) {
        char lower = tolower(ch);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            ++count;
        }
    }
    return count;
}

// Function to compute text statistics
void computeTextStatistics(const string &text) {
    string sanitizedText = sanitizeInput(text);
    istringstream stream(sanitizedText);
    string word;
    vector<string> words;
    int longestWordLength = 0;
    int maxVowelsInWord = 0;
    
    while (stream >> word) {
        words.push_back(word);
        if (word.length() > longestWordLength) {
            longestWordLength = word.length();
        }
        int vowelCount = countVowels(word);
        if (vowelCount > maxVowelsInWord) {
            maxVowelsInWord = vowelCount;
        }
    }

    cout << "Number of words: " << words.size() << "\n";
    cout << "Length of the longest word: " << longestWordLength << "\n";
    cout << "Greatest number of vowels in a word: " << maxVowelsInWord << "\n";
}

int main() {
    string input;
    cout << "Enter a line of text: ";
    getline(cin, input);

    computeTextStatistics(input);

    return 0;
}