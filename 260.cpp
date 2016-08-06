class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for (int num : nums)
            xr ^= num;
            
        int bitDif = 1;
        while (1)
        {
            if ((int)(bitDif&xr)) break;
            bitDif <<= 1;
        }
        
        vector<int> ans(2,0);
        for (int num : nums)
            if ((int)(bitDif&num)) ans[0] ^= num;
            else ans[1] ^= num;
            
        
        return ans;
    }
};
