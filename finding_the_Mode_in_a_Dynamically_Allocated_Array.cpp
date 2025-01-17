/*
Exercise 4-1:
Take a problem that you already know how to solve using an array but that is limited by the size of the array.
Rewrite the code to remove that limitation using a dynamically allocated array:

    1. Identify Analogies:
        find_mode_with_arrays.cpp: Demonstrates finding the mode of a dataset by counting frequencies.
        SalesAgentSorter.cpp: Involves array processing and sorting to find averages and medians.

    2. Determine the Operations:
        Input the number of elements:
            Prompt the user to enter the number of elements.
            Read and store the input value.
        Dynamically allocate memory for the array:
            Use the new operator to allocate memory for an array of integers based on the number of elements provided by the user.
        Input the elements:
            Prompt the user to enter each element of the array.
            Read and store the input values in the dynamically allocated array.
        Calculate the mode:
            Traverse the array to count the frequency of each element using a map or hash table.
            Identify the element with the highest frequency.
        Output the mode:
            Print the mode of the array.
        Deallocate memory:
            Use the delete[] operator to free the dynamically allocated memory.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int findMode(const int* numbers, int size) {
    std::unordered_map<int, int> frequencyMap;
    for (int i = 0; i < size; ++i) {
        frequencyMap[numbers[i]]++;
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
    int n, num;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int* numbers = new int[n]; // Dynamically allocate memory for the array

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    int mode = findMode(numbers, n);
    std::cout << "The mode is: " << mode << std::endl;

    delete[] numbers; // Free the dynamically allocated memory

    return 0;
}