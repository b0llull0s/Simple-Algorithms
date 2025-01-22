/*
Write heap-bases implementation for three required string functions:
- append: This functions takes a string and a character and appends the character to the end of the strings
- Concatenate: This function takes two strings and append the character of the second string onto te first.
- characterAT This functions takes a string and a number and returns the chracater at that position in the string.

Write the code with the assumption that characterAT willl be called frequently, while the other two functions will be called relatively seldom. 
The relative efficiency of the operations should reflect the calling frequency.

Exercise 4-2:
For our dynamically allocated strings, create a function substring that takes three parameters:
   - An arrayString.
   - A starting position integer.
   - An integer length of characters.
The function returns a pointer to a new dynamically allocated string array.
This string array contains the characters in the original string, starting at the specified position for the specified length.
The original string is unaffected by the operation. So if the original string was abcdefg, the position was 3, and the length was 4, then the new string would contain cdef.

Exercise 4-3:
For our dynamically allocated strings, create a function replaceString that takes three parameters, each of type arrayString: source, target, and replaceText.
The function replaces every occurrence of target in source with replaceText.
For example, if source points to an array containing abcdabee, target points to ab, and replacetext points to xyz, then when the function ends, source should point to an array containing xyzcdxyzee

Exercise 4-4:
Change the implementation of our strings such that location[0] in the array stores the size of the array(and therefore location[1] stores the first actual character in the string) rather than using a null-character terminator.
Implement each of the three functions, append, concatenate, and characterAt, taking advantage of the stored size information whenever possible.
Because we'll no longer using the null-termination convention expected by the standard output stream, you'll need to write your own output function that loops through its string parameter, displaying characters.
*/
#include <iostream>
using namespace std;

using arrayString = char*;

char characterAT(arrayString s, int position) {
    return s[position + 1]; // Adjust for size stored at s[0]
}

void append(arrayString& s, char c) {
    int oldLength = s[0]; // Get the old length from s[0]
    arrayString newS = new char[oldLength + 2]; // Allocate new array with extra space
    newS[0] = oldLength + 1; // Update the size
    for (int i = 1; i <= oldLength; i++) {
        newS[i] = s[i];
    }
    newS[oldLength + 1] = c; // Append the new character
    delete[] s;
    s = newS;
}

void appendTester() {
    arrayString a = new char[5];
    a[0] = 4; // Size
    a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    append(a, '!');
    for (int i = 1; i <= a[0]; i++) {
        cout << a[i];
    }
    cout << "\n";
}

int length(arrayString s) {
    return s[0]; // Return the length stored at s[0]
}

void Concatenate(arrayString& s1, arrayString s2) {
    int s1_OldLength = s1[0];
    int s2_Length = s2[0];
    int s1_NewLength = s1_OldLength + s2_Length;
    arrayString newS = new char[s1_NewLength + 1];
    newS[0] = s1_NewLength; // Update the size
    for (int i = 1; i <= s1_OldLength; i++) {
        newS[i] = s1[i];
    }
    for (int i = 1; i <= s2_Length; i++) {
        newS[s1_OldLength + i] = s2[i];
    }
    delete[] s1;
    s1 = newS;
}

void ConcatenateTester() {
    arrayString a = new char[5];
    a[0] = 4; // Size
    a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    arrayString b = new char[4];
    b[0] = 3; // Size
    b[1] = 'b'; b[2] = 'e'; b[3] = 'd';
    Concatenate(a, b);
    for (int i = 1; i <= a[0]; i++) {
        cout << a[i];
    }
    cout << "\n";
    for (int i = 1; i <= b[0]; i++) {
        cout << b[i];
    }
    cout << "\n";
}

void customOutput(arrayString s) {
    for (int i = 1; i <= s[0]; i++) {
        cout << s[i];
    }
    cout << "\n";
}

int main() {
    appendTester();
    ConcatenateTester();
    return 0;
}