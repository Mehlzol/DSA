/* ADT LIST VARIATION 3 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 10

typedef struct{
    char *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, char data, int pos);
List deletePos(List L, int pos);
int locate(List L, char data);
List insertSorted(List L, char data);
void display(List L);
List resize(List L);

int main(){
    List L = initialize(L);
    display(L);

    //insertPos
    L = insertPos(L, 'A', 0);
    L = insertPos(L, 'C', 1);
    L = insertPos(L, 'F', 2);
    display(L);

    //inSort
    L = insertSorted(L,'G');
    L = insertSorted(L,'B');
    L = insertSorted(L,'D');
    display(L);

    int lct = locate(L,'A');
    
    //deletePos
    L = deletePos(L, 4);
    L = deletePos(L, 0);
    L = deletePos(L, 2);
    display(L);
    return 0;
}

List initialize(List L){
    L.elemPtr = (char*)malloc(sizeof(char)*LENGTH);
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List insertPos(List L, char data, int pos){
    if(pos > L.count){
        printf("Invalid Position.\n");
    }else{
        if(L.max == L.count){
        L = resize(L);
    }
        for(int i = L.count; i > pos ; i--){
            L.elemPtr[i] = L.elemPtr[i-1];
        }
        L.elemPtr[pos] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int pos){
    if(pos >= L.count){
        printf("Invalid Position.\n");
    }else{
        for(int i = pos; i < L.count-1; i++){
            L.elemPtr[i] = L.elemPtr[i+1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, char data){
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, char data){
    int i;
    for(i = 0; i < L.count && L.elemPtr[i] < data; i++){ }
    return insertPos(L, data, i);
}

void display(List L){
    if(L.count != 0){ 
        printf("Character Elements:\n");
            for(int i = 0; i < L.count; i++){
                if(i == L.count-1){
                    printf("%c\n", L.elemPtr[i]);
                }else{
                    printf("%c ", L.elemPtr[i]);
                }
            }
        }else{
            printf("List is Empty.\n");
    }
}

List resize(List L){
    L.max *= 2;
    L.elemPtr = realloc(L.elemPtr, sizeof(char)*L.max);
    return L;
}
