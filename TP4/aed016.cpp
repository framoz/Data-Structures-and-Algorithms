#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    string name;
    int points;
    int saldo;
}team;

bool ehofut(team &t1, team& t2){
    if(t1.points > t2.points) return true;
    else if (t1.points < t2.points) return false;

    else if(t1.saldo > t2.saldo) return true;
    else if (t1.saldo < t2.saldo) return false;

    return t1.name < t2.name;
}

int main(){

    int N;
    cin >> N;
    vector<team> v(N);
    for (int i = 0; i<N; i++){
        cin >> v[i].name;
        int w, d, l;
        cin >> w >> d >>l;
        v[i].points = 3*w + d;
        int gs, ga;
        cin >> gs >> ga;
        v[i].saldo = gs-ga;        
    }

    sort(v.begin(), v.end(),ehofut);

    for (int i = 0; i<N; i++){
        cout << v[i].name << " " << v[i].points << " "<< v[i].saldo << endl;
    }
    return 0;
}