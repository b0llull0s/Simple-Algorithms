/*
Exercise 4-6:
Let's create an implementation for strings that uses a linked list of characters instead of dynamically allocated arrays.
So we'll have a linked list where the data payload is a single char; this will allow strings to grow without having to recreate the entire string.
We'll start by implementing the append and characterAt functions.

Exercise 4-7:
Following up on the previous exercise, implement the concatenate functions.
Note that if we make a call conatenate(s1, s2), where both parameters are pointers to the first node of their respective linked lists, the functions should create a copy of each of the nodes in s2 and append them to the end of s1.
That is, the function should not simply point the next field of the last node in s1's list to the first node of s2's list.
*/
#include <iostream>
using namespace std;

struct ListNode {
    char data;
    ListNode* next;
};

class LinkedListString {
public:
    LinkedListString() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedListString() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void append(char c) {
        ListNode* newNode = new ListNode{c, nullptr};
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++; 
    }

    int length() const {   // Allows to an O(1) operation to retrieve the length
        return size;  
    }

    char characterAt(int position) const {
        if (position < 0 || position >= size) {
            throw out_of_range("Index out of range");
        }
        ListNode* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }

    void display() const {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }

    // Concatenate function
    void concatenate(const LinkedListString& other) {
        ListNode* current = other.head;
        while (current != nullptr) {
            append(current->data);
            current = current->next;
        }
    }

private:
    ListNode* head;
    ListNode* tail;
    int size;  
};

void appendTester() {
    LinkedListString list;
    list.append('t');
    list.append('e');
    list.append('s');
    list.append('t');
    list.append('!');
    list.display(); 
}

void characterAtTester() {
    LinkedListString list;
    list.append('t');
    list.append('e');
    list.append('s');
    list.append('t');
    cout << list.characterAt(2) << endl;  
}

void concatenateTester() {
    LinkedListString list1;
    list1.append('H');
    list1.append('e');
    list1.append('l');
    list1.append('l');
    list1.append('o');

    LinkedListString list2;
    list2.append(' ');
    list2.append('W');
    list2.append('o');
    list2.append('r');
    list2.append('l');
    list2.append('d');

    list1.concatenate(list2);
    list1.display();  // Should output "Hello World"
}

int main() {
    appendTester();
    characterAtTester();
    concatenateTester();
    return 0;
}