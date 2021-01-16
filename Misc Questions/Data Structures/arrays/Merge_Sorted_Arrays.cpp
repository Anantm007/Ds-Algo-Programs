#include<bits/stdc++.h>

using namespace std;

int *merge_Sorted_Arrays(int a[], int b[], int m, int n)
{
	static int c[100000];
	
	int i, j, k;
	i = j = k = 0;
	
	while(i<m && j<n)
	{
		if(a[i] < b[j])
		c[k++] = a[i++];
		
		else
		c[k++] = b[j++];
	}
	
	while(i<m)
	{
		c[k++] = a[i++];
	}
	
	while(j<n)
	{
		c[k++] = b[j++];
	}
		
	return c;
}


int main()
{
	int a[] = {0, 3, 4, 31};
	int b[] = {4, 6, 30, 51, 68};
	
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(b)/sizeof(b[0]);
	
	int *c = merge_Sorted_Arrays(a, b, m, n);
	int s = n+m;
	
	for(int i=0; i < s; i++)
	cout<<c[i]<<" ";
	
	return 0;
}
