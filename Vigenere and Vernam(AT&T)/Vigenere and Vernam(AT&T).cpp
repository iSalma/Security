
#include<iostream>
#include<string>
 #include <sstream>
#include<stdio.h> 
#include <cassert>

using namespace std;

int main(){
    
    char key[1000];
	cin >> key;
	char txt[1000];
	cin >> txt;
	
    int txtLen = strlen(txt), keyLen = strlen(key), i, j; 
    char *newKey =new char [txtLen];
	char *encrtxt= new char [txtLen];

    for(i = 0, j = 0; i < txtLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';

	string flag;
	if ((strlen(key) < strlen(newKey)) )
	{
	   flag="NO";
	}
	else
	{
	   flag="YES";
	}

    for(i = 0; i < txtLen; ++i)
      {  
		  encrtxt[i] = ((txt[i] + newKey[i]) % 26) + 'A';
	  }
	     
	

	char *xor= new char [strlen(txt)];
	char *buffer= new char [strlen(txt) * 2];
	int n=0;
	for (int c=0 ; c <strlen(txt) ; c++)
	{
	   xor[c] =  (char)(  (txt[c]) ^  (newKey[c]));
	    n = n + sprintf (buffer+n, "%02X", xor[c]);  
	}

    encrtxt[i] = '\0';

    cout<<"Vigenere: "<<encrtxt;
	cout<<"\nVernam: "<<buffer;
	cout<<"\nOne-Time Pad: "<<flag;

  //  int x1; cin>>x1;
    return 0;
}

[close]
