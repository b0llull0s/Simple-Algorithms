/*
Write functions to store and manipulate a collection of student records.
A student record contains a student number and a grade, both integers.
The following functions are to be implemented:
    - addRecord: This funtions takes a pointer to a collection of student records, a student numer, and a grade, and it add the new record with this data to the collection.
    - averageRecord: This function takes a pointer to a collection of student records and returns the simple average of student grades in the collection as a double.
The collection can be of any size. The addRecord operation is expected to be called frequently, so it must be implemented efficiently. 
*/

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};
typedef listNode * studentCollection;

studentCollection sc;
listNode * node1 = new listNode;
node1->studentNum = 1001; node1->grade = 78;
listNode * node2 = new listNode;
node2->studentNum = 1012; node2->grade = 93;
listNode * node3 = new listNode;
node3->studentNum = 1076; node3->grade = 85;
sc = node1;
node1->next = node2;
node2->next = node3;
node3->next = NULL;
node1 = node2 = node3 = NULL;

void addRecord(studentCollection& sc, int stuNum, int gr) {
    listNode * newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
}
// List traversal
double averageRecord(studentCollection sc) {
    if (sc == NULL) return 0;
    int count = 0;
    double sum = 0;
    listNode * loopPtr = sc;
    while (loopPtr != NULL) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}