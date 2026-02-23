#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = value;
        cout << value << " pushed into stack\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top] << " popped from stack\n";
        top--;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements are:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.peek();

    return 0;
}
