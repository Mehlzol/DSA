#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct {
    int bits[MAX];
}SET;

SET UNION(SET A, SET B){
    SET C;
    for(int i = 0; i<MAX; i++){
        C.bits[i] = A.bits[i] | B.bits[i];
    }
    return C;
}

SET INTERSECTION(SET A, SET B){
    SET C;
    for(int i = 0; i<MAX; i++){
        C.bits[i] = A.bits[i] & B.bits[i];
    }
    return C;
}

SET DIFFERENCE(SET A, SET B){
    SET C;
    for(int i = 0; i<MAX; i++){
        C.bits[i] = A.bits[i] & !B.bits[i];
    }
    return C;
}


void main(){
    
}