// Author: Arnav Mishra
// CECS 325-02 Prog 3
// Due 03/12/2024

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>

using namespace std;

int main(int args, char *arglist[]) {
    if (args != 4) {
        cout << "Usage: generate [length] [min] [max]" << endl;
    } else {
        int length = stoi(arglist[1]);
        int min = stoi(arglist[2]);
        int max = stoi(arglist[3]);
        int x = rand() % (max - min + 1) + min;
        cout << x << endl;
    }

    return 0;
}