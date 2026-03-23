#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- Code Runner is Very complicated when there' multiple files, and I suck at terminal commands ---- */

/* ---- Begin cis1101.h contents ---- */
#ifndef CIS1101_H
#define CIS1101_H

typedef char* String;

String input_string(void);
int input_integer(void);

#endif
/* ---- End cis1101.h contents ---- */

/* ---- Begin cis1101.c contents ---- */
String input_string(void) {
    String value;
    char temp[100];
    
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';  // remove newline
    value = malloc(strlen(temp) + 1);
    strcpy(value, temp);
    
    return value;
}

int input_integer(void) {
    int value;
    scanf("%d", &value);
    return value;
}
/* ---- End cis1101.c contents ---- */

/* ---- Your main() ---- */
int main() {
    String name;
    printf("Enter your Name: ");
    name = input_string();

    printf("Now I know you are called %s, %s, %s.\n\n", name, name, name);
    printf("I will remember you.\n");
    free(name);
    return 0;
}