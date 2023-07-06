#ifdefine SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

typedef struct {
    void *next;
    int data;
} Node;

Node *addNode(int);

int removeNode(int);

Node *insertNode(int,int);

void printList();

void printMenu();

#endif
