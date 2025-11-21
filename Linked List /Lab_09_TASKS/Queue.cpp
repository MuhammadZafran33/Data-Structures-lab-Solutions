#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int frontidx;
    int rearidx;
    int currentSize;

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < currentSize; i++) {
            newArr[i] = arr[(frontidx + i) % capacity];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        frontidx = 0;
        rearidx = currentSize;
    }

public:
    Queue(int initialCapacity = 4) {
        capacity = initialCapacity;
        arr = new int[capacity];
        frontidx = 0;
        rearidx = 0;
        currentSize = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    int size() const {
        return currentSize;
    }

    void enqueue(int value) {
        if (currentSize == capacity) {
            resize();
        }

        arr[rearidx] = value;
        rearidx = (rearidx + 1) % capacity;
        currentSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underFlow..." << endl;
            return;
        }

        frontidx = (frontidx + 1) % capacity;
        currentSize--;
    }

    int front() const {
        if (isEmpty()) {
            cout << "Queue is Empty! No Front element." << endl;
            return -1;
        }
        return arr[frontidx];
    }

    void print() const {
        cout << "Queue elements: ";
        for (int i = 0; i < currentSize; i++) {
            int index = (frontidx + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    cout << "Enqueue 10, 20, 30, 40\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();

    cout << "Front Element: " << q.front() << "\n";

    cout << "Dequeue two elements\n";
    q.dequeue();
    q.dequeue();
    q.print();
    cout << "Front Element Now: " << q.front() << "\n";

    cout << "Enqueue 50, 60, 70, 80\n";
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.print();

    cout << "Dequeue ALL elements\n";
    while (!q.isEmpty()) {
        cout << "Front: " << q.front() << " -> dequeued...\n";
        q.dequeue();
    }
    q.dequeue(); 

    return 0;
}
