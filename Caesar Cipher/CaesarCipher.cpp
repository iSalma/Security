#include <iostream> 
#include <string>
using namespace std; 
  
string encr(string txt, long long shift) 
{ 
    string enc_res = ""; 
  
    for (int i=0;i<txt.length();i++) 
    { 
        
            enc_res += char(long long(txt[i]+shift-65)%26 +65); 

    } 
    return enc_res; 
} 

int main() 
{ 
	long long shift ; 
	cin>>shift;
    string txt; 
	cin>> txt;
    cout << encr(txt, shift); 
  //  int x; cin>>x;
    return 0; 
} 