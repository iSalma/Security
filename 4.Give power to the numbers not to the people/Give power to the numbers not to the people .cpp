#include <iostream>
using namespace std;

unsigned long long powMod(unsigned long long num, unsigned long long pow, unsigned long long mod)
{
    unsigned long long final;
    for(final = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            final = ((final % mod) * (num % mod)) % mod;

        num = ((num % mod) * (num % mod)) % mod;
    }
    return final;
}

int main()
{

   long long a,b,c;
   cin>> a>>b>>c;
    cout << powMod(a, b, c); 
//	int xx; cin>> xx;
    return 0;
}