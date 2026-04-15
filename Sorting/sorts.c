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

void insertionSort(int arr[], int n){
   for(int i = 1; i < n; i++){
       int j= i - 1;
       int x = arr[i];
       while(j > -1 && arr[j] > x){
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = x;
   } 
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n -1; i++){
        int k;
        for(int j = k = i; j < n; j++){
            if(arr[j] < arr[k])
                k = j;
        }
        swap(&arr[i], &arr[k]);
    }
}

int main(void){
    int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int sizeArr = (int) sizeof(arr) / sizeof(int);
    
    // bubbleSort(arr, sizeArr);
    
    // printf("arr sorted: ");
    // for(int i = 0; i < sizeArr; i++){
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    
    // insertionSort(arr, sizeArr);
    // printf("arr sorted: ");
    // for(int i = 0; i < sizeArr; i++){
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    
    selectionSort(arr, sizeArr);
    printf("arr sorted: ");
    for(int i = 0; i < sizeArr; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}