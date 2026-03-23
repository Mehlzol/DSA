#include<stdio.h>

#define VAT 0.12
#define MAX 14
#define MIN 1

float compute_VAT(float product_price[], float mark_up_price[], char product_code, int quantity);
float compute_total_price(float product_price[], float mark_up_price[], char product_code, int quantity);

int main(void) {
    // Hey there, start typing your C code here...
    float pp[5] = {108.17, 3.7, 4.86, 4.96, 1.26};
    float mup[5] = {23.7, 0.19, 1.1, 1.3, 0.5};
    char code;
    int gallons;

    printf("Enter Product Code: ");
    scanf(" %c", &code);
    if(code < '1' || code > '5'){
        printf("Invalid Input: Please try again.");
        return 0;
    }
    printf("How many gallons? ");
    scanf("%d", &gallons);
    if(gallons < MIN || gallons > MAX){
        printf("Invalid Input: Please try again.");
        return 0;
    }

    printf("\nVAT(Value Added Tax 12%%): %.2f", compute_VAT(pp, mup, code, gallons));
    printf("\nTotal Price: %.2f", compute_total_price(pp, mup, code, gallons));

    return 0;
}

float compute_VAT(float product_price[], float mark_up_price[], char product_code, int quantity) {
	// To do code logic here...
    int ndx = product_code - '1';
    return product_price[ndx]*VAT;
}

float compute_total_price(float product_price[], float mark_up_price[], char product_code, int quantity) {
	// To do code logic here... 
    int ndx = product_code - '1'; 
    return (product_price[ndx] *quantity * (1+VAT)) + mark_up_price[ndx];
}