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

void enqueue() {
    string data;
    if (isFull()) {
        cout << "Antrian sudah penuh!" << endl;
    } else {
        cout << "Input data: ";
        cin >> data;

        // Jika antrian masih kosong
        if (isEmpty()) {
            antrian.front = 0;
            antrian.rear = 0;
            antrian.nama_array[antrian.rear] = data;
        } else {
            antrian.rear++;
            antrian.nama_array[antrian.rear] = data;
        }
        cout << data << " berhasil ditambahkan!" << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian masih kosong!" << endl;
    } else {
        cout << "Data " << antrian.nama_array[antrian.front] << " berhasil dihapus!" << endl;
        
        // Geser semua elemen ke depan untuk mempertahankan susunan FIFO
        for (int i = antrian.front; i < antrian.rear; i++) {
            antrian.nama_array[i] = antrian.nama_array[i + 1];
        }
        
        // Atur ulang penanda rear setelah elemen digeser
        if (antrian.front == antrian.rear) {
            antrian.front = -1;
            antrian.rear = -1;
        } else {
            antrian.rear--;
        }
    }
}

void clear() {
    antrian.front = -1;
    antrian.rear = -1;
    cout << "Antrian dibersihkan!" << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Antrian kosong." << endl;
    } else {
        cout << "Data Antrian: " << endl;
        
        // Menampilkan sisa ruang kosong dalam bentuk tanda koma
        if (antrian.rear < MAX - 1) {
            int count_kosong = MAX - 1 - antrian.rear;
            
            while (count_kosong > 0) {
                cout << "- (Kosong)" << endl;
                count_kosong--;
            }
        }
        
        // Menampilkan data yang ada di dalam antrian secara terbalik (dari rear ke front)
        for (int i = antrian.rear; i >= antrian.front; i--) {
            cout << "- " << antrian.nama_array[i] << endl;
        }
        
        cout << endl;
    }
}

int main() {
    int pilih;
    
    