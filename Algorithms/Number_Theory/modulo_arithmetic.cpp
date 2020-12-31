#include<iostream>
using namespace std;

/*

Modulo Arithmetic introduction

(N1 + N2) % mod = (N1 % mod + N2 % mod) % mod

(N1 * N2) % mod = ((N1 % mod) * (N2 % mod)) % mod

Euclid Division Algorithm

GCD(a, b) =  a    if b == 0
          = GCD(b, a mod b) otherwise

Note the following
GCD(a, b) = GCD(b, a)

GCD(A, 0) = GCD(0, A)

GCD(A, B) = GCD(A-B, B) = GCD(A, B-A)

GCD(A, B) = GCD(A+B, B) = GCD(A, B+A)

*/

int gcd(int a, int b)
{
    // Complexity = log(max(a, b))
    
    if(b == 0)
    {
        return a;
    }
    else
    {
        return(gcd(b, a % b));
    }
    
}


int main()
{
    int a,b,gc;
    cin>>a>>b;
    gc = gcd(a,b);
    cout<<"GCD = "<<gc<<endl;
    return(0);
}
