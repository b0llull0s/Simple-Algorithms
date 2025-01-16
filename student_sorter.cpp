/*
Exercise 3-1:
Write a program that uses qsort to sort an array of our student struct. First have it sort by grade and tthen try it again using the student ID
*/
#include <iostream>
#include <algorithm> // for qsort
#include <string>
using namespace std;

struct student {
    int grade;
    int studentID;
    string name;
};

const int ARRAY_SIZE = 10;

student studentArray[ARRAY_SIZE] = {
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

void printStudents(const student* students, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << students[i].name << ", Grade: " << students[i].grade << ", ID: " << students[i].studentID << endl;
    }
}

int main() {
    cout << "Original array:\n";
    printStudents(studentArray, ARRAY_SIZE);

    // Sort by grade
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByGrade);
    cout << "\nSorted by grade:\n";
    printStudents(studentArray, ARRAY_SIZE);

    // Sort by student ID
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByID);
    cout << "\nSorted by ID:\n";
    printStudents(studentArray, ARRAY_SIZE);

    return 0;
}