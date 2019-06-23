#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

unsigned gcd(unsigned a, unsigned b) {
    return b == 0 ? a : gcd(b, a % b);
}
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
  
    else
        return gcd(b, a % b); 
}   
void leftrotate(int arr[], int d, int n) 
{ 
    for (int i = 0; i < gcd(d, n); i++) 
	{ 
        int temp = arr[i]; 
        int j = i; 
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
            if (k == i) 
                break; 
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 
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

int main()
{   
	int PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
	int PC2[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
	int Rotations [16]= {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	string keyinhex; //0123456789ABCDEF
	cin>> keyinhex;
	if (keyinhex.length()<16)
	{
		int diff = 16 - keyinhex.length();
		string add;
		for(int i=0; i<diff; i++)
		{
			add+='0';
		}
		keyinhex= add+keyinhex;
	}
	string keyinbin = hextobin(keyinhex);
	int arrkeyinbin [64];
	for (int i =0; i< 64; i++)
	{
	   arrkeyinbin[i] = keyinbin[i] - '0';
	   //cout<<arrfirstinbin[i];
	}

	int arrPC1out [56];
	for( int i=0; i<56; i++)
	{
		arrPC1out[i]= arrkeyinbin[PC1[i]-1];
		//cout<< arrPC1out[i];
	}
	for(int round=0; round<16; round++)
	{
		int shift = Rotations[round];
		int arrSLout [56];
		int arrSL1out[28];
		int arrSL2out[28];
		for(int i=0; i<28; i++)
		{
			arrSL1out[i]=arrPC1out[i]; 
		}
		//for(int i=0; i<28; i++){cout<< arrSL1out[i];}
		//cout<<endl;
		leftrotate(arrSL1out, shift, 28);
		//for(int i=0; i<28; i++){cout<< arrSL1out[i];}
		
		for(int i=28; i<56; i++)
		{
			arrSL2out[i-28]=arrPC1out[i];  
		}
		//for(int i=0; i<28; i++){cout<< arrSL2out[i];}
		//cout<<endl;
		leftrotate(arrSL2out, shift, 28);
		//for(int i=0; i<28; i++){cout<< arrSL2out[i];}

		for(int i=0; i<56; i++)
		{
			if (i<28)
				arrSLout[i]= arrSL1out[i];
			else
		        arrSLout[i]= arrSL2out[i-28];
		}
		//for(int i=0; i<56; i++){cout<< arrSLout[i];}
		//cout<<endl;
		 for( int i=0; i<56; i++)
	     {
	     	arrPC1out[i]= arrSLout[i];
	    	//cout<< arrPC1out[i];
	     }

		int arrPC2out [48];
		for( int i=0; i<48; i++)
		{
			arrPC2out[i]= arrSLout[PC2[i]-1];
			//cout<< arrPC2out[i];
		}

		stringstream osp;
		string outkey;
		for (int i=0; i<48; i++)
		{
			osp << arrPC2out[i];
		}
	   outkey=osp.str();
	   //cout<<outkey;
	   int fout= 0;
	   int k =0;
	   do {
			int b = outkey[k]=='1'?1:0;
			fout = (fout<<1)|b;
			k++;
		  } while (k<16);
		printf("%04X", fout);
		 fout= 0;
		k =16;
		do {
			int b = outkey[k]=='1'?1:0;
			fout = (fout<<1)|b;
			k++;
		  } while (k<48);
	   printf("%08X", fout);
	   cout<<endl;
		//break;
	}

    //int xxx; cin>> xxx;
    return 0;
} 