#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertData(int data, Node *(&root)) {
    if(root == NULL) {
        Node *newNode = new Node(data);
        root = newNode;
        return root;
    }   
    else if(data < (root->data)) {
        root->left = insertData(data, root->left);
    }
    else if(data > (root->data)) {
        root->right = insertData(data, root->right);
    }
    return root;
}

int findingmaximum(Node *root) {
    if(root->right == NULL) return root->data;
    return findingmaximum(root->right);
}

int findingminimum(Node *root) {
    if(root->left == NULL) return root->data;
    return findingminimum(root->left);
}

Node *deleteTree(Node *(&root), int num) {
    if(root == NULL) return NULL;
    else if(num < root->data) {
        root->left = deleteTree(root->left, num);
    }
    else if(num > root->data) {
        root->right = deleteTree(root->right, num);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            root = NULL;
            return root;
        }
        else if(root->left == NULL) {
            root = root->right;
            return root;
        }
        else if(root->right == NULL) {
            root = root->left;
            return root;
        }
        else {
            int temp = findingmaximum(root->left);
            root->data = temp;
            root->left = deleteTree(root->left, temp);
            return root;
        }
    }
    return root;
}

int heightOfTree(Node *root) {
    if(root == NULL) return 0;
    
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    
    return max(left, right) + 1;
    
}

void display(Node *root) {
    if(root != NULL) {
        display(root->right);
        cout << root->data << " ";
        display(root->left);
    }
}

void levelOrder(int level, Node *root) {
    if(root != NULL) {
        levelOrder(level - 1, root->left);
        if(level == 0) {
            cout << root->data << " ";
        }
        levelOrder(level - 1, root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insertData(10, root);
    root = insertData(6, root);
    root = insertData(14, root);
    root = insertData(8, root);
    root = insertData(3, root);
    root = insertData(16, root);
    root = insertData(20, root);
    root = insertData(22, root);
    root = insertData(12, root);
    display(root);
    cout << endl << "Maximum Value : " << findingmaximum(root->left);
    cout << endl << "Minimum Value : " << findingminimum(root->right);
    // deleteTree(root, 10);
    cout << endl;
    display(root);
    cout << endl;
    int height = heightOfTree(root);
    cout << height << endl;
    
    for(int i = 0; i < height; i ++) {
        levelOrder(i, root);
        cout << endl;
    }
    
    return 0;
}
