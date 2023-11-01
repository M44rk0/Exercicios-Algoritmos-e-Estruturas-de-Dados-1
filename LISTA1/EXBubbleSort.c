#include <stdio.h>


void sort(int numeros[], int size){

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(numeros[j] > numeros[j+1]){
                int temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;
            }
        }
    }

}

void printSorted(int numeros[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", numeros[i]);
    }
}


int main(){

    int numeros[] = {5, 7, 81, 45, 34, 2, 7, 20, 12, 34, 67, 31, 13, 10, 8, 97};
    int size = sizeof(numeros)/sizeof(numeros[0]);

    sort(numeros, size);
    printSorted(numeros, size);

    return 0;

}