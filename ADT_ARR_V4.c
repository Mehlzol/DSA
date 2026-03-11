/* ADT LIST VARIATION 4 */
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    char *elemPtr;
    int count;
    int max;
}List;

void initialize(List* L);
void insertPos(List* L, char data, int pos);
void deletePos(List* L, int pos);
int locate(List* L, char data);
int retrieve(List* L, int pos);
void insertSorted(List* L, char data);
void display(List* L);
void resize(List* L);
void makeNull(List* L);

int main(){

    List myList;
    List* L = &myList;

    initialize(L);

    insertPos(L, 'A', 0);
    insertPos(L, 'C', 1);
    insertPos(L, 'E', 2);
    display(L);

    insertSorted(L,'B');
    insertSorted(L,'D');
    display(L);

    int find;

    find = locate(L,'A');
    printf("Locate A: %d\n", find);

    find = locate(L,'F');
    printf("Locate F: %d\n", find);

    find = retrieve(L, 0);
    printf("Retrieve pos 0: %c\n", find);

    find = retrieve(L, 5);
    printf("Retrieve pos 5: %d\n", find);

    makeNull(L);
    display(L);

    free(L->elemPtr);

    return 0;
}

void initialize(List* L){
    L->elemPtr = (char*)malloc(sizeof(char)*LENGTH);
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(List* L, char data, int pos){

    if(pos > L->count || pos < 0){
        printf("Invalid Position.\n");
        return;
    }

    if(L->count == L->max){
        resize(L);
    }

    for(int i = L->count; i > pos; i--){
        L->elemPtr[i] = L->elemPtr[i-1];
    }

    L->elemPtr[pos] = data;
    L->count++;
}

void deletePos(List* L, int pos){

    if(pos >= L->count || pos < 0){
        printf("Invalid Position\n");
        return;
    }

    for(int i = pos; i < L->count-1; i++){
        L->elemPtr[i] = L->elemPtr[i+1];
    }

    L->count--;
}

int locate(List* L, char data){

    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data){
            return i;
        }
    }

    return -1;
}

int retrieve(List* L, int pos){

    if(pos >= 0 && pos < L->count){
        return L->elemPtr[pos];
    }

    return -1;
}

void insertSorted(List* L, char data){

    int i;

    for(i = 0; i < L->count && L->elemPtr[i] < data; i++);

    insertPos(L, data, i);
}

void display(List* L){

    if(L->count == 0){
        printf("List is Empty.\n");
        return;
    }

    printf("Character Elements:\n");

    for(int i = 0; i < L->count; i++){
        if(i == L->count-1){
            printf("%c\n", L->elemPtr[i]);
        }else{
            printf("%c ", L->elemPtr[i]);
        }
    }
}

void resize(List* L){

    L->max *= 2;

    char *temp = realloc(L->elemPtr, sizeof(char) * L->max);

    if(temp != NULL){
        L->elemPtr = temp;
    }else{
        printf("Memory reallocation failed\n");
    }
}

void makeNull(List* L){

    L->count = 0;
}