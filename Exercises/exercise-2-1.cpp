/*
Using only single-character output statements that output a hash mark, a space, or an end-of-line, write a program that produces the following shape:
########
 ######
  ####
   ##

1. Identify Analogies:

    one_line_hash.cpp: Outputs a single line of hash marks.
    full_square_hash.cpp: Outputs a full square of hash marks.
    the_elevator_sideways_triangle.cpp: Outputs a sideways triangle of hash marks.

2. Determine the Operations:

    Printing an increasing number of spaces at the beginning of each line.
    Printing a decreasing number of hash marks on each line.
    Moving to the next line after printing the spaces and hash marks.
*/

#include <iostream>
using std::cout;

int main() {
    int totalRows = 4;
    int maxHashes = 8;
    
// The outer loop controls the number of rows.
    for (int row = 0; row < totalRows; ++row) {
// The first inner loop prints the required number of spaces for indentation.
        for (int space = 0; space < row; ++space) {
            cout << " ";
        }
// The second inner loop prints the required number of hash marks.
        for (int hash = 0; hash < maxHashes - 2 * row; ++hash) {
            cout << "#";
        }
// After printing spaces and hash marks, a newline character is printed to move to the next row.
        cout << "\n";
    }

    return 0;
}



    
    

