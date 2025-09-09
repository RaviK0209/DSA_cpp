#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    
};
Node *head = NULL;
int ans = 0;

void insertLast(int num) {

    ans ++;
    Node *nn = new Node(num);
    if(head == NULL) {
        head = nn;
        return;
    }
    
    Node *aryan = head;
    
    while(aryan->next != NULL) {
        aryan = aryan->next;
    }
    
    aryan->next = nn;
}

void insertFirst(int num) {
    ans ++;
    Node *nn = new Node(num);
    nn->next = head;
    head = nn;
}

void insertInBetween(int num, int pos) {
    pos -= 2;
    if(pos < 0) {
        insertFirst(num);
        return;
    }
    
    if(pos >= ans) {
        insertLast(num);
        return;
    }
    
    Node *nn = new Node(num);
    ans ++;
    Node *aryan = head;
    while(pos != 0) {
        aryan = aryan->next;
        pos --;
    }
    
    nn->next = aryan->next;
    aryan->next = nn;
}

void display() {
    Node *aryan = head;
    while(aryan != NULL) {
        cout << aryan->data << " ";
        aryan = aryan->next;
    }
}



int main() {
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertFirst(40);
    insertFirst(50);
    insertInBetween(100, 10);
    display();
    
    return 0;
}
