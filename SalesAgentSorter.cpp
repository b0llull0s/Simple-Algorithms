/*
Exercise 3-2:
Rewrite the code that finds the agent with the best monthly sales average so that it also finds the agent with the highest median sales.
*/
#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;

struct agentStruct {
    int monthlySales[NUM_MONTHS];
};

agentStruct agents[NUM_AGENTS] = {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
};

double arrayAverage(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

double arrayMedian(int arr[], int size) {
    sort(arr, arr + size);
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

void findHighestAverage() {
    double highestAverage = arrayAverage(agents[0].monthlySales, NUM_MONTHS);
    int highestAgent = 0;
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentAverage = arrayAverage(agents[agent].monthlySales, NUM_MONTHS);
        if (agentAverage > highestAverage) {
            highestAverage = agentAverage;
            highestAgent = agent;
        }
    }
    cout << "Agent with highest monthly average: " << highestAverage << " (Agent " << highestAgent + 1 << ")\n";
}

void findHighestMedian() {
    double highestMedian = arrayMedian(agents[0].monthlySales, NUM_MONTHS);
    int highestAgent = 0;
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentMedian = arrayMedian(agents[agent].monthlySales, NUM_MONTHS);
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