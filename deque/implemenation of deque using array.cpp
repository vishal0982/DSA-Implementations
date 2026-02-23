#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front;
    int rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = SIZE - 1;
        }
        else {
            front--;
        }

        arr[front] = value;
        cout << value << " inserted at front\n";
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == SIZE - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;
        cout << value << " inserted at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << arr[front] << " removed from front\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == SIZE - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << arr[rear] << " removed from rear\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = SIZE - 1;
        }
        else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deque elements are: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque d;

    d.insertRear(10);
    d.insertRear(20);
    d.insertFront(5);

    d.display();

    d.deleteFront();
    d.deleteRear();

    d.display();

    return 0;
}
