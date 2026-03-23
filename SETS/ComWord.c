#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef unsigned int SET;

SET UNION(SET A, SET B){
    return A|B;
}

SET INTERSECTION(SET A, SET B){
    return A&B;
}

SET DIFFERENCE(SET A, SET B){
    return A&(~B);
}

void main(){
    SET A[MAX];
    SET B[MAX];
}
