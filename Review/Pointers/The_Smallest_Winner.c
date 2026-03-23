#include <stdio.h>

int main(){
    int w1, w2, w3;
    int* ptr;
    
    printf("Enter the first weight: ");
    scanf("%d",&w1);
    printf("Enter the second weight: ");
    scanf("%d",&w2);
    printf("Enter the third weight: ");
    scanf("%d",&w3);

    if(w1 < w2 && w1 <w3){
        ptr = &w1;
    }else if(w2 < w3){
        ptr = &w2;
    }else{
        ptr = &w3;
    }

    printf("Smallest weight = %d ", *ptr);
    
    return 0;
}