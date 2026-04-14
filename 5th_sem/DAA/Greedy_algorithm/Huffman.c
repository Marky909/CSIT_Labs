#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    char data;
    int freq;
    struct node *left, *right;
};

struct node* createNode(char data, int freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void swap(struct node **a, struct node **b) {
    struct node *t = *a;
    *a = *b;
    *b = t;
}

void sortNodes(struct node *arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i]->freq > arr[j]->freq)
                swap(&arr[i], &arr[j]);
}

void printCodes(struct node *root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    char ch[n];
    int freq[n];
    struct node *nodes[100];

    printf("Enter characters:\n");
    for (int i = 0; i < n; i++)
        scanf(" %c", &ch[i]);
    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    for (int i = 0; i < n; i++)
        nodes[i] = createNode(ch[i], freq[i]);

    clock_t start = clock();

    int size = n;
    while (size > 1) {
        sortNodes(nodes, size);
        struct node *left = nodes[0];
        struct node *right = nodes[1];
        struct node *newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        nodes[0] = newNode;
        for (int i = 1; i < size - 1; i++)
            nodes[i] = nodes[i + 1];
        size--;
    }

    int code[20], top = 0;
    printf("Huffman Codes:\n");
    printCodes(nodes[0], code, top);

    clock_t end = clock();
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
