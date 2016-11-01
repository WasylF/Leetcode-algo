class Solution {
vector<string> ans;

public:
    vector<string> readBinaryWatch(int num) {
        for (int i = 0; i <= num; i++) {
            hour(i, num - i);
        }
        return ans;
    }
    
    string init(int l, int one) {
        string res = "";
        l -= one;
        for (int i = 0; i < l; i++)
            res += '0';
        for (int i = 0; i < one; i++)
            res += '1';
        return res;
    }
    
    void hour(int h, int m) {
        string hr = init(4, h);
        do {
            int hInt = toInt(hr);
            if (hInt < 12) {
                string h_ = to_string(hInt);
                string mn = init(6, m);
                do {
                    int mInt = toInt(mn);
                    if (mInt<60) {
                        string m_ = (mInt < 10 ? "0" : "") + to_string(mInt);
                        ans.push_back(h_+":"+m_);
                    }
                } while (next_permutation(mn.begin(), mn.end()));
            }            
        } while (next_permutation(hr.begin(), hr.end()));
    }
    
    int toInt(string &s) {
        int ans = 0;
        int b = 1;
        for (int i = s.length() - 1; i>=0; i--) {
            if (s[i] == '1') ans += b;
            b *= 2;
        }
        return ans;
    }
};