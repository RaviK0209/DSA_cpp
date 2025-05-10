#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  
  Node(int data){
      this->data = data;
      this->next = nullptr;
  }
};

Node *head = nullptr;


void insertAtFirst(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return;
}

void insertInBetween(int data, int pos){
        pos = pos - 2;
        Node* newNode = new Node(data);
        Node* temp = head;
        if(pos <= 0){
            insertAtFirst(data);
            return;
        }
        while(pos != 0){
            temp = temp->next;
            pos--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
}

void display(){
    Node* temp = head;
    while(temp !=nullptr){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
}


void insertAtLast(int data){
    Node* newNode = new Node(data);
    
    if(head == nullptr){
        head = newNode;
        return;
    }
    
    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFirst(){
    head = head->next;
    if(head == nullptr){
        return;
    }
}

void deleteLast(){
    Node* temp = head;
    Node* prev = head;
    while(temp->next != nullptr){
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
}

void deleteInBetween(int pos){
    pos = pos - 1;
    Node* temp = head;
    Node* prev = head;
    
    while(pos != 0){
        pos--;
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    
}

void deleteBeforeTheValue(int key) {
    Node *temp = head;
    Node *prev = NULL;
    bool found = false;
    
    while(temp != NULL) {
        if(temp->data == key) {
            found = true;
            break;
        }
        
        prev = temp;
        temp = temp->next;
    }
    
    if(found) {
        if(prev == NULL) {
            cout << "No value before " << key << endl;
        } 
        else{
            prev->next = temp->next;
        }
    }
    else{
        cout << "Not Found";
    }
    
    
}

int main(){
    int choice, data;
    while(1){
        cin>>choice;
        if(choice == 1){
            int data;
            cin>>data;
            insertAtFirst(data);
        }
        else if(choice == 2){
            int data;
            cin>>data;
            insertAtLast(data);
        }
        else if (choice == 3){
            int data;
            int pos;
            cin>>data>>pos;
            insertInBetween(data,pos);
        }
        else if(choice == 4){
            deleteFirst();
        }
        else if(choice == 5){
            deleteLast();
        }
        else if(choice == 6){
            int pos;
            cin>>pos;
            deleteInBetween(pos);
        }
        else if(choice == 7){
            display();
        }
        else if(choice == 8) {
            cin >> data;
            deleteBeforeTheValue(data);
        }
        else{
            break;
        }
    }
    return 0;
    
}