#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node();

        if (newNode == NULL) {
            cout << "Stack Overflow\n";
            return;
        }

        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top element is: " << top->data << endl;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements are:\n";
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.display();

    s.pop();
    s.peek();

    return 0;
}
