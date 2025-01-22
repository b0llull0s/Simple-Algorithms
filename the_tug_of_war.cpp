#include <iostream>
using std::cin;
using std::cout;

int main() {
    int length = 10;

    cout << "Simulating Tug of War with a rope of length " << length << "\n";

    // Two pointers starting at opposite ends
    for (int left = 0, right = length; left <= right; left++, right--) {
        cout << "Left: " << left << " | Right: " << right << "\n";

        // If the two sides meet, the game (or loop) ends
        if (left == right) {
            cout << "The two sides meet at the center: " << left << "\n";
        }
    }

    return 0;
}
