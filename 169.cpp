class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        while (1)
        {
            int number = nums[rand()%n];
            int freq = 0;
            for (int num : nums)
                if (num == number)
                    freq++;
            
            if (freq > n/2)
                return number;
        }
        
    }
};
