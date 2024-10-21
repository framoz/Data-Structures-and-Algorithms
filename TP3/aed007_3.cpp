#include <iostream>
#include <functional>

using namespace std;

int bsearch(int array[],int high, int bar, auto& condition)
{   
    int low = 0;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (condition(mid, bar))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int interval(int array[], int size, int lower, int higher)
{   auto f1 = [](int i, int j){return i<= j;}; //high bound
    auto f2 = [](int i, int j){return i>=j;}; //low bound

    return bsearch(array, size -1, higher,f1) - bsearch(array, size-1, lower, f2);
}

int main()
{

    int size;
    cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    int q;
    cin >> q;

    for (; q > 0; q--)
    {
        int lower;
        cin >> lower;
        int higher;
        cin >> higher;

        cout << interval(array, size, lower, higher) << endl;
    }

    return 0;
}
