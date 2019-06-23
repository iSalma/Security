#include <iostream>
#include <vector>
#include<string>
#include<sstream>
using namespace std;

string hextobin (string sHex)
		{
			string sReturn = "";
			for (int i = 0; i < sHex.length (); ++i)
			{
				switch (sHex [i])
				{
					case '0': sReturn.append ("0000"); break;
					case '1': sReturn.append ("0001"); break;
					case '2': sReturn.append ("0010"); break;
					case '3': sReturn.append ("0011"); break;
					case '4': sReturn.append ("0100"); break;
					case '5': sReturn.append ("0101"); break;
					case '6': sReturn.append ("0110"); break;
					case '7': sReturn.append ("0111"); break;
					case '8': sReturn.append ("1000"); break;
					case '9': sReturn.append ("1001"); break;
					case 'A': sReturn.append ("1010"); break;
					case 'B': sReturn.append ("1011"); break;
					case 'C': sReturn.append ("1100"); break;
					case 'D': sReturn.append ("1101"); break;
					case 'E': sReturn.append ("1110"); break;
					case 'F': sReturn.append ("1111"); break;
				}
			}
			return sReturn;
		}
string int_array_to_string(int int_array[], int size_of_array) 
{
  ostringstream oss("");
  for (int temp = 0; temp < size_of_array; temp++)
  oss << int_array[temp];
  return oss.str();
}
int bintodec(int n)
{
    int factor = 1;
    int result = 0;

    while (n != 0)
    {
        result += (n%10) * factor;
        n /= 10;
        factor *= 2;
    }
    return result;
}

int arrtonum (int arr[], int n)
{
	int i, k=0;
	for (i=0; i<n; i++)
	{
	  k=10*k + arr[i];
	}
	return k;
}

int gfMul(int n1, int n2) {
    int res= 0;
	int overflow = 0x100, mod = 0x11B;
    while (n2 > 0) {
        if (n2 & 1) res = res ^ n1;             
        n2 = n2 >> 1;                           
        n1 = n1 << 1;                           
        if (n1 & overflow) n1 = n1 ^ mod;    
    }
    return res;
}

int main()
{
	string h1,h2;
    cin>> h1>>h2;
	string b1 =hextobin(h1);
	string b2 =hextobin(h2);
	int *arrb1 = new int [8];
	int *arrb2 = new int [8];
	for (int i =0; i< 8; i++)
	{
	   arrb1[i] = b1[i] - '0';
	   //cout<<arrb1[i];
	}
	//cout<<endl;


	for (int i =0; i< 8; i++)
	{
	   arrb2[i] = b2[i] - '0';
	  // cout<<arrb2[i];
	}
	//cout<<endl;

	int xorout[8];
	for (int i =0; i< 8; i++)
	{
	   xorout[i]= arrb1[i] ^ arrb2[i];
	   ////cout<<xorout[i];
	}
	//cout<<endl;
	string xoroutbin= int_array_to_string (xorout, 8);
	//cout<< xoroutbin;

   int num = 0;
   int ii =0;
   do {
        int b = xoroutbin[ii]=='1'?1:0;
        num = (num<<1)|b;
        ii++;
      } while (ii<8);
    printf("%02X", num);

	int arrbin1 =arrtonum(arrb1, 8);
	int arrbin2 =arrtonum(arrb2, 8);
	int dec1 = bintodec (arrbin1);
	int dec2 = bintodec (arrbin2);

	int mul = gfMul(dec1,dec2);
	cout<<" ";
	printf("%02X", mul);

//	int xx; cin>> xx;
    return 0;
}