class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n,"");
        for (int i = 1; i <= n; i++) {
            res[i-1] += i%3 == 0 ? "Fizz" : "";
            res[i-1] += i%5 == 0 ? "Buzz" : "";
            res[i-1] += res[i-1].size() == 0 ? to_string(i) : "";
        }
        
        return res;
    }
};
