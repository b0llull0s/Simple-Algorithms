/*
Exercise 2-9:
Write a program that reads a line of text, counting the number of words, identifying the length of the longest word, the greatest number of vowels in a word, and includes additional statistics such as average word length, number of unique words, word frequency, and number of symbols and special characters.

1. Identify the analogies:
    - palindromes.cpp: Demonstrates string manipulation and normalization.
    - decode_message.cpp: Shows handling of character sequences.
    - convert_char_digit_to_int.cpp: Simple conversion of character digits to integers.
    
2. Determine the operations:
    - Read a line of text.
    - Count the number of words.
    - Identify the length of the longest word.
    - Identify the greatest number of vowels in a word.
    - Calculate the average word length.
    - Count the number of unique words.
    - Determine the frequency of each word.
    - Count the number of symbols and special characters.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

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

// Function to count symbols and special characters
int countSymbols(const string &text) {
    int count = 0;
    for (char ch : text) {
        if (!isalnum(ch) && !isspace(ch)) {
            ++count;
        }
    }
    return count;
}

// Function to compute text statistics
void computeTextStatistics(const string &text) {
    istringstream stream(text);
    string word;
    vector<string> words;
    unordered_map<string, int> wordFrequency;
    int totalWordLength = 0;
    int longestWordLength = 0;
    int maxVowelsInWord = 0;
    int symbolsCount = countSymbols(text);
    
    while (stream >> word) {
        // Remove punctuation from the word
        word.erase(remove_if(word.begin(), word.end(), [](char ch) { return ispunct(ch); }), word.end());
        
        words.push_back(word);
        wordFrequency[word]++;
        totalWordLength += word.length();
        if (word.length() > longestWordLength) {
            longestWordLength = word.length();
        }
        int vowelCount = countVowels(word);
        if (vowelCount > maxVowelsInWord) {
            maxVowelsInWord = vowelCount;
        }
    }

    double averageWordLength = words.empty() ? 0 : static_cast<double>(totalWordLength) / words.size();

    cout << "Number of words: " << words.size() << "\n";
    cout << "Length of the longest word: " << longestWordLength << "\n";
    cout << "Greatest number of vowels in a word: " << maxVowelsInWord << "\n";
    cout << "Average word length: " << averageWordLength << "\n";
    cout << "Number of unique words: " << wordFrequency.size() << "\n";
    cout << "Number of symbols and special characters: " << symbolsCount << "\n";
    cout << "Word frequencies:\n";
    for (const auto &pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    string input;
    cout << "Enter a line of text: ";
    getline(cin, input);

    computeTextStatistics(input);

    return 0;
}