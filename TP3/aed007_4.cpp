#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int interval(vector<int> &seq, int l, int h){
   
    auto left = lower_bound(seq.begin(), seq.end(), l);
    auto right = upper_bound(seq.begin(), seq.end(), h);

    return distance(left, right);
}

int main(){
   

    int size;
    cin >> size;
    vector<int> sequence(size);
    for (int i = 0; i < size; i++)
    {
        cin >> sequence[i];
    }

    int q;
    cin >> q;

    for (; q > 0; q--)
    {
        int lower;
        cin >> lower;
        int higher;
        cin >> higher;

        cout << interval(sequence, lower, higher) << endl;
    }

    return 0;
}