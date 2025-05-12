#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor must be public and use 'this->' with arrow notation properly
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Global top pointer
Node* top = nullptr;

// Check if stack is empty
bool isEmpty() {
    return top == nullptr;
}

// Push operation
void push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    cout << value << " pushed into stack" << endl;
}

// Pop operation
int pop() {
    if (isEmpty()) {
        cout << "Stack is empty, no element to pop" << endl;
        return -1;
    }
    Node* current = top;
    int poppedData = top->data;
    top = top->next;
    delete current;
    return poppedData;
}

// Peek operation
int peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

// Display the stack
void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main menu
int main() {
    int choice, value;
    while (true) {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2: {
                int poppedValue = pop();
                if (poppedValue != -1)
                    cout << "Value popped is: " << poppedValue << endl;
                break;
            }
            case 3: {
                int topValue = peek();
                if (topValue != -1)
                    cout << "Element at top is: " << topValue << endl;
                break;
            }
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }
    return 0;
}
