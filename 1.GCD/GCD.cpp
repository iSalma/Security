#include <iostream>
using namespace std;

int gcd(int x, int y) 
{
   return y == 0 ? x: gcd(y, x % y);
}

int main() 
{
    int na, nb;
    cin >> na;
    cin >> nb;
    cout << gcd(abs(na), abs(nb));
//	int xx; cin>>xx;
	return 0;
}