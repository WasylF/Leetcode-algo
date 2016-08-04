class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
            
        vector<vector<int>> buckets(nums.size()+1);
        for (pair<int, int> p : freq)
        {
            buckets[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        {
            int j = buckets.size();
            while (k>0)
            {
                j--;
                if (buckets[j].size())
                    for (int i = min(k,(int)buckets[j].size()) - 1; i>=0; i--)
             {
                 ans.push_back(buckets[j][i]);
                 k--;
             }
            }
        }
        
        return ans;
    }
};
