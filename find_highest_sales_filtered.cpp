/*
Exercise 3-9:
Consider this modification of the sale array:
Because salespeople come and go throughout the year, we are now marking months prior to a sales agent's hiring, or after a sales agents's last months, with a -1.
Rewrite the highest sales average, or highest sales median, code to compensate.

1. Identify Analogies:

    SalesAgentSorter.cpp: Computes the average and median sales for sales agents, involving array processing and sorting.

2. Determine the Operations:

    Filter Valid Sales: Exclude sales marked with -1 from the calculations.
    Calculate Average and Median: Compute the average and median of the filtered sales.
    Find Highest: Identify the agent with the highest average and median sales.
    Output Result: Print the results.
*/
#include <iostream>
#include <algorithm> // for std::sort
#include <vector>
using namespace std;

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;

struct agentStruct {
    int monthlySales[NUM_MONTHS];
};

agentStruct agents[NUM_AGENTS] = {
    {1856, 498, 30924, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, -1, -1, -1},
    {23, 55, 67, 99, 265, 376, -1, -1, -1, -1, -1, -1}
};

double arrayAverage(const vector<int>& arr) {
    double sum = 0;
    for (int val : arr) {
        sum += val;
    }
    return sum / arr.size();
}

double arrayMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    if (arr.size() % 2 == 0) {
        return (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2.0;
    } else {
        return arr[arr.size() / 2];
    }
}

vector<int> filterValidSales(const int arr[], int size) {
    vector<int> filteredSales;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != -1) {
            filteredSales.push_back(arr[i]);
        }
    }
    return filteredSales;
}

void findHighestAverage() {
    double highestAverage = arrayAverage(filterValidSales(agents[0].monthlySales, NUM_MONTHS));
    int highestAgent = 0;
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentAverage = arrayAverage(filterValidSales(agents[agent].monthlySales, NUM_MONTHS));
        if (agentAverage > highestAverage) {
            highestAverage = agentAverage;
            highestAgent = agent;
        }
    }
    cout << "Agent with highest monthly average: " << highestAverage << " (Agent " << highestAgent + 1 << ")\n";
}

void findHighestMedian() {
    double highestMedian = arrayMedian(filterValidSales(agents[0].monthlySales, NUM_MONTHS));
    int highestAgent = 0;
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentMedian = arrayMedian(filterValidSales(agents[agent].monthlySales, NUM_MONTHS));
        if (agentMedian > highestMedian) {
            highestMedian = agentMedian;
            highestAgent = agent;
        }
    }
    cout << "Agent with highest monthly median: " << highestMedian << " (Agent " << highestAgent + 1 << ")\n";
}

int main() {
    int choice;
    cout << "Enter 1 to find the agent with the highest average sales, or 2 to find the agent with the highest median sales: ";
    cin >> choice;

    if (choice == 1) {
        findHighestAverage();
    } else if (choice == 2) {
        findHighestMedian();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}