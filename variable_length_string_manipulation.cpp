/*
Write heap-bases implementation for three required string functions:
- append: This functions takes a string and a character and appends the character to the end of the strings
- Concatenate: This function takes two strings and append the character of the second string onto te first.
- characterAT This functions takes a string and a number and returns the chracater at that position in the string.

Write the code with the assumption that characterAT willl be called frequently, while the other two functions will be called relatively seldom. 
The relative efficiency of the operations should reflect the calling frequency.
*/


typedef char * arrayString;

char characterAT(arrayString s, int position) {
    return s[position];
}

void append(arrayString& s, char c) {
    int oldLength = length(s);
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

// Testing code

arrayString b = new char[1];
b[0] = 0;
append(b, '!');
cout << b << "\n";

// Concatenate

int length(arrayString s) {
    int count = 0;
    while (s[count] != 0) {
        count++;
    }
    return count;
}

void Concatenate(arrayString& s1, arrayString s2) {   
}
void ConcatenateTester() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = '0';
    arrayString b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    Concatenate(a, b);
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

// Test case

arrayString a = new char[5];
a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
arrayString c = new char[1];
c[0] = 0;
Concatenate(c, a);
cout << a << "\n" << c << "\n";
cout << (void *) a << "\n" << (void *) c << "\n";