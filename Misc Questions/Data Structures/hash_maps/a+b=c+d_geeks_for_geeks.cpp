// Geeks for Geeks -> Find four elements a, b, c and d in an array such that a+b = c+d
// Link: https://www.geeksforgeeks.org/find-four-elements-a-b-c-and-d-in-an-array-such-that-ab-cd/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int ar[] = {3, 4, 7, 1, 12, 9};
	int n = sizeof(ar)/sizeof(ar[0]);
	int i, j;
	
	unordered_map<int, pair<int, int>> m;
	vector<int> ans;
	vector<vector<int>> v;
	
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			int sum = ar[i] + ar[j];
			
			if(m.find(sum) == m.end())
			{
			    m[sum] = make_pair(i, j);
			}
			
			else
			{
			    pair<int, int> p = m[sum];

				ans.push_back(ar[i]);
				ans.push_back(ar[j]);
				ans.push_back(ar[p.first]);
				ans.push_back(ar[p.second]);

				v.push_back(ans);
				ans.clear();
            	
				break;
			}
		}
	}
	
	if(v.size() == 0)
	{
		cout<<"No pairs found";
		return 0;
	}

	vector<vector<int>>::iterator row;
	vector<int>::iterator col;
    
	
	for(row=v.begin() ; row!=v.end(); row++)
	{
	    col = row->begin();
	    cout<<col[0]<<" "<<col[1]<<" "<<col[2]<<" "<<col[3]<<endl;
	}
	
	
	return 0;
}
