#include <iostream>
using namespace std;

#define MAX 5

struct Queue {
    string nama_array[MAX];
    int front = -1;
    int rear = -1;
} antrian;

bool isFull() {
    if (antrian.rear == MAX - 1) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (antrian.front == -1 && antrian.rear == -1) {
        return true;
    } else {
        return false;
    }
}
