class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     map<int,int> first;
     for (int num : nums1)
        first[num]++;
      
      vector<int> ans;
      for (int num : nums2)
        if (first[num])
            {
                ans.push_back(num);
                first[num]--;
            }
            
     return ans;
    }
};
