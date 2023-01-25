#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// create
void pushHead(int value);
void pushTail(int value);
// read
void traversal();
// update
void update(int old_value, int new_value);
// delete
void popHead();
void popTail();


int main() {
    // 0
    pushHead(0);
    traversal();

    // -1 0
    pushHead(-1);
    traversal();

    // -1 0 3
    pushTail(3);
    traversal();

    // -1 0 1
    update(3, 1);
    traversal();

    // 0 1
    popHead();
    traversal();

    // 0
    popTail();
    traversal();

    // empty linked list
    popHead();
    traversal();

    // pop no data
    popTail();
    printf("\n");
    popHead();

    return 0;
}

void pushHead(int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;

    // if no node in linked list
    if(head == NULL) {
        head = tail = temp;
        head->next = NULL;
    }
    // if there is node(s) in the linked list
    else {
        temp->next = head;
        head = temp;
    }
}

void pushTail(int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    // if no node in linked list
    if(head == NULL) {
        head = tail = temp;
    }
    // if there is node(s) in the linked list
    else {
        tail->next = temp;
        tail = temp;
    }
}

void traversal() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void update(int old_value, int new_value) {
    struct Node *temp = head;
    while(temp != NULL) {
        if(temp->data == old_value) {
            temp->data = new_value;
            break;
        }
        temp = temp->next;
    }
}

void popHead() {
    struct Node *temp = head;

    // if the linked list empty
    if(head == NULL) {
        printf("No data!");
    }
    // if there just one node in linked list
    else if(head == tail) {
        head = tail = NULL;
        free(temp);
    }
    // if there is more than one nodes in the linked list
    else {
        head = head->next;
        free(temp);
    }
}

void popTail() {
    struct Node *temp = head;

    // if no node in the linked list
    if(head == NULL) {
        printf("No data!");
    }
    // if just one node in the linked list
    else if(head == tail) {
        head = tail = NULL;
        free(temp);
    }
    // if there more than one nodes in linked list
    else {
        while(temp->next != tail) temp = temp->next;
        free(tail);
        tail = temp;
        tail->next = NULL;
    }
}