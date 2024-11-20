#include <map>
#include <iostream>

using namespace std;

int main()
{

    map<int, int> moments;

    int events;
    cin >> events;
    int id;
    cin >> id;

    moments[id] = 1;
    cout << -1;

    for (int i = 2; i < events+1; i++)
    {   
        cin >> id;
        if(moments.find(id) == moments.end()){
            moments[id] = i;
            cout << " " << -1;
        }
        else{
            cout << " " << moments[id];
            moments[id] = i;
        }
    }
    cout << endl;

    return 0;
}