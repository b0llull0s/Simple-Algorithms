/*
Exercise 4-9:
Imagine a linked list where instead of the node storing a character, the node stores a digit: an int in the range of 0-9.
We could represent positive numbers of any size using such a linked list; the number 149, for example, would be a linked list in which the node stores a 1, the second a 4, and the third and last a 9.
Write a function intToList that takes an integer value and produces a linked list of this sort.
Hint: You may find it easier to build the linked list backward, so if the value were 149, you would create the 9 node first.

Exercise 4-10:
For the digit list of the previous exercise, write a function that takes two such lists and produces a new list representing their sum.
*/
#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

using NodePtr = ListNode*;

class LinkedListNumber {
public:
    LinkedListNumber() : head(nullptr), tail(nullptr), size(0) {}
    
    ~LinkedListNumber() {
        NodePtr current = head;
        while (current != nullptr) {
            NodePtr next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int digit) {
        NodePtr newNode = new ListNode{digit, nullptr};
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    void display() const {
        NodePtr current = head;
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
            list.prepend(digit);
            value /= 10;
        }
        return list;
    }

    static LinkedListNumber sumLists(const LinkedListNumber& l1, const LinkedListNumber& l2) {
        // First reverse both input lists
        LinkedListNumber rev1 = l1.reverse();
        LinkedListNumber rev2 = l2.reverse();
        
        LinkedListNumber result;
        NodePtr p1 = rev1.head;
        NodePtr p2 = rev2.head;
        int carry = 0;
        
        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int sum = carry;
            if (p1 != nullptr) {
                sum += p1->data;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                sum += p2->data;
                p2 = p2->next;
            }
            carry = sum / 10;
            result.append(sum % 10);
        }
        
        return result.reverse();
    }

private:
    NodePtr head;
    NodePtr tail;
    int size;

    LinkedListNumber reverse() const {
        LinkedListNumber reversedList;
        NodePtr current = head;
        while (current != nullptr) {
            NodePtr newNode = new ListNode{current->data, reversedList.head};
            reversedList.head = newNode;
            if (reversedList.tail == nullptr) {
                reversedList.tail = newNode;
            }
            current = current->next;
        }
        return reversedList;
    }

    void prepend(int digit) {
        NodePtr newNode = new ListNode{digit, head};
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }
};

void intToListTester() {
    LinkedListNumber list1 = LinkedListNumber::intToList(149);
    LinkedListNumber list2 = LinkedListNumber::intToList(1450);
    
    cout << "First linked list: ";
    list1.display();
    
    cout << "Second linked list: ";
    list2.display();
    
    LinkedListNumber sumList = LinkedListNumber::sumLists(list1, list2);
    
    cout << "Sum of linked lists: ";
    sumList.display();  // Should output "1599"
}

int main() {
    intToListTester();
    return 0;
}