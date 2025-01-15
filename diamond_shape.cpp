/*
Exercise 2.2:
Using only single-character output statements that output a hash mark, a space, or an end-of-line, write a program that produces the following shape:
   ##
  ####
 ######
########
########
 ######
  ####
   ##

1. Identify Analogies:

    one_line_hash.cpp: Outputs a single line of hash marks.
    full_square_hash.cpp: Outputs a full square of hash marks.
    the_elevator_sideways_triangle.cpp: Outputs a sideways triangle of hash marks.
    inverted_triangle.cpp: Outputs a pattern with increasing spaces and decreasing hash marks.

2. Determine the Operations:

    Printing an increasing number of spaces at the beginning of each line for the top half.
    Printing a decreasing number of spaces at the beginning of each line for the bottom half.
    Printing an increasing number of hash marks on each line for the top half.
    Printing a decreasing number of hash marks on each line for the bottom half.
    Moving to the next line after printing the spaces and hash marks.
*/

#include <iostream>
using std::cout;

int main() {
    int totalRows = 8;
    int maxHashes = 8;

    // Top half of the shape
    for (int row = 0; row < totalRows / 2; ++row) {
        for (int space = 0; space < totalRows / 2 - row - 1; ++space) {
            cout << " ";
        }
        for (int hash = 0; hash < 2 * row + 2; ++hash) {
            cout << "#";
        }
        cout << "\n";
    }

    // Bottom half of the shape
    for (int row = 0; row < totalRows / 2; ++row) {
        for (int space = 0; space < row; ++space) {
            cout << " ";
        }
        for (int hash = 0; hash < maxHashes - 2 * row; ++hash) {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}