#include <stdlib.h>

#define TABLE_SIZE 10000

// Node for hash table
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

// Insert into hash table
void insert(int key, int value) {
    int index = hash(key);
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search key in hash table
int search(int key) {
    int index = hash(key);
    Node* current = hashTable[index];
    while (current) {
        if (current->key == key)
            return current->value;
        current = current->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(2 * sizeof(int));

    // Clear hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex = search(complement);
        if (foundIndex != -1) {
            result[0] = foundIndex;
            result[1] = i;
            return result;
        }
        insert(nums[i], i);
    }

    return NULL;
}
