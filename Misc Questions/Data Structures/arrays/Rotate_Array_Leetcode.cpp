// Leetcode Problem -> Rotate Array
// Link: https://leetcode.com/problems/rotate-array/


class Solution {
public:
    void rotate(vector<int>& ar, int k) {
        int i;
        
        while(k--)
        {
            int x = ar.back();
            ar.pop_back();
            ar.insert(ar.begin(), x);
        }
    }
};
