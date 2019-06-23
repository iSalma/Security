#include <iostream>
#include <string>
using namespace std;

int main()	
{
	int insize;
	cin>> insize;
	int outsize;
	cin>> outsize;
	int *arrout = new int [outsize];
	for ( int i=0; i< outsize ; i++)
	{
	   cin>> arrout[i];
	}
	int counter =0;
     for(int i=0; i<outsize; i++)
    {
        for(int j=i+1; j<outsize; j++)
        {
			if (arrout[i] == 0)
				break;
			else if(arrout[i] == arrout[j])
            {
                arrout[j]=0;
				counter ++;
            }
        }
    }

	for (int i=0; i<outsize; i++)
	{
	   if ( (arrout[i]>insize) || (insize> outsize) || (insize != (outsize-counter)) )
		   {
			  cout<<"IMPOSSIBLE"; 
		//	 int xx; cin>>xx;
			  return 0;
	       }
	}
	int *inverse = new int [insize];
	for(int i = 0; i<outsize; i++)
	{
		int nu= arrout[i];
		if (nu ==0)
			continue;
	     else
			 inverse[nu-1] = i+1;
	}
	for(int i = 0; i<insize; i++)
	{
	    cout<< inverse[i] ;
	    cout<< " ";
	}
//	int x; cin>> x;

 return 0;
}