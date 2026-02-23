#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void insertFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << value << " inserted at front\n";
    }

    void insertRear(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << value << " inserted at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " removed from front\n";

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = rear;
        cout << temp->data << " removed from rear\n";

        if (front == rear) {
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        Node* temp = front;
        cout << "Deque elements are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
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
