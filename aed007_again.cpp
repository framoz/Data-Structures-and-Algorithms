#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int interval(vector<int> &vec, int h, int l)
{
    auto left = lower_bound(vec.begin(), vec.end(), l);
    auto right = upper_bound(vec.begin(), vec.end(), h);

    return distance(left, right);
}

int main()
{

    int N;
    cin >> N;
    vector<int> seq(N);

    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i<Q; i++){
        int l, h;

        cin >> l>>h;
        cout << interval(seq, h, l);
    }
    return 0;
}