class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq['z'-'a'+1];
        memset(freq, 0, sizeof(freq));
        
        for (char c : s)
            freq[c-'a']++;
            
        for (char c : t)
            freq[c-'a']--;
            
        for (char c = 'a'; c <= 'z'; c++)
            if (freq[c-'a'])
                return false;
                
        return true;
    }
};
