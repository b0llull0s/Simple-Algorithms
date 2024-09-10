#include <iostream>
#include <algorithm>  // For std::min and std::max

int sumAll(int num1, int num2) {
    int start = std::min(num1, num2);
    int end = std::max(num1, num2);
    
    // Formula: sum = n * (a + l) / 2
    int n = end - start + 1;  // Number of terms
    int sum = (n * (start + end)) / 2;  // Sum of the series
    
    return sum;
}

int main() {
    int num1 = 1;
    int num2 = 5;
    std::cout << "Sum of consecutive integers between " << num1 << " and " << num2 << " is " << sumAll(num1, num2) << std::endl;
    return 0;
}
