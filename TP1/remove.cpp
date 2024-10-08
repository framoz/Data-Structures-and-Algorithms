#include <iostream>

int Remove(int v, int* x, int n){
    int t = 0;
    int p = 0;

    while (p<n) {
        if (x[p]<= v){
            x[t] = x[p];
            t++;
        }
        p++;
    }
    
    return t;
}


int main(){

    int array[] = {2,9,8,5,4};

    

    int t = Remove(5, array, 5);
    
    std::cout << t << "\n";

    for (int i= 0; i<5; i++){
        std::cout << array[i] << ", ";
    }
    std::cout << "\n";

    return 1;
}