// Leetcode Problem -> Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(), ar.end());
        
        for(int i=0;i<n-1;i++)
        {
            if(ar[i] == ar[i+1])
                return true;
        }
        
        return false;
    }
};
