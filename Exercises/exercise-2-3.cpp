/*
Using only single-character output statements that output a hash mark, a space, or an end-of-line, write a program that produces the following shape:
#            #
 ##        ##
  ###    ###
   ########
   ########
  ###    ###
 ##        ##
#            #

1. Identify Analogies:

    one_line_hash.cpp: Outputs a single line of hash marks.
    full_square_hash.cpp: Outputs a full square of hash marks.
    the_elevator_sideways_triangle.cpp: Outputs a sideways triangle of hash marks.
    exercise-2-1.cpp: Outputs a pattern with increasing spaces and decreasing hash marks.

2. Determine the Operations:

Top half of the shape:
    Print an increasing number of leading spaces for each row.
    Print an increasing number of left hash marks for each row.
    Print a decreasing number of middle spaces for each row (calculated as 12 - (row * 4)).
    Print an increasing number of right hash marks for each row.
    Move to the next line.

Bottom half of the shape:
    Print a decreasing number of leading spaces for each row.
    Print a decreasing number of left hash marks for each row.
    Print an increasing number of middle spaces for each row (calculated as 12 - (row * 4)).
    Print a decreasing number of right hash marks for each row.
    Move to the next line.

*/

#include <iostream>
using std::cout;

int main() {
    int totalRows = 4;
    
    // Top half of the shape
    for (int row = 0; row < totalRows; ++row) {
        // Print leading spaces
        for (int space = 0; space < row; ++space) {
            cout << " ";
        }
        
        // Print left hash marks
        for (int hash = 0; hash <= row; ++hash) {
            cout << "#";
        }
        
        // Print middle spaces
        // For row 0 (top): 12 spaces
        // For row 1: 8 spaces
        // For row 2: 4 spaces
        // For row 3: 0 spaces (middle row)
        int middleSpaces = 12 - (row * 4);
        for (int space = 0; space < middleSpaces; ++space) {
            cout << " ";
        }
        
        // Print right hash marks
        for (int hash = 0; hash <= row; ++hash) {
            cout << "#";
        }
        cout << "\n";
    }

    // Bottom half of the shape
    for (int row = totalRows - 1; row >= 0; --row) {
        // Print leading spaces
        for (int space = 0; space < row; ++space) {
            cout << " ";
        }
        
        // Print left hash marks
        for (int hash = 0; hash <= row; ++hash) {
            cout << "#";
        }
        
        // Print middle spaces
        // Same pattern as top half
        int middleSpaces = 12 - (row * 4);
        for (int space = 0; space < middleSpaces; ++space) {
            cout << " ";
        }
        
        // Print right hash marks
        for (int hash = 0; hash <= row; ++hash) {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}