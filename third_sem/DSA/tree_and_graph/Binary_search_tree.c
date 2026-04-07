#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (root->key < key) return search(root->right, key);
    return search(root->left, key);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30); insert(root, 20); insert(root, 40);
    insert(root, 70); insert(root, 60); insert(root, 80);
    
    printf("Inorder traversal: ");
    inorder(root); printf("\n");
    
    printf("Delete 20\n");
    root = deleteNode(root, 20);
    inorder(root); printf("\n");
    
    Node* found = search(root, 60);
    printf("Search for 60: %s\n", found ? "Found" : "Not found");
    return 0;
}