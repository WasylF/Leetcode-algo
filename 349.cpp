class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     set<int> first;
     for (int num : nums1)
        first.insert(num);
      
      set<int> ans;
      for (int num : nums2)
        if (first.count(num))
            ans.insert(num);
            
     return vector<int>(ans.begin(), ans.end());
    }
};
