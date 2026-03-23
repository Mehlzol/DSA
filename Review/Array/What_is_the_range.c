#include<stdio.h>

int get_smallest(int array[], int n);
int get_largest(int array[], int n);
int compute_range(int array[], int n);

int main(void) {
    // Hey there, start typing your C code here...
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int min, max, range;
    min = get_smallest(arr,n);
    max = get_largest(arr, n);
    range = compute_range(arr, n);

    printf("\nMIN: %d", min);
    printf("\nMAX: %d", max);
    printf("\nRANGE: %d", range);

    return 0;
}

int get_smallest(int array[], int n) {
  	// To do code logic here...
    int smallest = array[0];
    for(int i = 0; i < n ; i++){
        if(smallest > array[i]){
            smallest = array[i];
        }
    }
    return smallest;
}

int get_largest(int array[], int n) {
  	// To do code logic here...
    int largest = array[0];
    for(int i = 0; i < n ; i++){
        if(largest < array[i]){
            largest = array[i];
        }
    }
    return largest;
}

int compute_range(int array[], int n) {
  	// To do code logic here...
    int smallest = get_smallest(array, n);
    int largest = get_largest(array, n);
    return largest - smallest;
}