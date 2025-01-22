/*
Exercise 3-7:
Write a program that is given an array of integers and determines the mode, which is the number that appears most frequently in the array:

1. Identify Analogies:

    finding_the_mode.cpp: Finds the mode of a dataset by counting frequencies.
    student_sorter.cpp: Sorts an array of students by grade or student ID using qsort.

2. Determine the Operations:

    Count Frequency: Traverse the array and count the frequency of each element using a map or array.
    Find Mode: Identify the element with the highest frequency.
    Output Result: Print the mode of the array.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int findMode(const std::vector<int>& numbers) {
    std::unordered_map<int, int> frequencyMap;
    for (int num : numbers) {
        frequencyMap[num]++;
    }

    int mode = numbers[0];
    int maxCount = 0;
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

int main() {
    std::vector<int> numbers;
    int n, num;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        numbers.push_back(num);
    }

    int mode = findMode(numbers);
    std::cout << "The mode is: " << mode << std::endl;

    return 0;
}