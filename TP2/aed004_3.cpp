#include <iostream>


int main(){
    long n;
    std::cin >> n;
    long x= 0;
    long y = 0;
    
    long i = 1;
    while (i < n){
        x++;
        y++;
        i = (2*(x+1)-1)*(2*(x+1)-1);
    }
    long ring_side_size = 2*x+1;
    long smaller = (2*x-1)*(2*x-1)+1 ;
    
    if(n<=i && n>=i-2*(ring_side_size-1))
        //north
        if (n>= i-ring_side_size+1){
            while (n != i){
            i--;
            x--;
            }
        }
        //west
        else
        {   
            x-=ring_side_size-1;
            i-=ring_side_size;
            y--;
            while(n!=i)
            {
                i--;
                y--;
            }
        }
    else{
        //east
        if (n<=smaller + ring_side_size-2){
            i = smaller;
            y--;
            while (n != i){
            i++;
            y--;
            }
        }
        //south
        else
        {   
            y-=ring_side_size-1;
            i= smaller + ring_side_size-1;
            x--;
            while(n!=i)
            {
                i++;
                x--;
            }
        }
    }

   
   
    

    std::cout << "("<< x << "," << y << ")"<<  std::endl;
    return 0;
}     