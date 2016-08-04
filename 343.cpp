class Solution {
public:
    int integerBreak(int n) {
        int ans = n-1;
        
        for (int i = 2; i<n; i++)
        {
            int first = n/i;
            int numSecond = n%i;
            int numFirst = i - numSecond;
            
            int tmp = 1;
            for (int j = 0; j < numFirst; j++)
                tmp *= first;
                
            first++;
            for (int j = 0; j < numSecond; j++)
                tmp *= first;
            
            if (tmp > ans)
                ans = tmp;
        }
        
        return ans;
    }
};
