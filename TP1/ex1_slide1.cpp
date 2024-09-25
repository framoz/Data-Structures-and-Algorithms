#include <iostream>

using namespace std;

int PosMax(int v[],int n){

    int maxnum = v[0];
    int res = 0;
    for (int i=1; i<n; i++){
        if (maxnum < v[i]){
            res = i;
            maxnum = v[i];
        }
    }

    return res;
}

int main(){
    
    int v[] = {1, 3, 7, 2, 7, 5};
    int n = sizeof(v) / sizeof(v[0]);

    int maxPos = PosMax(v, n);
    std::cout << maxPos << "\n";

    return 1;
}