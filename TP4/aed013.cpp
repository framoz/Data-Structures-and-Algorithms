#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
    int value;
    int bits;
}number;

int countbit(int num){
    int c = 0;
    while (num >0){
        c += num & 1;
        num = num >> 1;
    }
    return c;
}


int main(){

    int N;
    cin >> N;
   
    vector<number> sequence(N);
    for (int i=0; i<N; i++){
       cin >> sequence[i].value;
       sequence[i].bits = countbit(sequence[i].value);
    }

    sort(sequence.begin(), sequence.end(), [](number &a, number& b){
        if (a.bits > b.bits) return true;
        
        if (a.bits == b.bits && a.value < b.value) return true;
        return false;
    });

    for (int i = 0; i<N; i++){
        cout << sequence[i].value << endl;
    }

}