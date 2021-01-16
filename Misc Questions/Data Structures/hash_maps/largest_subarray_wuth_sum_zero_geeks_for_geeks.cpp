// Problem: Find the length of largest subarray with 0 sum
// Link: https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i, j;
	 
    unordered_map<int, int> presum; 
  
    int sum, max_len;
	sum = max_len = 0;
	
    for (i = 0; i < n; i++) { 
        sum += arr[i]; 
  
        if (arr[i] == 0 && max_len == 0) 
            max_len = 1; 
        
		if (sum == 0) 
            max_len = i + 1; 
  
        if (presum.find(sum) != presum.end()) { 
            max_len = max(max_len, i - presum[sum]); 
        } 
        else { 
            presum[sum] = i; 
        } 
    } 
	
	cout<<max_len;
	return 0;
}
