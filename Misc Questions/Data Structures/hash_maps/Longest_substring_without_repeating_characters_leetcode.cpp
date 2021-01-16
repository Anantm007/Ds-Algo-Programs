// Leetcode Problem ->  Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        
        int l=0, r=0, ans=0;
        
        while(l<=r && r<s.length())
        {
            if(map[s[r]]==0)
            {
                map[s[r]]++;
                ans=max(ans,r-l+1);
                r++;
            }
            else
            {
                map[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};
