#include <iostream>
#include <string>
#include <sstream>
using namespace std;

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
	int EP [48]= {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16,
		          17, 18, 19, 20, 21,20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
	int SP [32]= {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};

	int S1[4][16] = {
	{ 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
	{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
	{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
	{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }
	};
    int S2[4][16] = {
	{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
	{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
	{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
	{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }
	};
	int S3[4][16] = {
	{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
	{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
	{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
	{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }
    };
	int S4[4][16] = {
	{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
	{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
	{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
	{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }
	};
	int S5[4][16] = {
	{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
	{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
	{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
	{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }
	};
	int S6[4][16] = {
	{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
	{ 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
	{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
	{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }
	};
	int S7[4][16] = {
	{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
	{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
	{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
	{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }
	};
	int S8[4][16] = {
	{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
	{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
	{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
	{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
	};

	string firstinhex; //F0AAF0AA
	cin>> firstinhex;
	string firstinbin = hextobin(firstinhex);
	int arrfirstinbin [32];
	for (int i =0; i< 32; i++)
	{
	   arrfirstinbin[i] = firstinbin[i] - '0';
	   //cout<<arrfirstinbin[i];
	}
	
	int arrEPout [48];
	for( int i=0; i<48; i++)
	{
		arrEPout[i]= arrfirstinbin[EP[i]-1];
		//cout<< arrEPout[i];
	}

	string key1hex; //0B02679B49A5
	cin>> key1hex;
	string key1bin = hextobin(key1hex);
	int arrkey1bin [48];
	for (int i =0; i< 48; i++)
	{
	   arrkey1bin[i] = key1bin[i] - '0';
	   //cout<<arrkey1bin[i];
	}

	int xorout[48];
	for (int i =0; i< 48; i++)
	{
	   xorout[i]= arrEPout[i] ^ arrkey1bin[i];
	   //cout<<xorout[i];
	}
	
	string xoroutbin= int_array_to_string (xorout, 48);
	//cout<< xoroutbin;

	char inarr[8][6]; 
	int i=0;
	for(int row=0; row < 8; row++)
	{
		for(int column=0;column < 6; column++)
			{
				inarr[row][column] = xoroutbin[i];
				i++;
			}
	}
	//for(int row=0; row < 8; row++)
	//{
	//  for(int column=0;column < 6; column++)
	//  {
	//	cout<< inarr[row][column];
	//  }
	//  cout<<endl;
	//}
	string srow[8];
	int binrow [8];
	int decrow[8];

	string scol[8];
	int bincol [8];
	int deccol[8];

	for(int i=0; i<8; i++)
	{
		srow[i].push_back(inarr[i][0]);
		srow[i].push_back(inarr[i][5]);
		stringstream rowconvt(srow[i]) ;
		rowconvt >> binrow[i]; 
		decrow[i] = bintodec (binrow[i]);

		scol[i].push_back(inarr[i][1]);
		scol[i].push_back(inarr[i][2]);
		scol[i].push_back(inarr[i][3]);
		scol[i].push_back(inarr[i][4]);
		stringstream colconvt(scol[i]) ;
		colconvt >> bincol[i]; 
		deccol[i] = bintodec(bincol[i]);
	}
	
	int soutdec[8];
	soutdec[0] = S1 [decrow[0]][deccol[0]];
	soutdec[1] = S2 [decrow[1]][deccol[1]];
	soutdec[2] = S3 [decrow[2]][deccol[2]];
	soutdec[3] = S4 [decrow[3]][deccol[3]];
	soutdec[4] = S5 [decrow[4]][deccol[4]];
	soutdec[5] = S6 [decrow[5]][deccol[5]];
	soutdec[6] = S7 [decrow[6]][deccol[6]];
	soutdec[7] = S8 [decrow[7]][deccol[7]];

	for(int i=0; i<8; i++)
	{
		//cout<<srow[i]<<endl;;
		//cout<<scol[i]<<endl;
		//cout<< binrow[i]<<endl;
		//cout<<bincol[i]<<endl;
		//cout<<decrow[i]<<endl;
		//cout<<deccol[i]<<endl;
		//cout<<soutdec[i]<<endl;
	}

	stringstream sshexout;
	for(int i=0; i<8; i++)
	{
	  sshexout<<uppercase<< hex << soutdec[i];
	}
    string shexout (sshexout.str());
    //cout <<shexout;
 
	string sbinout = hextobin(shexout);
	int arrsbinout [32];
	for (int i =0; i< 32; i++)
	{
	   arrsbinout[i] = sbinout[i] - '0';
	   //cout<<arrsbinout[i];
	}

	int arrSPout [32];
	for( int i=0; i<32; i++)
	{
		arrSPout[i]= arrsbinout[SP[i]-1];
		//cout<< arrSPout[i];
	}
	stringstream op;
	string outsp;
	for (int i=0; i<32; i++)
	{
		op << arrSPout[i];
	}
   outsp=op.str();
   //cout<<outsp;
     int num = 0;
   int ii =0;
   do {
        int b = outsp[ii]=='1'?1:0;
        num = (num<<1)|b;
        ii++;
      } while (ii<32);
     printf("%X", num);
   // int xxx; cin>> xxx;
    return 0;
} 