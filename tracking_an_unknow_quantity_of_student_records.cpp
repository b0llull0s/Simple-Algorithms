/*
Write functions to store and manipulate a collection of student records.
A student record contains a student number and a grade, both integers.
The following functions are to be implemented:
    - addRecord: This funtions takes a pointer to a collection of student records, a student numer, and a grade, and it add the new record with this data to the collection.
    - averageRecord: This function takes a pointer to a collection of student records and returns the simple average of student grades in the collection as a double.
The collection can be of any size. The addRecord operation is expected to be called frequently, so it must be implemented efficiently. 

Exercise 4-5:
Write a function removeRecord that takes a pointer to a studentCollection and a student number and that removes the record with that student number  from the student collection.
*/
#include <iostream>
#include <cmath> // For NaN check

struct listNode {
    int studentNum;
    int grade;
    listNode *next;
};
typedef listNode *studentCollection;

void addRecord(studentCollection &sc, int stuNum, int gr) {
    listNode *newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
}

double averageRecord(studentCollection sc) {
    if (sc == nullptr) return std::nan("1"); 
    int count = 0;
    double sum = 0;
    listNode *loopPtr = sc;
    while (loopPtr != nullptr) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}

void removeRecord(studentCollection &sc, int stuNum) {
    listNode *prev = nullptr;
    listNode *curr = sc;
    
    while (curr != nullptr && curr->studentNum != stuNum) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == nullptr) {
        // Student number not found
        return;
    }
    
    if (prev == nullptr) {
        // The record to be removed is the first node
        sc = curr->next;
    } else {
        prev->next = curr->next;
    }
    
    delete curr;
}

int main() {
    studentCollection sc = nullptr;

    addRecord(sc, 1001, 78);
    addRecord(sc, 1012, 93);
    addRecord(sc, 1076, 85);

    std::cout << "Original records:" << std::endl;
    listNode *node = sc;
    while (node != nullptr) {
        std::cout << "Student Number: " << node->studentNum << ", Grade: " << node->grade << std::endl;
        node = node->next;
    }

    removeRecord(sc, 1012);

    std::cout << "\nRecords after removal:" << std::endl;
    node = sc;
    while (node != nullptr) {
        std::cout << "Student Number: " << node->studentNum << ", Grade: " << node->grade << std::endl;
        node = node->next;
    }

    double avg = averageRecord(sc);
    if (std::isnan(avg)) {
        std::cout << "\nNo records available for average calculation." << std::endl;
    } else {
        std::cout << "\nAverage grade: " << avg << std::endl;
    }

    return 0;
}