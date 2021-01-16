// CoderByte Problem -> Longest Word
// Link: https://coderbyte.com/editor/Longest%20Word:Cpp

#include <bits/stdc++.h>
using namespace std;

string LongestWord(string sen) {
  string segment, maxString;
  int cs=0,ms=0;
    
  for(int i=0; i<sen.length(); i++)
  {
  	
	  if(cs > ms)
	  {
	  	ms=cs;
	  	maxString=segment;
	  }
	  
  	  if(sen[i]>=97 && sen[i]<=122)
  	  {
  	  	cs++;
  	  	segment+=sen[i];
	  }
	  
	  else
	  {
	  	segment = "";
		  cs=0;	
	  }
  }

  return maxString;

}

int main(void) { 
   string s;
   getline(cin, s);
   
   s+= ' ';
	
  cout<<LongestWord(s);
  return 0;
    
}
