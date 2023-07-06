#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct {
    void *next;
    int data;
} Node;

Node *head = NULL;

Node *addNode(int data) {
    Node *new = NULL;
    new = malloc(sizeof(Node));
    if(new == NULL) {
        return NULL;
    }
    if(head == NULL) {
        new->data = data;
        head = new;
        new->next = NULL;
    }
    else {
        new->data = data;
        new->next = head;
        head = new;
    }

    return new;
}


int removeNode(int data) {
    Node *current = head;
    Node *prev = head;
    while(current != NULL) {
        if(current->data == data) {
            if(current == head) {
                head = current->next;
                Node *new_head = head->next;
                free(head);
                head = new_head;
            }
            else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }
            return 1;
        } 
        else {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}

Node *insertNode(int data, int position) {
    Node *current = head;
    while(current != NULL && position != 0) {
        position--;
    }

    if(position != 0) {
        printf("Requested position too far into the list\n");
        return NULL;
    }

    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = current->next;
    current->next = new;

    return new;
}

void printList() {
    Node *current = head;
    while(current != NULL) {
        printf("%d->",current->data);
        current = current->next;
    }
    printf("\n");
}
