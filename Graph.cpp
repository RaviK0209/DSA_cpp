#include <bits/stdc++.h>
using namespace std;

//Creating user defined DT Node
struct Node {
    int data;
    Node *next;
      
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

//Display Adjacency Matrix
void adjacencyMatrix(int **arr, int n) {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//Adding edges in Adjacency Matrix
void addEdge(int **arr, int start, int end) {
    arr[start][end] = 1;
    arr[end][start] = 1;
}

// Adding edges in Adjacency List
Node *insertLast(Node *head, int num) {
    Node *newNode = new Node(num);
    if(head == NULL) {
        head = newNode;
        return head;
    } 
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//Display Adjacency List
void display(Node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//Program Execution starts here
int main() {
    int vertex, edge;   //Inputs from user
    cin >> vertex >> edge;
    
    //Dynamic memory allocation
    int **arr = (int **)malloc(vertex * sizeof(int*));
    for(int i = 0; i < vertex; i ++) {
        arr[i] = (int *) malloc(vertex * sizeof(int));
    }
    
    //Creating array of head
    Node *head[vertex];
    for(int i = 0; i < vertex; i ++) {
        head[i] = NULL;
    }
    
    for(int i = 0; i < edge; i ++) {
        int start, end;
        cin >> start >> end;
        addEdge(arr, start, end);
        
        head[start] = insertLast(head[start], end);
    }
    
    adjacencyMatrix(arr, vertex);
    
    cout << "\nList Representation : \n";
    for(int i = 0; i < vertex; i ++) {
        cout << i  << " - > ";
        display(head[i]);
    }
    
    return 0;
}
