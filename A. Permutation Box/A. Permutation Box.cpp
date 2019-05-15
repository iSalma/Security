#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
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

int main()
{
	int outnum;
	cin>> outnum;
	int *arrbox = new int [outnum];
	for (int i=0; i<outnum; i++)
	{
	   cin>>arrbox[i];
	}
	int innum;
	cin>>innum;

	string inhex;
	cin>>inhex;

	string binary = hextobin(inhex); 
   // cout << binary;

	int *arrbin = new int [innum];
	for (int i =0; i< innum; i++)
	{
	   arrbin[i] = binary[i] - '0';
	  //cout<<arrbin[i];
	}
	
	int *arrout = new int [outnum];
	for( int i=0; i<outnum; i++)
	{
		arrout[i]= arrbin[arrbox[i]-1];
		//cout<< arrout[i];
	}

	stringstream op;
	string outbin;
	for (int i=0; i<outnum; i++)
	{
		op << arrout[i];
	}
	   outbin=op.str();
	//   cout<<outbin;
	  
   int num = 0;
   int i =0;
   do {
        int b = outbin[i]=='1'?1:0;
        num = (num<<1)|b;
        i++;
      } while (i<outnum);
     printf("%X", num);
  //int xxx; cin>> xxx;
  return 0;
}