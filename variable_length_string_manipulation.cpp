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
*/
#include <iostream>
using namespace std;

typedef char * arrayString;

char characterAT(arrayString s, int position) {
    return s[position];
}

void append(arrayString& s, char c) {
    int oldLength = 0;
    while (s[oldLength] != 0) {
        oldLength++;
    }
    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++) {
        newS[i] = s[i];
    }
    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;
}

void appendTester() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    append(a, '!');
    cout << a << "\n";
}

int length(arrayString s) {
    int count = 0;
    while (s[count] != 0) {
        count++;
    }
    return count;
}

void Concatenate(arrayString& s1, arrayString s2) {
    int s1_OldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_OldLength + s2_Length;
    arrayString newS = new char[s1_NewLength + 1];
    for(int i = 0; i < s1_OldLength; i++) {
        newS[i] = s1[i];
    }
    for(int i = 0; i < s2_Length; i++) {
        newS[s1_OldLength + i] = s2[i];
    }
    newS[s1_NewLength] = 0;
    delete[] s1;
    s1 = newS;
}

void ConcatenateTester() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    arrayString b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    Concatenate(a, b);
    cout << a << "\n" << b << "\n";
}

arrayString substring(arrayString s, int start, int length) {
    arrayString sub = new char[length + 1];
    for (int i = 0; i < length; i++) {
        sub[i] = s[start + i];
    }
    sub[length] = 0;
    return sub;
}

void substringTester() {
    arrayString a = new char[8];
    a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd'; a[4] = 'e'; a[5] = 'f'; a[6] = 'g'; a[7] = 0;
    arrayString sub = substring(a, 2, 4);
    cout << sub << "\n";
    delete[] sub;
}

void replaceString(arrayString& source, arrayString target, arrayString replaceText) {
    int sourceLength = length(source);
    int targetLength = length(target);
    int replaceTextLength = length(replaceText);

    // Count occurrences of target in source
    int count = 0;
    for (int i = 0; i < sourceLength; i++) {
        if (strncmp(&source[i], target, targetLength) == 0) {
            count++;
            i += targetLength - 1;
        }
    }

    // Calculate new length for the source after replacements
    int newLength = sourceLength + count * (replaceTextLength - targetLength);
    arrayString newSource = new char[newLength + 1];

    // Replace occurrences of target with replaceText
    int index = 0;
    for (int i = 0; i < sourceLength; i++) {
        if (strncmp(&source[i], target, targetLength) == 0) {
            for (int j = 0; j < replaceTextLength; j++) {
                newSource[index++] = replaceText[j];
            }
            i += targetLength - 1;
        } else {
            newSource[index++] = source[i];
        }
    }
    newSource[newLength] = 0;

    // Update source
    delete[] source;
    source = newSource;
}

void replaceStringTester() {
    arrayString a = new char[9];
    a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd'; a[4] = 'a'; a[5] = 'b'; a[6] = 'e'; a[7] = 'e'; a[8] = 0;
    arrayString target = new char[3];
    target[0] = 'a'; target[1] = 'b'; target[2] = 0;
    arrayString replaceText = new char[4];
    replaceText[0] = 'x'; replaceText[1] = 'y'; replaceText[2] = 'z'; replaceText[3] = 0;
    replaceString(a, target, replaceText);
    cout << a << "\n";
    delete[] a;
    delete[] target;
    delete[] replaceText;
}

int main() {
    appendTester();
    ConcatenateTester();
    substringTester();
    replaceStringTester();
    return 0;
}