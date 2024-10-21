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
    long middle;
    while (low < high){
        middle = low + (high -low)/2;
        if (key <= array[middle]) high = middle;
        else low = middle+1;
         
    }


    if(key <= array[high]){
        std::cout << middle << std::endl;
    }
    else{
    std::cout << -1  << std::endl;
    }
    q--;
    }
    
    return 0;
}