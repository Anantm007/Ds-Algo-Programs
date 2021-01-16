// Leetcode Problem -> Maximum Subarray.
// Link: https://leetcode.com/problems/maximum-subarray/


// USING KADANE'S ALGORITHM

class Solution {
public:
    int maxSubArray(vector<int>& ar) {
        int n = ar.size();
        
        int cs = 0, ms = 0, i;
        
        for(i=0; i<n; i++)
        {
            cs = cs + ar[i];
            
            if(cs > ms)
            {
                ms = cs;
            }
            
            if(cs < 0)
            {
                cs = 0;
            }
        }
        
        if(ms == 0)
        {
            sort(ar.begin(), ar.end());
            return ar[n-1];            
        }
            
        
        return ms;
    }
};
