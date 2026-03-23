#include<stdio.h>

int get_even(int num);
int get_odd(int num);

int main(void){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    return 0;
}

int get_even(int num){
    while((num/=2)== 0){
        //sakto ba? wth
    }
}
int get_odd(int num);