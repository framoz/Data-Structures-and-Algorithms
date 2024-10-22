#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> l(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        cin >> l[i];
    }
    sort(a.begin(), a.end());
    sort(l.begin(), l.end());
    int max = 0, j = 0, counter = 0;
    
    for (int i = 0; i < N; i++){
        counter ++;
        if (a[i] >= l[j]){
            counter --;
            j++;
        }
        if (counter > max) max = counter;
    }

    cout << max << endl;

        return 0;
}