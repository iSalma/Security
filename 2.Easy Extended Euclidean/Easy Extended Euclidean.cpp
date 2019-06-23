#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long x, long long y) 
{
   return y == 0 ? x: gcd(y, x % y);
}

int coprime(long long a, long long b) { 
    int res;
    if ( gcd (a, b) == 1) 
        res=1;
    else
        res=0;
	return res;
} 


long long modAdd(long long n, long long m) 
{ 
   /* n = n%m; 
    for (long long i=1; i<m; i++) 
       if ((n+i) % m == 0) 
          return i; */
	if (n>m)
	   n=n%m;

	while (n<0)
	   n=n+m;

	return m-n;
}

long long gcdEx(long long a, long long b, long long *x, long long *y) 
{ 
    
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    long long x1, y1; 
    long long gcd = gcdEx(b%a, a, &x1, &y1); 
 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd;
}

long long modInv(long long a, long long m) 
{  
	long long x,y;
	long long g = gcdEx(a, m, &x, &y); 

        long long res = (x%m + m) % m; 
		 while (res < 0) 
           res += m; 

        return res;
    
} 


int main()
{
	long long mod,num;
    cin>> mod>>num;
	int copr= coprime (num, mod);
	if (copr == 0)
	{
	  cout<<"IMPOSSIBLE";
	}
	else
	{
	    cout << modAdd(num, mod)<<" ";
		cout << modInv(num, mod);
	}

//	int xx; cin>> xx;
    return 0;
}