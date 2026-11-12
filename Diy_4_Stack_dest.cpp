#include <iostream>
using namespace std;

class stack {
private:
    int *arr;
    int capacity;
    int top;

public:
    // Constructor
    stack(int size) {
        capacity = size;
        top = -1;
        arr = new int[capacity];
        cout << "Stack created." << endl;
    }

    // Delete copy constructor and copy assignment operator 
    // to prevent double-free errors (Rule of Three)
    stack(const stack&) = delete;
    stack& operator=(const stack&) = delete;

    // Push operation
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return;
        }
        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    // Display operation
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~stack() {
        delete[] arr;
        cout << "Stack buffer released." << endl;
    }
};

int main() {
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();

    return 0;
}