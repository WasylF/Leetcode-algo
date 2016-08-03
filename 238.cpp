class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        for (int i = 1; i < n; i++)
            left[i] = left[i-1] * nums[i-1];
            
        int right = nums[n-1];
        for (int i = n-2; i > 0; i--)
        {
            left[i] = left[i] * right;
            right *= nums[i];
        }
        left[0] = right;
        
        return left;
    }
};
