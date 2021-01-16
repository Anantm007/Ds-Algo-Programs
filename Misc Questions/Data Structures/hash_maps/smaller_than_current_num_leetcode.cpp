// Leetcode Problem -> How Many Numbers Are Smaller Than the Current Number
// Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& ar) {
        vector<int> ans;
        
        for(int i=0; i<ar.size(); i++)
        {
            int x = 0;
            for(int j=0; j<ar.size(); j++)
            {
                if(i!=j && ar[j] < ar[i])
                    x++;
            }
            
            ans.push_back(x);
        }
        
        return ans;
    }
};
