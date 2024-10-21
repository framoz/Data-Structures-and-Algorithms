#include <iostream>

using namespace std;

int lower_bound(int array[], long size, int boundary)
{
    long high = size;
    long low = 0;

    while (high > low)
    {
        long middle = low + (high - low) / 2;
        if (array[middle] < boundary)
            low = middle +1;
        else
            high = middle;
    }
    // if (!(array[low] >= boundary) && low != size -1)
    //     return -1;
    if (low == size - 1 && array[low] != array[low - 1])
        return size;
    return low;
}

int upper_bound(int array[], long size, int boundary)
{
    long high = size;
    long low = 0;

    while (high > low)
    {
        long middle = low + (high - low) / 2;
        if (array[middle] <= boundary)
            low = middle +1;
        else
            high = middle;
    }    

    return low;
}

int interval(int array[], int size, int lower, int higher)
{
    // int a = upper_bound(array, size, higher);
    // int b = lower_bound(array, size, lower);

    return (upper_bound(array, size, higher) - lower_bound(array, size, lower));
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