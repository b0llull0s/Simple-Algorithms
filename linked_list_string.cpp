/*
Exercise 4-6:
Let's create an implementation for strings that uses a linked list of characters instead of dynamically allocated arrays.
So we'll have a linked list where the data payload is a single char; this will allow strings to grow without having to recreate the entire string.
We'll start by implementing the append and characterAt functions.
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

int main() {
    appendTester();
    characterAtTester();
    return 0;
}
