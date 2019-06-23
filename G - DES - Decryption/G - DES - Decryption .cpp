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
	int EP [48]= {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16,17, 18, 19, 20, 21,20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
	int SP [32]= {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
	int S1[4][16] = {
	{ 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
	{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
	{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
	{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }};
    int S2[4][16] = {
	{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
	{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
	{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
	{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }};
	int S3[4][16] = {
	{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
	{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
	{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
	{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }};
	int S4[4][16] = {
	{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
	{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
	{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
	{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }};
	int S5[4][16] = {
	{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
	{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
	{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
	{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }};
	int S6[4][16] = {
	{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
	{ 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
	{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
	{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }};
	int S7[4][16] = {
	{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
	{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
	{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
	{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }};
	int S8[4][16] = {
	{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
	{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
	{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
	{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }};
	int PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
	int PC2[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
	int Rotations [16]= {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	int IP[64] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
	int IP_1 [64]={40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};

	string keyinhex; 
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
		string ptxt; 
		cin>> ptxt;
		if (ptxt.length()<16)
	    {
		int diff = 16 - ptxt.length();
		string add;
		for(int i=0; i<diff; i++)
		{
			add+='0';
		}
		ptxt= add+ptxt;
	    }
		string ptxtbin = hextobin(ptxt);
		int ptxtlen = ptxtbin.length();
		int *arrptxtbin = new int [ptxtlen];
		for (int i =0; i< ptxtlen; i++)
		{
		   arrptxtbin[i] = ptxtbin[i] - '0';
		  //cout<<arrptxtbin[i];
		}
		
	int repeatnumb;
	cin>>repeatnumb;
	int arrIPout  [64];
	int arrtxtleft[32];
	int arrtxtright[32];
	if( repeatnumb ==0)
	{
		  int fout= 0;
		   int k =0;
		   do {
				int b = ptxtbin[k]=='1'?1:0;
				fout = (fout<<1)|b;
				k++;
			  } while (k<32);
			printf("%08X", fout);
			fout= 0;
			k =32;
			do {
				int b = ptxtbin[k]=='1'?1:0;
				fout = (fout<<1)|b;
				k++;
			  } while (k<64);
		   printf("%08X", fout);
		//int c; cin>>c;
		return 0;
	}
	for (int repeat=0 ; repeat<repeatnumb ; repeat++)
	{
		
		for( int i=0; i<64; i++)
		{
		    arrIPout[i]= arrptxtbin[IP[i]-1];
		   // cout<< arrIPout[i];
		}
		
		for(int i=0; i<64; i++)
		{
			if (i<32)
			arrtxtleft[i]=arrIPout[i]; 
			else
			arrtxtright[i-32]=arrIPout[i]; 
		}

   int arrPC2outkey[16] [48];
   for(int round=0; round<16 ; round++)
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

		for( int i=0; i<48; i++)
		{
			arrPC2outkey[round][i]= arrSLout[PC2[i]-1];
			//cout<< arrPC2outkey[i];
		}
   }
	for(int round=0; round<16 ; round++)
	{

	int arrEPout [48];
	for( int i=0; i<48; i++)
	{
		arrEPout[i]= arrtxtright[EP[i]-1];
		//cout<< arrEPout[i];
	}
	int xorout[48];
	for (int i =0; i< 48; i++)
	{
	   xorout[i]= arrEPout[i] ^ arrPC2outkey[15-round][i];
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

	//for(int i=0; i<8; i++)
	//{
		//cout<<srow[i]<<endl;;
		//cout<<scol[i]<<endl;
		//cout<< binrow[i]<<endl;
		//cout<<bincol[i]<<endl;
		//cout<<decrow[i]<<endl;
		//cout<<deccol[i]<<endl;
		//cout<<soutdec[i]<<endl;
	//}

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

	int xorRi[32];
	for (int i =0; i<32; i++)
	{
	   xorRi[i]= arrSPout[i] ^ arrtxtleft[i];
	   //cout<<xorRi[i];
	}

	for (int i =0; i<32; i++)
	{
		arrtxtleft[i]= arrtxtright[i];
		arrtxtright[i]= xorRi[i];
	   //cout<<arrtxtleft[i];	
	}
	//cout<<endl; for (int i =0; i<32; i++){cout<<arrtxtright[i];}
	// break;
	}
	//swap
	int arroutround [64];
	for(int i=0; i<64; i++)
		{
			if (i<32)
				arroutround[i]= arrtxtright[i];
			else
		        arroutround[i]= arrtxtleft[i-32];
		}
	//for(int i=0; i<64; i++){cout<<arroutround[i];}

	int arrcipher [64];
		for( int i=0; i<64; i++)
		{
		    arrcipher[i]= arroutround[IP_1[i]-1];
		   // cout<< arrcipher[i];
		}
		if( repeatnumb>1 && repeat != repeatnumb)
		{for( int i=0; i<64; i++)
		 {
		    arrptxtbin[i]= arrcipher[i];
		 }
		}
		if ( repeat == repeatnumb-1)
		{
			stringstream osp;
			string outcipher;
			for (int i=0; i<64; i++)
			{
				osp << arrcipher[i];
			}
		   outcipher=osp.str();
		  // cout<<endl<<outcipher<<endl;
		   int fout= 0;
		   int k =0;
		   do {
				int b = outcipher[k]=='1'?1:0;
				fout = (fout<<1)|b;
				k++;
			  } while (k<32);
			printf("%08X", fout);
			fout= 0;
			k =32;
			do {
				int b = outcipher[k]=='1'?1:0;
				fout = (fout<<1)|b;
				k++;
			  } while (k<64);
		   printf("%08X", fout);
		}
	}
	
   // int xxx; cin>> xxx;
    return 0;
} //	0123456789ABCDEF