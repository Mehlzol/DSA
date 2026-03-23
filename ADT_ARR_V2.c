/* ADT LIST VARIATION 2 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *Eptr;

void initialize(Eptr L);
void insertPos(Eptr L, int data, int pos);
void deletePos(Eptr L, int pos);
int locate(Eptr L, int data);
int retrieve(Eptr L, int pos);
void insertSorted(Eptr L, int data);
void display(Eptr L);
void makeNULL(Eptr L);

void main(){
    Eptr L = (Eptr)malloc(sizeof(Etype));
    initialize(L);
    
    insertPos(L,10,0);    
    insertPos(L,30,1);
    insertPos(L,50,2);
    display(L);
    
    insertSorted(L, 20);
    insertSorted(L, 40);
    display(L);
    
    locate(L, 40);
    locate(L, 30);
    retrieve(L, 1);
    retrieve(L, 2);
    
    deletePos(L, 4);
    deletePos(L, 0);
    deletePos(L, 2);
    display(L);
}

void initialize(Eptr L){
    L->count = 0;
}

void insertPos(Eptr L, int data, int pos){
     if(L->count!=MAX && pos <= L->count){
        for(int i = L->count; i > pos; i--){
            L->elem[i] = L->elem[i-1];
        }
        L->elem[pos] = data;
        L->count++;
        printf("Insertion Successfull.\n");
    }else{
        printf("Position invalid or the array is full.\n");
    }
}
void deletePos(Eptr L, int pos){
    if(pos >= 0 && pos < L->count){
        for(int i = pos; i < L->count-1; i++){
            L->elem[i] = L->elem[i+1];
        }
        L->count--;
        printf("Deletion Succcessful.\n");
    }else{
        printf("Position invalid.\n");
    }
}
int locate(Eptr L, int data){
    int i = 0;
    for( ; i < L->count && L->elem[i] != data; i++){ }
    if(i == L->count){
        return -1;
        printf("Invalid position or not in List.");
    }else{
        printf("The Location of the element %d is at position %d.\n", data, i+1);
        return i;
    }
}
int retrieve(Eptr L, int pos){
    int i = 0;
    for( ; i < L->count && L->elem[i] != L->elem[pos]; i++){ }
    if(i == L->count){
        return -1;
        printf("Invalid position or not in List.");
    }else{
         printf("The Element in the location %d is %d.\n", i+1, L->elem[i]);
    }
}

void insertSorted(Eptr L, int data){
    int i = 0;
    for(; i < L->count && L->elem[i] < data; i++){ }
    return insertPos(L, data, i);
}

void display(Eptr L){
     if(L->count != 0){
        printf("Element List: \n");
        for(int i = 0; i < L->count; i++){
            if(i == L->count -1){
                printf("%d\n", L->elem[i]);
            }else{
                printf("%d ", L->elem[i]);
            }
        }
    }else{
        printf("List is Empty.\n");
    }
}
void makeNULL(Eptr L){
    L->count = 0;
}
