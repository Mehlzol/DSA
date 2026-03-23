/* ADT LIST VARIATION 1 */
#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int pos);
List deletePos(List L, int pos);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

void main(){
    List L = initialize(L);
    
    L = insertPos(L,10,0);    
    L = insertPos(L,30,1);
    L = insertPos(L,50,2);
    display(L);
    
    L = insertSorted(L, 20);
    L = insertSorted(L, 40);
    display(L);
    
    locate(L, 40);
    locate(L, 30);
    
    L = deletePos(L, 4);
    L = deletePos(L, 0);
    L = deletePos(L, 2);
    display(L);
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int pos){
    if(L.count!=MAX && pos <= L.count){
        for(int i = L.count; i > pos; i--){
            L.elem[i] = L.elem[i-1];
        }
        L.elem[pos] = data;
        L.count++;
        printf("Insertion Successfull.\n");
    }else{
        printf("Position invalid or the array is full.\n");
    }
    return L;
}

List deletePos(List L, int pos){
    if(pos >= 0 && pos < L.count){
        for(int i = pos; i < L.count-1; i++){
            L.elem[i] = L.elem[i+1];
        }
        L.count--;
        printf("Deletion Succcessful.\n");
    }else{
        printf("Position invalid.\n");
    }
    return L;
}

int locate(List L, int data){
    int i = 0;
    for( ; i < L.count && L.elem[i] != data; i++){ }
    if(i == L.count){
        return -1;
    }else{
        printf("The Location of the element is at position %d.\n", i+1);
        return i;
    }
}

List insertSorted(List L, int data){
    int i = 0;
    for(; i < L.count && L.elem[i] < data; i++){ }
    return insertPos(L, data, i);
}

void display(List L){
    if(L.count != 0){
        printf("Element List: \n");
        for(int i = 0; i < L.count; i++){
            if(i == L.count -1){
                printf("%d\n", L.elem[i]);
            }else{
                printf("%d ", L.elem[i]);
            }
        }
    }else{
        printf("List is Empty.\n");
    }
}