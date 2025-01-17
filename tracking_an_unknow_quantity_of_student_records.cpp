/*
Write functions to store and manipulate a collection of student records.
A student record contains a student number and a grade, both integers.
The following functions are to be implemented:
    - addRecord: This funtions takes a pointer to a collection of student records, a student numer, and a grade, and it add the new record with this data to the collection.
    - averageRecord: This function takes a pointer to a collection of student records and returns the simple average of student grades in the collection as a double.
The collection can be of any size. The addRecord operation is expected to be called frequently, so it must be implemented efficiently. 
*/
#include <iostream>

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
    if (sc == NULL) return 0;
    int count = 0;
    double sum = 0;
    listNode *loopPtr = sc;
    while (loopPtr != NULL) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}

int main() {
    studentCollection sc = NULL;

    addRecord(sc, 1001, 78);
    addRecord(sc, 1012, 93);
    addRecord(sc, 1076, 85);

    double avg = averageRecord(sc);
    std::cout << "Average grade: " << avg << std::endl;

    return 0;
}