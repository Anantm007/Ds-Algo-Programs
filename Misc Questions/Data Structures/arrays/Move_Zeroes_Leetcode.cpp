// LeetCode Problem -> Moving Zeros
// Link: https://leetcode.com/problems/move-zeroes/description/


class Solution {
public:
    
void moveZeroes(vector<int>& ar) {
	        
		int n = ar.size(), i;
        int c=0;
       
       // All zero input
       int f=0;
       for(i=0;i<n;i++)
       {
           if(ar[i] != 0)
           {
               f=1;
               break;
           }
       }
       
       if(f==0)
       {
           return;
       }
       
       // If last element is 0 so to prevent out of bounds
       if(ar[n-1] == 0)
       {
        	ar.push_back(INT_MAX);
        	n++;
	   }
		
		int k=n;
		
        for(i=0;i<k;i++)
        {
            if(ar[i] == 0)
            {
                ar.erase(ar.begin() + i);
                i--;
                c++;
            }
        }
        
        // Add the necessary zeros at the end
        for(i=0;i<c;i++)
        {
            ar.push_back(0);
        }
        
        // Remove the INT_MAX stored for trailing zeros
        for(i=0;i<n;i++)
        {
        	if(ar[i]==INT_MAX)
        	{
	        	ar.erase(ar.begin() + i);
	        	n--;
	        	break;	
			}
		}
            
        
        for(i=0;i<n;i++)
        {
            ar[i]!=INT_MAX && cout<<ar[i]<<" ";
        }
    }
};
