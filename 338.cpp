class Solution {
public:
    vector<int> countBits(int num) {
     vector<int> ans(1,0);
     if (num==0) return ans;
     
     ans.push_back(1);
     if (num==1) return ans;
     
     int curPow = 1;
     int nextPow = 2;
     for (int i=2; i<=num; i++)
     {
         if (i == nextPow)
         {
             curPow = i;
             nextPow *= 2;
         }
         ans.push_back(1+ans[i-curPow]);
     }
     
     return ans;
    }
};
