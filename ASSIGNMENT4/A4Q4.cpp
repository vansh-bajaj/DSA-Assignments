#include <iostream>
using namespace std;

const int SIZE = 100;
char q[SIZE];
int f = -1, r = -1;
int countArr[26];

void enqueue(char ch) {
    if (r == SIZE - 1) return;
    if (f == -1) f = 0;
    q[++r] = ch;
}

void dequeue() {
    if (f == -1) return;
    if (f == r) f = r = -1;
    else f++;
}

char frontChar() {
    if (f == -1) return '#';
    return q[f];
}

bool isEmpty() {
    return f == -1;
}

void findFirstNonRepeating(char str[]) {
    f = -1;
    r = -1;
    for (int i = 0; i < 26; i++) countArr[i] = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch < 'a' || ch > 'z') {
            cout << "-1 ";
            continue;
        }
        countArr[ch - 'a']++;
        enqueue(ch);
        while (!isEmpty()) {
            char fc = frontChar();
            if (countArr[fc - 'a'] > 1) dequeue();
            else {
                cout << fc << " ";
                break;
            }
        }
        if (isEmpty()) cout << "-1 ";
    }
    cout << endl;
}

void displayMenu() {
    cout << "\nFirst Non-Repeating Character Menu\n";
    cout << "1. Find first non-repeating character in string\n";
    cout << "2. Exit\n";
    cout << "Choose: ";
}

int main() {
    int choice;
    char str[100];
    while (true) {
        displayMenu();
        if (!(cin >> choice)) break;
        if (choice == 1) {
            cout << "Enter a string (lowercase letters only): ";
            cin >> str;
            cout << "First non-repeating characters: ";
            findFirstNonRepeating(str);
        } else if (choice == 2) {
            cout << "You have exited the menu" << endl;
            break;
        } else {
            cout << "Enter a valid menu option" << endl;
        }
    }
    cout << "\nSample Test:" << endl;
    char sample[] = "aabc";
    cout << "Input: " << sample << endl;
    cout << "Output: ";
    findFirstNonRepeating(sample);
    return 0;
}
