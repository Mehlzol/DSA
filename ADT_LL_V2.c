#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
    List* L = initialize();

    insertPos(L, 2, 0);
    insertPos(L, 4, 1);
    insertPos(L, 6, 1);
    display(L);

    insertSorted(L, 1);
    insertSorted(L, 3);
    insertSorted(L, 5);
    display(L);

    deletePos(L, 0);
    deletePos(L, 3);
    deletePos(L, 1);
    display(L);

    return 0;
}

List* initialize(){
    List* list =(List*)malloc(sizeof(List));
    list->count = 0;
    list->head = NULL;
    return list;
}

void empty(List* list){
    Node* temp;
    while(list->head != NULL){
        temp = list->head;
        list->head = temp->next;
        free(temp);
    }
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    list->count++;
}

void insertPos(List *list, int data, int index) {
    Node *newNode, *current;
    int i;

    if (index < 0 || index > list->count) {
        printf("Invalid Position\n");
    }else if (index == 0) {
        insertFirst(list, data);
    }else if (index == list->count) {
        insertLast(list, data);
    } else {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;

        Node *curr = list->head;
        for (i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        list->count++;
    }
}


void deleteStart(List *list) {
    Node *curr = list->head;

    if (list->head != NULL) {
        list->head = curr->next;
        free(curr);
        list->count--;
    }
}

void deleteLast(List *list) {
    Node *curr;
    int i;

    if (list->head == NULL) {
        return;
    }

    if (list->count == 1) {
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    curr = list->head;
    for (i = 0; i < list->count - 2; i++) {
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;

    list->count--;
}

void deletePos(List *list, int index) {
    Node *temp;
    int i;

    if (index >= 0 && index < list->count) {
        if (index == 0) {
            deleteStart(list);
        } else {
            Node *curr = list->head;
            for (i = 0; i < index - 1; i++) {
                curr = curr->next;
            }

            temp = curr->next;
            curr->next = temp->next;
            free(temp);

            list->count--;
        }
    }
}

int retrieve(List *list, int index) {
    
    int i;

    if (index < 0 || index >= list->count) {
        return -1;
    }

    Node *curr = list->head;
    for (i = 0; i < index; i++) {
        curr = curr->next;
    }

    return curr->data;
}

int locate(List *list, int data) {
    int index = 0;

    if (list->head == NULL) {
        return -1;
    }

    Node *curr = list->head;
    while (curr != NULL) {
        if (curr->data == data) {
            return index;
        }
        curr = curr->next;
        index++;
    }

    return -1;
}

void display(List *list) {
    Node *curr = list->head;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
