#include <stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n){
    int flag;
    
    for(int i = 0; i < n; i++){
        flag = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    
}

int main(void){
    int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int sizeArr = (int) sizeof(arr) / sizeof(int);
    
    bubbleSort(arr, sizeArr);
    
    printf("arr sorted: ");
    for(int i = 0; i < sizeArr; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}