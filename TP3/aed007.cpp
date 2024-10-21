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
   // if(low == size-1) return low +1;
    //if  (array[low] < boundary) return -1;

    return low;
    }

int upper_bound(int array[], long size, int boundary) {
    long high = size - 1;
    long low = 0;

    while (high > low) {
        long middle = low + (high - low + 1) / 2;
        if (array[middle] > boundary) high = middle - 1;
        else low = middle;
    }
    if(low == 0) return -1;
    // if (array[low] > boundary) return -1;

    return low;
}

int interval(int array[], int size, int lower, int higher){
    
    
    return (upper_bound(array, size, higher+1)-lower_bound(array, size, lower));
    

}


int main(){

    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i<size; i++){
        cin >> array[i];
    }

    int q;
    cin >> q;

    for (; q>0; q--){
        int lower;
        cin >> lower;
        int higher;
        cin >> higher;

        cout << interval(array, size, lower, higher) << endl;
    }

    return 0;
}