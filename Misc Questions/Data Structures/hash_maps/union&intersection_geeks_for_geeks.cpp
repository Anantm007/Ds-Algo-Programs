#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[] = {10, 15, 4, 20};
	int b[] = {8, 4, 2, 10};
	
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(b)/sizeof(b[0]);
	
	int i;
    unordered_map<int, int> umap;
    unordered_map<int, int>:: iterator it; 

	
	for(i=0; i<m; i++)
	{
		umap[a[i]]++;
	}
	
	
	for(i=0; i<n; i++)
	{
		umap[b[i]]++;
	}
	
	// Union
	cout<<"Union		=>	";
	for(it = umap.begin(); it!= umap.end(); it++)
	{
		cout<<it->first<<" ";
	}
	
	
	// Intersection
	cout<<"\nIntersection		=>	";
	for(it = umap.begin(); it!= umap.end(); it++)
	{
		if(it->second > 1)
		cout<<it->first<<" ";
	}
	
	return 0;
}
