#include <stdio.h>

int count(int number);

int main(){
    int digits, integer;

    printf("Enter an Integer: ");
    scanf("%d", &integer);

    digits = count(integer);
    printf("Number of digits: %d", digits);

    return 0;
}

int count(int number){
    int count = 0;
    if(number == 0){
        return count++;
    }else{
        if(number < 0) number = -number;
        while(number != 0){
            number /=10;
            count++;
        }
    }
    return count;
}