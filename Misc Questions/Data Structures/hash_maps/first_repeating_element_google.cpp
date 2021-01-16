#include<bits/stdc++.h>

using namespace std;

int main()
{
	int ar[] = {2,5,1,2,3,5,1,2,4};
	int n = sizeof(ar)/sizeof(ar[0]);
	unordered_map<int, int> m;
	
	for(int i=0;i<n;i++)
	{
		if(m[ar[i]] > 0)
		{
			cout<<ar[i];
			return 0;
		}
		m[ar[i]]++;	
	}
	
	cout<<"NULL";
	
	return 0;
}
