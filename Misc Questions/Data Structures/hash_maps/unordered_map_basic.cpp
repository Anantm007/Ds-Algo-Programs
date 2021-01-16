#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_map<char, int> freq;
	
	string str = "Anant Mathur";
	int i;
	
	for(i=0; i<str.length(); i++)
	{
		freq[str[i]]++;
	}
	
	for(i=0; i<str.length(); i++)
	{
		cout<<str[i]<<" -> "<<freq[str[i]]<<" times"<<endl;
	}
	
	return 0;
}
