#include <iostream>

int main(){
    long i;
    std::cin >> i;

    long* array = new long[i];

    for (long h = 0; h<i ; h++){
        std::cin >> array[h];
    }

    int q;
    std::cin >> q;


    while(q!= 0){
    long key;
    std::cin >> key;

    long low = 0;
    long high = i;
    bool not_found = true;
   
    while (low <= high){
        long middle = low + (high -low)/2;
        if (key < array[middle]) high = middle -1;
        else if (key > array[middle]) low = middle +1;
        else {std::cout << middle << std::endl; not_found = false; low = high +1;} 
    }

    if (not_found) std::cout << "-1" << std::endl;
    q--;
    }
    
    return 0;
}