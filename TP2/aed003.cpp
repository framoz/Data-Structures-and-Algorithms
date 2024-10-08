#include <iostream>
//#include <limits.h>

using namespace std;

int main(){


    //N Length
    int length;
    cin >> length;

    //K Positions
    int pos;
    cin >> pos;

    //T Depth
    int min_depth;
    cin >> min_depth;       
    
    int sum = 0;
   
    int res = 0;
    
    int val = 0;
    int* array = new int[length];

    for (int i = 0; i<length; i++){
        cin >> array[i];
    }

    for (int i = 0; i < pos; i++){
        int num = array[i];
        
        if (num >= min_depth){
            val++;
        }

        sum += num;
    }
    
    if (val*2 >= pos){
        res++;
    }

    for (int i = pos; i<length ; i++){           
        int first = array[i-pos];
        if (first >= min_depth){
            val--;
        }
        int last = array[i];   
        if (last >= min_depth){
            val++;
        }
        if (val*2 >= pos){
            res++;
        }              
    }

   cout << res << endl;

    return 0;
}