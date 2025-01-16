/*
Exercise 3-8:
Write a program that processes an array of student objects and determines the grade quartiles:

1. Identify Analogies:

    student_sorter.cpp: Sorts an array of student structures by grade or student ID.
    SalesAgentSorter.cpp: Computes the average and median sales for sales agents.
    ArraySortedChecker.cpp: Checks if an array is sorted.

2. Determine the Operations:

    Sort Students: Sort the array of students by their grades.
    Find Quartiles: Calculate the 1st, 2nd (median), and 3rd quartiles from the sorted array of grades.
    Output Result: Print the quartiles of the grades.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    int grade;
    int studentID;
    string name;
};

vector<int> findQuartiles(vector<int>& grades) {
    sort(grades.begin(), grades.end());
    vector<int> quartiles(3);

    quartiles[0] = grades[grades.size() / 4];
    quartiles[1] = grades[grades.size() / 2];
    quartiles[2] = grades[3 * grades.size() / 4];

    return quartiles;
}

int main() {
    vector<student> students = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    vector<int> grades;
    for (const auto& student : students) {
        grades.push_back(student.grade);
    }

    vector<int> quartiles = findQuartiles(grades);

    cout << "Grade Quartiles:" << endl;
    cout << "1st Quartile: " << quartiles[0] << endl;
    cout << "2nd Quartile (Median): " << quartiles[1] << endl;
    cout << "3rd Quartile: " << quartiles[2] << endl;

    return 0;
}