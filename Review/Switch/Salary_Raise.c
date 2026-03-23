#include <stdio.h>
#include <ctype.h>

int main(){
    float salary, increase;
    char department;
    printf("Enter your Current salary: ");
    scanf("%f", &salary);

    if(salary <= 0){
        printf("Invalid Salary!\nInput a valid Salary");
        return 1;
    }

    printf("Enter your Department [A, B, C, D]: ");
    scanf(" %c", &department);
    department = toupper(department);

    if(department < 'A' || department > 'D') {
        printf("Invalid Department!\nInput a valid Department");
        return 1;
    }
    
    switch(department){
    case 'A':
        increase = 0.02;
    break;
    case 'B':
        increase = 0.02;
    break;
    case 'C':
        increase = 0.015;
    break;
    case 'D':
        increase = 0.03;
    break;
    default:
    printf("...");
    }
    printf("\nYour raise is %.2f%% and your salary increase is %.2f\n", increase * 100, salary * increase);
    printf("Your new salary is %.2f\n", salary + salary * increase);
    
    return 0;
}