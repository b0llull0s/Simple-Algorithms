/*
Exercise 4-1:
Rewrite the code to remove the limitation using a dynamically allocated array
*/

#include <iostream>
#include <algorithm> // for qsort
#include <string>
#include <vector>
using namespace std;

struct student {
    int grade;
    int studentID;
    string name;
};

// Comparison function to sort by grade
int compareByGrade(const void* a, const void* b) {
    student* studentA = (student*)a;
    student* studentB = (student*)b;
    return (studentA->grade - studentB->grade);
}

// Comparison function to sort by student ID
int compareByID(const void* a, const void* b) {
    student* studentA = (student*)a;
    student* studentB = (student*)b;
    return (studentA->studentID - studentB->studentID);
}

void printStudents(const vector<student>& students) {
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Grade: " << student.grade << ", ID: " << student.studentID << endl;
    }
}

int main() {
    vector<student> studentArray = {
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

    cout << "Original array:\n";
    printStudents(studentArray);

    // Sort by grade
    qsort(&studentArray[0], studentArray.size(), sizeof(student), compareByGrade);
    cout << "\nSorted by grade:\n";
    printStudents(studentArray);

    // Sort by student ID
    qsort(&studentArray[0], studentArray.size(), sizeof(student), compareByID);
    cout << "\nSorted by ID:\n";
    printStudents(studentArray);

    return 0;
}