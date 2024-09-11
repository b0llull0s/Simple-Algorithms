#include <iostream>
#include <string>
#include <cctype>     // For std::isalnum and std::tolower
#include <algorithm>  // For std::reverse

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& str) {
    std::string normalizedStr;
    
    // Normalize the string: convert to lowercase and remove non-alphanumeric characters
    for (char ch : str) {
        if (std::isalnum(ch)) {
            normalizedStr += std::tolower(ch);
        }
    }
    
    // Reverse the normalized string
    std::string reversedStr = normalizedStr;
    std::reverse(reversedStr.begin(), reversedStr.end());
    
    // Compare the normalized and reversed strings
    return normalizedStr == reversedStr;
}

// Example usage
int main() {
    std::string testStr = "A man, a plan, a canal, Panama";
    if (isPalindrome(testStr)) {
        std::cout << "\"" << testStr << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << testStr << "\" is not a palindrome." << std::endl;
    }
    
    return 0;
}
