#include <iostream>
using std::cin;
using std::cout;

int main() {
    for (int row = 1; row <= 7; row++) {
        for (int hashNum = 1; hashNum <= 4 - abs(4 - row); hashNum++) {
            cout << "#";
        }
        cout << "\n";        
    }
}