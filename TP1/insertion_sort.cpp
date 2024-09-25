#include <iostream>


void insertion_sort(int* array, int n){
    for (int i = 1; i<n; i++){
      
        int key = array[i];
        int j = i-1;

        while (j>=0 && array[j]<key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

int main(){

    int array[] = {5, 2, 4, 6, 1, 3};

    insertion_sort(array, 6);

    for (int i= 0; i<6; i++){
        std::cout << array[i] << ", ";
    }

    return 1;
}