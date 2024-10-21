#include <iostream>

using namespace std;

int lower_bound(int array[], long size, int boundary){
    long high = size-1;
    long low = 0;

    while (high > low){
        long middle = low + (high - low) / 2;
        if(array[middle] >= boundary) high = middle;
        else low = middle +1;        
    }
    if(array[low] < boundary) return -1;

    return low;
    }



int main(){

    int size;
    cin >> size;
    int* array = new int[size];
    for (int i= 0; i<size; i++){
        int num;
        cin >> num;
        array[i] = num;
    }

    int g;
    cin >> g;
    while (g){
        int boundary;
        cin >> boundary;
        
        g--;
    }

    return 0;
}