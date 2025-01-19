/*
Exercise 4-6:
Let's create an implementation for strings that uses a linked list of characters instead of dynamically allocated arrays.
So we'll have a linked list where the data payload is a single char; this will allow strings to grow without having to recreate the entire string.
We'll start by implementing the append and characterAt functions.

Exercise 4-7:
Following up on the previous exercise, implement the concatenate functions.
Note that if we make a call conatenate(s1, s2), where both parameters are pointers to the first node of their respective linked lists, the functions should create a copy of each of the nodes in s2 and append them to the end of s1.
That is, the function should not simply point the next field of the last node in s1's list to the first node of s2's list.

Exercise 4-8:
Add a function to the linked-list string implementation called removeChars to remove a section of characters from a string based on the position and length.
For example, removeChars(s1, 5, 3) would remove the three characters starting at the fifth character in the string.
Make sure the removed nodes are properly deallocated.
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

    // Remove characters function
    void removeChars(int position, int length) {
        if (position < 0 || position >= size || length <= 0) {
            throw out_of_range("Invalid position or length");
        }

        ListNode* current = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < position; i++) {
            prev = current;
            current = current->next;
        }

        for (int i = 0; i < length && current != nullptr; i++) {
            ListNode* toDelete = current;
            current = current->next;
            delete toDelete;
            size--;
        }

        if (prev != nullptr) {
            prev->next = current;
        } else {
            head = current;
        }

        if (current == nullptr) {
            tail = prev;
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

void removeCharsTester() {
    LinkedListString list;
    list.append('H');
    list.append('e');
    list.append('l');
    list.append('l');
    list.append('o');
    list.append(' ');
    list.append('W');
    list.append('o');
    list.append('r');
    list.append('l');
    list.append('d');
    list.display();  // Should output "Hello World"
    list.removeChars(5, 3);
    list.display();  // Should output "Hellorld"
}

int main() {
    appendTester();
    characterAtTester();
    concatenateTester();
    removeCharsTester();
    return 0;
}