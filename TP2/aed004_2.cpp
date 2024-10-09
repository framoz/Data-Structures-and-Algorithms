#include <iostream>

int main(){
    long n;
    std::cin >> n;
    int x= 0;
    int y = 0;
    if (n>1){
        x++;
    }
    long i = 2;
    while(i<n){       
            
            while((y != -1*x || !(x>y)) && i<n){
                i++;
                y--;
            }

            while((x!=y || !(y <0)) && i <n){
                i++;
                x--;
            }
              while((y!= -1*x || !(x<y))&& i <n){
                i++;
                y++;
            }   
             while((x!=y+1 || !(y>0))&& i<n){
                i++;
                x++;
            }     
    }

    std::cout << "("<< x << "," << y << ")"<< std::endl;
    return 0;
}     