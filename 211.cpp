const int ALPHABET_SIZE = 'z' - 'a' + 1;

class Node { 
    public:
    int next[ALPHABET_SIZE];
    bool leaf;
    Node() : leaf(false) {
        memset(next, 0, sizeof(next));
    }
};

class WordDictionary {
private:
    vector<Node> trie;
public:
    WordDictionary() {
        trie.push_back(Node()); // create root
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int cur = 0;
        for (char c : word) 
        {
            int next = trie[cur].next[c-'a'];
            if (next == 0)
            {
                trie[cur].next[c-'a'] = trie.size();
                trie.push_back(Node());
            }
            cur = trie[cur].next[c-'a'];
        }
        trie[cur].leaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int length = word.length();
        return search(word, 0, 0, length);
    }
    
    bool search(string &word, int i, int cur, int &length)
    {
        if (i==length) return trie[cur].leaf;
        
        char c = word[i];
        
        if (c != '.') 
        {
            int next = trie[cur].next[c-'a'];
            if (next == 0) return false;
            return search(word, i+1, next, length);
        } 
        else 
        {
            bool res = false;
            for (char ch = 'a'; !res && ch <= 'z'; ch++)
                if (trie[cur].next[ch-'a']) 
                {
                    res |= search(word, i+1, trie[cur].next[ch-'a'], length);
                }
            return res;
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
