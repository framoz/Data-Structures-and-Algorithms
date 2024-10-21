#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    // N players
    cin >> N;

    int K;
    cin >> K;

    vector <int> vec(N);

    for(int i = 0; i<N; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for (int i = 1;i<=K;i++){
        cout <<vec[N-i]<< "\n";
    }

    return 0;
}