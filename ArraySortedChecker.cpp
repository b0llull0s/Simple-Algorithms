/*
Exercise 3-3
Write a bool function that is passed an array and the number of elements in that array and determines whether the data in the array is sorted.
This should require only one pass.

1. Identify the analogies:

    Student Sorter: This program uses sorting algorithms and comparison functions, which can be helpful in understanding array operations and comparisons.
    Sales Agent Sorter: This program includes functions to calculate averages and medians, which involve array processing and sorting.
    Leap Years: This program demonstrates the use of a bool function with clear logic and conditions.

2. Determine the operations:

    - Initialize a loop to iterate through the array starting from the second element.
    - In each iteration, compare the current element with the previous element.
    - If any element is found to be less than the previous element, return false.
    - If the loop completes without finding any out-of-order elements, return true.
*/
#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};

    if (isSorted(arr1, 5)) {
        cout << "Array 1 is sorted." << endl;
    } else {
        cout << "Array 1 is not sorted." << endl;
    }

    if (isSorted(arr2, 5)) {
        cout << "Array 2 is sorted." << endl;
    } else {
        cout << "Array 2 is not sorted." << endl;
    }

    return 0;
}

