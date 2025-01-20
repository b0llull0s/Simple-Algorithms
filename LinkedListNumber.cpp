/*
Exercise 4-9:
Imagine a linked list where instead of the node storing a character, the node stores a digit: an int in the range of 0-9.
We could represent positive numbers of any size using such a linked list; the number 149, for example, would be a linked list in which the node stores a 1, the second a 4, and the third and last a 9.
Write a function intToList that takes an integer value and produces a linked list of this sort.
Hint: You may find it easier to build the linked list backward, so if the value were 149, you would create the 9 node first.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

class LinkedListNumber {
public:
    LinkedListNumber() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedListNumber() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int digit) {
        ListNode* newNode = new ListNode{digit, nullptr};
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    void display() const {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }

    int length() const {
        return size;
    }

    static LinkedListNumber intToList(int value) {
        LinkedListNumber list;
        if (value == 0) {
            list.append(0);
            return list;
        }
        while (value > 0) {
            int digit = value % 10;
            list.append(digit);
            value /= 10;
        }
        return list.reverse();
    }

private:
    ListNode* head;
    ListNode* tail;
    int size;

    LinkedListNumber reverse() const {
        LinkedListNumber reversedList;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* newNode = new ListNode{current->data, reversedList.head};
            reversedList.head = newNode;
            if (reversedList.tail == nullptr) {
                reversedList.tail = newNode;
            }
            current = current->next;
        }
        return reversedList;
    }
};

void intToListTester() {
    LinkedListNumber list = LinkedListNumber::intToList(149);
    list.display();  // Should output "149"
}

int main() {
    intToListTester();
    return 0;
}