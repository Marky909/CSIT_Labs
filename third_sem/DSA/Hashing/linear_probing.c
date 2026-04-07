#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

struct HashItem { int key, value; } hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i].key = EMPTY;
}

int hashFunction(int key) { return key % TABLE_SIZE; }

void insert(int key, int value) {
    int index = hashFunction(key), start = index;
    while (hashTable[index].key != EMPTY && hashTable[index].key != DELETED) {
        if (hashTable[index].key == key) { hashTable[index].value = value; return; }
        if ((index = (index + 1) % TABLE_SIZE) == start) { printf("Table Full!\n"); return; }
    }
    hashTable[index].key = key, hashTable[index].value = value;
}

int search(int key) {
    int index = hashFunction(key), start = index;
    while (hashTable[index].key != EMPTY) {
        if (hashTable[index].key == key) return index;
        if ((index = (index + 1) % TABLE_SIZE) == start) break;
    }
    return -1;
}

void delete(int key) {
    int index = search(key);
    if (index != -1) hashTable[index].key = DELETED;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("Index %d: %s\n", i, hashTable[i].key == EMPTY ? "EMPTY" : 
               (hashTable[i].key == DELETED ? "DELETED" : "OCCUPIED"));
}

int main() {
    int choice, key, value;
    initHashTable();
    while (1) {
        printf("\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 5) break;
        if (choice == 1) { printf("Enter key, value: "); scanf("%d %d", &key, &value); insert(key, value); }
        else if (choice == 2) { printf("Enter key: "); scanf("%d", &key); printf(search(key) != -1 ? "Found\n" : "Not Found\n"); }
        else if (choice == 3) { printf("Enter key: "); scanf("%d", &key); delete(key); }
        else if (choice == 4) display();
    }
    return 0;
}