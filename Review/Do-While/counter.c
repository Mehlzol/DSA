#include <stdio.h>

int main(){
    int pos = 0, neg = 0, zero = 0, i = 0;
    do{
        int integer;
        printf("Enter Integer: ");
        scanf("%d", &integer);
        if(integer == 0){
            zero++;
        }else if(integer < 0){
            neg++;
        }else{
            pos++;
        }
        i++;
    }while(i<5);

    printf("\nPositive Count: %d", pos);
    printf("\nNegative Count: %d", neg);
    printf("\nZero Count: %d", zero);
    return 0;
}