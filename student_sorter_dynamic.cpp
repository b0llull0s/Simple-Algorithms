/*
Exercise 4-1:
Rewrite the code to remove the limitation using a dynamically allocated array
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct student {
    int grade;
    int studentID;
    string name;
};

void printStudents(student* students, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << students[i].name << ", Grade: " << students[i].grade << ", ID: " << students[i].studentID << endl;
    }
}

vector<int> findQuartiles(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());
    vector<int> quartiles(3);

    quartiles[0] = sortedGrades[sortedGrades.size() / 4];
    quartiles[1] = sortedGrades[sortedGrades.size() / 2];
    quartiles[2] = sortedGrades[3 * sortedGrades.size() / 4];

    return quartiles;
}

int main() {
    int size = 10;
    student* studentArray = new student[size] {
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
    printStudents(studentArray, size);

    // Sort by grade using std::sort
    sort(studentArray, studentArray + size, [](const student& a, const student& b) {
        return a.grade < b.grade;
    });
    cout << "\nSorted by grade:\n";
    printStudents(studentArray, size);

    // Sort by student ID using std::sort
    sort(studentArray, studentArray + size, [](const student& a, const student& b) {
        return a.studentID < b.studentID;
    });
    cout << "\nSorted by ID:\n";
    printStudents(studentArray, size);

    // Find and print grade quartiles
    vector<int> grades;
    for (int i = 0; i < size; ++i) {
        grades.push_back(studentArray[i].grade);
    }
    vector<int> quartiles = findQuartiles(grades);

    cout << "\nGrade Quartiles:\n";
    cout << "1st Quartile: " << quartiles[0] << endl;
    cout << "2nd Quartile (Median): " << quartiles[1] << endl;
    cout << "3rd Quartile: " << quartiles[2] << endl;

    delete[] studentArray;
    return 0;
}