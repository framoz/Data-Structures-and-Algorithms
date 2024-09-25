#include <iostream>

int sum_arr(int* arr, int n){
    int res = arr[0];

    for (int i = 1; i<n;i++){
        res += arr[i];
    }

    return res;
}


int main(){

    int arr[] = {1,3,4,7};

    std::cout << sum_arr(arr, 4);

    return 1;
}