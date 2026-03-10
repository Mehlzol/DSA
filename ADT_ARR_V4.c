/* ADT LIST VARIATION 4 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void inSort(List* L, int data);
void display(List* L);
void resize(List* L);
void makeNull(List* L);

int main(){
    List myList;
    List* L = &myList;
    initialize(L);
    return 0;
}

void initialize(List* L){
    L->elemPtr = (char*)malloc(sizeof(char)*LENGTH);
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(List* L, char data, int pos){
    if(pos > L->count){
        printf("Invalid Position.\n");
    }else{
        if(L->max == L->count){
            resize(L);
    }
        for(int i = L->count; i > pos ; i--){
            L->elemPtr[i] = L->elemPtr[i-1];
        }
        L->elemPtr[pos] = data;
        L->count++;
    }
    
}

void deletePos(List* L, int pos){
    if(pos >= L->count){
        printf("Invalid Position");
    }else{
        for(int i = pos; i < L->count-1; i++){
            L->elemPtr[i] = L->elemPtr[i+1];
        }
        L->count--;
    }
    
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
    if(pos >= 0 && pos > L->count){
        return L->elemPtr[pos];
    }else{
        return -1;
    }
}

List insertSorted(List* L, char data){
    int i;
    for(i = 0; L->elemPtr[i] < data && i < L->count; i++){ }
    insertPos(L, data, i);
}

void display(List* L){
    if(L->count != 0){ 
        printf("Character Elements:\n");
            for(int i = 0; i < L->count; i++){
                if(i == L->count-1){
                    printf("%c\n", L->elemPtr[i]);
                }else{
                    printf("%c ", L->elemPtr[i]);
                }
            }
        }else{
            printf("List is Empty.");
    }
}

void resize(List* L){
    L->max *= 2;
    L->elemPtr = realloc(L->elemPtr, sizeof(char)*L->max);
    
}