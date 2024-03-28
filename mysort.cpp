// Author: Arnav Mishra
// CECS 325-02 Prog 4
// Due 03/28/2024

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <pthread.h>

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

void merge(int a[], int asize, int b[], int bsize) {
    int temp[asize + bsize];

    int i, j, k = 0;

    while (i < asize && j < bsize) {
        if (a[i] <= b[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = b[j];
            j++;
        }
        k++;
    }
}

struct sortStuff {
    int* start;
    int size;
};

void* bridge(void* ptr) {
    sortStuff* arg = (sortStuff*) ptr;
    bubble(arg->start, arg->size);
}

int main(int args, char *argv[]) {

    int* numbers = new int[1000000]; // dynamic meme-ory!!

    // read file and get size
    ifstream input(argv[1]);
    string temp;
    // int numbers[1000000]; <-- old michael buble sort
    int size = 0;
    while (getline(input, temp)) {
        numbers[size] = stoi(temp);
        size++;
    }
    input.close();

    // creating structs
    sortStuff ss0, ss1, ss2, ss3, ss4, ss5, ss6, ss7;
    ss0.start = &numbers[0];
    ss0.size = 125000;
    ss1.start = &numbers[125000];
    ss1.size = 125000;
    ss2.start = &numbers[250000];
    ss2.size = 125000;
    ss3.start = &numbers[375000];
    ss3.size = 125000;
    ss4.start = &numbers[500000];
    ss4.size = 125000;
    ss5.start = &numbers[625000];
    ss5.size = 125000;
    ss6.start = &numbers[750000];
    ss6.size = 125000;
    ss7.start = &numbers[875000];
    ss7.size = 125000;

    // creating pthreads, check if any return a nonzero integer
    pthread_t t0, t1, t2, t3, t4, t5, t6, t7;
    int problem = 0;
    problem += pthread_create(&t0, NULL, bridge, (void*) &ss0);
    problem += pthread_create(&t1, NULL, bridge, (void*) &ss1);
    problem += pthread_create(&t2, NULL, bridge, (void*) &ss2);
    problem += pthread_create(&t3, NULL, bridge, (void*) &ss3);
    problem += pthread_create(&t4, NULL, bridge, (void*) &ss4);
    problem += pthread_create(&t5, NULL, bridge, (void*) &ss5);
    problem += pthread_create(&t6, NULL, bridge, (void*) &ss6);
    problem += pthread_create(&t7, NULL, bridge, (void*) &ss7);

    if (problem != 0) {
        cout << "problem!!!!" << endl;
    }

    // this function waits for threads to terminate before cleaning up resources used by the thread and continuing the program
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);

    // merge threads together, two at a time

    // run bubble sort function
    // bubble(numbers, size); <-- old michael buble sort
    
    // write to output file
    ofstream output(argv[2]);
    for (int i = 0; i < size; i++) {
        output << numbers[i] << endl;
    }

    return 0;
}