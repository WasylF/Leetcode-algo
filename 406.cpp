class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end());
        
        vector<pair<int, int>> ans;
        list<pair<int, int>> order;
        map<int, int> height;
        for (pair<int, int> p : people) {
            height[p.first] = 0;
            order.push_back(p);
        }
            
        while (!order.empty()) {
            
            list<pair<int,int>>::iterator iter = order.begin();
            
            while (height[(*iter).first] != (*iter).second)
                iter++;
            
            ans.push_back(*iter);
            
            for (auto& kv : height) {
                if (kv.first <= (*iter).first)
                    kv.second++;
            }
            
            order.erase(iter);
        }
        
        return ans;
    }
};
