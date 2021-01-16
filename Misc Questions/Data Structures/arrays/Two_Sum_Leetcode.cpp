// Leetcode question -> Two Sum
// Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        int n = ar.size(),i,j;
        vector<int> ans;

        for(i=0; i<n-1; i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(ar[i] + ar[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }      
                    
            }
                
        }
        
        return ans;
    }
};
