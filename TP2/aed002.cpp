#include <iostream>
//#include <limits.h>

using namespace std;

int main(){

    int size;

    std::cin >> size;
    
    int max_sum = -200000;

   
    int cur_sum = 0;

  
    
    for (int i = 0; i<size ; i++){
        int value;
        
        std::cin >> value;
        
        cur_sum += value;
        
        if (cur_sum > max_sum){
            max_sum = cur_sum;
        }
        if(cur_sum<0){
            cur_sum= 0;
        }
             
    }

    cout << max_sum << endl;

    return 0;
}