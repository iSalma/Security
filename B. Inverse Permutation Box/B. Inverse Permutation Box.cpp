#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

int main()
{
	int outnum;
	cin>> outnum;
	int *arrbox = new int [outnum];
	for (int i=0; i<outnum; i++)
	{
	   cin>>arrbox[i];
	}

	int flag=0;
	 for(int i=0; i<outnum; i++)
       {
         for(int j=i+1;j<outnum;j++)
            {
             if(arrbox[i]==arrbox[j])
                {
                   flag =1;
	            	break;
                 }
             }
		 if (flag==1) break;
      }

	int *inverse = new int [outnum];
	for(int i = 0; i<outnum; i++)
	{
		int nu= arrbox[i];
	    inverse[nu-1] = i+1;
	}
	string out;
	for(int i = 0; i<outnum; i++)
	{
	  if (flag==0)
	   { 
		   cout<< inverse[i] ;
	       cout<< " ";
	  }
	  else 
	  {
		  cout<<"IMPOSSIBLE"; 
		  break; 
	  }
	} 
	
  //int xxx; cin>> xxx;
  return 0;
}
