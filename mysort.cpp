// Author: Arnav Mishra
// CECS 325-02 Prog 3
// Due 03/12/2024

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>

using namespace std;

void bubble(int A[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

int main(int args, char *argv[]) {
    // read file and get size
    ifstream input(argv[1]);
    string temp;
    int size = 0;
    while(getline(input, temp)) {
        size++;
    }

    // create and fill array
    int numbers[size];
    int i = 0;
    while(getline(input, temp)) {
        numbers[i] = stoi(temp);
    }
    input.close();

    // run bubble sort function
    bubble(numbers, size);
    
    // write to output file
    ofstream output(argv[2]);
    for (int num : numbers) {
        output << num << endl;
    }

    return 0;
}