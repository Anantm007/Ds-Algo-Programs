// Leetcode Problem -> Jewels and Stones
// Link: https://leetcode.com/problems/jewels-and-stones/


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> umap;
        int i;
        int ans = 0;
        
        for(i=0; i<J.length(); i++)
        {
            umap[J[i]]++;
        }
        
        for(i=0; i<S.length(); i++)
        {
            if(umap[S[i]] != 0)
                ans++;
        }
        
        return ans;
    }
};
