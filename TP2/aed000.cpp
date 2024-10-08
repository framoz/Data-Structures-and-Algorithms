#include <iostream>

using namespace std;

int main(){

    int n;

    cin >> n;

    int count = 0;

    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        if (v == 42) count++;

    }

    cout << count << endl;

    return 0;


}
