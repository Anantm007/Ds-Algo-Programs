#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	
	// Naive way ==> O(n)
	for(int i=s.length()-1; i>=0; i--)
	{
		cout<<s[i];
	}
	
	// C++ STL
    reverse(s.begin(), s.end()); 
	cout<<endl<<s;
	
	return 0;
}
