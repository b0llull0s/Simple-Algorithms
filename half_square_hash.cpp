#include <iostream>
using std::cin;
using std::cout;

int main() {
    for (int row = 1; row <= 5; row++) {
        for (int hashNum = 1; hashNum <= 6 - row; hashNum++) {
            cout << "#";
        }
        cout << "\n";        
    }
}