// Author: Arnav Mishra
// CECS 325-02 Prog 3
// Due 03/12/2024

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main(int args, char *argv[]) {
    // check for correct usage
    if (args != 4) {
        cout << "Usage: generate [count] [min] [max]" << endl;
    } else {
        // argument variables
        int count = stoi(argv[1]);
        int min = stoi(argv[2]);
        int max = stoi(argv[3]);

        // generate random numbers and add to array
        srand(time(NULL));
        int numbers[count];
        for (int i = 0; i < count; i++) {
            numbers[i] = rand() % (max - min + 1) + min;
        }

        //write to file
        ofstream file("numbers.dat");
        for (int a : numbers) {
            file << a << "\n";
        }
        file.close();
        
    }

    return 0;
}