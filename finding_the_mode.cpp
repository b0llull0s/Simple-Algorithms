/*
Write code that processes an array of survey data, to determine the mode of the data set. If multiple modes exist, any may be chosen.
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findModes(const std::vector<int>& surveyData) {
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE] = {0};

    // Fill the histogram
    for (int response : surveyData) {
        histogram[response - 1]++;
    }

    // Find the highest frequency
    int highestFrequency = *std::max_element(histogram, histogram + MAX_RESPONSE);

    // Collect all modes
    std::vector<int> modes;
    for (int i = 0; i < MAX_RESPONSE; i++) {
        if (histogram[i] == highestFrequency) {
            modes.push_back(i + 1);
        }
    }

    return modes;
}

int main() {
    std::vector<int> surveyData = {1, 3, 2, 4, 4, 5, 2, 3, 3, 4, 4, 4, 5, 6, 6, 6, 6, 6, 7, 8, 8, 9, 9, 10, 10, 10, 10};
    std::vector<int> modes = findModes(surveyData);

    std::cout << "The mode(s) of the survey data is/are: ";
    for (size_t i = 0; i < modes.size(); i++) {
        std::cout << modes[i];
        if (i < modes.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}