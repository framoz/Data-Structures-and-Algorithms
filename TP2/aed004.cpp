#include <iostream>

int main(){
    long n;
    std::cin >> n;
    int x= 0;
    int y = 0;
    bool right = true;
    bool left = false;
    bool up = false;
    bool down = false;
    if (n > 1){
            x++;
            right = false;
            down = true;            
        }
    for (long i = 2; i< n; i++){
        
        
        if(y == -1*x){
            if (x>y){
            x--;
            left = true;
            down = false;}
            else{
            x++;
            up = false;
            right = true;}
            continue;
        }        
        if(x == y+1 && y > 0){
            right = false;
            down = true;
            y--;
            continue;
        }
        if (x==y && y <0){
            up = true;
            left = false;
            y++;
            continue;
        }

        if (up){
            y++;
            continue;
        }
        if (down){
            y--;
            continue;
        }
        if (left){
            x--;
            continue;
        }
        if (right){
            x++;
            continue;
        }   
        

    }

    std::cout << "("<< x << "," << y << ")"<< std::endl;
    return 0;
}