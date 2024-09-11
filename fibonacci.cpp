#include <iostream>
#include <string>
#include <cstdlib> // for std::atoi

// Function to compute the nth Fibonacci number
int fibonacci(const std::string& nStr) {
    // Convert string input to integer
    int n = std::atoi(nStr.c_str()); // Using std::atoi to convert string to int
    
    // Input Handling
    if (n < 0) {
        std::cout << "OOPS" << std::endl;
        return -1; // Indicates an error; you could also handle this differently
    }
    if (n == 0) return 0;

    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    // Test the function
    std::string testInput = "5";
    std::cout << "Fibonacci of " << testInput << " is: " << fibonacci(testInput) << std::endl;
    return 0;
}
