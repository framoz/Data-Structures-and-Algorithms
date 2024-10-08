#include <iostream>


using namespace std;

int main(){

    int size = 0;

    cin >> size;

    for (int i = 0; i<size; i++){
        int number = 0;
        cin >> number;
        bool prime = true;
        for (int j = 2; j*j <= number; j++){
            if (!(number%j)){
               prime = false;
                break;
            }
        }

        if (prime){
            cout << number << " is prime" << endl;
        }
        else{
            cout << number << " is composite" << endl;
        }
      

    }    

    return 0;
}